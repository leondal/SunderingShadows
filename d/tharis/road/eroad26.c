#include <std.h>
#include "../eroad.h"
inherit ROOM;

void create()
{
    ::create();
    set_travel(DIRT_ROAD);
    set_terrain(LIGHT_FOREST);
    set_short("%^ORANGE%^Clearing before the lodge");
    set_long(query_short() + "\n" + "%^GREEN%^The road here expands into a clearing infront of a long stone %^BOLD%^%^BLACK%^ho%^RESET%^%^GREEN%^u%^BOLD%^%^BLACK%^se%^RESET%^%^GREEN%^ that serves as a hunters lodge. Thick smoke rises from hole in the roof, and aroma of cooked food invites from the inside. In front of the house several small %^ORANGE%^te%^GREEN%^n%^GREEN%^t%^ORANGE%^s%^GREEN%^ have been pitched into a camp, several %^ORANGE%^hunters%^GREEN%^ wander about the %^GREEN%^f%^RED%^ire%^GREEN%^p%^RED%^it%^GREEN%^. The path here splits into three.%^RESET%^
");
    set_items(([
                   "house" : "%^BOLD%^%^BLACK%^Stone-walled house with straw roof, hole in the middle serves as a chimney.",
                   "tents" : "%^ORANGE%^Small tents for hunters to spend a night in.",
                   "firepit" : "%^RED%^Firepit with cooking rack over it. Venison roasts slowly over the fire.",
                   "hunters":"%^ORANGE%^Various folk, mostly human and half-elven men."
                   ]));

    set_smell("default", "Hints of the forest to the north reach your nostrils.");
    set_listen("default", "The sounds of people milling about reach your ears.");
    set_exits(([
                   "northwest" : ROOMS + "eroad25",
                   "southwest" : ROOMS + "eroad27",
                   /* "lodge" : ROOMS + "hlodge", */
                   "north" : "/d/tharis/conforest/rooms/path35",
                   ]));
}
