#include <std.h>
#include <rooms.h>

inherit ROOM;


void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(HEAVY_FOREST);
    set_travel(GAME_TRACK);
    set_short("Tree House");
    set_long(
@KAYLA
Ahead of you, suspended 40' above ground in a cluster of massive trees,
is a giant wooden structure.  It is made of a collection of log walls
and floors at various angles, with a roof of thatched sticks and leaves
covered with tar.  The structure is built on at least four 8 ft. diameter
ash trees and several other thin ones.
KAYLA
    );
     set_listen("default","You hear the creaking of doors and footsteps
from above.");
    set_exits(([
       "west" : "/d/deku/open/forest6"
    ] ));
    set_items(([
        "structure":"This tree house has stood for hundreds of years,
concealed from most creatures.  The few windows or openings you see
are hidden by shadow.  You catch a glimpse of a large furry face that peers out of a small side opening and vanishes back inside.",
      ({"trees", "ash tree", "tree"}): "It looks almost as though one of the trees were hiding something."
    ]));
    set_search("default", "%^GREEN%^One of the trees catches your eye.%^RESET%^");
    set_search("steps",(:TO,"search_pile":));
    set_search("tree",(:TO,"search_pile":));
    set_search("trees",(:TO,"search_pile":));
}
void search_pile(){  
   if(query_exit("steps")!=ROOM_VOID){
   tell_object(TP,"You've already found the hidden steps.");
   return ;    
   }      
   tell_object(TP,"You search around and find hidden steps leading up into the treehouse above!");
   add_exit("/d/deku/open/treehouse","steps");
   set_pre_exit_functions(({"steps"}),({"gotroll"}));
   return ; 
}
int gotroll() {
    if(present("troll")) {
    write("The troll blocks your passage.");
    tell_room(TO,"The troll blocks "+TPQCN+" from entering the treehouse.",TP);        
    return 0;
    }
    else return 1;
}
void reset() {
  ::reset();
   if(query_exit("steps")){  
   remove_exit("steps");
   }
  if(!present("troll")) {
    new("/d/deku/monster/troll")->move(TO);
  }
}
