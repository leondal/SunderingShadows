#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("signet ring");
   set_short("%^RESET%^a tarnished signet ring%^RESET%^");
   set_id(({"ring","tarnished ring","tarnished silver ring","myringz"}));
   set_long("%^BOLD%^%^BLACK%^Dull %^RESET%^and rather plain, this ring isn't exactly eye-catching.  It seems "
"to be made of %^BOLD%^%^WHITE%^silver%^RESET%^, although it is terribly weathered and tarnished around the "
"outside.  Only one marking interrupts its smooth surface, of what appears to be a glyph or letter of some "
"sort.\n");
   set("read","\n\n%^ORANGE%^-obey-%^RESET%^");
   set_language("drow");
   set_weight(1);
   set_value(0);
   set_limbs(({"right hand"}));
   set_type("ring");
   set_size(2);
}
