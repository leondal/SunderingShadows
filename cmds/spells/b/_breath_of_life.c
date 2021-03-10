#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
    ::create();
    set_spell_name("breath of life");
    set_spell_level(([ "cleric" : 5,"oracle":5, "psion" : 5 ]));
    set_mystery("life");
    set_domains("renewal");
    set_affixed_spell_level(5);
    set_spell_sphere("conjuration_summoning");
    set_discipline("egoist");
    set_syntax("cast CLASS breath of life on TARGET");
    set_damage_desc("positive energy");
    set_description("You channel a beam of your own energy at the target, healing them. If the target is deceased, the beam will instead try to return them to life.

This spell accepts the recognized player's name or their corpse as the TARGET if they are deceased.
");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_non_living_ok(1);
	set_helpful_spell(1);
}

string what_alignment(int align)
{
    string alignment;
    switch(align)
    {
    case 1: alignment = "Lawful Good"; break;
    case 2: alignment = "Lawful Neutral"; break;
    case 3: alignment = "Lawful Evil"; break;
    case 4: alignment = "Neutral Good"; break;
    case 5: alignment = "True Neutral"; break;
    case 6: alignment = "Neutral Evil"; break;
    case 7: alignment = "Chaotic Good"; break;
    case 8: alignment = "Chaotic Neutral"; break;
    case 9: alignment = "Chaotic Evil"; break;
    }
    return alignment;
}

spell_effect(int prof) {
    string what, theirname;
    object corpse, targ;

    ::spell_effect();

    if(!objectp(target))
    {
        theirname = caster->realName(lower_case(arg));
        target = find_player(theirname);
    }

    if(!objectp(target))
    {
        tell_object(caster,"The target is needed.");
        dest_effect();
    }

    if(target->is_corpse()||target->query_ghost())
    {
        if(target->is_corpse())
            corpse = target;
        else
            corpse = present("corpse of $&$"+target->query_true_name()+"$&$",place);

        if (!interactive(target)) {
            tell_object(caster,"You can only revive interactive players.");
            dest_effect();
            return;
        }
        if (interactive(caster) ) {
            set_cast_string(caster->QCN+" calls upon the magic!\n");
            tell_object(caster, "%^ORANGE%^You attempt to raise "+capitalize(arg)+" from the dead.");
            tell_room(environment(CASTER), "%^ORANGE%^"+caster->QCN+" tries to bring the dead "+capitalize(arg)+" back among the living.", ({ caster, target}));
        } else {
            set_cast_string(caster->QCN+" prays for the gods to raise "+capitalize(arg)+" from the dead!\n");
        }
        if (!target->query_ghost()) {
            tell_object(caster,capitalize(arg)+" does not need to be revived.");
            dest_effect();
            return;
        }
        if (!objectp(corpse)) {
            tell_object(caster,capitalize(arg)+"'s corpse is not here.");
            tell_object(target,"You think you feel a faint pull on your soul, but it is gone as soon as it begins.");
            dest_effect();
            return;
        }
        tell_object(caster,"%^ORANGE%^You can feel the power of magic flow out to "+target->QCN+"'s soul, and know that "+target->QP+" life is in "+target->QP+" own hands now.");
        tell_room(environment(caster),"The power of "+caster->QCN+"'s spell flows through the area as "+caster->QS+" tries to bring "+target->QCN+" back to life!",caster);
        target->set("RaisingPriestGod",caster->query_diety());
        target->set("RaisingPriestAlignment",caster->query_alignment());
        target->set("RaisingRoom",base_name(environment(caster)));
        target->set("RaisingExpLoss",(-10+(random(2)+random(3)+1)));
        target->set("RaisingType","raise dead");
        tell_object(target,"%^RESET%^%^WHITE%^%^BOLD%^You can feel a pull on your soul. You sense that a faithful of "+capitalize((string)caster->query_diety())+" is trying to return you to life!\nType %^ORANGE%^<accept>%^WHITE%^ to return to life, or %^ORANGE%^<cancel>%^WHITE%^ to die.%^RESET%^");
        corpse->remove();
    }
    else
    {
        tell_room(place,"%^ORANGE%^"+caster->QCN+" points "+caster->QP+" hand at "+target->QCN+" and channels a beam of light into them!");
        if(target->is_undead())
            set_helpful_spell(0);
        damage_targ(target, "torso", sdamage,"positive energy");
    }
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
