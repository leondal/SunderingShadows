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
	" The city street opens up into a larger open area. To the north "
	"stands a building that appears better crafted than the others "
	"and lends itself to house "
	"occupants of a higher status than most buildings seen so far. "
	"The %^RED%^red banners%^BLUE%^ of Lloth hang from the roof of "
	"the building. A large open doorway can be located to the "
	"north a means of entering the building. "
	"To the west the chain link fence of the slave compound continues "
	"and from here "
	"you can see it molds into a tunnel shape and crosses a bridge "
	"before meeting an opening in the cavern wall.%^RESET%^"
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
	"building":"The building before you is a regal sight indeed, "
	"however you suspect it does not house nobles, but instead..."
	"highly trained Drow warriors.",
	"fence":"The large chain fence cannot be entered from here.",
	"banners":"%^RED%^Two large red banners of Lloth hang down from "
	"the roof of the building.%^RESET%^",
	"doorway":"%^BLUE%^The open doorway is dark and evil seems to "
	"seep out of it.%^RESET%^",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"northwest":"/d/dagger/drow/rooms/city29",
	"north":"/d/dagger/drow/rooms/elite1",
	"east":"/d/dagger/drow/rooms/city27",
	"south":"/d/dagger/drow/rooms/city25"
    ]));
}
