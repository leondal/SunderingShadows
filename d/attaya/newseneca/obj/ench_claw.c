//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/19/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"claw";

void create() {
   ::create();
   set_id(({ "iron claw","claw","well-made claw","special claw","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made iron claw%^RESET%^");
   set_long("Attached to a metal brace are three six-inch pointed "+
      "claws.  Two straps attached to the metal brace allow for "+
      "the claw to be fitted in place on the wearer's forearm.  "+
      "The glint of light shimmering off the claws hint that this "+
      "weapon is anything but ordinary.");
   set_value(2000);
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