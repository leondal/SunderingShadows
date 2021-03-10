//updated by Circe 5/30/04
// Llewddyn Blagenvirin, Gnomish Mage
// Thorn@ShadowGate
// 010205
// Tabor
// llewddyn.c

#include <std.h>
#include "../include/tabor.h"

inherit "/std/comp_vend.c";

void create()
{
    ::create();
    set_name("llewddyn");
    set_id( ({ "llewddyn", "clerk", "shop keeper", "gnome", "mage",
    	"shopkeeper", "blagenvirin"}) );
    set_short("Llewddyn Blagenvirin, Gnomish Mage");
    set("aggressive", 0);
    set_long(
"Llewddyn is a middle-aged gnome mage of some local reputation.  As his "+
"store is in an ancient chamber built for humans, many of the shelves and "+
"cabinets are placed out of his reach.  This seems to be no problem "+
"for the gnomish mage, however, as he simply levitates to reach "+
"whichever shelf and component he needs.  His wiry gray hair stands "+
"out at strange angles from his head, and his clear blue eyes are "+
"overshadowed by the thin-framed spectacles he wears.  His simple "+
"robe is made of a shockingly vibrant shade of green, and his little "+
"feet are clad in plain red shoes.\n\n"+
"To get you a list of shop commands, type <help shop>."
	);
    set_gender("male");
    set_alignment(4);
    set("race", "gnome");
    set_class("mage");
    set_hd(30,2);
    set_level(30);
    set_guild_level("mage",30);
    set_body_type("human");
    set_property("no bump", 1);
    set_wielding_limbs( ({ "right hand","left hand" }) );
    set_emotes(6,({"%^MAGENTA%^Llewddyn says%^RESET%^: You "+
        "people always seem to want the stuff on the top shelf.",
        "%^MAGENTA%^Llewddyn says%^RESET%^: What did I do with "+
        "that eye of roc?  You'd think they'd be too big to lose.",
        "%^MAGENTA%^Llewddyn says%^RESET%^: Fetch this, fetch that "+
        "diamond dust.  A gnome's work is never done.",
        "%^CYAN%^BOLD%^Llewddyn whispers%^RESET%^: Lemme tell you a secret"+
        "... Bat guano is the worst stuff.  I really hate that crap!",
        "Llewddyn starts to say something, but looks as if he forgot "+
        "what he was going to say.",
        "Llewddyn scratches his head forgetfully.","Llewddyn "+
        "shrugs and smiles."}), 0);
    set_emotes(20, ({"%^MAGENTA%^Llewddyn says%^RESET%^: Think "+
        "the widdle cute gnome is easy to pick on, eh?",
		"%^MAGENTA%^BOLD%^Llewddyn yells%^RESET%^: Eat lightning, moron!",
		"%^MAGENTA%^Llewddyn says%^RESET%^: I got some bat guano for "+
		"you!  Come here and open wide!",
		"%^MAGENTA%^Llewddyn says%^RESET%^: You're lucky I can't remember "+
		"half my spells."}), 1);
    set_components(100);
    set_spell_chance(100);
    set_spells(({"fireball","lightning bolt","acid arrow",
        "powerword stun", "incendiary cloud", "magic missile"}));
    set_property("strength","spells");
}
