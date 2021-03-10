#include <std.h>

inherit BANK;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("indoors",1);
   set_short("%^BOLD%^%^GREEN%^Seneca branch of the Bank of Attaya");
   set_long(
@DESC
The %^CYAN%^Bank of Seneca%^RESET%^ is a large multi-story structure where currencies 
from around the globe are exchanged in volumes that would make your 
head spin. Several desks fill the large lobby and a red carpet leads 
you to the general transaction desks. Carved wood pillars hold up a 
roof that is made mostly of glass panels and stained wood. There are 
also two split levels that open up into this room floors above. There 
is a sign detailing possible transactions posted beside each of the 
main desks.
DESC
   );
   set_items(([
      "bank" : "You are in its huge lobby. There is a counter in front of you "
           "and an exit behind you.",
      "customers" : "They are wandering about aimlessly.",
      "sign" : "Reading it will give you a list of commands.",
      "teller" : "The teller looks at you impatiently.",
      "counter" : "A teller waits behind it for you to do something.",
      "exit" : "It leads out into the street."
   ]));
   set_exits( ([
      "out" : "/d/attaya/seneca/bankyard",
   ]) );
   set_listen("default","There is a murmur of countless people talking at once.");
   set_smell("default","The metallic fragrance of coins fills the air here.");
}

