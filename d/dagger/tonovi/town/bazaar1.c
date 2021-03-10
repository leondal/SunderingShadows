//updated by Circe 12/19/04 with new desc
//changed to use VAULT & add jail window *Styx* 10/05

#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit VAULT;

void create(){
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Bazaar of Tonovi");
    set_property("light",2);
    set_short("Bazaar of Tonovi");
    set_long("%^CYAN%^Bazaar of Tonovi%^RESET%^\n"+
       "This is the northwestern corner of the bazaar of Tonovi, "+
       "bounded on the west by the %^BOLD%^%^BLACK%^city walls%^RESET%^."+
       "  To the north stands a %^BOLD%^stone building %^RESET%^"+
       "featuring %^BOLD%^%^BLACK%^iron bars %^RESET%^on the windows.  "+
       "The %^CYAN%^bazaar %^RESET%^opens to the south and east, "+
       "with %^ORANGE%^stands %^RESET%^and %^MAGENTA%^merchants "+
       "%^RESET%^advertising their wares.  All manner of unusual "+
       "%^ORANGE%^goods %^RESET%^seem to be sold here, and there is "+
       "a large crowd gathered around what looks to be a %^ORANGE%^"+
       "platform %^RESET%^of sorts to the southeast in the center "+
       "of the %^CYAN%^bazaar%^RESET%^.  Occasionally you see someone "+
	"pause and peer into the window to taunt the prisoners.\n");
    set_smell("default", "You smell several strange smells, "+
       "especially strong is the sweet smell of fruits.");
    set_listen("default","You can hear the merchants peddling "+
       "their wares from all around.");
    set_items( ([
      ({"jail","building"}) : "The squat stone jail looks to house "+
         "several small cells.  At times, prisoners can be seen peering "+
         "through the cell window at the bustle of the bazaar.",
      ({"window", "cell window" }) : "You can't help but notice the "
	 "%^BOLD%^%^BLACK%^grime-covered cell window%^RESET%^ with a "
	 "few spots rubbed clean enough for the prisoners to peer out or "
	 "curious passersby to peer in.",
      ({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
      ({"wares","goods","stands","merchants"}) : "Merchants in "+
         "clothing from all parts of the realms stand before their "+
         "stalls, proffering their wares.  The goods range from "+
         "exotic fruits and vegetables to perfumes, silks, and "+
         "unusual pets.",
      ({"platform","large platform","center"}) : "Directly in "+
         "the center of the bazaar to the southeast, there is "+
         "what looks to be a large platform.  It is hard to tell "+
         "from here exactly what is going on there, but it has "+
         "drawn the attention and presence of most of the people "+
         "in the bazaar."
    ]));
    set_exits(([
 	"window" : RPATH "cell",
	"north" : RPATH "jail1",
	"south" : RPATH "bazaar4",
	"east" : RPATH "bazaar2"
      ]));
   set_invis_exits(({ "window"}));
   set_pre_exit_functions(({ "window"}),({"GoThroughDoor"}));
}

void init() {
   ::init();
   add_action("peer_in", "peer");
   if(userp(TP) && !random(15))
	tell_object(TP, "You notice some movement and tapping from the %^BOLD%^"
	  "%^BLACK%^grime-covered window%^RESET%^ to the jail cell.  Perhaps "
	  "you want to take a closer look to see who is in custody today.");
}

int peer_in(string str) {
   if(!str) {
      tell_object(TP,"Peer where?");
      return 1;
   }
   if(str == "window" || str == "through window" || str == "in window" || str == "cell") {
      	tell_object(TP,"You step up to the window and peer "+
               "into the cell.\n");
      	tell_room(ETP,TPQCN+" steps up to the window and "+
               "peers into the jail cell.\n",TP);
      	tell_room("/d/dagger/tonovi/town/bazaar1","You hear a scratching "
      	   "at the jail window and catch a glimpse of movement outside.\n",TP);
	write("/d/dagger/tonovi/town/cell"->query_long());
      	TP->force_me("peer window 1");
    		return 1;
   }
   return 0;
}

int GoThroughDoor() {
   if(query_verb() == "window") {  
     write("%^ORANGE%^Why would you want to go in??? Even if you did truly want "
	"to, the window has heavy bars!");
     tell_room(ETP, TPQCN+" seems to be trying to get into the cell through the window!",TP);
     return 0;
   }
//need to allow normal GoThroughDoor for the regular door exits
   return ::GoThroughDoor();
}
