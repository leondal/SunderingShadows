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
	" You stand beside the %^MAGENTA%^regal building%^BLUE%^ "
	"which is located to the east of you. "
	"The %^BOLD%^lake%^RESET%^%^BLUE%^ lies to the north of you."
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
	"building":"There are no windows or doors on this side of the "
	"building and the wall is quite bare other than "
	"the %^RED%^red banner%^RESET%^ of Lloth which hangs from "
	"the roof.",
	"lake":"%^BLUE%^The lake is deep, dark and black. You decide not "
	"to swim here.%^RESET%^",
	"banner":"%^RED%^The banner bears the "
	"spider symbol of Lloth.%^RESET%^",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"west":"/d/dagger/drow/rooms/city28",
	"southeast":"/d/dagger/drow/rooms/city26"
    ]));
}
