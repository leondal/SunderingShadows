#include <std.h>
inherit POTION;

void create() {
    ::create();
set_short("A vial containing a pale blue liquid");
    set_long("The pale blue liquid is viscous and cool to the touch.");
    set("color", "blue");
    set("effect_time", (random(4) * 60));
}
int do_effect() {
    tell_object(drinker, "The potion seems to cool your body.");
 drinker->add_hp(roll_dice(2,4)+2);
    return 1;
}
int do_wear_off() {
}
