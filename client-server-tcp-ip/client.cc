
#include <omnetpp.h>

using namespace omnetpp;


class client : public cSimpleModule
{

    cMessage *msg;
    simtime_t simtime=0;
   // int flag=1;
    //int flagcontroller=0;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(client);
void client::initialize()
{
   EV <<"Client initialized"<<"\n";
   //int flag=1;
   msg= new cMessage("RTS");

   scheduleAt(simTime() + 0.5,msg->dup());

   EV <<"Client initialize complete"<<"\n";


}
void client :: handleMessage(cMessage *msg)
{
    EV <<"Client handle message initialize "<<"\n";

    cModule *target;
    target=getParentModule()->getSubmodule("Server");



    if(msg->isSelfMessage()){

        sendDirect(msg,target,"radioIn");
        scheduleAt(simTime() + dblrand(),msg->dup());
     //   flag=0;

       }

    else{

        if (strcmp("CTS", msg->getName())==0)
               {
                     //  cMessage *generateNewMessage();
                // using sendDirect method for wireless communication

            simtime=simTime()+0.001;
                msg= new cMessage("DATA");
                     sendDirect(msg,target,"radioIn");
                   //  flagcontroller++;
                     //scheduleAt(simTime() + dblrand(),msg->dup());
               }


        else if(strcmp("ACK", msg->getName())==0){

            msg= new cMessage("RTS");
            sendDirect(msg,target,"radioIn");
            simtime=simTime()+0.001;
            //flagcontroller++;

        }
    //if(flagcontroller%2==0)
       // flag=1;
    }

}


