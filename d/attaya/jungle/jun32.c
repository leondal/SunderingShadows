//Octothorpe (3/27/10)
//Attaya Jungle Path 32
//Original by Thundercracker

#include <std.h>

inherit ROOM;
#include "../defs.h"

void create(){
   ::create();
   set_climate("tropical");
   set_terrain(ROCKY);
   set_travel(RUBBLE);
   set_name("Ridge above a volcanic rift valley");
   set_short("%^BOLD%^%^BLACK%^A ridge above a v%^RED%^o%^BOLD%^"+
      "%^BLACK%^lc%^RED%^a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^"+
	  "%^BLACK%^c r%^RESET%^i%^BOLD%^%^BLACK%^ft v%^RED%^a%^BOLD%^"+
	  "%^BLACK%^ll%^RED%^ey%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A ridge above a v%^RED%^o%^BOLD%^"+
      "%^BLACK%^lc%^RED%^a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^"+
	  "%^BLACK%^c r%^RESET%^i%^BOLD%^%^BLACK%^ft v%^RED%^a%^BOLD%^"+
	  "%^BLACK%^ll%^RED%^ey%^RESET%^\n "+
      "%^BOLD%^%^BLACK%^The jungle %^RESET%^%^GREEN%^f%^ORANGE%^o"+
      "%^GREEN%^l%^ORANGE%^ia%^BOLD%^%^GREEN%^g%^YELLOW%^e %^BOLD%^"+
	  "%^BLACK%^ends suddenly as a large valley opens up to the east.  "+
	  "This ridge is just above the former high watermark of a %^BOLD%^"+
	  "%^RED%^lava %^BOLD%^%^BLACK%^flow, and slopes gently down to "+
	  "the valley below.  From this vantage point, a river of %^BOLD%^"+
	  "%^RED%^lava %^BOLD%^%^BLACK%^is just barely visible through the "+
      "numerous plumes of %^BOLD%^%^WHITE%^sulfur dioxide %^BOLD%^"+
	  "%^BLACK%^escaping through fissure vents in the basalt.\n");
   set_property("indoors",0);
   set_property("light",2);
   set_property("no peer",1);
   set_peer_message("%^BOLD%^%^WHITE%^The clouds of sulfur dioxide "+
      "are too thick to really get a good look.%^RESET%^");
   set_exits(([
      "south":JGL"jun31a",
      "down":JGL"jun33"
   ]));
   set_smell("default", "%^BOLD%^%^BLACK%^The thick %^WHITE%^smoke "+
      "%^BOLD%^%^BLACK%^assaults your nose and stings your eyes");
   set_listen("default", "You hear the rumbling of the ground beneath you.");
   set_items(([
      ({"jungle","bush","foliage"}):"%^BOLD%^%^GREEN%^The jungle is "+
	     "little more than a nearly impenetrable wall of trees and "+
		 "foliage.  Luckily the narrow path towards the south offers "+
		 "relatively easy passage through the bush.%^RESET%^",
      ({"trees","canopy"}):"%^BOLD%^%^GREEN%^Numerous types of trees "+
	     "can be found to the south in the jungle, ranging from fruit-"+
		 "bearing fig trees, to giant palm trees.%^RESET%^",
      "ridge":"%^BOLD%^%^BLACK%^This ridge of basalt looks out over the "+
	     "volcanic rift valley below.  It slopes gently down into the "+
		 "valley below, offering easy access.%^RESET%^",
      "lava":"%^BOLD%^%^RED%^Channels of lava run over parts of the "+
	     "%^BOLD%^%^BLACK%^basalt %^RED%^below.%^RESET%^",
      ({"river of lava","river"}):"%^BOLD%^%^RED%^Some distance to "+
	     "the east, a vast river of lava is just barely visible "+
		 "through the thick clouds of %^WHITE%^sulfur dioxide%^RESET%^.",
	  ({"volcanic rift valley","rift valley","valley","basalt"}):"%^BOLD%^"+
	     "%^BLACK%^The valley extends north and south for as far as "+
		 "you can see, eventually getting swallowed up by the thick "+
		 "clouds of %^WHITE%^sulfur dioxide%^BOLD%^%^BLACK%^.  Veins "+
		 "of %^RED%^lava %^BOLD%^%^BLACK%^stream over the surface of "+
		 "the valley in spots, lending the landscape a hellish visage.%^RESET%^",
   ]));		 
}