#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create() {
	::create();
    set_spell_name("mass castigate");
    set_spell_level(([ "inquisitor" : 5,  ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS mass castigate");
    set_damage_desc("cowering, shaken on save");
    set_description("You compel the target to beg for forgiveness. On a failed save, the target cowers with fear. On a successful save, it is shaken for 1 round.  A creature who worships the same god as you takes a penalty on its saving shrow.");
    set_verbal_comp();
    set_somatic_comp();
    mental_spell(1);
    splash_spell(3);
    set_save("will");
}

string query_cast_string(){
    return "%^RESET%^%^RED%^"+caster->QCN+"%^RESET%^%^RED%^'s eyes darken as dread emanates from "+caster->QO+".%^RESET%^";
}

void spell_effect(int prof){
    int bonus;
    object attackers;

    if(!objectp(target))
        dest_effect();

    caster->force_me("yell %^RED%^%^BOLD%^BEG FORGIVENESS.");

    spell_successful();
    bonus = (int)caster->query_stats("intelligence");
    bonus = (bonus - 10) / 2;
    if(target->query_diety() == caster->query_diety())
        bonus += 8;
    bonus = -bonus;//negative bonus is bonus to you, positive to them

    attackers = target_selector();

    foreach(target in attackers)
    {
        if(mind_immunity_damage(target))
        {
            spell_successful();
            dest_effect();
            continue;
        }
        if(do_save(target,bonus))
        {
            tell_object(target, "%^RESET%^%^RED%^You fight compulsion to fall onto your knees.%^RESET%^");
            tell_room(place,"%^RESET%^%^RED%^"+target->QCN+" grimmaces and shakes "+target->QP+" head, fighting off the mental attack.%^RESET%^",target);

            "/std/effect/status/shaken"->apply_effect(target,roll_dice(1,6));
        }
        else
        {
            tell_object(target,"%^BOLD%^%^RED%^You drop to your knees, cowering, and begging for forgiveness.%^RESET%^");
            tell_room(place, "%^BOLD%^%^RED%^Sheer horror contorts "+target->QCN+"'s face as "+target->QS+" drop onto the knees and beg for forgiveness.%^RESET%^",target);
            "/std/effect/status/cowering"->apply_effect(target,roll_dice(1,6));
        }
    }

    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
