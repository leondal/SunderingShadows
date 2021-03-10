#include <std.h>
inherit "/d/common/obj/armour/leather";

void create() {
    ::create();
    set_name("leather");
    set_id(({"leather","leather armor", "armor","white leather"}));
    set("short", "White leather armor");
    set("long", 
	"This armor is made of leather, hardened in boiling oil and then "
	"shaped into breastplate and shoulder protectors. The rest of the "
	"suit is made of softer, more flexible materials.  It is stained "
	"completely white somehow."
       );
    set("value", 5);
}
