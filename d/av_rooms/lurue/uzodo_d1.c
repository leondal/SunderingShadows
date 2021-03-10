// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("uzodo_d1");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("beach");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Shore of an Island%^RESET%^");

    set_long("%^RESET%^%^CYAN%^A small island drifts from the %^WHITE%^mists %^CYAN%^and reveals itself as you near the inlet.  Thickets of %^GREEN%^trees%^CYAN%^ dot the shoreline making it impossible to see furth"
	"er into the thickly wooded land.  Only here, where a thin %^BLUE%^stream %^CYAN%^makes its way from a break in the foliage out toward to the greater ocean, is there a spot where one could land a boat."
	"  The %^ORANGE%^sandy bank%^CYAN%^, little more then a thin strip of dry land running along the water's edge, one which likely vanishes at high-tide.  Further up the shore, the trees break open a bit "
	"to reveal a %^BOLD%^%^BLACK%^game path%^RESET%^%^CYAN%^.%^RESET%^"
	);

    set_smell("default","
You can smell the sweet scent of fresh water and a faint hint of ocean air.");
    set_listen("default","The waves crash in the distance.");

    set_search("sand","%^RESET%^%^ORANGE%^You search around in the sand, but find nothing interesting.%^RESET%^");
    
set_items(([ 
	({ "path", "game path" }) : "%^BOLD%^%^BLACK%^It looks as though some sort of animal comes down near this bank to drink from the river.  You might be able to follow the path if you tried.%^RESET%^",
	({ "shore", "bank", "sand" }) : "%^RESET%^%^ORANGE%^The sand is gravely and coarse, formed into a narrow strip that follows the edge of a small stream.  Only a few dozen feet wide at it's largest point, the narrow strip quickly gives way to the heavy forest.%^RESET%^",
	({ "ocean", "water", "river", "stream" }) : "%^BOLD%^%^BLUE%^The stream flows down out of the thick foliage and cuts a small inlet into the ground where a sandy bank makes a spot to draw a boat up on.  Further out, the stream widens a little and then flows into the ocean beyond.%^RESET%^",
	({ "trees", "tree", "foliage", "plants" }) : "%^BOLD%^%^GREEN%^The trees grow thickly together here creating a natural blind and preventing you from seeing further into the island.  Cypress, cedar, fir, hemlock, pine, spruce, and juniper cluster and spread their thickly nettled branches outward.%^RESET%^",
	]));

    set_exits(([ 
		"path" : "/d/av_rooms/lurue/uzodo_v2",
		"beach" : "/d/av_rooms/lurue/uzodo_d2",
	]));



    set_invis_exits(({ "path" }));

}