//  sustenance
//  Feeds/waters the psion
//  ~Circe~ 7/19/05
#include <spell.h>
#include <daemons.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("sustenance");
    set_spell_level(([ "psion" : 2, "psywarrior" : 2 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS sustenance");
    set_description("By focusing his energies on the blue-green gem apatite, a psion can relieve himself of both hunger "
"and thirst.  This power can be especially useful to adventurers who oftentimes find themselves well away from the "
"nearest restaurant.");
    set_verbal_comp();
    set_somatic_comp();
    set_property("keywords", ({ "targeted", "personal" }));
	set_helpful_spell(1);
}

void spell_effect(int prof) {

    if (!target) target=caster;
    spell_successful();
    if (target == caster) {
        tell_object(caster,"%^CYAN%^You focus your energies through the "+
            "cut apatite crystal and feel your hunger and thirst fade away!");
        tell_room(place,"%^CYAN%^"+caster->QCN+" holds the apatite aloft, "+
            "making it glitter at "+caster->QP+" touch before "+
            "growing dull!", caster );
    } else {
       tell_object(caster,"%^BOLD%^Your mental powers can feed only you!");
       TO->remove();
       return;
    }
    if ((int)target->query_stuffed() < ((int)target->query_formula()) )
	target->add_stuffed(((int)target->query_formula()));
    if ((int)target->query_quenched() < ((int)target->query_formula()) )
	target->add_quenched(((int)target->query_formula()));
     
    if(objectp(TO)) TO->remove();
}

string query_cast_string() {
    return ""+caster->QCN+" raises a blue-green gem before "+caster->QP+" eyes.";
}
