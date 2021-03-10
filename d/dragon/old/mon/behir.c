#include <std.h>
#include <daemons.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("behir");
  set_id(({"behir","snake-like reptile","magical beast"}));
  set_race("behir");
  set_gender("male");
  set("short","Snake-like reptile");
  set("long","A behir is a snake-like reptilian monster with a dozen legs\n"+
             "that allow it to move with considerable speed and climb well.\n"+
              "The color of this monster is an aquamarine blue with bands of\n"+
             "gray-brown.  The belly is pale blue.");
  set_level(12);
  set_hd(12,7);
  set_body_type("snake");
  set_class("fighter");
  set_size(3);
  set("aggressive", 18);
    set_guild_level("fighter", 9);
  set_alignment(5);
  set_stats("strength", 23);
  set_stats("intelligence", 7);
  set_overall_ac(3);
  set_funcs(({"stroke","squeeze"}));
  set_func_chance(80);
  set_exp(2800);
  set_hp(159);
}

void squeeze(object targ) {
  int i;
   tell_room(environment(targ), "%^BOLD%^%^GREEN%^The behir loops his body around "+targ->query_cap_name()+" and squeezes.",targ);
   tell_object(targ,"%^BOLD%^%^GREEN%^The behir loops his body around you and squeezes.");
  targ->do_domage("torso", random(8));
  targ->set_paralyzed(7);
  tell_object(targ, "\n%^GREEN%^You cannot move, and are subjected to 6 talon attacks.\n");
  add_limb("first right talon","torso",20,20,10);
  add_limb("second right talon","torso",20,20,10);
  add_limb("third right talon","torso",20,20,10);
  add_limb("first left talon","torso",20,20,10);
  add_limb("second left talon","torso",20,20,10);
  add_limb("third left talon","torso",20,20,10);
  set_wielding_limbs(({"first right talon","second right talon","third right talon","first left talon","second left talon","third left talon"}));
  set_func_chance(0);
  for(i=0;i<6;i++) {
    this_object()->execute_attack();
  }
  set_func_chance(60);
  set_funcs(({"stroke"}));
  return 1;
}


void stroke(object targ) {
  int damage;
  if(((string)targ->query_property("strength") == "breath weapon")) {
    tell_object(targ, "%^RED%^Behir discharges a 20-foot long stroke of electrical energy at you, but it stops short!!");
    tell_room(environment(targ), "%^GREEN%^Behir discharges a 20-foot long stroke of electrical energy towards "+targ->query_cap_name()+" and it seems to stop short.", targ);
  } else{
    tell_object(targ, "%^RED%^Behir discharges a 20-foot long stroke of electrical energy towards you!!");
    tell_object(targ, "%^RED%^You begin to shake radically and fall upon the ground.");
    targ->set_paralyzed(7);
    tell_room(environment(targ), "%^GREEN%^Behir discharges a 20-foot long stroke of electrical energy towards "+targ->query_cap_name()+"!!",targ);
    damage = 24;
    if(SAVING_D->saving_throw(targ, "breath_weapon"))
      damage /= 2;
    targ->do_damage("torso", damage);
  }
}

void die(object ob) {
  object obj;
  message("environment","%^GREEN%^As the Behir begins to die he releases a long strong errie sound!",environment(TO));
  obj = new(OBJECT);
  obj->set_name("golden key");
  obj->set_id(({"golden key","key","dsewer_key"}));
  obj->set_short("A golden key");
  obj->set_long("This is an unused golden key, shaped like an old skull key.");
  obj->move(TO);
  ::die(ob);
}

void init() {
  ::init();
  if(avatarp(TP)) return;
  kill_ob(TP, 1);
}
