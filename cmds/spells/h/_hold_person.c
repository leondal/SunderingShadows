#include <std.h>
#include <daemons.h>
#include <spell.h>

//#define BODY_TYPES ({"human","merperson","elf","goblin","orc","gnome","drow","halfling","half-elf","bugbear","dwarf","beastman","centaur","hobgoblin","minotaur","half-orc","lizardman","kobold"})

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("hold person");
    set_spell_level( ([ "mage" : 3, "bard" : 2, "cleric" : 2, "monk" : 5, "inquisitor" : 2, "paladin" : 2, "psion" : 4 ]) );
    set_spell_sphere("enchantment_charm");
    set_monk_way("way of the elements");
    set_discipline("kineticist");
    set_syntax("cast CLASS hold person on TARGET");
    set_description("This spell will hold its target for rounds that reflect the level of the caster.");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
        "mage" : ([ "piece of iron" : 1, ]),
    ]));
    set_save("will");
    set_immunities( ({ "spell_immunity"}) );
}


void spell_effect(int prof)
{
    int change;

    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }

    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return;
    }

    if (target->query_race())
    {
        if (member_array((string)target->query_race(),VALID_BACKS) == -1)
        {
            tell_object(caster,"%^BOLD%^Your target is not a person!%^RESET%^");
            dest_effect();
            return;
        }
    }

    if (target->query_property("no hold") || target->query_property("no paralyze"))
    {
        tell_object(caster,"%^YELLOW%^You spell disperses futilely around "+target->QCN+".\n");
        dest_effect();
        return;
    }

    if (target->query_property("magic resistance"))
    {
        if (target->query_property("magic resistance") < random(99) +1)
        {
            tell_object(caster,"%^BOLD%^%^ORANGE%^You feel your spell take a grasp on "+target->QCN+" but then disperse as its power is rendered useless!\n");
            tell_object(target,"%^BOLD%^%^ORANGE%^You feel a spell attempt to grip your mind, but the grip slips and you are freed from it.\n");
            spell_kill(target,caster);
            dest_effect();
            return;
        }
    }
    if (target->query_size()>2)
    {
        tell_object(caster,"%^BOLD%^%^ORANGE%^You feel your spell take a grasp on "+target->QCN+" but then disperse as its power is rendered useless!\n");
        tell_object(target,"%^BOLD%^%^ORANGE%^You feel a spell attempt to grip your mind, but the grip slips and you are freed from it.\n");
        spell_kill(target, caster);
        dest_effect();
        return;
    }

    change = ((int)target->query_stats("wisdom") - 10) / 2;

    if(!spell_kill(target,caster))
    {
        if(objectp(TO)) TO->remove();
        return;
    }

    if(do_save(target,change))
    {
        tell_object(caster,"%^BOLD%^%^ORANGE%^You feel your spell take a grasp on "+target->QCN+" but then disperse as its power is rendered useless!\n");
        tell_object(target,"%^BOLD%^%^ORANGE%^You feel a spell attempt to grip your mind, but the grip slips and you are freed from it.\n");
        TO->remove();
        return;
    }

    if(mind_immunity_damage(target, "default"))
    {
        spell_successful();
        dest_effect();
        return;
    }

    target->set_paralyzed(roll_dice(1, 4) * 8,"%^BOLD%^%^CYAN%^Your mind is caught within the grips of a spell!");

    if(spell_type == "monk")
    {
        tell_room(environment(caster), caster->QCN+"%^BOLD%^%^GREEN%^ stares intently at "+target->QCN+"!\n", ({caster, target}));
        tell_object(caster, "%^BOLD%^%^GREEN%^You focus you ki, staring intently at "+target->QCN+"!\n");
        tell_object(target, caster->QCN+"%^BOLD%^%^GREEN%^ stares intently at you!\n");
    }
    else
    {
        tell_room(environment(caster),"%^BOLD%^%^GREEN%^"+caster->QCN+" holds the piece "
            "of iron up and concentrate upon it!",({caster}));
        tell_object(caster,"%^BOLD%^%^GREEN%^You hold up the piece of iron and concentrate upon "
            "it, focusing on it and "+target->QCN+"!\n");
    }

    tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+" looks at "
        ""+target->QCN+" and a small wave rushes forth and seizes "
        ""+target->QP+" head, forcing "+target->QO+" to "
        "mimic the rigidness of the iron!",({caster,target}));
    tell_object(caster,"%^BOLD%^%^RED%^You send a wave rushing toward "+target->QCN+" "
        "which seizes "+target->QP+" head, forcing "+target->QO+" to "
        "mimic the rigidness of the iron!\n");
    tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+" looks at you and a small "
        "wave rushes forth and seizes your head, forcing you to mimic the rigidness of the iron!\n");
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
