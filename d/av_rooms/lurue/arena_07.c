// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arena_07");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^YELLOW%^The Seneca Arena Gladiator's Lounge%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^Unlike the other two rooms of the lounge, this one is tiled.  The once white tiles are now dingy with dirt and grime, but you can imagine they once were spotless. On the eastern wall "
	"a %^RESET%^%^ORANGE%^bronze plaque %^BOLD%^%^WHITE%^has been set behind glass, the only thing that is untilled in the entire room.  On the western wall a series of %^BLACK%^knobs %^WHITE%^can be found"
	" that might have once twisted back and forth, though time has fixed them into place and they no long turn.  A %^RESET%^%^CYAN%^drain %^BOLD%^%^WHITE%^in the middle of the floor gives a clue to their p"
	"urpose as it provides a place for water to drain away.  And a strange set of short %^BLACK%^metal tubes %^WHITE%^extend out of the top of the ceiling, a place where water likely flowed down, washing a"
	"way the grime, grit and blood from the warrior's bodies.%^RESET%^ "
	);

    set_smell("default","
There is a sterile smell to this room.");
    set_listen("default","You can hear an occasional pinging sound coming from the eastern wall.");

    set_search("plaque","%^RESET%^%^ORANGE%^You search around the plaque and discover a small lever that might allow the plaque to be opened.%^RESET%^");
    
set_items(([ 
	({ "knobs", "knob", "metal", "tubes", "metal tubes" }) : "%^BOLD%^%^BLACK%^These knobs and tubes appear to once have been some sort of water supply system that allowed the warriors from the Arena to clean up between matches.  You can only imagine what sort of magic would allow such a device to work properly.%^RESET%^",
	({ "plaque", "bronze plaque" }) : "%^RESET%^%^ORANGE%^You gaze at the plaque and see that it is a delicate carving of an %^BOLD%^%^WHITE%^angel %^RESET%^%^ORANGE%^with her glorious %^BOLD%^%^WHITE%^white wings %^RESET%^%^ORANGE%^uplifted and her bowed head.  Her hands are to either side of her body, which is sheathed in a %^BOLD%^%^CYAN%^gossamer gown %^RESET%^%^ORANGE%^that tapers down in a sleeve to cover her whole body.  Soft locks of %^YELLOW%^golden hair %^RESET%^%^ORANGE%^curl to either side of her head framing the heart shaped face.  Above her, between her wide spread wings, a carving of an island, much like the one you visit now can be seen.  The mountains and shore line, a %^BOLD%^%^CYAN%^metropolis %^RESET%^%^ORANGE%^sitting on the shore, with a %^BOLD%^%^BLACK%^black tower %^RESET%^%^ORANGE%^seen in the distance.  The artwork is stunning and the whole image is life like enough to send a shiver down your spine.%^RESET%^",
	"tiles" : "%^BOLD%^%^WHITE%^The tiles are dirty and dingy now, but you imagine that these glossy squares of fired clay were once bright white and shed grime as easily as they did water.%^RESET%^",
	"drain" : "%^RESET%^%^CYAN%^The dark hole in the center of the tiled floor has a wide metal grate over it, providing a place for the water and grime to drain away.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/arena_06",
		"north" : "/d/av_rooms/lurue/arena_08",
		"east" : "/d/av_rooms/lurue/arena_09",
	]));



    set_invis_exits(({ "east" }));

}