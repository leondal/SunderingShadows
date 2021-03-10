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
    set_long(query_short() + "\n" + "%^ORANGE%^This is a rough tunnel dug in the soil and stone you're in. It is not cramped and appears to be well-maintained. All wooden beams that support the tunnel seems to be in decent condition, with no sign of rot. Floor of this tunnel is layered with stone. There is a ladder that leads up into a dark hole in the ceiling.\n");
    set_smell("default", "%^CYAN%^Breeze of fresh air flows from the hole in the ceiling.");
    set_listen("default", "Earth silences all distant sounds.");
    set_items(([
                   ({"floor", "road", "stone road"}):"Stones cut flat and placed to form a road.",
                   "beams":"Lumber that supports this tunnels is of various quality, but placed thoroughly.",
                   "soil":"Dirt plants take roots in.",
                   "roots":"Some roots, some are long and thick, some hang from the ceiling. Most of them are cut to clear the tunnel.",
                   ({"hole", "ladder"}):"The ladder leads many paces up.",
                   "tunnel":"You're in the tunnel. This is it. A tunnel. And you're in it.",
                   ]));
}
