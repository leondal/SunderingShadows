#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit CVAULT;

void populate_area()
{
    if(base_name(TO) != MIZCAMP)
    {
        switch(random(2))
        {
            case 0:
                set_monsters( ({MMON+"mizat_guard"}), ({2 + random(3)}) );
                set_repop(55);
                break;
            case 1:
                set_monsters(({}));
                break;
        }
    }
}

void create() 
{
    populate_area();    
    ::create();
    set_name("A well-lit cavern");
    set_short("%^BOLD%^%^WHITE%^A well-lit cavern%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This cavern has been carefully hollowed out from "+
    "enormous %^BOLD%^%^BLACK%^grey%^BOLD%^%^WHITE%^ stone. It looks relatively "+
    "new as there are still some edges left from where the stone has been "+
    "hollowed out. The %^BOLD%^%^BLACK%^dust%^BOLD%^%^WHITE%^ and "+
    "%^BOLD%^%^BLACK%^rock%^BOLD%^%^WHITE%^ debris have been removed from this "+
    "portion of the cavern, thankfully. "+
    "It is almost perfectly squared, though the walls, "+
    "floor, and ceiling are all somewhat bumpy and imperfect, suggesting that maybe "+
    "the square shape was more a matter of convenience than an effort to achieve "+
    "perfection. Numerous "+
    "%^BOLD%^%^CYAN%^orbs%^BOLD%^%^WHITE%^ float effortlessly near the ceiling and give off "+
    "enough %^BOLD%^%^YELLOW%^light%^BOLD%^%^WHITE%^ to make this cavern easy to "+
    "navigate.%^RESET%^");

    set_smell("default","\nAn odor of unwashed filth mixed with dirt hangs heavily here.");

    set_listen("default","All types of movement echo constantly throughout the cavern and a loud hum bounces off the walls.");			
	
    set_items(([
    
       ({"cavern", "walls", "wall", "ceiling", "grey stone", "floor"}) : "%^BOLD%^%^BLACK%^"+
       "This cavern has been hollowed out from enormous grey stone. The walls, floor, and ceiling "+
       "are almost perfectly squared, but they are each quite bumpy and there are some "+
       "sharp edges left on the stone.%^RESET%^",
      
       ({"orbs", "light orbs", "light"}) : "%^YELLOW%^"+
       "Numerous orbs float effortlessly near the ceiling "+
       "here. They give off a constant soft light, making the cavern easy to see in and "+
       "navigate.%^RESET%^",
       
    ]));
      
    set_property("light",2);
    set_property("indoors",1);

    set_terrain(BUILT_CAVE);
    set_travel(SLICK_FLOOR);
	
    set_search("default", "%^BOLD%^%^WHITE%^Nothing really catches your attention here.%^RESET%^");
}
