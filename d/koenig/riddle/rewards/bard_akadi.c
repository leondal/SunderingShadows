//bard_akadi.c - Bard of Akadi reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit ANGERDETECT;

void create(){
    ::create();
//    set_name("akadi instrument");
    set_id(({"delicate flute","flute","instrument"}));
    set_short("%^BOLD%^%^CYAN%^A delicate flute%^RESET%^");
    set_long(
      "%^BOLD%^This paper-thin flute is light as air but is somehow "+
      "still quite sturdy.  It is made of an unusual translucent "+
      "material that shifts color from %^BLUE%^deep blue %^WHITE%^"+
      "to fluffy white.  The slender tube is fitted with many "+
      "holes, both covered and uncovered.  The instrument can be "+
      "played by blowing gently across the mouthpiece, and the pitch "+
      "can be greatly varied by covering and uncovering the finger holes.  "+
      "In the shifting colors, a message can sometimes be seen."
    );
    set_read("%^BOLD%^%^CYAN%^May the fury of the winds grant you your "+
       "freedom.  You may use this flute to call on the winds and "+
       "%^WHITE%^<%^CYAN%^anger%^WHITE%^> %^CYAN%^those who impede you or "+
       "%^WHITE%^<%^CYAN%^play%^WHITE%^> %^CYAN%^to detect magic around you.");
    set_weight(8);
    set_value(0);
    set_lore("Akadians are often fond of flutes, for they utilize the wind "+
       "to produce innumerable melodies.  This particular flute is made of "+
       "a mystical substance known to Akadians as andusil, which is said "+
       "to be a gift from Akadi herself.  No one knows the creation of this "+
       "legendary substance, but proof of its existence rests in your hands.  "+
       "Fickle though Akadi may be, boons such as this instrument show her "+
       "blessing...for the moment.");
    set_property("lore difficulty",12);
}
