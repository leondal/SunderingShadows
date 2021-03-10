#include <std.h>
inherit "/d/common/obj/armour/coif_leather";

void create()
{
    ::create();
    set_name("deep purple leather coif");
    set_id(({ "coif", "leather coif", "leather helm", 
    "deep purple coif", "deep purple helm", "purple coif", "purple helm", 
    "coif of the purple worm", "worm coif", "purple worm coif"}));
	
    set_obvious_short("%^RESET%^%^MAGENTA%^A deep purple leather coif%^RESET%^");

    set_short("%^RESET%^%^MAGENTA%^C%^BOLD%^oi%^RESET%^%^MAGENTA%^f "+
    "%^BOLD%^o%^RESET%^%^MAGENTA%^f th%^BOLD%^e%^RESET%^%^MAGENTA%^ "+
    "p%^BOLD%^u%^RESET%^%^MAGENTA%^rpl%^BOLD%^e %^RESET%^%^MAGENTA%^w"+
    "%^BOLD%^o%^RESET%^%^MAGENTA%^rm%^RESET%^");
	
    set_long("%^RESET%^%^MAGENTA%^This coif is made from several layers of "+
    "a deep purple material. It looks as if it was cured simply by being left "+
    "to sit for a long period of time. It has become dried and cracked open in "+
    "several spots but none of the cracks appear deep enough to go all the way "+
    "through the many layers. It has been stitched together with a %^BOLD%^%^BLACK%^"+
    "charcoal%^RESET%^%^MAGENTA%^ colored thread that is knotted up almost "+
    "continuosly, which either hints at the quality of the thread or the quality "+
    "of the craftsman. In the front it comes down to just above the eyes of the "+
    "wearer. The back of the coif is considerably longer, coming down to almost the "+
    "middle of the back.%^RESET%^");

    set_property("lore difficulty", 14);

    set_lore("%^RESET%^%^MAGENTA%^It is said that this coif was one of the items "+
    "worn by the crazed ranger of Silvanus, who was known only as Howne. It was rumored "+
    "to be enchanted to protect the wearer from acid originally, since Howne had "+
    "experienced the unpleasant sensation of being inside the stomach of a purple "+
    "worm. However, some say that eventually Howne grew disturbed enough to seek "+
    "out another to enchant it to protect against mental attacks, since he began to "+
    "believe the worms he was obsessed with were attempting to read his "+
    "thoughts.%^RESET%^");
         	
    set_value(2500);
    set_size(2);
    set_property("enchantment",2);
    
    set_item_bonus("mental resistance", 4);
    set_item_bonus("acid resistance", 4);
    
    set_wear("%^BOLD%^%^MAGENTA%^You feel some protection seep out into "+
    "you from the coif.%^RESET%^");
    
    set_remove("%^BOLD%^%^MAGENTA%^You feel the protection afforded to "+
    "you by the coif slip off with it.%^RESET%^");
}


