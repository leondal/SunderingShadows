#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding through "
	"the existing structures around you. The wind blows back your "
	"hair as you wander through the city pathways."
	" To the west lies a soldier's barracks. A large black door lies "
	"open leading inwards to the barracks.%^RESET%^"
    );
    set_listen("default",
	"You hear a few voices chanting the Drow battle hymn, "
	"`Sok slather rocx', from within the barracks."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"barracks":"The barracks are made of black obsidian stone and "
	"bear no markings on the outside walls.",
	"doorway":"The doorway stands open and nothing inside it can "
	"be seen.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"south":"/d/dagger/drow/rooms/city4",
	"west":"/d/dagger/drow/rooms/brk8",
	"east":"/d/dagger/drow/rooms/city14",
	"north":"/d/dagger/drow/rooms/city6"
    ]));
}
