//ghostcloak.c - Coded by Circe for Lothwaite 3/21/04
// removed AC (none for cloaks), put it to randomly +2/+3 instead. Nienne, 10/07
#include <std.h>
#include "../lothwaite.h"

inherit ARMOUR;

void create(){
	::create();
	set_name("Deathshroud");
	set_id(({"shroud","death shroud","deathshroud","cloak","neckthing"}));
	set_obvious_short("%^RESET%^%^CYAN%^a tran%^BOLD%^slu%^RESET%^%^CYAN%^cent cloak%^RESET%^");
      set_short("%^BOLD%^%^CYAN%^Deathshroud%^RESET%^");
	set_long(
         "%^BOLD%^%^WHITE%^This translucent cloak seems a strange "+
         "mix of the %^CYAN%^ethereal %^WHITE%^and %^BLUE%^material"+
         "%^WHITE%^.  It certainly feels solid, but it has an "+
         "unearthly quality that suggests it is not wholly of "+
         "this plane.  The cloak has a deep hood that may be pulled "+
         "forward to hide the wearer's features, and a permanent "+
         "aura of %^CYAN%^cool air %^WHITE%^seems to hover around it.");
      set_lore("The %^BOLD%^%^CYAN%^Deathshroud %^RESET%^is said "+
         "to be just that - a shroud worn in death by the firbolgs "+
         "in the Barrier Mountain settlement of Lothwaite.  Those "+
         "who wear such things are said to be cursed by some for "+
         "killing the peaceful ghosts there, while others claim "+
         "the ghosts are malevolent spirits who must be put down."
      );
	set_weight(5);
      set_wear((:TO,"wear_me":));
      set_remove((:TO,"unwear_me":));
      set_value(1250);
        set_property("enchantment",random(2)+2);
      set_item_bonus("stealth",2);
	set_type("clothing");
	set_limbs(({"neck"}));
}

int wear_me(){
   int mylvl = ETO->query_lowest_level();
   int ench = TO->query_enchantment();
   if((string)ETO->query_name() == "firbolg ghost") return 1;
   if(mylvl/5 < ench+2){
      tell_object(ETO,"%^BOLD%^As you try to slip the cloak about "+
         "your shoulders, it fades away, and you hear a soft voice "+
         "laughing.");
      TO->remove();
      return 1;
   }
    tell_object(ETO,"%^BOLD%^You feel somehow less substantial "+
       "as you slip on the ghostly cloak.");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+"'s face grows a bit pale as "+
      ""+ETO->QS+" wears the cloak.",ETO);
   return 1;
}

int unwear_me(){
   tell_object(ETO,"%^BOLD%^You feel your full weight again.");
   return 1;
}
