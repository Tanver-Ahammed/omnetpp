#include<omnetpp.h>
using namespace omnetpp;

class Server: public cSimpleModule {

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Server);

void Server ::initialize() {

}

void Server::handleMessage(cMessage *msg) {
    EV <<"Server Message initialize"<<"\n";
    msg = new cMessage("CTS");
    send(msg, "Out");
}
