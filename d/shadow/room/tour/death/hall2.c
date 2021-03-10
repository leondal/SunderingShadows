//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>

inherit ROOM;

void create(){
    ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_short("This is a clearing in the DarkWood.");
        set_long(
@BUILD
%^BOLD%^You step into a clearing, in the DarkWood%^RESET%^
This clearing is a hub of activity.  To the east is a open
air bar, with many patrons.  To the west is a shabby looking
building, from the smoke coming from the chimney, you assume
it to be an inn.
BUILD
);
        set_exits(([
       "south":"/d/shadow/room/tour/death/hall3.c",
       "east":"/d/shadow/room/tour/death/bar.c",
       "west":"/d/shadow/room/tour/death/inn.c",
       "north":"/d/shadow/room/tour/death/hall1.c",
        ]));



        set_items(([
               "road":"A small trail leads out of this section of forest.",
        ]));
        set_smell("default","You can smell the smoke from the inn.");
       set_listen("default","You can hear the laughing of people "+
          "from both the bar and the inn.");

}




