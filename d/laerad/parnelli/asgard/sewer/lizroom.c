#include <std.h>
#include "lizard.h"
inherit CROOM;

void create(){
   if(base_name(TO) != "/d/laerad/parnelli/asgard/sewer/lizroom") {
    switch(random(21)) {
     case 0..3:	
	set_monsters( ({LMON+"lman", LMON+"plead"}), ({2, 1 })); 
	break;
     case 4:	
	set_monsters( ({LMON+"lman", LMON+"warlead", LMON+"lman_youth"}), ({2, 1, 1 })); 
	break;
     case 5:	
	set_monsters( ({LMON+"lman"}), ({random(3)+1}) ); 
	break;
     case 6:	
	set_monsters( ({LMON+"lman", LMON+"plead", LMON+"warlead"}), ({2, 1, 1}) ); 
	break;
     case 7:
	set_monsters( ({LMON+"lman", LMON+"plead", LMON+"lman_youth"}), ({2, 1, 1}) );
	break;
	case 8:
     set_monsters( ({LMON+"lman_youth", LMON+"plead", LMON+"warlead"}), ({2, 1, 1}) ); 
     default:
	break;
    }
   }
   ::create();
   set_repop(30);
	set_name("Lizard Caves");
	set_short("Dark and damp cavern.");
  	set_terrain(NAT_CAVE);
  	set_travel(RUTTED_TRACK);
	set_long("You are standing in a large cavern.  "+
   		"Stalagmites sprout from the floor and look much like the teeth of "+
   		"a large beast.  Stalactites dangle from the ceiling and glisten "+
   		"with a fine coat of water.  The ceiling is high above you "+
   		"somewhere in the darkness.  Loose rocks from fallen "+
   		"stalactites litter the floor and the cavern opens up all around you.");
	set_property("indoors",1);
	set_property("no teleport",1);
	set_property("no sticks",1);
	set_property("light",1);
	set_smell("default","The caves smell musty and damp.");
	set_listen("default","An occasional drop from a stalactite splashes to the floor.");
    set_items(([
   	"walls":"Much like what you would expect cave walls to be like, hard, wet and cool to the touch.",
   	"floor":"Littered with rubble from broken stalactites watching your step and watching your head may prove interesting.",
   	({"stalactite","stalactites"}):"Hanging high above your head...sure hope they do not crash down upon you.",
   	({"stalagmites","stalagmite"}):"Sprouting from the floor these stones vary in size and could be hiding many things from your vision."
    ]));
}