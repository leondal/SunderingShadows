#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("A ruined bakery");
    set_short("A ruined bakery");
    set_long("%^BOLD%^%^BLACK%^This room is small, and has been utterly destroyed. A %^RESET%^%^WHITE%^gla"
"%^WHITE%^s%^RESET%^%^WHITE%^s co%^BOLD%^u%^RESET%^%^WHITE%^nter %^BOLD%^%^BLACK%^has been shattered, and "
"shards of %^RESET%^%^ORANGE%^tables %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^chairs %^BOLD%^%^BLACK%^lay "
"everywhere.  In the back you see a kitchen that has been likewise %^RESET%^%^RED%^d%^BOLD%^%^BLACK%^e%^RESET%^"
"%^RED%^str%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^yed.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");
    set_items(([
      ({"chair","tables"}) : "%^BOLD%^%^BLACK%^All around the room are wooden chips and shards, as the only remains of the tables and chairs.%^RESET%^",
      ({"counter" }) : "%^BOLD%^%^BLACK%^The %^RESET%^%^WHITE%^glass counter%^BOLD%^%^BLACK%^, once a work of "
"art, has been shattered.%^RESET%^",
    ]));
    set_exits(([
      "south" : STREETS"street7",
    ]));
}
