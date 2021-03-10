#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "voulge","pole arm","polearm",
      }));
    set_name(
  "voulge"
    );
    set_short(
  "a stout voulge"
    );
    set_long(
  "  This looks like some deranged cook afixed a massive cleaver to a long thick pole to make a weapon capable of cleaving through armor."
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
  2,4
    );
    set_large_wc(
  2,4
    );
    set("read","Another fine newbie product from Amidon.\n");
}
