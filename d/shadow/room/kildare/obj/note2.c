//note2.c
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("ranger history 2");
   set_short("A weathered sheet of parchment");
   set_id(({"paper","sheet of parchment","parchment"}));
   set_long(
      "This aged piece of parchment is weathered and torn, "+
      "but it has a length of sprawling script that might still be "+
      "read."
   );
   set("read",
      "%^YELLOW%^8 Winterstime, 318 SG\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^The orcs have taken the closest pass over "+
      "the mountains, ambushing our people and cutting off any retreat "+
      "the citizens of the nearby towns my have.  I fear all will end "+
      "in ruin.  We have not lost faith in our Lady, but they seem too "+
      "many and our numbers dwindle.  There is not one of us who would "+
      "not give his life...and I believe in the end we all may be called "+
      "to do just that.  We will continue our struggle, and as long as "+
      "there is a breath left in any of our bodies, we will not let "+
      "these orcs burn the forests and scattered the woodland creatures.\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^We sent an emissary to the leige of the human "+
      "province of Drogheda, warning him that this danger might come "+
      "to his lands as well, but we have yet to hear word from him, and "+
      "our brother has not returned.  We only hope that we will yet "+
      "see him again, and that his message was successfully delivered.  "+
      "That many of our people dying at the hands of these brutes..."+
      "it cannot be tolerated.  In the end, we will find the way.  They "+
      "must have a weakness...\n"+
      "\n"+
      "%^BOLD%^%^GREEN%^In haste,\n"+
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
