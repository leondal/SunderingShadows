//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void create(){
	::create();
   set_name("sitting room");
   set_short("Sitting Room");
   set_long(
   	"This room is furnished with a leather-covered couch and two leather "+
    	"covered chairs.  There is a table between the chairs and one on each end "+
    	"of the couch.  Against the west wall if a cabinet with glass doors that "+
    	"stands about 6 feet tall.  A small fireplace is set into the northern "+
    	"wall.  Over the fireplace is a painting.  There is a door in the east, "+
    	"south, and northwest.\n"
   );
 	set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room smells clean and dry.");
   set_listen("default","You hear very little save the noises you make yourself.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to cover "+
     		"the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
     		"looks to be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and free of "+
     		"dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	({"couch","chair","chairs"}) : "The furniture is covered in some sort of "+
			"leather, but you cannot quite make out what kind of animal it came "+
			"from.  The coverings feel soft and supple and seem to almost give "+
			"of a little warmth as if leather itself was still alive.\n",
		({"tables","table"}) : "The tables are made from some form of wood that "+
			"is hard and black and gives off a bright shine when polished.  The "+
			"table workmanship is of very good quality although simple.\n",
		"painting" : "%^RESET%^The painting is of a male "+
			"%^BOLD%^%^BLACK%^drow%^RESET%^. His eyes are ice "+
			"%^BOLD%^%^BLUE%^blue %^RESET%^and his hair is as "+
			"%^BOLD%^%^WHITE%^white %^RESET%^as new snow.  His hair is "+
			"shoulder length except for the section in the back, which would "+
			"be waist length if not braided and coiled about his neck like a "+
			"%^BOLD%^%^GREEN%^snake %^RESET%^resting.  His skin is unblemished "+
			"and as %^BOLD%^%^BLACK%^black %^RESET%^as the darkest night.  "+
			"He is smiling, but it could easily be mistaken for a sneer as "+
			"there is little warmth displayed.  The %^BOLD%^%^BLACK%^drow "+
			"%^RESET%^is wearing fine silks and jewelry holds himself with the "+
			"bearing of nobility.\n",
		"cabinet" : "About 6 feet tall and 3 feet wide the cabinets doors are made "+
			"of glass.  Inside the cabinet are crystal drinking glasses and a "+
			"few bottles of undetermined dark liquids.\n"
        ]));
	set_exits(([
		"east" : DROOMS+"cd7",
		"south" : DROOMS+"cd6",
		"northwest" : DROOMS+"cd3"
   ]));

   set_door("door",DROOMS+"cd3","northwest","obsidian key");
   set_door_description("door","This is a normal looking wooden door "+
   	"with a simple lock.");
   set_string("door","open","You open the door into a dark hallway.\n");

   set_door("trophy room door",DROOMS+"cd7","east","obsidian key");
   set_locked("trophy room door",0,"lock");
   	(DROOMS+"cd7")->set_locked("trophy room door",0,"lock");
   set_door_description("trophy room door","This is a normal looking wooden door with a "+
    		"simple lock.");
   set_string("trophy room door","open","You open the door into a dark room.\n");

   set_door("dining room door",DROOMS+"cd6","south","obsidian key");
   set_locked("dining room door",0,"lock");
   	(DROOMS+"cd6")->set_locked("dining room door",0,"lock");
   set_door_description("dining room door","This is a normal looking wooden door with a "+
    	"simple lock.");
   set_string("dining room door","open","You open the door into a dark room.\n");
}