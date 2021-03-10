//sewer1.c

#include <std.h>

inherit ROOM;

int gate;

void create() {
	::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(SLICK_FLOOR);
    set_property("no sticks", 1);
	set_property("light",1);
	set_property("indoors",1);
	set("short","The sewers under Tharis.");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The sewers under Tharis%^RESET%^
This is a very old entrance to the sewers of Tharis. It is obvious that 
few people use this entrance. Before you stands an old gate guarding against
entrance or exit. This is how the elven underground enters the city undetected.
The new government does not know this place exists. The entrance to the sewers
is to the south and the exit to the surface is to the north. 
OLI
	);
	set_exits(([
		"north":"/d/tharis/road/road14",
		"south":"/d/tharis/Tharis/sewer2"
		]));
	set_pre_exit_functions(({"south"}),({"GoThroughDoor"}));
	set_smell("default","The stench of the sewers seeps through from the portions below you.");
	set_listen("default","The occasional squeak of a rat and a bang and a clatter.");
    set_items(([
    	"gate":"The large iron gate is rusted beyond use but still it stands in your way."
    ]));
}

void init(){
	::init();
	add_action("filter_say","say");
	add_action("stop_open","open");
}

int filter_say(string str){
	if(!str) return 0;
	if(gate == 1) return 0;
	if(strsrch(str,"friend") == -1) return 0;
	
	call_out("fix_gate",1);
	return 0;
}

void fix_gate(){
	tell_room(TO,"%^BOLD%^%^GREEN%^As the words are said the iron gate that barred your passage opens!");
	gate = 1;
}

void reset(){
	::reset();
	gate = 0;
}

int GoThroughDoor(){
	if(!gate){
		tell_room(TO,"%^BOLD%^"+TPQCN+" runs into the iron gate!",TP);
		write("%^BOLD%^You run into the iron gate!");
		return 0;
	}
	return 1;
}

int stop_open(string str){
    if(!str) return notify_fail("Open what?\n");
	if(str != "gate") return notify_fail("Open what?\n");
	write("%^BOLD%^You struggle with the magically sealed gate.");
	tell_room(TO,TPQCN+" struggles with the magically sealed gate!",TP);
	return 1;
}
