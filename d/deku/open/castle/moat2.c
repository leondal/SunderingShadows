//	moat2.c
//	Written by Pator@ShadowGate
//	Tue Apr 11 05:31:25 1995

#include <castle.h>

inherit "std/pier";

void create() {
    ::create();
   set_terrain(SHALLOW_WATER);
   set_travel(FOOT_PATH);
    set_light(2);
    set_short("In the moat");
    set_long(
@FISHING
You are standing in the moat. The water looks still fresh here. You see some fish and you almost can't resist to take a rod and start fishing.
FISHING
    );
    set_max_fishing(5);
    set_chance(7);
    set_max_catch(15);
set_listen("default","You hear water splashing and birds singing");
    set_exits(([
"west" : CASTLE+"moat1",
"east" : CASTLE+"moat3"
    ] ));
    set_items(([
       "fish" : "You see the fish in the clear water. It looks they are playing follow the leader."
    ] ));
}
// There are some fish here ... ready to be butchered by low-level players

init()  {
	::init();
        add_fish("salmon",15);
	add_action("search_it","search");
	}

int search_it(string str) {
	if (present("fishing_rod")) return 0;
	if (str == "rod" || str == "fishing rod")
	{ new("/d/common/obj/misc/fishing_rod")->move(this_object()); 
	  tell_player(this_player(),"You find a stick to fish with !!\n");
	  return 1;
	}
	else
	{ return 0;
	}
	}
