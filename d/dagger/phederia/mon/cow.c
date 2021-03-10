#include <std.h>
inherit WEAPONLESS;
void create(){
  ::create();
  set_name("cow");
  set_id(({"cow","sickly looking cow"}));
  set_short("Sickly looking cow");
  set_long("  This uncared for looking animal seems gaunt and unhealthy even with these rich pastures surrounding it.  Perhaps it is something in the air?  Black foamy spittle crusts its muzzle and mouth.");
  set_hd(3,8);
  set_max_hp(25);
  set_hp(25);
  set_race("bovine");
  set_body_type("equine");
  set_ac(7);
  set_exp(100);
  set_gender("female");
  set_attacks_num(1);
  set_damage(1,6);
  set_attack_limbs(({"head","hoof"}));
  set_stats("strength",17);
  set_moving(1);
  set_speed(20);
  set_base_damage_type("blunt");
  set_funcs(({"poison"}));
  set_func_chance(10);
}
void poison(object targ){
  if (!random(10)){
  tell_object(targ,"%^BOLD%^%^BLACK%^The cow wipes some poison spittle on you and you can feel the hideous stuff at work!");
  tell_room(environment(targ),"%^BOLD%^%^BLACK%^The cow brushes "+targ->query_cap_name()+" with its foaming mouth who screams and tries to claw the hidious stuff off!",targ);
  return 100;
  }
  tell_object(targ,"%^BOLD%^%^BLACK%^The cow brushes you with its muzzel and some foam is wiped off on you which begins to burn into your flesh!");
  tell_room(environment(targ),"%^BOLD%^%^BLACK%^The cow brushes "+targ->query_cap_name()+" with its muzzel who wipes fraticly to get it off his hand!",targ);
  return (roll_dice(2,10));
}
