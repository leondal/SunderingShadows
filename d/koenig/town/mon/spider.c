#include <std.h>
inherit MONSTER;

// void paralyze(object targ);

void create()
{
  ::create();
  set_name("spider");
  set_id( ({"black widow","black widow spider"}) );
  set_short("%^BOLD%^%^BLACK%^A Giant Black Widow Spider%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This black widow spider is very hungry. Its beady black eyes %^GREEN%^glow%^BOLD%^%^BLACK%^ with malice and spite as it looks for its next meal.%^RESET%^");
  set_race("spider");
  set_gender("female");
  set_body_type("arachnid");
  add_limb("mouth", "head", 20, 20, 10);
  add_wielding_limb("mouth");
  set_wielding_limbs( ({"mouth"}) );
  set_hd(8,6);
  set_class("fighter");
  set_mlevel("fighter",8);
  set_max_hp(70);
  set_hp(70);
  set_overall_ac(4);
  set_size(3);
  set_new_exp(10, "normal");
  add_money("gold", (20));
  new("/d/koenig/town/mon/weapons/fangs2.c")->move(this_object());
  command("wield fangs in mouth");
  set_funcs( ({"paralyze"}) );
  set_func_chance(40);
}
void paralyze(object targ)
{
  if(!targ) return 0;
  if(!random(20)) return 0;
  tell_room(environment(targ),"%^YELLOW%^The Black Widow bites "+targ->query_cap_name()+" and paralyzes them!",targ);
  targ->set_paralyzed(10);
  tell_object(targ, "%^RED%^You have recieved the paralyzing bite of the Black Widow!");
  return 1;
}
