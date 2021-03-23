// variation of fireball
//    Acid Orb - Cythera 5/05
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_author("cythera");
    set_spell_name("acid orb");
    set_spell_level(([ "mage" : 3, "cleric" : 3 ]));
    set_domains("elements");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS acid orb on TARGET");
    set_description("This spell allows a mage to tap into the Para-Elemental Plane of Ooze and borrow some of its energy "
        "to create an orb of pure acid.  Once the orb is launched into the air, the first thing it strikes will cause it to burst "
        "open, releasing the acid on the mage's foes.  Though care should be taken as it is possible to accidently catch the "
        "mages allies in the blast.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_components(([ "mage" : ([ "citric acid" : 2, "beeswax" : 1, ]), ]));
    set_save("reflex");
    set_immunities( ({"acid"}) );
}


string query_cast_string() { return "%^BOLD%^%^GREEN%^"+caster->QCN+" chants rapidly, creating an orb of acid in "+caster->QP+" hand."; }


spell_effect(int prof)
{
    object *foes = ({});
    string YOU,HIM,tmp = "";
    int i;

    if(!present(target, (caster->is_room()) ? (caster) : (place) ))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    spell_successful();

    YOU=caster->QCN;
    HIM=target->QCN;

    foes = target_selector();

    foes -= ({ target });

    if(interactive(caster)) { tmp="'s finger"; }

    tell_object(target,"%^BOLD%^%^GREEN%^An orb of acid speeds through the air from "+YOU+tmp+", heading straight for you!");
    tell_object(caster,"%^BOLD%^%^GREEN%^An orb of acid speeds through the air from your hand, heading straight for "+HIM+"!");
    tell_room(place, "%^BOLD%^%^GREEN%^An orb of acid speeds through the air from "+YOU+tmp+", heading straight for "+HIM+"!",({ caster, target}) );

    tell_object(target,"%^BOLD%^%^WHITE%^The acid orb explodes as it hits you!",target);
    tell_room(environment(target),"%^BOLD%^%^WHITE%^The orb of acid explodes as it hits "+target->QCN+"!",target);

    if(!do_save(target)) { damage_targ(target, "torso", sdamage / 2, "acid" ); }
    else { damage_targ(target, "torso", sdamage / 2, "acid" ); }

    for(i=0;sizeof(foes),i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) { continue; }

        if(!do_save(foes[i]))
        {
            tell_room(environment(foes[i]),"%^BOLD%^%^GREEN%^Acid splashes onto "+foes[i]->QCN+"!",foes[i]);
            tell_object(foes[i],"%^BOLD%^%^GREEN%^Your flesh is burnt by the acid.");
            damage_targ(foes[i], "torso", sdamage, "acid" );
            continue;
        }

        tell_room(environment(foes[i]),"%^BOLD%^%^GREEN%^Acid splashes onto "+foes[i]->QCN+"!",foes[i]);
        tell_object(foes[i],"%^BOLD%^%^GREEN%^Acid splashes onto you!");
        damage_targ(foes[i], "torso", sdamage / 2, "acid");
    }

    dest_effect();
    return;
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
