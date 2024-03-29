/*
 * tanver.cc
 *
 *  Created on: Jan 30, 2023
 *      Author: tanver
 */

#include <omnetpp.h>

using namespace omnetpp;


class Server : public cSimpleModule {
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Server);

void Server::initialize(){
}

void Server :: handleMessage(cMessage *msg) {
    if (strcmp("RTS", msg->getFullName())==0) {
        msg= new cMessage("CTS");
    }
    else if(strcmp("DATA", msg->getFullName())==0){
        msg = new cMessage("ACK");
    }
    cModule *target=getParentModule()->getSubmodule("Client");
    sendDirect(msg, target, "radioIn");
}

