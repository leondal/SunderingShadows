#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_property("swarm",1);
  set_name("topi");
  set_id( ({"topi"}) );
   set_short("%^BOLD%^%^BLACK%^A Hideous Little Topi");
  set_long("%^BOLD%^%^BLACK%^This little beast looks to have been human once, but is now %^RESET%^shrunken%^BOLD%^%^BLACK%^, zombie-like, and most %^RED%^evil%^BOLD%^%^BLACK%^. They are very %^RESET%^agile%^BOLD%^%^BLACK%^ little buggers so watch it!");
//  new("/d/shadow/obj/potion/dimination.c")->move(this_object());
  set_race("topi");
  set_body_type("human");
  set_wielding_limbs( ({"left hand", "right hand"}) );
  set_gender("male");
  set_hd(7,3);
  set_stats("strength", 15);
  set_stats("dexterity", 20);
  set_stats("constitution", 10);
  set_stats("wisdom", 8);
  set_stats("intelligence", 8);
  set_stats("charisma", 2);
  set_max_hp(75);
  set_hp(75);
  set_overall_ac(6);
  set_alignment(9);
  set_size(1);
  set_new_exp(8, "normal");
  new("/d/koenig/town/mon/weapons/claws1.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/claws1.c")->move(this_object());
  command("wield claws in left hand");
  command("wield claws 2 in right hand");
  set_funcs( ({"leap"}) );
  set_func_chance(75);
}
void leap(object targ)
{
  tell_room(environment(targ), "The topi leaps high in the air then slashes "+targ->query_cap_name()+" horribly!", targ);
  targ->do_damage("head", random(8)+2);
  tell_object(targ, "%^BOLD%^%^RED%^The topi leaps high into the air and slashes at your head and neck without remorse!");
  return 1;
}
