#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Entrance hall");
    set_long(
	"%^BLACK%^%^BLUE%^You enter the room in the %^MAGENTA%^regal "
	"building%^BLUE%^ and quickly your eyes adjust to the dim "
	"lighting. A large %^GREEN%^wooden%^BLUE%^ table made of old "
	"oak stands in the center of the room. Several chairs are "
	"located around the table. Fine %^CYAN%^vases and "
	"dishware%^BLUE%^ decorate the table. Inset on the west "
	"wall is a fireplace. Several figurines decorate the "
	"mantelpiece.%^RESET%^"
    );
    set_listen("default",
	"You hear the clanging of weapons and several drow shout "
	"occasionally."
    );
    set_smell("default",
        "There is a faint trace of polinic odour in the room."
    );
    set_items(([
	"table":"%^BOLD%^%^GREEN%^The table is made of old oaken wood "
	"and is decorated with vases and dishware.%^RESET%^",
	"vases":"%^MAGENTA%^The vases are actually quite nice to "
	"look at...but all worthless.",
	"dishware":"The dishes are dirty and all quite worthless "
	"except to eat off of.",
	"fireplace":"%^RED%^The fireplace contains no fire "
	"currently and is filled with ashes.",
	"chairs":"The chairs are made of hard oaken wood.",
	"mantelpiece":"Several figurines lay scattered about on "
	"the mantelpiece.",
	"figurines":"%^BLUE%^The figurines are made in the likeness "
	"of %^RED%^playing pieces%^BLUE%^ used to play `Azakkrps'. You "
	"remember this is the famous drow game of gambling and "
	"strategy.%^RESET%^"
    ]));
    set_exits(([
	"south": RPATH "city36",
	"west": RPATH "elite5"
    ]));
}
