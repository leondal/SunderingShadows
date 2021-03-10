#include <std.h>

inherit WEAPON;

void create(){
    ::create();
   set_id(({"guisarme","pole arm","polearm"}));
   set_name("guisarme");
   set_short("A gruesome looking guisarme");
    set_long(
   "This weapon looks like a pruning hook that's been pressed into service as a moderately effective polearm."
   "  It doesn't have a spear point however, just the inside of the sharpened curved hook to inflict damage."
    );
    set_size(3);
    set_weight(10);
    set_value(10);
   set_type("slash");
   set_prof_type("polearm");
    set_weapon_speed(8);
   set_wc(2,4);
   set_large_wc(1,8);
}
