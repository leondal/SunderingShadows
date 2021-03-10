#include "chaos.h"

inherit VAULT;

int do_exit();

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A Staircase, first floor");
    set_long(
	"Your on the ninth floor of the Chaos Tower. \n"
	"You can see four doors, one in each direction. "
	"There doesn't appear to be locks on the doors. "
	"In the center of the room, is a spiral staircase, "
	"that leads down. "
    );
    set_exits( ([
	"down"  : CHAOSDIR+"floor8",
	"east"  : CHAOSDIR+"east9",
	"west"  : CHAOSDIR+"west9",
	"south" : CHAOSDIR+"south9",
	"north" : CHAOSDIR+"north9"
        ]) );
    set_door("north door",CHAOSDIR+"north9","north",0);
    set_door("south door",CHAOSDIR+"south9","south",0);
    set_door("east door",CHAOSDIR+"east9","east",0);
    set_door("west door",CHAOSDIR+"west9","west",0);
    set_door_pre_exit_function("east door","do_exit1"); 
    set_door_pre_exit_function("west door","do_exit2"); 
    set_door_pre_exit_function("north door","do_exit3"); 
    set_door_pre_exit_function("south door","do_exit4"); 
    set_smell("default","There is a musky odor about the place.");
    set_listen("default","The sound of dead silence, numbs your ears.");
}
void reset(){
    object ob;

	if(!present("guard1")){
		ob = new(MONDIR+"guard");
		ob->set_id(({"guard","guard1"}));
		ob->set_short("a mean looking guard");
		ob->set_long("A very mean looking guard. He guards the doors.\n");
		ob->move(TO);
	}
	if(!present("guard2")){
		ob = new(MONDIR+"guard");
		ob->set_id(({"guard","guard2"}));
		ob->set_short("a mean looking guard");
		ob->set_long("A very mean looking guard. He guards the doors.\n");
		ob->move(TO);
	}
	if(!present("guard3")){
		ob = new(MONDIR+"guard");
		ob->set_id(({"guard","guard3"}));
		ob->set_short("a mean looking guard");
		ob->set_long("A very mean looking guard. He guards the doors.\n");
		ob->move(TO);
	}
	if(!present("guard4")){
		ob = new(MONDIR+"guard");
		ob->set_id(({"guard","guard4"}));
		ob->set_short("a mean looking guard");
		ob->set_long("A very mean looking guard. He guards the doors.\n");
		ob->move(TO);
	}
}
int do_exit1(){

	if(present("guard1")){
		write("One of the guards blocks your way.");
		return 0;
	}
	else return 1;
}
int do_exit2(){
	if(present("guard2")){
		write("One of the guards blocks your way.");
		return 0;
	}
	else return 1;
}
int do_exit3(){
	if(present("guard3")){
		write("One of the guards blocks your way.");
		return 0;
	}
	else return 1;
}
int do_exit4(){
	if(present("guard4")){
		write("One of the guards blocks your way.");
		return 0;
	}
	else return 1;
}

