#include <std.h>
#include "../valley.h"
inherit EDGE;

void create(){
	::create();
	set_exits( ([
	"north" : ROOMS+"e1610",
	"east" : ROOMS+"e1511",
	]) );
	set_invis_exits(({"north","east"}));
	set_pre_exit_functions(({"north"}),({"go_through_brush"}));
}

void go_through_brush(){
//adjusting the wander ports to function on survival skill rather
//than class ~Circe~ 4/8/13
	int i,j;
	int skill = TP->query_skill("survival");
	object ppl,*global_array;

	if(skill > 9) {
		tell_object(TP,"%^GREEN%^You skillfully navigate your way"+
		" through the woods.");
		tell_room(ETP,"%^GREEN%^"+TPQCN+" navigates"+
		" easily through the woods.",TP);
		TP->move_player("/d/antioch/valley/rooms/e1610","north");
		return;
	}else{
		tell_object(TP,"You wander lost through the woods.");
		tell_room(ETP,""+TPQCN+" wanders lost through"+
		" the woods.",TP);

		i = random(3);
		switch(i) {
			case 0:
				TP->move_player(ROOMS+"e1512");
				break;
			case 1:
				TP->move_player(ROOMS+"e1609");
				break;
			case 2:
				TP->move_player(ROOMS+"e1807");
				break;
		}

	}
}
