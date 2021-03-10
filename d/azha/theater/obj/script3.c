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
      set_read("\n\n\t%^MAGENTA%^Hivetta's Harmony Act"+
		" 3 Scene 5\n\n"+
		"%^RESET%^\n"+
		"%^GREEN%^Sir Roderick - %^BOLD%^Our forces"+
		" are gathered Nightcloak Usuki.  My army "+
		"stands ready to lead the charge.  The glory"+
		" of this night shall fall to The Lady of Loss.\n"+
		"%^RESET%^%^CYAN%^=Roderick lowers himself to his"+
		" knees and bows reverently before Usuki=%^RESET%^\n"+
		"%^MAGENTA%^Usuki -%^BOLD%^ Well done Sir Roderick."+
		"  The Mistress of the Night shall be pleased with "+
		"your dedication to her cause.  Her wisdom to make"+
		" you one of her holy knights has paid off faster than"+
		" I anticipated.  How strong of a force do you lead?\n"+
		"%^RESET%^%^CYAN%^=Usuki rests her hand on Roderick's "+
		"forehead in a blase manner, granting him a blessing, "+
		"but looking rather bored with the process=%^RESET%^\n"+
		"%^GREEN%^Roderick - %^BOLD%^Twenty archers, ten spearmen"+
		", thirty footmen, fifteen cavaliers, two wizards and by"+
		" your grace Reverent Nightcloak, five clerics will strike"+
		" against the Halls of the Silver Moon.%^RESET%^\n"+
		"%^CYAN%^=Roderick keeps his head bowed, showing his "+
		"complete devotion and submission to Usuki=%^RESET%^\n"+
		"%^MAGENTA%^Usuki -%^BOLD%^ You shall have your five"+
		" priests, Sir Roderick.  The force you lead is an "+
		"impressive one indeed.  One that will smother the "+
		"light of the moon this night in the bleakness of the"+
		" dark.  Let the followers of the Light Sister feel "+
		"all that The Dark Mother is on this night.  Deliver"+
		" upon them lessons of sorrow and loss.  Let them know"+
		" that the hand of Shar has shattered their hopes."+
		"%^RESET%^\n"+
		"%^CYAN%^=Usuki should be feeling smug and proud during "+
		"this speech, stepping away from Roderick =%^RESET%^\n"+
		"%^MAGENTA%^Usuki - %^BOLD%^Kill them all but one.  "+
		"Bring the harpist, Hivetta, to me.  Let the men do "+
		"what they with the rest of the Selunites, as long "+
		"as none live after this.  I want Hivetta unharmed "+
		"and alive, Roderick.  Her fate is tied to yours "+
		"Sir Roderick.%^RESET%^\n"+
		"%^CYAN%^=Usuki begins to pull her cloak and robes "+
		"around her, hiding her flesh under the dark veils"+
		" and layers=%^RESET%^\n"+
		"%^BOLD%^%^BLUE%^+As Usuki begins to cloth herself "+
		"drop the lighting in the room for each piece, "+
		"until it seems as if the whole stage is bathed"+
		" in 'visible darkness' - Violet lighting+\n\n\n"+
		"%^RESET%^Written in fresher ink than the play reads\n"+
		"%^RESET%^%^BLUE%^All hope has left us now.  The church "+
		"of Tyr arrived to deliver us from these creatures"+
		".  Or so we thought  They tried to rush the theater"+
		", but were met with that winged devil's army.. They"+
		" were like twigs trying to battle an inferno.. the"+
		" first wave was killed instantly.  They have left "+
		"usretreated..  Obelisks now encircle the theater.."+
		" Marjamal says they are wards set in place to keep "+
		"these creatures here in the theater, from escaping "+
		"to the rest of the lands.  What of us though?  "+
		"What of those of us still alive in here..  will "+
		"this become our tomb?\n\n");
      set_language("common");
      set_weight(1);
      set_value(30);
}