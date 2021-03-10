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
	" This part of the city lies along the south section of the lake "
	"surrounding it. To the north a row of barracks begins. To the "
	"east lies what appears to be a large black "
	"obsidian tower.%^RESET%^"
    );
    set_listen("default",
	"The wind howls a strangled cry which causes you to feel nervous "
	"about being here."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"barracks":"The barracks are merely stone structures. They most "
	"likely are living quarters for Drow soldiers.",
	"lake":"The lake is dark, murky and black as the night. You "
	"doubt even the drow swim in it. You also doubt you will "
	"ever swim in it either.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"tower":"%^BOLD%^%^BLACK%^The black obsidian tower appears to "
	"have no openings on it and above it hangs a huge black "
	"storm cloud.%^RESET%^",
	"cloud":"%^BOLD%^%^BLACK%^The black storm cloud seems to be "
	"a product of the tower as it hangs directly above it and "
	"seems not to move. It almost appears as though it is "
	"grinning at you.%^RESET%^",
	"street":"The street is made up of cobblestones and winds "
	"through the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
    "west":"/d/dagger/drow/rooms/city20",
	"east":"/d/dagger/drow/rooms/city40",
	"north":"/d/dagger/drow/rooms/city10"
    ]));
}
