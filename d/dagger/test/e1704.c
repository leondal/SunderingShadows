#include <std.h>
#include "/d/antioch/valley/valley.h"
inherit EDGE2;

void create()
{
	::create();
	set_exits( ([
	"northwest" : ROOMS+"e1803",
	"southeast" : ROOMS+"e1605",
	]) );
	set_invis_exits(({"northwest","southeast"}));
	set_pre_exit_functions(({"southeast"}),({"goThroughDoors"}));
}

int goThroughDoors()
{
	int i;
	object *global_array;
	global_array = TP->query_followers();

	if(TP->is_class("ranger")) {
		tell_object(this_player(),
		"%^GREEN%^You skillfully navigate your way"+
		" through the woods."
		);
		tell_room(environment(this_player()),
		"%^GREEN%^"+TP->query_cap_name()+" navigates"+
		" easily through the woods.",({TP})
		);
		return 1;
	} 

	if(!global_array) global_array = ({});

	if(member_array(TP,global_array) != -1) {
		global_array -= ({TP});
		return 1;
	}

	else {
		tell_object(this_player(),
		"You wonder lost through the woods."
		);
		tell_room(environment(this_player()), 
		""+TP->query_cap_name()+" wonders lost through"+
		" the woods.",({TP})
		);

		i = random(3);
		switch(i) {
			case 0:
				TP->move_player(ROOMS+"e2005");
				break;
			case 1:
				TP->move_player(ROOMS+"e1510");
				break;
			case 2:
				TP->move_player(ROOMS+"e1908");
				break;
		}

	}
}

void reset()
{
	::reset();
	if(!present("creeper")) {
		if(!random(2)) {
			new(MONS+"creeper")->move(TO);
			return 1;
		}
	}
}
