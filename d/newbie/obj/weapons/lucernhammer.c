#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "hammer","lucern hammer","pole arm","polearm",
      }));
    set_name(
  "lucern hammer"
    );
    set_short(
  "Lucern hammer"
    );
    set_long(
  "  This pole arm has a longe spear tip with a three pronged sharpened hammer jutting from one side and a spike counterbalance on the other."
  "  It looks a good weapon for smashing through armor."
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
  2,4
    );
    set_large_wc(
  1,6
    );
    set("read","Another fine newbie product from Amidon.\n");
}
