//tent1.c

#include <std.h>

inherit ROOM;

int searched;

void create(){
	::create();
	
	set_name("The good leader's tent");
	set_short("The steel dragon's tent");
	set_properties((["indoors":1,"light":2]));
	set_long(
@OLI
	This tent is obviously doubles as the good leader's dwelling and the 
war room for the army of good. It is richly decorated. Lanterns flicker about
the room. The richness of the room impresses you as you gaze about. The
occupant of this room must indeed be a grand warrior to have gathered so much
about him. You wonder what a through search of the room might turn up.
OLI
	);
	set_exits(([
		"exit":"/d/tharis/forest/good13"
		]));
	set_items(([
		"lanterns":"These shiney brss lanterns shead light all about."
		]));
	
	set_search("default",(:TO,"search_func":));
	set_smell("default","Sweet insense is burning maybe trying to cover a small oder.");
set_property("no teleport",1);
	set_listen("default","The chirp of a bird and the hum of the lantern flames is all that is heard.");

}

void search_func(){
	object ob,ob2;
	
	if(present("old man") || present("dragon"))
		return tell_object(TP,"Search while the owner is watching .. I think not!\n");
	
	if(!searched) {
		write("You find several heavy chests!");
		tell_room(TO,"You see "+TPQCN+" find a chests",TP);
		
		ob = new("/d/shadow/obj/misc/lkchest");
		ob->set_weight(1000);
		ob2 = new("/std/obj/coins");
		ob2->add_money("gold",1000);
		ob2->add_money("platinum",50);
		ob2->move(ob);
		searched = 1;
		ob->toggle_closed();
		ob->toggle_lock();
		ob->move(TO);
		
	} else 
		write("You find nothing odd");
}

void reset(){
	::reset();
	
	searched =0;
	
	if(!present("old leader"))
		new("/d/tharis/monsters/old_leader")->move(TO);
}
	
		
	
