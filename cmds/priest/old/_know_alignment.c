
#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("know_alignment");
	set_spell_level(2);
	set_spell_type("priest");
	set_spell_sphere("divination");
	set_target_required(1);
}

spell_effect() {
    int al;
    string align;
	::spell_effect();
	al = TARGET->query_alignment();
	align = capitalize(TARGET->query_al_title(al));
	tell_object(CASTER, "You cast know alignment on "+TARGET->query_cap_name());
	tell_object(CASTER, "You see that "+TARGET->query_cap_name()+ "'s alignment is "+align);
	CASTER->set_casting(5);
	
}
int help(string str){
write(
@HELP
Level  : 2nd level
Sphere : Divination
Syntax : <cast know alignment on [npc || char]>

Will detect npc or char's alignment. 

HELP
);
}

