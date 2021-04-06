// Bless
#include <std.h>
#include <magic.h>

inherit SPELL;

#define ALIGN_D "/daemon/alignment_d.c"

int bonus;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("blight");
    set_spell_level(([ "inquisitor" : 1]));
    set_spell_sphere("alteration");
    set_bonus_type("morale");
    set_syntax("cast CLASS blight on TARGET");
    set_damage_desc("clevel / 24 + 1 to damage and attack bonus, but no more than 2");
    set_description("This spell will empower the target with dark energy, giving them a slightly better chance to hit in "
"combat as well as allowing them to do a small amount more damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
	set_helpful_spell(1);
}

int preSpell()
{
//    if(!ALIGN_D->is_evil(caster)) {
   if((int)caster->query_true_align()%3 != 0) {
        tell_object(caster,"%^RED%^Only those of evil intent may call on the power to blight a foe.");
        return 0;
    }
    if(!target) { target = caster; }
    /*
    if(target->query_property("blessed")) {
        tell_object(caster,"%^BOLD%^%^RED%^Your target is already enjoying the blessings of a deity!%^RESET%^");
        return 0;
    }
    */
    return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^GREEN%^You begin to chant a delicate prayer.");
    tell_room(place,"%^GREEN%^"+caster->QCN+" begins a delicate prayer"+
        " to "+caster->QP+" diety.",caster);
    return "display";
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 20) * clevel;
    bonus = clevel/24+1;
    bonus = bonus>2?2:bonus;
	if(target == caster)
    {
        tell_room(place,"%^BOLD%^%^RED%^A profane aura surrounds "+caster->QCN+""+
		    " for a moment",target);
        tell_object(target, "%^BOLD%^%^RED%^A profane aura surrounds you for"+
		    " a moment, before it sinks into your skin.");
    }
    else
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^You call on "+(string)caster->query_diety()+"'s aid and bless "
            ""+target->QCN+".");
        tell_object(target,"%^BOLD%^%^BLACK%^"+caster->QCN+" calls to "+caster->QP+" diety for aid, blessing you.");
        tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" calls to "+caster->QP+" diety for aid, blessing "
            ""+target->QCN+".",({caster,target}));
    }
    target->add_damage_bonus(bonus);
    target->add_attack_bonus(bonus);
    addSpellToCaster();
    target->set_property("spelled",({TO}));
    //target->set_property("blessed",1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
     spell_successful();
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^RED%^You can feel the blessing you have been granted fade "
            "away.");
        target->add_damage_bonus(-1*bonus);
        target->add_attack_bonus(-1*bonus);
        //target->remove_property("blessed");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
