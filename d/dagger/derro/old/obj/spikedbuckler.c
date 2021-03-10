#include <std.h>
inherit WEAPON;
void create(){
  ::create();
  set_id(({"shield","spiked shield","buckler","spiked buckler"}));
  set_name("spiked buckler");
  set_short("A spiked buckler");
  set_long(
  "  This is a small metal shield with a single large spike protruding from its center."
  "  A long thin blade runs out from the edge of the shield to make it able to slash as well as stab."
  "  "
  "From the look of the handle, it's a shield you would wield rather than wear to make it effective in combat."
  );
  set_weight(7);
  set_size(1);
  set_value(25);
  set_ac(1);
  set_wc(1,4);
  set_large_wc(1,4);
  set_type("piercing");
  set_prof_type("spikedbuckler");
  set_property("enchantment",1);
  set_hit((:TO,"extra_hit":));
}
int extra_hit(object victem){
  if(!objectp(victem)) return 1;
  if(!random(5)){
   tell_object(ETO,"As you strike with the blade on the shield you drag the spike back across "+victem->query_cap_name()+" scratching "+victem->query_objective()+" badly.");
   tell_object(victem,""+ETO->query_cap_name()+" slashes you with a blade on "+ETO->query_possessive()+" buckler then twists the small shield to rake its spike across you as well.");
   tell_room(environment(query_wielded()),""+ETO->query_cap_name()+" slashes at "+victem->query_cap_name()+" with the blade on the edge of a small buckler then twists it to rake the spiked back across "+victem->query_objective()+" again.",({ETO,victem}));
  victem->heal(-(random(6)+5));
  }
  return 1;
}
