//bard_silvanus.c - Bard of silvanus reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit CALMLIGHT;

void create(){
    ::create();
//    set_name("silvanus instrument");
    set_id(({"set of panpipes","panpipes","pipes","pipe","instrument"}));
    set_short("%^ORANGE%^An aged set of panpipes%^RESET%^");
    set_long(
      "This rustic set of panpipes is made of aged %^ORANGE%^oak "+
      "wood %^RESET%^that has been bleached in the sun.  It is now "+
      "a fantastic %^BOLD%^si%^RESET%^lve%^BOLD%^ry %^RESET%^color "+
      "that has the streaked and mottled look of a wise, ancient tree.  "+
      "Each of the slender reeds is a little shorter than the one before "+
      "it, and the pipes have been bound with a living %^BOLD%^%^GREEN%^"+
      "ivy vine%^RESET%^.  A light, sylvan melody can be played by blowing "+
      "gently across the openings of the pipes.  A message has been carved "+
      "in a blocky, rustic script along the longest pipe."
    );
    set_read("%^BOLD%^%^GREEN%^May the magic of these pipes fill you with "+
       "the balance of nature.  You may use these panpipes to "+
       "%^WHITE%^<%^GREEN%^calm%^WHITE%^> %^GREEN%^those who attack you or "+
       "%^WHITE%^<%^GREEN%^play%^WHITE%^> %^GREEN%^to create a bright light.");
    set_weight(8);
    set_value(0);
    set_lore("Made of an ancient oak tree that still lives, these panpipes "+
       "are sacred to the clergy of Silvanus, the Oak Father.  It is said "+
       "that all such pipes are made from the wood of the same oak and that "+
       "they are grown, rather than carved.  No one has seen this tree, "+
       "however, and many outside the faith contend that it's simply a legend.  "+
       "All agree, though, that those granted these panpipes walk with the "+
       "blessings of the Oak Father surrounding them.");
    set_property("lore difficulty",12);
}
