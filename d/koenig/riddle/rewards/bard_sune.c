//bard_sune.c - Bard of Sune reward for Nereid Riddle Quest.
//Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit RALLYLIGHT;

void create(){
    ::create();
//    set_name("sune instrument");
   set_id(({"ivory lyre","lyre","instrument"}));
    set_obvious_short("%^BOLD%^%^WHITE%^An ivory lyre%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^Lyre of %^RESET%^%^RED%^Love's"+
		"%^BOLD%^%^RED%^ Sweet %^BOLD%^%^WHITE%^Song"+
		"%^RESET%^");
   set_long("%^RESET%^Crafted from %^BOLD%^%^WHITE%^ivory%^RESET%^ this graceful and elegant lyre"
   " has been polished to a high luster.  Either ends of the lyre have been sculpted"
   " to spiral inwards, like twin locks of hair.  A curling %^YELLOW%^yellow gold%^RESET%^"
   " cross bar connects either side of the lyre together.  The cross bar has been carved with images"
   " with images of intertwined roses and a short phrase carved into the gold.  Strings of pure %^YELLOW%^gold%^RESET%^"
" sparkle in the light, causing them to seem to %^BOLD%^%^WHITE%^g%^YELLOW%^l%^WHITE%^o%^YELLOW%^w %^RESET%^with an"
" unearthy beauty.  When played, the lyre tends to produce %^RED%^beautiful %^RESET%^notes in all manner of pitches and ranges.");
    set_read("%^RESET%^%^RED%^May the power of this lyre inspire romance"+
		" and love to all who hear its sweet song."+
		"  With this lyre you may:"+
       	"%^BOLD%^%^RED%^<rally>%^RESET%^%^RED%^ your companions, or "+
       	"%^BOLD%^%^RED%^%^<play> %^RESET%^%^RED%^to create light around you.");
    set_weight(8);
    set_value(0);
   set_lore("The Lyre of Love's Sweet Song was a very common instrument within the temples and "
   "and shrines to Sune Firehair.  The faith of Sune use to be some of the largest supporters of"
   " artists and musicians, rivaling even the faith of Lathander with their patronage."
   " These lyres were given out each year during the Midsummer Night's contests that the faith of"
   " Sune celebrated.  Seen as one of the most romantic times of the year, Midsummer's Night was"
   " always a huge festival with the temple of Sune.  Among the entertainer community it was seen as "
   "a great honor to be asked to perform for the Sunites during this time, and even a greater honor to actually win a lyre.");
    set_property("lore difficulty",12); 
}
