#include <std.h>
inherit "/d/shadow/room/mountain/mons/ogre";

create() {
  ::create();
  set_id(({"ogre","ogreX"}));
  set("short", "Ogre");
  set_level(7);
  set_exp(450);
  set_hp(75);
    new("/d/deku/weapons/spiked_club")->move(TO);
    command("wield club");
  add_money("gold",random(50));
}
