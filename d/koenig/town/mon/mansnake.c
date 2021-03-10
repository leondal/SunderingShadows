#include <std.h>
inherit "/realms/pegasus/bodies/humanserpent.c";

// void strangle(object targ);
// void extasy(object targ);

void create()
{
  ::create();
  set_name("snakeman");
  set_id( ({"snakeman"}) );
  set_short("%^BOLD%^%^GREEN%^A %^RESET%^%^GREEN%^Hideous%^BOLD%^%^GREEN%^ Snakeman%^RESET%^");
  set_long("%^RESET%^This man is as much snake as he is a man. He has slitted %^YELLOW%^golden eyes%^RESET%^ and a forked %^BOLD%^%^RED%^tongue%^RESET%^ pokes between his %^BOLD%^sharp fangs%^RESET%^. His tuft of %^BOLD%^%^BLACK%^black hair%^RESET%^ is carefully groomed to enhance his serpentine features. His long tail rattles in warning.");
  set_race("mansnake");
  set_gender("male");
  set_alignment(6);
  set_body_type("humanserpent");
  add_limb("mouth", "head", 20, 20, 10);
  add_limb("tail", "torso", 20, 20, 10);
  set_wielding_limbs( ({"mouth", "tail"}) );
  set_class("fighter");
  set_hd(8,2);
  set_max_hp(66);
  set_hp(66);
  set_overall_ac(5);
  set_size(3);
  set_new_exp(12, "normal");
  add_money("gold", (75));
  new("/d/koenig/town/mon/weapons/fangs2.c")->move(this_object());
  new("/d/koenig/town/mon/weapons/rattle.c")->move(this_object());
  command("wield fangs in mouth");
  command("wield rattle in tail");
  set_funcs( ({"extasy", "strangle"}) );
  set_func_chance(102);
  set("aggressive",19);
}
void extasy(object targ) 
{
  if(!targ) return 0;
tell_room(environment(targ),"The snakeman gives "+targ->query_cap_name()+" a kiss of death.\n",targ);
    targ->set_paralyzed(random(50),"%^BOLD%^%^CYAN%^The snakeman gives you the bite of ecstasy, paralyzing you!");
  return 1;
}
void strangle(object targ) {
  if(!targ) return 0;
  tell_room(environment(targ),"The snakeman reaches up with his tail and begins to strangle "+targ->query_cap_name()+"!", targ);
  tell_object(targ,"%^BOLD%^%^RED%^The snakeman begins to slowly strangle the life from you!");
   targ->do_damage("torso", random(10)+2);
  return 1;
}
