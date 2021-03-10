#include <std.h>

inherit WEAPON;

void create(){
    ::create();
   set_id(({"pole arm","polearm","spetum"}));
   set_name("spetum");
   set_short("A spetum");
    set_long(
   "This is a long polearm with a long, heavy spear point that splits into two forward curving spikes at its base."
    );
    set_size(3);
    set_weight(10);
    set_value(10);
   set_type("piercing");
   set_prof_type("polearm");
   set_weapon_speed(8);
   set_wc(1,6);
   set_large_wc(2,6);
}
