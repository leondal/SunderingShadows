#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("fur hat");

  set_id(({"fur hat","hat"}));
  set_short("fur hat");
    set_long(
   "  This heavy fur hat is soft to the touch and looks very warm."
   "  There are flaps that can come down to cover your ears and a you couldn't think of anything you'd rather have on a cold night in the wilds."
    );
  set_weight(10);
  set_value(100);
    set_type("clothing");
   set_limbs(({"head"}));
  set_size(roll_dice(1,3));
}
