// Based on Cone of Cold - Cythera 6/05
//Acid Breath
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_author("cythera");
    set_spell_name("acid breath"); // acid spit
    set_spell_level(([ "mage" : 3, "druid":3, "monk":15]));
    set_monk_way("way of the elements");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS acid breath on TARGET");
    set_damage_desc("delayed acid");
    set_description("This incantation allows for the mage to collect a pool of acid in his/her mouth.  The magics of this "
        "spell prevent the caster from being harmed by the acid while it is being collected.  The mage then is able to release "
        "the acid as a breath weapon attack, the droplets of acid spinning around in a cone.  More acid is able to be collected "
        "as the mage grows in power, making the spell very deadly for a powerful caster.  Though it will become harder for the "
        "mage to control the acid they stream forth, sometimes even accidentally hitting friends or allies.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
}


string query_cast_string()
{
    tell_object(caster,"%^GREEN%^As you finish chanting a mystic phrase, you "+
        "drop the prepared snakes tongue into your mouth.");
    tell_room(place,"%^GREEN%^"+caster->QCN+" chants a mystic phrase and drops"+
        " a snakes tongue into "+caster->QP+" mouth.",caster);
    return "display";
}


spell_effect(int prof)
{
    if (interactive(caster))
    {
        tell_object(caster, "%^BOLD%^%^GREEN%^You feel the acid building in your mouth.%^RESET%^");
        tell_room(place, "%^BOLD%^%^GREEN%^"+caster->QCN+" stares intently for a moment, as green smoke rolls out of "+caster->QP+" mouth.", caster);
        call_out("zapper",4);
        return;
    }
    zapper();
}


void zapper()
{
    object *hits = ({}),*inven;
    string YOU, HIM, before, after;
    int i;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!objectp(target) || !objectp(place) || !present(target, place))
    {
        tell_object(caster, "%^GREEN%^The acid in your mouth fades away.");
        tell_room(place, "%^GREEN%^Clouds of green smoke roll out of "+caster->QCN+"'s mouth and vanishes into the air.", caster);
        dest_effect();
        return;
    }

    YOU = caster->QCN;
    HIM = target->QCN;

    spell_successful();

    tell_object(caster, "%^GREEN%^%^BOLD%^You release a cone of acid droplets at "+HIM+"!");
    tell_room(place,"%^GREEN%^%^BOLD%^A cone of acid droplets is spit forth from "+YOU+"'s mouth, aimed at "+HIM+"!",({caster,target}) );
    tell_object(target,"%^GREEN%^%^BOLD%^A cone of acid droplets is spit forth from "+YOU+"'s mouth, aimed right at you!");

    inven = all_living(environment(caster));
    inven = target_filter(inven);

    // cone spell, I suppose we are simulating targets being in the line of fire or not
    for (i=0;sizeof(inven), i<sizeof(inven);i++)
    {
        if(!objectp(inven[i])) { continue; }
        if(!living(inven[i])) { continue; }
        if(inven[i] == caster || inven[i] == target) { continue; }

        if(random(100) < clevel)
        {
            hits += ({ inven[i] });
            continue;
        }
        if(random(500) < clevel)
        {
            hits += ({ inven[i] });
            continue;
        }
    }

    for(i=0;sizeof(hits),i<sizeof(hits);i++)
    {
        if(!objectp(hits[i])) { continue; }

        tell_object(caster,"%^GREEN%^The acid droplets fall onto "+ hits[i]->QCN+".");
        tell_object(hits[i],"%^GREEN%^The acid dropslets fall onto you, burning your skin!");
        tell_room(place,"%^GREEN%^The acid droplets fall onto "+hits[i]->QCN+".",({caster,hits[i]}));

        if(do_save(hits[i])) { damage_targ(hits[i],"torso",sdamage / 4,"acid"); }
        else { damage_targ(hits[i],"torso",sdamage / 2,"acid"); }
    }

    tell_object(caster,"%^BOLD%^%^WHITE%^The cone of acid droplets fall onto "+HIM+" covering "+target->QP+" flesh!");
    tell_object(target,"%^BOLD%^%^WHITE%^The cone of acid droplets fall onto your flesh, buring deep into your skin!");
    tell_room(place,"%^BOLD%^%^WHITE%^"+YOU+"'s cone of acid droplets tears through "+HIM+"!!", ({caster, target}) );

    if(do_save(target)) { damage_targ(target,"torso",sdamage / 2,"acid"); }
    else { damage_targ(target,"torso",sdamage,"acid"); }

    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
