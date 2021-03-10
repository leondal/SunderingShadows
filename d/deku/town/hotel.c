#include <std.h>

inherit HOTEL;
void create(){
    ::create();
    set_property( "light" , 3);
    set_property("indoors" , 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_short("Verbobone Hotel");
    set_long(
@GRAY
       %^YELLOW%^Welcome to the Verbobone Hotel%^RESET%^
There is a registry counter on the south side of the room.
The clerk will check you in and out.  All of the rooms
here are very secure.  We have never had a death or theft,
of any players or possessions while they slept since we opened.
This hotel has rooms for rent. %^YELLOW%^< help hotel >%^RESET%^ will get you
help on renting a room in the hotel.
GRAY
);
    set_listen("default","You hear the snoring of sleeping adventurers.");
    set_search("default","You poke around aimlessly and find nothing
worthwhile.");
    set_exits( ([
        "north":"/d/deku/town/road5"
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
