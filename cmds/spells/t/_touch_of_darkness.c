#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("touch of darkness");
    set_spell_level(([ "innate" : 5 ]));
    set_domains("darkness");
    set_spell_sphere("illusion");
    set_syntax("cast innate touch of darkness");
    set_damage_desc("20% miss chance");
    set_description("You call on the shadows to protect you, gaining 20% concealment. This spell costs one Divine Grace point to cast.");
    set_helpful_spell(1);
}

int preSpell() {
    if (caster->query_property("amorpha") || caster->query_property("timeless body")) {
        tell_object(caster, "You can't maintain such a spell while under a concealment illusion.");
        return 0;
    }
    if (caster->query_blinking()) {
        tell_object(caster, "You are already blinking!");
        return 0;
    }

    if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to cast Touch of Darkness!");
        return 0;
    }

    return 1;
}

void spell_effect(int prof) {

    int bonus = prof/10 - 10;

    tell_room(place, "%^MAGENTA%^"+caster->QCN+" speaks quickly to "+caster->QO+"self and looks around furtively.  "+capitalize(caster->QP)+" body starts to blur!",caster);
    tell_object(caster, "%^MAGENTA%^You start to cast the spell and you feel your body start to blur its movements..");

    caster->set_property("spelled", ({TO}) );
    caster->set_property("amorpha",1);
    caster->set_missChance(caster->query_missChance()+ 20);
    spell_successful();
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 5;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int chance;
    remove_call_out("test");  // clean up open call_out
    if (!objectp(caster)) {
        TO->remove();
        return;
    }

    tell_object(caster, "%^BOLD%^%^MAGENTA%^You feel the shadows blurring your movements fade.");
    tell_room(environment(caster), "%^BOLD%^%^MAGENTA%^"+caster->QCN+" slows down from a blur.",caster);
    chance = (int)caster->query_missChance()-20;
    caster->set_missChance(chance);
    caster->remove_property("amorpha");
    caster->remove_property_value("spelled", ({TO}) );
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
