#include <spell.h>
#include <magic.h>

inherit SPELL;

object oldenv, *conceal;
int i, num = 0;

void dest_effect();
object *invisobs();
void env_change();
void see_room();
void see_changes();

create() {
    ::create();
    set_spell_name("detect invisibility");
    set_spell_level(2);
    set_spell_type("priest");
    set_diety("mask");
    set_spell_sphere("divination");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^BLACK%^%^BOLD%^"+caster->query_cap_name()+" closes "+caster->query_possessive()+" eyes and whispers under "+caster->query_possessive()+" breath.%^RESET%^";
}

int preSpell(){
    if(caster->detecting_invis()){
        tell_object(caster, "You are already detecting invisible.");
        return 0;
    }
    return 1;
}

spell_effect(int prof) {
    caster=CASTER;
    oldenv=environment(caster);
    spell_successful();
    tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+
              caster->query_cap_name()+"'s eyes snap open and flash "+
              "bright green for an instant.",caster);
    tell_object(caster,"%^BOLD%^%^GREEN%^Your eyes snap open and flash bright green for an instant.");
    caster->set_detecting_invis(1);
    caster->set_property("spelled", ({TO}) );
//    call_out("dest_effect", clevel * 5 * ROUND_LENGTH);
    call_out("dest_effect", clevel * ROUND_LENGTH);
}


void dest_effect() {
    ::dest_effect();
    if (caster) {
        tell_object(caster,"%^BOLD%^%^GREEN%^Your eyes hurt for a moment and you "+
                    "close them, then they flutter open quickly.");
        tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->query_cap_name()+
                  " closes "+caster->query_possessive()+" eyes tightly in apparent "+
                  "pain, then they flutter open and "+caster->query_subjective()+
                  " peers around.",caster);
        caster->set_detecting_invis(0);
        caster->remove_property_value("spelled", ({TO}) );
    }
    TO->remove();
}

int help() {
    write(
@GRE
Spell  : Detect Invisibility
Level  : 2nd Level
Sphere : Divination
Deity  : Mask
Syntax : chant detect invisibility

This spell will allow Mask to gaze through your eyes, allowing you to see
objects and people around you that have been concealed from sight.
GRE

);
    return 1;
}
