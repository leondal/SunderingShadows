// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dungeons");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^ORANGE%^Dungeons Portal");

    set_long("%^RESET%^%^ORANGE%^This is a long extension of the previous chamber.  The hub chamber is partially lit by a single antique gas street %^BOLD%^%^BLACK%^lamp%^RESET%^%^ORANGE%^, though its light fades i"
	"nto darkness overhead.  The area looks well trafficked, evidenced by misplaced %^MAGENTA%^arms%^ORANGE%^, %^YELLOW%^treasure%^RESET%^%^ORANGE%^ and skeletal %^RESET%^remains%^ORANGE%^ at the various e"
	"ntrances to the wider world.  An odd silence hangs palpably in the air, but is occasionally broken by sounds coming from the various branching corridors.  It sounds as though armies of creatures, ever"
	"y size and form, are waiting just beyond the shadows.  There is movement from every shadow nearby, as though excitement could break out at any moment.%^RESET%^"
	);

    set_smell("default","
%^GREEN%^Mmm, smells like adventure.");
    set_listen("default","%^ORANGE%^You've got a bad feeling about this.");

    
set_items(([ 
	({ "lamp", "light", "gaslight" }) : "%^BOLD%^%^BLACK%^The tall street light looks out of place and time.  It looks old and antique, despite being brought here by a possible future.  It stands on seven feet of black iron and sheds its oily light through cracked panes.  A wispy cobweb dances off of the lamp on air expelled from the tunnels.%^RESET%^",
	({ "arms", "treasure", "remains" }) : "%^MAGENTA%^Bits of past or possible adventures have been discarded here.  Magic weapons here lack their luster.  Enchanted armor is broken or rusting.  Treasures that were not meant to be are simply collecting dust.  The long dead remains of curious monsters, annoying heroes and experiments gone wrong are now only scattered bone.%^RESET%^",
	]));

    set_exits(([ 
		"tower" : "/d/av_rooms/tiamat/tower1",
		"tunnel" : "/d/av_rooms/tiamat/tunnel1",
		"hags" : "/d/av_rooms/tiamat/coven",
		"tomb" : "/d/av_rooms/tiamat/tomb1",
		"ship" : "/d/av_rooms/tiamat/ship1",
		"castle" : "/d/av_rooms/tiamat/castle1",
		"ginger" : "/d/av_rooms/tiamat/ginger1",
		"cryscave" : "/d/av_rooms/tiamat/trial4",
		"stones" : "/d/av_rooms/tiamat/stones",
		"back" : "/d/av_rooms/tiamat/complex",
		"keep" : "/d/av_rooms/tiamat/tiamatbasement1",
		"hut" : "/d/av_rooms/tiamat/hut",
	]));

}