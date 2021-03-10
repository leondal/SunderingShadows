#include <std.h>
#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("Chamber");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_climate("desert");
    set_property("no teleport", 1);

    set_short("%^BOLD%^%^BLACK%^You are in a Chamber%^RESET%^");
 
    set_long("%^BOLD%^BLACK%^You stand in a chamber shaped like a perfect "
        "cube.  It contains a large oaken table in its center, which holds a large "
        "basin of %^RED%^blood%^BOLD%^%^BLACK%^ on it. Seated around it are several "
        "respectable looking gentelmen, except for the fact that there fine clothes "
        "are dotted with red blood stains.");
 
    set_exits(([
        "east"      :HALL+"hall9"
             ]));

    set_smell("default","You smell a hard bitter odor.");
    set_listen("default","You can hear wind blow through the room.");

}
