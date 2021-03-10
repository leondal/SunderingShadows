#include <std.h>
inherit "/d/common/obj/armour/leather";

void create() {
    ::create();
    set_name("leather armor");
    add_id("striped leather armor");
    add_id("striped leather");
    set_short("%^WHITE%^A suit of leather armor with %^BOLD%^%^BLUE%^blue %^RESET%^%^WHITE%^and %^BOLD%^%^YELLOW%^yellow %^BLUE%^s%^YELLOW%^t%^BLUE%^r%^YELLOW%^i%^BLUE%^p%^YELLOW%^e%^BLUE%^s");
    set_long(
@AZHA
This is an old and well-broken in set of leather armor decorated with 
blue and yellow diagonal striping.  On the upper left of the armor, over 
the heart, is a metallic crescent moon, the Imperial symbol of Tsarven. 
Since no Imperial soldier would be found with such mediocre equipment, 
you must assume that this belonged to a town policeman or watchman.
AZHA
    );
    set_weight(15);
    set("value", 5);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(2);
}
