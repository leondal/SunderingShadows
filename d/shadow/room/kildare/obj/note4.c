//note4.c
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("ranger history 4");
   set_short("A weathered sheet of parchment");
   set_id(({"paper","sheet of parchment","parchment"}));
   set_long(
      "This aged piece of parchment is weathered and torn, "+
      "but it has a length of sprawling script that might still be "+
      "read."
   );
   set("read",
      "%^YELLOW%^5 Renewal, 318 SG\n"+
      "\n"+
      "%^BOLD%^%^GREEN%^To the goodwife Marian Basquil,\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^It is with great sadness that I pen this "+
      "letter.  I hope it finds you well, though I cannot say my news "+
      "will bring you any happiness our comfort.  I find it hard to "+
      "pen these words, but it was your husband's last request that "+
      "you know of what befell him.\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^Keth was a dear friend to all of us, and "+
      "especially to me.  I do not know if you have ever heard my "+
      "name, as our order is kept quiet to avoid gaining attention "+
      "we do not need.  We do our part to protect this land in "+
      "secrecy, asking no thanks or acknowledgement from those we "+
      "protect.  I do not doubt you have wondered where your husband "+
      "disappeared to for days, even weeks or months at a time.  I am "+
      "not free to tell you everything, but I can tell you that your "+
      "husband Keth was a good, honest man who loved you and the young "+
      "ones more than anything, save his Lady.\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^Keth spent many days wandering the wilderness "+
      "around your village, meeting with the rest of us and sharing information "+
      "to keep your family and friends safe.  Unlike most of us, he married.  "+
      "He said he was unable to resist you and that he would never be "+
      "complete otherwise.  Against our advice, he married and had a "+
      "family.  I do now believe he was right - at least as far as his "+
      "life was concerned.  He was not the same man...the grim look in his "+
      "eyes faded, and he regained the hope that so many of us struggle to "+
      "hold on to.  In short, you aand your children were what he lived for.  "+
      "It was in defense of all that he holds dear that Keth perished.  A "+
      "band of savage orcs were marauding in the countryside, heading "+
      "straight toward your small hamlet.  Keth, in horror of what might "+
      "happen, held his ground with only a handful of other warriors.\n"+
      "\n"+
      "   %^BOLD%^%^GREEN%^It is with pride that I tell you not a single orc "+
      "escaped that day.  However, I am saddened to say that Keth himself "+
      "fell in battle.  He realized his time was coming, and he sent "+
      "back his young comrade to tell me what happened and ask that I "+
      "write this letter to you.  I am so sorry we could not do more for "+
      "him, but I trust you will find some comfort in the knowledge that "+
      "your husband was a good man who loved you and your children.  You "+
      "will not hear from any of us again, but know that we are always "+
      "watching over these hills.\n"+
      "%^BOLD%^%^GREEN%^In sadness,\n"+
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
