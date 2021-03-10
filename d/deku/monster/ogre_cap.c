#include <std.h>
inherit "/d/deku/inherits/ogre";

create() {
  ::create();
  set_id(({"ogre","captain","ogre captain"}));
  set("short", "Ogre captain");
      set("long", "This ogre is even bigger and more savage-looking than the "
          "others.  He looks extremely evil and on a rampage.");
  set("aggressive",30);
  set_hd(12,2);
  new("/d/deku/weapons/battle_axe")->move(TO);
  command("wield axe");
  new("/d/deku/armours/hide")->move(TO);
  command("wear hide");
  set_exp(1100);
  set_hp(90);
  add_money("gold",random(300));
  if(!random(4))   "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"kit");
}
