// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("wagon_4");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("light forest");
    set_travel("fresh blaze");
    set_climate("temperate");

    set_short("%^RESET%^A narrow path%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This trail cuts through some brush, angling back away from the old wagon trail and making its way up into the rough terrain of the echo mountains.  The trail looks fresh and recentl"
	"y cut, some of the shrubs and lower tree branches still show where a sword was used to hack the path back.  Oddly the ground had deep grooves along its center, as though some heavy object was wheeled "
	"up along this path.%^RESET%^"
	);

    set_smell("default","
There is an odd pungent odor in the air.");
    set_listen("default","There are a few birds chirping nearby.");

    set_search("brush","%^GREEN%^You search the brush but notice only that it has been cut through by some type of sword or other sharp blade.%^RESET%^");
    
set_items(([ 
	({ "groove", "grooves" }) : "%^ORANGE%^A set of ruts dig into the ground.  Narrowly spaced, they follow along the path's center like some sort of small wagon or cart. The earth is dry and doesn't appear to have been very muddy recently, making you wonder at the heavy load that must have dug these tracks.%^RESET%^",
	({ "branch", "branches" }) : "%^GREEN%^The brush looks freshly cut, maybe a few weeks old at best.  A sword or large knife seems to have been used to hack at it, judging by the gouges in the wood and the way that much of the brush is simply broken instead of sheered. %^RESET%^",
	({ "brush", "trees", "grass" }) : "%^GREEN%^The brush looks freshly cut, maybe a few weeks old at best.  A sword or large knife seems to have been used to hack at it, judging by the gouges in the wood and the way that much of the brush is simply broken instead of sheered. %^RESET%^",
	({ "rut", "ruts", "trail", "path", "road" }) : "%^ORANGE%^A set of ruts dig into the ground.  Narrowly spaced, they follow along the path's center like some sort of small wagon or cart. The earth is dry and doesn't appear to have been very muddy recently, making you wonder at the heavy load that must have dug these tracks.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/wagon_3",
		"south" : "/d/av_rooms/lurue/wagon_5",
	]));

}