#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("pantaloons");
  set_id(({"pants","pantaloons","puffy pantaloons"}));
   set_short("%^BOLD%^%^BLUE%^Puffy pantaloons%^RESET%^");
    set_long(
  "%^BOLD%^%^BLUE%^"
  "  Bright blue, these puffy  pants certainly stick out in any crowd."
  "  They're tightly cinched at the ankles so even though they balloon around the lower leg they dont interfere with movement."
    );
  set_value(65);
  set_type("clothing");
  set_limbs(({"left leg","right leg"}));
}
