#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("deep ogre");
  set_id(({"ogre","deep","deep ogre"}));
  set_gender("male");
  set_race("ogre");
  set_short("A deep ogre");
  set_long("He looks evil and very mad.");
  set("aggressive",18);
  set_alignment(7);
  set_hd(10,3);
  new("/d/common/obj/weapon/bardiche")->move(TO);
  command("wield bardiche");
  add_money("gold",random(100));
  set_hp(101);
  set_exp(900);
}
