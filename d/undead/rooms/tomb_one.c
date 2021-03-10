#include <std.h>
#include "../undead.h"

inherit ROOM;
object setter;

void create() 
{
    ::create(); 

    set_name("Tomb Road");
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_climate("desert");
 
    set_short("You are traveling along the Tomb Road");
 
    set_long("%^BOLD%^You are in a vast desert.%^RESET%^\n"
        "%^MAGENTA%^To the east and west you see a parched desert.  "
        "%^MAGENTA%^While the path you are traveling on appears to be "
        "almost a tunnel running through the very desert.  The sands "
        "to your side and above you are being held at bay by and "
        "invisible force.  You only hope that after all this time "
        "the barrier is still strong enough to withstand the weight "
        "of the sand.");
 
    set_exits(([
        "north"     :HALL+"temproad2",
             ]));

    set_smell("default","You catch the rotten stench of death.");
    set_listen("default","You hear the faint sound of whailing in the distance.");

    setter = find_object_or_load(SETTER); // Places random exit in the desert -Ares
}