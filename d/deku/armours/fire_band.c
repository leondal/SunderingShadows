#include <std.h>
inherit ARMOUR;

void create()
{
	::create();
	"/d/deku/armours/ring_p_base.c"->create_ring(TO);
    set_name("fire band");
    set_id(({"ring","band","fire band","ring of protection",
    "fire band of protection"}));
    set_short("%^BOLD%^%^WHITE%^K%^YELLOW%^i%^BOLD%^%^WHITE%^n%^YELLOW%^o%^BOLD%^%^WHITE%^rd%^YELLOW%^a%^BOLD%^%^WHITE%^'s"+
    "%^RED%^ f%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^ "+
    "band of pr%^YELLOW%^o%^RESET%^%^RED%^t%^RESET%^e%^RED%^ct"+
    "%^BOLD%^%^WHITE%^i%^RESET%^o%^RED%^n%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^A band of %^ORANGE%^f%^BOLD%^%^RED%^i%^YELLOW%^r%^RESET%^%^RED%^e%^RESET%^");
    set_long("%^RED%^This ring is made from a circle of %^BOLD%^"+
    "%^BLACK%^dark %^RESET%^%^ORANGE%^orange%^RESET%^%^RED%^ f"+
    "%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^.  "+
    "A light %^BLUE%^blue%^RESET%^%^RED%^ barr%^RESET%^i%^YELLOW%^"+
    "e%^RESET%^%^RED%^r encircles the outside and inside of the "+
    "band, as a means of preventing the fire from harming the wearer.  "+
    "A thinner band, made from a lighter and %^BLUE%^blue%^RESET%^"+
    "%^RED%^ colored fl%^YELLOW%^a%^RESET%^%^RED%^m%^YELLOW%^e"+
    "%^RESET%^%^RED%^ circles the center of the b%^RESET%^a%^RED%^"+
    "nd.  The fl%^YELLOW%^a%^RESET%^%^RED%^m%^YELLOW%^e%^RESET%^"+
    "%^RED%^ just beneath the barr%^RESET%^i%^YELLOW%^e%^RESET%^"+
    "r%^RED%^ burns brightly, fl%^RESET%^i%^RED%^ck%^YELLOW%^e"+
    "%^RESET%^%^RED%^r%^RESET%^i%^RED%^ng and fl%^YELLOW%^a"+
    "%^RESET%^%^RED%^sh%^RESET%^i%^RED%^ng "+
    "continually, a testimony to its chaotic and out of "+
    "control existance.%^RESET%^");   
    set_lore("This ring of protection was formed personally "+
    "for the old priest Kinorda.  It is rumored that he took "+
    "the magic found in its sister bands of protection and "+
    "made something that would reflect his own attachment "+
    "to fire.");
    set_property("enchantment",3);
    set_item_bonus("fire resistance",8);
    set_property("lore difficulty",8);
    set_remove("%^RED%^You remove the band of fire "+
    "and it %^BOLD%^%^BLACK%^darkens%^RESET%^%^RED%^ "+
    "slightly.%^RESET%^"); 
}

int do_wear() {
    object *stuff;
    int i,j, flag;

    stuff = TP->all_armour();
    j = sizeof(stuff);
    for(i=0;i<j;i++) {
        if(!objectp(stuff[i])) continue;
        if((string)stuff[i]->query_type() == "ring") {
//         if(stuff[i]->query_property("enchantment")){
            if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
                flag = 1;
                break;
            }
//         }
        }
    }
    if(flag) {
        write("%^BOLD%^The magic of the ring already worn prevents you from wearing this one!");
        return 0;
    }
    tell_object(ETO,"%^RED%^You wear the band and it flash%^RESET%^"+
    "e%^RED%^s brilliantly in an expl%^YELLOW%^o%^RESET%^%^RED%^si"+
    "%^YELLOW%^o%^RESET%^%^RED%^n of fl%^YELLOW%^a%^RESET%^%^RED%^"+
    "m%^YELLOW%^e%^RESET%^%^RED%^s.%^RESET%^");
    tell_room(EETO,ETOQCN+"%^RED%^ wears the band and it flash%^RESET%^"+
    "e%^RED%^s brilliantly in an expl%^YELLOW%^o%^RESET%^%^RED%^si"+
    "%^YELLOW%^o%^RESET%^%^RED%^n of fl%^YELLOW%^a%^RESET%^%^RED%^"+
    "m%^YELLOW%^e%^RESET%^%^RED%^s.%^RESET%^",ETO);
    return 1;
}
