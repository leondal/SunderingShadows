//modified from Detect Magic by
//~Circe~ 7/20/05

#include <std.h>
#include <priest.h>
#include <daemons.h>

void create() {
    ::create();
    set_spell_name("detect aura");
    set_spell_level(([ "psion" : 1, "psywarrior" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect aura");
    set_description("This power allows a psion to see the mystical auras surrounding some objects in the world, whether "
"they be divine, arcane, or psionic in nature.  The psion attunes himself to the world through this power, seeing the "
"auras as a glow that strengthens or lessens based upon the power of the item.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

query_cast_string() {
   return "%^CYAN%^"+YOU+" closes "+MINE+" eyes briefly, concentrating.";
}

void spell_effect(int prof) {
    int magic;
    string what;
    object ob;

    tell_object(caster,"%^BOLD%^%^CYAN%^You focus your mind to see "+
       "the hidden auras of the world.");
    caster->set_detecting_magic(1);
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (objectp(caster)) {
        caster->set_detecting_magic(0);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
