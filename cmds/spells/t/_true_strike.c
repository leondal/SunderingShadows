#include <std.h>
#include <magic.h>
inherit SPELL;

int thebonus;

void create() {
    ::create();
    set_spell_name("true strike");
    set_spell_level(([ "mage" : 1, "inquisitor" : 1, "magus" : 1, "cleric" : 1 ]));
    set_spell_sphere("divination");
    set_bonus_type("insight");
    set_domains(({"destruction", "fate"}));
    set_syntax("cast CLASS true strike on TARGET");
    set_damage_desc("clevel/3 to attack bonus for clevel/12+1 rounds");
    set_description("Gaining insight on future events, caster can grant anyone knowledge of how to exploit it to make a strikes unlikely to miss for the next few rounds

%^BOLD%^See also:%^RESET%^ true strikes *feats");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

void spell_effect(int prof) {
    if (!objectp(caster)) return;
    if(!objectp(target))
    {
        tell_object(caster,"You don't see that target here!");
        return;
    }
    if(target != caster){
        tell_object(caster,"%^BOLD%^%^CYAN%^You touch "+target->QCN+", granting "+target->QO+" a temporary insight into events as they unfold.%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches you, granting a temporary insight into events as they unfold.%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches "+target->QCN+", they both seem lethargic for a moment.%^RESET%^",({caster,target}));
    }
    else {
        tell_object(caster,"%^BOLD%^%^CYAN%^You touch your forehead, granting yourself a temporary insight into events as they unfold.%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" touches "+caster->QP+" forehead, and seems lethargic for a moment.%^RESET%^");
    }
//    target->set_property("attack bonus",clevel);
    thebonus = clevel / 3;
    target->add_attack_bonus(thebonus);
    addSpellToCaster();
    spell_duration = (clevel / 10 + 1) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^BOLD%^%^CYAN%^An insight into future events fades%^RESET%^");
//        target->set_property("attack bonus",-clevel);
        target->add_attack_bonus(-1*thebonus);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
