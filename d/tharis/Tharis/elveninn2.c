//elveninn2.c

#include <std.h>

inherit ROOM;

int flag = 0;

void create(){
	::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
	set_property("light",2);
	set_property("indoors",1);
   set_short("The back room of the inn");
	set("long",
@OLI
    %^BOLD%^%^YELLOW%^Storage room in the inn%^RESET%^
This back room contains some food products and other items. Large
casks of ale sit here, most are untapped. The room is plain with shelves
and other such items. You do notice a throw rug thrown not in the middle 
of the room but to one side. To the east is the main room of the inn.
OLI
	);
	set_exits(([
		"east":"/d/tharis/Tharis/elveninn",
		"down":"/d/tharis/Tharis/sewer17"
		]));
	set_items(([
             "rug":"This throw rug is obviously covering something. You should lift it.",
		"casks":"These large untapped ale casks could get you really drunk!",
		"shelves":"These shelves are cluttered with nothing important."
		]));
	set_smell("default","The raw spices tickle your nose.");
	set_listen("default","You hear a slight dripping noise from below you.");
	set_invis_exits(({"down"}));
	set_pre_exit_functions(({"down"}),({"down"}));
}

void init(){
	::init();
	add_action("lifting","lift");
}

int lifting(string str){
	if(!str || (str != "rug" && str != "throw rug")) return notify_fail("Lift what?\n");
	if(flag) return notify_fail("The rug lies in a heap to one side already!\n");
	
	write("%^BOLD%^You toss the rug aside revealing a trapdoor going down!");
	tell_room(TO,"%^BOLD%^"+TPQCN+" throws the rug to one side and finds a trap door!",TP);
	remove_invis_exit("down");
	flag = 1;
	return 1;
}
		
int down(){
	return flag;
	}
	
void reset(){
	::reset();
	flag = 0;
	set_invis_exits(({"down"}));
	}
