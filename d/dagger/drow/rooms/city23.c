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
	"through the existing structures around you. The wind blows "
	"back your hair as you wander through the city pathways."
	" The road continues north and south here and to the west is "
	"a twenty foot high chain link fence. The fence is used to "
	"form a larger slave compound. Up the road to the north "
	"you can see the gates of the compound.%^RESET%^"
    );
    set_listen("default",
        "The wind howls a strangled cry which causes you to feel "
	"nervous about being here."
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
	"fence":"%^BLUE%^You can see two shacks made of wheat. Wandering "
	"around the compound are several %^CYAN%^elven "
	"slaves%^BLUE%^.%^RESET%^",
        "shacks":"The shacks are used to house the slaves and are made of "
	"wheat. You question the humanity of forcing anyone to dwell "
	"here...but then again...Drow are known for their inhumanitys.",
	({"slaves","slave","elf","elves"}):"The slaves wander with all hope "
	"vanquished from their eyes. Dressed in rags and dirty from head "
	"to foot...they are all but dead.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"south":"/d/dagger/drow/rooms/city21",
	"north":"/d/dagger/drow/rooms/city24"
    ]));
}
