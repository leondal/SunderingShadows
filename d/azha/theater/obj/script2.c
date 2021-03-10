#include <std.h>
inherit OBJECT;

void create(){
      ::create();
      set_name("script page");
      set_id(({ "script", "page","paper"}));
      set_short("%^YELLOW%^A page from a script%^RESET%^");
      set_long("%^YELLOW%^Torn from it's binding,"+
		" this page appears to have been taken from a script."+
		"  Lines from a play are transcribed onto the yellowed"+
		" sheet of paper, along with some notes added.");
      set_read("\n\n\t%^MAGENTA%^Hivetta's Harmony Act 1 Scene"+
		" 2\n\n\n%^RESET%^"+
		"%^RESET%^*Location Shrine of Shar - Dark Interior*\n"+
		"%^GREEN%^Ramzalina - %^BOLD%^I say we just kill the"+
		" pesky priest now, no use in leaving him alive.\n"+
		"%^CYAN%^+Ramzalina glares at the bound Laeol lying"+
		" on the floor, reaching for her dagger+\n"+
		"%^RED%^Yathar - %^BOLD%^Get your hand away from "+
		"there, you stupid girl.  The Nightcloak Usuki "+
		"wishes him alive, and alive he shall stay until she"+
		" says other wise.  Do not forget your place within "+
		"this faith, woman!%^RESET%^\n"+
		"%^CYAN%^+Ramzalina shoots a cold glance to Yathar her"+
		" hand still on her dagger, but no longer focused on "+
		"Laeol+%^RESET%^\n"+
		"%^GREEN%^Ramzalina - %^BOLD%^Watch yourself mage, or "+
		"I shall gut you here and now! While you were to busy"+
		" flailing around blindly I was the one who captured "+
		"this priest, not you.%^RESET%^\n"  
		"%^CYAN%^+Ramzalina should be feeling smug now, Yathar "+
		"is feeling his pride wounded by her comment+%^RESET%^\n"+
		"%^RED%^Yathar - %^BOLD%^Cursed priest of that Lunatic "+
		"Witch.  It is not MY fault that he was able to blind me."+
		"  Damn him, damn his rotten luck, and thrice damn his "+
		"bitch of a goddess.%^RESET%^\n\n"+
		"%^RESET%^Written in fresher ink than the play reads\n"+
		"%^BLUE%^What have they done to the actors!?!?! The screams"+
		" of Diva Zahara and Maestro Daleric ..still hear.. oh gods.."+
		" what has happened here?  What has my beautiful play been "+
		"reduced to?  Their bodies.. all seven of them.. taken.."+
		"eatten.. oh my sweet Diva.  This is not the end you should"+
		" have had.. The winged bird-woman's appetite grows with "+
		"each day we are trapped here.  Why hasn't Azha sent aid?"+
		"  Why hasn't aid come to free us..");
      set_language("common");
      set_weight(1);
      set_value(30);
}