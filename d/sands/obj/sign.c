#include <std.h>
inherit OBJECT;

void create() {
  ::create();
  set_name("sign");
  set_id(({ "sign" }));
  set_short("A sign");
  set_long(
"The sign reads:\n"+
"Caution. That first trap was only a warning. The rest are very real. The\n"+
"best way to avoid them is to simply be smart about them. Simply <check>ing\n"+
"before acting can save your life in some cases. Trapped items may be\n"+
"<disarm>ed sometimes.\n"+
"     -Tebryn");
  set_weight(0);
  set_value(0);
}

get() {return 0;}
