// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("selune_under1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("stairway");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^Under the Temple of Selune%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You find yourself under the Temple of Selune.  The corridor here starts at the bottom of a flight of stairs made out of the same natural rock as the corridor itself.  Within the stone"
	"s you can see the centuries of striations and changes to the earth in a polished natural stone.  The room is lit softly with a the glow of moonlight, captured within orbs that hover along the arched c"
	"eiling.  They illuminate frescos of celestial objects.  The moon, the stars and the ribbons of distant galaxies all peeked at through the soft edges of clouds.%^RESET%^"
	);

    set_smell("default","You detect the faintest hint of night-blooming jasmine.");
    set_listen("default","The corridor is silent but for the sounds you make.");

    
set_items(([ 
	({ "celestials", "celestial objects", "ceiling", "stars", "moons", "galaxies", "clouds" }) : "%^BOLD%^%^WHITE%^The ceiling is covered in a fresco painting that depicts the night sky with a clarity that no human eye could summon.  The moon, stars, even distant galaxies all can be seen through a surrounding break in the clouds.  The beauty of the art is breathtaking.%^RESET%^",
	({ "striations", "wall", "walls" }) : "%^BOLD%^%^WHITE%^The striations are the natural production of countless centuries of earth formation, smoothed and cut through to reveal their beauty.%^RESET%^",
	({ "stairs", "stair" }) : "%^BOLD%^%^WHITE%^The stairs are carved of the same stone as the rest the corridor.  Oddly they lead to the ceiling and abruptly end.%^RESET%^",
	]));

    set_exits(([ 
		"stairs" : "/d/av_rooms/lurue/selune_meadow",
		"east" : "/d/av_rooms/lurue/selune_under2",
	]));

}