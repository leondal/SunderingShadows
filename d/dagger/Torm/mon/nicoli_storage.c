#include <std.h>
#include <daemons.h>
inherit "/std/obj/fence_store_int";

object ob;

void create(){
	::create();
   set_property("no teleport",1);
	set_properties((["light":2,"indoors":1]));

	set("short","DD guild storage");
	set("long","If you're here you shouldn't be, so report it to a wiz please.");
}

void reset(){
	object ob;
	int x, val;
	::reset();
	if(!present("tools")){
		new("/d/tharis/obj/thief_tools")->move(TO);
		new("/d/tharis/obj/thief_tools")->move(TO);
		new("/d/tharis/obj/thief_tools")->move(TO);
	}

	if(!present("playersettabletrapkit"))
	{
		x = 4;
		while(x)
		{
			if(!random(3)) 
			{
				ob = TRAP_D->get_trap_object("high", "random");
				val = 1000 + random(251);
			}
			else 
			{
				ob = TRAP_D->get_trap_object("mid", "random");
				val = 550 + random(251);
			}
			if(objectp(ob)) 
			{
				ob->move(TO);
				ob->set_value(val);
			}
			x--;
			continue;
		}
	}
	

	if(random(20) <8)
		if(!present("sheath")){
			ob = new("/d/tharis/obj/wrist_sheath");
			ob->move(TO);
			ob = new("/d/tharis/obj/wrist_sheath");
			ob->move(TO);
			ob = new("/d/tharis/obj/wrist_sheath");
			ob->move(TO);
	}
		
	if(random(20) < 8)
		if(!present("bag")){
			ob = new("/d/tharis/obj/bpowder");
			ob->move(TO);
			ob = new("/d/tharis/obj/bpowder");
			ob->move(TO);
			ob = new("/d/tharis/obj/bpowder");
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
