#include <std.h>
#define RANDGEAR "/d/common/daemon/randgear_d"

inherit "/std/monster";

create() {
  ::create();
  set_name("mountain giant");
  set_id(({"giant","mountain giant"}));
  set("race", "giant");
  set_gender("male");
  set("short", "Mountain giant");
  set("long","This huge, barbaric looking humanoid is about 14 ft. tall with legs that remind you of small tree trunks.  You might guess he weighs close to 2,000 lbs. with his broad shoulders, bulging muscles, and pot belly.  His black scraggly hair and beard is long and tangled.  He reeks like he hasn't bathed in months.");
  set_level(8);
  set_ac(3);
  set("aggressive",18);
  set_size(3);
  set_body_type("giant");
  set_class("fighter");
  set_alignment(6);
  set_hd(8,2);
  set_stats("strength",21);
  set_sp(query_max_sp(100));
  set_mp(query_max_mp(100));
  set_wielding_limbs(({"right hand","left hand"}));
  set_hp(91);
  switch(random(3)) {
    case 0: RANDGEAR->arm_me(TO, "bluntl", 10, 1);            break;
    case 1: new("/d/deku/weapons/club")->move(TO);
            command("wield club");
    case 2: new("/d/deku/weapons/club")->move(TO);
            command("wield club");                        break;
  }
  add_money("gold", random(500));
  set_funcs(({"hurl"}));
  set_func_chance(50);
  new("/d/deku/misc/stones")->move(TO);
}

void hurl(object targ) {
  int dam;
  int dex;
  dex = targ->query_stats("dexterity");
  if(present("stone", TO)) {
    if(dex > random(20)+10) {
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
  set_func_chance(0);
}
