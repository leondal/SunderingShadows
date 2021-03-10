// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_t15");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("decayed floor");
    set_climate("mountain");

    set_short("%^BOLD%^%^BLACK%^Underground Warren");

    set_long("%^RESET%^%^ORANGE%^Dug into the earth and stone, this warren is more tunnel then finished structure.  The walls are uneven and show signs of %^RED%^claws %^ORANGE%^gouging into their surface as well a"
	"s scrapes and claw marks along the %^BOLD%^%^BLACK%^dark stone%^RESET%^%^ORANGE%^.  The floor and ceilings likewise show a lack of engineering, yet there is a clear determination to the tunneling as i"
	"t curves deeper into the earth and stone.  A few bits of %^GREEN%^lichen %^ORANGE%^add light to the cave, though their phosphorescent lighting is poor at best.%^RESET%^"
	);

    set_smell("default","
The stink of unwashed bodies and fur linger in the air.");
    set_listen("default","You can hear something hissing near by.");

    
set_items(([ 
	({ "claw marks", "marks", "scrapes", "gouges" }) : "%^BOLD%^%^BLACK%^The uneven crafting of the walls here shows the marks where claws and a few tools have dug away at the stone and earth to burrow deeper into the ground.  More then a few glow faintly with bits of phosphorescent moss.%^RESET%^	",
	({ "lichen", "phosphorescent", "phosphorescents", "moss" }) : "%^GREEN%^In a few of the cracks and gouges in the walls, you can make out small growths of a %^BOLD%^fa%^CYAN%^i%^GREEN%^nt%^WHITE%^l%^GREEN%^y il%^CYAN%^l%^GREEN%^u%^WHITE%^m%^GREEN%^ina%^CYAN%^t%^GREEN%^ed %^RESET%^%^GREEN%^moss that glows with a sickly phosphorescence.  The faint glow is difficult to see by, but keeps the tunnels from being completely pitch black.%^RESET%^",
	({ "tunnel", "earth", "stone", "ceilings", "walls", "floor" }) : "%^RESET%^%^ORANGE%^The tunnel seems to curve, dip and follow the path of least resistance, cutting through the stone and earth wherever the diggers found it easiest to excavate.  This causes the tunnel to narrow and widen at odd points and makes for a rather claustrophobic feeling as you explore through the confining passageway.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/dekumage_t14",
		"south" : "/d/av_rooms/lurue/dekumage_t1",
	]));

}