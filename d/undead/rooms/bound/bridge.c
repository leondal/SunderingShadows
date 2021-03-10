#include "../../undead.h"

inherit ROOM;

void create() 
{
    ::create();

    set_name("A bridge over a river");
    set_terrain(BOATS);
    set_travel(DIRT_ROAD);
    set_climate("temperate");
    set_property("light", 2);
    set_property("indoors", 0);

    set_short("%^BLUE%^You are on a bridge%^RESET%^");

    set_long("%^BOLD%^You stand on a bridge crossing the River of Sorrows.  \n%^RESET%^"
        "%^BLUE%^The river rushes under your feet with an incredible strength.  "
        "You guess that anyone who might slip off of this bridge would be crushed "
        "by the current in a matter of seconds. On that note, you begin to "
        "watch your steps more closely.%^RESET%^");
 
    set_exits(([
        "east":DES+"desert_8,0",
        "west":BO+"path15"
             ]));

    set_smell("default","You smell the fresh water beneath you.");
    set_listen("default","You can hear nothing over the roar of the river.");

}
