#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors",1);
    set_name("A ruined building");
    set_short("%^BOLD%^%^BLACK%^A ruined building%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This small room has been damaged by whatever ruined the building. A few burnt "
"threads remain of the rug, leaving no hint as to its original color. What must have once been a hanging lamp "
"has been melted, now nothing more than a malformed length of %^RESET%^metal %^BOLD%^%^BLACK%^hanging from the "
"wall. The wooden walls and floor are not perhaps as badly ruined as the rooms downstairs, but still carry "
"great %^RESET%^%^RED%^scorch marks %^BOLD%^%^BLACK%^along their length.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "stairs" : SHOPS"wood_back",
    ]));
}
