//bard_mielikki.c - Bard of Mielikki reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit CALMLIGHT;

void create(){
    ::create();
//    set_name("mielikki instrument");
    set_id(({"rustic panpipes","panpipes","pipes","pipe","instrument"}));
    set_short("%^BOLD%^%^GREEN%^A set of rustic panpipes%^RESET%^");
    set_long(
      "%^GREEN%^This set of panpipes has been crafted from %^BOLD%^"+
      "living reeds %^RESET%^%^GREEN%^that seems to be ever-green.  "+
      "The reeds are cut at an angle, each one longer than the one "+
      "before it.  They are bound in a row with a simple length of "+
      "%^ORANGE%^leather cording%^GREEN%^, and a symbol has been carved "+
      "on each individual pipe.  The symbol is that of a %^BOLD%^%^WHITE%^"+
      "unicorn head %^RESET%^%^GREEN%^set with a %^YELLOW%^golden horn"+
      "%^RESET%^%^GREEN%^, the only hint of wealth on these pipes.  "+
      "Burned into the leather is a message."
    );
    set_read("%^BOLD%^%^GREEN%^May the magic of these pipes fill you with "+
       "the purity of the forests.  You may use these panpipes to "+
       "%^WHITE%^<%^GREEN%^calm%^WHITE%^> %^GREEN%^those who attack you or "+
       "%^WHITE%^<%^GREEN%^play%^WHITE%^> %^GREEN%^to create a bright light.");
    set_weight(8);
    set_value(0);
    set_lore("These panpipes are made of a reed not found in the "+
       "natural world.  Legend holds that they are plucked from the "+
       "banks of a stream which runs through the domain of the Lady "+
       "of the Forests.  While many panpipes are made in this realm, "+
       "none can match the pure, sweet tone of these pipes.  The Lady "+
       "grants them only to those who serve her by preserving the lore of "+
       "the natural world and telling others of the importance of "+
       "protecting the forests.");
    set_property("lore difficulty",12);
}
