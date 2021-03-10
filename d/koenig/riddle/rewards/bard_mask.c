//bard_mask.c - Bard of mask reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit CALMDETECT;

void create(){
    ::create();
//    set_name("mask instrument");
    set_id(({"cypress lute","lute","instrument"}));
    set_obvious_short("%^RESET%^%^ORANGE%^A cypress wooden lute%^RESET%^");
    set_short("%^YELLOW%^Lute of Fleet Feet%^RESET%^");
    set_long(
      "%^YELLOW%^Golden cypress wood is used in the construction "+
      "of this lute.  The wood has been polished to a high gloss, "+
      "further adding to the richness of the warm wood.  The lute "+
      "is inlaid with swirls of bronze, giving it an even richer "+
      "golden hue.  Four steel strings are strung on the lute to "+
      "give it a rich sound.  Striking a chord on this lute tends "+
      "to produce a rapid quick tune that does not carry for long.  "+
      "Stylized bronze knobs mounted with %^GREEN%^agate%^YELLOW%^ "+
      "allow one to tune the lute when needed.  There appears to "+
      "be something written on the neck of the lute, under the "+
      "steel strings, though at first glance it looks to be part "+
      "of the design."
    );
    set_read("%^YELLOW%^May the cover of shadows hide your every "+
       "movement.  You may use this lute to call on the shadows and "+
       "%^BLACK%^<%^YELLOW%^calm%^BLACK%^> %^YELLOW%^those who see your intentions or "+
       "%^BLACK%^<%^YELLOW%^play%^BLACK%^> %^YELLOW%^to detect magic around you.");
    set_weight(8);
    set_value(0);
    set_lore("This simple looking lute has been used by Maskarrans "+
       "for centuries to help them avoid detection.  Foreknowledge "+
       "can help avoid detection, which makes the lute's ability to sense "+
       "magic all the more desirable to a Maskarran.  Should the Maskarran's "+
       "sense fail, however, the lute provides a way to help calm those "+
       "who might otherwise be angered.  It is said that this lute was first "+
       "granted to a bard simply known as Madeline by Mask himself.  Since "+
       "then, all Maskarran bards have coveted this simple lute.");
    set_property("lore difficulty",12);
}
