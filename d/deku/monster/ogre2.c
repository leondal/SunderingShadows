#include <std.h>
inherit "/d/deku/inherits/ogre";

create() {
  ::create();
  set_id(({"ogre","ogre zombie", "zombie"}));
  set("race","undead");
  set("short", "Ogre zombie");
  set("long","This ogre is even more horrid looking than others, having been "
    "turned into an undead some evil source.");
  set_level(6);
  set_exp(400);
  set_hp(70);
  new("/d/common/obj/weapon/club")->move(TO);
  command("wield club");
  add_money("gold",random(50));
}
