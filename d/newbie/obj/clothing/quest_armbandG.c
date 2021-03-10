#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("colorful armband");
   set_short("A colorful %^BLUE%^a%^CYAN%^r%^GREEN%^m%^YELLOW%^b%^MAGENTA%^a%^RESET%^%^GREEN%^n%^CYAN%^d%^RESET%^");
   set_id(({"colorful armband","armband"}));
   set_long(
@STYX
%^GREEN%^This colorful %^BLUE%^a%^CYAN%^r%^GREEN%^m%^YELLOW%^b%^MAGENTA%^a%^RESET%^%^GREEN%^n%^CYAN%^d %^GREEN%^is clearly elven craftsmanship.  It has been intricately woven from various color leaves and vines.  The weave allows it to stretch slightly so it can slip up the arm and fit various size wearers at different points. 
STYX
   );
   set_lore("Crafted in the manner of the elves, this armband "+
      "looks to have been meant as some sort of mark of honor.  "+
      "It is rare for the elves to give these to those not of "+
      "their race, but it is known to happen when the recipient "+
      "has done an exceptional deed.");
   set_weight(3);
   set_type("clothing");
   set_limbs(({"right arm"}));
   set_value(20);
   set_cointype("gold");
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   set_ac(1);
}

int wearme() {
    tell_object(ETO,"As you slip the armband on, you feel more in touch with "
      "nature.");
    tell_room(environment(ETO),ETO->query_cap_name()+" slips the armband on and smiles.",ETO);
    return 1;
}

int removeme() {
    tell_object(ETO,"You feel less in touch with nature as you remove the "
       "colorful armband.");
    tell_room(environment(ETO),ETO->query_cap_name()+" reluctantly removes the colorful "
       "armband.",ETO);
    return 1;
}

