#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>


inherit VAULT;

void populate_area()
{
    //set_monsters( ({MMON+"arcane_ooze", MMON+"summoning_ooze"}), ({1, 1 + random(2) }) );
    //set_repop(100);
    
}

void create() 
{
    //populate_area();    
    ::create();
    set_name("A well-lit cavern");
    set_short("%^BOLD%^%^WHITE%^A well-lit cavern%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This cavern has been carefully hollowed out from "+
    "enormous %^BOLD%^%^BLACK%^grey%^BOLD%^%^WHITE%^ stone. It looks relatively "+
    "new as there is still lots of %^BOLD%^%^BLACK%^dust%^BOLD%^%^WHITE%^ and "+
    "%^BOLD%^%^BLACK%^rock%^BOLD%^%^WHITE%^ debris scattered about the area. "+
    "However, it is also just as possible that whoever or whatever hollowed it out "+
    "did not care to leave the mess. It is almost perfectly squared, though the walls, "+
    "floor, and ceiling are all somewhat bumpy and imperfect, suggesting that maybe "+
    "the square shape was more a matter of convenience than an effort to achieve "+
    "perfection. Near the ceiling and almost touching the top of the walls, are "+
    "%^BOLD%^%^CYAN%^orbs%^BOLD%^%^WHITE%^ which float effortlessly and give off "+
    "enough %^BOLD%^%^YELLOW%^light%^BOLD%^%^WHITE%^ to make this cavern easy to "+
    "navigate.%^RESET%^");

    set_smell("default","\nAn odor of unwashed filth mixed with dirt hangs heavily here.");

    set_listen("default","All types of movement echo constantly throughout the cavern and a loud hum bounces off the walls.");			
	
    set_items(([
    
       ({"cavern", "walls", "wall", "ceiling", "grey stone", "floor"}) : "%^BOLD%^%^BLACK%^"+
       "This cavern has been hollowed out from enormous grey stone. The walls, floor, and ceiling "+
       "are almost perfectly squared, but they are each quite bumpy still, as if the "+
       "squared shape was more a matter of convenience than any attempt at perfection.%^RESET%^",
       
       ({"dust", "rocks", "debris", "rock debris"}) : "%^BOLD%^%^BLACK%^There are piles of "+
       "rocks and dust scattered all around the cavern carelessly, as if whoever "+
       "created this place either did so recently or hasn't yet taken the time to clean it up.%^RESET%^",
       
       ({"orbs", "light orbs", "light"}) : "%^YELLOW%^"+
       "Orbs float effortlessly near the ceiling and almost touch the top of the walls "+
       "here. They give off a constant soft light, making the cavern easy to see in and "+
       "navigate.%^RESET%^",
       
    ]));
      
    set_property("light",2);
    set_property("indoors",1);

    set_terrain(BUILT_CAVE);
    set_travel(SLICK_FLOOR);
	
    set_search("default", "%^BOLD%^%^WHITE%^Nothing really catches your attention here.%^RESET%^");
}
