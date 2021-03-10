//note3.c
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("ranger history 3");
   set_short("A weathered sheet of parchment");
   set_id(({"paper","sheet of parchment","parchment"}));
   set_long(
      "This aged piece of parchment is weathered and torn, "+
      "but it has a length of sprawling script that might still be "+
      "read."
   );
   set("read",
      "%^YELLOW%^21 Winterstime, 318 SG\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^We received word only today that our shelter "+
      "in the southern reaches of Echoes Mountains was discovered and "+
      "decimated four days ago.  Two of our brothers were there, sharing "+
      "what news they had and resting briefly before going out to protect "+
      "these hills again.  They were found strung up on pikes outside our "+
      "well-hidden tree.  None before has ever been able to find it without "+
      "knowing our secrets, so I fear the worst...they either have a very "+
      "potent magic user among them, or it is as some have suggested...we "+
      "may well have a traitor in our midst.\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^I cannot abide the thought that one of the Needles "+
      "could have fallen so far into darkness as to turn on his own brothers, "+
      "so I cling to the hope that it is only a devilish sorcerer we battle, "+
      "though the foreboding in my heart warns me otherwise.  Infighting would "+
      "be the worst possible calamity to befall us at this moment, and I "+
      "hope the mistrust does not create rifts between our rangers that nothing "+
      "can heal.  For now, we must cling to each other and know that our cause "+
      "is just and true, as it is given to us by the Lady of the Forests.  We "+
      "answer to her and no other.\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^Our unfortunate brothers who met the orcs first "+
      "hand and brought bravely to the death must not be forgotten.  I will "+
      "begin collecting their names to do what I can to honor their memories.  "+
      "The two who fell most recently are well known to us all as steadfast and "+
      "fearless, and their names shall be remembered forever in honor of their "+
      "sacrifice.  Please, my Lady, keep Jonathan Lanyer and Felwar Ellison "+
      "in your heart.  They gave their all for you.\n"+
      "\n"+
      "%^BOLD%^%^GREEN%^With a heavy hand and heavier heart,\n"+
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
