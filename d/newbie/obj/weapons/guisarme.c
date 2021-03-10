#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "guisarme","pole arm","polearm",
      }));
    set_name(
  "guisarme"
    );
    set_short(
  "Gruesome looking guisarme"
    );
    set_long(
  "This weapon looks like a pruning hook thats been pressed into service as a moderatly effective polearm."
  "  It doesnt have a spear point though, only the inside of the sharpened curved hook to inflict damage."
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
  1,8
    );
    set("read","Another fine newbie product from Amidon.\n");
}
