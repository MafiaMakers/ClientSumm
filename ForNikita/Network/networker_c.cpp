#include "include_c.h"
#include "networker_c.h"
#include "systemfunctions_c.h"

namespace Mafia {
    NetWorker_c::NetWorker_c(){
        _initSocket();
        ipServer = SERVER_ADDR;
        // Setup the TCP listening socket
        _setAddr();
    }
    QUdpSocket* NetWorker_c::getSock(){
        return(sock);
    }

    char* NetWorker_c::getIP(){
        return((char*)ipServer.c_str());
    }

    QHostAddress* NetWorker_c::getAddrIn(){
        return(&serverAddr);
    }

    int NetWorker_c::setNickname(char* newName){
        nickname = newName;
        if(!connected){
            return 0;
        }
        return sendMessage(serverAddr, CHANGE_NAME_MESSAGE_ID, newName, strlen(newName));
    }

    int NetWorker_c::leave(){
        if(sendMessage(serverAddr, EXIT_ROOM_MESSAGE_ID, (char*)"EXIT!", 6) == -1){
            //std::cout << WSAGetLastError() << std::endl;
            return SEND_ERROR;
        }
        //std::cout << (sock, SD_SEND) << std::endl;
        return 0;
    }


    //recommended to run in another thread
    int NetWorker_c::connect(std::string key){
        char* mes = new char[KEY_SIZE + 1];
                mes[0] = (char)roomId;
                for (int i = 0; i < KEY_SIZE; i++)
                {
                    mes[i + 1] = key[i];
                }
                //Send connecting message
                if(sendMessage(serverAddr, CONNECT_MESSAGE_ID, mes, KEY_SIZE + 1) == -1){
                    //WSAGetLastError()
                    return(SEND_ERROR);
                }

                //get room Id
                return receiveMessage();
    }

    NetWorker_c::~NetWorker_c() {
        leave();
    }

    //recommended to run in another thread
    int NetWorker_c::receiveMessage(){
        //buffer to write there received message
        char *buffer = new char[BUF_SIZE];
        QHostAddress currentClient;
        int cCSize = sizeof(currentClient);
        //receive message
        qint64 bytesReceived = sock->readDatagram(buffer, BUF_SIZE, &currentClient);
        //check if message is OK
        if (bytesReceived > 0) {
            char* mes = new char[BUF_SIZE];
            short mId = 0;
            int err = _decodeMessage(buffer, bytesReceived, mes, &mId);
            if(err != 0){
                //if message is wrong, throw it away
                if(err != CONTROL_SUM_ERROR){
                    delete[] buffer;
                    delete[] mes;
                    return(err);
                }
                //if error was in control sum - it means that not all message received, then ask for resending
                std::cout << "CONTROL SUM!!!" << std::endl;
                char *resendMes = new char[2];
                resendMes[0] = ((char*)&mId)[0];
                resendMes[1] = ((char*)&mId)[1];
                int error = sendMessage(currentClient, RESEND_MESSAGE_ID, resendMes, 2);
                if(error != 0){
                    delete[] buffer;
                    delete[] mes;
                    return(error);
                }
                delete[] buffer;
                delete[] mes;
                return receiveMessage();

            }
            int errorerr = _processMessage(mes, bytesReceived-7, mId);
            return(errorerr);
        }
        else  {
            delete[] buffer;
            return 0;
        }
    }

    //run in another thread
    void NetWorker_c::processMessages() {
        while (true) {
            int err = receiveMessage();
            if (err != 0) {
                std::cout << err << std::endl;
            }
        }
    }

    //is this client connected to any room?
    bool NetWorker_c::isConnected(){
        return(connected);
    }

    //sends message with length mesLen and id messageId to client. Returns 0 if succes, error id if error
    int NetWorker_c::sendMessage(QHostAddress client, short messageId, char* message, int mesLen){
        char *resMes = new char[BUF_SIZE];
        //zeroMemSys(resMes, BUF_SIZE);
        int err = _wrapMessage(message, mesLen, messageId, resMes);
        if(err != 0){
            return(err);
        }
        try{
            //std::cout << QByteArray(resMes, mesLen + 7).toStdString() << std::endl;
            int e = sock->writeDatagram(QByteArray(resMes, mesLen + 7), client, CASUAL_PORT);
            delete[] resMes;
            return(e);
        } catch(std::exception e){
            delete[] resMes;
            return SEND_ERROR;
        }
        delete[] resMes;
        return 0;
    }

    //codes message to Prot which we use
    int NetWorker_c::_wrapMessage(char* message, int mesLen, short messageId, char* result){
        result[0] = roomId;
        result[1] = ((char*)&messageId)[0];
        result[2] = ((char*)&messageId)[1];

        int controlSum = 0;
        for(int i = 0; i < mesLen; i++){
            result[i+3] = message[i];
            controlSum += (int)((unsigned char)message[i]);
        }

        for(int i = 0; i < 4; i++){
            result[3 + mesLen + i] = ((char*)&controlSum)[i];
        }

        return(0);
    }

    void NetWorker_c::setRoomId(char rId){
       this->roomId = rId;
    }

    //Works with given decoded message of size size, with messageId
    int NetWorker_c::_processMessage(char* message, int size, short messageId){

        switch(messageId){
        case SUCCESS_MESSAGE_ID:{
            int* a = (int*)message;
            roomId = *a;
            connected = true;
            std::cout << "RoomId - " << (int)roomId << std::endl;
            emit gotToRoom(roomId);
            break;
        }
        case CHECK_CONNECTION_MESAGE_ID: {
            sendMessage(serverAddr, CHECK_CONNECTION_MESAGE_ID, (char*)"recv", 5);
            break;
        }
        default:{
            char* newMes = new char[size];
            int id = (int)messageId;
            int newSize = size;
            for(int i = 0; i < size; i++){
                newMes[i] = message[i];
            }
            emit messageReceived(id, newMes, newSize);
            break;
        }
    }
    return(0);
 }

    void NetWorker_c::_nextStage() {
        std::cout << "Write anything to go to next stage" << std::endl;
        std::string a;
        std::cin >> a;
        sendMessage(serverAddr, NEXT_STAGE_MESSAGE_ID, (char*)"a", 1);
    }

    void NetWorker_c::_inputVote(char* message) {
        std::cout << "Choose who to " << message << std::endl;
        int answer;
        std::cin >> answer;
        sendMessage(serverAddr, VOTE_MESSAGE_ID, (char*)& answer, 4);
        if (currentStage == ARGUMENT_STAGE) {
            sendMessage(serverAddr, STOP_SPEAK_MESSAGE_ID, (char*)& answer, 4);
        }
    }

    void NetWorker_c::_inputRoles() {
        if (myIndex == 0) {
            std::cout << "Who will be the next admin?" << std::endl;
            int idx;
            std::cin >> idx;
            sendMessage(serverAddr, SET_ADMIN_MESSAGE_ID, (char*)& idx, 4);
        }
        else {
            char* count = new char[MAX_ROLE_ID];
            for (int i = 0; i < MAX_ROLE_ID; i++)
            {
                std::cout << "How many players with role " << i << std::endl;
                int c;
                std::cin >> c;
                count[i] = (char)c;
            }
            sendMessage(serverAddr, NEXT_STAGE_MESSAGE_ID, count, MAX_ROLE_ID);
            sendMessage(serverAddr, SETUP_MESSAGE_ID, count, MAX_ROLE_ID);
        }
    }
    /*
    **  decodes message recieved from client using our message proto. Returns 0 if success, return error id (from defines.h) if error
    **  bytes is received message, size is size of message, result is INITIALIZED array with size BUF_SIZE of char to put there decoded message,
    **  getMessageId is ref to short variable to write there the id of this message
    */
    int NetWorker_c::_decodeMessage(char* bytes, int size, char* result, short* getMessageId){
        //check if message is too short
        if(size < 8){
            return SHORT_MESSAGE_ERROR;
        }
        //if not connected - any roomId is OK
        if(connected){
            //check if roomId is ok
            char room = bytes[0];
            if(room != roomId){
                std::cout << (int)room << " / " << (int)roomId << std::endl;
                return ROOM_ID_ERROR;
            }
        }

        //getting message Id
        short messageId = 0;
        ((char*)&messageId)[0] = bytes[1];
        ((char*)&messageId)[1] = bytes[2];

        //check if control sum is correct
        unsigned int controlSum = 0;
        for(int i = 0; i < 4; i++){
            ((char*)&controlSum)[i] = bytes[size - 4 + i];
        }

        unsigned int realSum = 0;

        for(int i = 3; i < size - 4; i++){
            realSum += (unsigned char)bytes[i];
        }

        if(realSum != controlSum){
            return CONTROL_SUM_ERROR;
        }

        //fill the result array
        for(int i = 3; i < size - 4; i++){
            result[i-3] = bytes[i];
        }
        *getMessageId = messageId;
        return 0;
    }


    void NetWorker_c::_initSocket(){
        sock = new QUdpSocket(this);

    }

    void NetWorker_c::_setAddr(){
        serverAddr = QHostAddress(SERVER_ADDR);
    }
}
