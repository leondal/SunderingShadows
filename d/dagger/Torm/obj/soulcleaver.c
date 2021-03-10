#include <std.h>
inherit "/d/common/obj/weapon/halberd";

create() {
    ::create();
  set_id(({"halberd","soul cleaver","soul cleaver halberd"}));
  set_name("soul cleaver");
  set_obvious_short("a dark grey halberd");
  set_short("%^BOLD%^BLACK%^Soul Cleaver%^RESET%^");
  set_long(
  "%^BOLD%^%^BLACK%^"
  "  This grey halberd seems moulded from a single piece of strange grey metal."
    "  It's almost as if it was poured from liquid smoke and solidified at the outside, leaving the shadows inside to swirl about like water under a skim of ice."
  "  Slowly faces take form and swirl about under the surface for a short time before dispersing into the background only to have another face surface somewhere else."
    "  The weapon fills you with unease but you realize it's all in balance as you contine to watch the smoke."
   );
//  set_weight(20);
//   set_size(3);
  set_value(150);
//  set_wc(1,12);
//  set_large_wc(3,6);
//   set_type("slash");
//   set_prof_type("polearm");
  set_property("enchantment",2);
  set_hit((:TO,"extra_hit":));
  set_wield((:TO,"extra_wield":));
}
  int extra_hit(object ob){
  int dam;
  if(!random(4)){
    tell_object(ETO,"%^BOLD%^%^BLACK%^The halberds blade slices though "+ob->query_cap_name()+" as if "+ob->query_possessive()+" body were made of smoke.");
    tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s halberd cuts through "+ob->query_cap_name()+" who seems to lose a piece of "+ob->query_possessive()+" soul as the grey blade passes through.",(({ETO,ob})));
  tell_object(ob,"%^BOLD%^%^BLACK%^You feel the halberd take a piece of your soul with it when it slices through your body.");
  dam=random(3)+1;
  ETO->add_hp(dam);
  return dam;
  }
}
int extra_wield(){
  if((int)ETO->query_level() < 25){tell_object(ETO,"%^BLUE%^The weapon laughs as such a weak hand as yours tries to wield it!");return 0;}
  return 1;
}
