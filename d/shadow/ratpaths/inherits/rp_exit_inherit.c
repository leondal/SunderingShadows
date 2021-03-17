#include <std.h>
#include "../common.h"

inherit ROOM;

void create(){
    ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_light(-1);
    set_short("%^BOLD%^%^BLACK%^Underpaths entrance%^RESET%^");
    set_long(query_short() + "\n" + "%^ORANGE%^Soil and stone have been forcibly "+
    "plowed through in order to create this tunnel. The well-maintained passageway is wide "+ 
    "enough that you don't feel cramped here. Wooden beams support the walls and "+ 
    "ceiling, and show no signs of rot. The floor is made from rough stones. "+ 
    "A ladder leads up to a dark hole in the ceiling.\n");
    set_smell("default", "%^CYAN%^A breeze of fresh air flows down from above.");
    set_listen("default", "The earth silences all distant sounds.");
    set_items(([
                   ({"floor", "road", "stone road"}):"Flat stones form the path beneath your feet.",
                   "beams":"Lumber that supports this tunnel is of various quality, but placed thoroughly.",
                   "soil":"Roots push through the soil from the surface overhead.",
                   "roots":"Roots, some rather long and thick, hang from the ceiling. Most of them are cut back to keep the path clear.",
                   ({"hole", "ladder"}):"The ladder leads many paces up.",
                   "tunnel":"You're in the tunnel. This is it. A tunnel. And you're in it.",
                   ]));
}
