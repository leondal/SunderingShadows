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
	" To the north is a building which appears to be a shop of some "
	"kind or another."
	" \n%^RED%^A gallows pole is in the center of this "
	"intersection. From the gallows hangs a long "
	"hangmans's noose.%^RESET%^"
    );
    set_listen("default",
	"You hear the faint whispering of martyred souls in the wind."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"building":"A sign hangs above the doorway that leads into the "
	"building to the north.",
	"gallows pole":"The gallows pole is obviously used in the "
	"execution of enemies of the Drow.",
	"pole":"There are 13 notches engraved into the side of the pole.",
	"notches":"The notches are probably some sort of record keeping "
	"device.",
   "noose":"The noose looks quite strong and would snap its victims "
	"neck before snapping itself.",
	"sign":"The sign bears symbols marking it as a general store.",
	"doorway":"The open doorway appears to an entrance to the building "
	"to the north.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/store",
	"west":"/d/dagger/drow/rooms/city14",
	"south":"/d/dagger/drow/rooms/city2",
	"east":"/d/dagger/drow/rooms/city16"
    ]));
}
void reset() {
    ::reset();
    if(!present("maul")) {
	message("environment",
	"%^RED%^The executioner known as Maul strides into the room "
	"and examines his gallows.%^RESET%^"
   ,TO);
    new("/d/dagger/drow/mon/maul")->move(TO);
    }
}
