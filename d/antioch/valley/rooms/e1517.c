#include <std.h>
#include "../valley.h"
inherit EDGE;

int go_west();
int go_north();

void create()
{
	::create();
	set_exits( ([
	"north" : ROOMS+"v6",
	"east" : ROOMS+"e1518",
	"west" : ROOMS+"e1516",
	]) );
	set_invis_exits(({"north","east","west"}));
	set_pre_exit_functions(
	({"north", "west"}),({"GoThroughDoor", "GoThroughDoor"}) );
}

int GoThroughDoor()
{
	if(query_verb() == "west") {
		return go_west();
	}
	if(query_verb() == "north") {
		return go_north();
	}
	else {
		write("You step on a branch that crackles loudly as you try"+
		" to sneak around.");
		say(""+TP->query_cap_name()+" steps on a branch as "+TP->query_subjective()+""+
		" begins to move.");
		return 0;
	}
}

int go_north()
{
	int i;
	object *global_array;
	global_array = TP->query_followers();

	if(TP->is_class("ranger") || TP->is_class("druid")) {
//adding druids since it seems logical ~Circe~ 4/7/13
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

		i = random(2);
		switch(i) {
			case 0:
				TP->move_player(ROOMS+"e1824");
				break;
			case 1:
				TP->move_player(ROOMS+"e1610");
				break;
		}

	}
}

int go_west()
{
	int i;
	object *global_array;
	global_array = TP->query_followers();

	if(TP->is_class("ranger") || TP->is_class("druid")) {
//adding druids since it seems logical ~Circe~ 4/7/13
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

		i = random(2);
		switch(i) {
			case 0:
				TP->move_player(ROOMS+"e1523");
				break;
			case 1:
				TP->move_player(ROOMS+"e1520");
				break;
		}

	}
}

