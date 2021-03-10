//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/19/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"battle_axe";

void create(){
   ::create();
   set_id(({ "axe", "battle","battle axe", "well-made battle axe","special battle axe","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made battle axe%^RESET%^");
   set_long("This hefty axe features two crescent moon blades "+
      "balanced at the end of a thick wooden handle.  Each axe "+
      "blade is razor sharp and could easily slice through most "+
      "any opponent.  Tipping the wooden handle is a steel "+
      "spike that seems made to provide a little extra kick when "+
      "needed.  The shimmer along the axe's edges suggest that "+
      "this is no ordinary axe.");
   set_value(2500);
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
