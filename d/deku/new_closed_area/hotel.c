#include <std.h>
#include "/d/shadow/mon/melnmarn.h"
inherit HOTEL;
void create(){
    ::create();
    set_property( "light" , 3);
    set_property("indoors" , 1);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_short("The Yawning Portal");
    set_long(
@GRAY
       %^YELLOW%^Welcome to the Yawning Portal%^RESET%^
There is a registry counter on the south side of the room.
The clerk will check you in and out. All of the rooms
here are very secure. We have never had a death or theft
of any players or possessions since we opened.
This hotel has rooms for rent. %^YELLOW%^< help hotel >%^RESET%^ will get you
help on renting a room in the hotel.
GRAY
);
    set_listen("default","You hear the shuffling of strangers moving around
the hotel.");
    set_listen("default","You hear the snoring of sleeping adventurers.");
    set_search("default","You look around aimlessly, and find nothing
worthwhile.");
    set_exits( ([
        "east":"/d/deku/new/town1"
             ]) );
    set_rooms(([
        "westgroup":6,
        "eastgroup":5,
        "southroom":3,
        "singleroom":1,
        "doubleroom":2,
        "tripleroom":3,
        "quadroom":4,
        ]));
    set_cost(10);
} 
