#include <std.h>
inherit "/std/monster";
#include "../derrodefs.h";
void create(){
  ::create();
  set_name("%^RESET%^%^RED%^fire snake%^RESET%^");
  set_short("%^RESET%^%^RED%^fire snake%^RESET%^");
  set_id(({"snake","fire snake"}));
  set_long("  This large snake is molted red and black like the surface of a pool of cooling lava."
  "  It seems to love the tempurature and the chance to roast some fresh meat!"
  );
  set_hd(20,2);
  set_hp(50);
  set_max_hp(50);
  set_race("snake");
  set_funcs(({"bite"}));
  set_emotes(15,({"%^BOLD%^%^RED%^Fire snake wraps around your legs trying to trip you!",
  "%^BOLD%^%^RED%^The firesnake suddenly glows %^WHITE%^white hot,%^RED%^ then fades as it scorches you!",
  }),1);
  set_func_chance(50);
  set_overall_ac(6);
  set_body_type("snake");
  set("aggressive",25);
  set_wielding_limbs(({"mouth"}));
  set_alignment(5);
  set_size(1);
  set_exp(1000);
  set_stats("strength",10);
  new(OBJ"fangs.c")->move(this_object());
  this_object()->force_me("wield fangs in mouth");
}
void bite(object targ){
tell_room(environment(TO),"%^BOLD%^%^RED%^The firesnake lunges forward to to slash at "+targ->query_cap_name()+" venom dripping from its jaws!",targ);
 tell_object(targ,"%^BOLD%^%^RED%^The firesnake lunges at you with its venomous jaws!");
  if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death",0)){
  targ->set_paralyzed(25,"%^BOLD%^%^RED%^The venom from the firesnakes jaws racks your body with pain!");
 tell_room(environment(TO),"%^BOLD%^%^RED%^"+targ->query_cap_name()+" grimaces in agony as the venom runs through him!",targ);
  }
}
//void die(mixed ob){
//  object fangs;
//message("environment","%^BOLD%^%^RED%^The firesnake crumbles into cinders!",environment(ob));
//fangs=(present("fangs",TO));
//fangs->remove();
 //::die(TO);
//}
