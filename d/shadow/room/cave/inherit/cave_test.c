#include "../../cave.h"

inherit ROOM;

string *unstable_exits = ({ });

void create(){
    ::create();
    set_property("light" , 1);
    set_property("indoors" , 1);
    set_short("Dragon's Den Caverns");
    set_long(
@MELNMARN
%^BOLD%^You are in the Dragon's Den Caverns.%^RESET%^
It is dark here, and damp. The air is cool.
The walls are made out of naturally carved rock.
MELNMARN
);
    set_smell("default","You can smell the stale air.");
    set_listen("default","You can hear scurrying rats, and dripping water.");
    set_items( ([ 
   	({"rubble", "earth", "exit"}):"The cave walls have crumbled and rocks and earth have piled up at the exit.  Perhaps with some effort you could dig that exit open.", 
	]) );
    set_exits(([
    ]));
}

void init(){
int iter; 
    ::init();
    if (!userp(TP))
       return;
    if (!ETP->query_property("collapse"))
       return;
   if (sizeof(ETP->query_buried_exits())) return;
    if (!avatarp(TP)) {
       if (!random(50)) {
           tell_room(ETP,"%^RED%^The room trembles suddenly with a quake of earth, and rubble blocks off all the exits!");
           ETP->collapse_all_exits();
       } else if (sizeof(unstable_exits))
           for(iter=0;iter<sizeof(unstable_exits); iter++)
             if (!random(20)) {
             tell_room(ETP,"%^RED%^The room trembles suddenly with a quake of earth, and the "+unstable_exits[iter]+" exit is caved in.");
             ETP->collapse_exit(unstable_exits[iter]);
           }
     } else {
       if (!random(50))
          write("%^B_GREEN%^%^BOLD%^%^WHITE%^The room's exits should collapse.");
       if (sizeof(unstable_exits))
          for(iter=0;iter<sizeof(unstable_exits); iter++)
             if (!random(20))
                write("%^B_GREEN%^%^BOLD%^%^WHITE%^Exit "+unstable_exits[iter]+" should collapse.");
     }
}
