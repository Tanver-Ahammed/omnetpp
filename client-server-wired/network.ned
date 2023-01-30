simple Server
{
    @display("i=device/server;p=230,40");
    gates:
        input In;
        output Out;
}


simple Client
{
    @display("i=device/wifilaptop;p=230,40");
    gates:
        input In;
        output Out;
}
//
// TODO documentation
//
network Network
{
    @display("bgb=333,229");
    submodules:
        server: Server {
            @display("p=264,118;is=l");
        }
        client: Client {
            @display("p=64,	113;is=l");
        }
    connections:
        client.Out --> server.In;
        server.Out --> client.In;
}

