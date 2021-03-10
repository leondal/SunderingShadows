#include <std.h>
#include "farm.h"
inherit CROOM;
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
   	set_name("%^CYAN%^Piaf Huffelmuffin's Cellar");
   	set_short("%^CYAN%^Piaf Huffelmuffin's Cellar");
   	set_long("%^CYAN%^Under Piaf's workshop, this area of"+
		" the abode is used to store needed parts and tools."+
		"  Gears of all shapes and sizes rest on the floor.  "+
		"Boxes of %^BOLD%^%^WHITE%^crystals%^RESET%^%^CYAN%^"+
		" sorted by shapes are lined up against"+
		" the earthen walls.  Buckets of nails, screws, bolts and"+
		" rivets are scattered around the basement.  From the wooden"+
		" beams of the ceiling lengths of hoses, wires, and rope hang,"+
		" ever ready for the tinkering gnome to use.\n");
	set_smell("default","The cellar has an earthy scent.");
   	set_listen("default","The squeaking of a rodent can be heard.");
  	set_items(([
      	({"box","boxes","crystals"}) : "%^BOLD%^Boxes of crystals"+
			" sorted by shape rather than color are scattered "+
			"around the cellar. Perhaps you could search them?",
      	({"gear","gears"}) : "%^YELLOW%^Gears of all shapes and sizes"+
			" and materials rest on the floor of the cellar.  The "+
			"gears look in various states from well worn to brand new.",
		({"nails","screws","bolts","rivets","buckets"}) : "%^BLUE%^Buckets"+
			" of nails, screws, bolts, and rivets are mixed throughout "+
			"the cellar.  The large supply of them hints at just how much"+
			" work Piaf does in his workshop.",
		({"twine","hoses","wire","beams"}) : "%^ORANGE%^On wooden begs, coils"+
			" of twine, hoses, and wires hang around the cellar."
			]));
	set_search("default","%^BOLD%^%^CYAN%^The boxes of crystals look interesting.");
	set_search("box",(:TO,"search_box":));
	set_search("crystals",(:TO,"search_box":));
	FLAG=0;
	make_creatures();
}
void search_box(){
	if(FLAG) { 
		tell_object(TP,"%^CYAN%^The box looks as if its"+
			" already been searched.");
    	return; 
	}
	if(present("farm_mon")){
   		tell_object(TP,"Yeah, right, they won't let you search that.");
   	return 1;
	}
	if(random(4)){
                tell_object(TP,"%^BOLD%^You search through the box of crystals and find nothing of interest.");
		tell_room(ETP,"%^BOLD%^"+TPQCN+" seems disappointed as "+TP->QS+" searches the box.",TP);
	FLAG=1;
	return ;
	}
 	else{
	switch(random(36)){
case 0..20:
	new("/d/common/obj/misc/gem.c")->move(TO);
break;
case 21..30:
	 new("/d/common/obj/misc/gem.c")->move(TO);
	new("/d/common/obj/misc/gem.c")->move(TO);

break;
case 31..33:
	new("/d/common/obj/misc/gem.c")->move(TO);
	new("/d/common/obj/misc/gem.c")->move(TO);
	new("/d/common/obj/misc/gem.c")->move(TO);
break;
case 34..35:
	 new("/d/common/obj/misc/gem.c")->move(TO);
	new("/d/common/obj/misc/gem.c")->move(TO);
	new("/d/common/obj/misc/gem.c")->move(TO);
	new("/d/common/obj/misc/gem.c")->move(TO);
break;
	}
}
tell_object(TP,"%^BOLD%^You search through the box and find something sparkly.");
	tell_room(ETP,"%^BOLD%^"+TPQCN+" searches through "+
    		"the crystals in the box and finds something sparkly.",TP);
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
        		switch(random(30)){
case 0..10:
break;
case 11..21:
    	set_monsters(({MON"osquip"}),({1}));
break;
case 22..31:
    	set_monsters(({MON"osquip"}),({2}));
break;
			}
	}
	return;
}

void reset() 
	{ ::reset(); 
		FLAG=0; 
	return;
}
