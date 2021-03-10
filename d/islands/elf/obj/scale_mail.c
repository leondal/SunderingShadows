#include <std.h>
inherit "/d/common/obj/armour/scale.c";


void create(){
  ::create();

  set_id(({"scale","armor","scale mail","tarnished scale mail","mail","scales"}));
  set_obvious_short("%^BLUE%^t%^CYAN%^a%^BLUE%^rnished scale mail%^RESET%^");
  set_short("%^BLUE%^s%^CYAN%^c%^BLUE%^ales of the d%^CYAN%^e%^BLUE%^ep%^RESET%^");
  set_long("Long ago this scale mail used"+
  " to be nice.  Many years have not been "+
  "kind to it.   The scales are dark and "+
  "tarnished.  Dark barnicles are growing on"+
  " the item leaking a black ooze from time to time.");

   set_value(10000);
   set_wear((:TO,"extra_wear":));
   set_remove((:TO,"remove_fun":));
   set_property("enchantment",4+random(2));
   set_item_bonus("spell damage resistance",20);
   set_item_bonus("charisma",-1);
   set_size(2);
   set_property("lore_difficulty",40);
   set_lore("This armor used to be something nobles"+
   " of an ancient empire would wear to show their"+
   " status.  However the name of the empire has "+
   "been lost.  They suddenly are said to have"+
   " been sunken into the sea and most of the history was lost. ");
   set_struck((:TO,"strikeme":));
   set_item_bonus("divine resistance",-10);
   set_item_bonus("fire resistance",20);
   set_item_bonus("bludgeoning resistance",5);
}

int extra_wear(){

  tell_object(ETO,"%^BLUE%^You secure the straps of the "+
  "scale mail and feel cold and wet.\n%^CYAN%^For "+
  "some reason you seem to be able to breath water now!");
  tell_room(EETO,"%^BLUE%^"+ETOQCN+" equips the scale mail "+
     "and gets wet.",ETO);
  ETO->set_property("water breather",1);
  return 1;
}
int remove_fun() {
   ETO->set_property("water breather",-1);
   return 1;
}
int strikeme(int damage, object what, object who){
       if(!random(5))return damage;
        tell_object(ETO,"%^BLUE%^"+who->QCN +"strikes your scales and gets cut
on the barnicles.");
        tell_object(who,"%^BLUE%^You strike "+ETO->QCN+"'s scale mail and get cut
on the barnicles.");
        tell_room(EETO,"%^BLUE%^"+who->QCN+" strikes "+ETO->QCN+
                "'s scale mail and gets cut by it.",({who,ETO}));
  if(!random(4)){   
        who->set_paralyzed((random(6)+3),
       "Poison freezes your limbs!");
  }
  who->cause_typed_damage(who,0,roll_dice(1,6)+5,"slashing");
  return (-1)*(damage/2);
}