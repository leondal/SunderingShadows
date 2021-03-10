#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
    find_object_or_load("/d/dagger/drow/rooms/city35");
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding through "
	"the existing structures around you. The wind blows back your "
	"hair as you wander through the city pathways."
	" The city road opens into  clearing here. To the north lies "
	"a %^MAGENTA%^regal building%^BLUE%^ "
	"from which two %^RED%^red banners%^BLUE%^ hang. An open "
	"doorway lays open leading into the building. Off in the "
	"distance, to the northeast, a large %^WHITE%^%^BOLD%^bone tower "
	"%^RESET%^%^BLUE%^rises towering above you.\n%^RED%^A feeling of "
	"dread passes through you as you stare up at the tower.%^RESET%^"
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
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"west":"/d/dagger/drow/rooms/city35",
	"northeast":"/d/dagger/drow/rooms/city42",
	"south":"/d/dagger/drow/rooms/city37",
    "north":"/d/dagger/drow/rooms/elite4"
    ]));
}
