// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("workroom");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^Mystra's Crystal Tower%^RESET%^");

    set_long("%^BOLD%^%^MAGENTA%^Cluttered and full of mess, this room appears to have no order or reason, other than for an overly ambitious imm to try out new things and test her creations in the comfy confines o"
	"f her own space.  Burnt cookies and bullet-riddled bunneez lie scattered across the west wall.  :P%^RESET%^"
	);

    set_smell("default","
Burnt cookies and bunnies smell fierce.");
    set_listen("default","Holes in the walls remind you of chaingun bullets.");


    set_exits(([ 
		"north" : "/d/av_rooms/mystra/southgate",
	]));

}