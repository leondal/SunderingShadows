#include <std.h>

inherit DAEMON;

int cmd_lounge(string str){
   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }
    if(!avatarp(TP)) return 0;
    TP->move_player("/d/dagger/avalounge.c");
    return 1;
}

int help(){
    write("Syntax: lounge  \n\n  Takes you to the avatar's lounge, the place you will learn to call home.");
    return 1;
}
