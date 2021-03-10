
#include <std.h>
inherit WEAPONLESS;

int move_func();

create() {
 ::create();
set_name("nasty rat");
set_id( ({ "rat", "nasty rat"}) );
set_short("A Huge Nasty Rat.");
set("aggressive", 0);
set_level(12);
set_long("This is a huge grey nasty rat with glowing yellow eyes.
He bares his teeth at you and Hisses!!");
set_gender("male");
set_alignment(9);
set("race", "rat");
set_hd(19,1);
set_body_type("quadruped");
set_emotes(15,({
"The Nasty Rat squeeks loudly!",
"The Nasty Rat drools on you!"
}),1);
set_emotes(7,({
"The Nasty Rat sniffs the air!",
"The Nasty Rat looks at you with hunger in it's eyes!!"
}),0);
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
move_func();
}

void bite(object targ)
{
  if(!targ) return 0;
  if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "The Nasty Rat bites at "+targ->query_cap_name()+" with it's sharp incisors!",targ);
  tell_object(targ, "The Nasty Rat bites you hard with it's sharp incisors!");
  targ->add_poisoning(2);
  return 1;

} else {

  tell_object(targ, "The Nasty Rat bites at you with his sharp incisors but misses you!");
  tell_room(environment(targ), "The Nasty Rat bites at "+targ->query_cap_name()+" with it's sharp incisors but misses!",targ);
}
}

int move_func() {
   remove_call_out("move_func");
if(!sizeof(query_attackers()) && !random(5)) run_away();
   return call_out("move_func",random(10));
}

