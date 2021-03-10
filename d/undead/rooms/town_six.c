#include "../undead.h"

inherit ROOM;

void create() 
{
    ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);

    set_property("indoors", 1);
    set_light(2);

    set_short("%^BLUE%^You are in an underground tunnel.%^RESET%^");

    set_long("%^BLUE%^You are in what appears to be an underground tunnel.\n"
        "%^CYAN%^Apparently the ogre's must have dug a hole underneath the "
        "city gates so that they could make a quick escape if ever the city "
        "were invaded. Obviously the cowards are now using the tunnel as a "
        "source of revenues, charging adventurers a toll for its use. Where "
        "it leads is anyone's guess.");
 
    set_exits(([
        "up"        :TOWN+"room24",
        "east"      :TOWN+"ditch2"
             ]));

    set_smell("default", "Stale, moist air fills the tunnel.");
    set_listen("default" ,"You can hear very little underneath all of this dirt.");

}
