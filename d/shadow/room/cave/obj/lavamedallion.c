//lavamedallion.c
#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_id( ({"medallion","cave medallion","lava medallion"}) );
    set_name("lava cave medallion");
    set_short("%^BOLD%^%^RED%^A lava medallion%^RESET%^");
    set_weight(0);
    set_long("Heat rises from this medallion of lava bound within "+
      "a transparent sphere.  The sphere does not seem to be made of "+
      "glass - it is almost as if magic itself holds the lava at "+
      "bay.  The molten red and black rocks shifts and churns, "+
      "burning a message into your memory.");
    set("read",
      "Boundless energy binds my friends to me.");
    set_value(0);
    set_ac(0);
    set_type("ring");
    set_limbs(({"neck"}));
}

