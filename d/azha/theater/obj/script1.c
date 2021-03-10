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
      set_read("\n\n\t%^MAGENTA%^Hivetta's  Harmony Act 2 "+
		"Scene 3\n\n%^RESET%^"+
		"\t%^CYAN%^Hivetta %^BOLD%^I do not know what it is you "+
		"ask of me, Lord Daeranth.\n%^RESET%^"+
		"%^GREEN%^=Hivetta crosses stage left, moving upstage,"+
		" circling around Daeranth =%^RESET%^\n"+
		"\t%^BOLD%^%^BLUE%^Daeranth %^YELLOW%^Lady Hivetta, most"+
		" favored harpist and songstress of Selune, you alone"+
		" must know what they are seeking.  You must know why"+
		" they are after you.  I ask you to trust me Hivetta.  "+
		"Trust me so that we may work together in freeing your brother-"+
		"priest.  Torm has heard the plight of Selune's faith "+
		"and has charged me to aid you.  How can I if you do not"+
		" trust me?%^RESET%^\n"
		"%^GREEN%^= Daeranth pleads to Hivetta's sense of reason,"+
		" though his frustration is clear.  He turns in a circle,"+
		" holding a firm position but keeping his eyes on Hivetta"+
		"=%^RESET%^\n"+
		"%^MAGENTA%^+Focus amber lights on these two, the stage "+
		"should be dim letting the others around them fade into "+
		"the shadowy shapes+\n\n\n"+
		"%^RESET%^Written in fresher ink than the play reads\n"+
		"%^BLUE%^They have come, gods save us they have come.  "+
		"From where I do not know  but they are here.  Blue "+
		"skinned females lead by a dark skinned winged woman.. "+
		"they hunt us they prey on us..  The exits are blocked.."+
		" we are at their mercy.  Sweet Lathander, deliver us from"+
		" these creat...\n\n");
      set_language("common");
      set_weight(1);
      set_value(30);
}