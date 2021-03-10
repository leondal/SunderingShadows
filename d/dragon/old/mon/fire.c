#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("fire giant");
  set_id(({"fire giant","giant","Fire giant"}));
  set("race","giant");
  set("short","Fire giant");
set("long","This Fire giant is very broad, looking almost like a dwarf's.\n"+
             "His skin is coal black, hair is flaming red, and eyes are deep\n"+
              "red, with yellowish orange teeth.\n");
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
  set_hp(114);
  set_wielding_limbs(({"right hand","left hand"}));
  new("/d/deku/weapons/battle_axe")->move(this_object());
  command("wield axe in right hand");
  set("aggressive", 18);
  new("/d/deku/misc/stones")->move(this_object());
  new("/d/deku/misc/stones")->move(this_object());
  set_funcs(({"hurl"}));
  set_func_chance(20);
}

void hurl(object targ) {
  if(present("stone", this_object())) {
     tell_room(environment(targ), "%^GREEN%^The Fire giant hurls a large stone towards "+targ->query_cap_name()+"!%^RESET%^",targ);
    tell_object(targ, "%^BOLD%^The Fire giant hurls a large stone at you!");
    targ->do_damage("torso", roll_dice(2,10));
    return 1;
  }
}
