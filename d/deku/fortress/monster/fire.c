#include <std.h>
#include "/d/common/common.h"

inherit "/std/monster";

void create() {
  ::create();
  set_name("fire giant");
  set_id(({"fire giant","giant","Fire giant"}));
  set("race","giant");
  set("short","Fire giant");
  set("long","This Fire giant is very broad, looking almost like a HUGE dwarf.  "
      "His skin is coal black, hair is flaming red, and eyes are deep red.  "
      "Yellowish orange teeth jut out, adding to his wicked appearance.");
  set_gender("male");
  set_level(11);
  set_hd(11,5);
  set_body_type("human");
  set_class("fighter");
  set_size(3);
  set_alignment(2);
  set_stats("strength",22);
  set_stats("intelligence",10);
  set_stats("dexterity",11);
  set_stats("constitution", 14);
  set_overall_ac(4);
  set_hp(114);
  set_wielding_limbs(({"right hand","left hand"}));
	set_new_exp(10, "low");

//  new("/d/deku/weapons/battle_axe")->move(TO);
//  command("wield axe in right hand");
  RANDGEAR->arm_me(TO, "edgedm", 50, 1);
  RANDGEAR->arm_me(TO, "bluntm", 20, 1);
  set("aggressive", 18);
  new("/d/deku/misc/stones")->move(TO);
  new("/d/deku/misc/stones")->move(TO);
  add_money("gold",random(250)+50);
  set_funcs(({"hurl"}));
  set_func_chance(50);
  set_max_level(15);
}

void hurl(object targ) {
  int dam;
  int dex;
  dex = targ->query_stats("dexterity");
  if(present("stone", TO)) {
    if(dex > random(20)+10) {
      tell_room(environment(targ), "%^BOLD%^The Fire giant hurls a large "
        "stone towards "+targ->query_cap_name()+" but it misses!",targ);
      tell_object(targ, "%^BOLD%^The Fire giant hurls a large stone at you "
        "but you manage to dodge out of the way!");
      return 1;
    }
    tell_room(environment(targ), "%^BOLD%^%^RED%^The Fire giant hurls a large "
       "stone towards "+targ->query_cap_name()+"!",targ);
    tell_object(targ, "%^BOLD%^%^RED%^The Fire giant hurls a large stone at you!");
    dam = roll_dice(2,10);
    targ->do_damage("torso", dam);
    return 1;
  }
   set_func_chance(0);
}
