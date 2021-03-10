//d/tharis/road/road1.c//
#include <std.h>
#include <objects.h>
inherit ROOM;
void create()
{
    room::create();
    set_terrain(HILLS);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_short("Road to Darkwood and Tharis.");
    set_long(
"%^GREEN%^As you crest a ridge you realize that you are on the border between Darkwood and Tharis.To the south is the grand trade city of Tharis and to the north is the realm of Darkwood.The %^BOLD%^%^BLACK%^f%^RESET%^%^GREEN%^o%^GREEN%^r%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^t%^RESET%^%^GREEN%^ looms round you.You marvel at the rumours of the Elven civilization which lives in the forest.To the south you can see the grand towers of the city of Tharis, made rich by its exploitation of its natural resources."
        );
    set_smell("default", "The wonderful fragrances of the forest waft through your senses.");
    set_listen("default", " There is an unnatural quiet about the forest.");
    set_exits(([
                   "south" : "/d/tharis/road/road2",
                   "north" : "/d/darkwood/room/road16"
                   ]));
    set_items(([
                   "road" : "The road is deeply rutted by the eons of travle by heavily laidened wagons of
trade." ,
                    "forest" : "The forest is impenetrable around you, yet it seems to call for help."
                ]));
 }
