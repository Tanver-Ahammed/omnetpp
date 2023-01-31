/*
 * tanver.cc
 *
 *  Created on: Jan 30, 2023
 *      Author: tanver
 */


#include <omnetpp.h>

using namespace omnetpp;


class Client : public cSimpleModule{
    cMessage *msg;
    simtime_t simtime=0;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Client);

void Client::initialize(){
   msg= new cMessage("RTS");
   scheduleAt(simTime() + 0.5,msg->dup());
}

void Client :: handleMessage(cMessage *msg){
    cModule *target=getParentModule()->getSubmodule("Server");

    if(msg->isSelfMessage()){
        sendDirect(msg, target, "radioIn");
        scheduleAt(simTime() + dblrand(), msg->dup());
    }
    else{
        if (strcmp("CTS", msg->getName())==0){
            msg= new cMessage("DATA");
        }
        else if(strcmp("ACK", msg->getName())==0){
            msg= new cMessage("RTS");
        }
        simtime=simTime()+0.001;
        sendDirect(msg,target,"radioIn");
    }

}
