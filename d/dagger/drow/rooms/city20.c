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
	"%^BLUE%^The city street is made of cobblestones winding through the "
	"existing structures around you. The wind blows back your hair as "
	"you wander through the city pathways."
	" Before you to the north stands a huge black obsidian stone "
	"tower. There are many slits in the tower face for archers to "
	"use. A large %^RED%^red banner%^BLUE%^ hangs down the side "
	"of the tower.%^RESET%^"
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
        "tower":"The tower is black as the shadows and from within the "
	"arrow slits you can see movement.",
	"banner":"%^RED%^The large red banner hangs down the face of the "
	"tower and bears the spider symbol of Lloth.",
	"slits":"These are obviously arrow slits for archers to fire bows "
	"from within the tower. However, they seem to be more for show "
	"than purpose.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"north":"/d/dagger/drow/rooms/twr3",
	"west":"/d/dagger/drow/rooms/city1",
	"east":"/d/dagger/drow/rooms/city9"
    ]));
}
