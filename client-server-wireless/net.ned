simple Server
{
    @display("i=device/server;p=230,40");
    gates:
        input radioIn @directIn;
}


simple Client
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input radioIn @directIn;
}
//
// TODO documentation
//
network Network
{
    @display("bgb=333,229");
    submodules:
        Server: Server {
            @display("p=264,118;is=l");
        }
        Client: Client {
            @display("p=64,113;is=l");
        }
}

