#include <std.h>
inherit WEAPON;

void create() {
  ::create();
  set_name("dagger");
  set_id(({ "dagger", "demon dagger" }));
  set_short("A demon dagger");
  set_long(
"This long and jagged piece of metal looks rather demonic. You wonder if it\n"+
"lives up to it's name in fighting ability.");
  set_wc(1,4);
  set_weight(2);
  set_value(2500);
  set_type("slash");
  set_size(1);
}
