#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("command");
    set_spell_level(([ "paladin" : 1, "cleric" : 1, "inquisitor" : 1, "psion" : 1, "warlock" : 1 ]));
    set_spell_sphere("enchantment_charm");
    set_discipline("telepath");
    set_syntax("cast CLASS command on TAGET to COMMAND");
    set_description("You intone a spelled command that the target has no choice but to obey. If the target succeeds the save or is immune, they will attack the caster.");
    set_save("will");
    mental_spell(1);
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
    set_feats_required(([ "warlock" : "book of shadows"]));
}

void spell_effect()
{
    string targ, command;

    if(sscanf(arg,"%s to %s",targ,command)!=2)
    {
        tell_object(caster,"<"+syntax+">");
        dest_effect();
        return;
    }

    if(!objectp(target = present(targ,place)))
    {
        tell_object(caster,"That is not here!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^MAGENTA%^You enspell your voice and command "+target->QCN+":%^RESET%^ "+command+"!");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" enspells "+caster->QP+" voice and commands "+target->QCN+"%^RESET%^!",caster);

    if(do_save(target,0)||
       target->query_property("no dominate",1)||
       mind_immunity_damage(target, "default"))
    {
        tell_room(environment(target),"Outraged at "+caster->QCN+" for "+caster->QP+" attempt at mind control, "+target->QCN+" attacks "+caster->QO+"!", ({target, caster}) );
        tell_object(target,"Outraged at "+caster->QCN+" for "+caster->QP+" attempt at mind control, you attack "+caster->QO+"!");
        tell_object(caster,""+target->QCN+" attacks you, outraged at you for your attempt at mind control!" );
        spell_kill(target, caster);
        return;
    }

    target->set_property("dominated",1);
    target->force_me(command);
    target->remove_property("dominated");
    spell_successful();
    return;
}
