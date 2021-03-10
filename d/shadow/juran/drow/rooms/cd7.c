//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void create(){
 	::create();
   set_short("Trophy Room");
   set_long(
   	"%^BOLD%^%^RED%^"+
   	"This room has each wall covered with different items that one might "+
   	"assume where trophies.  The room is spectacular in its barbarism.  "+
   	"Many different holy symbols are placed on the walls, each in its own "+
   	"place and no symbol duplicated.  An eye patch hangs from a nail as well "+
   	"as several different colors of hair hanging from different locations "+
   	"many with some portion of the skin that the hair grew from still "+
   	"attached.  Various captured weapons and armor, also, lie at various "+
   	"points in the room sharing the spotlight.  No labeling or system can be "+
   	"seen to identify each of these items and their previous owners. Among "+
   	"the more grisly trophies are those that are former body parts of once "+
   	"living beings.  What adds to the brutal realism of this room is that "+
   	"many of the items still have dark stains and scraps of dried flesh "+
   	"attached to them as if no effort was made or considered in cleaning "+
   	"them up before display.  There is a painting  on the south wall."+
   	"%^RESET%^"
   );
 	set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room has a musky smell as well as a darker scent "+
   	"that is better left undetermined.");
   set_listen("default","You own heart beats in your ears.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to cover "+
     		"the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
     		"looks to be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and free of "+
     	"dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	({"holy symbols","holy symbol"}) : "Many holy symbols are displayed, but "+
     		"almost exclusively those that belong to followers of gods of good "+
     		"intent.  One symbol, that of Helm seems to be displayed in a manner "+
     		"to show that it is more treasured than the rest.  The Help symbol "+
     		"is almost completely covered with a dark stain.\n",
     	({"hair","scalps","scalp"}) : "There is hair mounted onto a board and "+
     		"braided so that the observer can more easily tell the color of "+
     		"the hair.  In many cases the hair is still attached to dried, "+
     		"shriveled up skin that it sprouted from.\n",
     	"eye patch" : "The eye patch hangs from a nail and seems to have a "+
     		"golden eye carefully painted on the outside so that everyone "+
     		"would see it when it is worn.\n",
     	({"weapons","armors"}) : "Broken lances that once belonged to mighty "+
     		"paladins, swords, daggers. Maces, helms, plate mails, and rings "+
     		"stand or hang from various points along the walls.\n",
     	"body parts" : "The various body parts are now mostly only skeletal "+
     		"remains with tattered pieces of flesh hanging onto the bone.  "+
     		"Little is anything was done by the owner to preserve these "+
   		"specimens.\n",
      "painting" : "The painting depicts a battle.  In the battle you can "+
      	"see four individuals.  On the ground is a dwarf and he is bound "+
      	"and gagged.  Fighting are two humans, armor clad and wielding "+
      	"lances, riding magnificent chargers toward a lone drow.  The "+
      	"drow is on foot, but standing his ground against the humans.  "+
      	"The drow has his arms raised above his head and power seems to "+
      	"be forming between his hands.  The drow is unbloodied, but the "+
      	"humans look to be on the verge of loosing.  Fear is painted on "+
      	"the faces of the dwarf and the humans while a look of "+
      	"unadulterated pleasure is written on the face of the drow.\n"
      ]));
    	set_exits(([
			"west" : DROOMS+"cd5"
    	]));

    	set_door("trophy room door",DROOMS+"cd5","west","obsidian key");
    	set_door_description("trophy room door","This is a normal looking wooden door "+
    		"with a simple lock.");
   	set_string("trophy room door","open","You open the door into a dark room.\n");
}