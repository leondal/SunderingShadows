#include <std.h>
inherit "/realms/pegasus/bodies/mollusk.c";

// void strangle(object targ);

void create()
{
  ::create();
  set_name("decapus");
  set_id( ({"decapus"}) );
  set_short("%^BOLD%^%^BLACK%^A decapus%^RESET%^");
   set_long("%^RESET%^This decapus is of the land variety. It is a 4-foot wide, hairy, bloated, globe sprouting 10-foot long tentacles. It is a hideous %^GREEN%^green%^RESET%^ color with %^BOLD%^%^BLACK%^black hair%^RESET%^ and its mouth is full of %^BOLD%^razor sharp teeth%^RESET%^! It prefers to strangle its victims.");
  set_race("decapus");
  set_gender("male");
  set_size(2);
  set_stats("strength", 18);
  set_stats("constitution", 16);
  set_stats("dexterity", 25);
  set_stats("wisdom", 14);
  set_stats("intelligence", 10);
  set_stats("charisma", 4);
  set_alignment(9);
  set_class("thief");
  set_body_type("mollusk");
  add_limb("fifth left tentacle", "torso", 20, 20, 10);
  add_limb("fifth right tentacle", "torso", 20, 20, 10);
  add_limb("second left tentacle", "torso", 20, 20, 10);
  add_limb("third left tentacle", "torso", 20, 20, 10);
  add_limb("fourth left tentacle", "torso", 20, 20, 10);
  add_limb("second right tentacle", "torso", 20, 20, 10);
  add_limb("third right tentacle", "torso", 20, 20, 10);
  add_limb("fourth right tentacle", "torso", 20, 20, 10);
  add_wielding_limb("fifth right tentacle");
  add_wielding_limb("fifth left tentacle");
  set_wielding_limbs( ({"second left tentacle", "third left tentacle", "fourth left tentacle", "fifth left tentacle", "second right tentacle", "third right tentacle", "fourth right tentacle", "fifth right tentacle"}) );
  set_hd(8,6);
  set_max_hp(70);
  set_hp(70);
  set_overall_ac(5);
  set_new_exp(12, "normal");
  add_money("gold",random(1000));
  new("/d/koenig/town/mon/weapons/hooks1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/hooks1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/hooks1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/hooks1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/hooks1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/hooks1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/hooks1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/hooks1.c")->move(this_object());
  new("/d/koenig/town/items/dungeonkey.c")->move(this_object());
  command("wield hook 8 in second left tentacle");
  command("wield hook 7 in third left tentacle");
  command("wield hook 6 in fourth left tentacle");
  command("wield hook 5 in fifth left tentacle");
  command("wield hook 4 in second right tentacle");
  command("wield hook 3 in third right tentacle");
  command("wield hook 2 in fourth right tentacle");
  command("wield hook in fifth right tentacle");
  set_funcs( ({"strangle"}) );
  set_func_chance(70);
}

void strangle(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ), "%^BOLD%^%^GREEN%^The decapus wraps a tentacle about "+ targ->query_cap_name()+" throat and begins to squeeze the life from them!", targ);
  tell_object(targ, "%^BOLD%^%^GREEN%^The decapus wraps a tentacle about your throat and begins to squeeze the life from you!");
  targ->do_damage("torso", random(9)+1);
  tell_object(targ, "%^BOLD%^%^RED%^The decapus squeezes the life from you!");
  targ->set_paralyzed(random(3), "%^BOLD%^%^WHITE%^You take a short time to recover from the deadly tentacle.");
  return 1;
}
