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
        set_lore("%^GREEN%^The only way to tell this amulet apart from the others is by the small four leaf clover that magically appears within the emerald when you spin the amulet around.  This amulet is much stronger than the others and is rumored to possess better warding powers as well.  It is said that this amulet was made stronger to match the strength of Laklier, the guardian of the pot of gold.");
        set_weight(2);
        set_value(1700);
        set_type("clothing");
        set_limbs(({"neck"}));
        set_property("enchantment",2);
        set_item_bonus("magic resistance",1);
        set_size(-1);
        set_wear((:TO,"wearme":));
}
int wearme(string str){
   tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" reaches up and carefully secures the amulet into place.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^GREEN%^You reach up and carefully clasp the amulet into place.%^RESET%^");
   return 1;
}
int spin(string str){
   if(str == "necklace"||str=="the necklace"||str=="amulet"||str=="the amulet"||str=="emerald"||str=="the emerald"){
      tell_object(TP,"%^GREEN%^You slowly lift the amulet towards the light and spin it.  The amulet quickly gains speed, and as if by magic, a small four leaf clover shimmers into view within the emerald!%^RESET%^");
      tell_room(TO,"%^GREEN%^"+TPQCN+" lifts the amulet towards the light and spins it slowly.  The emerald seems to mesmerize "+TP->query_objective()+" for a moment becuase "+TP->query_subjective()+" can't seem to take "+TP->query_possessive()+" eyes off of it!",TP);
      return 1;
    }
}
