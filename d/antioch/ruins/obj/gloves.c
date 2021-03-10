#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/clothing/gloves";

void create()
{
    ::create();
    set_name("Gloves of Darkness");
    set_short("%^BOLD%^%^BLACK%^Gloves of Darkness%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^A pair of black leather gloves%^RESET%^");
    set_id(({ "gloves", "gloves of darkness", "Gloves of Darkness" }));
    set_long(
        "These gloves have been made from the supple hide of a selkie. They have" +
        " been dyed a dark black, and are ever so soft to the touch. They are thin" +
        " and excellently made."
        );
    set_lore("A creation from the stealthy thieves of Mask the " +
             "gloves of darkness are said to bring the comfort of " +
             "the shadows to those who wear them.  The leather gloves" +
             " are crafted from the hides of selkies, which is then " +
             "dyed black.  The gloves are a favorite among followers " +
             "of Shar and Mask for they give the feeling of being " +
             "protected by the darkness.  Some rogues claim that the" +
             " gloves are mutable in nature, allowing them to use the" +
             " fingers of the gloves to open locks.");
    set_property("lore", 17);
    set_weight(4);
    set_value(2500);
    set_type("clothing");
    set_property("enchantment", 3);
    set_item_bonus("dungeoneering", 2);
    set_ac(0);
    set_property("picking tool", 20);
    set_wear((: TO, "wearme" :));
    set_remove((: TO, "removeme" :));
}

int wearme()
{
    if (ALIGN->is_good(ETO)) {
        tell_object(ETO, "You can't bring yourself to wear the evil gloves.");
        return 0;
    }
    if (ETO->query_property("good item")) {
        tell_object(ETO, "The gloves refused to be worn while you are using such goodly items!");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^BLACK%^The gloves fit perfectly, you can hardly feel that they're there.");
    ETO->set_property("evil item", 1);
    return 1;
}

int removeme()
{
    tell_object(ETO, "%^MAGENTA%^You slowly remove your hands from the dark safety of the gloves.");
    ETO->set_property("evil item", -1);
    return 1;
}
