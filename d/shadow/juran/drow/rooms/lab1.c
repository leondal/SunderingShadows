//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void create(){
	object ob;
   ::create();
	set_name("scrying room");
  	set_short("Scrying Room");
  	set_long(
   	"%^MAGENTA%^"+
   	"This room is small, but comfortable looking.  In the center of the "+
   	"north wall is a very large mirror.  Set in from of the mirror is a "+
   	"large overstuffed and comfortable looking, leather covered chair.  "+
   	"Next to the chair is a small table.  In the southeast corner is a small "+
   	"cot.\n"+
   	"%^RESET%^"
   );
  	set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The only thing you smell is the leather from the chair.");
   set_listen("default","The room is as quiet as a tomb.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to cover "+
     		"the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
     		"looks to be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and "+
     		"free of dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	"mirror" : "A very large mirror dominates the north wall.  The surface "+
     		"is smooth and the reflection is without any distortions.  The "+
     		"mirror is obviously an expensive one.\n",
     	"chair" : "The chair looks to be very comfortable to someone who is "+
     		"elf-sized.  It is overstuffed with armrests and is covered in a "+
     		"gray leather of some kind.  The chair is placed in front of the "+
			"mirror.\n",
		"table" : "The table is within reach of the chair has a decanter of a "+
			"dark liquid sitting on it.  There is a small crystal glass sitting "+
			"next to the decanter."
	]));
	
   set_search("chair","You find that the armrest is loose and can be moved.\n");
   
   ob = new("/d/magic/obj/mirror");
   ob->move(TO);
   set_exits(([
		"west" : DROOMS+"lab0"
   ]));
}
void init() {
  	::init();
  	add_action("pull","pull");
  	add_action("lift","lift");
}
int pull(string str) {
  	if(!str) {
     	tell_object(TP,"Pull what?");
     	return 1;
   }
  	if(str == "shelf"){
     	tell_object(TP,"You pull the shelf closed behind you hiding the entrance "+
     		"once again.\n");
     	tell_room(ETP,""+TPQCN+" pulls the shelf behind him hiding the exit again.\n",TP);
     	(DROOMS+"lab0")->remove_exit("east");
     	return 1;
  	}
}
int lift(string str) {
 	if(!str) {
     	tell_object(TP,"Lift what?");
     	return 1;
   }
  	if(str == "armrest"){
     	tell_object(TP,"You lift the armrest and discover a compartment in the arm "+
     		"of the chair.\n");
     	tell_room(ETP,""+TPQCN+" lifts the armrest of the chair and opens a small "+
			"compartment in the arm of the chair.\n",TP);
     	new(DSTUFF+"obs_key")->move(TO);
     	return 1;
     	}
}