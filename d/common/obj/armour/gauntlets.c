//armor template
#include <std.h>

inherit ARMOUR;

void create()
{
     ::create();
     set_name("metal gauntlets");
     set_id(({ "gauntlets", "metal gauntlets" }));
     set_short("metal gauntlets");
     set_long("These gauntlets are fashioned from several small steel plates.  "
         "they form a set of bulky gloves that will protect the wearers hands and "
         "forarms.  The craftsmanship is rough as if they were created in haste.");
    set_weight(2);
    set_value(10);
    set_ac(1);
    set_size(2);
    set_type("armor");
    set_armor_prof("medium");
    set_limbs(({"left arm", "right arm"}));
}

int is_metal() { return 1; }
