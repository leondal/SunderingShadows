#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "guisarme","voulge","pole arm","polearm",
  "guisarme-voulge"
      }));
    set_name(
  "guisarme-voulge"
    );
    set_short(
  "a guisarme-voulge"
    );
    set_long(
  "This heavy bladed polearm looks designed to delive powerfull cleaving blows to opponents after dismounting them with the hook on the back of the axeblade."
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
