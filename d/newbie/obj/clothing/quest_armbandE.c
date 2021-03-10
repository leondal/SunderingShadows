#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("leather armband");
   set_short("%^ORANGE%^A leather armband%^RESET%^");
   set_id(({"leather armband","armband"}));
   set_long(
@STYX
%^ORANGE%^This leather armband has some rather crude and unusual markings cut into the leather.  It is actually several strips of half inch wide leather woven flat into a six inch wide band.  The weave allows it to stretch slightly so it can slip up the arm and fit various size wearers at different points, typically near the bicep.
STYX
   );
   set_lore("This armband is crafted after the manner of "+
      "orcs, who often use braided leather.  The crude markings "+
      "suggest its orcish nature as well.  Often bands such as "+
      "these are given as a sign of honor for some deed well done.");
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
    tell_object(ETO,"The armband slips on snugly and reminds you of the young "
      "elf's likely fate.");
    tell_room(environment(ETO),ETO->query_cap_name()+" slips the armband on and smirks.",ETO);
    return 1;
}

int removeme() {
    tell_object(ETO,"Your arm chills slightly as you remove the leather band.");
    tell_room(environment(ETO),ETO->query_cap_name()+" seems to regret removing the armband.",ETO);
    return 1;
}