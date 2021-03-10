#include <std.h>
#include "../area_stuff.h"
inherit OBJECT;

void create()
{
    ::create();
    set_name("chunk of strange material");
    set_id(({ "chunk", "strange material", "material", 
    "spongy substance", "substance", "heart of the storm", 
    "storm heart", "eldebaro_heart_of_the_storm_xxx", "heart"}));
    
    set_short("%^RESET%^%^ORANGE%^heart of the st%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^rm%^RESET%^");    
    set_obvious_short("chunk of strange material");
    
    set_long("%^RESET%^%^ORANGE%^This chunk of material is heavier than what "+
    "it would appear at first glance. It has a spongy quality about it, almost "+
    "squishy but not quite. You are unable to determine what exactly that it is "+
    "composed of. Parts of it are warm to the touch and other parts feel cold and "+
    "almost wet, though it does not appear to contain any water at all. In fact the inside "+
    "of it seems hollow but you are unsure if it is possible to actually open it. It also "+
    "seems quite durable, as if it would take a tremendous force to actually break it "+
    "open, it it were even possible at all.%^RESET%^");
    
    set_lore("%^RESET%^%^ORANGE%^This material is what has come to be known as "+
    "a heart of the storm. There is debate about whether or not this material powers "+
    "the storm elementals found on the island of Eldebaro or if this material is "+
    "in fact the remnants of a defeated elemental. Some suggest that it is both.\n\n"+
    "One theory that seems most plausible is that something used this material to "+
    "create the elementals and when defeated the only thing that remains of them is "+
    "this material. However, who or what could have been involved in their creation or "+
    "even the creation of this material is a mystery.%^RESET%^");
    
    set_property("lore difficulty", 35);
    
    set_weight(5);
    set_value(1000);
}

