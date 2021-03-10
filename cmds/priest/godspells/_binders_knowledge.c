//Based on Tongues - Cythera 6/05
#include <std.h>
#include <langs.h>
#include <daemons.h>

inherit SPELL;
int theProf;

create() {
    ::create();
    set_spell_name("binders knowledge");
    set_spell_level(4);
    set_spell_type("priest");
set_diety("oghma");
    set_spell_sphere("charm");
    set_verbal_comp();
}

query_cast_string() {
   return caster->query_cap_name()+" invokes the wisdom of Oghma.\n";
}

int preSpell() {

    if (target->query_property("langed")) {
      tell_object(caster,"%^BOLD%^Your target is already blessed with the knowledge of the Binder.");
        return 0;
    }
    if (!((string)target->query_diety()=="oghma")) {
        tell_object(caster,"%^BOLD%^Only the faithful may receive the Binder's Knowledge.");
        return 0;
    }
    return 1;
}


spell_effect(int prof) {
    	int i;
    	string what;
    	string arg;
    	object ob;
	theProf = prof;
    	tell_object(caster,"%^YELLOW%^You call to Oghma, seeking his knowledge and wisdom.");
    tell_object(target,"%^YELLOW%^You feel the knowledge of Oghma upon you, "+
		"filling your mind a greater understanding of languages.");
    spell_successful();
    
    for (i =0;i<sizeof(ALL_LANGS);i++) {
        	target->add_lang_overload(ALL_LANGS[i],prof);
	 	target->set_property("langed",1);
    		target->set_property("spelled", ({TO}) );

    }
    addSpellToCaster();
    caster->set_property("spelled",({TO}));
    call_out("dest_effect",clevel*16);
}

void dest_effect() {
    int i;
    ::dest_effect();
    if (objectp(target)) {
    for (i =0;i<sizeof(ALL_LANGS);i++) { 
        target->subtract_lang_overload(ALL_LANGS[i],theProf);
    }
    }  
    TO->remove();
}

void do_spell_blowup(int prof){
    MAGIC_D->fizzile(TO);
}

int help(string str) {
    write(
@HELP
Spell  : Binder's Knowledge
Level  : 4th Level
Deity  : Oghma
Sphere : Knowledge
Syntax : <chant binders knowledge on target>

This blessing allows the priest to call on the 
vast knowledge of Oghma.  The blessing comes in 
the form of a greater understanding of languages.  
Because the prayer is seens as a sacred gift from 
Oghma, only those who follow the Binder can recieve 
the benifits.

HELP
);
    return 1;
}
