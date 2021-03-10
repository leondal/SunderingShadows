#include <std.h>
inherit "/d/common/obj/clothing/cloak.c";

void create(){
	::create();
	set_name("cloak of fire");
	set_id(({ "cloak", "fire cloak", "cloak of fire",
    "kinordas cloak","phoenix cloak"}));
	set_short("%^BOLD%^%^WHITE%^K%^YELLOW%^i%^BOLD%^%^WHITE%^n%^YELLOW%^o%^BOLD%^%^WHITE%^rd%^YELLOW%^a%^BOLD%^%^WHITE%^'s"+
    "%^RED%^ Cloak of The Ph%^YELLOW%^o%^RESET%^%^RED%^en%^YELLOW%^"+
    "i%^RESET%^%^RED%^x%^RESET%^");
    set_obvious_short("%^RESET%^%^RED%^A cloak of %^BOLD%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^e%^RESET%^");
	set_long("%^RED%^This garment is made entirely from a "+
    "dark %^BLUE%^blue%^RESET%^%^RED%^ f%^YELLOW%^i%^RESET%^%^RED%^r"+
    "%^YELLOW%^e%^RESET%^%^RED%^.  It wraps tightly around the "+
    "neck of the wearer, yet its destructive power is somehow "+
    "kept at bay and it does not harm the wearer.  A "+
    "%^CYAN%^sp%^BOLD%^%^WHITE%^a%^CYAN%^rkl%^BOLD%^%^WHITE%^"+
    "i%^CYAN%^ng%^RESET%^%^RED%^ thread has been sewn into the "+
    "edges of the cloak.  From the thread extends a light "+
    "%^BLUE%^blue%^RESET%^%^RED%^ b%^BLUE%^a%^RESET%^%^RED%^rr"+
    "%^BLUE%^i%^RESET%^%^RED%^er that rad%^RESET%^i%^RED%^at%^RESET%^"+
    "e%^RED%^s a light glow and surrounds the entire garment.  "+
    "A very small Ph%^YELLOW%^o%^RESET%^%^RED%^en%^YELLOW%^"+
    "i%^RESET%^%^RED%^x has been embroidered into the front of "+
    "the garment, its wings stretched wide and its mouth open "+
    "in a silent %^RESET%^scr%^RED%^e%^RESET%^am.");

    set_weight(5);
    set_value(1000);
	set_lore("This garment was created by the old priest "+
    "Kinorda some many years ago.  It was rumored to hold "+
    "many magical properties at one time, but like all "+
    "things created by Kinorda, most of its magic has faded "+
    "over the course of time.  These garments have not "+
    "been seen in decades, they vanished to wherever Kinorda "+
    "himself disappeared to.");
	set_property("lore difficulty",10);
	set_size(2);
	set_property("enchantment",3);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
	set_item_bonus("fire resistance", 12);
}

int wear_func() {
    if(ETO->query_highest_level() < 15) {
        tell_object(ETO,"%^RED%^A swelling begins in your mind "+
        "as you try to don the cloak and the pain thwarts "+
        "your attempt to wear it.%^RESET%^");
        return 0;
    }
    tell_object(ETO,"%^RED%^You don the cloak and feel an "+
    "energy flow out from it, leaving you %^CYAN%^refreshed"+
    "%^RESET%^%^RED%^ and pr%^YELLOW%^o%^RESET%^%^RED%^"+
    "tected!%^RESET%^");
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+"%^RED%^ dons the cloak and "+
        "looks %^CYAN%^refreshed%^RESET%^%^RED%^!%^RESET%^",ETO);
    }
    ETO->add_hp(5 + random(3));
    return 1;
}

int remove_func() {
    tell_object(ETO,"%^RED%^You remove the cloak and "+
    "feel slightly less pr%^YELLOW%^o%^RESET%^%^RED%^tected.%^RESET%^");
    return 1;
}
