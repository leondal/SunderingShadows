#include <priest.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;

void create()
{
    ::create();
    set_spell_name("profane nimbus");
    set_spell_level(([ "cleric" : 5, "paladin" : 4,"inquisitor":5 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS profane nimbus");
    set_damage_desc("divine to good");
    set_description("You are surrounded by a nimbus of darkness shaped like your god's holy symbol or a symbol of your faith. Any good creature attacking you will be scorched by the darkness.");
    set_property("magic",1);
    traveling_aoe_spell(1);
    evil_spell(1);
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^MAGENTA%^You growl a quiet plea to your divine patron.");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" growls a quiet plea under "+caster->QP+" breath.",caster);
    return "display";
}


int preSpell()
{
    if(caster->query_property("nimbus"))
    {
        tell_object(caster,"You are still affected by numbus.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 10) * clevel;

    tell_object(caster,"%^BOLD%^%^MAGENTA%^You feel your gods power warding you from the good!");
    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" is suddenly surrounded by halo of darkness!",caster);

    caster->set_property("spelled", ({TO}));
    caster->set_property("nimbus",1);
    caster->set_property("added short",({"%^BOLD%^%^MAGENTA%^ (in halo of darkness)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("room_check",ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check",ROUND_LENGTH*2);
    return;
}

void execute_attack(){
    object *attackers,room;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    room      = environment(caster);
    if(!objectp(caster) || !objectp(room))
    {
        dest_effect();
        return;
    }
    attackers = filter_array(caster->query_attackers(),(:objectp($1):));
    attackers = filter_array(attackers,(:$1->is_living():));
    attackers = filter_array(attackers,
                             (:
                              $1->query_alignment() == 1 ||
                              $1->query_alignment() == 4 ||
                              $1->query_alignment() == 7
                              :));

    if(sizeof(attackers))
    {
        define_base_damage(0);
        tell_room(room,"%^BOLD%^%^BLACK%^The darkness around "+caster->QCN+" falls upon "+caster->QP+" enemies!",({caster,target}));
        tell_object(caster,"%^BOLD%^%^BLACK%^The darkness around you falls upon your enemies!");
        for(i=0;i<sizeof(attackers);i++){
            if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
            tell_object(attackers[i],"%^BOLD%^%^BLACK%^You are scorched by the darkness as you strike "
                        ""+caster->QCN+"!");
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"divine");
        }
    }
    prepend_to_combat_cycle(place);
}

void dest_effect()
{
    remove_call_out("room_check");
    if(objectp(caster))
    {
        tell_object(caster,"%^RESET%^%^BOLD%^The halo around you fades.");
        caster->remove_property("nimbus");
	    caster->remove_property_value("added short",({"%^BOLD%^%^MAGENTA%^ (in halo of darkness)%^RESET%^"}));
    }
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }
}
