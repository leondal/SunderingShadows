//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/19/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"dagger";

void create(){
   ::create();
   set_id(({"dagger","well-made dagger","special dagger","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made dagger%^RESET%^");
   set_long("This slender dagger has a sharpened blade about "+
      "six inches long with a narrow point.  The hilt is "+
      "wrapped in strips of black leather, giving the weapon "+
      "a fine grip.  The sharpness of the blade and the way "+
      "the light glints off it make this seem to be an "+
      "extraordinary weapon.");
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
