#include <std.h>
#include <spell.h>

inherit SPELL;

string * GIBBERISH = ({
            "Bye!",
            "Do you respect me?!",
            "Great pillows!",
            "I am the king! Kneel!",
            "I am the queen! Kneel!",
            "I like heat in a certain way!",
            "I love you!",
            "I really don't!",
            "I reject your accusations!",
            "I stink!",
            "It's a rough situation over here!",
            "Join me, I have cookies!",
            "Let me join you!",
            "Look! Over there!",
            "No collusion!",
            "Nobody knows what who knows!",
            "Our country is the best!",
            "The moon is fluffy today!",
            "Together we will make the world great again!",
            "We all are fighting battles!",
            "What's happening is a disgrace!",
            "Who knows, you know?!",
            "You know what you know you know?!",
            "You stink!",
            "You're mean! Bye!",
            "Your shoes are untied!",
            "Your mother was a hamster!",
            "You father smelt of elderberries!",
            "I fart in your general direction!",
            "Klaatu barada nikto",
            "Are you threatening me?",
                });

create()
{
    ::create();
    set_spell_name("word of chaos");
    set_spell_level(([ "cleric" : 7, "inquisitor" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS word of chaos on TARGET");
    set_description("You shout some gibberish. Upon hearing it, the target may be briefly stunned, confused, or even die from such nonsense. A will save will negate some of the effects.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^You can feel a chaotic presence building inside as you chant the words of chaos.");
    tell_room(place,"%^BOLD%^"+caster->QCN+" chants some gibberish.",caster);
    return "display";
}


void spell_effect()
{
    int ldiff;

    ldiff=(clevel-target->query_level());

    caster->force_me("yell %^WHITE%^%^BOLD%^"+GIBBERISH[random(sizeof(GIBBERISH))]);

    if(!do_save(target,4))
    {
        tell_room(place,"%^BOLD%^"+target->QCN+" stops for a moment with a thoughtful expression.",target);
    tell_object(target,"%^BOLD%^%^You are stunned by this utter nonsense.");
    target->set_paralyzed(8*2,"You are stunned by the gibberish you just heard.");
    }

    if(ldiff>4)
    {
        "/std/magic/confusion"->confuse(caster,target);
    }

    if(ldiff>9)
    {
        if(!(do_save(target,4)||
             target->query_property("no death")))
        {
            tell_room(place,"%^BOLD%^Upon hearing the words "+target->QCN+" simply explodes!",target);
            tell_object(target,"%^BOLD%^WHAT "+caster->QS+" DID JUST SAY");
            damage_targ(target,target->return_target_limb(),target->query_max_hp()*2,"mental");
        }
    }

    dest_effect();
    return;
}
