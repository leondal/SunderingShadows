// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("t_latrine");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("game track");
    set_climate("temperate");

    set_short("Camp Latrines");

    set_long("There is a row of outhouses here next to the walls of the pallisade. Its been a busy place and is not a very nice place to visit. The outhouses have been built over some deeply dug trenches. To the so"
	"utheast is the entrance of the camp."
	);

    set_smell("default","
It really stinks here.");
    set_listen("default","You can hear some prisoners on the other side of the pallisade walls.");

    set_search("outhouses","You don't want to search IN there... but you might be able to <climbwall> to go up the sides of the outhouse and over the walls.");
    set_search("outhouse","You don't want to search IN there... but you might be able to <climbwall> to go up the sides of the outhouse and over the walls.");
    
set_items(([ 
	({ "walls", "wall" }) : "The walls are pretty close to the outhouses. They are made out of wood logs and rope.",
	"outhouse" : " The outhouses have a moon caved in the door to let some light in. Of course this also lets in the flies, which have taken up residence. Disgusting!",
	"outhosue" : "The outhouses have a moon caved in the door to let some light in. Of course this also lets in the flies, which have taken up residence. Disgusting!",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/myrkul/t_entrance",
		"climbwall" : "/d/av_rooms/myrkul/t_pens",
	]));



    set_invis_exits(({ "climbwall" }));

}