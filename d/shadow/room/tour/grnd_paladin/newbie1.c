//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>

inherit ROOM;

void create(){
    ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_short("This is the new player training forest.");
        set_long(
@BUILD
%^BOLD%^This is the new player training forest.%^RESET%^
This is a place for new players to practice using
their characters abilities. There are wimpy monsters
here, for practice fighting.

BUILD
);
        set_exits(([
       "west":"/d/shadow/room/tour/main.c",



        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
        set_smell("default","You can smell the pine trees.");
     set_listen("default","You can hear the birds and forest animals moving about.");

}
void init(){
    ::init();
        do_random_encounters(({"d/shadow/mon/rat.c",}),80,5);
}
