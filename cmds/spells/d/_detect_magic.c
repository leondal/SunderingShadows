// Modified by PAtor@ShadowGate
// August 25 1995
#include <std.h>
#include <priest.h>
#include <daemons.h>

void create() {
    ::create();
    set_spell_name("detect magic");
    set_spell_level(([ "cantrip" : 1, "warlock" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect magic");
    set_description("Will allow the caster to view an aura of magic around objects or creatures they observe. The more "
"intense the aura the more magic is indicated. Particularly powerful magic may skew the view of other magics. For example "
"an especially magical creature might skew the view of the magic sword its wielding.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

query_cast_string() {
   return YOU+" concentrates carefully.\n";
}


int preSpell(){
    if(caster->get_static("detecting magic")){
        tell_object(caster, "You are already detecting magic.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int magic;
    string what;
    object ob;

    tell_object(caster,"%^BOLD%^You start to detect magic. The view of the world changes slightly.");
    caster->set_detecting_magic(1);
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 4;
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

void do_spell_blowup(int prof){
    MAGIC_D->fizzile(TO);
}
