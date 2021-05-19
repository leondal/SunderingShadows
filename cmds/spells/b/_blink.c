//
//added the checks for mage armor from armor code -Tsera 11/5/04
#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("blink");
    set_spell_level(([ "mage" : 3, "bard" : 3, "magus" : 3 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS blink");
    set_damage_desc("35% miss chance");
    set_description("With a snap of the fingers, the mage can start to blink between the prime and ethereal planes. This will give a chance for melee attacks to simply pass right through their form, while it is incorporeal. The chance to miss is thirty five percent.

%^BOLD%^%^RED%^N.B.%^RESET%^ Will only work while wearing no armor.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^CYAN%^With a wave of "+caster->QP+" hands and a deep breath, "+caster->QCN+" starts to cast.";
}

int preSpell() {
    if (caster->query_property("amorpha") || caster->query_property("timeless body")) {
//together these are broken, stacking regularly 100% miss chance. N, 4/14
        tell_object(caster, "You can't maintain such a spell while under a concealment illusion.");
        return 0;
    }
    if (caster->query_blinking()) {
        tell_object(caster, "You are already blinking!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {

    int bonus = prof/10 - 10;
    if (!caster->is_ok_armour("mage"))
    {
        if(!FEATS_D->usable_feat(caster,"armored caster") && !FEATS_D->usable_feat(caster,"eldritch conditioning"))
        {
            tell_object(caster,"The spell can not offer protection to those wearing armor.");
            TO->remove();
            return;
        }
    }

    tell_room(place, "%^BOLD%^"+caster->QCN+" speaks quickly to "+caster->QO+"self and looks around furtively.  "+capitalize(caster->QP)+" body starts to blur!",caster);
    tell_object(caster, "%^BOLD%^You start to cast the spell and you feel your body start to blur, blinking between reality and etherealness.");

    caster->set_property("spelled", ({TO}) );
    caster->set_property("amorpha",1);
    caster->set_missChance(caster->query_missChance()+ 35);
    spell_successful();
    addSpellToCaster();
    call_out("test", 2);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void test() {
// added to avoid errors when the spell has already dested *Styx* 11/14/04
    if (!objectp(TO) || !objectp(caster))
        return;
    if (!caster->is_ok_armour("mage"))
    {
        if(!FEATS_D->usable_feat(caster,"armored caster") && !FEATS_D->usable_feat(caster,"eldritch conditioning"))
        {
            tell_object(caster,"The spell can not offer protection to those wearing armor.");
            TO->dest_effect();
            return;
        }
    }
    call_out("test", 5);  // added to keep it checking periodically *Styx* 11/14/04
}

void dest_effect() {
    int chance;
    remove_call_out("test");  // clean up open call_out
    if (!objectp(caster)) {
        TO->remove();
        return;
    }

    tell_object(caster, "%^BOLD%^%^YELLOW%^You feel yourself slow down a great deal, becoming fully corporeal again.");
    tell_room(environment(caster), "%^BOLD%^%^YELLOW%^"+caster->QCN+" slows down from a blur.",caster);
    chance = (int)caster->query_missChance()-35;
    caster->set_missChance(chance);
    caster->remove_property("amorpha");
    caster->remove_property_value("spelled", ({TO}) );
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
