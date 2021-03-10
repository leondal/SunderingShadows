// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("hut");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^CYAN%^A small home%^RESET%^");

    set_long("%^RESET%^You are standing in a quaint, though somewhat comfortable home.  It is little more than a hut, composed of a single room made of rough cobblestone.  %^ORANGE%^Wooden dividers%^RESET%^ and %^M"
	"AGENTA%^plush furniture%^RESET%^ separate the various 'rooms,' but everywhere there is %^ORANGE%^clutter%^RESET%^.  You immediately see a small sitting area with a stout varnished table and three larg"
	"e %^MAGENTA%^comfortable chairs%^RESET%^.  A few portraits and antiques hang from the walls.  You hear the gentle crackling of a fire nearby, as well as teapot coming to a boil.  A small ladder leads "
	"up to a loft, where you imagine a single bed is found.%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^You smell dust and cooking aromas.");
    set_listen("default","%^GREEN%^You hear the low whistle of a teapot.");

}