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
%^BOLD%^This is The begining of a very long hall%^RESET%^
It looks as to be a hall that connects rooms in which to train in.
You may go east or south, each one will take you to a different part
of training, you should go south or north if you wish to continue.

BUILD
);
        set_exits(([
       "south":"/d/shadow/room/tour/main.c",
       "west":"/d/shadow/room/tour/gs_store.c",
       "north":"/d/shadow/room/tour/hall2.c",
        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
        set_smell("default","You can smell the pine trees.");
     set_listen("default","You can hear the birds and forest animals moving about.");

}




