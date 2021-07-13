//touchsight.c
//~Circe~ 7/22/05
#include <spell.h>
#include <magic.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("touchsight");
    set_spell_level(([ "psion" : 3, "psywarrior" : 3 ]));
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS touchsight");
    set_description("Manifesting this power will allow the psionic character to focus his eyes on things oft unseen.  This power will "
"grant the psion better vision in the dark, as well as allow him to see invisible creatures.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
}

string query_cast_string() {
    return "%^BLACK%^%^BOLD%^"+caster->QCN+" closes "+caster->QP+" eyes "+
       "and touches both temples with "+caster->QP+" forefingers.%^RESET%^";
}

int preSpell(){
    if(caster->detecting_invis()){
        tell_object(caster, "You are already able to detect invisible creatures.");
        return 0;
    }
    return 1;
}

spell_effect(int prof) {
    spell_successful();
    tell_room(environment(caster),"%^BOLD%^%^WHITE%^"+caster->QCN+" opens "+
      ""+caster->QP+" eyes wide, briefly revealing an %^RED%^i%^RESET%^%^ORANGE%^r"+
       "%^YELLOW%^i%^GREEN%^d%^CYAN%^e%^BLUE%^s%^RESET%^%^BLUE%^c%^MAGENTA%^"+
       "e%^BOLD%^n%^RED%^t %^WHITE%^iris!",caster);
    tell_object(caster,"%^BOLD%^%^WHITE%^Your eyes open, and you view "+
       "the world through an %^RED%^i%^RESET%^%^ORANGE%^r"+
       "%^YELLOW%^i%^GREEN%^d%^CYAN%^e%^BLUE%^s%^RESET%^%^BLUE%^c%^MAGENTA%^"+
       "e%^BOLD%^n%^RED%^t %^WHITE%^gleam for a moment.");
    caster->set_detecting_invis(1);
    caster->add_sight_bonus(3);
    caster->set_property("spelled", ({TO}) );
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}


void dest_effect() {

    if (objectp(caster)) {
        tell_object(caster,"%^BOLD%^%^WHITE%^You feel the hidden power "+
           "within your eyes fade away, leaving you mildly disoriented briefly.");
        tell_room(environment(caster),"%^BOLD%^%^WHITE%^"+caster->QCN+" "+
           "looks dazed for a moment before blinking and looking around.",caster);
        caster->set_detecting_invis(0);
        caster->add_sight_bonus(-3);
        caster->remove_property_value("spelled", ({TO}) );
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
