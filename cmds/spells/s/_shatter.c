// Shatter
//Made D4 to slightly improve it.  Cloudburst does d3 but also trips
//Changes by ~Circe~ 5/6/08 with rebalancing of domains

#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("shatter");
    set_spell_level(([ "monk" : 7,"paladin": 2, "magus" : 2 ]));
    set_spell_sphere("alteration");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS shatter on TARGET");
    set_description("%^RESET%^This spell sends a piercing vibration of sonic damage straight towards the target of the spell.  If the target is not able to escape the blast, they will take a significant deal of damage.

%^BOLD%^%^RED%^See also:%^RESET%^ shatter *feats");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string(){
    tell_object(caster,"%^ORANGE%^You begin to chant in shifting "+
        "chaotic tones, feeling the vibrations building inside of you.");
    tell_room(place,"%^ORANGE%^"+caster->QCN+" begins to chant in shifting"+
        " cacophany of sound.",caster);
	return "display";
}

void spell_effect(int prof)
{
    string the_god;
    int damage;

    if (!objectp(target)) dest_effect();
    if (!objectp(caster)) dest_effect();

    if (environment(caster) != environment(target)){
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }

    the_god = caster->query_diety();
    if(the_god) { the_god = capitalize(the_god); }
    else { the_god = "your god"; }
    if(spell_type == "monk") { MAGIC_D->elemental_opportunist(caster, target); }
    tell_object(caster,"%^YELLOW%^You open your mouth and shout at "+target->QCN+", the "
        "power of your voice amplified by "+the_god+"!");
    tell_object(target,"%^YELLOW%^"+caster->QCN+" opens "+caster->QP+" mouth and bellows "
       "an ear shattering shout at you!",caster);
    tell_room(place,"%^YELLOW%^"+caster->QCN+" opens "+caster->QP+" mouth and bellows an ear "
        "splitting shout at "+target->QCN+"!",({caster,target}));

    if(!do_save(target,0)) {
        tell_object(caster,"%^ORANGE%^The power of your shout rips into "+target->QCN+" nearly "
            "ripping "+target->QO+" apart!");
        tell_object(target,"%^ORANGE%^The power of "+caster->QCN+"'s shout rips into you, nearly "
            "tearing you apart!");
        tell_room(place,"%^ORANGE%^The power of "+caster->QCN+"'s shout rips into "+target->QCN+", "
            "nearly ripping "+target->QO+" apart!",({target,caster}));
        damage = sdamage;
    }else{
        tell_object(caster,"%^YELLOW%^"+target->QCN+" is able to move at the last instant, avoiding "
            "the full effect of your shout!");
        tell_object(target,"%^YELLOW%^You are able to move at the last instant, avoiding the full "
            "effect of "+caster->QCN+"'s shout!");
        tell_room(place,"%^YELLOW%^"+target->QCN+" is able to move at the last instant, avoiding "
            "the full effect of "+caster->QCN+"'s shout!",({target,caster}));
        damage = sdamage/2;
    }
    damage_targ(target,target->return_target_limb(),damage,"sonic");
    spell_kill(target,caster);
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
