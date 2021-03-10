#include <std.h>
#include "farm.h"
inherit CROOM;
object obj;
int FLAG;
	void make_creatures();
	void create(){
	make_creatures();
	set_repop(20);
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^CYAN%^Piaf Huffelmuffin's Workshop");
   	set_short("%^CYAN%^Piaf Huffelmuffin's Workshop");
   	set_long("%^CYAN%^This subterranean part of the home"+
		" serves as Piaf Huffelmuffin's workshop, where all"+
		" his inventions are crafted.  The cluttered workshop"+
		" is filled with strange gears, hoses, crystals, glass"+
		" tubes and mechanical parts in various stages of creation."+
		"  %^ORANGE%^Wooden%^CYAN%^ workbenches are scattered around"+
		" the room, covered with tools that Piaf uses.  A %^YELLOW%^glowing"+
		"%^RESET%^%^CYAN%^ crystal lamp hangs from the ceiling, "+
		"shedding light on the workroom.  Underfoot a clockwork rabbit"+
		" hops about with a small wicker broom, sweeping the floor clean.\n");
	set_smell("default","The smell of oil and metal lingers in the air.");
   	set_listen("default","Numerous mechanical devices hum and churn.");
  	set_items(([
      	({"rabbit"}) : "%^BOLD%^Piaf hates and fears nothing more "+
			"than dust bunnies.  To alleviate this problem and set"+
			" his fears to rest he has created a clockwork rabbit to"+
			" sweep the floor of his workshop.  The mechanical rabbit"+
			" hops about on its hind quarters as its front paws sweep"+
			" up the dust.",
      	({"lamp","crystal","crystal lamp"}) : "%^YELLOW%^A glowing crystal"+
			" lamp hangs from the ceiling, casting its bright glow on "+
			"the workshop.",
		({"workbench","table","worktable"}) : "%^ORANGE%^The wooden workbench is littered with"+
			" strange tools and even stranger items in various stages of"+
			" creation.  Metal hooks, bolts, screws, and rings are "+
			"intermixed with the mechanical contraptions.  Gears and"+
			" leather belts are scattered across the table, looking like"+
			" one chaotic mess.  Perhaps if you search the worktable you"+
			" might find something useful.",
			]));
	set_search("default","%^BOLD%^%^CYAN%^The worktable looks interesting.");
	set_search("table",(:TO,"search_table":));
	set_search("workbench",(:TO,"search_table":));
	set_search("worktable",(:TO,"search_table":));
	FLAG=0;
	make_creatures();
}
void search_table(){
	if(FLAG) { 
		tell_object(TP,"%^CYAN%^The worktable looks as if its"+
			" already been searched.");
    	return; 
	}
	if(present("farm_mon")){
   		tell_object(TP,"Yeah, right, they won't let you search that.");
   	return 1;
	}
	switch(random(14)){
case 0..2:
	"/d/common/daemon/randtreasure_d"->find_stuff(TO,"random");
break;
case 3:
	 new(OBJ"dinnerfork")->move(TO);
break;
case 4:
	 new(OBJ"backscratcher")->move(TO);
break;
case 5:
	 new(OBJ"goggles")->move(TO);
break;
case 6:
	 new(OBJ"jamspear")->move(TO);
break;
case 7:
	new(OBJ"wading_boots")->move(TO);
break;
case 8:
	new(OBJ"foil")->move(TO);
break;
case 9:
	obj=new("/d/common/obj/rand/s_curiass.c");
	obj->set_size(2);
	obj->move(TO);
break;
case 10..13:
	new(OBJ"toolset")->move(TO);
break;
	}
tell_object(TP,"%^ORANGE%^You search through the workbench and find something useful.");
	tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches through "+
    		"the mess on the workbench and finds something useful.",TP);
		FLAG=1;
		return;
}
void make_creatures()
{	
	int monsters;
   	monsters = has_mobs();
	if(!monsters) 
	{
     		if(mons) { mons = ([]); }
        		switch(random(80)){
case 0..10:
break;
case 11..21:
    	set_monsters(({MON"human_bandit"}),({1}));
break;
case 22..31:
    	set_monsters(({MON"dwarf_bandit"}),({1}));
break;
case 32..41:
   	set_monsters(({MON"halfling_bandit",MON"human_bandit"}),({1,1}));
break;
case 42..51:
	set_monsters(({MON"halfling_bandit"}),({2}));
break;
case 52..61:
	set_monsters(({MON"human_bandit"}),({2}));
break;
case 62..71:
	set_monsters(({MON"halfling_bandit",MON"human_bandit"}),({2,1}));
break;
case 72..79:
	set_monsters(({MON"dwarf_bandit",MON"human_bandit"}),({1,2}));
			}
	}
	return;
}

void reset() 
	{ ::reset(); 
		make_creatures();
		FLAG=0; 
		switch(random(5)){
case 0:  tell_room(TO,"%^BOLD%^The clockwork rabbit hops about sweeping the floor.");
	break;
case 1:  tell_room(TO,"%^BLUE%^ One of the contraptions bolts to life and whirls loudly.");
	break;
case 2:  tell_room(TO,"%^BOLD%^%^CYAN%^A metal crane moves the tools around on the table.");
      break;
case 3: tell_room(TO,"%^BOLD%^%^RED%^The clockwork rabbit shoots a jet of flame"+
	" from its cute little mouth, destroying the pile of dust it collected.");
	break;
case 4: tell_room(TO,"%^ORANGE%^The clockwork rabbit twitches its nose.");
	break;
   		}
	return;
}
