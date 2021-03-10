#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",1);  
    set_property("light",1);
    set_travel(FOOT_PATH);
    set_terrain(ROCKY);
    set_name("A tunnel deep in the earth");    
    set_short("%^RESET%^%^ORANGE%^A tunnel deep in the earth%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Hollowed from the granite stone of the "
"%^RESET%^%^CYAN%^Barrier Mountains%^BOLD%^%^BLACK%^, this passageway has "
"been painstakingly carved to create an underground tunnel system for the "
"higher levels of the %^RESET%^%^BLUE%^Underdark%^BLACK%^%^BOLD%^.  "
"Chisel and pick marks are clearly evident along the floor, walls and "
"ceiling, though only the floor has seen any degree of smoothing.  Rusty, "
"iron %^RESET%^%^ORANGE%^hooks %^BOLD%^%^BLACK%^have been set into the "
"walls every fifty feet or so.  Most are empty, but a few still support "
"sputtering %^RESET%^%^ORANGE%^oil lanterns%^BOLD%^%^BLACK%^.  These "
"along with the phosphorescent %^RESET%^%^CYAN%^lichen %^BOLD%^%^BLACK%^"
"that grows in the crevices provide just enough light to see "
"by.%^RESET%^\n");
    set_smell("default","The air is chill and damp, smelling of earth, stone and fresh water.");
    set_listen("default","The rushing sound of a river reaches your ears.");

    set_items(([
      ({"river","water"}) : "%^RESET%^%^BLUE%^You can't make out the "
"river but you can hear it nearby.%^RESET%^",
      ({"walls","floor","wall","ceiling"}) : "%^BOLD%^%^BLACK%^The walls, "
"floors and ceilings are made from the hard stone of the %^RESET%^%^CYAN%^"
"Barrier Mountains%^BOLD%^%^BLACK%^.  Chisel and pick marks mar the "
"surfaces, leaving lots of niches for lichen to grow within.  Only the "
"floor seems to have received any manner of smoothing.%^RESET%^",
      ({"chisel","marks","pick"}) : "%^BOLD%^%^BLACK%^Biting into the "
"hard stone of the %^RESET%^%^CYAN%^Barrier Mountains%^BOLD%^%^BLACK%^, "
"these marks cover the floor, walls and ceiling of this tunnel.  Clear "
"evidence that manual, probably slave labor was used to expand this "
"tunnel system.%^RESET%^",
      ({"mountains","mountain"}) : "%^BOLD%^%^BLACK%^The cold granite "
"stone that these tunnels are carved from appear to be the same stone "
"that makes up the %^RESET%^%^CYAN%^Barrier Mountain%^RESET%^ "
"range.%^RESET%^",
      ({"rust","hooks","hook"}) : "%^BOLD%^%^BLACK%^Drilled into the hard "
"stone of the walls, most are empty or beyond use but some of the hooks "
"still hold a few sputtering oil lanterns.",
      ({"lantern","lamps","lanterns"}) : "%^RESET%^%^ORANGE%^Simple "
"copper pots filled with oil and capped with a stone disk through which a "
"wick has been fed, these lamps sputter and flicker offering poor "
"lightning to the tunnel system.  They hang from old rusty looking iron "
"hooks that have been drilled into the hard stone of the wall every fifty "
"feet or so.%^RESET%^",
      ({"lichen","phosphorescene"}) : "%^RESET%^%^CYAN%^Growing within a "
"few of the crevices left by the deeper tool marks, you can make out the "
"faint glow of phosphorescent lichen.  The glow barely aids the "
"sputtering oil lamps in illuminating this tunnel system.",
    ]));

    set_exits(([
      "southeast" : TUNNEL"tunnel13",
      "west" : TUNNEL"tunnel15",
    ]));
}
