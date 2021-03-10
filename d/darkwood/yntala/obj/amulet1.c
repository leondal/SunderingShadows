#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("%^BOLD%^%^GREEN%^Amulet of protection%^RESET%^");
        set_id(({"amulet"}));
        set_short("%^RESET%^%^GREEN%^E%^BOLD%^m%^RESET%^%^GREEN%^er%^BOLD%^a%^RESET%^%^GREEN%^ld %^BOLD%^amulet of protection%^RESET%^");
        set_obvious_short("%^BOLD%^%^GREEN%^A large %^RESET%^%^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^a%^RESET%^%^GREEN%^ld %^BOLD%^amulet%^RESET%^");
        set_property("repairtype",({ "jewel" }));
        set_long("%^BOLD%^%^GREEN%^This is a fairly large square cut %^RESET%^%^GREEN%^e%^BOLD%^m"
"%^RESET%^%^GREEN%^er%^BOLD%^a%^RESET%^%^GREEN%^ld %^BOLD%^that sets within a %^YELLOW%^golden"
" setting.  %^GREEN%^At about four inches long and two across, the emerald is flawless in appearance and a true"
" marvel to look at.  The setting itself is suspended from a finely crafted %^YELLOW%^gold chain %^GREEN%^with"
" tiny engravings of %^RESET%^%^GREEN%^four-leaf clovers %^BOLD%^on each of the dainty %^YELLOW%^links."
"  %^GREEN%^A lobster clasp holds both the amulet and chain securely around the wearers neck.%^RESET%^\n");
        set_lore("%^GREEN%^Stories say that this amulet is something made by the leprechauns, for the leprechauns.  As an object of warding and protection, this amulet is truly amazing.");
        set_weight(2);
        set_value(1700);
        set_type("clothing");
        set_limbs(({"neck"}));
        set_property("enchantment",1);
        set_item_bonus("magic resistance",1);
        set_size(-1);
        set_wear((:TO,"wearme":));
        set_remove((:TO,"unwearme":));
}
int wearme(string str){
   tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" reaches up and carefully secures the amulet into place.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^GREEN%^You reach up and carefully clasp the amulet into place.%^RESET%^");
   return 1;
}