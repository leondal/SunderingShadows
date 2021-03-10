//bard_bane.c - Bard of bane reward for Nereid Riddle Quest.  Circe 4/21/04
#include <std.h>
#include "../../nereid.h"

inherit ANGERDARK;

void create(){
    ::create();
//    set_name("bane instrument");
    set_id(({"drum","ebony drum","instrument"}));
    set_obvious_short("An ebony drum");
    set_short("%^BOLD%^%^BLACK%^Tyranny's Rhythmic Beat%^RESET%^");
    set_long(
@CIRCE
%^BOLD%^%^BLACK%^This small drum's base is made from polished ebony.  An %^GREEN%^emerald green%^BLACK%^ hide is stretched taut across the top of the drum.  The hide looks rather like snakeskin, with its scales still intact.  Carved into the ebony base, images of a spiked black gauntlet hand jut out of the material, giving it a slightly sinister feeling.  Written on each gauntlet hand seems to be a message of sorts.  An %^GREEN%^emerald green%^BLACK%^ snakeskin strap is attached to the drum, allowing one to slip it on without a fear of dropping it.
CIRCE
    );
    set_read("%^BOLD%^%^GREEN%^May the gauntleted hand of tyranny "+
       "stretch forth over all your foes.  You may use this drum to "+
       "%^BLACK%^<%^BOLD%^%^GREEN%^anger%^BLACK%^> %^BOLD%^%^GREEN%^those beneath you or "+
       "%^BLACK%^<%^BOLD%^%^GREEN%^play%^BLACK%^> %^BOLD%^%^GREEN%^to create an "+
       "inky darkness to confuse and blind your foes.");
    set_weight(8);
    set_value(0);
    set_lore("Drums such as these have long been used by followers of the "+
       "Black Hand to inspire fear in all others.  Bards in his faith have "+
       "mastered the art of using spells to alter another's will, and all such "+
       "spells are highly prized by them.  This drum was crafted as a gift from "+
       "bane to one bard in particular who had served him well.  Sadly, Malicant "+
       "the Green overstepped his bounds one day, and Bane had to smite him.  No "+
       "one can aspire to rise above such a powerful Tyrant, not even his most favored "+
       "pupil.");
    set_property("lore difficulty",12);
}
