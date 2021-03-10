//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/20/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"shortsword";

void create(){
   ::create();
   set_id(({"shortsword","short sword","well-made short sword","well-made shortsword","special short sword","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made short sword%^RESET%^");
   set_long("This small sword features a short steel blade around "+
      "two feet in length.  The slender sword has been honed to "+
      "a keen edge on both sides, and a carved ebony handle is "+
      "attached using iron fittings for added stability.  The "+
      "sheen of the blade suggests that this is a most "+
      "extraordinary short sword.");
   set_value(4500);
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
