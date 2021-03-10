#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit ARMOUR;

void create(){
    ::create();
    set_name("Scale Helmet");
    set_short("Scale Helmet");
    set_id( ({"helm", "helmet", "scale helm", "scale helmet"}) );
    set_long(
      "This sickly blue helmet looks to have been covered with the scales of several unfortunate fish.  The helmet covers the head and curves around to cover the wearer's nose and mouth, leaving a strip to see out of, and a large fin sticks up off the top of the helmet.  The scales on the helmet seem to move in the light, especially the ones around the mouth."
    );
    set_weight(6);
    set_size(1+random(3));
    set_value(50);
    set_ac(0);
    set_property("enchantment", 1);
    set_type("armour");
    set_limbs( ({"head"}) );
    set_wear( (:TO, "extra_wear":) );
    set_remove( (:TO, "extra_remove":) );
}

int extra_wear(){
    tell_object(ETO, "%^BOLD%^%^BLUE%^You have trouble breathing when you put on the helmet.%^RESET%^");
    ETO->set_property("water breather", 1);
    return 1;
}

int extra_remove(){
    tell_object(ETO, "%^BOLD%^The fresh air tastes sweet as you remove the helment.");
    ETO->remove_property("water breather");
    return 1;
}
