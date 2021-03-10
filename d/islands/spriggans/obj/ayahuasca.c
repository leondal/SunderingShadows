#include <std.h>
#include "../spriggan.h"

inherit OBJECT;

void create(){
   ::create();
   set_name("ayahuasca");
   set_id(({"ayahuasca","vine","healing vine","ayahuasca vine"}));
   set_short("%^BOLD%^%^GREEN%^ayahuasca vine%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This thick green vine has "+
      "%^YELLOW%^knobby protrusions %^RESET%^%^GREEN%^at "+
      "intervals along its length.  It has a few oval-"+
      "shaped %^BOLD%^leaves %^RESET%^%^GREEN%^attached "+
      "but the real prize seems to be the vine itself.%^RESET%^");
   set_lore("This vine is said to have both medicinal and "+
      "hallucinogenic properties.  Prized for its healing "+
      "abilities, it is often used to create potions and "+
      "poultices to help heal the sick.");
   set_property("lore difficulty",10);
   set_weight(1);
}

int is_healing_vine(){ return 1; }