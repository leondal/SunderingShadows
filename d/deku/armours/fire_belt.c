#include <std.h>
inherit "/d/common/obj/clothing/belt";

void create(){
	::create();
	set_name("belt of fire");
	set_id(({ "belt", "fire belt", "daliigwins belt", 
    "leather belt"}));
	set_short("%^RED%^D%^RESET%^a%^RED%^l%^YELLOW%^i%^RESET%^i%^RED%^gw%^BOLD%^%^WHITE%^i%^RESET%^%^RED%^n's B%^YELLOW%^u%^RESET%^%^RED%^rn%^RESET%^i%^RED%^ng B%^YELLOW%^e%^RESET%^%^RED%^lt%^RESET%^");
    set_obvious_short("%^BOLD%^%^RED%^A flaming leather belt%^RESET%^");
	set_long("%^RED%^This thick belt is made from a rough and "+
    "%^BOLD%^%^BLACK%^dark%^RESET%^%^RED%^ leather.  It has "+
    "been %^CYAN%^enchanted%^RESET%^%^RED%^ to glow continually "+
    "with an ever burning f%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^"+
    "e%^RESET%^%^RED%^.  Patterns are embroidered into it by "+
    "some method that is no longer apparent.  The patterns "+
    "fl%^RESET%^i%^RED%^ck%^YELLOW%^e%^RESET%^%^RED%^r and "+
    "dance continually, as if in a et%^BOLD%^%^WHITE%^e"+
    "%^RESET%^%^RED%^rnal rythme with the ever burning "+
    "f%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^e%^RESET%^%^RED%^.  "+
    "The belt buckle in the front is in the shape of a small "+
    "and %^YELLOW%^stained%^RESET%^ skull%^RED%^.  The "+
    "belt gives off only a slight bit of heat, suggesting "+
    "that something has been done to it to keep it from "+
    "severely burning the wearer.%^RESET%^");

	set_weight(1);
    set_value(700);
	set_lore("These belts were formed by Kinorda some ages ago.  "+
    "They were formed for his more powerful servants, as "+
    "rewards that they had requested.  This particular belt "+
    "was formed for Daliigwin.  The leather used in their "+
    "creation is said to be the hide of those servants who "+
    "disappointed Kinorda.  They are rumored to be very simple, "+
    "with only a slight magic to keep them continually burning "+
    "and to keep that fire from burning their "+
    "wearers.  The fire from them could easily provide an "+
    "aide for seeing in the dark.");

	set_property("lore difficulty",10);
	set_size(1);
	set_property("enchantment",3);
    set_item_bonus("bludgeoning resistance",2);
    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));
	set_item_bonus("sight bonus", 1);
}

int wear_me() {
    tell_object(ETO,"%^RED%^You %^RESET%^buckle%^RED%^ the "+
    "belt around your waist.%^RESET%^");
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+" buckles%^RED%^ the belt "+
        "around "+ETO->QP+" waist.%^RESET%^", ETO);
    }
    return 1;
}

int remove_me() {
    tell_object(ETO,"%^RED%^You %^RESET%^unbuckle%^RED%^ the "+
    "belt from around your waist.%^RESET%^");
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+" unbuckles%^RED%^ the belt "+
        "from around "+ETO->QP+" waist.%^RESET%^", ETO);
    }
    return 1;
}


