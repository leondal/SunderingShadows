#include <std.h>
#include "../inherits/area_stuff.h"
inherit VAULT;

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_name("mausoleum of the damned");
    set_short("%^BOLD%^%^BLACK%^Mausoleum of the Damned%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand before an ancient %^BOLD%^%^WHITE%^"+
    "stone%^BOLD%^%^BLACK%^ mausoleum. The outside of it has been overtaken "+
    "by thick %^RESET%^%^GREEN%^vines%^BOLD%^%^BLACK%^, which snake their "+
    "way up it indiscriminately. Visible %^BOLD%^%^WHITE%^cracks%^BOLD%^%^BLACK%^ "+
    "on the outside of the structure allow you to catch glimpses through the stone "+
    "into the darker interior. It is quite apparent that in recent years whatever "+
    "once took care of the building has ceased. Double doors with a forboding "+
    "%^BOLD%^%^RED%^skull%^BOLD%^%^BLACK%^ chiseled into the center of them "+
    "provide the one opening into the ancient mausoleum.%^RESET%^");
    
    set_listen("default","Eerie moans and groans echo from within the mausoleum.");
    set_smell("default","The aroma of death and decay hangs heavily here.");
    
    set_exits(([
       "south" : OUT,
       "enter" : MROOMS"enter",
    ] ));
  
    set_door("double doors", MROOMS"enter" ,"enter", "","lock");
    set_door_description("double doors","%^BOLD%^%^BLACK%^These thick double "+
    "doors are made from the same %^BOLD%^%^WHITE%^white%^BOLD%^%^BLACK%^ stone "+
    "that composes the rest of the mausoluem. A forboding %^BOLD%^%^RED%^skull"+
    "%^BOLD%^%^BLACK%^ with %^BOLD%^%^RED%^blazing red%^BOLD%^%^BLACK%^ eyes "+
    "sockets has been chiseled into the center of them.%^RESET%^");
    
    set_items(([
       ({"structure", "mausoluem", "cracks"}) : "%^BOLD%^%^WHITE%^This ancient "+
       "structure is currently in a state of decay. There are visible cracks litering "+
       "the outter walls of it, allowing glimpses into the darker interior. Apparently "+
       "whatever may have once cared for this place has ceased. This is understandable "+
       "as recent reports confirm that it has been cursed by something.... and lately "+
       "the locals have taken to referring to it as the mausoleum of the damned.%^RESET%^",
       ({"vines", "vine"}) : "%^RESET%^%^GREEN%^These vines have almost entirely overtaken "+
       "the outside of the mausoleum. They snake their way up it indiscriminately, providing "+
       "a sort of morbid decorum that is a testament to the lack of care that has been given "+
       "to this structure in recent years.%^RESET%^",
    ] ));
    
    
}
