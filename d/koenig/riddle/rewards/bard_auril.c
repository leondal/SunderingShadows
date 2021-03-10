//bard_auril.c - Bard of Auril reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit ANGERDETECT;

void create(){
    ::create();
//    set_name("auril instrument");
    set_id(({"crystalline flute","flute","instrument"}));
    set_short("%^BOLD%^A crystalline flute%^RESET%^");
    set_long(
      "%^BOLD%^Examining this flute, you quickly realize it's not made "+
      "of crystal as it first appears - it's made of ice!  Cold to the "+
      "touch, it has been enchanted to never melt.  Snowflake patterns "+
      "have been frosted into the otherwise transparent ice and seem "+
      "to shift and swirl.  The fingerholes are covered with small caps "+
      "of ice that can be opened or closed to vary the pitch of the flute.  "+
      "The music of the flute is lonely and frigid, a fitting tune for "+
      "the Frostmaiden.  A messages swirls up to the surface of the flute "+
      "between the snowflakes."
    );
    set_read("%^BOLD%^%^CYAN%^May the fury of the frigid winter freeze your "+
       "foes.  You may use this flute to call on the fury of the snow and "+
       "%^WHITE%^<%^CYAN%^anger%^WHITE%^> %^CYAN%^those who dare oppose you or "+
       "%^WHITE%^<%^CYAN%^play%^WHITE%^> %^CYAN%^to detect magic around you.");
    set_weight(8);
    set_value(0);
    set_lore("These flutes are used by those devout in the Frostmaiden's faith "+
       "to spread her fury.  Legend holds that in ancient times these flutes "+
       "could bring forth the cold itself to freeze the blood in the veins "+
       "of those who angered the Frostmaiden.  If that is true, it seems "+
       "they have lost some of their potency.  However, they are still quite "+
       "powerful and those who hold them are revered within the faith of Auril.");
    set_property("lore difficulty",12);
}
