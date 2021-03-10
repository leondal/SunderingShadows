// Flaming Sphere

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("flaming sphere");
	set_spell_level(2);
	set_spell_type("wizard");
	set_spell_sphere("evocation");
	set_components(([
	"tallow" : 1,
	"sulfur" : 0,
	"powdered iron" : 0,
	]));
	set_visual_comp();
	set_semantic_comp();
}

spell_effect() {
	object sphere, caster;
	int clevel;
  	::spell_effect();
	caster=CASTER;
	clevel=caster->query_guild_level("mage");
	tell_room(environment(CASTER), "You see a sphere of fire appear"+
	" at the feet of "+caster->query_cap_name()+"\n");
	sphere=new(SPELL_OBJ_DIR+"fsphere");
	sphere->set_owner(caster);
	sphere->move(environment(caster));
	call_out("dest_sphere", ROUND_LENGTH * clevel, sphere);
}

void dest_sphere(object sphere) {
	tell_room(environment(sphere), "The flaming sphere disappears!!\n");
	sphere->move(ROOM_VOID);
	destruct(sphere);
	destruct(TO);
}


help() {
	write(
@HELP

HELP
	);
}

