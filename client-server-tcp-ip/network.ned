simple Server {
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

network Network
{
    @display("bgb=391,226");
    submodules:
        Server: Server {
            @display("p=62,73");
        }
        Client: Client {
            @display("p=236,77");
        }
}
