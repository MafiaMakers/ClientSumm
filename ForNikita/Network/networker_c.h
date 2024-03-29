#include "include_c.h"
#include <QObject>

#ifndef NETWORKER_H
#define NETWORKER_H


namespace Mafia {
//the main networker class
    class NetWorker_c : public QObject {
        Q_OBJECT
    public:
        explicit NetWorker_c();

        QUdpSocket* getSock();

        char* getIP();

        QHostAddress* getAddrIn();

		void processMessages();

        //recommended to run in another thread
        int receiveMessage();
        //sends message with length mesLen and id messageId to client. Returns 0 if succes, error id if error
        int sendMessage(QHostAddress client, short messageId, char* message, int mesLen);

        int connect(std::string key);

        int setNickname(char* newName);

        void setRoomId(char rId);

        int leave();

        bool isConnected();

		~NetWorker_c();
    protected:
        int _wrapMessage(char* message, int mesLen, short messageId, char* result);
        //There will be process method, but it's the next step
        int _processMessage(char* message, int size, short messageId);

        void _finishArg();
        /*decodes message recieved from client using our message proto. Returns 0 if success, return error id (from defines.h) if error
        **bytes is received message, size is size of message, result is INITIALIZED array with size BUF_SIZE of char to put there decoded message,
        ** getMessageId is ref to short variable to write there the id of this message*/
        int _decodeMessage(char* bytes, int size, char* result, short* getMessageId);
        void _initSocket();

		void _inputRoles();

		void _nextStage();

        void _setAddr();
		void _inputVote(char* message);
        char roomId = 0;
		int myIndex = 0;
		int adminIndex = 0;
		int currentStage = 0;
        //Current server socket
        QUdpSocket* sock;
        std::string ipServer;
        //Current address
        QHostAddress serverAddr;

        bool connected = false;

        char* nickname = (char*)"User";

signals:
    void messageReceived(int id, char* data, int size);
    void gotToRoom(int roomId);

};


}
#endif // NETWORKER_H
