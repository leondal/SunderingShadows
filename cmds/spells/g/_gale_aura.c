/*
  _gale_aura.c
  
  Innate spell for Clerics with the Storms Domain.
  Similar to Cloak of Winds.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int flag;

void create()
{
    ::create();
    
    set_spell_name("gale aura");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("storms");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate gale aura on TARGET");
    set_damage_desc("Bludgeoning damage to attackers");
    set_description("Clerics with the storms domain learn, by the grace of their deity, how to protect themselves in an aura of air. This aura causes bludgeoning damage to attackers. This spell requires one Divine Grace point to use.");
    traveling_aoe_spell(1);
    set_immunities( ({ "bludgeoning" }) );
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while raising "+caster->QP+" hand to the sky.%^RESET%^";
}

int preSpell()
{
    
    if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to cast Gale Aura!");
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    tell_object(caster,"%^CYAN%^BOLD%^A gale of protective winds surrounds you!%^RESET%^");
    tell_room(place,"%^CYAN%^BOLD%^"+caster->QCN+" is suddenly enshrouded in a gale of protective winds!",caster);

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({"%^CYAN%^BOLD%^ (in a maelstrom of wind)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("room_check",ROUND_LENGTH);
}

void execute_attack(){
    object *attackers;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }

    attackers = filter_array(caster->query_attackers(),(:objectp($1):));
    attackers = filter_array(attackers,(:$1->is_living():));

    if(sizeof(attackers))
    {
        define_base_damage(0);
        tell_room(place,"%^BOLD%^%^WHITE%^The winds around "+caster->QCN+" buffet "+caster->QP+" enemies!",({caster,target}));
        tell_object(caster,"%^BOLD%^WHITE%^The winds around you buffet your enemies!");
        for(i=0;i<sizeof(attackers);i++){
            if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
            tell_object(attackers[i],"%^BOLD%^%^WHITE%^You are buffeted by winds as you attack "+caster->QCN+"!");
            attackers[i]->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), sdamage, "bludgeoning");
        }
    }
    prepend_to_combat_cycle(place);
}


void dest_effect()
{
    remove_call_out("room_check");
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^The maelstrom of winds around you dissappates.");
        caster->remove_property("nimbus");
        caster->remove_property_value("added short",({"%^CYAN%^BOLD%^ (in a maelstrom of wind)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}