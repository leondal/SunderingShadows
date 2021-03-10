// Cirtwith Aelfine
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
    set_name("cirtwith");
    set_id( ({ "cirtwith", "clerk", "shop keeper", 
    	"shopkeeper", "aelfine"}) );
    set_short("Cirtwith Aelfine");
    set("aggressive", 0);
    set_long(
@TABOR
Cirtwith Aelfine is an old wizard who appears to frown all of the time. 
Despite the frown, he doesn't seem praticularly upset or unhappy, it 
appears to be more of a look of intense concentration. Given the state 
of his store, you imagine that he needs every bit of his concentration 
to actually find items that his customers ask for.

To get you a list of shop commands, type <help shop>.
TABOR
	);
    set_gender("male");
    set_alignment(4);
    set("race", "human");
    set_class("mage");
    set_hd(30,2);
    set_level(30);
    set_guild_level("mage",30);
    set_body_type("human");
    set_property("no bump", 1);
    set_wielding_limbs( ({ "right hand","left hand" }) );
   set_emotes(4,({"%^MAGENTA%^Cirtwith says%^RESET%^: If I "+
        "actually had time to catalog this stuff, I'd probably have "+
        "every spell component known to magi.",
        "%^MAGENTA%^Cirtwith says%^RESET%^: I'm getting as scatterbrained "+
        "as that twerp, Llewddyn.\nCirtwith chuckles to himself.",
        "%^MAGENTA%^Cirtwith says%^RESET%^: Oh look!  An archmage.  Seems "+
        "like they are a dime a dozen these days.  In the old days....",
        "%^CYAN%^BOLD%^Cirtwith whispers%^RESET%^: I hear Llewddyn sells "+
        "fake bat guano because he can't stand the smell of the real stuff.  "+
        "You're better off with my quality guano.  Straight from a bat.",
        "Cirtwith snickers.",
        "Cirtwith snickers.",
        "Cirtwith snorts.",
        "Cirtwith casts a baleful stare at a pile of miscellaneous crap in a corner.",
        "Cirtwith snorts."}), 0);
    set_emotes(20, ({"%^MAGENTA%^Cirtwith says%^RESET%^: Great. "+
        "Now this place is going to be an even bigger mess.",
		"%^MAGENTA%^BOLD%^Cirtwith yells%^RESET%^: Okay, now you've done it, "
		"Get out of my store!!",
		"%^MAGENTA%^Cirtwith says%^RESET%^: You're about to find out where my "+
		"drop of blood supply comes from!",
		"%^MAGENTA%^Cirtwith says%^RESET%^: What was the incantation for "+
		"meteor swarm again?  Hmm...."}), 1);
    set_components(100);
    set_spell_chance(100);
    set_spells(({"fireball","lightning bolt","acid arrow",
        "powerword stun", "incendiary cloud", "magic missile"}));
    set_property("strength","spells");
}
