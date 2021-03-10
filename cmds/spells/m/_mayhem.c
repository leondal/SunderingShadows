//This is the spell associated with the
//Book of Ancient Secrets feat

#include <spell.h>
#include <magic.h>

inherit SPELL;

int time, first_execute;

void create()
{
    ::create();
    set_spell_name("mayhem");
    set_spell_level(([ "warlock" : 4 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS mayhem");
    set_damage_desc("AOE confusion over several rounds.");
    set_description(""
    "The Tome-Bound Master has unlocked the secret of true confusion and madness, "
    "and can unleash that confusion upon a group of unsuspecting victims. Those who "
    "do not make a will savings throw will be confused. This manifests as a purplish "
    "haze that, when breathed in, has the desired effect.");
    set_verbal_comp();
    set_somatic_comp();
    aoe_spell(1);
    set_save("will");
    set_aoe_message("%^BOLD%^MAGENTA%^(bathed in a cloud of chaos)%^RESET%^");
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

void spell_effect(int prof)
{
    tell_object(caster,"%^MAGENTA%^You raise your hands and a purple haze enters the area, causing u%^WHITE%^n%^RESET%^c%^MAGENTA%^o%^BOLD%^ntro%^WHITE%^l%^RESET%^l%^MAGENTA%^a%^BOLD%^ble m%^WHITE%^a%^RESET%^y%^MAGENTA%^h%^BOLD%^em!%^RESET%^");
    tell_room(place,"%^MAGENTA%^" + caster->QCN + " raises their hands and a purple haze enters the area, causing u%^WHITE%^n%^RESET%^c%^MAGENTA%^o%^BOLD%^ntro%^WHITE%^l%^RESET%^l%^MAGENTA%^a%^BOLD%^ble m%^WHITE%^a%^RESET%^y%^MAGENTA%^h%^BOLD%^em!%^RESET%^",caster);
    place->set_property("spelled", ({TO}) );
    caster->set_property("spelled",({TO}));
    time = 0;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack(int prof)
{
    string target_limb;
    object *foes;
    int i, damage;

    if(!objectp(place))
    {
        dest_effect();
        return;
    }
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if (!first_execute)
    {
        first_execute++;
        ::execute_attack();
        return;
    }

    foes = target_selector();
    foes -= ({ caster });

    if (time > clevel * 2 || !present(caster,place))
    {
        dest_effect();
        return;
    }

    if (!present(caster,place))
    {
        dest_effect();
        return;
    }

    damage = sdamage;

    tell_room(place,"%^MAGENTA%^The c%^WHITE%^h%^RESET%^a%^MAGENTA%^o%^BOLD%^tic e%^WHITE%^n%^RESET%^e%^MAGENTA%^r%^BOLD%^gy swirls around the area, causing m%^WHITE%^a%^RESET%^d%^MAGENTA%^n%^BOLD%^ess and m%^WHITE%^a%^RESET%^y%^MAGENTA%^h%^BOLD%^em in whomever it touches!%^RESET%^");
    
    foreach(object ob in foes)
    {
        if(!do_save(ob, clevel))
        {
            "/std/effect/status/confused"->apply_effect(ob,clevel/5+1,caster);
            tell_object(ob, "%^BOLD%^MAGENTA%^Your mind is filled with madness!%^RESET%^");
        }
        else
            tell_object(ob, "You are able to resist the madness seeping into your mind.");
    }
    
    time++;

    if (present(caster,place) && !caster->query_unconscious())
    {
        place->addObjectToCombatCycle(TO,1);
        return;
    }
    else
    {
        dest_effect();
        return;
    }
    place->addObjectToCombatCycle(TO,1);
}
    
    
    
    
void dest_effect()
{
    if(objectp(place))
    {
        tell_object(place,"%^BOLD%^%^WHITE%^The cloud of madness recedes.%^RESET%^");
        place->remove_property_value("spelled", ({TO}) );
    }
    if(objectp(caster))
    {
        caster->remove_property_value("spelled", ({TO}) );
    }
    
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
