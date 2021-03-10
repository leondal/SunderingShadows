
#include <std.h>
#include "../elf.h"
inherit NPC;

void create()
{
        ::create();

        set_name("Anarane Galathil");
        set_short("Anarane Galathil");
        set_id(({"elf","citizen","anarane galathil","anarane"}));
                set_gender("female");
        set_long("This is a gold elf dressed "+
                "in a gold dress with red trim.  She carries"+
                " a book for studying.  "+
                "She has long gold hair and bright gold"+
                " eyes.  Like all of her kin she is very slender"+
                " with soft almost child-like features.");

        
        set_race("elf");
        set_hd(1,60);
        set_hp(50);
      
      set_emotes(6,({
      "%^MAGENTA%^Anarane says:%^CYAN%^ I've not been here as long as many but it is a good safe place.",
      "%^MAGENTA%^Anarane says:%^CYAN%^ Some of my peers can be a bit eccentric.",
      "%^MAGENTA%^Anarane says:%^CYAN%^ The moon elves live outside in the grove "+
	  "and we gold elves stay here in the keep.  Most of them would rather live"+
	  " carefree lives than devote themselves to the Weave.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ There is one rumor that has been around quite a while though."+
	  "  Some say that outside in the ice one can hear the wailing of a woman at night.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ It is hard to believe that there once was"+
	  " a whole civilization here.  Now all that is left is this keep. ",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ The magic to enchant the mirror warriors"+
	  " is extremely difficult.  I've seen the elders do it for those wishing "+
	  "to pledge their lives to protecting this place.  It is rather awe-inspiring.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ I'm glad the humans are gone.  It is a "+
	  "shame what happened, but at least we can live in peace now.",
      "%^MAGENTA%^Anarane says:%^CYAN%^ This place is cursed with an eternal "+
	  "winter but it keeps away unwanted guests.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ High magic was performed here, which why this place is safe.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ The human mages use the Weave"+
	  " like it is a tool.  We elves are a part of it.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ The elders are very strict but for good reason.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ I've learned much from the elders.  I'm proud of my golden heritage.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ It is sad the drastic measures our ancestors "+
	  "took, but they had to or the humans would have wiped us out.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ Ages ago, our ancestors made a treaty with the humans "+
	  "to stop the bloodshed, but they did not honor it.  It was just a trick to lower our "+
	  "guard.  If there is one thing to expect from a human, it is betrayal.",
	  "%^MAGENTA%^Anarane says:%^CYAN%^ Sometimes freed slaves come here.  It is sad "+
	  "how feral some are, but our duty is to care for them and show them the elven ways.",
     }),0);
        command("message in walks with light steps.");
        command("message out walks out with light steps");
	set_base_damage_type("bludgeoning"); 
}