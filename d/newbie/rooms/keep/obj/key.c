#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("skeleton key");
   set_id(({"key","skeleton key","keep master_key"}));
   set_short("%^BOLD%^%^WHITE%^a skeleton key%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a key made of old, dull iron. The end of the handle has been shaped into "
"a %^WHITE%^grinning skull%^BLACK%^.%^RESET%^");
   set_lore("This key bears a tiny marking near the base of the skull that labels it as belonging to the "
"abandoned Kilgore Keep just northeast of Offestry.  Once a grand place, the keep has now fallen into "
"disrepair at the hands of the strange creatures known as xvarts.");
   set_property("lore difficulty",3);
   set_weight(1);
   set_value(0);
}
