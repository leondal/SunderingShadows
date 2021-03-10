#include <std.h>
inherit "/d/deku/inherits/ogre";

create() {
  ::create();
  set_id(({"ogre","ogre guard", "guard"}));
  set("short", "Ogre guard");
  new("/d/deku/weapons/spiked_club")->move(TO);
  command("wield club");
  add_money("gold",random(100)+100);
}
