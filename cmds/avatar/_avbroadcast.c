#include <std.h>

inherit DAEMON;

int help(){
    write(
@OLI
    avbroadcast <distance> <message>
    

    Allows you to broadcast messages that span connected rooms.
The distance represents how many rooms away the system should broadcast.
OLI
    );
    return 1;
}

int cmd_avbroadcast(string str){
    string msg;
    int d;

    if(sscanf(str, "%d %s", d, msg) != 2){
        return help();
    }

    write("You broadcast\n"+msg+"\n to room upto "+d+" %^RESET%^far away.");


    message("info",msg,nearbyRoom(ETP,d));
    return 1;

}
