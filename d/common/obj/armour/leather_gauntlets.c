//armor template
#include <std.h>

inherit ARMOUR;

void create()
{
     ::create();
     set_name("leather gauntlets");
     set_id(({ "gauntlets", "leather gauntlets" }));
     set_short("leather gauntlets");
     set_long("These gauntlets are fashioned from hardened lengths of leather stitched "
         "onto a softer leather lining.  They form heavy gloves that would protect "
         "the wearer's hands and forarms.  They are rough quality as if they were "
         "crafted in haste.");
    set_weight(2);
    set_value(10);
    set_ac(1);
    set_size(2);
    set_type("leather");
    set_armor_prof("light");
    set_limbs(({"left arm", "right arm"}));
}

int is_metal() { return 0; }