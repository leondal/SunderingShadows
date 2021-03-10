//ranger_tyr.c - Reward for Riddle Quest. Cythera 4.05
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("tyr bow");
   set_id(({"oak longbow","bow","longbow","long bow","felon's demise","oak bow"}));
   set_obvious_short("%^RESET%^%^ORANGE%^An oak longbow%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^F%^RED%^e%^BLUE%^l%^RED%^o%^BLUE%^n%^RED%^'%^BLUE%^s Demise%^RESET%^");
   set_long("%^ORANGE%^Fashioned from oak, this bow seems ancient and"+
		" old in appearance.  The long bow curves more than a "+
		"typical longbow, hinting at it's Tsvaren make.  "+
		"The weathered oak takes on a deep golden luster.  "+
		"A %^BOLD%^%^BLUE%^bright blue%^RESET%^%^ORANGE%^ "+
		"leather handgrip rests in the center of this rather"+
		" plain looking bow.  Embossed into the leather handgrip"+
		" is the image of a pair of balanced scales resting on "+
		"a war hammer.  Hanging from the top of the bow is a "+
		"leather cord that has six round %^BOLD%^%^RED%^b%^BLUE%^"+
		"e%^RED%^a%^BLUE%^d%^RED%^s%^RESET%^%^ORANGE%^ on it.\n%^RESET%^");
   set_lore("Within Tyr's faith is a band of rangers devoted to "+
		"hunting down criminals and bringing them back to "+
		"trial.  The Justicars of the Wolf have an impressive"+
		" success rate in being able to locate nearly anyone.  "+
		"With almost an obsession, they spend weeks, months if "+
		"not years hunting for their target.  The rangers are "+
		"well known for the longbows they use of Tsvaren origin."+
		"  Within the Justicars, it is said that for each felon "+
		"that they are unable to bring back to justice, and must "+
		"judge them personally a bead is added to the leather cord"+
		" on their bow.  ");
   set_property("lore difficulty",12);
	set_unwield("%^CYAN%^You put your bow away, but know the time will "+
		"come when there will be criminals to bring to justice.");
}