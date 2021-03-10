//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/19/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"bastard_two";

void create(){
   ::create();
   set_id(({ "sword", "bastard sword", "two-handed bastard sword", "bastard", "bastard_two", "two-handed sword", "well-made two-handed bastard sword", "well-made two-handed sword", "special two-handed bastard sword","special weapon" }));
   set_short("%^BOLD%^%^WHITE%^A well-made two-handed "+
      "bastard sword%^RESET%^");
   set_long(
      "This well-made sword is fashioned from steel and features a "+
      "heavy blade with an almost blunt point.  It is double-edged "+
      "and quite sharp, two qualities that combine with the size "+
      "and weight to make this a dangerous weapon.  The hilt is "+
      "long enough to require too hands to effectively wield it.  "+
      "The extra shimmer along the blade's edge hints that this is "+
      "no ordinary weapon.");
   set_value(3000);
   set_property("no curse",1);
   set_property("enchantment",1);
   while((int)query_property("enchantment") < 1){
      remove_property("enchantment");
      set_property("enchantment",1);
   }
   set_wield((:TO,"wield_me":));
   set_property("levelrestrict",21);
   set_item_owner_prop("sale_clear",1);
   set_item_owner_prop("fence_clear",1);
}

void init(){
   ::init();
   if(interactive(ETO)){
      TO->add_item_owner(ETOQN);
   }
}

int wield_me(){
   if(!TO->query_owns_item(ETOQN)){
      tell_object(ETO,"You are not bound to this item.");
      return 0;
   }
   return 1;
}
