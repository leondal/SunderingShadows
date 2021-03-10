//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/19/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"lance";

void create(){
   ::create();
   set_id(({"lance","medium horse lance", "medium lance", "well-made lance","special lance","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made medium horse lance%^RESET%^");
   set_long("This slender wooden lance is several feet in length, "+
      "meant to be used against an opponent in mounted combat.  "+
      "The handle is wrapped with leather to provide a c"+
      "comfortable grip, and the wielder's hand is protected "+
      "by a guard that curves up and away from the lance.  "+
      "The superior craftsmanship shows that this is an "+
      "extraordinary weapon.");
   set_value(4000);
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
