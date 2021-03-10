#include <std.h>
inherit MONSTER;

void create()
{
  ::create();
  set_mob_magic_resistance("average");
  set_name("The Gentleman");
  set_id( ({"gentleman", "The Gentleman", "the gentleman"}) );
  set_short("%^BOLD%^%^GREEN%^The Gentleman%^RESET%^");
  set_long("Well let's just say you never heard of %^CYAN%^insects %^WHITE%^and %^CYAN%^humans %^WHITE%^cross breeding before, until now. This thing that stands before you is dressed in the most %^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^x%^BOLD%^quisi%^RESET%^%^BLUE%^t%^BOLD%^e cl%^RESET%^%^BLUE%^o%^BOLD%^th%^RESET%^%^BLUE%^e%^BOLD%^s %^RESET%^and carries himself %^BOLD%^proudly%^RESET%^. Unfortunatly, you only see him as a %^BOLD%^%^BLACK%^monster %^RESET%^and can't figure for the life of you why he is called '%^BOLD%^%^GREEN%^The Gentleman%^RESET%^'. He has the head of a %^BOLD%^%^BLACK%^fly %^RESET%^and appears to have no real spine, other then that he could pass as human.");
  set_race("insecthumanoid");
  set_gender("male");
  set_body_type("human");
  set_alignment(9);
  set_hd(20,20);
  set_max_hp(180);
  set_hp(180);
  set_mp(180);
  set_max_mp(180);
  set_new_exp(13, "boss");
  set_stats("strength", 15);
  set_stats("constitution", 10);
  set_stats("dexterity", 20);
  set_stats("wisdom", 18);
  set_stats("intelligence", 20);
  set_stats("charisma", 2);
  set_overall_ac(0);
  set_size(2);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  set_class("mage");
  set_guild_level("mage", 20);
  set_mlevel("mage",20);
  set_funcs(({"hack"}));
  set_func_chance(40);
  set_spell_chance(50);
  set_spells( ({"dispel magic","magic missile", "animate dead", "monster summoning 2", "blindness"}) );
}

void hack(object targ) {
  int need, i, tac, tlevel, roll;
  tlevel = this_object()->query_level();
  need = "/daemon/bonus_d.c"->thaco(tlevel, "mage");
  tac = targ->query_ac();
  if(!((roll >= (need - tac)) || (roll == 20))) {
    tell_room(environment(targ), "%^BOLD%^%^CYAN%^The Gentleman casts a spell of haste upon himself and receives a burst of speed, but nothing happens!");
    return 1;
  }
  tell_room(environment(targ), "%^GREEN%^The Gentleman casts a spell of haste upon himself and receives a burst of unknown speed, and hacks upon "+targ->query_cap_name()+"!");
  set_func_chance(0);
  for(i=0;i<2;i++) {
    this_object()->execute_attack();
  }
  set_func_chance(35);
  tell_room(environment(targ), "%^BOLD%^%^WHITE%^The Gentleman's spell fades away!\n");
  return 1;
}
