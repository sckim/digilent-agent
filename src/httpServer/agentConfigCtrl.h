#ifndef AGENTCONFIGCTRL_H
#define AGENTCONFIGCTRL_H

#include <QJsonObject>

#include "httprequesthandler.h"
#include "../core/agent.h"


class AgentConfigCtrl : public HttpRequestHandler {
    Q_OBJECT

public:
    AgentConfigCtrl(Agent* agent, QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);

private:
    enum CmdCode {
        e_getInfo,
        e_unknownCommand,
    };

    Agent *agent;

    QJsonObject processCommand(QJsonObject cmdObj);
    CmdCode parseCmd(QString cmdString);
};

#endif // AGENTCONFIGCTRL_H
