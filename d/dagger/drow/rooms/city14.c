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
	" To the north is a building which appears to be a shop of some "
	"kind or another."
    );
    set_listen("default",
	"You hear the clanging of weapons being tested or forged."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"building":"A sign hangs above the doorway that leads into the "
	"building to the north.",
	"sign":"The sign bears the symbols of weapons upon it.",
	"doorway":"The open doorway appears to an entrance to the building "
	"to the north.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/weapons",
	"west":"/d/dagger/drow/rooms/city5",
	"east":"/d/dagger/drow/rooms/city15"
    ]));
}
