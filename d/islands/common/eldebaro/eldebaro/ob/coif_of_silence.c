#include <std.h>
inherit "/d/common/obj/armour/coif_leather";

void create()
{
    ::create();
    set_name("coif of silence");
    set_id(({ "coif", "leather coif", "coif of silence",
    "silence"}));
	
    set_obvious_short("%^RESET%^%^ORANGE%^dark leather coif%^RESET%^");

    set_short("%^RESET%^%^ORANGE%^C%^BOLD%^oi%^RESET%^%^ORANGE%^f %^BOLD%^o"+
    "%^RESET%^%^ORANGE%^f s%^BOLD%^i%^RESET%^%^ORANGE%^l%^BOLD%^e%^RESET%^%^ORANGE%^"+
    "nc%^BOLD%^e%^RESET%^");
	
    set_long("%^RESET%^%^ORANGE%^The long flowing coif is made from a thick leather "+
    "that has been tanned to be very %^BOLD%^%^BLACK%^dark%^RESET%^%^ORANGE%^. The thread "+
    "holding it together seems to almost %^BOLD%^%^CYAN%^s%^BOLD%^%^WHITE%^p%^BOLD%^%^YELLOW%^a"+
    "%^BOLD%^%^MAGENTA%^r%^BOLD%^%^CYAN%^k%^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^e%^RESET%^%^ORANGE%^ "+
    "for a brief moment as you glance at the coif, before quickly dimming to the point where you can "+
    "no longer distinguish it from the leather. Embroidered onto the back of it are a series of "+
    "images which seem to depict a human moving through %^BOLD%^%^BLACK%^shadows%^RESET%^%^ORANGE%^. "+
    "In one image he steps into the shadows, in the next he is gone, and in the final one he is "+
    "walking way with a large pouch. You are unsure what the images mean but they and the "+
    "thread are the only truly remarkable qualities of this coif.%^RESET%^");

    set_property("lore difficulty", 25);

    set_lore("%^RESET%^%^ORANGE%^Rumored to be another item bestowed upon the servants of the "+
    "mysterious creature known as the 'collector' these coifs are said to empower the wearer's "+
    "ability to blend in with the shadows and to even impart knowledge that allows 'collecting' "+
    "items from others to be easier. They were thought of as nothing more than a rumor, much like "+
    "the reported collector, but the fact that they are starting to show up suggests that maybe this "+
    "is one rumor that has some truth to it. The creator of them has been long since forgotten or maybe "+
    "he was never known in the first place.%^RESET%^");
         	
    set_value(5500);
    set_size(-1);
    set_property("enchantment",5);
    
    set_item_bonus("stealth", 4);
    set_item_bonus("thievery", 4);
    
    set_wear("%^RESET%^%^ORANGE%^You feel something encompass you imparting knowledge!%^RESET%^");
    
    set_remove("%^RESET%^%^ORANGE%^You feel the imparted knowledge leave you.%^RESET%^");
}


