
#include <omnetpp.h>

using namespace omnetpp;


class server : public cSimpleModule
{

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(server);
void server::initialize()
{

 }

void server :: handleMessage(cMessage *msg)
{
    if (strcmp("RTS", msg->getFullName())==0)
    {

   // delete msg;

    msg= new cMessage("CTS");

    cModule *target=getParentModule()->getSubmodule("Client");


    // using sendDirect method for wireless communication

    sendDirect(msg,target,"radioIn");

    }


    else if(strcmp("DATA", msg->getFullName())==0){

        msg= new cMessage("ACK");

        cModule *target=getParentModule()->getSubmodule("Client");

        sendDirect(msg,target,"radioIn");
    }
}





