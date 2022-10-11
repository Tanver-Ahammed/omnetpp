/*
 * Server.cc
 *
 *  Created on: Oct 6, 2022
 *      Author: tanver
 */

#include<omnetpp.h>
using namespace omnetpp;

class Server: public cSimpleModule {
    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(Server);

void Server::initialize() {
}

void Server::handleMessage(cMessage *msg) {
    msg = new cMessage();
    cModule *target = getParentModule() -> getSubmodule("Client");
    sendDirect(msg, target, "radioIn");
}

