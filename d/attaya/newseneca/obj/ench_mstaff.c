//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/20/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"mstaff";

void create(){
   ::create();
   set_id(({"staff", "wooden staff", "medium wooden staff", "mstaff", "medium staff", "well-made wooden staff", "well-made staff", "special staff","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made medium wooden staff%^RESET%^");
   set_long("This is a sturdy wooden staff about three feet "+
      "long.  It has bands of metal tightened around the far end "+
      "and along its length to afford it more support.  This one "+
      "is small enough to be wielded in one hand by human-sized "+
      "races or be used like a quarterstaff for the smaller ones.  "+
      "The exquisite carving and care taken in the wrapping of the "+
      "metal hint that this is an extraordinary staff.");
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
