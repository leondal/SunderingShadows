#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("white monkey");
  set_id(({"monkey","white monkey"}));
  set("race","monkey");
  set_gender("male");
  set("short","White monkey");
  set("long","The white monkey is a larger, stronger and very aggressive\n"+
             "relative of the normal monkey.  This beast has fair intelligence\n"+
             "and is very cunning.  It hungers particulary for human flesh.\n");
  set_level(6);
  set_hd(6,3);
  set_body_type("human");
  set_class("fighter");
  set_size(3);
  set("aggressive", 18);
  set_alignment(5);
  set_stats("strength", 20);
  set_stats("intelligence", 14);
  set_stats("constitution", 16);
  set_stats("wisdom", 7);
  set_stats("dexterty", 14);
  set_overall_ac(4);
  set_exp(100);
  set_hp(63);
  set_funcs(({"rending"}));
  set_func_chance(40);
}

void rending(object targ) {
   tell_room(ETO,"%^BOLD%^%^GREEN%^The white monkey slams "+targ->query_cap_name()+" with both hands, and renders "+targ->query_objective()+" useless.",targ);
   tell_object(targ,"The white monkey slams you with both hands rendering you useless.");
  targ->set_paralyzed(random(10)+3);
  targ->do_damage("torso", roll_dice(1,8));
  return 1;
}
