#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string element;

void create()
{
    ::create();
    set_spell_name("fireball");
    set_spell_level(([ "mage" : 3, "monk" : 7, "oracle" : 3, "magus" : 3, "cleric" : 3, "druid" : 3 ]));
    set_domains("fire");
    set_mystery("flame");
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS fireball on TARGET");
    set_damage_desc("fire, versatile arcanist");
    set_description("By casting this spell, a mage can aim and release a massive ball of fire at a target and those "
        "around him.  The fireball spell will wreak havoc on the caster's target and those who oppose him.  Damage done to those "
        "hit by the spell is 1d6 per level of the caster, subject to a maximum, halved if they manage to evade the brunt of the "
        "spell. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_components(([ "mage" : ([ "bat guano":1, "sulfur":1, ]), ]));
    set_save("reflex");
}


string query_cast_string()
{
    element = (string)caster->query("elementalist");

    switch(element)
    {
    case "acid":
        tell_object(caster,"%^BOLD%^%^GREEN%^You chant rapidly, creating an orb of acid in your hand.%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" chants rapidly, creating an orb of acid in "+caster->QP+" hand.%^RESET%^",caster);
        set_immunities(({"acid"}));
        break;
    case "cold":
        tell_object(caster,"%^BOLD%^%^CYAN%^You chant rapidly, creating an orb of frost in your hand.%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" chants rapidly, creating an orb of frost in "+caster->QP+" hand.%^RESET%^",caster);
        set_immunities(({"cold"}));
        break;
    case "electricity":
        tell_object(caster,"%^BOLD%^%^YELLOW%^You chant rapidly, creating an orb of lightning in your hand.%^RESET%^");
        tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+" chants rapidly, creating an orb of lightning in "+caster->QP+" hand.%^RESET%^",caster);
        set_immunities(({"electricity"}));
        break;
    case "sonic":
        tell_object(caster,"%^BOLD%^%^MAGENTA%^You chant rapidly, creating an orb of sound in your hand.%^RESET%^");
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" chants rapidly, creating an orb of sound in "+caster->QP+" hand.%^RESET%^",caster);
        set_immunities(({"sonic"}));
        break;
    default:
        tell_object(caster,"%^BOLD%^%^RED%^You chant rapidly, creating an orb of fire in your hand.%^RESET%^");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" chants rapidly, creating an orb of fire in "+caster->QP+" hand.%^RESET%^",caster);
        set_immunities(({"fire"}));
        break;
    }

    return "display";
}


void spell_effect(int prof)
{
    object *foes = ({});
    string YOU, HIM, tmp = "";
    int i;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!present(target, caster->is_room() ? caster : environment(caster) ))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    YOU = caster->QCN;
    HIM = target->QCN;

    if(spell_type == "monk") { MAGIC_D->elemental_opportunist(caster, target); }
    spell_successful();

    foes = target_selector();

    foes -= ({ target});

    if(interactive(caster)) { tmp = "'s finger"; }

    switch(element)
    {
    case "acid":
        tell_object(target,"%^BOLD%^%^GREEN%^An orb of acid speeds through the air from "+YOU+tmp+", heading straight for you!");
        if(living(caster)) tell_object(caster,"%^BOLD%^%^GREEN%^An orb of acid speeds through the air from your hand, heading straight for "+HIM+"!");
        tell_room(place, "%^BOLD%^%^GREEN%^An orb of acid speeds through the air from "+YOU+tmp+", heading straight for "+HIM+"!",({ caster, target}) );
        break;
    case "cold":
        tell_object(target,"%^BOLD%^%^CYAN%^An orb of frost and ice speeds through the air from "+YOU+tmp+", heading straight for you!");
        if(living(caster)) tell_object(caster,"%^BOLD%^%^CYAN%^An orb of frost and ice speeds through the air from your hand, heading straight for "+HIM+"!");
        tell_room(place, "%^BOLD%^%^CYAN%^An orb of frost and ice speeds through the air from "+YOU+tmp+", heading straight for "+HIM+"!",({ caster, target}) );
        break;
    case "electricity":
        tell_object(target,"%^BOLD%^%^YELLOW%^An orb of lightning speeds through the air from "+YOU+tmp+", heading straight for you!");
        if(living(caster)) tell_object(caster,"%^BOLD%^%^YELLOW%^An orb of lightning speeds through the air from your hand, heading straight for "+HIM+"!");
        tell_room(place, "%^BOLD%^%^YELLOW%^An orb of lightning speeds through the air from "+YOU+tmp+", heading straight for "+HIM+"!",({ caster, target}) );
        break;
    case "sonic":
        tell_object(target,"%^BOLD%^%^MAGENTA%^An orb of sound speeds through the air from "+YOU+tmp+", heading straight for you!");
        if(living(caster)) tell_object(caster,"%^BOLD%^%^MAGENTA%^An orb of sound speeds through the air from your hand, heading straight for "+HIM+"!");
        tell_room(place, "%^BOLD%^%^MAGENTA%^An orb of sound speeds through the air from "+YOU+tmp+", heading straight for "+HIM+"!",({ caster, target}) );
        break;
    default:
        element = "fire";
        tell_object(target,"%^BOLD%^%^RED%^A massive ball of fire jets out from "+YOU+tmp+", furiously growing as it speeds towards you!");
        if(living(caster)) tell_object(caster,"%^BOLD%^%^RED%^A massive ball of fire jets out from your finger, furiously growing as it speeds towards "+HIM+"!");
        tell_room(place, "%^BOLD%^%^RED%^A massive ball of fire jets out from "+YOU+tmp+" furiously growing as it speeds towards "+HIM+"!",({ caster, target}) );
        break;
    }

    if(do_save(target))
    {
        damage_targ(target, "torso", to_int(sdamage / 2),element);
    }
    else
    {
        damage_targ(target, "torso", sdamage,element);
    }

    switch(element)
    {
    case "acid":
        tell_object(target,"%^BOLD%^%^WHITE%^The acid orb explodes as it hits you!",target);
        tell_room(environment(target),"%^BOLD%^%^WHITE%^The orb of acid explodes as it hits "+HIM+"!",target);
        break;
    case "cold":
        tell_object(target,"%^BOLD%^%^WHITE%^The frost orb explodes as it hits you!",target);
        tell_room(environment(target),"%^BOLD%^%^WHITE%^The orb of frost explodes as it hits "+HIM+"!",target);
        break;
    case "electricity":
        tell_object(target,"%^BOLD%^%^WHITE%^The lightning orb explodes as it hits you!",target);
        tell_room(environment(target),"%^BOLD%^%^WHITE%^The orb of lightning explodes as it hits "+HIM+"!",target);
        break;
    case "sonic":
        tell_object(target,"%^BOLD%^%^WHITE%^The sonic orb explodes as it hits you!",target);
        tell_room(environment(target),"%^BOLD%^%^WHITE%^The orb of sound explodes as it hits "+HIM+"!",target);
        break;
    default:
        tell_object(target,"%^BOLD%^%^WHITE%^The ball of fire explodes into you!",target);
        tell_room(environment(target),"%^BOLD%^%^WHITE%^The ball of fire explodes into "+HIM+"!",target);
        break;
    }


    for(i=0;i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) { continue; }

        if(!do_save(foes[i]))
        {
            switch(element)
            {
            case "acid":
                tell_room(environment(foes[i]),"%^BOLD%^%^GREEN%^Acid sears into "+foes[i]->QCN+"'s flesh!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^GREEN%^Your flesh is burnt by the acid!");
                break;
            case "cold":
                tell_room(environment(foes[i]),"%^BOLD%^%^CYAN%^Shards of ice and frost tear into "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^CYAN%^Shards of ice and frost tear into your skin!");
                break;
            case "electricity":
                tell_room(environment(foes[i]),"%^BOLD%^%^YELLOW%^Bolts of lightning from the orb shock "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^YELLOW%^You are shocked by bolts of lighting from the orb!");
                break;
            case "sonic":
                tell_room(environment(foes[i]),"%^BOLD%^%^MAGENTA%^Sonic waves slam into "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^MAGENTA%^Sonic waves slam into you!");
                break;
            default:
                tell_room(environment(foes[i]),"%^BOLD%^%^RED%^The blast of the explosion smashes into "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^RED%^The blast of the explosion smashes into you!");
                break;
            }
            damage_targ(foes[i], "torso", sdamage, element);
        }
        else
        {
            switch(element)
            {
            case "acid":
                tell_room(environment(foes[i]),"%^BOLD%^%^GREEN%^Acid splashes onto "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^GREEN%^Acid splashes onto you!");
                break;
            case "cold":
                tell_room(environment(foes[i]),"%^BOLD%^%^CYAN%^Shards of ice and frost graze "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^CYAN%^Shards of ice and frost graze you from the orb!");
                break;
            case "electricity":
                tell_room(environment(foes[i]),"%^BOLD%^%^YELLOW%^A stray bolt of lightning from the orb jolts "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^YELLOW%^A stray bolt of lightning from the orb jolts you!");
                break;
            case "sonic":
                tell_room(environment(foes[i]),"%^BOLD%^%^MAGENTA%^Sonic waves graze past "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^MAGENTA%^Sonic waves graze you!");
                break;
            default:
                tell_room(environment(foes[i]),"%^BOLD%^%^RED%^The blast singes "+foes[i]->QCN+"!",foes[i]);
                tell_object(foes[i],"%^BOLD%^%^RED%^The blast of the explosion singes you!");
                break;
            }
            damage_targ(foes[i], "torso", sdamage / 2, element);
        }
    }

    dest_effect();
    return;
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
