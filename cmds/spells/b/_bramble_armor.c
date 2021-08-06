/*
  _bramble_armor.c

  Innate spell for Clerics with the Plant Domain.
  Travelling AOE. Reskin of Sacred Nimbus.

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

    set_spell_name("bramble armor");
    set_spell_level( ([ "innate" : 5 ]) );
    set_domains("plant");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast innate bramble armor");
    set_damage_desc("Piercing damage to attackers");
    set_description("Clerics with the plant domain learn, by the grace of their deity, how to cause a host of thorns to burst from their skin. This spell is a travelling AOE that does piercing damage. This spell requires one Divine Grace point to use.");
    traveling_aoe_spell(1);
    set_immunities( ({ "piercing" }) );
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while raising "+caster->QP+" hand to the sky.%^RESET%^";
}

int preSpell()
{
    if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
    {
        tell_object(caster, "You don't have the Divine Grace to cast Bramble Armor!");
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    tell_object(caster,"%^GREEN%^You feel a host of thorns burst forth from your skin!%^RESET%^");
    tell_room(place,"%^GREEN%^"+caster->QCN+" is suddenly covered by a host of thorns!",caster);

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({"%^GREEN%^BOLD%^ (covered with thorns)%^RESET%^"}));
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
        tell_room(place,"%^BOLD%^%^GREEN%^The thorns covering "+caster->QCN+" pierce "+caster->QP+" enemies!",({caster,target}));
        tell_object(caster,"%^BOLD%^GREEN%^The thorns covering you pierce your enemies!");
        for(i=0;i<sizeof(attackers);i++){
            if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
            tell_object(attackers[i],"%^BOLD%^%^GREEN%^You are pierced by thorns as you attack "+caster->QCN+"!");
            attackers[i]->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), sdamage, "piercing");
        }
    }
    prepend_to_combat_cycle(place);
}


void dest_effect()
{
    remove_call_out("room_check");
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^The thorns covering you fall to the grown and wilt away.");
        caster->remove_property("nimbus");
        caster->remove_property_value("added short",({"%^GREEN%^BOLD%^ (covered with thorns)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
