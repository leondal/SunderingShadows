#include <std.h>

inherit ROOM;

void create(){
    ::create();
   set_property("no teleport",1);

    set_properties((["light":2,"indoors":1]));

    set("short","thief storage");
    set("long","If your here you shouldn't be");
}

void reset(){
    ::reset();

    if(!present("tools")){
	new("/d/tharis/obj/thief_tools")->move(TO);
	new("/d/tharis/obj/thief_tools")->move(TO);
	new("/d/tharis/obj/thief_tools")->move(TO);
	new("/d/tharis/obj/thief_tools")->move(TO);
    }

    if(random(20) <8)
	if(!present("sheath")){
	    new("/d/tharis/obj/wrist_sheath")->move(TO);
	    new("/d/tharis/obj/wrist_sheath")->move(TO);
	    new("/d/tharis/obj/wrist_sheath")->move(TO);
	}

    if(random(20) < 8)
	if(!present("bag")){
	    new("/d/tharis/obj/bpowder")->move(TO);
	    new("/d/tharis/obj/bpowder")->move(TO);
	    new("/d/tharis/obj/bpowder")->move(TO);
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
    if(random(10) < 7)
	if(!present("caltrops"))
	    new("/d/tharis/obj/caltrops")->move(TO);



}
