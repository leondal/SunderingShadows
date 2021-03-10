#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("A destroyed armory");
    set_short("%^BOLD%^%^BLACK%^A destroyed armory%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This shop has been ruined, the counter destroyed to leave nothing more than "
"fragments of %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^strewn about the area. Pieces of shelving lie scattered "
"about the room, along with melted lumps of now-useless %^RESET%^metal%^BOLD%^%^BLACK%^, fused with flakes of "
"charcoal and chips of wood upon the ground. From the shape of a few that aren't entirely melted, you imagine "
"they might once have been suits of armor.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");
    set_items(([
      ({"armor"}) : "%^BOLD%^%^BLACK%^Several suits of armor have melted into the ground, now merely worthless "
"chunks of metal fused with charcoal and chips of wood.%^RESET%^",
    ]));
    set_exits( ([
      "west" : STREETS"street10"
    ]) );
}