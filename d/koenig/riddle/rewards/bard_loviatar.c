//bard_loviatar.c - Bard of loviatar reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit ANGERDARK;

void create(){
    ::create();
//    set_name("loviatar instrument");
    set_id(({"black leather drum","drum","leather drum","instrument"}));
    set_obvious_short("A black leather drum");
    set_short("%^BOLD%^%^BLACK%^Drum of the %^RED%^Wailing%^BLACK%^ Lash%^RESET%^");
    set_long(
@CIRCE
%^BOLD%^%^BLACK%^This black leather drum is set with %^WHITE%^mithril%^BLACK%^ studs.  The base of the drum is round and cylindrical, like all drums.  A black leather hide is stretched taut against the base of the drum, and held in place with even more studs.  A leather strap, in the same hue as the drum, allows one to wear the drum without a fear of losing it.  Tooled into the strap of the drum appears to be a message that one can barely make out.  This drum seems to admit a quick cracking tune, much like the sound of a whip makes, when struck rapidly.
CIRCE
    );
    set_read("%^RED%^May this drum serve as a fitting companion to the "+
       "pain you inflict.  You may use this drum to "+
       "%^WHITE%^<%^RED%^anger%^WHITE%^> %^RED%^your victims and increase their pain or "+
       "%^WHITE%^<%^RED%^play%^WHITE%^> %^RED%^to create a "+
       "darkness to veil hope from them.");
    set_weight(8);
    set_value(0);
    set_lore("This mithril-studded drum is fashioned in the stark manner "+
       "prefered by followers of the Maiden of Pain.  No one knows the manner "+
       "of creature whose hide makes up the majority of this drum, but a close "+
       "look shows it is most definitely not livestock.  The Maiden of Pain "+
       "takes great delight in heightening pain and suspense for her victims.  "+
       "This drum was crafted for her faithful high priest Malorn Foucault, "+
       "who often used it to mimic the sound of a whip, making his blindfolded "+
       "victims cringe and tense in terror.");
    set_property("lore difficulty",12);
}
