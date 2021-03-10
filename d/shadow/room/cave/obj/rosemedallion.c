//rosemedallion.c
#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_id( ({"medallion","cave medallion","rose medallion","rose cave medallion"}) );
    set_name("rose cave medallion");
    set_short("%^BOLD%^%^MAGENTA%^A rose medallion%^RESET%^");
    set_weight(0);
    set_long("A perfect pink rose has been somehow preserved and "+
      "made into this medallion.  The white cording is made of soft "+
      "wool that has been braided and looped around the rose.  Peeling "+
      "back the outer petals, a message waits inside.");
    set("read",
      "Strong as the earth and natural as the wind are my colleagues.");
    set_value(0);
    set_ac(0);
    set_type("ring");
    set_limbs(({"neck"}));
}

