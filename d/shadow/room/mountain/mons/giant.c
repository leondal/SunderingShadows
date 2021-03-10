//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#define RANDGEAR "/d/common/daemon/randgear_d"

inherit MONSTER;

void create() {
  ::create();
  set_name("mountain giant");
  set_id(({"giant","mountain giant"}));
  set_race("giant");
  set_gender("male");
  set_short("Mountain giant");
  set_long("This huge, barbaric looking humanoid is about 14 ft. tall with legs that remind you of small tree trunks.  You might guess he weighs close to 2,000 lbs. with his broad shoulders, bulging muscles, and pot belly.  His black scraggly hair and beard is long and tangled.  He reeks like he hasn't bathed in months.");
  set_level(8);
  set_ac(3);
  set("aggressive",18);
  set_size(3);
  set_body_type("human");
  set_class("fighter");
  set_alignment(6);
  set_monster_feats(({"parry"}));
  set_hd(8,2);
  set_stats("strength",20);
  set_wielding_limbs(({"right hand","left hand"}));
  set_hp(91);
//  set_exp(900);
  set_new_exp("normal",8);
  switch(random(5)) {
    case 0:  RANDGEAR->arm_me(TO, "edgedl", 20, 1);     break;
    case 1:  RANDGEAR->arm_me(TO, "bluntl", 20, 1);     break;
    case 2:  RANDGEAR->arm_me(TO, "polearm", 20, 1);    break;
    case 3:  RANDGEAR->arm_me(TO, "blunts", 20, 1);  // I meant to not break here
    case 4:  RANDGEAR->arm_me(TO, "clubm", 20, 1);    break;
  } 
  add_money("gold", random(200)+50);
  set_funcs(({"hurl"}));
  set_func_chance(20);
  new("/d/deku/misc/stones")->move(TO);
}

void hurl(object targ) {
  int dam;
  int dex;
  dex = targ->query_stats("dexterity");
  if(present("stone", TO)) {
    if(dex > random(20)) {
      tell_room(environment(targ), "%^ORANGE%^The Mountain giant hurls a large "
        "stone towards "+targ->query_cap_name()+" but it misses!",targ);
      tell_object(targ, "%^ORANGE%^The Mountain giant hurls a large stone at you "
        "but you manage to dodge out of the way!");
      return 1;
    }
    tell_room(environment(targ), "%^MAGENTA%^The Mountain giant hurls a large stone towards "+targ->query_cap_name()+"!",targ);
    tell_object(targ, "%^MAGENTA%^The Mountain giant hurls a large stone at you!");
    dam = roll_dice(2,10);
    targ->do_damage("torso", dam);
    return 1;
  }
}
