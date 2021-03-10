// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_oldsewer5");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^ORANGE%^Old S%^GREEN%^e%^ORANGE%^wer Beneath %^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^neca%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This is an ancient aqueduct system left over from the old city. The air is tight here, and the walls feel very close in. Water no longer flows here as the new sewers have blocked off "
	"the old construction. Bricks block the canal in either direction. The dust is thick with age. %^BOLD%^%^WHITE%^The skeletons of several humanoids lie in a pile in the center of the room.%^RESET%^"
	);

    set_smell("default","
You air is not as stale here. You smell filth wafting down from above.");
    set_listen("default","The familiar sound of rats scratching echos from somewhere in the darkness. You hear muffled screams echoing above you.");

    set_search("skeletons","The skeletons lie in a pile as if having been dropped from a height. The fall likely did not kill them as the bones show much trauma. Most likely the pitiful creatures were already dead. The bodies look as if they dropped from the center of the ceiling.");
    set_search("floor","You see tracks leading to the east wall.");
    set_search("skeleton","The skeletons lie in a pile as if having been dropped from a height. The fall likely did not kill them as the bones show much trauma. Most likely the pitiful creatures were already dead. The bodies look as if they dropped from the center of the ceiling.");
    set_search("ceiling","The ceiling is made of old bricks. There appears to be some sort of metal grate that blocks an ancient drain in the middle of the ceiling. ");
    set_search("bricks","The bricks are shrouded in darkness and the sturdy looking construction might be deceiving.");
    set_search("east wall","There is a gap in the bricks here, and you think you can go <east> by squeezing through the gap.");
    set_search("walls","The bricks here are shrouded in darkness, and what looks like a firm wall might be deceiving.");
    
set_items(([ 
	({ "skeleton", "skeletons" }) : "The skeletons are of humanoids, and they don't look like they died at peace.",
	"floor" : "The floors are covered in dust.",
	"ceiling" : "The ceiling is made of old bricks.",
	"bricks" : "The bricks are new construction and look quite sturdy.",
	"walls" : "The bricks are new construction compared to the walls and they block the channel leaving this part of the sewer entombed.",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/myrkul/sen_oldsewer4",
		"drain" : "/d/attaya/newseneca/rooms/jail_cell",
	]));



    set_invis_exits(({ "drain", "east" }));

    set_door("grate","/d/attaya/newseneca/rooms/jail_cell","drain","sewer key","lock");
    add_lock("grate","sewer key","lock","This is a simple lock.");
    set_locked("grate",1,"lock");
    lock_difficulty("grate",-20,"lock");
    set_open("grate",0);
    set_string("grate","knock","pounds on the");
    set_string("grate","open","The grate screeches open.");
    set_string("grate","close","The grate screeches closed.");
    set_door_description("grate","This grate blocks a <drain> in the ceiling. Perhaps if this grate were opened you could squeeze through the <drain> and leave this miserable place.");
}