//_dark_aura.c
//Based on Luckbolt by Circe - Cythera 7/05
#include <std.h>
#include <magic.h>
#define DELAY 1200

inherit SPELL;

int mybonus;

void create() 
{
    ::create();
    set_spell_name("dark aura");
    set_spell_type("priest");
    set_spell_level(7);
    set_spell_domain("tyranny");
    set_spell_sphere("combat");
    set_target_required(1);
    set_verbal_comp();
}

int preSpell() 
{
    if(!objectp(target)) 
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    if (target->query_property("daura")) 
    {
        tell_object(caster,"Your target alread has a dark aura about them.");
        return 0;
    }
    if ((int)target->query_property("daura time")+DELAY > time()) 
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You can not create a dark aura so soon.");
        return 0;
    }
    return 1;
}

string query_cast_string() 
{
    tell_object(caster,"%^BOLD%^%^BLACK%^You begin to chant"+
        " in a commanding voice as you lift your chin.");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" lifts "+
        ""+caster->QP+" chin as "+caster->QS+" begins to "+
        "chant in a commanding haughty voice.",caster);
    return "display";
}

void spell_effect(int prof) 
{
    int mybonus,duration;
    mybonus  = (clevel/7)+1;
    duration = (2 * ROUND_LENGTH) * clevel; 

    if(target == caster)
    {
        tell_room(place,"%^BOLD%^%^BLACK%^A flaring dark aura surrounds"+
            " "+caster->QCN+"'s head.",target);
        tell_object(target, "%^BOLD%^%^BLACK%^A flaring black aura surrounds"+
            " you!");
    }
    else
    {
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" clentches "+caster->QP+" "+
            "fist.  A flaring dark aura surrounds "+target->QCN+"'s head.",({target,caster}));
        tell_object(target,"%^BOLD%^%^BLACK%^"+caster->QCN+" clentches "+
            ""+caster->QP+" fist.  A flaring dark aura surrounds your head!");
        tell_object(caster,"%^BOLD%^%^BLACK%^You chant wildly while clentching "+
            "your fist, summoning a dark aura around "+target->QCN+".");
    }
    target->add_ac_bonus(mybonus);
    target->add_saving_bonus("all",(mybonus));
    target->set_property("magic resistance",5);
    target->set_property("daura",1);
    target->set_property("spelled", ({TO}) );
    target->set_property("daura time",time());
    call_out("dest_effect",duration);
   spell_successful(); 
    execute_attack();
}

void execute_attack()
{
    object room;

    ::execute_attack();

    if(!objectp(target)) 
    {
        dest_effect();
        return;
    }
    room = environment(target);
    if(!random(10))
    {
        tell_room(room,"%^BOLD%^%^BLACK%^A dark aura surrounds "+target->QCN+"'s head.", target);
        tell_object(target,"%^BOLD%^%^WHITE%^You feel the dark aura aiding you.");
    }
    room->addObjectToCombatCycle(TO,1);
}

dest_effect()
{
    if (objectp(target)) 
    {
        target->add_ac_bonus(-1 * mybonus);
        target->add_saving_bonus("all",(-1 * mybonus));
	    target->set_property("magic resistance",-5);
        target->remove_property("daura");
     	tell_room(place,"%^BOLD%^%^BLACK%^The flaring dark aura around"+
		    " "+target->QCN+" quickly fades away.", target);
	    tell_object(target,"%^BOLD%^%^BLACK%^The dark aura around"+
		    " you quickly fades away.");
    }
    ::dest_effect();
    remove();
}

int help() 
{
    write(
@CYTHERA
Spell  : Dark Aura
Level  : 7th Level
Sphere : Combat
Domain : Tyranny
Syntax : chant dark aura on <target>

Calling out for aid, the caster is able to create 
a crown of flaring darkness around the target's head.  The 
dark aura flares and spikes chaotically for the duration 
of the spell.  While the dark aura is in effect, the target 
will find themselves with a heightened protection from 
physical, magical, and supernatural attacks.

CYTHERA
);
    return 1;
}
