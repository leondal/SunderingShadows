#include <std.h>
inherit "/d/common/obj/clothing/breeches";

void create(){
    ::create();
    set_name("linen Pants");
    set_id(({"pants", "linen pants"}));
    set_short("%^BOLD%^%^WHITE%^Diving Pants");
    set_obvious_short("%^BOLD%^%^WHITE%^White Linen Pants%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This is a fine set of pants made from white linen. They are crafted from good quality fabric and are %^BOLD%^%^CYAN%^soft%^WHITE%^ and" 
        " %^MAGENTA%^light%^WHITE%^ to the touch. They are probably worn in %^RESET%^%^ORANGE%^warmer climates%^BOLD%^%^WHITE%^. There is a single %^BOLD%^%^BLUE%^blue%^WHITE%^"
        " stripe traveling down the outer side of each pant leg. The stripe tapers at the end of the pants cuff, which is stitched together with" 
        " %^YELLOW%^golden%^WHITE%^ threads.\n");
    set_lore("These pants were supposedly crafted for a Fire Magi who was tired of traveling after his nemesis an Isthishian priestess in the open seas. She would always escape"
        " by diving into the water and swimming away. These pants helped him correct that situation or so he thought. The priestess was thrilled to see the Fire Magi" 
        " dive into the water as she communed with the nearby sharks.");
    set_weight(2);
    set_size(-1);
    set_value(1000);
    set_property("enchantment",4);
    set_item_bonus("cold resistance", 25);
    set_item_bonus("fire resistance",25);
    set_remove( (: TO,"rem_pants" :) );
    set_wear( (: TO,"wear_pants" :) );
}

int wear_pants(){
    tell_object(ETO,"%^BOLD%^%^BLUE%^You feel like each molecule of %^CYAN%^air%^BLUE%^ is more invigorating somehow.%^RESET%^");
    ETO->set_property("water breather", 1);
    return 1;
  
}


int rem_pants(){
    tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the %^CYAN%^air%^BLUE%^ return to normal.%^RESET%^");
    ETO->set_property("water breather", -1);
    return 1;
}
