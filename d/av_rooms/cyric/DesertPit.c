// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("DesertPit");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("desert rocks");
    set_travel("decayed floor");
    set_climate("desert");

    set_short("Desert Pit");

    set_long("This is a deep pit in the middle of the desert.  Whether it's caused naturally or if it was dug as some kind of trap for a large creature is difficult to tell.  The walls are packed sand and rocks, an"
	"d the floor is hard packed clay.  You could probably clamber up fairly easily and escape the pit."
	);

    set_smell("default","
The air here is dry, and the dust tickles your nose.");
    set_listen("default","You hear the sounds of the wind whistling across the top of the pit.");

}