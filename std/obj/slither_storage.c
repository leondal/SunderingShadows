#include <std.h>
#include <daemons.h>

inherit "/std/obj/fence_store_int";

void create(){
     ::create();
}

void reset()
{
	object ob, TrapOb;
	int x, val;
    	::reset();
        
    	if(!present("sheath")) new("/d/tharis/obj/wrist_sheath")->move(TO);
    	if(!present("sheath 2")) new("/d/tharis/obj/wrist_sheath")->move(TO);

	if(!present("playersettabletrapkit"))
	{
		tell_room(TO, "It's getting here...");
		x = 3 + random(2);
		while(x)
		{
			if(!random(3)) 
			{
				TrapOb = TRAP_D->get_trap_object("mid", "random");
				val = 750 + random(251);
			}
			else 
			{
				TrapOb = TRAP_D->get_trap_object("low", "random");
				val = 400 + random(201);
			}
			if(objectp(TrapOb)) 
			{
				tell_room(TO, "Trap object is valid");
				TrapOb->move(TO);
				TrapOb->set_value(val);
			}
			x--;
			continue;
		}
	}

    	while(ob = present("kit")) ob->remove();
    	while(!present("bright white 3")) 
	{
      	ob = new ("/d/common/obj/potion/extra_heal");
      	ob->set_uses(15 + random(5));
      	ob->move(TO);
    	}
}