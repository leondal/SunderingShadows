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
    set_short("%^BOLD%^Entrance of Antioch's Grand Church");
    set_long(
        "%^WHITE%^The inside of the church is even more impressive than the outside. It is not lavish with expensive things, but the craftsmanship of the building itself is superb. The %^BOLD%^%^BLACK%^s%^WHITE%^tone %^BLACK%^b%^WHITE%^l%^BLACK%^oc%^WHITE%^k%^BLACK%^s%^RESET%^%^WHITE%^ fit together perfectly on the %^BOLD%^%^BLACK%^f%^WHITE%^lo%^BLACK%^o%^WHITE%^r%^RESET%^%^WHITE%^ and are completely level. %^BOLD%^%^BLACK%^Mortar%^RESET%^%^WHITE%^ fills in the small gaps between each stone, and it has been dyed to a matching gray shade. The %^BOLD%^%^WHITE%^c%^BLACK%^e%^BLACK%^i%^WHITE%^l%^BLACK%^i%^WHITE%^n%^BLACK%^g%^RESET%^%^WHITE%^ is flat and smooth and the walls look sturdy, supporting the architecture well. The great %^BOLD%^%^ORANGE%^a%^RESET%^%^ORANGE%^rchway%^WHITE%^ is just behind you and in front of you are some %^BOLD%^%^BLACK%^ste%^WHITE%^p%^BLACK%^s%^RESET%^%^WHITE%^ leading up to the main altar. %^BOLD%^%^BLACK%^Pas%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^ag%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^ys%^RESET%^%^WHITE%^ lead to the left and right, the doorways are also arched. Just standing in the entrance of the church you feel a sense of peace wash over you.
"
        );
    set_smell("default", "The soothing scent of incense is in the" +
              " air.");
    set_listen("default", "In the background you can hear the whispered" +
               " sounds of prayers.");
    set_items(([
                   ({ "stone", "stones", "blocks", "stone blocks", "stone block" }) : "The" +
                   " entire building is made out of perfectly made stone blocks. They" +
                   " have been flawlessly joined together and mortar smooths in the" +
                   " gaps to keep the wind out. Standing in the entrance way you" +
                   " can see that the stones are quite thick, about a foot deep. It" +
                   " must have been some work to build this impressive church.",
                   "floor" : "The floor is also made out of the perfectly connecting" +
                   " stone blocks and looks to be kept quite clean.",
                   "ceiling" : "The ceiling is made out of the smooth stone blocks." +
                   " They look as though they are held well in place, but they" +
                   " would surely crush anything they should happen to fall upon.",
                   ({ "archway", "doorway" }) : "The archway here shows that the stone" +
                   " blocks used to create this building are at least a foot in" +
                   " thickness. All the doorways are arched in a curving manner and" +
                   " none of them actually have doors. This church is a sanctuary" +
                   " to all who deserve protection.",
                   "mortar" : "Gray mortar fills in the tiny gaps between the stone" +
                   " blocks. It is almost so perfectly the color of the stone that" +
                   " you can hardly tell it's there.",
                   ({ "step", "steps", "stone steps" }) : "A few small stone steps lead" +
                   " to the east, which appears to be the main altar area.",
                   ({ "passageway", "passageways" }) : "There are two passageways here," +
                   " one leads to the north and the other to the south.",
               ]));
    set_exits(([
                   "west" : ROOMS + "street14",
                   "south" : ROOMS + "church2",
                   "north" : ROOMS + "church3",
                   "east" : ROOMS + "church4",
               ]));
}
