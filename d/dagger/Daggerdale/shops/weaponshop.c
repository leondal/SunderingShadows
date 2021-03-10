#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_property("indoors", 1);
    set_name("A ruined shop");
    set_short("%^BOLD%^%^BLACK%^A ruined shop%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Once probably a shop, this building is now utterly destroyed. %^YELLOW%^Light "
"%^BLACK%^filters in from holes in the stone ceiling, shattered by some unknown force that has left the room "
"in ruins. Scorch marks mar the partial remains of what might have once been the shop counter, with %^RESET%^"
"%^CYAN%^melted glass %^BOLD%^%^BLACK%^that has oozed down from the display case and is now frozen part-way to "
"the floor. Small mounds of fused metal are scattered along the floor, perhaps the remains of weapons that "
"were once kept here.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits( ([
      "north" : "/d/dagger/Daggerdale/streets/street19",
    ]) );
}