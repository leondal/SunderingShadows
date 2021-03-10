//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void bathing(object tp, int num);

void create(){
	::create();
	set_name("hot springs");
   set_short("hot springs pool");
   set_long(
    	"%^RESET%^%^ORANGE%^"+
    	"This part of the cave is large and airy.  You have entered into a large "+
    	"cavern.  The ceiling is so high that is cannot be seen with the feeble "+
    	"light sources that most surface dwellers must use to see in these caves.  "+
		"Stalagmites dot the floor area and provide many shadows even with the "+
		"best lighting.  The floor here is relatively free of debris as though "+
		"it has been cleared at some point in the recent past.  Guano deposits "+
		"splatter some of stalagmites attesting to the fact there is life in "+
		"the upper-reaches of the cavern.  Patches of mold and fungi add color to "+
		"the otherwise drab appearance of underground stone.  %^BOLD%^%^BLUE%^You "+
		"see a steaming pool of water that is about 50 feet wide by 80 feet "+
		"long.%^RESET%^%^ORANGE%^  The water gives off a mist from its surface due "+
		"to the difference in temperature of the water and the cavern.   Some of "+
		"the stone surfaces near the pool look to have been shaped and resemble "+
		"rough hewn benches and stone couches.\n"+
		"%^RESET%^"
    	);
  	set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
  	set_property("indoors",1);
	set_property("light",-3);
	set_smell("default","The room smells strongly of brimstone.  This smell comes "+
		"from the hot pool of water which dominates the room.\n");
	set_listen("default","Aside from your occasional noises you can hear the "+
		"chirps and squeaks of a colony of bats high above.");
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
		"guano" : "The is bat poop.  Mostly this substance is dry and white, "+
			"but in some cases you find to your disgust it is still quite moist.\n",
		({"pool","water"}) : "The surface of the pool is as smooth as glass and "+
			"in the darkness it is as black as the darkest obsidian.  The water "+
			"gives off a mist because the water is much warmer than the chilly "+
			"cavern.  Upon testing the water you find that the sulfur content "+
			"would make it unsuitable for drinking, but the temperature, while "+
			"hot, would not cause any permanent damage if one were to enter the "+
			"water for any reason, even to bathe.  The Sulfur and the water would "+
			"not combine to well with most armor and equipment and could cause "+
			"damage to them.\n"
		]));
    	set_exits(([
			"southeast" : DROOMS+"c12",
			"south" : DROOMS+"c8",
			"southwest" : DROOMS+"c4"
    	]));
}
void init(){
    ::init();
    add_action("bathe","bathe");
}
int bathe(string str) {
   if (str == "in pool"){
    	TP->set_paralyzed(5000,"You are bathing and relaxing and unable to do that!");
      bathing(TP,0);
      return 1;
  	}else{
 		tell_object(TP,"Bathe in what?\n");
      return 1;
   }
}
void bathing(object tp,int num){
	switch(num){
   	case(0):
   		tell_object(TP,"%^BOLD%^%^BLUE%^You slip into the water slowly "+
				"getting used to the heat!\n");
			tell_room(ETP,""+TPQCN+" slides gingerly into the water.",TP);
         break;
     	case(1):
     		tell_object(TP,"%^BOLD%^%^BLUE%^You find that the water is not "+
         	"too deep, but gets hotter as you move toward the "+
            "northwest part of the pool.\n");
			tell_room(ETP,""+TPQCN+" moves to the northwest part of the "+
				"pool and pauses.\n",TP);
			break;
    	case(2):
    		tell_object(TP,"%^BOLD%^%^BLUE%^You stumble on what seems to be an "+
				"underwater stone bench in the southeast part of the pool "+
				"perfect for sitting on and relaxing.\n");
        	tell_room(ETP,""+TPQCN+" sits down in the southeast part of the "+
				"pool and lets out a relaxed sigh.",TP);
         break;
    	case(3):
    		tell_object(TP,"%^BOLD%^%^BLUE%^You rest with your eyes closed "+
         	"for a time and absorb the relaxing heat from the water as "+
				"your muscles unkink.\n");
			tell_room(ETP,""+TPQCN+" rests with eyes close and a peaceful "+
				"smile.",TP);
        	break;
     	case(4):
     		tell_object(TP,"%^BOLD%^%^BLUE%^You rise having rested "+
         	"enough for now and leave the pool slowly.\n");
        	tell_room(ETP,""+TPQCN+" rises from the pool reluctantly, but "+
				"refreshed.",TP);
         break;
     	case(5):
     		TP->set_paralyzed(0);
			TP->heal(random(4)+2);
         return;
    }
    num++;
    call_out("bathing",0,tp,num);
    return;
}