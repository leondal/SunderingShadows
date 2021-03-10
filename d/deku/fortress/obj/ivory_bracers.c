#include <std.h>
inherit "/d/common/obj/armour/bracers";
int x;
string choose_protection();

void create()
{
    ::create();
    set_name("Ivory Bracers");
    set_id(({ "bracers", "bracer", "ivory bracer", "ivory bracers",}));
    set_short("%^BOLD%^%^WHITE%^I%^RESET%^%^WHITE%^v%^BOLD%^"+
    "%^WHITE%^o%^RESET%^%^WHITE%^r%^BOLD%^%^WHITE%^y %^YELLOW%^"+
    "bracers of %^CYAN%^war%^RESET%^d%^CYAN%^ing%^RESET%^");
    set_obvious_short("Ivory bracers");

    set_long("%^BOLD%^%^WHITE%^These bracers are made from a "+
    "smooth and dull piece of ivory.  A beautiful forest "+
    "has been carefully etched into the upperside of them.  The "+
    "trees in the forest have been been altered to a "+
    "%^RESET%^%^GREEN%^dark green%^BOLD%^%^WHITE%^ hue, "+
    "contrasting with the otherwise dull white.  Expertly "+
    "carved into the center of the etched forest is a "+
    "%^YELLOW%^unicorn%^RESET%^%^BOLD%^%^WHITE%^, its sleek "+
    "and powerful body a brilliant %^RESET%^%^WHITE%^white"+
    "%^BOLD%^%^WHITE%^.  Its head is looking forward, as if "+
    "it's staring directly at you.  An almost tangible "+
    "aura of magic surround these bracers.%^RESET%^");
    
    set_lore("%^BOLD%^%^GREEN%^These bracers were gifts from Mielikki"
			 " to her rangers on Deku Island. The last pair were seen"
			 " on one of her N%^RESET%^%^GREEN%^ee%^BOLD%^%^GREEN%^dles"
			 " who was captured by a cult of the Shadowlord.%^RESET%^");
    set_weight(10);
    set_value(1000);
    set_size(2);
    set_property("enchantment",3);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
	set_item_bonus(choose_protection(), 10);
}

string choose_protection()
{
    int x;
    string myprot;
    string *possible_protections;
    possible_protections = ({"fire resistance", "magic resistance", "cold resistance", "sonic resistance ", "acid resistance", "negative energy resistance", "positive energy resistance", "mental resistance"});   
    x = sizeof(possible_protections);
    myprot = possible_protections[random(x)];
    return myprot;
}

int wear_func(){
   ::check();
    tell_room(EETO,ETO->QCN+"%^BOLD%^%^WHITE%^'s "+
    "fingers trace the outline of the unicorn on "+ETO->QP+
    " bracers.%^RESET%^",ETO);
	
    tell_object(ETO,"%^BOLD%^%^WHITE%^You allow your fingers to "+
    "trace the outline of the unicorn and feel a magical "+
    "protection flow out over you.%^RESET%^");

    return 1;
}
int remove_func(){
    tell_room(EETO,ETO->QCN+"%^BOLD%^%^WHITE%^ sighs "+
    "softly.%^RESET%^",ETO);
    tell_object(ETO,"%^BOLD%^%^WHITE%^With a soft sigh you "+
    "remove the bracers and feel the protection leave you."+
    "%^RESET%^");
    return 1;
}

int is_metal() { return 0; };
