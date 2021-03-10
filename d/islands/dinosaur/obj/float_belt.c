#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_property("magic", 1);
    set_name("belt of floating");
    set_short("%^BLUE%^A faded blue belt.");
    set_id( ({"belt", "faded belt", "blue belt"}) );
    set_long(
      "This old faded blue belt looks to have spent a lot of time in the water.  The leather is not very cracked, but just has that waterlogged look.  As you inspect the belt you can barely make out shell and bubble designes etched into the leather."
    );
    set_weight(5);
    set_value(2);
    set_type("clothing");
    set_limbs( ({"waist"}) );
    set_ac(0);
    set_wear( (:TO, "wearme":) );
    set_remove( (:TO, "removeme":) );
}

int wearme(){
    TP->set_property("floats", 1);
    tell_object(TP, "%^BLUE%^%^BOLD%^You feel the tickle of bubbles against you where you wear the belt.");
    return 1;
}

int removeme(){
    TP->remove_property("floats");
     tell_object(TP, "You feel heavier as you remove the belt.");
    return 1;
}

void init(){
    ::init();
    if(environment(TO) == TP) set_size(TP->query_size());
}
