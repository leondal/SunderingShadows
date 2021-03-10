#include <std.h>
#include "../dagger.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("A destroyed jail");
    set_short("%^BOLD%^%^BLACK%^A destroyed jail%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This room, made of granite, looks like it was the last stand for whoever tried "
"to defend this city. It appears to have once been a jail, with stout iron cell doors, and %^RESET%^%^WHITE%^"
"heavy walls%^BOLD%^%^BLACK%^. Those walls are now crumbled in several places, leaving chunks of stone and "
"rubble scattered about amidst the melted remains of the iron cells. In a few of the cells that are still "
"partially intact, the %^WHITE%^skeletal remains %^BLACK%^of bodies can be seen strewn across the floor, while "
"in one, the mutilated corpse of a man has been pinned to the back wall, locked eternally in the melted "
"remains of his prison. At his feet lies a small, bright %^RESET%^badge%^BOLD%^%^BLACK%^.%^RESET%^");
    set_smell("default","An acrid, burnt smell fills the air.");
    set_listen("default","It is deathly quiet here.");

    set_items( ([
	({"man","corpse","remains"}) : "%^BOLD%^%^BLACK%^The mutilated remains of one man are pinned to the back "
"wall, trapped in the melted remains of a large jail cell. His own features are marred beyond recognition, "
"parts of his skin melted and fused with the wall behind him, from some horrific event. The only "
"distinguishing feature is the badge still pinned to his chest, which seems to have survived whatever happened "
"here. %^WHITE%^SHERIFF %^BLACK%^is written across it in large letters. At his feet lies a small, bright "
"%^RESET%^badge%^BOLD%^%^BLACK%^ made of silver.%^RESET%^",
	"badge" : "%^CYAN%^This finely %^BOLD%^%^WHITE%^polished %^RESET%^%^CYAN%^badge is crafted from glorious "
"%^BOLD%^%^WHITE%^silver metal%^RESET%^%^CYAN%^. The front displays a detailed %^YELLOW%^eng%^BLACK%^ra%^YELLOW%^"
"ving %^RESET%^%^CYAN%^of a magnificent %^YELLOW%^roc %^RESET%^%^CYAN%^clutching two pairs of "
"%^BOLD%^%^BLACK%^crossed daggers %^RESET%^%^CYAN%^within its talons. Beneath this image is the word "
"%^BLUE%^\"DEPUTY\"%^CYAN%^ written in common in bold lettering. This is clearly a badge issued "
"to %^RESET%^law enforcement %^CYAN%^of a city.%^RESET%^"
    ]) );
    set_exits( ([
      "east" : STREETS"street32",
    ]) );
}