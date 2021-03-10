//ankheghouse.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
	::create();

	set_name("ankheghouse");
	set_short("Ankheghouse");
	set_property("indoors",1);
	set_terrain(BUILT_CAVE);
    set_travel(FRESH_BLAZE);
	set_light(0);
	set_long(
@OLI
	%^CYAN%^
	This is a small tunnel that the ankhegs have burrowed under the
common paths of the jungle. They use it to capture prey. You smell
the dirt around you. The darkness is oppressive.
OLI
	);
   set_smell("default","You smell the decay and growth that come with the earth");
	set_listen("default","The movement of the animals living here chatter in your ears");
	set_pre_exit_functions(({"up"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
	if(present("ankheg")){
		write("As you try to climb from the hole the ankhegs easily drag you down.");
	 	return 0;
	}
	return 1;
}

void reset(){
	object ob;
	::reset();

	if(!present("ankheg")){
		ob = new(MON+"ankheg");
		ob->move(TO);
		ob->set_aggressive(25);
	}
	if(!present("ankheg 2")){
		ob = new(MON+"ankheg");
		ob->move(TO);
		ob->set_aggressive(25);
	}
	if(!present("ankheg 3")){
		ob = new(MON+"ankheg");
		ob->move(TO);
		ob->set_aggressive(25);
	}
	if(!present("ankheg 4")){
		ob = new(MON+"ankheg");
		ob->move(TO);
		ob->set_aggressive(25);
	}
	if(!random(3)){
		if(!present("ankheg 5")){
			ob = new(MON+"ankheg");
			ob->move(TO);
			ob->set_aggressive(25);
		}
	}
	if(!random(4)){
		if(!present("ankheg 6")){
			ob = new(MON+"ankheg");
			ob->move(TO);
			ob->set_aggressive(25);
		}
	}
}

clean_up()
{
    if (member_array("up", query_exits()) != -1) {
        (query_exit("up"))->remove_exit("down");
    }

    return 1;
}
