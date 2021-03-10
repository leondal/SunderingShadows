//_orb.c

#include <std.h>

inherit DAEMON;

int cmd_forcechat(){

	new("/cmds/avatar/orb")->move(TP);
     return 1;
}

int help(){
    write("Syntax: orb \n\n  Creates the 'monster control orb'  read the help on the orb when you have it for better information.");
    return 1;
}
