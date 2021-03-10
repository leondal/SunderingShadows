
#include <std.h>

inherit WEAPONLESS;
create ()
{
::create ();
set_name("shambling mound");
set_id(({"mound","shambling mound","shambler"}));
set("short", "A shambling mound");
set("long", "This is a Shambling Mound or Shambler.
It looks like a large heap of rotting vegitation, but it's
actually a intelligent form of plant life with a rough humanoid
shape of around 7 feet tall. It doesn't look like much,
But...beware it will eat anything it can catch.");
set_gender("neuter");
set("race", "shambling mound");
set_body_type("human");
set_hd(13,0);
set_overall_ac(0);
set_size(2);
set_stats("strength", 18);
set_stats("intelligence", 5);
set_stats("dexterity", 16);
set_stats("charisma", 1);
set_stats("wisdom", 1);
set_class("fighter");
set("aggressive", 15);
set_alignment(5);
set_base_damage_type("bludgeoning");
set_damage(2,16);
set_attack_limbs(({"right arm","left arm"}));
set_attacks_num(2);
remove_limb("left hand");
remove_limb("right hand");
set_max_hp(250);
set_hp(250);
set_exp(2500);
set_emotes(20,({"%^GREEN%^The Shambling Mound Grabs at you!",
"%^BOLD%^%^GREEN%^The Shambling Mound bashes at you with its arms!"}),1);
  set_funcs( ({"suffocation"}) );
  set_func_chance(60);
}


void suffocation(object targ)
{
  if(!targ) return 0;
  if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "%^GREEN%^The Shambling Mound grabs "+targ->query_cap_name()+" in its arms and smothers them against its body!",targ);
  tell_object(targ, "%^RED%^The Shambling Mound grabs you in its arms and smothers you against its body!!");
  targ->do_damage("head", random(2)+18);
  return 1;
}else{
   tell_object(targ, "%^BOLD%^%^BLUE%^The Shambling Mound grabs at you, but you avoid its grasp!");
   tell_room(environment(targ), "%^BOLD%^%^BLUE%^The Shambling Mound grabs at "+targ->query_cap_name()+", but "+targ->query_subjective()+" avoid its grasp!",targ);

}
}

