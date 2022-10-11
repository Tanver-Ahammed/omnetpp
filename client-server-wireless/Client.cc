/*
 * Client.cc
 *
 *  Created on: Oct 6, 2022
 *      Author: tanver
 */
#include<omnetpp.h>
using namespace omnetpp;


class Client: public cSimpleModule {
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Client);

void Client ::initialize() {

    EV <<"Client initialize"<<"\n";
    msg = new cMessage("RTS");
    scheduleAt(simTime() + dblrand(), msg->dup());
    EV<<"Client initialize Complete"<<"\n";

}

void Client::handleMessage(cMessage *msg) {
    EV<<"Client handleMessage initialize"<<"\n";
    cModule *target = getParentModule() -> getSubmodule("Server");
    msg = new cMessage("RTS");
    sendDirect(msg, target, "radioIn");
    scheduleAt(simTime() + dblrand(), msg->dup());

}




