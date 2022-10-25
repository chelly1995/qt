#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QObject>
#include <QWidget>
#include <QDataStream>

#include "chatserverform.h"

class QTextEdit;
class QLineEdit;
class QTcpSocket;
class QPushButton;


typedef struct {
    int type;
    char data[1020];
} chatProtocolType;
/*
typedef enum {
    Chat_Login,
    Chat_In,
    Chat_Talk,
    Chat_Close,
    Chat_LogOut,
    Chat_Invite,
    Chat_KickOut,
    Chat_FileTransform
} Chat_Status;
*/

class ChatClient : public QWidget
{
    Q_OBJECT
public:
    ChatClient(QWidget *parent = nullptr);
    ~ChatClient();
signals:

private slots:
    void connectToServer( );
    void receiveData( );			// 서버에서 데이터가 올 때
    void sendData( );			// 서버로 데이터를 보낼 때
    void disconnect( );

private :

    void closeEvent(QCloseEvent*) override;

    QLineEdit *name;
    QTextEdit *message;		// 서버에서 오는 메세지 표시용
    QLineEdit *inputLine;		// 서버로 보내는 메시지 입력용
    QPushButton* sentButton;
    QPushButton* connectButton;
    QTcpSocket *clientSocket;		// 클라이언트용 소켓
};

#endif // CHATCLIENT_H
