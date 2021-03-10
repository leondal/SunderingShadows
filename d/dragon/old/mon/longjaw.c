#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("pirate");
  set_id(({"pirate","longjaw","longjaw pete"}));
  set_short("Longjaw Pete");
  set_long("
Longjaw Pete is a dapper-looking pirate.  He does have an abnormally long
jaw, with a scar on one cheek.  He keeps his hair in a long mohawk and
wears a golden ring in his right ear.  He has dancing blue eyes and is
very unpleasant.");
  set_race("human");
  set_gender("male");
  set_hd(17,6);
  set_size(2);
  set_class("thief");
  set_guild_level("thief",16);
  set_max_hp(175);
  set_hp(175);
  set_wielding_limbs(({"right hand","left hand"}));
  set_body_type("humanoid");
  set_property("no_bump",1);
  set_stats("strength", 19);
  set_stats("dexterity", 19);
  set_stats("constitution", 15);
  set_stats("intelligence", 14);
  set_stats("wisdom", 14);
  set_thief_skill("move silently",95);
  set_thief_skill("hide in shadows",95);
  add_search_path( "cmds/thief" );
  set("aggressive","aggfunc");
  set_mob_magic_resistance("average");
  set_exp(5500);
  set_alignment(5);
  set_emotes(15, ({
    "Longjaw says: How dare thee enter my private quarters!",
    "Longjaw says: So you are after my buried treasure, ya bastard!",
    "Longjaw says: Die ye bastard!"}),1);
    new("/d/shadow/obj/weapon/khopesh")->move(TO);
  command("wield khopesh in right hand");
    new("/d/shadow/obj/weapon/dagger")->move(TO);
  command("wield dagger in left hand");
  new( "/d/dragon/obj/armor/leather" )->move(this_object());
  command("wear leather");
  set_invis();
  set_overall_ac(-1);
  set_funcs(({"dart"}));
  set_func_chance(25);
}

void aggfunc() {
  if(this_player()->query_invis()) {
    command("say You dare to enter my quarters invisible!");
    call_out("stab",1,this_player());
  } else {
    command("say How dare you, now you must die!");
    call_out("stab",1,this_player());
  }
}

void stab(object targ) {
  command("stab "+targ->query_name());
  set_invis();
}

void dart(object targ) {
  string dam;
  if("daemon/saving_d"->saving_throw(targ,"poison")) {
    dam="hurts";
  } else {
    dam="poisons";
  }
  tell_object(targ,"Longjaw throws a small dart towards you. It "+dam+" you.");
   tell_room(environment(targ),"Longjaw throws a dart towards "+targ->query_cap_name()+"!",targ);
  if(dam == "poisons") {
    targ->do_damage("torso",roll_dice(3,6));
    targ->set_paralyzed(random(10)+15,"The poison enters your blood stream.");
  } else {
    targ->do_damage("torso",roll_dice(1,6));
  }
  return 1;
}
