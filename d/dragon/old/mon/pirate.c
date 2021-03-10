#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("pirate");
  set_id(({"pirate","human pirate"}));
  set_short("Dirty Pirate");
  set_long("
This pirate keeps his hair in a long mohawk and wears a golden ring in 
his right ear.  This pirate is a member of Longjaw's evil band of pirates.
He has a remarkable tattoo of a pirate flag upon his forearm.");
  set_race("human");
  set_gender("male");
  set_hd(10,6);
  set_size(2);
  set_class("fighter");
  set_guild_level("fighter",10);
  set_max_hp(175);
  set_hp(175);
  set_wielding_limbs(({"right hand","left hand"}));
  set_body_type("humanoid");
  set_property("no_bump",1);
  set_stats("strength", 17);
  set_stats("dexterity", 18);
  set_stats("constitution", 14);
  set_stats("intelligence", 14);
  set_stats("wisdom", 10);
  set("aggressive","aggfunc");
  set_mob_magic_resistance("average");
  set_exp(1500);
  set_alignment(5);
  set_emotes(15, ({
    "How dare thee enter Longjaw's boat!",
    "So you are after Longjaw's buried treasure, ya bastard!",
    "Die ye bastard!"}),1);
  new("/d/dragon/obj/weapon/shsword")->move(this_object());
  command("wield sword in right hand");
  new("/d/common/obj/weapon/dagger")->move(TO);
  command("wield dagger in left hand");
  new( "/d/dragon/obj/armor/leather" )->move(this_object());
  command("wear leather");
  set_invis();
  set_overall_ac(3);
  set_funcs(({"dart"}));
  set_func_chance(25);
}

void aggfunc() {
  if(this_player()->query_invis()) {
    command("say You dare to enter Longjaw's boat invisible!");
    this_player()->kill_ob(this_object(), 0);
  } else {
    command("say How dare you, now you must die!");
    this_player()->kill_ob(this_object(), 0);
  }
}

void dart(object targ) {
  string dam;
  if("daemon/saving_d"->saving_throw(targ,"poison")) {
    dam="hurts";
  } else {
    dam="poisons";
  }
  tell_object(targ,"The pirate throws a small dart towards you. It "+dam+" you.");
   tell_room(environment(targ),"The pirate throws a dart towards "+targ->query_cap_name()+"!",targ);
  if(dam == "poisons") {
    targ->do_damage("torso",roll_dice(3,6));
    targ->set_paralyzed(random(10)+15,"The poison enters your blood stream.");
  } else {
    targ->do_damage("torso",roll_dice(1,6));
  }
  return 1;
}
