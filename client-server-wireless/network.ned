
simple server
{
    @display("i=device/server;p=230,40");
    gates:
        input radioIn @directIn;
}

//
// TODO documentation
//
simple client
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
    @display("bgb=391,226");
    submodules:
        Server: server {
            @display("p=62,73");
        }
        Client: client {
            @display("p=236,77");
        }
}


