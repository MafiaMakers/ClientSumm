#ifndef DEFINES_H
#define DEFINES_H

#define BUF_SIZE 16384
#define CLIENTS_MAX_COUNT 64
#define CASUAL_PORT 53000
#define IP_PROTO AF_INET
#define TIME_PAUSE 5000
#define THINK_TIME 45000
#define DELTA_TIME 100
#define VOTE_TIME 15000
#define TALK_TIME 60000
#define KEY_SIZE 20
//здесь укажите Ip сервера "91.214.71.57"
#define SERVER_ADDR "91.214.71.57"

#define SERVER_INITIALIZATION_ERROR 100
#define RECEIVING_ERROR 101
#define SHORT_MESSAGE_ERROR 102
#define ROOM_ID_ERROR 103
#define CONTROL_SUM_ERROR 104
#define UNKNOWN_MES_ID_ERROR 105
#define CLIENTS_LIMIT_ERROR 106
#define REPEATATIVE_REQUEST_ERROR 107
#define CLOSED_ROOM_REQUEST_ERROR 108
#define MESSAGE_SIZE_ERROR 109
#define PRIVACY_ERROR 110
#define ROLE_ERROR 111
#define CLIENT_INDEX_ERROR 112
#define KEY_ERROR 113

#define RESEND_MESSAGE_ID 1
#define TEXT_MESSAGE_ID 2
#define CONNECT_MESSAGE_ID 3
#define ERROR_MESSAGE_ID 4
#define SUCCESS_MESSAGE_ID 5
#define EXIT_ROOM_MESSAGE_ID 6
#define CHANGE_NAME_MESSAGE_ID 7
#define ROLE_MESSAGE_ID 8
#define STAGE_MESSAGE_ID 9
#define CHECK_CONNECTION_MESAGE_ID 10
#define VOTE_MESSAGE_ID 11
#define DIE_HEAL_MESSAGE_ID 12
#define MADE_VOTE_MESSAGE 13
#define INDEX_MESSAGE_ID 14
#define SHERIFF_MESSAGE_ID 15
#define NEXT_STAGE_MESSAGE_ID 16
#define SET_ADMIN_MESSAGE_ID 17
#define SETUP_MESSAGE_ID 18
#define CLIENT_CONNECTED_DISCONNECTED_MESSAGE_ID 19
#define CLIENTS_COUNT_MESSAGE_ID 20
#define CAN_SPEAK_MESSAGE_ID 21
#define STOP_SPEAK_MESSAGE_ID 22
#define CREATE_ROOM_MESSAGE_ID 23
#define KEY_MESSAGE_ID 24
#define FATHER_MESSAGE_ID 25
#define CANDIDATES_MESSAGE_ID 26
#define VIDEO_MESSAGE_ID 27
#define AUDIO_MESSAGE_ID 28

#define WAITING_STAGE 0
#define SPEAKING_STAGE 1
#define NIGHT_STAGE 2
#define ARGUMENT_STAGE 3
#define DEATH_STAGE 4
#define RESULT_STAGE 5

#define CIVILIAN_ROLE 0
#define MAFIA_ROLE 1
#define SHERIFF_ROLE 2
#define DOCTOR_ROLE 3
#define MAX_ROLE_ID 4



#endif // DEFINES_H
