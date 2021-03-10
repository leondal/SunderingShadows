#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
	"bardiche","polearm","pole axe","axe",
      }));
    set_name(
      "bardiche"
    );
    set_short(
      "A nasty looking bardiche"
    );
    set_long(
      "The massive blade on this axe makes you shudder, as its only purpose could be war."
   "  Just over two feet of razor sharpened steel are connected to a five foot handle with two steel rings."
    );
    set_size(
      3
    );
    set_weight(
      12
    );
    set_value(
      7
    );
    set_type(
      "slashing"
    );
    set_prof_type(
      "large axe"
    );
    set_weapon_speed(
      8);
set_wc(
  2,4
);
set_large_wc(
  2,6
);
set("read","Another fine newbie product from Amidon.\n");
}
