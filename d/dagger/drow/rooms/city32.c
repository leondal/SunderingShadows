#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    find_object_or_load("/d/dagger/drow/rooms/city35");
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding "
	"through the existing structures around you. The wind blows "
	"back your hair as you wander through the city pathways."
	" To the north lies the northern border of "
	"the %^BOLD%^%^BLUE%^lake%^RESET%^%^BLUE%^ which surrounds "
	"the city. Directly to your south lies the %^RED%^north "
	"gates%^BLUE%^ of the temple walls. \n%^RED%^The gates "
	"lay open but a shimmering field of energy fills the passageway "
	"leading through the gates.%^RESET%^"
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
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"lake":"The lake is deep, murky and black as the night. You feel "
	"as though something in the water is watching you.",
	"gates":"%^RED%^A shimmering field of energy fills the passageway "
	"through the gates.%^RESET%^",
	"wall":"The temple walls seem to be alive with energy and a "
	"humming noise can be heard coming from within them.",
	"field":"%^BOLD%^%^RED%^The field of energy seems to weaken "
	"at points. Perhaps you could pass through it unharmed if you "
	"were quick about it.%^RESET%^",
	"street":"The street is made up of cobblestones and winds "
	"through the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"west":"/d/dagger/drow/rooms/city31",
	"east":"/d/dagger/drow/rooms/city33",
	"gate":"/d/dagger/drow/rooms/court1"
    ]));
}
