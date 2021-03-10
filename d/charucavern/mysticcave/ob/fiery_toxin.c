#include <std.h>
#include <magic.h>
#include "/d/common/obj/poisons/poison.h"
inherit POISON_INH;

void create()
{
    ::create();
    add_id(({"fiery toxin"}));	
    set_poison_dc(17);
    set_poison_effect_type(({"life", "constitution"}));
    set_poison_name("fiery toxin");
    set_poison_dice( ({1, 1}) );
    set_save_allowed(1);
    set_delay(1);
    set_poison_num_dice( ({10, 4}) );
    set_delivery_method("contact");
}
