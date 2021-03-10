#include <std.h>

inherit ROOM;

void create(){
	::create();
	
	set_properties((["light":2,"indoors":1]));
	
    set_property("no teleport",1);
	set_short("Assassin storage room");
	set("long","If your here you shouldn't be");
}

void reset(){
	::reset();
	
	if(!present("dagger")){
		new("/d/laerad/obj/ice_dagger")->move(TO);
		new("/d/laerad/obj/ice_dagger")->move(TO);
		}
		
	if(random(20) <8)
		if(!present("sheath")){
			new("/d/tharis/obj/wrist_sheath")->move(TO);
			new("/d/tharis/obj/wrist_sheath")->move(TO);
			new("/d/tharis/obj/wrist_sheath")->move(TO);
		}
		
   if(random(20) < 12)
	if(!present("poison")){
	new("/cmds/thief/poison")->move(TO);
		new("/cmds/thief/poison")->move(TO);
		new("/cmds/thief/poison")->move(TO);
             new("/cmds/thief/poison")->move(TO);
             new("/cmds/thief/poison")->move(TO);
             new("/cmds/thief/poison")->move(TO);
}
	}
