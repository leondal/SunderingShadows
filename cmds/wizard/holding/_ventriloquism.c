//

#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("ventriloquism");
	set_spell_level(1);
	set_spell_type("wizard");
	set_spell_sphere("Illusion_phantasm");
	set_components(([
	"cone of parchment" : 0,
	]));
}

spell_effect() {
	::spell_effect();
}

//  I was thinking that this spell will give the player 'echo' 
// abilities with a saving throw taken on all in the room.  There
// will be an invisible object created that wil have the proper 
// add_actions.  At a certain point the object will be destructed.
// /d/magic/etc/ventr.c will be the name.
