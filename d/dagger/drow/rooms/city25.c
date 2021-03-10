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
	"To the west is a slave compound made up of a large chain link "
	"fence to ensure the slaves cannot escape. "
	"You can see two shacks made of wheat within the compound and "
	"several %^CYAN%^elven slaves%^BLUE%^ huddled about."
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
	"compound":"The compound is a fence like structure used to "
	"prevent the %^CYAN%^elven slaves%^RESET%^ from escaping.",
	"fence":"The large chain link fence stands twenty feet high and "
	"is covered with barb wire along the top.",
	({"slave","slaves","elf","elves"}):"You see several dirty elven "
	"slaves dressed in rags huddled about within the compound in misery.",
	"shacks":"The wheat shacks are barely housing at all. You feel "
	"sorrow for those forced to dwell within them.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/city26",
	"south":"/d/dagger/drow/rooms/city24"
    ]));
}
