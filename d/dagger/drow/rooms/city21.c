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
	" The lake continues along to the south of you and to the "
	"northwest lies a large fourteen foot high chain "
	"link fence.%^RESET%^"
    );
    set_listen("default",
	"From within the fence you hear the sound of elven voices "
	"complaining and sobbing."
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
	"lake":"%^BLUE%^The lake is dark and black and swimming here would "
	"be the last thing you ever did.%^RESET%^",
	"fence":"%^RED%^Through the fence you see two small shacks made of "
	"wheat straw. There are a few %^CYAN%^elven slaves%^RED%^ "
	"wandering about in %^GREEN%^chains%^RED%^. Farther up the "
	"northern road you can see the gates leading inside the fenced "
	"in area.%^RESET%^",
	"shacks":"%^CYAN%^The shacks are made of wheat and do not look "
	"like dwellings fitting of anyone, let alone a member of the "
	"fair elf race.%^RESET%^",
	({"elf","elves","slave","slaves"}):"%^RED%^The elven slaves "
	"are in chains and look underfed. They are covered in dirt, "
	"unkempt and wearing rags. It is a miserable sight to behold "
	"indeed.%^RESET%^",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
        "east":"/d/dagger/drow/rooms/city4",
        "west":"/d/dagger/drow/rooms/city22",
        "north":"/d/dagger/drow/rooms/city23"
    ]));
}
