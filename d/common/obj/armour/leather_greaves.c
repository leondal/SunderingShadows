//armor template
#include <std.h>

inherit ARMOUR;

void create(){
     ::create();
     set_name("leather greaves");
     set_id(({ "greaves", "leather greaves" }));
     set_short("leather greaves");
     set_long("These greaves are formed from several hardened leather plates stitched onto "
         "a softer leather lining.  They are light enough to offer little restriction to "
         "movement and will offer limited protection to the shins and calves.  They are "
         "of rough quality as if they were crafted in haste.");
    set_weight(2);
    set_value(20);
    set_ac(1);
    set_size(2);
    set_type("leather");
    set_armor_prof("light");
    set_limbs(({ "left leg", "right leg" }));
}

int is_metal() { return 0; }