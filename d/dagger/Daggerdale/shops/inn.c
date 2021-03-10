#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors",1);
    set_name("A ruined inn");
    set_short("%^BOLD%^%^BLACK%^A ruined inn%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This building was obviously multiple stories, but the top floors have collapsed "
"and the stairs are gone. Rubble and splinters of wood are strewn about the room. It is obvious that there was "
"fierce fighting here, as there are more blast marks then normal, and numerous %^RESET%^%^RED%^blood stains "
"%^BOLD%^%^BLACK%^all over the room.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "out" : STREETS"street29",
    ]));
}
