// Windstorm
//Updated this spell after I realized that the random
//strength and dex check was way too good and made the
//target's stats not count for much, which was not
//the intention ~Circe~ 6/11/08
#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

object storm_room;
int duration;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("windstorm");
    set_spell_level(([ "druid":8, "oracle" : 8 ]));
    set_mystery("wind");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS windstorm");
    set_description("This spell calls on the power of the plane of air to unleash a terrible gale of wind that sends "
        "debris whipping around the caster's enemies.  It has a chance to blind them with sand, and even knock them from their "
        "feet.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^CYAN%^(buffeted by fierce winds)%^RESET%^");
}


string query_cast_string()
{
    tell_object(caster,"%^BOLD%^You begin to turn around in a circle, as you"+
        " begin your howling prayer.");
    tell_room(place,"%^BOLD%^"+caster->QCN+" turns around in a circle, as"+
        ""+caster->QP+" begins a howling prayer.",caster);
    return "display";
}

void spell_effect(int prof)
{
    duration = (ROUND_LENGTH * clevel) * 2;
    tell_room(place,"%^BOLD%^"+caster->QCN+" whispers a soft chant into the winds "
        "and a gale force wind howls into the area!");
    tell_object(caster,"%^BOLD%^You whisper a soft chant into the winds and a "
        "gale of wind answers your call!");

    caster->set_property("spelled", ({TO}));

    storm_room = environment(caster);
    addSpellToCaster();
    spell_successful();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",duration);
}


void execute_attack()
{
    object *attackers = ({});
    int i;

    ::execute_attack();

    if(!objectp(caster) || !objectp(environment(caster)) || caster->query_unconscious())
    {
        dest_effect();
        return;
    }

    if(environment(caster) != storm_room)
    {
        tell_object(caster,"%^BOLD%^%^BLUE%^The howling winds calm as you leave the area.");
        tell_room(storm_room,"%^BOLD%^%^BLUE%^The howling winds return to normal as "
            ""+caster->QCN+" leaves the area.");
        dest_effect();
        return;
    }

    attackers = target_selector();

    if(sizeof(attackers))
    {
        tell_room(storm_room,"%^BOLD%^%^BLACK%^The winds howl furiously, throwing debris around "
            "in a chaotic swirl.");
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            if(!storm_effects(attackers[i])) { continue; }
        }
    }
    place->addObjectToCombatCycle(TO,1);
}


int storm_effects(object obj)
{
    int damage;
    object room;
    if(!objectp(obj))               { return 0; }
    if(!objectp(environment(obj)))  { return 0; }
    room = environment(obj);

    tell_object(obj,"%^BOLD%^%^BLACK%^The winds howl aound you, making it difficult to "
        "see and hear!");

    define_base_damage(0);
    damage = sdamage;

    if(do_save(obj,0))
    {
        tell_object(obj,"%^BOLD%^%^BLUE%^You dodge away from most of the debris, taking "
            "only a small amount of damage!");
        tell_room(room,""+obj->QCN+" dodges away from the swirling debris!",obj);
        damage_targ(obj,obj->return_target_limb(),damage/2,"bludgeoning");
    }
    else
    {
        tell_object(obj,"%^BOLD%^%^BLUE%^The stinging wind sends debris everything, pelting "
            "your skin and tearing at your flesh!");
        tell_room(room,"%^BOLD%^%^BLUE%^"+obj->QCN+" gets pelted painfully with whipping debris!",obj);
        damage_targ(obj,obj->return_target_limb(),damage,"bludgeoning");
    }

    if(!do_save(obj,4))
    {
        tell_object(obj,"%^BOLD%^%^WHITE%^The wind throws you from your feet, swirling your "
            "body up into the air before you hit the ground with a thud!");
        tell_room(room,"%^BOLD%^%^WHITE%^"+obj->QCN+" is suddenly caught by the force of the "
            "wind and sent spinning into the air before "+obj->QS+" crashes "
            "back to the ground with a bone jarring thud!");
        obj->set_tripped(roll_dice(1,2),"%^BOLD%^You are struggling to get back to "
            "your feet!",2);
    }
    return 1;
}


void dest_effect()
{
    if(objectp(place)) tell_room(place,"%^BOLD%^%^BLUE%^The howling winds calm and the air returns to normal.");
    if(objectp(caster))
    {
        caster->remove_property_value("spelled", ({TO}));
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
