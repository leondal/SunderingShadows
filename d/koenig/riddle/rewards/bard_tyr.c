//bard_tyr.c - Bard of tyr reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit RALLYLIGHT;

void create(){
    ::create();
//    set_name("tyr instrument");
    set_id(({"tabor","electrum tabor","instrument"}));
    set_obvious_short("An electrum tabor");
    set_short("%^BOLD%^%^BLUE%^Tabor of Justice's Rhythm%^RESET%^");
    set_long(
@CIRCE
%^BOLD%^%^BLUE%^This tabor is made out of electrum that has a rich blue sheen.  The tabor has a strong, solid feel to it.  The tabor is a cousin of the drum, but tends to be favored more by traveling musicians for its size and ease in travel. Around the base of this tabor an elaborate depiction of a %^WHITE%^wolf%^BLUE%^ has been painted.  The wolf appears to be watching over a small band of paladins and clerics who bear the symbol of Tyr as they are in a wilderness setting.  On the banner that one of paladins carry a message can be made out to read.  A blue membrane has been stretched across the base of the drum, and when struck tends to give a clear solid sound.  A simple blue strap is attached to the tabor, to allow one to wear the tabor without fear of losing it. 
CIRCE
    );
    set_read("%^BOLD%^%^BLUE%^May this tabor grant you the calm stillness needed "+
       "to give sound judgment.  You may use the tabor to "+
       "%^WHITE%^<%^BLUE%^rally%^WHITE%^> %^BLUE%^your companions or "+
       "%^WHITE%^<%^BLUE%^play%^WHITE%^> %^BLUE%^to create a "+
       "light to help you find the truth in all things.");
    set_weight(8);
    set_value(0);
    set_lore("The steady nerve of the Tyrran is echoed in the unwavering beat "+
       "of the tabor, a symbol of the faith.  This tabor was crafted by a "+
       "highly skilled craftsman and storyteller in Tyr's fold.  Khylock "+
       "the Blue - as he was ever known - was an aged storyteller at the "+
       "time he crafted his tabor.  As the legend goes, Tyr himself set within "+
       "Khylock's workroom, listening to his stories as the craftsman worked.  "+
       "Few now believe it, though not even the most skilled mage to examine the "+
       "tabor has been able to explain the mystical powers it has.");
    set_property("lore difficulty",12);
}
