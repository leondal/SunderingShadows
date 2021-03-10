//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/20/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"mace";

void create(){
   ::create();
   set_id(({"mace","well-made mace","special mace","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made mace%^RESET%^");
   set_long("This mace is a blunt striking weapon, suitable "+
      "for fighting on foot or from horseback.  The head of "+
      "the mace is a single piece of cast iron, and the "+
      "handle is made from the heartwood of an oak tree.  "+
      "The handle has been wrapped in slender leather strips "+
      "to help provide a more comfortable grip, and the glinting "+
      "of light from the cast iron head shows that this is an "+
      "extraordinary mace.");
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
