#include <std.h>
inherit "/d/common/obj/armour/breastplate";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("%^BOLD%^%^BLACK%^B%^RESET%^a%^BOLD%^%^WHITE%^t%^BLACK%^t%^RESET%^l%^BOLD%^%^WHITE%^e%^BLACK%^p%^RESET%^l%^BOLD%^%^BLACK%^a%^WHITE%^t%^BLACK%^e%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^B%^RESET%^a%^BOLD%^%^WHITE%^t%^BLACK%^t%^RESET%^l%^BOLD%^%^WHITE%^e%^BLACK%^p%^RESET%^l%^BOLD%^%^BLACK%^a%^WHITE%^t%^BLACK%^e%^RESET%^");
   set_obvious_short("%^RESET%^A battered old breastplate");
   set_id(({"breastplate","breast plate","plate","armor"}));
   set_long("%^BOLD%^%^BLACK%^This beaten breastplate is made "+
      "of thick adamantium somehow made rather light.  It has "+
      "many dents and dings, and even a few repaired holes.  "+
      "However, the center of the breastplate is dominated by "+
      "a flawless image - that of a spiked war gauntlet.  Carved "+
      "on the back of the gauntlet and filled with %^WHITE%^molten "+
      "silver %^BLACK%^is a fantastic long sword.  The sword has "+
      "been stained to look as though it is always covered in blood.");
   set_lore("This breastplate was once worn by the greatest warrior "+
      "of Tempus, Merigant the Brave.  The breastplate was made "+
      "for him by his leader when he was young and was instrumental "+
      "in winning his first battle.  Thereafter, he never cast "+
      "the breastplate aside, and it is said that so long as "+
      "Merigant was present and in this armor, his army would "+
      "never fall.");
   set_property("lore difficulty",12);
   set_property("enchantment",2);
      if(TO->query_property("enchantment")< 2){
      remove_property("enchantment");
      set_property("enchantment",2);
      }   
   set_value(0);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

void init()
{
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED) {
   owner = TPQN;
   OWNED = 1;
   set_size(TP->query_size());
   }
}

int wearme()
{
   if((string)TPQN != owner) {
      tell_object(ETO,"The armor refuses to fit to your form! 
You are not its master!");
      tell_room(environment(ETO),""+ETO->query_cap_name()+" screams in pain as "+ETO->query_subjective()+" tries to slip on
the armor.",ETO);
      set_property("magic",1);
      ETO->do_damage("torso",random(20)+10);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }
   tell_object(ETO,"%^RED%^You slip on the breastplate and feel "+
      "the comfortable weight of %^BOLD%^battle %^RESET%^%^RED%^"+
      "settle on your shoulders.");
   tell_room(environment(ETO),"%^RED%^"+ETOQCN+"'s eyes grow dark "+
      "as "+ETO->QS+" wears a battered breastplate.",ETO);
   return 1;
}


int removeme(){
   tell_object(ETO,"%^RED%^The weight of the battle leaves you as you "+
      "remove the breastplate.");
   tell_room(EETO,"%^RED%^"+ETOQCN+" seems more relaxe as "+ETO->QS+" "+
      "takes off the breastplate.",ETO);
   return 1;
}

void set_owner(string str){
   owner = str;
   OWNED = 1;
}