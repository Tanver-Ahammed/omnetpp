#include<omnetpp.h>
using namespace omnetpp;

class Client: public cSimpleModule {
    private:
        cMessage *msg;
    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
};

Define_Module(Client);

void Client ::initialize() {
    EV <<"Client initialize"<<"\n";
    msg = new cMessage("RTS");
    scheduleAt(5.0 , msg->dup());
    EV <<"Client initialize Complete"<<"\n";
}

void Client ::handleMessage(cMessage *msg) {
    send(msg, "Out");
}
