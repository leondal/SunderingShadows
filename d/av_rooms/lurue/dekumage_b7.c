// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b7");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("dirt road");
    set_climate("tropical");

    set_short("an underground passage");

    set_long("%^ORANGE%^You find yourself standing in a narrow passage deep under the earth.  Wooden planks hold the dirt walls back, but soil shifts and showers you as you pass by.  Droplets of %^BLUE%^water %^ORA"
	"NGE%^cover most things and the pungent smell of wet soil pervades your surroundings.  Ahead, a dim %^WHITE%^light %^ORANGE%^catches your attention. And on the west wall a rope ladder ascends to the st"
	"ore room above.%^RESET%^"
	);

    set_smell("default","
You can smell the wet earth of the swamp.");
    set_listen("default","Things seem very quiet here.");


    set_exits(([ 
		"south" : "/d/av_rooms/lurue/dekumage_b9",
		"up" : "/d/av_rooms/lurue/dekumage_b4",
	]));

}