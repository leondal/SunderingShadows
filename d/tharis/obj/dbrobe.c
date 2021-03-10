//dbrobe.c

#include <std.h>

inherit PARMOUR;

void create(){
        ::create();
        set_name("Dirty brown robe");
        set_id(({"robe","robes","brown robes","dirty brown robes","mage robes"}));
        set_short("%^RESET%^%^ORANGE%^Dirty brown robes%^RESET%^");
        set_long(
@OLI
    These robes are made from a brown material. The thick material must
serve to keep the wearer warm, but also might offer some level of
protection. There is a small pocket in these robes you can store something
in. It looks like its specifically made for a book or a bag or something light.
OLI
        );
   set_property("enchantment",1);
        set_weight(5);
        set_value(300);
        set_type("clothing");
        set_limbs(({"torso"}));
        set_max_internal_encumbrance(21);
//        set_wear((:TO,"wear_stuff":));
}

int wear_stuff(){
       if(!TP->is_class("bard") && !TP->is_class("mage") ) {
                write("The magic within these robes prevents you from wearing them.");
                return 0;
        }
        return 1;
}

