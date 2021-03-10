// Death Watch
//Changed to general cleric spell after conversations
//with Ares during the domain reworking ~Circe~ 4/24/08
#include <std.h>
#include <daemons.h>
#include <magic.h>
#include <party.h>

inherit SPELL;


void create()
{
    ::create();
    set_author("ares");
    set_spell_name("death watch");
    set_spell_level(([ "cleric" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS death watch");
    set_description("With this prayer, the priest creates a magical bond with his party mates.  The priest is able to "
        "perceive the life force of his companions and will gain a warning when one is in need of healing.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


int preSpell()
{
    if(caster->query_property("death watch")){
        tell_object(caster,"You are already using death watch.");
        return 0;
    }
    return 1;
}


string query_cast_string()
{
    tell_object(caster,"%^GREEN%^You begin to chant in a solemn tone,"+
        " your voice resonating through the area.");
    tell_room(place,"%^GREEN%^"+caster->QCN+"'s voice resonates through the area"+
        " as "+caster->QS+" chants in a solemn tone.",caster);
    return "display";
}


void spell_effect(int prof)
{
    int duration;
    duration = (ROUND_LENGTH * 40) * clevel;
    tell_object(caster,"%^GREEN%^You finish your prayer and become "+
        "much more aware of the health of your allies.");
    caster->set_property("death watch",1);
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}


void tell_caster(string str)
{
    tell_object(caster,str);
    return;
}


void execute_attack()
{
    object *party_members = ({}),room;
    string party;
    int hp,max_hp,high_percent,low_percent,i;

    ::execute_attack();
    if(!objectp(caster)){
        dest_effect();
        return;
    }

    room  = environment(caster);
    party_members = ob_party(caster);
    party_members -= ({caster});

    if(!sizeof(party_members))
    {
        room->addObjectToCombatCycle(TO,1);
        return;
    }

    for(i=0;i<sizeof(party_members);i++)
    {
        if(!present(party_members[i],room)) { continue; }
        hp           = (int)party_members[i]->query_hp();
        max_hp       = (int) party_members[i]->query_max_hp();
        high_percent = (max_hp * 75)/100;
        low_percent  = (max_hp * 60)/100;
        if(hp < low_percent)
        {
            call_out("tell_caster",0.3, "%^B_CYAN%^%^BOLD%^%^WHITE%^"+party_members[i]->QCN+" is critically injured!");
            continue;
        }
        if(hp < high_percent)
        {
            call_out("tell_caster",0.3, "%^B_GREEN%^%^BOLD%^%^WHITE%^"+party_members[i]->QCN+" is injured.");
            continue;
        }
    }

    room->addObjectToCombatCycle(TO,1);
    return;
}


void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster,"%^GREEN%^As the death watch fades, your awareness returns to normal.");
        caster->remove_property("death watch");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
