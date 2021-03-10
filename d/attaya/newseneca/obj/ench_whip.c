//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/20/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"whip";

void create(){
   ::create();
   set_id(({"whip","well-made whip","special whip","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made whip%^RESET%^");
   set_long("Interwoven strips of leather and steel have been "+
      "braided together to create this flexible whip.  The "+
      "handle of the whip is crafted from leather, creating a "+
      "comfortable grip.  The tip of the whip has been dipped in "+
      "molten steel, which has hardened to add quite an effective "+
      "sting to the weapon.  The exquisite craftsmanship hints "+
      "that this is an extraordinary whip indeed.");
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
