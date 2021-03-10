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
	" To the west is the %^MAGENTA%^regal building%^BLUE%^ and to "
	"the north lies the edge of "
	"%^BOLD%^lake%^RESET%^%^BLUE%^.%^RESET%^"
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
	"building":"The wall of the building is bare of any windows or "
	"doors. The only marking upon the wall is "
   "the %^RED%^red banner%^RESET%^ hanging from its roof.",
	"banner":"%^RED%^The banner "
	"bears the dreaded symbol of Lloth.%^RESET%^",
	"lake":"%^BLUE%^The lake is cold, dark, black and deep. "
	"Somehow you are sure swimming here would be deadly.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"southwest":"/d/dagger/drow/rooms/city27",
	"east":"/d/dagger/drow/rooms/city31"
    ]));
}
