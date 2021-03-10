
#include <std.h>
inherit WEAPONLESS;
create() {
 ::create();
set_name("sewer rat");
set_id( ({ "rat", "sewer rat"}) );
set_short("A Huge Sewer Rat.");
set("aggressive", 0);
set_level(12);
set_long("This is a huge brown sewer rat with glowing green eyes.
He bares his teeth at you and Drools!!");
set_gender("male");
set_alignment(9);
set("race", "rat");
set_hd(19,1);
set_body_type("quadruped");
set_max_hp(150);
set_hp(150);
set_size(1);
set_exp(500);
set_overall_ac(8);
set_funcs(({"bite"}));
set_func_chance(25);
set_attacks_num(3);
set_attack_limbs( ({"right paw","left paw","incisors"}) );
set_base_damage_type("slashing");
set_damage(2,15);
set_emotes(15,({
"The Sewer Rat screams like 2 cats fighting!",
"The Sewer Rat gnaws on your foot!"
}),1);
set_emotes(7,({
"The Sewer Rat adds a few stinky gifts to the muck on your foot!",
"The Sewer Rat looks at you with hunger in it's eyes!!"
}),0);
}

void bite(object targ)
{
  if(!targ) return 0;
  if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "The Sewer Rat bites at "+targ->query_cap_name()+" with it's sharp incisors!",targ);
  tell_object(targ, "The Sewer Rat bites you hard with it's sharp incisors!");
  targ->add_poisoning(2);
  return 1;

} else {

  tell_object(targ, "The Sewer Rat bites at you with his sharp incisors but misses you!");
  tell_room(environment(targ), "The Sewer Rat bites at "+targ->query_cap_name()+" with it's sharp incisors but misses!",targ);
}
}
int move_func() {
   remove_call_out("move_func");
if(!sizeof(query_attackers()) && !random(5)) run_away();
   return call_out("move_func",random(10));
}
