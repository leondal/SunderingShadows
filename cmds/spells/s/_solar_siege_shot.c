#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("solar siege shot");
    set_spell_level(([ "mage" : 5, "oracle" : 5, "druid" : 5 ]));
    set_mystery("solar");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS solar siege shot on TARGET");
    set_damage_desc("divine, 4/3 times more to undead");
    set_description("With this spell conjures a ballista made out of solar energy, and then it takes a shot at your target. Undead take extra damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^As "+caster->QCN+" chants a huge siege ballista made of solar energy forms behind "+caster->QP+" back.%^RESET%^";
}

spell_effect(int prof)
{
    int dam = sdamage;
    if(target->is_undead())
        dam*=5/4;
    spell_successful();
    tell_room(place,"%^BOLD%^%^WHITE%^The ballista makes a shot at "+target->QCN+" and then disappears!");
    tell_room(place,"%^BOLD%^%^ORANGE%^A bolt made of light pierces "+target->QCN+"!");
    damage_targ(target, target->return_target_limb(), dam,"divine");
    TO->dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
