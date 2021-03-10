//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/19/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"flail";

void create(){
   ::create();
   set_id(({"flail","well-made flail","special flail","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made flail%^RESET%^");
   set_long("This wicked weapon is made from a thick oaken handle "+
      "covered with a layer of iron.  A thick chain dangles from "+
      "the end of the handle and supports a spiked iron ball that "+
      "may be swung at enemies to cause tremendous harm.  The "+
      "sharpness of the spikes and the extra reinforcement along "+
      "the handle hint that this is no ordinary weapon.");
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
