//TP proofed - Octothorpe 6/4/09
#include <std.h>
inherit ROOM;

void create() {
  	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  	set_property("light", 1);
  	set_property("indoors", 1);
  	set_property("no sticks",1);
        set_property("no teleport",1);
  	set_name("The gentleman's bedchambers.");
  	set_short("A Terrifying Bedchamber");
  	set_long(
         "%^RESET%^%^BOLD%^This so called 'Gentleman' is one strange individual.  "+
         "His airs of importance and well-schooled manners and intelligence "+
         "did not in any way prepare you for what lays before you now. "+
         "Looking around, you find yourself in what you would assume to "+
         "be his private bedchamber. But it looks more like a %^BOLD%^%^BLACK%^torture "+
         "chamber%^WHITE%^ to you. It would appear he also liked to play with his "+
         "%^RESET%^%^ORANGE%^food%^BOLD%^%^WHITE%^ before devouring it. You can almost hear the tortured "+
         "%^RED%^screams%^WHITE%^ of the souls who died in this room, and in the banquet "+
         "hall. Unexplained %^RESET%^shivers%^BOLD%^ of %^BOLD%^%^BLACK%^fear%^WHITE%^ travel the length of your "+
         "spine as you look upon the many undescribable features here.  "+
         "One thing catches your attention, a faint %^RESET%^glim%^BOLD%^%^BLACK%^m%^WHITE%^e%^RESET%^r%^BOLD%^%^WHITE%^ behind a "+
         "pair of %^MAGENTA%^curtains%^WHITE%^ on the far wall.%^RESET%^\n"
   	);
  	set_smell("default","It smells less than pleasant here.");
  	set_listen("default","You swear you can hear the tortured screams of past victims.");
  	set_items( ([
     		"curtains":"As you pull the curtains further apart you find yourself "+
     			"standing before a portal. Where it leads, you do not know."
     	]) );
      set_pre_exit_functions( ({"south"}),({"go_south"}) );
      set_pre_exit_functions( ({"portal"}),({"GoThroughDoor"}) );
  	set_exits( ([
     		"south":"/d/koenig/town/tower32",
     		"portal":"/d/koenig/town/room8"
     	]) );
  	set_invis_exits( ({"portal"}) );
}



void reset(){
  	::reset();
  	if(!present("donner"))new("/d/koenig/town/mon/donner.c")->move(TO);
  	if(!present("bugsy"))new("/d/koenig/town/mon/bugsy.c")->move(TO);
  	if(!present("Muileann Quest"))new("/d/koenig/town/items/boy.c")->move(TO);
}

int go_south(){
  	if((string)TPQN == "freloc") return 1;
  	if(present("donner")){
  		tell_object(TP,"Donner blocks your path.");
  		tell_room(ETP,"Donner blocks "+TPQCN+"'s path.",TP);
  		return 0;
	}
  	return 1;
}

int GoThroughDoor(){
  	if((string)TPQN == "freloc") return 0;
  	if(present("bugsy")){
  		tell_object(TP,"Bugsy blocks your path.");
  		tell_room(ETP,"Bugsy blocks "+TPQCN+"'s path.",TP);
  		return 0;
	}
  	return 1;
}
