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
	"%^BLUE%^The city street is made of cobblestones winding "
	"through the existing structures around you. The wind "
	"blows back your hair as you wander through the city pathways."
        " To the north the temple wall towers above you. Your skin "
	"crawls thinking about what lies behind it."
    );
    set_listen("default",
	"A faint humming sound comes from behind the temple wall."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"wall":"The black obsidian temple wall is unclimable and towers "
	"twenty feet above you.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
        "pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"west":"/d/dagger/drow/rooms/city18",
	"east":"/d/dagger/drow/rooms/city12"
    ]));
}
