//bandoleer.c - Just an altered large pouch to give new RP options
//Circe 9/9/04
#include <std.h>
inherit PARMOUR;

void create() {
    ::create();
    set_id(({"bandoleer","pouch","leather bandoleer"}));
    set_name("bandoleer");
    set_short("leather bandoleer");
    set_long("This unique storage device consists of a leather "+
       "belt fitted with various straps and pouches to hold small "+
       "items.  The pouches have flaps that buckle, allowing "+
       "items up to about dagger size to be stored without being "+
       "lost - even if one is, say, climbing upside down!  The "+
       "bandoleer can be cinched around the waist or thrown across "+
       "the chest depending on which is more convenient at the time.");
    set_value(8);
    set_weight(3);
    set_max_internal_encumbrance(8);
    set_limbs(({"waist"}));
    set_type("clothing");
    set_property("repairtype",({ "leatherwork","tailor" }));
}
int query_size(){
    if(!objectp(ETO)) return 2;
    return ETO->query_size();
}
