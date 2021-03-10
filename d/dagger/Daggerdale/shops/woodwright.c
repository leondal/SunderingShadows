#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors",1);
    set_name("A ruined shop");
    set_short("%^BOLD%^%^BLACK%^A ruined shop%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This building has been completely %^RESET%^%^RED%^destroyed%^BOLD%^%^BLACK%^. "
"The original %^RESET%^%^ORANGE%^wood %^BOLD%^%^BLACK%^construction has been burned and what look like half "
"completed %^RESET%^%^ORANGE%^wood projects %^BOLD%^%^BLACK%^are also charred, now ruined beyond repair. "
"Several large %^RESET%^%^RED%^scorch marks %^BOLD%^%^BLACK%^mar the walls, with broken hinges as all that "
"remains of the shop doors.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_items(([
      ({"chairs","tables"}) : "%^BOLD%^%^BLACK%^All around the room are shards of wooden projects.%^RESET%^",
    ]));

    set_exits(([
      "out" : STREETS"street16",
      "back" : SHOPS"wood_back",
    ]));
}
