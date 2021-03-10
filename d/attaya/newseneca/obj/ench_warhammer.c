//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/20/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"warhammer";

void create(){
   ::create();
   set_id(({"hammer","warhammer","war hammer","medium warhammer", "medium war hammer", "well-made war hammer","well-made warhammer","special warhammer","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made medium war hammer%^RESET%^");
   set_long("This is a heavy iron war hammer.  It has a long, "+
      "thick head on one side counterbalanced on the other by "+
      "a heavy spike.  The long handle is made of oak reinforced "+
      "with iron plating.  The hammer definitely has its uses if "+
      "you want to try to crack someone out of his shell.  "+
      "The extra care taken in the creation of this weapon hint "+
      "that it is no ordinary hammer.");
   set_value(3500);
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
