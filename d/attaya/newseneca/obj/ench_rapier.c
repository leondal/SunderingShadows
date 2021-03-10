//enchanted weapon for new Seneca
//buyable by levels 21+ as a means to reequip
//~Circe~ 1/20/08
#include <std.h>
#define COMWEAP "/d/common/obj/weapon/"+

inherit COMWEAP"rapier";

void create(){
   ::create();
   set_id(({"rapier","foil","well-made rapier","special rapier","special weapon"}));
   set_short("%^BOLD%^%^WHITE%^A well-made rapier%^RESET%^");
   set_long("This is a fairly light and thin-bladed weapon, "+
      "sometimes referred to as a foil.  It is used more for "+
      "thrusting jabs than sweeping arcs and often is used by "+
      "nimble, swashbuckling types or those who prefer to employ "+
      "finesse rather than brute force in sparring or battle.  "+
      "It looks durable, light, and easy to maintain.  The special "+
      "detail around this rapier's basket and the way the edge of "+
      "blade seems to hold the light hints that this is an "+
      "extraordinary weapon most unlike the common rapier.");
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
