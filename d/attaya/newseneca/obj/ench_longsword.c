//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/19/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"longsword";

void create(){
   ::create();
   set_id(({"long sword","longsword","well-made long sword","well-made longsword","special longsword","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made longsword%^RESET%^");
   set_long("This is a straight bladed, double-edged sword, "+
      "commonly known as a longsword.  The blade is thinner "+
      "than the broad and bastard sword, but a bit longer.  "+
      "It looks very effective, as its combination of an edge, "+
      "point, speed and length makes it more versatile than many "+
      "other weapons.  The brilliant edge and faint glimmer of "+
      "this particular weapon hint that it is no ordinary "+
      "longsword.");
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
