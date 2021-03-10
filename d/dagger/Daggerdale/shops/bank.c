#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_name("A destroyed bank");
    set_short("%^BOLD%^%^BLACK%^A destroyed bank%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This must once have been a large bank with thick granite walls. The room has "
"been %^RESET%^%^RED%^blasted%^BOLD%^%^BLACK%^, probably by numerous spells, and the walls look like they have "
"been clawed by giant beasts. The worst damage was done to the far wall where there must once have been a safe"
". It has been ripped apart, leaving nothing but a great hole.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_exits(([
      "west" : STREETS"street11",
    ]));
}