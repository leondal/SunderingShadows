#include <std.h>

inherit HOTEL;
void create(){
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_property( "light" , 3);
    set_property("indoors" , 1);
    set_short("The Hotel Tharis");
    set_long(
@OLI
The Hotel Tharis.
There is a registry counter on the south side of the room.
The clerk will check you in and out. All of the rooms
here are very secure. We have never had a death or theft,
of any players or possessions since we opened.
This hotel has beds for rent. < help hotel > will get you
help on renting a room in the hotel.
OLI
);
    set_listen("default","You hear the shuffling of strangers moving around
the hotel.");
    set_smell("default","You hear the sounds of people moving about around
you. ");
    set_search("default","You look around aimlessly and find nothing
worthwhile.");
    set_exits( ([
     "west":"/d/tharis/Tharis/market2",
        "south":"/d/tharis/Tharis/estreet1"
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
