#include <std.h>
#include "../dragon.h";

inherit OBJECT;

void create() {
   ::create();
   set_name("journal");
   set_id(({"journal"}));
   set_short("%^RESET%^%^RED%^A small journal%^RESET%^");
   set_value(0);
   set_weight(0);
   set_long(
   "%^RESET%^%^GREEN%^You scan over the journal and pick out an excerpt:\n"+
   "%^BOLD%^%^GREEN%^Auica is running a home, not a mage tower"+
   " There are obvious students she has purposely overlooked in"+
   " order to promote her own children. I do admit myself, her"+
   " children show promise. However, there are others much better"+
   " than them. I would have taken over this tower long ago if it"+
   " were not for the delicate %^BOLD%^%^BLACK%^Monolith%^BOLD%^%^GREEN%^"+
   " project. The commotion it is causing among the Brotherhood is"+
   " enormous. %^BOLD%^%^RED%^Malverin%^BOLD%^%^GREEN%^ expects things"+
   " to run smooth on everyone's part and killing Auica now would only"+
   " hamper the progress we have already made here in Sanctuary. Doing"+
   " that could mean the wrath of Malverin or %^BOLD%^%^RED%^worse%^BOLD%^%^GREEN%^."
   );
}
