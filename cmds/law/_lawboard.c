#include <std.h>

inherit DAEMON;

int cmd_lawboard(string str){
    if(!member_group(geteuid(this_player()), "law")) return 0;
    TP->move_player("/adm/save/lawboardroom.c");
    return 1;
}

int help(){
    write("Syntax: lounge  \n\n  Takes you to the avatar's lounge, the place you will learn to call home.");
    return 1;
}
