// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("t_pens");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^YELLOW%^Holding Pens%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This is an area for holding prisoners, or slaves. %^WHITE%^Chains%^RESET%^%^ORANGE%^ line the pallisade %^YELLOW%^walls%^RESET%^%^ORANGE%^ to hold any prisoners too unruly to follow"
	" directions. There is limited shelter, with just %^CYAN%^tents%^ORANGE%^ to keep off the rain. The ground is damp from recent rain. To the east lies the center of the camp.%^RESET%^"
	);

    set_smell("default","
It smells of filth as the latrines are just over the walls from here.");
    set_listen("default","You can hear laughter and the tramp of feet to the east. ");

    set_search("chains","You might be able to <climbwall> over the walls using those chains to help pull yourself up. ");
    set_search("wall","You might be able to <climbwall> over the walls using those chains to help pull yourself up. ");
    set_search("walls","You might be able to <climbwall> over the walls using those chains to help pull yourself up. ");
    
set_items(([ 
	"chains" : "They look rusted but quite servicable restraints. It would be truly heartbreaking to be confined here.",
	"tents" : "The tents are made out of some kind of hide, and have some holes. Not the best stuff.",
	"walls" : "The walls are made out of logs and held together by rope. They are only about 8 feet tall.",
	]));

    set_exits(([ 
		"climbwall" : "/d/av_rooms/myrkul/t_latrine",
		"east" : "/d/av_rooms/myrkul/t_camp",
	]));



    set_invis_exits(({ "climbwall" }));

}