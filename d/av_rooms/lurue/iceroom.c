// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("iceroom");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("glacier");
    set_travel("slick floor");
    set_climate("arctic");

    set_short("%^BOLD%^%^CYAN%^A plain of ice in the sky%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You find yourself standing upon a slick slab of %^CYAN%^ice %^WHITE%^hovering in the middle of a %^BLUE%^raging storm%^WHITE%^.  Just above you, stormclouds roll and burn with glowing"
	" %^YELLOW%^lightning%^WHITE%^.  But this is hardly the most frightening, for spilling out of the turmoil is a horrific, large cone of raw destruction in the form of a whirling %^BLACK%^vortex%^WHITE%^"
	".%^RESET%^"
	);

    set_smell("default","
Ozone fills the air.");
    set_listen("default","The pounding sound of thunder deafen you.");

    
set_items(([ 
	({ "storm", "lightning" }) : "%^BOLD%^%^BLACK%^The thick clouds surround you with their black mass.  Lightning flickers deep within and thunder pounds your senses.  This is the center of the storm.  No mortal being could go closer and survive.  And really, you probably wont either.",
	"vortex" : "%^BOLD%^%^BLACK%^Extending down in a tornado of raw power, this thing is the titanic elemental core of the storm.  A storm titan that would destroy the world if not contained or destroyed.",
	"ice" : "%^BOLD%^%^CYAN%^A slab of ice hovers in the sky, its slick surface suspended between heaven and earth by the sheer power of divine magic.  If it shatters, anything upon it will fall...%^RESET%^",
	]));

    set_exits(([ 
		"vecna" : "/d/dagger/marsh/tower/rooms/gate",
		"down" : "/d/tharis/Tharis/market2",
	]));

}