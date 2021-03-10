// bestow curse
#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int bonus;

void create() 
{
    ::create();
    set_author("ares");
    set_spell_name("bestow curse");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_domain("trickery");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    set_target_required(1);
}

int preSpell()
{
    if(!target)
    {
        tell_object(caster,"You must pick a target for this spell.");
        return 0;
    }
    if(target->query_property("cursed"))
    {
        tell_object(caster,"That target is already cursed.");
        return 0;
    }
    return 1;
}

string query_cast_string() 
{
    tell_object(caster,"%^BLUE%^You begin to rant an ancient"+
		" and vile prayer.");
    tell_room(place,"%^BLUE%^"+caster->QCN+" begins to an ancient"+
		" and vile prayer.",caster);
    return "display";
}

void spell_effect(int prof) 
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;
    if(sizeof(caster->query_classes()) == 1) { bonus = 4; }
    else { bonus = 2; }

    tell_object(caster,"%^MAGENTA%^You level your gaze at "+target->QCN+" and send forth "
        "a hideous spell to curse "+target->QO+"!");
    tell_object(target,"%^MAGENTA%^"+caster->QCN+" levels "+caster->QP+" gaze at you and "
        "sends a hideous spell to curse you!");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" levels "+caster->QP+" gaze at "+target->QCN+" "
        "and sends forth a hideous spell to curse "+target->QO+"!",({caster,target}));
/*
    if(!SAVING_D->saving_throw(target,"spell",0))
*/
    if(!do_save(target))
    {
        tell_object(target,"%^BLUE%^You almost wretch as you feel the insidious magic clawing "
            "it's way into your soul!");
        tell_room(place,"%^BLUE%^"+target->QCN+" doubles over in agony as the magic twists "
            ""+target->QP+" insides!",target);
        target->add_damage_bonus(-1*bonus);
        target->add_attack_bonus(-1*bonus);
        target->set_property("magic resistance",(-1*bonus));
        target->set_property("empowered",(-1*bonus));
        target->set_property("cursed",1);
     spell_successful();
        spell_kill(target,caster);
        call_out("dest_effect",duration);
    }
}

void dest_effect() 
{
    if(objectp(target))
    {
        tell_object(target,"%^BLUE%^You feel a great weight lifted from you "+
		    "as the curse finally fades away!");
        target->add_damage_bonus(bonus);
        target->add_attack_bonus(bonus);
        target->set_property("magic resistance",(bonus));
        target->set_property("empowered",(bonus));
        target->remove_property("cursed");
    }
    ::dest_effect();
    TO->remove();
}

int help(string str) 
{
    write(
@HELP
Spell  : %^MAGENTA%^Bestow Curse
Level  : 3rd Level
Domain : Trickery
Syntax : chant bestow curse on <target>

This spell will send forth a insidious curse at the
target.  If the target fails their save, several bad
things will happen to them.  The will find it more 
difficult to hit things in combat, their spells will
become less effective, they will do less damage, and
their magic resistance will be slightly lowered.

HELP
);
    return 1;
}
