// orders oath
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("orders oath");
    set_spell_level(([ "paladin" : 2 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS orders oath on TARGET");
    set_damage_desc("paralyzed for 2d4 rounds");
    set_description("This spell magically enhances the power of the caster's voice.  The spell takes the form of a single "
        "spoken word, 'halt'.  The target need not understand the language of the spell for the magic to work.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^You can feel a commanding pressence "+
        "building inside, as you chant the enthralling words of this prayer.");
    tell_room(place,"%^BOLD%^"+caster->QCN+" strikes a commanding pose as "+
        ""+caster->QS+" chants through an enthralling prayer.",caster);
    return "display";
}

void spell_effect(int prof)
{
    int damage;
    if (!present(target,place))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return 1;
    }
    caster->force_me("yell %^BOLD%^%^WHITE%^H%^YELLOW%^A%^WHITE%^L%^YELLOW%^T%^WHITE%^!");
    //    if(!SAVING_D->saving_throw(target,"spell",0))
    if(!do_save(target,0))
    {
        if(mind_immunity_damage(target, "default"))
        {
            spell_successful();
            dest_effect();
            return;
        }

        tell_object(target,"%^YELLOW%^You lurch as the power of "+caster->QCN+"'s voice "
            "magically compells you to freeze in your tracks!");
        tell_room(place,"%^YELLOW%^"+target->QCN+" freezes in place, compelled by the "
            "power of "+caster->QCN+"'s voice!",target);
        target->set_paralyzed(roll_dice(2,4)*8,"%^YELLOW%^You are magically compelled to stop!");
        target->set_disable(10,target);
        spell_successful();
        dest_effect();
        return;
    }

    tell_object(caster,"%^BLUE%^%^BOLD%^The power of your voice slams into "+target->QCN+" but "
        ""+target->QS+" is able to resist!");
    tell_object(target,"%^BOLD%^%^BLUE%^The power of "+caster->QCN+"'s voice slams into you, but "
        "you are able to resist the command!");
    tell_room(place,"%^BOLD%^%^BLUE%^The power of "+caster->QCN+"'s voice slams into "+target->QCN+" but "
        ""+target->QS+" is able to resist the command!",({target,caster}));
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
