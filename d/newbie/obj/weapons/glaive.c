#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "sharp glaive","a sharp glaive",
  "pole arm","polearm",
  "glaive",
      }));
    set_name(
  "glaive"
    );
    set_short(
  "a sharp glaive"
    );
    set_long(
  "  This weapon consists of a huge, single edged knifeblade on a long pole."
  "  Looks like you could certainly get a bit of leverage into any cutting blow."
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
  1,6
    );
    set_large_wc(
  1,8
    );
    set("read","Another fine newbie product from Amidon.\n");
}
