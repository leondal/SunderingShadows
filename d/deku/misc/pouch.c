#include <std.h>
inherit PARMOUR;

void create() {
    ::create();
    set_id( ({"pouch"}) );
    set_name("large pouch");
    set("short", "A large belt pouch");
    set_weight(3);
    set("long", "This is a leather pouch you wear on a belt. You could put things in.\n");
    set_value(1);
    set_max_internal_encumbrance(8);
   set_limbs(({"waist"}));
   set_type("clothing");
}
int get_size(){
    if(!objectp(TP)) return 2;
    return TP->query_size();
}
