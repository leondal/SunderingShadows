#include <std.h>
#include "../tomb.h"

inherit ROOM;

void create()
{
    ::create();
    set_indoors(1);
    set_property("light",2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("smithy",1);
    set_name("Forge");
    set_short("%^BOLD%^%^BLACK%^Forge%^RESET%^");
    set_long(query_short() + "
%^RED%^This place has thick stone walls, blackened with soot from the nearly perpetual fire. The northeast corner has a wall about three foot high across it that encloses a fire pit. Several %^BOLD%^%^BLACK%^a%^RED%^nvi%^BLACK%^l%^RED%^s%^RESET%^%^RED%^ sit about the room, along with barrels of dirty water used for quenching the metals, various %^BOLD%^%^BLACK%^t%^BLACK%^o%^RED%^o%^BLACK%^l%^BLACK%^s%^BLACK%^,%^RESET%^%^RED%^ and of course sharpening stones for the edged weapons. You sweat profusely from the %^BOLD%^%^RED%^heat of the forging fire that is kept roaring.%^RESET%^
");
    set_smell("default", "%^RED%^Smoke from the fire irritates your nostrils.");
    set_listen("default", "%^BOLD%^%^BLACK%^The coals in the fire pop and crackle.");
    set_exits(([
                   "north" : ROOMS + "/village",
                   ]));
    set_items(([
                   ({"anvil", "anvils"}): "They are large blocks of metal or stone in various shapes to form the metal over.",
                   ({"tools", "stones"}): "Small and large hammers, piercing tools, vises to clamp the metal in for bending, sharpening stones, and other things you probably don't know the names of or what they do., fire : %^BOLD%^%^RED%^It seems to be fueled from both wood and coal, with baffles used to pump extra air in at the base to make it even hotter when needed.",
                   ]));
}
