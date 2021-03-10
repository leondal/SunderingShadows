//Coded by Diego//

#include <std.h>
#include "jdrow.h"

inherit VAULT;

void create(){
::create();
   set_name("cavern");
   set_short("cavern");
   set_long(
    	"%^RESET%^%^ORANGE%^"+
    	"You have entered into a large "+
    	"cavern.  The ceiling is so high that is cannot be seen with the feeble "+
    	"light sources that most surface dwellers must use to see in these caves.  "+
		"Stalagmites dot the floor area and provide many shadows even with the "+
		"best lighting.  The floor here is relatively free of debris as though "+
		"it has been cleared at some point in the recent past.  Guano deposits "+
		"splatter some of stalagmites attesting to the fact there is life in "+
		"the upper-reaches of the cavern.  Patches of mold and fungi add color to "+
		"the otherwise drab appearance of underground stone.\n"+
		"%^RESET%^"
   );
	set_property("indoors",1);
	set_property("light",-3);
  	set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
	set_smell("default","You smell the musty smells of a dry cave.");
	set_listen("default","It is very quiet and the noises you make are echoed "+
		"off the walls except for the occaional chirps of a bat colony high above.");
	set_items(([
      ({"molds","fungi","mold","fungus"}) : "Various colors of molds and fungi "+
      	"cling to the walls, floor and ceiling.\n",
		({"stalagmite","stalagmites"}) : "Jutting from the floor these rock "+
			"formations look like old worn dull teeth pointing to the ceiling.\n",
		({"stalactite","stalactites"}) : "Hanging from the ceiling these rock "+
			"formations look like old worn dull teeth pointing towards the floor.\n",
		({"wall","walls"}) : "The rock walls look very solid with an occasional "+
			"dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "Remarkably clear of debris the floor looks like the area may "+
			"have been cleared and cleaned.\n",
		"ceiling" : "The ceiling is high above and lost in the shadows, "+
			"stalactites hang above you threateningly.\n",
		"guano" : "This is bat poop.  Mostly this substance is dry and white, "+
			"but in some cases you find to your disgust it is still quite moist.\n"
	]));
}