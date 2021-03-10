#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_indoors(1);
    set_property("light", 2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("smithy", 1);
    set_name("Weaponsmith's workroom");
    set_short("Weaponsmith's workroom");
    set_long("%^RED%^Here in the back of the shop, you see a large %^CYAN%^tro%^BOLD%^%^CYAN%^u%^CYAN%^g%^RESET%^%^CYAN%^h%^RED%^ of %^BLUE%^water,%^RED%^ black smith tools, and several different types of sharpening %^BOLD%^%^WHITE%^s%^BLACK%^tones.%^RESET%^%^RED%^ This must be where the weapons smith fixes broken blades or even makes new ones. Several different types of weapons in various stages of being madeare hung in racks around the room. The floor looks like it hasn't been swept in a while and there is even a %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^ro%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^m%^RED%^ that has started gathering cobwebs in the back. Soot %^ORANGE%^st%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^in%^BOLD%^%^BLACK%^s%^RESET%^%^RED%^ the floor, walls, and ceiling here.
"
        );
    set_smell("default", "The smell of smelted iron hangs in the air.");
    set_listen("default", "The cooling metals pop and groan from time to time.");
    set_exits(([
                   "south" : "/d/antioch/antioch2/rooms/weapon",
                   ]));
    set_items(([
                   "trough" : "It is a large wooden trough full of water and absolutely" +
                   " covered with soot stains.",
                   "broom" : "A broom stands in the corner, covered in cobwebs.",
                   ({ "tools", "blacksmith tools" }) : "These tools are used for heating" +
                   " up and shaping weapons. There's a forge, a bellows, some tongs" +
                   " and a few more items.",
                   ({ "stones", "stone", "sharpening stones" }) : "These stones are" +
                   " used for sharpening weapons. There are several different types," +
                   " each suited for certain types of weapons or metals.",
                   ({ "stains", "soot stains" }) : "Soot stains cover everything from" +
                   " the floor to the chair and desk, even on some of the walls." +
                   " Only the ceiling and weapons seem to be untouched by them.",
                   ({ "dirt", "dust", "mud" }) : "The floor is splattered with mud and" +
                   " dirt, and a thin layer of dust lays on the rest of the floor." +
                   " Looks like the weapons smith has been too busy to sweep.",
               ]));
}
