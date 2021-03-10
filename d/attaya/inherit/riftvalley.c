//Octothorpe (3/22/10)
//Attaya Volcanic Rift Valley Inherit

#include <std.h>
#include "../defs.h"
inherit CROOM;

void create()
{
   ::create();
   set_climate("desert");
   set_terrain(ROCKY);
   set_travel(RUBBLE);
   set_name("Volcanic rift valley");
   set_short("%^BOLD%^%^BLACK%^V%^RED%^o%^BOLD%^%^BLACK%^lc%^RED%^"+
      "a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^c r%^RESET%^i"+
	  "%^BOLD%^%^BLACK%^ft v%^RED%^a%^BOLD%^%^BLACK%^ll"+
	  "%^RED%^ey%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^V%^RED%^o%^BOLD%^%^BLACK%^lc%^RED%^"+
      "a%^BOLD%^%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^c r%^RESET%^i"+
	  "%^BOLD%^%^BLACK%^ft v%^RED%^a%^BOLD%^%^BLACK%^ll"+
	  "%^RED%^ey%^RESET%^\n "+
	  "%^BOLD%^%^BLACK%^A spectacular wasteland of basalt is nearly "+
	  "all encompassing for as far as the eye can see. The sky is "+
	  "obscured by thick clouds of %^BOLD%^%^WHITE%^sulfur dioxide"+
	  "%^BOLD%^%^BLACK%^, %^BOLD%^%^BLACK%^which constantly spews "+
	  "forth from numerous fissures in the ground. Fountains of "+
	  "molten rock feed into %^RED%^lava %^BOLD%^%^BLACK%^flows "+
	  "which spread across the floor of the valley. The glow of "+
	  "the %^RED%^lava %^BOLD%^%^BLACK%^is reflected in the %^WHITE%^"+
	  "clouds %^BOLD%^%^BLACK%^overhead, perpetually illuminating "+
	  "the valley in an eerie, hellish light.%^RESET%^\n");
   set_property("indoors",0);
   set_property("light",3);
   set_property("no peer",1);
   set_peer_message("%^BOLD%^%^WHITE%^The clouds of sulfur dioxide "+
      "are too thick to really get a good look.%^RESET%^");
   set_smell("default", "%^BOLD%^%^BLACK%^The thick %^WHITE%^smoke "+
      "%^BOLD%^%^BLACK%^assaults your nose and stings your eyes.%^RESET%^");
   set_listen("default", "%^RED%^You hear the rumbling of the ground beneath you.%^RESET%^");
   set_items(([
      ({"lava","molten rock"}):"%^BOLD%^%^RED%^Channels of lava run over parts of the "+
	     "%^BOLD%^%^BLACK%^basalt %^RED%^below.%^RESET%^",
	  ({"volcanic rift valley","rift valley","valley","basalt"}):"%^BOLD%^"+
	     "%^BLACK%^The valley extends north and south for as far as "+
		 "you can see, eventually getting swallowed up by the thick "+
		 "clouds of %^WHITE%^sulfur dioxide%^BOLD%^%^BLACK%^. Veins "+
		 "of %^RED%^lava %^BOLD%^%^BLACK%^stream over the surface of "+
		 "the valley in spots, lending the landscape a hellish "+
		 "visage.%^RESET%^",
      ({"clouds","sulfur dioxide"}):"%^BOLD%^The thick clouds block "+
	     "out the sky and glow an angry %^RED%^red %^WHITE%^from the "+
		 "%^RED%^lava%^WHITE%^.%^RESET%^",
   ]));		 
}