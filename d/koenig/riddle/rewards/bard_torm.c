//bard_torm.c - Bard of torm reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit RALLYLIGHT;

void create(){
    ::create();
//    set_name("torm instrument");
    set_id(({"lyre","birch lyre","instrument"}));
    set_obvious_short("A birch lyre");
    set_short("%^BOLD%^%^WHITE%^Lyre of the Lion's Pride%^RESET%^");
    set_long(
@CIRCE
%^BOLD%^%^WHITE%^Brilliant white birch wood has been bleached to make the base of this curved lyre.  The lyre's flutes that rise up have been carved to look like two lion's heads facing outwards.  %^YELLOW%^Gold%^WHITE%^ gilding has been used to bring some detail to the lion's faces and to give a hint of their bodies on the base of the lyre.  The lyre is strung with mithril strings that give a clear strong sounds when struck.  The %^YELLOW%^gold gilding%^WHITE%^ seems to spell out a message that one can read on the base of the lyre.
CIRCE
    );
    set_read("%^YELLOW%^May this lyre aid you in finding those who are "+
       "untrue and bringing them to justice.  You may use the lyre to "+
       "%^WHITE%^<%^YELLOW%^rally%^WHITE%^> %^YELLOW%^your companions or "+
       "%^WHITE%^<%^YELLOW%^play%^WHITE%^> %^YELLOW%^to create a "+
       "light to help you journey through the darkness of lies and betrayal.");
    set_weight(8);
    set_value(0);
    set_lore("Carved in the likenss of Torm, this lyre is likewise said to have "+
       "been touched by him.  The magical abilities of this lyre are attributed "+
       "to a famous case of betrayal that was tried by the faithful of Tyr "+
       "brought to swift justice by a priest of Torm.  A devout Tormish minstrel "+
       "observed the ordeal and recorded it all in song.  Torm is said to have "+
       "been so pleased with the minstrel that he reached down and touched the "+
       "mistrel's lyre, blessing it.  The minstrel was thereafter called "+
       "Hrothgar the Loyal, and the case was one involving the oft-troubled fief "+
       "of Drogheda near Echoes Mountains.");
    set_property("lore difficulty",12);
}
