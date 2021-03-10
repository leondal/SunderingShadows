#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("%^BOLD%^Grand Church of Antioch");
    set_long(
        "%^WHITE%^There is a grand %^BOLD%^%^WHITE%^stai%^RESET%^%^WHITE%^r%^WHITE%^ case here, it spirals up for at least another level and probably beyond, but it is hard to see because it winds out of sight. The chants of acolytes drift to your ears from upstairs. The second %^BOLD%^%^WHITE%^floor%^RESET%^%^WHITE%^ must be where they study and sleep. There are %^BOLD%^%^BLACK%^s%^WHITE%^t%^BLACK%^one %^WHITE%^sc%^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^nces%^RESET%^%^WHITE%^ here that hold some of the %^MAGENTA%^in%^CYAN%^c%^MAGENTA%^en%^CYAN%^s%^CYAN%^e%^WHITE%^ that is throughout the church. The acolytes are probably responsible for keeping them lit and fresh.
"
        );
    set_smell("default", "The scent of incense is relaxing.");
    set_listen("default", "You can hear the chants drifting down from" +
               " the acolytes upstairs.");
    set_items(([
                   ({ "sconce", "sconces", "stone sconces" }) : "The sconces are carved" +
                   " out of the stone blocks themselves, actually part of the wall." +
                   " They are shaped like roses, and they hold" +
                   " incense.",
                   "incense" : "There are sticks of incense in the sconces along" +
                   " the walls. The incense has a curious relaxing quality to it" +
                   " and you feel safe and at peace because of it.",
                   ({ "stone", "stones", "blocks", "stone blocks", "stone block" }) : "The" +
                   " entire building is made out of perfectly made stone blocks. They" +
                   " have been flawlessly joined together and mortar smooths in the" +
                   " gaps to keep the wind out.",
                   "floor" : "The floor is also made out of the perfectly connecting" +
                   " stone blocks and looks to be kept quite clean.",
                   "doorway" : "The doorway here shows that the stone blocks used to" + " create this building are at least a foot in thickness. You can't" +
                   " imagine anything capable of breaking through the walls.",
                   "mortar" : "Gray mortar fills in the tiny gaps between the stone" +
                   " blocks. It is almost so perfectly the color of the stone that" +
                   " you can hardly tell it's there.",
                   ({ "stairs", "stone stairs", "stair case", "staircase" }) : "The large" +
                   " stone stair case here winds up at least one level. You can't" +
                   " see much of the ceiling from this view, the stair case simply" +
                   " seems to go on forever. It is made out of large stone blocks" +
                   " that look very sturdy.",
               ]));
    set_exits(([
                   "south" : ROOMS + "church1",
                   "up" : ROOMS + "church7",
               ]));
}
