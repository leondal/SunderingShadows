//note5.c
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("ranger history 5");
   set_short("A weathered sheet of parchment");
   set_id(({"paper","sheet of parchment","parchment"}));
   set_long(
      "This aged sheet of parchment is weathered and beaten, "+
      "and has been torn in half, leaving only the top portion.  "+
      "It has a length of hastily scrawled script that might "+
      "still be read."
   );
   set("read",
      "%^BOLD%^%^GREEN%^The orcs have surrounded us even as I "+
      "write this.  I must take up my bow in a moment and go "+
      "stand with the others, but as this may very well be our "+
      "last action in the mortal world, we want those coming "+
      "behind us to know the dangers they face.  The orcs "+
      "are controlled by a strange being called the Master, "+
      "but no one has seen it.  We have heard them refer to "+
      "it and scream its praises in battle.  They wear strange "+
      "tatoos - wickedly curved sickles crossed over a bloody "+
      "heart.  I do not know what it means, but these things "+
      "may prove most important.  Our Lady has aided us, but "+
      "they have proven too strong so far, and\n"+
      "\n"+
      "[Here, the paper ends and you are left wondering what "+
      "might have happened.]"
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
