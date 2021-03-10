//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>

inherit ROOM;

void create(){
    ::create();
        set_property("indoors",0);
        set_property("light",1);
     set_short("This is a small path trough the DarkWood.");
        set_long(
@BUILD
%^BOLD%^You move down a small path, in the DarkWood%^RESET%^
This is a small path leading through the DarkWood.  The trees are so
dense above you can barely see the sky above.  The path opens up
into a clearing to the north and stretches through the dark forest 
to the south.
BUILD
);
        set_exits(([
         "south":"/d/shadow/room/tour/death/hall4.c",
         "north":"/d/shadow/room/tour/death/hall2.c",
        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
               "trees":"The trees are huge distorted oaks.",
        ]));
        set_smell("default",
           "You stretch your senses, but can smell nothing.");
     set_listen("default","You can hear the fast pace beating of your "+
        "heart, nothing more.");

}




