#include <std.h>

inherit DAEMON;

int cmd_rope(){

    new("/d/common/obj/misc/rope")->move(TP);
    write("You create rope.");
    return 1;
}

int help(){
   write("Creates rope.");
   return 1;
}
