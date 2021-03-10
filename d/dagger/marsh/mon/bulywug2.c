
#include <std.h>
inherit MONSTER;

create (){
::create ();
set_name("bullywug");
set_id( ({"bullywug"}) );
set("short", "A bullywug");
set("long", "This is a Bullywug, a bipedal frog-like amphibian.
It looks like a large frog standing on his hind feet and has mottled
olive green skin and stands about 5 feet tall.
You remember hearing that they attack in droves, so if theres 1
of them here, theres gonna be more of them soon!");
set_gender("male");
set("race", "bullywug");
set_body_type("human");
set_hd(9,0);
set_overall_ac(6);
set_size(2);
set_stats("strength", 15);
set_stats("intelligence", 6);
set_stats("dexterity", 17);
set_stats("charisma", 1);
set_stats("wisdom", 5);
set_class("fighter");
set("aggressive", 15);
set_alignment(8);
set_max_hp(95);
set_hp(95);
set_exp(600);
remove_limb("right foot");
remove_limb("left foot");
remove_limb("head");
add_limb("right webbed foot","right leg",0,0,0);
add_limb("left webbed foot","left leg",0,0,0);
add_limb("frog head","torso",0,0,0);
add_money("gold", 15 + random(50));
set_emotes(20,({"The Bullywug croaks loudly calling for his pals to come aid him!"}),1);
set_funcs( ({"hop"}) );
set_func_chance(65);
set_wielding_limbs( ({"left hand","right hand"}) );
new("/d/dagger/marsh/items/wpns/falchion.c")->move(this_object());
command("wield sword");
new("/d/dagger/marsh/items/armor/shield.c")->move(this_object());
command("wear shield");
new("/d/dagger/marsh/items/armor/scale.c")->move(this_object());
command("wear armor");
}

void hop(object targ)
{
  if(!targ) return 0;
  if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "%^GREEN%^The Bullywug HOPS 15 feet into the air at "+targ->query_cap_name()+", swinging it's weapon in a attack!!",targ);
  tell_object(targ, "%^GREEN%^The Bullywug HOPS 15 feet into the air at you, swinging it's weapon in a attack!!");
  targ->do_damage("torso", random(4)+6);
  return 1;

}else{

  tell_object(targ, "%^BOLD%^%^BLUE%^The Bullywug HOPS at you in a attack, but misses you!");
  tell_room(environment(targ), "%^BOLD%^%^BLUE%^The Bullywug HOPS at "+targ->query_cap_name()+" in a attack, but misses them!",targ);
}
}
