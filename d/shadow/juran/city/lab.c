#include <std.h>
#include "../juran.h"


inherit "/std/lab";

void create(){
   	object ob;
   	::create();
   	set_property("indoors",1);
   	set_property("light",-2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
   	set_short("%^BOLD%^%^BLACK%^Juran Mage Guild's Public laboratory%^RESET%^");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
   	set_long(query_short() + "
%^MAGENTA%^This is the Juran Mage guild's public Laboratory. Here the mages without laboratories of their own keep small cubbies and work areas. Even some magic dabblers keep an area here. All around you, potions bubble and mice squeak. Smells of sulfur and carbon and such waft through the air. A slight smoke lingers at the top of the high ceiling."
   	);

   	set_exits(([
           "south" : JROOMS+"mt2",
      ]));

   	set_smell("default","Sulfur, carbon, and smoke fill the air around you.");
   	set_listen("default","You hear the bubbling of alchemy and the chanting "+
   		"of test casts.");
   	set_door("door",JROOMS+"mt2","south",0);
   	set_open("door",0);
   	(JROOMS+"mt2")->set_open("door",0);

   	setOwner("none");
   	setLabId("juran");
   	ob=new("/d/magic/obj/mirror");
        ob->set_short("%^BOLD%^%^BLACK%^A %^RESET%^%^ORANGE%^f%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^e %^BLACK%^mi%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^ror%^RESET%^");
   	ob->move(TO);
}
