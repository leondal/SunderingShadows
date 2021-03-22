// Detect Invisibility
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

void create() {
    ::create();
    set_spell_name("detect invisibility");
    set_spell_level(([ "mage" : 2, "bard" : 3, "inquisitor" : 2, "magus" : 3, "cleric" : 3 ]));
    set_domains(({"law"}));
    set_spell_sphere("divination");
    set_syntax("cast CLASS detect invisibility");
    set_description("Detect invisibility will let a mage see all magically invisible and even hidden people in the near vicinity. The spell's duration gets longer as the mage grows in level.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "talc" : 1, "powdered silver" : 1, ]),
    ]));
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^GREEN%^"+caster->QCN+" closes "+
    caster->QP+" eyes and growls "+
    "undecipherable words.";
}

int preSpell(){
    if(caster->detecting_invis()){
        tell_object(caster, "You are already detecting invisible.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int bonus = prof;

    oldenv=environment(caster);
    spell_successful();
    tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+
              caster->QCN+"'s eyes snap open and flash "+
              "bright green for an instant.",caster);
    tell_object(caster,"%^BOLD%^%^GREEN%^Your eyes snap open and flash bright green for an instant.");
    caster->set_detecting_invis(1);
    caster->set_property("spelled", ({TO}) );
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
}

void flip(int onOff){
    if(objectp(caster)){
        caster->set_detecting_invis(onOff);
        call_out("flip",random(20),!onOff);
    }
}



void dest_effect() {

    if (objectp(caster)) {
        tell_object(caster,"%^BOLD%^%^GREEN%^Your eyes hurt for a moment and you "+
                    "close them, then they flutter open quickly.");
        tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->QCN+
                  " closes "+caster->QP+" eyes tightly in apparent "+
                  "pain, then they flutter open and "+caster->QS+
                  " peers around.",caster);
        caster->set_detecting_invis(0);
        caster->remove_property_value("spelled", ({TO}) );
        remove_call_out("flip");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
