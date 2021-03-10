#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "heavy halberd",
  "pole axe","halberd","pole arm","polearm",
      }));
    set_name(
  "halberd"
    );
    set_short(
  "heavy halberd"
    );
    set_long(
  "  This 8ft long pole axe looks very menacing and effective."
  "  Its convex axe blade is set at the perfect angle for cutting into someone before he could get to close."
  "  Its topped by a long spearhead and backed with a curved spike."
    );
    set_size(3);
    set_weight(10);
    set_value(10);
    set_type(
  "slashing"
    );
    set_prof_type(
      "polearm"
    );
    set_weapon_speed(8);
    set_wc(
  1,10
    );
    set_large_wc(
  3,6
    );
    set("read","Another fine newbie product from Amidon.\n");
}
