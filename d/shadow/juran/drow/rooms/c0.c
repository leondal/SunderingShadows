//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;
void crushing(object tp, int num);
void set_rope(int rope);

int rope_present;

void create(){
	::create();
   set_short("Cave Entrance");
   set_long(
   	"%^RESET%^%^ORANGE%^"+
   	"After finding the hidden tunnel in the shrubbery you find climb down a "+
   	"long way to finally end up in an unlit dry cave.  The floor is "+
   	"remarkably clear of debris.  Even though dry you find that there is "+
   	"enough moisture in the air to bring nourishment to various molds and "+
   	"fungi that cover parts of the walls.  The cave appears to be an older "+
   	"one since you notice very little in the way of stalagmites and "+
   	"stalactites.  The cave opens up and you can move northeast, east, or up.\n"+
		"%^RESET%^"
   );
  	set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
	set_property("indoors",1);
	set_property("light",-3);
	set_smell("default","You smell the musty smells of a dry cave.");
	set_listen("default","It is very quiet and the noises you make are echoed "+
		"off the walls.");
	set_items(([
     	({"molds","fungi","mold","fungus"}) : "Various colors of molds and fungi "+
     		"cling to the walls, floor, and ceiling.\n",
		({"stalagmite","stalagmites"}) : "Jutting from the floor these rock "+
			"formations look like old worn dull teeth pointing to the ceiling.\n",
		({"stalactite","stalactites"}) : "Hanging from the ceiling these rock "+
			"formations look like old worn dull teeth pointing towards the floor.\n",
		({"wall","walls"}) : "The rock walls look very solid with an occasional "+
			"dotting of a mold or a fungus to break its monotony.\n",
		"floor" : "Remarkably clear of debris the floor looks like the area may "+
			"have been cleared and cleaned.\n",
		"ceiling" : "The ceiling is high above and lost in the shadows, "+
			"stalactites hang above you threateningly.\n"
        	]));
   set_exits(([
		"east" : DROOMS+"c2",
		"northeast" : DROOMS+"c1"
  	]));

   set_climb_exits((["climb":({DROOMS+"outside",20,6,100})]));
   set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
		"darkness bouncing off the sides of the tunnel until you come to a sudden "+
		"and painful stop at the bottom!%^RESET%^\n");
   set_trap_functions(({"east"}),({"cave_in"}),({"east"}));
}
int cave_in(){
   TP->set_paralyzed(5000,"You are thrown off your feet and unable to do that!");
 	call_out("rubble_fill",3);
   crushing(TP,0);
	return 0;
}
void rubble_fill(){
	(DROOMS+"c2")->remove_exit("east");
	(DROOMS+"c1")->remove_exit("southeast");
	(DROOMS+"c3")->remove_exit("west");
	(DROOMS+"c3")->remove_exit("northwest");
	tell_room((DROOMS+"c1"),"%^BOLD%^%^RED%^The ceiling suddenly falls in blocking "+
		"the exit to the southeast.",TP);
	tell_room((DROOMS+"c3"),"%^BOLD%^%^RED%^The ceiling suddenly falls in blocking "+
		"the exits to the west and northwest.\n",TP);
}
void crushing(object tp,int num){
	switch(num){
   	case(0):
   		tell_object(TP,"%^BOLD%^%^RED%^As you start to move east you "+
         	"feel a tug at your ankle and hear the sound of a "+
            "small wire breaking.%^RESET%^\n");
			tell_room(ETP,""+TPQCN+" looks suddenly concerned.",TP);
         break;
   	case(1):
   		tell_room(ETP,""+TPQCN+" gulps.",TP);
         tell_object(TP,"%^BOLD%^%^RED%^Portions of the ceiling fall "+
         	"right where you are standing and nearly crushes "+
				"you.%^RESET%^\n");
        	tell_room(TO,"%^BOLD%^%^RED%^The ceiling collapses to the "+
				"east.%^RESET%^\n");
			break;
    	case(2):
    		tell_room(ETP,"Dust and debris fill the room causing you to "+
         	"choke and impairing your vision.");
        	break;
   	case(3):
   		tell_room(ETP,"The passage to the east is completely blocked.");
         break;
     	case(4):
     		TP->set_paralyzed(0);
         return;
  	}
   num++;
   call_out("crushing",0,tp,num);
   return;
}