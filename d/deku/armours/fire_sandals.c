#include <std.h>
inherit "/d/common/obj/clothing/shoes";

void create()
{
    ::create();
    set_name("fire sandals");
    set_id(({ "sandals", "fire sandals", "flame sandals", "sandals of fire", "kinordas sandals" }));
    set_short("%^BOLD%^%^WHITE%^K%^YELLOW%^i%^BOLD%^%^WHITE%^n%^YELLOW%^o%^BOLD%^%^WHITE%^rd%^YELLOW%^a%^BOLD%^%^WHITE%^'s "+
    "%^RED%^Fire Sandals%^RESET%^");    
    set_obvious_short("%^RESET%^%^RED%^A pair of %^ORANGE%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^%^ORANGE%^y%^RED%^ sandals%^RESET%^");
    set_long("%^RED%^These small sandals are made entirely "+
    "from an %^ORANGE%^orange%^RESET%^%^RED%^ fl%^YELLOW%^"+
    "a%^RESET%^%^RED%^m%^YELLOW%^e%^RESET%^%^RED%^.  A thong "+
    "comes from the front of the sandals and extends back to "+
    "buckle together with two other straps that each travel to "+
    "the sides.  The soles of the sandals are made from a "+
    "much darker %^ORANGE%^orange%^RESET%^%^RED%^ fl%^YELLOW%^"+
    "a%^RESET%^%^RED%^m%^YELLOW%^e%^RESET%^%^RED%^ that has "+
    "been hardened to a solid substance.  A light "+
    "%^BLUE%^blue%^RESET%^%^RED%^ barrier surrounds the "+
    "sandals, protecting the wearer from the f%^YELLOW%^i%^RESET%^"+
    "%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^ that they "+
    "are made of.%^RESET%^");
    set_weight(2);
    set_value(800);
    set_lore("These sandals were made by the priest Kinorda "+
    "some ages ago.  Unlike most of his items, they are quite "+
    "simple, and have never held much magic, other than the "+
    "magic which keeps their flame ever burning, and the "+
    "barrier which somewhat protects the wearer from their fire.");
    set_property("lore difficulty",10);
	
    set_size(2);
    set_property("enchantment",3);
    set_item_bonus("fire resistance", 10);
    set_wear("%^RED%^You buckle the sandals in place "+
    "and are left unscathed by the f%^YELLOW%^i%^RESET%^%^RED%^"+
    "r%^YELLOW%^e%^RESET%^%^RED%^.%^RESET%^");
    set_remove("%^RED%^You unbuckle the sandals and remove "+
    "them from your feet.%^RESET%^");
}


