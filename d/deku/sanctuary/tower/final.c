#include <std.h>
#include "../dragon.h";

inherit BTOWER;

void create() {
   ::create();
   set_long(
      "%^RESET%^This massive chamber his lit by light orbs which"+
      " are placed along the walls in perfect intervals. Large"+
      " %^BOLD%^%^WHITE%^pillars %^RESET%^are holding the ceiling of the tower up and the"+
      " marble floors glow in a sparkling light. A long carpet"+
      " converges upon a throne like chair at the end of the"+
      " room, where a large %^BOLD%^%^RED%^tapestry %^RESET%^of hangs behind it."  
   );
   set_items( ([
      "pillars" : "These are large marble pillars which support the ceiling of the tower.",
      "throne" : "This massive throne is lined with red velvet, and looks extremely comfortable.",
      "carpet" : "This plush red carpet starts out wide near the entrance and narrows to a focal point at the throne.",
      "tapestry" : "This is a beautiful tapestry showing the portrait of a woman in long flowing robes with golden blonde hair.",
]) );
   set_exits( ([
      "south" : TOWER+"top",
      "portal" : DEKU
   ]) );
   set_pre_exit_functions(({"portal"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(present("mage")) {
      write("The mage guards over the portal.");
      return 0;
   }
   return 1;
}


void reset() 
{
    ::reset();
    if(!objectp(TO)) return;
    if(!present("auica")) 
    {
        new(MON+"auica")->move(TO);
    }
    if(!present("andreas")) 
    {
        new(MON+"andreas")->move(TO);
    }
    if(!present("lecia")) 
    {
        new(MON+"lecia")->move(TO);
    }
}
