// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_u3");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^Balcony of an old manor house%^RESET%^");

    set_long("%^RESET%^%^CYAN%^A wide balcony wraps around the upper half of the manor and supplies an area for these strange %^BOLD%^%^BLACK%^metal contraptions %^RESET%^%^CYAN%^that litter it.  A narrow %^WHITE%^"
	"railing %^CYAN%^provides a barrier between the balcony and the roof, while %^BOLD%^%^BLACK%^slate tiles%^RESET%^%^CYAN%^ make for a smooth surface to walk along.  Strangely, %^ORANGE%^copper wire %^CY"
	"AN%^feeds between many of these slates, connecting the various contraptions to one another.%^RESET%^"
	);

    set_smell("default","
The scent of the swamp is heavy in the air.");
    set_listen("default","The drone of insects fills your senses.");

    
set_items(([ 
	({ "contraptions", "machines", "contraption" }) : "%^BOLD%^%^BLACK%^Made from several types of metal, including a large supply of copper, these contraptions appear to be almost haphazard in design, having many fingers and extensions reaching toward the sky.  However, as you study them, you realize that each one has thin lines of copper wire running back and forth, along with dials, knobs and gauges to monitor and record the atmospheric changes.",
	({ "rail", "railings" }) : "%^BOLD%^%^WHITE%^These white rails stand about three feet high and run along the edge of the balcony, providing some protection against accidental falls, though not much.%^RESET%^",
	({ "wire", "copper wire", "slate", "tiles", "copper" }) : "%^RESET%^%^ORANGE%^You look down at the slate tiles that cover the balcony's floor and notice that there are copper wires running back and forth between the contraptions.  Linking them together.  A pair run through the doorway and into the room you just left, making you think that perhaps they serve a purpose.  Strangely, you notice that while all the wires are laid out in geometric patterns, there is one wire that is out of place.  Almost as if it had been added as an afterthought.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/lurue/dekumage_u2",
	]));

}