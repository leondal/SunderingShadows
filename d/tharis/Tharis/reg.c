#include <std.h>

inherit ROOM;

string *name_list;

void create(){
	::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
	name_list = ({});
	set_property("light",2);
	set_property("indoors",1);
     set("short","Registration office");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The elf registration office of Tharis%^RESET%^
This building is where elves are registered by the city. You must sign 
the <%^BOLD%^register%^RESET%^> here if you are to be allowed to leave here alive.
This is mostly an exercise in insulting the elves. The rumor is that
at the end of every day Merve loses the list just so that the elves
have to do it all over again. You notice that the floor boards carry a slight tint of crimson.
OLI
	);
	set_exits(([
		"south":"/d/tharis/Tharis/reg2",
		"north":"/d/tharis/Tharis/estreet10"
	]));
	set_items(([]));
	set_smell("default","This office carries a rancid smell.");
	set_listen("default","Shuffling papers and feet reach your ears.");
	set_pre_exit_functions(({"north"}),({"stop_north"}));
}


void reset(){
	::reset();
	
	if(!present("merve"))
		new("/d/tharis/monsters/merve")->move(TO);
}

int stop_north(){
	object room, ob;
	
	if(!present("merve")) return 1;
    if(wizardp(TP)) return 1;
   if((string)TP->query_race() != "elf" && (string)TP->query_race() != "drow") return 1;
   if(!userp(TP)) return 1;
	
	if(member_array((string)TP->query_name(),name_list) != -1){
		tell_room(TO,"%^RED%^Merve announces:%^GREEN%^ All right elf you are registered.");
		return 1;
	}
	else {
		tell_room(TO,"%^BOLD%^%^RED%^Merve yells:%^YELLOW%^ YOU, ELF, HOW DARE YOU TRY TO ESCAPE PROPER REGISTRATION!");
		tell_room(TO,"%^BOLD%^%^RED%^Merve yells:%^YELLOW%^ BOYS!!!!!");
		
		room = find_object_or_load("/d/tharis/Tharis/reg2");
		if(present("ruffian",room)) tell_room(TO,"%^BOLD%^Some ruffians run into the room from the south");
		else tell_room(TO,"When no one answers his call, Merve boldly blocks your way.");
		while(ob = present("ruffian",room))
			ob->move(TO);
		return 0;
	}
}
 
void init() {
	::init();
	add_action("reg","register");
	}
	
int reg(){

    if((string)TP->query_race() != "elf" && (string)TP->query_race() != "drow") return notify_fail("You needn't register.\n");
	
	if(member_array((string)TP->query_name(),name_list) == -1){
                tell_room(TO,"You see "+TPQCN+" write "+TP->query_possessive()+" name in a large book",TP);
		write("You write your name in a large book");
		name_list += ({TP->query_name()});
		return 1;
	} else notify_fail("You needn't do that again\n");
}
		
	
	
