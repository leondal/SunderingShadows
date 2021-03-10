#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("%^BOLD%^%^YELLOW%^gold earring%^RESET%^");
set_id(({"earring","gold earring"}));
  set_short("%^BOLD%^%^YELLOW%^gold earring%^RESET%^");
    set_long(
  "%^BOLD%^%^YELLOW%^"
    "  A small hoop earring that looks like it's seen better days."
  "  A bit dented and battered, and at one point in time bitten it appears."
   "  It's still gold though and its hard to deny its beauty."
    );
  set_weight(2);
  set_value(25);
  set_type("ring");
  set_limbs(({"head"}));
}
