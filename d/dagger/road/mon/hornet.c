
#include <std.h>
inherit WEAPONLESS;

create (){
::create ();
set_name("giant hornet");
set_id( ({"hornet","giant hornet"}) );
set("short", "A giant hornet");
set("long", "This is a Giant Hornet!! It's stinger is HUGE!!!");
set_gender("female");
set("race", "hornet");
set_body_type("insectoid-winged");
set_hd(6,2);
set_overall_ac(2);
set_size(2);
set_stats("strength", 14);
set_stats("intelligence", 1);
set_stats("dexterity", 16);
set_stats("charisma", 1);
set_stats("wisdom", 1);
set_class("fighter");
set("aggressive", 50);
set_alignment(5);
set_max_hp(55);
set_hp(55);
set_exp(550);
add_limb("stinger","abdomen",0,0,0);
set_base_damage_type("piercing");
set_damage(1,4);
set_attack_limbs(({"stinger"}));
set_attacks_num(1);
set_emotes(20,({"%^YELLOW%^The Giant Hornet flys around wildly looking for a opening to sting you!",
"%^BOLD%^The Giant Hornet swoops down at you in a attack!!"}),1);
set_funcs( ({"sting"}) );
set_func_chance(65);
}

void sting(object targ)
{
  if(!targ) return 0;
  if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "%^YELLOW%^The Giant Hornet grabs "+targ->query_cap_name()+" with it's legs and STINGS them repeatedly!!",targ);
  tell_object(targ, "%^YELLOW%^The Giant Hornet grabs you with it's legs and STINGS you repeatedly!!");
  targ->do_damage("torso", random(5)+6);
  return 1;

}else{

  tell_object(targ, "%^BOLD%^%^BLUE%^The Giant Hornet grabs you in it's legs, but you deflect it's stinger!");
  tell_room(environment(targ), "%^BOLD%^%^BLUE%^The Giant Hornet grabs "+targ->query_cap_name()+" in it's legs but they deflect the stinger!",targ);

}
}
