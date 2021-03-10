#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int current,max,x;

void create()
{
    ::create();
    set_spell_name("microcosm");
    set_spell_level(([ "psion" : 9 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS microcosm on TARGET");
    set_description("When a psion manifests microcosm, he affects the target's mind to make him feel as though he is "
        "happily in a world of his own, effectively rendering the target utterly helpless.  The success of the power depends upon "
        "the might of the psion against the target's hardiness.");
    mental_spell();
    set_silent_casting(1);
    set_target_required(1);
    set_save("will");
}


void spell_effect(int prof)
{
    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    if(!caster->ok_to_kill(target))
    {
        tell_object(caster,"%^BOLD%^A magical force prevents you from "+
            "attacking "+target->QCN+"!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^YELLOW%^You call forth the image of a world "+
        "and bestow it upon "+target->QCN+"'s mind.");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" mouths a few syllables, "+
        "but you hear no sound.",({caster}));

    spell_kill(target, caster);

    if(target->query_property("no hold") || target->query_property("no paralyze"))
    {
        tell_object(target,"%^YELLOW%^The spell disperses futilely around you.");
        tell_room(place,"%^YELLOW%^The spell disperses futilely around "+
            ""+target->QCN+".",({target}));
        spell_successful();
        dest_effect();
        return;
    }

    if (checkMagicResistance(target,10 - prof/10))
    {
        sendDisbursedMessage(target);
        spell_successful();
        dest_effect();
        return;
    }

    if(do_save(target,-1*(clevel/7)))
    {
        tell_object(target,"%^BOLD%^You hear "+caster->QCN+"'s voice "+
            "whisper in your mind, '%^YELLOW%^A world of your own,%^WHITE%^"+
            "' before you shake off the power of the suggestion!%^RESET%^");
        tell_room(place,"%^BOLD%^"+target->QCN+" sways with "+
            ""+target->QP+" eyes closed before shaking "+target->QO+""+
            "self and blinking!",target);
        spell_successful();
        dest_effect(); //added missing spell-end here. Nienne, 10/09.
        return;
    }

    if(mind_immunity_damage(target, "default"))
    {
        target->add_attacker(caster);
        damage_targ(target, target->return_target_limb(), roll_dice(9,8),"mental");
        spell_successful();
        dest_effect();
        return;
    }

    tell_object(target,"%^BOLD%^You hear "+caster->QCN+"'s voice "+
        "whisper in your mind, '%^YELLOW%^A world of your own,%^WHITE%^"+
        "' before you fall helpless to the ground!");
    tell_room(place,"%^BOLD%^"+target->QCN+" sways and slumps to "+
        "the ground!",target);

    current = target->query_hp();
    max = target->query_max_hp();
    x = (current*100)/max;
    if(x > 90)
    {
        target->set_paralyzed(roll_dice(4,2)*8,"%^BOLD%^%^MAGENTA%^You are dancing about happily in your own perfect world!");
    }
    else if(x > 50)
    {
        target->set_paralyzed(roll_dice(6,2)*8,"%^BOLD%^%^MAGENTA%^You are dancing about happily in your own perfect world!");
    }
    else
    {
        target->set_paralyzed(roll_dice(8,2)*8,"%^BOLD%^%^MAGENTA%^You are dancing about happily in your own perfect world!");
    }
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
