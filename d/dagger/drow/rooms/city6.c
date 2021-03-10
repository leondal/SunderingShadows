#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding through "
	"the existing structures around you. The wind blows back your "
	"hair as you wander through the city pathways."
	" To the west lies a soldier's barracks. There is an open doorway "
	"leading into the barracks and a pool of blood lays beneath "
	"it.%^RESET%^"
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
	"barracks":"Simple soldier barracks made of black obsidian stone.",
	"doorway":"The doorway lays open and nothing can be seen through it.",
	"pool":"The pool of blood has dried up and must have been from a "
	"while ago.",
	"blood":"You question yourself about what lies to the west "
	"because of this blood and also suspect a trap possibly being "
	"in the doorway.",
	"pool of blood":"The pool of blood has long since dried up.",
	"trap":"There is a trap on the doorway but it has been triggered "
	"and now lays broken against the door frame.",
	"frame":"The frame has a scythe style trap hanging against it.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/city7",
	"south":"/d/dagger/drow/rooms/city5",
	"west":"/d/dagger/drow/rooms/brk7"
    ]));
}
