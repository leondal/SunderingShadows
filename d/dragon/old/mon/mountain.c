#include <std.h>

inherit "/std/monster";

create() {
  ::create();
  set_name("mountain giant");
  set_id(({"giant","mountain giant"}));
  set("race", "giant");
  set_gender("male");
  set("short", "Mountain giant");
  set("long","This large creature is about 10 feet in height.  This\n"+
             "creature resides within the Echoes Mountains");
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
  new("/d/deku/weapons/axe")->move(this_object());
  command("wield axe in right hand");
  add_money("gold", random(500));
  set_funcs(({"hurl"}));
  set_func_chance(50);
  new("/d/deku/misc/stones")->move(this_object());
}

void hurl(object targ) {
  int dam;
  if(present("stone", this_object())) {
    tell_room(environment(targ), "%^MAGENTA%^The Mountain giant hurls a large stone towards "+targ->query_cap_name()+"!",targ);
    tell_object(targ, "%^BOLD%^The Mountain giant hurls a large stone at you!");
    dam = roll_dice(2,10);
    targ->do_damage("torso", dam);
    return 1;
  }
}
