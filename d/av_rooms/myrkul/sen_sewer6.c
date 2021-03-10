// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sen_sewer6");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A dead end in %^CYAN%^S%^RESET%^%^CYAN%^e%^BOLD%^neca S%^RESET%^%^CYAN%^e%^BOLD%^wers%^RESET%^");

    set_long("You arrive at a dead end. A %^ORANGE%^b%^RED%^r%^ORANGE%^i%^RED%^c%^ORANGE%^k%^BOLD%^%^BLACK%^ wall%^RESET%^ closes off this section of the sewer, leaving the canal dry. The ceiling has no drain openi"
	"ngs and there are no more magical orbs, which leaves this corner of the sewer very dark. "
	);

    set_smell("default","
The odor of the sewer is lessened here, and the air is very still.");
    set_listen("default","%^RESET%^The %^BOLD%^%^RED%^rats%^RESET%^ sound very active in this section of sewer.");

    set_search("wall","You notice that a few bricks are loose in the canal.");
    set_search("brick","You notice that a few bricks are loose in the canal.");
    set_search("grate","As you pull the bricks free around the grate to get a better look, you notice that there is a <trap door> where maintenance workers from long ago freed large objects from blocking the canal.");
    set_search("canal","There looks to be some kind of grate behind the bricks in the canal.");
    
set_items(([ 
	({ "brick", "bricks" }) : "The bricks here look to have once been very high quality, but they have decayed over time.",
	"wall" : "The brick wall is more recent than the surrounding construction. It apparently blocks off portions of the old sewer that was no longer needed when the new sewer was added.",
	"grate" : "There is a grate behind the old bricks. It must have been part of a trap to prevent large debris from getting stuck further down in the sewer.",
	"canal" : "The canal has also been bricked up, although you notice a trickle of water where some of the bricks must have given way.",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/myrkul/sen_sewer4",
		"trapdoor" : "/d/av_rooms/myrkul/sen_oldsewer1",
	]));



    set_invis_exits(({ "trapdoor" }));

    set_door("trap door","/d/av_rooms/myrkul/sen_oldsewer1","trapdoor","sewer key","lock");
    add_lock("trap door","sewer key","lock","This is a simple lock.");
    set_locked("trap door",1,"lock");
    lock_difficulty("trap door",-20,"lock");
    set_open("trap door",0);
    set_string("trap door","knock","pounds on the");
    set_string("trap door","open","The trapdoor creaks open");
    set_string("trap door","close","The trapdoor creaks closed");
    set_door_description("trap door","This is an old maintenance trap door. It looks very rusty. To squeeze through, you will have to go <trapdoor>.");
}