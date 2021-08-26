//Earthquake - based on Windstorm by Ares
//new Cavern domain spell by ~Circe~ 5/10/08
//rebalancing domains
// Windstorm
//Updated both this spell and windstorm after I noticed that having
//the random strength/dex checks versus 1d20 was *way* too good
#include <spell.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

int storm_effects(object obj);

object storm_room;
int duration;


void create()
{
    ::create();
    set_spell_name("earthquake");
    set_spell_level(([ "innate" : 8, "cleric" : 8, "druid" : 8 ]));
    set_spell_sphere("invocation_evocation");
    set_mystery("battle");
    set_domains(({ "earth" }));
    set_syntax("cast CLASS earthquake");
    set_description("By unleashing this spell, the caster calls forth a mighty earthquake to trip and damage his foes.  "
        "The spell will last several rounds depending upon the level of the priest, and the priest must remain present for the "
        "spell to continue.  All those attacking the caster are subject to the effects of the earthquake, though they do receive "
        "saving throws.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^RESET%^%^ORANGE%^(rumbling and filled with %^RESET%^debris%^ORANGE%^)%^RESET%^");
}


string query_cast_string()
{
    tell_object(caster,"%^ORANGE%^You growl a prayer, planting your "+
        "feet upon the ground.%^RESET%^");
    tell_room(place,"%^ORANGE%^"+caster->QCN+" growls a prayer, planting "+
        ""+caster->QP+" feet upon the ground.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof)
{
    duration = (ROUND_LENGTH * clevel) * 3;
    tell_room(place,"%^YELLOW%^"+caster->QCN+" stomps "+caster->QP+" "+
        "foot, and the %^BLACK%^ground%^YELLOW%^ rumbles ominously"+
        "!%^RESET%^",caster);
    tell_object(caster,"%^YELLOW%^You stomp your foot and the "+
        "%^BLACK%^ground %^YELLOW%^rumbles ominously!%^RESET%^");
    place->set_property("spelled", ({TO}));
    storm_room = place;
    addSpellToCaster();
    spell_successful();
    //execute_attack();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
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
        tell_object(caster,"%^ORANGE%^The rumbling earth settles "+
            "as you leave the area.%^RESET%^");
        tell_room(storm_room,"%^ORANGE%^The rumbling earth settles "+
            "as "+caster->QCN+" leaves the area.%^RESET%^");
        dest_effect();
        return;
    }

    attackers = target_selector();

    if(sizeof(attackers))
    {
        tell_room(storm_room,"%^BOLD%^%^BLACK%^The earth shakes and "+
            "groans, throwing up debris and tossing objects about!%^RESET%^");
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            if(!storm_effects(attackers[i])) { continue; }
        }
        place->addObjectToCombatCycle(TO,1);
        return;
    }
    else
    {
        dest_effect();
        return;
    }
}


int storm_effects(object obj)
{
    object room;
    if(!objectp(obj))               { return 0; }
    if(!objectp(environment(obj)))  { return 0; }
    if(environment(caster) != environment(obj)) { return 0; }
    room = environment(obj);

    tell_object(obj,"%^YELLOW%^The earth tosses you about, making "+
        "footing treacherous!%^RESET%^");

    if(do_save(obj,0))
    {
        tell_object(obj,"%^ORANGE%^The debris grazes you, but you "+
            "avoid the worst of it!%^RESET%^");
        tell_room(room,"%^ORANGE%^"+obj->QCN+" dodges the worst of "+
            "the debris!%^RESET%^",obj);
        damage_targ(obj,obj->return_target_limb(),sdamage/2,"bludgeoning");
    }
    else
    {
        tell_object(obj,"%^BOLD%^%^RED%^The debris from the earthquake "+
            "tears at your flesh!%^RESET%^");
        tell_room(room,"%^BOLD%^%^RED%^"+obj->QCN+" is shredded by the "+
            "earthquake's debris!%^RESET%^",obj);
        damage_targ(obj,obj->return_target_limb(),sdamage,"bludgeoning");
    }

    if(!do_save(obj,4))
    {
        tell_object(obj,"%^ORANGE%^The shifting floor tosses you about, "+
            "leaving you helpless on the ground!%^RESET%^");
        tell_room(room,"%^ORANGE%^"+obj->QCN+" is tossed about by the "+
            "earthquake and ends up helpless on the ground!",obj);
        obj->set_tripped(roll_dice(1,2),"%^BOLD%^You are struggling "+
            "to get back to your feet!%^RESET%^",2);
    }
    return 1;
}


void dest_effect()
{
    if(objectp(place)) tell_room(place,"%^ORANGE%^The rumbling earth settles and grows still.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
