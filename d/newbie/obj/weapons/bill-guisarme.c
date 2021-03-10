#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({
  "bill-guisarme","bill guisarme","pole arm","polearm","bill","guisarme",
      }));
    set_name(
  "bill-guisarme"
    );
    set_short(
  "bill-guisarme"
    );
    set_long(
  "  This is a very multi purpose polearm."
  "  This pretty much looks like it could peel an armorer opponent out of his armor after dragging him off his horse with the large hook that forms the body of the head."
  "  Its long spear point would be usefull for keeping things at bay on the long pole."
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
  1,10
    );
    set("read","Another fine newbie product from Amidon.\n");
}
