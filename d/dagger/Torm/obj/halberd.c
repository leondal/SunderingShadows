#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
  set_id(({"halberd","soul cleaver","soul cleaver halberd"}));
  set_name("soul cleaver");
  set_short("Soul cleaver halberd");
   set_long(
  "  This grey halberd seems moulded from a single piece of strange grey metal."
    "  It's almost as if it was poured from liquid smoke and solidified at the outside, leaving the shadows inside to swirl about like water under a skim of ice."
  "  Slowly faces take form and swirl about under the surface for a short time before dispersing into the background only to have another face surface somewhere else."
    "  The weapon fills you with unease but you realize it's all in balance as you contine to watch the smoke."
   );
  set_weight(20);
   set_size(3);
  set_value(150);
  set_wc(4,3);
  set_large_wc(3,6);
   set_type("slash");
   set_prof_type("polearm");
  set_property("enchantment",2);
  set_property("monsterweapon",1);
  set_hit((:TO,"extra_hit":));
  set_wield((:TO,"extra_wield":));
}
  int extra_hit(object ob){  
  if(!random(4)){
    tell_object(ETO,"%^BOLD%^%^BLACK%^The halberd's blade slices though "+ob->query_cap_name()+" as if the body were made of smoke.");
    tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"s halberd cuts through "+ob->query_cap_name()+" who seems to lose a piece of "+ob->query_possessive()+" soul as the grey blade passes through.",(({ETO,ob})));
  tell_object(ob,"%^BOLD%^%^BLACK%^You feel the halberd take a piece of your soul with it when it slices through your body.");
  return(random(5)+1);
  }
}
int extra_wield(){
  if((int)ETO->query_level() < 25){tell_object(ETO,"%^BLUE%^The weapon laughs as such a weak hand as yours tries to wield it!");return 0;}
  return 1;
}
