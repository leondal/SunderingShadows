#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(1);
    set_name("A ruined shop");
    set_short("%^BOLD%^%^BLACK%^A ruined shop%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand in a ruined shop, blasted apart and wrecked by what could only have "
"been a bloody battle. The floor is marred by %^RESET%^%^RED%^blood stains %^BOLD%^%^BLACK%^from what has to "
"have been several bodies judging by their size. The shelves are smashed, and the door hangs loosely from "
"broken hinges, swinging in the wind with a quiet creak.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "east" : STREETS"street11"
    ]) );
}