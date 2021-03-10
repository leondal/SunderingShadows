//Meteor Swarm coded by Bane//
// Extensive damage formula change to hopefully put on par with other spells. Nienne, 03/09.
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("meteor swarm");
    set_spell_level(([ "mage" : 9, "oracle":9 ]));
    set_mystery(({"heavens","apocalypse"}));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS meteor swarm on TARGET");
    set_damage_desc("half bludgeoning, half fire or versatile arcanist");
    set_description("When the meteor swarm spell is cast, the target creature is assaulted by a swarm of flaming meteors, "
        "doing considerable damage.  Any other beings in the path may be engulfed in the explosion and also have a chance to "
        "receive some damage.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(1);
    set_target_required(1);
}


void spell_effect(int prof)
{
    object *foes, mycolor, element;
    int i;

    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }

    if(!present(target,place))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    element = (string)caster->query("elementalist");

    switch(element)
    {
    case "acid":        mycolor = "%^GREEN%^";      break;
    case "electricity": mycolor = "%^ORANGE%^";     break;
    case "fire":        mycolor = "%^RED%^";        break;
    case "sonic":       mycolor = "%^MAGENTA%^";    break;
    default:            mycolor = "%^RED%^"; element = "fire";  break;
    }

    switch(element)
    {
    case "acid":
        tell_object(caster,"%^BOLD%^%^GREEN%^You finish your chant and the area hisses under an explosion of searing acid!");
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" finishes "+caster->QP+" chant and the area hisses under an explosion of searing acid!",caster);
        tell_object(target,"%^GREEN%^A swarm of hissing meteors slams into you with tremendous force!");
        tell_room(place,"%^GREEN%^A swarm of hissing meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^GREEN%^";
        break;
    case "cold":
        tell_object(caster,"%^BOLD%^%^CYAN%^You finish your chant and the area crackles under an explosion of chilling ice!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" finishes "+caster->QP+" chant and the area crackles under an explosion of chilling ice!",caster);
        tell_object(target,"%^CYAN%^A swarm of frozen meteors slams into you with tremendous force!");
        tell_room(place,"%^CYAN%^A swarm of frozen meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^CYAN%^";
        break;
    case "electricity":
        tell_object(caster,"%^YELLOW%^You finish your chant and the area crackles with an explosion of sparks and static!");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" finishes "+caster->QP+" chant and the area crackles with an explosion of sparks and static!",caster);
        tell_object(target,"%^ORANGE%^A swarm of crackling meteors slams into you with tremendous force!");
        tell_room(place,"%^ORANGE%^A swarm of crackling meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^ORANGE%^";
        break;
    case "sonic":
        tell_object(caster,"%^BOLD%^%^MAGENTA%^You finish your chant and the area pulses under an explosion of sound!");
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" finishes "+caster->QP+" chant and the area pulses under an explosion of sound!",caster);
        tell_object(target,"%^MAGENTA%^A swarm of pulsing meteors slams into you with tremendous force!");
        tell_room(place,"%^MAGENTA%^A swarm of pulsing meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^MAGENTA%^";
        break;
    default:
        element = "fire";
        tell_object(caster,"%^BOLD%^%^RED%^You finish your chant and the area bleeds red with an explosion of sparks and fire!");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" finishes "+caster->QP+" chant and the area bleeds red with an explosion of sparks and fire!",caster);
        tell_object(target,"%^RED%^A swarm of meteors slams into you with tremendous force!");
        tell_room(place,"%^RED%^A swarm of meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^RED%^";
        break;
    }

    spell_successful();
    spell_kill(target, caster);
    damage_targ(target, target->return_target_limb(), sdamage/2, element);
    damage_targ(target, target->return_target_limb(), sdamage/2, "bludgeoning");

    foes = target_selector();
    foes -= ({ target });
    foes -= ({ caster });

    if(!sizeof(foes))
    {
        dest_effect();
        return;
    }

    for (i=0;i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) { continue; }
        if(!spell_kill(target,caster)) { continue; }

        tell_object(foes[i], ""+mycolor+"A meteor slams into you!");
        tell_room(place, ""+mycolor+"A meteor slams into "+foes[i]->QCN+"!", foes[i]);

        damage_targ(foes[i], foes[i]->return_target_limb(), sdamage/2, element);
        damage_targ(foes[i], foes[i]->return_target_limb(), sdamage/2, "bludgeoning");
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
