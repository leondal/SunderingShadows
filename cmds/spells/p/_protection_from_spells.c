#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;

void create() {
    ::create();
    set_spell_name("protection from spells");
    set_spell_level(([ "mage" : 8,"inquisitor":5,"oracle":6 ]));
    set_spell_sphere("abjuration");
    set_mystery("dragon");
    set_bonus_type("resistance");
    set_domains("magic");
    set_damage_desc("clevel / 6 + 2 but no more than 5 to all saves");
    set_syntax("cast CLASS protection from spells on TARGET");
    set_description("Using this power will allow a mage or sorcerer to temporarily raise the target's "
"resistance to spells of all kinds.  This is only a temporary state, however, and will fade after a "
"short while.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" holds up a tiny d%^BOLD%^%^WHITE%^ia%^BOLD%^%^CYAN%^m"
"%^BOLD%^%^WHITE%^on%^BOLD%^%^CYAN%^d, light glinting from its facets.";
}

int preSpell()
{
    if(target->query_property("protection from spells"))
    {
        tell_object(caster,"The target is already under the influence of a similar effect.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    if (!objectp(caster)) return;
    if(!objectp(target))
    {
        tell_object(caster,"You don't see that target here!");
        return;
    }
    tell_room(place,"%^BOLD%^%^CYAN%^The diamond held in "
        +caster->QCN+"'s fingertips g%^BOLD%^%^WHITE%^li"
        "%^BOLD%^%^CYAN%^tt%^BOLD%^%^WHITE%^er%^BOLD%^%^CYAN%^s "
        "brightly, the sparks spreading across "+target->QCN+
        " in a brilliant wave!",({caster,target}));
    if(target == caster){
        tell_object(caster,"%^BOLD%^%^CYAN%^The diamond held between "
        "your fingertips g%^BOLD%^%^WHITE%^li%^BOLD%^%^CYAN%^tt"
        "%^BOLD%^%^WHITE%^er%^BOLD%^%^CYAN%^s brightly, the "
        "sparks spreading across you in a brilliant wave!");
    }
    else{
        tell_object(caster,"%^BOLD%^%^CYAN%^The diamond held between "
        "your fingertips g%^BOLD%^%^WHITE%^li"
        "%^BOLD%^%^CYAN%^tt%^BOLD%^%^WHITE%^er%^BOLD%^%^CYAN%^s "
        "brightly, the sparks spreading across "+target->QCN+
        " in a brilliant wave!");
        tell_object(target,"%^BOLD%^%^CYAN%^The diamond held between "
        +caster->QCN+"'s fingertips g%^BOLD%^%^WHITE%^li%^BOLD%^%^CYAN%^tt"
        "%^BOLD%^%^WHITE%^er%^BOLD%^%^CYAN%^s brightly, the "
        "sparks spreading across you in a brilliant wave!");
    }
    if(target->query_property("protection from spells")){
        tell_object(caster,"%^BOLD%^The power is repelled forcibly.");
        tell_object(target,"%^BOLD%^The power is repelled forcibly.");
        dest_effect();
        return;
    }

    lower = 5;
    //lower = clevel / 6 + 2;
    //lower = lower > 8 ? 8 : lower;
    target->add_saving_bonus("all",lower);
    target->set_property("protection from spells", 1);
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect(){

    if(objectp(target))
    {
        target->add_saving_bonus("all",-lower);
        target->remove_property("protection from spells");
        tell_room(environment(target),"%^RESET%^%^CYAN%^The air suddenly seems to grow dull as "
        "a wave of energy dissipates from the air around "+target->QCN+".%^RESET%^",target);
        tell_object(target,"%^RESET%^%^CYAN%^The air suddenly seems to grow dull as "
        "a wave of energy dissipates from the air around you!%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
