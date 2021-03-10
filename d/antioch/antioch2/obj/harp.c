#include <std.h>
inherit "/d/common/obj/instruments/lap-harp";

void create()
{
   ::create();
   set_name("harp");
   set_short("%^RESET%^%^ORANGE%^A bronze harp%^RESET%^");
   set_id(({"harp","bronze harp","instrument"}));
   set_long("This is a lovely harp made out of bronze. It is small enough"+
   " to carry around in a bag, but must be set on the ground to be played."+
   " The strings are taut and carefully tuned.");
   set_value(1000);
}

