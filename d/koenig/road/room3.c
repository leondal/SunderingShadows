#include <std.h>
inherit ROOM;

void create(){
  	::create();
   set_travel(DIRT_ROAD);
   set_terrain(VILLAGE);
  	set_property("light", 1);
  	set_short("The road that leads to the ocean and the gates of Muileann.");
  	set("day long","%^GREEN%^The gates of Muileann stand tall and "+
  		"intimidating here.  Looking at them you begin to wonder if "+
  		"this town is trying to keep something "+
		"%^RESET%^%^RED%^OUT%^RESET%^%^GREEN%^...or something "+
      	"%^RESET%^%^RED%^IN%^RESET%^%^GREEN%^. The road continues on "+
      	"to the north towards the ocean.");
  	set("night long","%^BOLD%^%^BLUE%^The gates of Muileann stand tall and "+
      	"intimidating here. Shadows dance more thickly here in the midnight "+
      	"hour making you more nervous then before.  You find yourself "+
      	"wanting to get inside the town fast, or trying your luck and "+
      	"making a break for it and see how fast your legs can carry "+
      	"you to the ocean.");
  	set_items(([
     		"gates" : "These gates are enormous! A giant could have built "+
     			"these and judging by their size one did! They are made "+
     			"of stone wood and as if to soften their harsh appearance "+
     			"an intricate if delicate design made of wrought iron has "+
     			"been inlaid over the wood.",
	]));
  	set_smell("default","Crisp air and the taint of something unclean.");
  	set_listen("default","Insects buzz about and town noises can be heard.");
  	set_exits(([
     		"north" : "/d/koenig/road/room4",
     		"south" : "/d/koenig/road/room2"
	]));
  	new("/d/koenig/obj/signpost.c")->move(TO);
}

void init(){
  	::init();
    	add_action("knock","knock");
}

int knock(string str){
   object gk;
   	if(str != "on gates") return notify_fail("Maybe you should "+
   		"try <<knock on gates >>.\n");
  	tell_room(ETP,"You see "+TPQCN+" step up to the great gates and "+
  		"begin knocking with one of the knockers.",TP);
  	tell_object(TP,"You step up to the great gates and begin to knock with "+
                 "one of the knockers.");
    gk = find_object_or_load("/d/koenig/town/mon/gatekeeper1");
  if(!present("gatekeeper"))
      gk->move(TO);
    gk->start_grumble();
  	return 1;
}
