#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create()
{
    ::create();
    set_spell_name("visions from within");
    set_spell_level(([ "mage":7,"cleric":7,"bard":5, "inquisitor" : 6, "psion" : 7 ]));
    set_spell_sphere("illusion");
    set_discipline("telepath");
    set_syntax("cast CLASS visions from within");
    set_damage_desc("mental");
    set_description("With this spell the caster shares own nightmares with everyone in the area.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("will");
    set_components((["mage":(["rose petals":3,"slug":1])]));
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLUE%^(%^BLACK%^populated with %^BLACK%^n%^BLUE%^i%^BLACK%^ght%^BLUE%^m%^BLACK%^ar%^BLUE%^i%^BLACK%^s%^BLUE%^h%^BLACK%^ horrors%^BLUE%^)%^RESET%^");
}

string query_cast_string()
{
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" voices few syllables.");
    return "display";
}

void spell_effect(int prof)
{
    tell_room(place,"%^RESET%^%^BOLD%^%^BLACK%^Fearsome %^BLACK%^n%^BLUE%^i%^BLUE%^g%^BLUE%^h%^BLACK%^tma%^BLUE%^r%^BLACK%^i%^BLUE%^s%^BLACK%^h %^BLUE%^c%^BLACK%^re%^BLUE%^a%^BLUE%^t%^BLACK%^ur%^BLUE%^e%^BLUE%^s%^BLACK%^ spring into being!%^RESET%^%^RESET%^");
    counter = clevel * 3;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object *foes=({}),targ;
    int i;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster) || !objectp(place) || !present(caster,place)|| counter<0)
    {
        dest_effect();
        return;
    }

    foes = target_selector();
    foes -= ({ caster });

    define_base_damage(0);//reroll each turn
    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i]))
            continue;
        if(do_save(targ,4))
        {
            tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^Nigh%^BLUE%^t%^BLACK%^mar%^BLUE%^e%^BLACK%^s%^BLACK%^ pierce into your mind, but you manage to shrug some of them.%^RESET%^%^RESET%^");
            damage_targ(targ,targ->return_target_limb(),sdamage/2,"mental");
        }
        else
        {
            tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^Nigh%^BLUE%^t%^BLACK%^mar%^BLUE%^e%^BLACK%^s%^BLACK%^ pierce into your mind!%^RESET%^%^RESET%^");
            tell_room(place,"%^BOLD%^%^GREEN%^"+targ->QCN+"%^BOLD%^%^BLACK%^'s mind is %^BLACK%^ravag%^BLUE%^e%^BLUE%^d%^BLACK%^ by the %^BLUE%^n%^BLACK%^i%^BLUE%^g%^BLUE%^h%^BLACK%^tma%^BLUE%^r%^BLUE%^e%^BLUE%^s%^BLACK%^!%^RESET%^%^RESET%^",({targ}));
            targ->set_paralyzed(1,"%^RESET%^%^BLUE%^No! No! NO! I must run away! This can't be real!%^RESET%^");
            damage_targ(targ,targ->return_target_limb(),sdamage,"mental");
        }
    }
    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {
    if(objectp(place)) tell_object(place,"%^BOLD%^%^BLUE%^The nightmares recede.%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
