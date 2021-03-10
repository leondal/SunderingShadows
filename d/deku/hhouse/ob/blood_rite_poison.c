#include <std.h>
#include <magic.h>
#include "/d/common/obj/poisons/poison.h"
inherit POISON_INH;

void create()
{
    ::create();
    add_id(({"arag dyne ritual poison"}));	
    set_poison_dc(800);
    set_poison_effect_type(({"strength", "constitution", "dexterity", "wisdom", "intelligence", "charisma"}));
    set_poison_name("arag dyne ritual poison");
    set_poison_dice( ({2}) );
    set_save_allowed(0);
    set_duration(10000);
    set_delay(2);
    set_poison_num_dice( ({3}) );
    set_delivery_method("injury");
    set_poison_base_value(100);
    set_number_of_effects(6);
}
