//glassmedallion.c
#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_id( ({"medallion","cave medallion","glass medallion"}) );
    set_name("glass cave medallion");
    set_short("%^CYAN%^A glass medallion%^RESET%^");
    set_weight(0);
    set_long("This unusual medallion is crafted entirely of glass.  "+
      "The seemingly delicate chain is made of spun glass links "+
      "that are surprisingly strong.  The medallion itself is "+
      "completely smooth to the touch, though inside it is carved with "+
      "a breath-taking starburst that catches the light.  Dancing inside "+
      "is a faint message.");
    set("read",
      "Smooth and shimmering my companions must be.");
    set_value(0);
    set_ac(0);
    set_limbs(({"neck"}));
    set_type("ring");
}

