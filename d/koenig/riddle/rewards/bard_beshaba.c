//bard_beshaba.c - Bard of Beshaba reward for Nereid Riddle Quest.
//Cythera 8/05
#include <std.h>
#include "../../nereid.h"

inherit RALLYDARK;

void create(){
    ::create();
//    set_name("beshaba instrument");
    set_id(({"blackhorn flute","flute","instrument"}));
    set_obvious_short("%^BOLD%^%^BLACK%^A blackhorn flute%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^Flute of %^BOLD%^%^MAGENTA%^Ma"+
		"%^BOLD%^%^BLACK%^dn%^BOLD%^%^RED%^es%^BOLD%^%^BLACK%^"+
		"s%^RESET%^");
    set_long(
"%^RESET%^This flute has been carved out a %^BOLD%^%^BLACK%^black horn%^RESET%^.  "+
"The narrow flute is longer than a flute typically is.  The %^BOLD%^%^BLACK%^black "+
"horn%^RESET%^ has a %^BOLD%^%^WHITE%^glossy%^RESET%^ luster to it, which only brings "+
"out the %^BOLD%^%^BLACK%^darker%^RESET%^ tones and shades of the flute.  Thirteen "+
"holes of random sizes and dimensions has been drilled into the body of the flute.  "+
"A band of either %^BOLD%^%^MAGENTA%^mauve%^RESET%^ or %^BOLD%^%^RED%^red%^RESET%^ "+
"has been painted around each of the holes. Tied around the top part of the flute is "+
"a %^BOLD%^%^BLACK%^black%^RESET%^ silk ribbon with a short phrase stitched in "+
"%^BOLD%^%^RED%^red%^RESET%^. When played the flute tends to produce a cacophony "+
"of notes in variety of ranges and pitches."
	);
    set_read("%^BOLD%^%^RED%^May the power of this flute bring calamity and "+
		"misfortune to the lives of those who hear its song."+
		"  With this flute you may:"+
       	"%^BOLD%^%^MAGENTA%^<rally>%^RED%^ your companions, or "+
       	"%^BOLD%^%^MAGENTA%^%^<play> %^RED%^to create darkness around you.");
    set_weight(8);
    set_value(0);
    set_lore(
@CYTHERA
The Flute of Madness is usually tied with the Pipe Pipers.  The Pipers where a small collection of bards that venerated Beshaba and sought to bring her misfortune to all they encountered on their travels.  The Pipers usually used their gift of charm and music to infest a town or village with rats.  Rats are seen as unholy agents of Beshaba, and the towns people would often fall into a near panic to be rid of them.  The Pipers would then enter the town and offer to lead the rats away for a fee.  The towns people more often than not were so overjoyed to be rid of the rats that they paid the Pipers what ever price they asked.  True to their word the Pipers would 'lead' the rats out of town, but they usually took a special prize or two with them as they left, children from the village.  Thus Beshaba's Misfortunes were spread to a family or two.
CYTHERA
	);
    set_property("lore difficulty",12); 
}
