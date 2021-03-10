#include <std.h>
#include <daemons.h>
inherit WEAPON;

int my_weight;

void create() {
	::create();
      "/d/common/daemon/bane_rweap_d.c"->create_weapon(TO);
}

set_weight(int x) {
   ::set_weight(x);
   my_weight = x;
}

query_weight() {
   return my_weight;
}
