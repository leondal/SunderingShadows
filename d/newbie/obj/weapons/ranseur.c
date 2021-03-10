#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "ranseur","polearm","pole arm",
      }));
    set_name(
  "ranseur"
    );
    set_short(
  "Ranseur"
    );
    set_long(
  "  The spear head on this polearm catches your attention right off when looking at it"
  "  Just behind the straight arrow shaped blade are backward pointing hooked projections capable of disarming an oppenent if his weapon gets caught in them."
    );
    set_size(3);
    set_weight(10);
    set_value(10);
    set_type(
  "piercing"
    );
    set_prof_type(
      "polearm"
    );
    set_weapon_speed(8);
    set_wc(
  1,6
    );
    set_large_wc(
  1,6
    );
    set("read","Another fine newbie product from Amidon.\n");
}
