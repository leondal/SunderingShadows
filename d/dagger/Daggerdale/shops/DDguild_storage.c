//DDguild_storage - Storage for Vethor's guild in Daggerdale

#include <std.h>

inherit ROOM;

object ob;

void create(){
	::create();
   set_property("no teleport",1);
	set_properties((["light":2,"indoors":1]));

	set("short","DD guild storage");
	set("long","If you're here you shouldn't be, so report it to a wiz please.");
}

void reset(){
	::reset();
	if(!present("tools")){
		new("/d/tharis/obj/thief_tools")->move(TO);
		new("/d/tharis/obj/thief_tools")->move(TO);
		new("/d/tharis/obj/thief_tools")->move(TO);
	}
		
	if(random(20) <8)
		if(!present("sheath")){
			ob = new("/d/tharis/obj/wrist_sheath");
			ob->set_value(2020); 
			ob->move(TO);
			ob = new("/d/tharis/obj/wrist_sheath");
			ob->set_value(2020); 
			ob->move(TO);
			ob = new("/d/tharis/obj/wrist_sheath");
			ob->set_value(2020); 
			ob->move(TO);
	}
		
	if(random(20) < 8)
		if(!present("bag")){
			ob = new("/d/tharis/obj/bpowder");
			ob->set_value(220); 
			ob->move(TO);
			ob = new("/d/tharis/obj/bpowder");
			ob->set_value(220); 
			ob->move(TO);
			ob = new("/d/tharis/obj/bpowder");
			ob->set_value(220); 
			ob->move(TO);
	}

   if(random(20) < 12)
	if(!present("poison")){
	new("/cmds/thief/poison")->move(TO);
	new("/cmds/thief/poison")->move(TO);
	new("/cmds/thief/poison")->move(TO);
	new("/cmds/thief/poison")->move(TO);
	}

	if(random(10) < 7)
   if(!present("caltrops"))
   new("/d/tharis/obj/caltrops")->move(TO);
}
