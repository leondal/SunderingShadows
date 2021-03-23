#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
    ::create();
    set_spell_name("inspiring recovery");
    set_spell_level(([ "cleric" : 6, "ranger" : 4, "paladin" : 4, "inquisitor" : 6 ]));
    set_affixed_spell_level(6);
    set_spell_sphere("healing");
    set_syntax("cast CLASS inspiring recovery on TARGET");
    set_damage_desc("positive/negative energy");
    set_description("You channel a beam of own energy at target, healing them. If the target is deceased, the beam instead will try to return them to life into their body. The type of energy depends on who is the caster. Undead will use negative energy, living will use positive energy.

This spell accepts recognized players name or their corpse as the TARGET if they are deceased.
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
    string what, theirname, dam_type;
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
        if(caster->is_undead())
        {
            tell_room(place,"%^BLUE%^"+caster->QCN+" points "+caster->QP+" hand at "+target->QCN+" and channels a beam of darkness energy into them!");
            dam_type = "negative energy";
            if(!target->is_undead())
                set_helpful_spell(0);
        }
        else
        {
            tell_room(place,"%^ORANGE%^"+caster->QCN+" points "+caster->QP+" hand at "+target->QCN+" and channels a beam of light into them!");
            dam_type = "positive energy";
            if(target->is_undead())
                set_helpful_spell(0);
        }
        damage_targ(target, "torso", sdamage, dam_type);
    }
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
