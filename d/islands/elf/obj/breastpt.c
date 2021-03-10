#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";


void create(){
  ::create();

  set_id(({"plate","breastplate","coral breastplate","saakrune breastplate"}));
  set_obvious_short("%^RESET%^%^CYAN%^coral breastplate%^RESET%^");
  set_short("%^RESET%^%^CYAN%^saakrune breastplate%^RESET%^");
  set_long("%^CYAN%^This is a breastplate made from sharp coral."+
  "  The coral is smoother where it fits against the "+
  "wearer but it still looks rather uncomfortable.  "+
  "The coral itself oddly seem perpetually wet.  "+
  "Time will not dry it out.  Stalks of %^YELLOW%^yellow,%^BLUE%^ blue "+
  "and %^MAGENTA%^purple%^RESET%^%^CYAN%^ jut from the wearer's chest.  Getting "+
  "past these would prove a problem for any attacker.%^RESET%^" );

   set_value(10000);
   set_wear((:TO,"extra_wear":));
   set_property("enchantment",4);
   set_item_bonus("spell damage resistance",20);
   set_item_bonus("charisma",-1);
   set_size(random(3)+1);
   set_property("lore_difficulty",30);
   set_lore("This appears to be the armor of some sea wizard."+
   "  The coral looks like it was grown in this shape rather"+
   " than harvested.  ");
   set_struck((:TO,"strikeme":));
   set_item_bonus("cold resistance",10);
}

int extra_wear(){

  tell_object(ETO,"%^CYAN%^You slide into the roughly carved "+
     "armor, and it causes your clothing to get wet.");
  tell_room(EETO,"%^CYAN%^"+ETOQCN+" slides into a breastplate of "+
     "coral, and gets wet.",ETO);
  return 1;
}
int strikeme(int damage, object what, object who){
       if(!random(5))return damage;
        tell_object(ETO,"%^CYAN%^"+who->QCN +"strikes your breastplate and gets cut on the coral.");
        tell_object(who,"%^CYAN%^You strike "+ETO->QCN+"'s breastplate and get cut on the coral.");
        tell_room(EETO,"%^CYAN%^"+who->QCN+" strikes "+ETO->QCN+
		"'s breastplate and gets cut on the coral.",({who,ETO}));
  if(!random(4)){   
        who->set_paralyzed((random(6)+3),
		"%^MAGENTA%^The cut from the coral causes your limbs to go numb and become heavy!");
  }
  who->cause_typed_damage(who,0,roll_dice(1,6)+2,"slashing");
  return (-1)*(damage/2);
}
