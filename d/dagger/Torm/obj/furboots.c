#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("fur boots");
  set_id(({"boots","fur boots"}));
  set_short("fur boots");
    set_long(
  "  These low soft boots are made from a fine pelt and look like they're worth a fair bit."
  "  They're extremly large though and you doubt anyone but a giant could wear them."
    );
  set_weight(10);
  set_value(100);
    set_type("clothing");
  set_limbs(({"left foot","right foot"}));
  set_size(3);
}
