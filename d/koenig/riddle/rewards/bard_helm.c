//bard_helm.c - Bard of helm reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit RALLYLIGHT;

void create(){
    ::create();
//    set_name("helm instrument");
    set_id(({"tabor","mithril tabor","instrument"}));
    set_obvious_short("A mithril tabor");
    set_short("%^CYAN%^Tabor of the %^BLUE%^Watchful Beats%^RESET%^");
    set_long(
@CIRCE
%^CYAN%^Made of mithril, this tabor has a strong solid feel to it.  A tabor is a cousin to the drum, but tends to be smaller and more compact, allowing for easier travel.  This mithril tabor has been polished to a high gloss, giving an inspiring gleam.  Painted onto the metal is the image of a %^BLUE%^blue eye%^CYAN%^ that travels in an orderly fashion around the base of the tabor.  A dull %^RESET%^white%^CYAN%^ membrane is stretched across the top of the tabor.  This tabor comes with a %^BLUE%^blue tapestry %^CYAN%^band to hold the instrument in place.  The tapestry image mirrors that of the tabor itself, with the same blue eye, only with a message woven into the cloth that one could read.  When struck, this tabor tends to give off a steady solid beat that never wavers or changes much.
CIRCE
    );
    set_read("%^CYAN%^May this tabor help you keep a watchful eye on those in "+
       "your protection.  You may use the tabor to "+
       "%^BLUE%^<%^CYAN%^rally%^BLUE%^> %^CYAN%^your comrades or "+
       "%^BLUE%^<%^CYAN%^play%^BLUE%^> %^CYAN%^to create a "+
       "light to guide them to the truth.");
    set_weight(8);
    set_value(0);
    set_lore("Much like the faithful of Tyr, the bards in Helm's employ "+
       "favor tabors for their solid, steady beat that never wavers.  Those "+
       "who have a good sense of rhythm and can keep all those around them "+
       "on the right foot are highly admired in Helm's service.  They are often "+
       "granted with tabors such as this one.  This particular tabor, however, "+
       "has a long and glorious history.  It is said to have been blessed by "+
       "the Guardian himself and infused with some of his own powers.  The "+
       "musician who carries this tabor is truly always within the watchful "+
       "gaze of his Guardian.");
    set_property("lore difficulty",12);
}
