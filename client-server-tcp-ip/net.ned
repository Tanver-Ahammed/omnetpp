
simple server
{
    @display("i=abstract/accesspoint");
    gates:
        input radioIn @directIn;
}

//
// TODO documentation
//
simple client
{
    @display("i=abstract/accesspoint");
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

