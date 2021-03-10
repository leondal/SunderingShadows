#include <std.h>

inherit DAEMON;

int cmd_make(string str){
    object *usr;
    int i;

    if(!TP->is_class("thief") && !TP->is_class("assassin") && !TP->is_class("bard")) return 0;
    if(str != "thief sign") return notify_fail("make what?\n");
    if(TP->query_invis()){
      tell_object(TP, "You're not quite visible, they won't see it.");
      return 1;
    }

    usr = all_living(ETP);
    for(i=0;i<sizeof(usr);i++){
      if(!usr[i]->is_class("thief") && !usr[i]->is_class("bard") && !usr[i]->is_class("assassin")) continue;
      if(usr[i] == TP) continue;
      tell_object(usr[i], "You notice "+TPQCN+" signing to the room that "+TP->query_subjective()+" is a thief.");
    }
    tell_object(TP, "You sign to the room that you are a thief.");
    return 1;
}

void help(){
    write("Syntax: <make thief sign>\n\n"
      +"Tells EVERY thief bard and assassin in the room that you are one of their brethren.  You never know who's going to be one."
    );
}
