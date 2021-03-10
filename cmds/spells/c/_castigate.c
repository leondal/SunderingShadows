#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create() {
	::create();
    set_spell_name("castigate");
    set_spell_level(([ "inquisitor" : 2,  ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS castigate on TARGET");
    set_damage_desc("cowering, shaken on save");
    set_description("You compel the target to beg for forgiveness. On a failed save, the target cowers with fear. On a successful save, the target is shaken for one round. A creature who worships the same god as you takes a penalty on its saving throw.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    mental_spell(1);
    set_save("will");
}

string query_cast_string(){
    return "%^RESET%^%^RED%^"+caster->QCN+"%^RESET%^%^RED%^'s eyes darken as dread emanates from "+caster->QO+".%^RESET%^";
}

void spell_effect(int prof){
    int i,j, percent, x, hits, bonus,mylevel;
    string *ids, MyType;
    object *weapons;
    if(!objectp(target))
        dest_effect();

    caster->force_me("yell %^RED%^%^BOLD%^BEG FORGIVENESS!");

    if(mind_immunity_damage(target))
    {
        spell_successful();
        dest_effect();
        return;
    }

    spell_successful();
    bonus = (int)caster->query_stats("intelligence");
    bonus = (bonus - 10) / 2;
    if(target->query_diety() == caster->query_diety())
        bonus += 8;
    bonus = -bonus;//negative bonus is bonus to you, positive to them

    if(do_save(target,bonus))
    {
        tell_object(target, "%^RESET%^%^RED%^You fight the compulsion to fall onto your knees.%^RESET%^");
        tell_room(place,"%^RESET%^%^RED%^"+target->QCN+" grimaces and shakes "+target->QP+" head, fighting off the mental attack.%^RESET%^",target);

        "/std/effect/status/shaken"->apply_effect(target,roll_dice(1,6));
    }
    else
    {
        tell_object(target,"%^BOLD%^%^RED%^You drop to your knees, cowering, and beg for forgiveness.%^RESET%^");
        tell_room(place, "%^BOLD%^%^RED%^Sheer horror contorts "+target->QCN+"'s face as "+target->QS+" drops to the floor and begs for forgiveness.%^RESET%^",target);
      "/std/effect/status/cowering"->apply_effect(target,roll_dice(1,6));
    }

    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
