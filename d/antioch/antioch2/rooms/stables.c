#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("Entrance of the Antioch Stables");
    set_long(
        "%^WHITE%^This is the entrance to the Antioch stables. It is a very large building with a huge entrance. The %^ORANGE%^ceiling%^WHITE%^ is arched high so the horses won't feel too claustrophobic. Enchanted %^ORANGE%^light%^WHITE%^ stones hang down from the ceiling, providing light to the stables without the threat of a fire. The %^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^loor%^WHITE%^ is made of dirt and some %^ORANGE%^hay%^WHITE%^ has been tracked in here. To the south looks like to be a tethering post to tie your horse up to. To the north are some stables and there are some more to the west. %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^is back to the east.
"
        );
    set_smell("default", "You can smell the sweat of horses mingled" +
              " with hay.");
    set_listen("default", "The horses are stomping about in their" +
               " stalls.");
    set_items(([
                   ({ "floor", "ground", "dirt" }) : "The floor is dirt in order to be" +
                   " gentler on the horses' hooves. Some hay has been tracked in" +
                   " by the stable hands.",
                   "hay" : "%^YELLOW%^Bits of hay have been tracked in from the stable hands" +
                   " and horses.",
                   "ceiling" : "The ceiling is high and arched. Chains hang down" +
                   " from it holding stones that have been enchanted with light.",
                   ({ "light", "stone", "enchanted stone", "light stone", "enchanted stones", "light stones", "stones" }) : "%^BOLD%^Stones that have been enchanted" +
                   " with a continual light spell are hung from the ceiling. It gives" +
                   " easy and constant light to the area without having to worry" +
                   " about the possibilities of fires.",
               ]));
    set_exits(([
                   "east" : ROOMS + "street6",
                   "west" : ROOMS + "stable3",
                   "north" : ROOMS + "stable1",
                   "south" : ROOMS + "stable2",
               ]));
}
