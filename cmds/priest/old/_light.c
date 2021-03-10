#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("light");
	set_spell_level(1);
	set_spell_type("priest");
	set_spell_sphere("sun");
}

spell_effect() {
    object ob;
    int level;
	::spell_effect();
	level = TP->query_level();
	if(level > 20) level = 20;
	tell_object(CASTER, "You create a mystical light source.");
	tell_room(environment(CASTER), CASTER->query_cap_name()+" makes a mystical light source.", CASTER);
	ob = new("/cmds/priest/obj/light");
	ob->set_duration(3600+(level * 60));
	if(!TARGET)
	    ob->move((TP));
	else
	    ob->move((TARGET));
	CASTER->set_casting(4);
	
}
int help(string str){
write(
@HELP
Level  : 1st level
Sphere : Sun
Syntax : <cast light ( on [object || char] ) >

Will create a small ball of light, which will
light your way. You can optionally cast it on 
an object or char which it will follow, instead
of the caster.

HELP
);
}

