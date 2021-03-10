// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("trial2");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("paved road");
    set_climate("mountain");

    set_short("%^RESET%^%^CYAN%^Ice altar%^RESET%^");

    set_long("%^RESET%^%^CYAN%^You are within a large cavern bored into a mountain of %^BOLD%^glacial ice%^RESET%^%^CYAN%^.  Natural light cannot penetrate the thick walls here, forcing you to rely on other means t"
	"o catch your bearings.  Beneath your feet crunches a layer of ice crystals.  The walls around you %^BOLD%^shimmer %^RESET%^%^CYAN%^like %^BOLD%^%^WHITE%^glass%^RESET%^%^CYAN%^.  Two massive ice pillar"
	"s fill the tall chamber, gradually coming together near their bases into a kind of frozen altar.  Planted in the center of the ice altar is unremarkable fruit %^ORANGE%^tree%^CYAN%^, encased in a thic"
	"k layer of transparent ice.  The walls around you give the impression of once being sculpted, but years of cracks and partial melting have rendered them unrecognizable.%^RESET%^"
	);

    set_smell("default","
%^BLUE%^It smells crisp and clean.%^RESET%^");
    set_listen("default","%^MAGENTA%^You hear your footsteps echo.%^RESET%^");

    
set_items(([ 
	({ "tree", "trees" }) : "%^ORANGE%^The stump of a small tree is locked in ice.  Remarkably, it looked like it once grew from the depths of the glacier.  Its limbs, once coated and thriving in ice, have been hacked away by some kind of bladed object.",
	]));

    set_exits(([ 
		"south" : "/d/av_rooms/tiamat/trial1",
	]));

}