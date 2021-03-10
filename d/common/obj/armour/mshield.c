//updated by ~Circe~ 5/6/11 to more current code and better description
#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("medium shield");
    set_id(({"shield","medium shield","medium","mshield"}));
    set_short("A medium shield");
    set_long("This shield has been fashioned by bending a layer of metal around "
        "a wooden frame in a circular shape.  The frame has straps for the wearer "
        "to loop around the arm in the back.");
    set_weight(8);
    set_value(7);
    set_type("shield");
    set_limbs(({"right hand"}));
    set_ac(1);
    set_armor_prof("shield");
    set_block_chance(25);
    set_item_bonus("shieldMiss",25); // setting these equal to the old block chance since it's a replacement
}

int is_metal() { return 1; }
