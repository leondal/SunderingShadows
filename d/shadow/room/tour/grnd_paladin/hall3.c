//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>

inherit ROOM;

void create(){
    ::create();
        set_property("indoors",0);
        set_property("light",2);
     set_short("This is the begining of a long hall.");
        set_long(
@BUILD
%^BOLD%^You continue down the long hall%^RESET%^
You do not see anything interesting in this part of the hall...But you do see fingers that have been cut off by a dull knife.



BUILD
);
        set_exits(([
       "south":"/d/shadow/room/tour/hall4.c",


       "north":"/d/shadow/room/tour/hall2.c",
        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
        set_smell("default","You can smell the pine trees.");
     set_listen("default","You can hear the birds and forest animals moving about.");

}




