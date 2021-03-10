#include <std.h>
inherit WEAPONLESS;
void init(){
  ::init();
  if(!userp(TP)) return ;
  if(TP->query_hp() < TP->query_max_hp() && !wizardp(TP)){
  tell_room(ETO,"The ape goes wild at the smell of blood!");
  kill_ob(TP,1);
  }
}
void create(){
  ::create();
  set_name("phederian white ape");
  set_id(({"ape","white ape"}));
  set_short("%^BOLD%^%^WHITE%^White ape%^BOLD%^%^RED%^");
  set_long(
  "  This white beast look completly out of place here."
  "  Its pale red eyes shimmer with mallice and it continually sniffs at the air around you as if looking for a weakness."
  "   A massive barrel chest supports great arms which end in hands that could more appropriatly be called talons."
  "  Phederia breeds these albino apes to fight alongside her troops and to guard areas, which to your misfortune appears to be right where you are."
  );
  set_hd((random(10)+15),20);
  set_attacks_num(2);
  set_max_hp(query_hd()*8);
  set_hp(query_max_hp());
  set_property("no random treasure",1);
  set_attack_limbs(({"right clawed hand","left clawed hand","slavering jaws"}));
  add_money("silver",roll_dice(2,10));
  add_money("platinum",roll_dice(1,10));
  set_damage(2,4);
  set_stats("strength",18);
  set_race("white ape");
  set_body_type("humanoid");
  set_moving(1);
  set_speed(20);
  set_ac(-5);
  set_exp(query_hp()*10);
  set_property("swarm",1);
  set_mob_magic_resistance("average");
  if(!random(2)){set_gender("male");} else {set_gender("female");}
  set_funcs(({"pin"}));
  set_func_chance(10);
}
void pin(object targ){
  if(random(30)>((int)targ->query_stats("dexterity"))){
  tell_object(targ,"%^BOLD%^%^The ape screeches and lunges onto your back, grabs both your arms and twists them behind you!");
  tell_room(environment(targ),"%^BOLD%^The ape screeches and lunges at "+targ->query_cap_name()+" grabs both his arms and twists them behind his back!",targ);
  targ->set_paralyzed(15,"You struggle to break free from the apes embrace!\n");
  TO->set_paralyzed(15,"Pinning");
  return roll_dice(10,2);
  }
  else {
  tell_object(targ,"%^BOLD%^The ape lunges for you with malice in its eye but you duck out of the way.");
  tell_room(environment(targ),"%^BOLD%^The ape lunges for "+targ->query_cap_name()+" but they duck out of the way and the ape misses.",targ);
  return 1;
  }
}
int query_watched(){
  return 20;
}
