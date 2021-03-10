// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tunnel12");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("ledge");
    set_climate("temperate");

    set_short("%^MAGENTA%^A ruined ledge%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^You are standing in a roughly hewn tunnel.  It appears that it was chiseled by intelligent hands, but is free of dcor and unfinished.  The tunnel rises about six feet into the air and "
	"tapers into a vague arch-shape.  The floor beneath you is still rough, un-level and sometimes precarious to walk over.  A sense of deep antiquity fills you as you notice the only embellishments of the"
	" tunnel: A row of %^RESET%^%^ORANGE%^pictograms%^BOLD%^%^BLUE%^ lead down either side of the tunnel at about waist high for a human.  The tunnel seems to end abruptly, but as you look around you see i"
	"t continue several feet below, as though part of the tunnel sank ages ago.  You need only climb down to continue."
	);

    set_smell("default","
%^ORANGE%^It smells dry and old");
    set_listen("default","%^GREEN%^You hear little here");

    
set_items(([ 
	({ "pictogram", "pictograms" }) : "%^ORANGE%^The pictograms here were destroyed by collapse of rubble.",
	]));

    set_exits(([ 
		"down" : "/d/av_rooms/tiamat/tunnel9",
		"east" : "/d/av_rooms/tiamat/tunnel13",
	]));

}