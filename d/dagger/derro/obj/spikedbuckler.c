//updated code to inherit dagger for consistency ~Circe~ 7/30/19
#include <std.h>

inherit "/d/common/obj/weapon/dagger.c";

void create(){
   ::create();
   set_id(({"shield","spiked shield","buckler","spiked buckler"}));
   set_name("spiked buckler");
   set_short("A spiked buckler");
   set_long("This is a small metal shield with a single large spike protruding from its center.  A long thin blade runs out from the edge of the shield to make it able to slash as well as stab.  From the look of the handle, it's a shield you would wield rather than wear to make it effective in combat.");
   set_lore("Ever inventive with anything involving combat, the derro developed these unusual shields and have spent centuries perfecting their use.");
   set_weight(7);
   set_value(25);
   set_ac(1);
   set_property("enchantment",3);
   set_hit((:TO,"extra_hit":));
}

int extra_hit(object victim){
   if(!objectp(victim)) return 1;
   if(!random(5)){
      tell_object(ETO,"As you strike with the blade on the shield, you drag the spike back across "+victim->QCN+" scratching "+victim->QO+" badly.");
      tell_object(victim,""+ETO->QCN+" slashes you with a blade on "+ETO->QP+" buckler, then twists the small shield to rake its spike across you as well.");
      tell_room(environment(query_wielded()),""+ETO->QCN+" slashes at "+victim->QCN+" with the blade on the edge of a small buckler, then twists it to rake the spiked back across "+victim->QO+" again.",({ETO,victim}));
     victim->do_damage("torso",random(6)+5);
   }
   return 1;
}
