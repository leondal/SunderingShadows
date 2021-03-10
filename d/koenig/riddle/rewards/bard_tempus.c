//bard_tempus.c - Bard of tempus reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit RALLYLIGHT;

void create(){
    ::create();
//    set_name("tempus instrument");
    set_id(({"drum","steel drum","instrument"}));
    set_obvious_short("A steel drum");
    set_short("%^RESET%^%^WHITE%^Drum of %^RED%^Battle's Frenzy%^RESET%^");
    set_long(
@CIRCE
%^RED%^The base of this drum is made from %^RESET%^steel%^RED%^,which looks to have been scoured to give it a dull finish.  A red leather hide is stretched across the top of the medium drum.  Etched into the red leather hide is a message written in faded %^RESET%^silver%^RED%^.  Red leather cording criss-crosses the base of the drum, ending in a series of tassels.  A red leather strap is attached to the drum, allowing one to hold it in place, without fear of dropping it.  Tooled into the red leather strap is the image of a %^BOLD%^flaming sword on a shield%^RESET%^%^RED%^, the holy symbol of the Lord of Battles.  Striking this drum tends to give a loud clear sound, one that could possibly be heard above the roar of the battle.
CIRCE
    );
    set_read("%^BOLD%^%^RED%^May the joy of a well-fought battle "+
       "fill you with pride.  You may use this drum to "+
       "%^CYAN%^<%^BOLD%^%^RED%^rally%^CYAN%^> %^BOLD%^%^RED%^the warriors around you or "+
       "%^CYAN%^<%^BOLD%^%^RED%^play%^CYAN%^> %^BOLD%^%^RED%^to create a "+
       "mystical light to lead you into battle.");
    set_weight(8);
    set_value(0);
    set_lore("The stout-hearted faithful of Tempus enter battle with "+
       "his name on their lips.  The Warsingers, as his band of heralds "+
       "and loremasters is called, join the fray alongside the true "+
       "warriors with the music of drums.  This particular drum was first crafted "+
       "ages ago as a reward for Evan Steelsong, a minstrel who had taken "+
       "up the Battlelord's cause.  It is said to be crafted from dyed leather "+
       "taken from one of the Battlelord's own monstrous foes, and he has "+
       "breathed his blessing upon it.");
    set_property("lore difficulty",12);
}
