#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding through "
	"the existing structures around you. The wind blows back your "
	"hair as you wander through the city pathways."
	" To the east lies an open doorway leading into the drow soldier "
	"barracks. To the west, towering above you, lies a temple wall."
    );
    set_listen("default",
	"You can hear a strange humming sound coming from behind the temple "
	"wall."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
        "wall":"The temple wall is twenty feet high above you and is made "
	"of unclimably smooth black obsidian stone.",
	"hint":"Here is a hint clever one: To enter the temple you enter the "
	"walls from the north gate...the south one is trapped heavily!",
	"barracks":"The barracks are made of simple black obsidian stone and "
	"bear no markings.",
	"doorway":"The doorway hangs open but nothing can be seen through "
	"it.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"south":"/d/dagger/drow/rooms/city12.c",
	"north":"/d/dagger/drow/rooms/city35.c",
	"west":"/d/dagger/drow/rooms/brk4.c"
    ]));
}
