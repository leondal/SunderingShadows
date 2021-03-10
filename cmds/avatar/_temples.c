#include <std.h>

inherit DAEMON;

int cmd_temples(){

     TP->move_player("/d/magic/temples/main");
    return 1;
}

int help(){
   write(
@OLI
   Usage: temples
     This command moves you to the universal god's room. From here you can enter the temple of any god.
OLI
    );
return 1;
}
