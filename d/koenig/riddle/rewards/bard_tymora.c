//bard_tymora.c - Bard of tymora reward for Nereid Riddle Quest.  Circe 4/21/04
#include <std.h>
#include "../../nereid.h"

inherit CALMLIGHT;

void create(){
    ::create();
//    set_name("tymora instrument");
    set_id(({"silver flute","flute","instrument"}));
    set_obvious_short("%^BOLD%^A silver flute%^RESET%^");
    set_short("%^BOLD%^%^MAGENTA%^Flute of the Gambler%^RESET%^");
    set_long(
       "%^BOLD%^This slender flute is made out of polished "+
       "silver that has a slight %^CYAN%^blue cast %^WHITE%^"+
       "to it.  The flute is engraved with images of %^YELLOW%^"+
       "gems%^WHITE%^, %^RED%^swords%^WHITE%^, %^RESET%^%^ORANGE%^"+
       "clubs%^BOLD%^%^WHITE%^, and %^BLACK%^towers%^WHITE%^, "+
       "which you recognize as suits from a deck of cards.  Five "+
       "holes have been drilled into the cool silver, four to allow "+
       "for a variation of sounds and the fifth being the windpipe.  "+
       "This flute seems to perform a lighthearted clear melody when "+
       "played.  A pair of %^RESET%^%^ORANGE%^ivory dice %^BOLD%^"+
       "%^WHITE%^are thread on a thick %^BLUE%^blue silk ribbon "+
       "%^WHITE%^that is tied about the flute.  Looking at the "+
       "ribbon you can see that a phrase has been embroidered "+
       "into the silk."
    );
    set_read("%^BOLD%^%^MAGENTA%^May the luck of the Lady guide your  "+
       "footsteps.  You may use this flute to call on the Lady's luck to "+
       "%^CYAN%^<%^MAGENTA%^calm%^CYAN%^> %^MAGENTA%^those who become angry or "+
       "%^CYAN%^<%^MAGENTA%^play%^CYAN%^> %^MAGENTA%^to create a light "+
       "for your path.");
    set_weight(8);
    set_value(0);
    set_lore("These flutes are decorated with symbols of good "+
       "fortune and are said to possess some of the power of "+
       "Lady Luck herself.  Indeed, a performer in the Lady's "+
       "embrace may use this to extract himself from many "+
       "sticky situations, including finding a way out when "+
       "none seems possible.  Those who carry a flute like this "+
       "are thought to be blessed by Tymora herself.");
    set_property("lore difficulty",12);
}
