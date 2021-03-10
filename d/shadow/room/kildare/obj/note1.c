#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("ranger history 1");
   set_short("A weathered sheet of parchment");
   set_id(({"paper","sheet of parchment","parchment"}));
   set_long(
      "This aged piece of parchment is weathered and torn, "+
      "but it has a length of sprawling script that might still be "+
      "read."
   );
   set("read",
      "     %^BOLD%^%^GREEN%^Set here within this book is a record of "+
      "the Orc Wars of the 4th century, SG, as recorded by Althonius "+
      "Tivalden, scribe to the Needles of the Forest, a band of "+
      "rangers sworn to the service of Mielikki here in the foothills "+
      "of Echoes Mountains.  This record has been kept in the hopes "+
      "that someday we may look back upon our victories, or at the "+
      "very least, let others know what happened to us in case we "+
      "fall.\n"+
      "\n"+
      "     %^BOLD%^%^GREEN%^In the year 317 SG, a small band of orcs moved "+
      "into the foothills northwest of Echoes Mountains.  Our people "+
      "watched them and tried to drive them off.  They feinted and ran, "+
      "but returned in huge numbers and took the hills in only one day.  "+
      "It was early fall of that year, in Harvestdays, and it is to our "+
      "shame that we did not see their ploy for what it was.\n"+
      "\n"+
      "     %^BOLD%^%^GREEN%^It is now the 1st day of Colddays, and we begin to worry that this "+
      "will be the bloodiest winter these lands have known.  We fear we "+
      "may have failed the Lady of the Forests even now by slipping in "+
      "our vigilance, but we vow to overcome this threat.  I will record "+
      "more of the battles as chance allows me, but for now, I must join "+
      "my brothers.  By my hand,\n"+
      "\n"+
      "%^BOLD%^%^RED%^Althonius Tivalden"
   );
   set_lore("These papers are the scattered pieces of the journal of "+
      "Althonius Tivalden, a scribe who dedicated himself to the "+
      "Needles of the Forest, a band of rangers serving Mielikki "+
      "in the 300s SG.  The band fought the Orc Wars, and though "+
      "they were eventually decimated, it is said that Mielikki "+
      "had her revenge on the orcs.  Relics of the rangers exist "+
      "still today and may be found all around the Echoes Mountains.");
   set_property("lore difficulty",11);
   set_weight(1);
   set_value(0);
}
