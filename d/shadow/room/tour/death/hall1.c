//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>

inherit ROOM;

void create(){
    ::create();
        set_property("indoors",0);
        set_property("light",1);
        set_short("This is the entrance to the DarkWood");
        set_long(
@BUILD
%^BOLD%^This is the entrance to the DarkWood%^RESET%^
As you step under the canopy of the trees, the cool darkness surrounds
you.  When your eyes adjust to the darkness, you see the minions of
Death moving about prepareing to take the battle to the forces
of the Grand Paladin.  There is a small shack to the west.  The 
path continues south into the DarkWood.
To the east you see a wagon.
BUILD
);
        set_exits(([
       "south":"/d/shadow/room/tour/death/hall2.c",
     "north":"/d/shadow/room/tour/main.c",
       "east":"/d/shadow/room/tour/death/bank.c",
       "west":"/d/shadow/room/tour/death/dth_store.c",
        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
        set_smell("default","The strong smell of campfires surrounds "+
                  "this area");
         set_listen("default","You can hear many sounds as the minion "+
            "of Death prepare for battle.");

}




