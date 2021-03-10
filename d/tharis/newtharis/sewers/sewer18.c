#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

void create(){
   ::create();
   set_long(::query_long()+"%^RESET%^\n");
   set_exits(([
      "north" : SEWERS"sewer17",
      "east" : SEWERS"crush",
   ]));
}

void init() {
   ::init();
   add_action("peer_override","peer");
}

int peer_override(string str) {
   if(!str) return 0;
   if(str != "east" && str != "e") return 0;
   tell_object(TP,"%^BOLD%^%^BLACK%^Grimy sewers%^RESET%^\n%^BOLD%^%^CYAN%^[1:%^BOLD%^%^CYAN%^ w]%^RESET%^\n%^RESET%^You cannot see far in that direction.");
   return 1;
}

// so! sewer20 and sewer24 were removed long ago in Loki's remodel; they don't exist. This needs gone unless someone is inclined to re-expand the sewer.
/*void init(){
        ::init();
        add_action("leap","leap");
        add_action("leap","jump");
}

int leap(string str) {
        if(!str) return notify_fail(query_verb()+" where?\n");
        if(str != "across pit" && str != "south") return notify_fail(query_verb()+" where?\n");
        write("You atempt to leap across the drainage pit");
        tell_room(TO,""+TPQCN+" attempts to leap across the pit!",TP);
        if((int)TP->query_stats("dexterity") > random(100)) {
                TP->move_player(ROOMS"sewer20");
                write("You land precariously with the water gushing into the pit!");
        } else {
                TP->move_player(ROOMS"crush");
                write("You slip on the opposite edge! You tumble into the pit!");
                tell_room(TO,"You hear someone fall into the pit!");
                tell_room(find_object_or_load(SEWERS"sewer24"),"You hear someone fall into the pit!");
        }
        return 1;
}
*/