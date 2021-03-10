#include <std.h>
inherit WATER;

void create(){
  	::create();
   set_terrain(DEEP_WATER);
   set_travel(PAVED_ROAD);
  	set_name("pool4");
  	set_property("surface",0);
  	set_property("underwater",0);
  	set_property("light", 1);
  	set_property("indoors", 1);
  	set_short("The Bottom of a Pool");
  	set_long("%^CYAN%^"+
  		"You have finally come to the bottom of the pool and as you "+
  		"stand on its bottom looking around you take a closer look at "+
  		"things. There are %^ORANGE%^rocks%^CYAN%^ and much %^GREEN%^plant%^CYAN%^ life here, there are "+
  		"even %^MAGENTA%^flow%^RED%^e%^ORANGE%^r%^MAGENTA%^s%^CYAN%^ here of many assorted and blazing colors. The "+
                "%^BOLD%^archway%^RESET%^%^CYAN%^ stands to one side and the area surrounding it is "+
  		"clear of rocks, plants, flowers, of any life at all.%^RESET%^\n");
  	set_smell("default", "Are you crazy...you are underwater.");
  	set_listen("default", "You hear a strange vibration in the waters.");
  	set_items( ([
 ({ "plants","rocks","fish"}) : "Colorful fish swim happily through the gorgeous plants here near the bottom of the clear pool. A few rocks poke up from the sandy bottom.",
     	"archway" : "Looking at it, it seems rather ordinary really. As "+
     			"you look through it though you catch glimpses of where this "+
     			"crazy trip started and glimpses of more pool bottom....hmmmmm."
	]) );
  	set_exits( ([
     		"up" : "/d/koenig/town/pool3"
	]) );
      new("/d/koenig/town/items/poolchest.c")->move(TO);
}
void init() {
  	::init();
  	add_action("enter_archway", "archway");
}
int enter_archway(string str) {
  	if(present("water elemental")) {
  		tell_object(TP,"The elemental blocks your path!");
   		tell_room(TO,"You see the elemental block "+TPQCN+"'s path!",TP);
  		return 1;
	}
  	tell_object(TP,"As you pass beneath the archway you feel a strangness.");
  	tell_object(TP,"You have been teleported back to where it all began.");
    	tell_room(ETP,""+TPQCN+" passes beneath the archway but you notice "+
    		"they don't come out the other side!",TP);
      TP->move_player("/d/koenig/town/tower16");
  	return 1;
}
void reset(){
  	::reset();
   	if(!present("water elemental"))new("/d/koenig/town/mon/welemental.c")->move(TO);
}
