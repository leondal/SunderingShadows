#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create()
{
    ::create();
    set_spell_name("acid fog");
    set_spell_level(([ "mage":7,"magus" : 6, "cleric" : 7 ]));
    set_domains("creation");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS acid fog");
    set_damage_desc("acid");
    set_description("With this spell the mage opens a portal to the paraelemental plane of ooze, allowing raw matter of that plane to enter the world. For the duration of the spell's effect, the area will be filled with acid fumes. The mage can then direct them to attack her enemies.");
    set_verbal_comp();
    set_somatic_comp();
    set_immunities( ({"acid"}) );
    set_components((["mage":(["citric acid":1,"nitric acid":1])]));
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(%^GREEN%^engulfed in acid fog%^BLACK%^)%^RESET%^");
}

string query_cast_string()
{
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" %^RESET%^%^BOLD%^%^GREEN%^draws an %^BLACK%^a%^BLACK%^c%^GREEN%^i%^BLACK%^d %^BLACK%^i%^GREEN%^n%^BLACK%^f%^GREEN%^use%^BLACK%^d %^BLACK%^s%^GREEN%^igil%^GREEN%^ in the air.%^RESET%^%^RESET%^");
    return "display";
}

void spell_effect(int prof)
{
    tell_object(caster,"%^RESET%^%^BOLD%^%^GREEN%^You take quick retreat from %^BLACK%^t%^GREEN%^he %^BLACK%^s%^GREEN%^i%^BLACK%^g%^GREEN%^il%^GREEN%^ as it opens a portal and fumes rush through it!%^RESET%^%^RESET%^");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+"%^BOLD%^%^GREEN%^ takes cover as %^GREEN%^aci%^BLACK%^d%^BLACK%^i%^GREEN%^g %^GREEN%^si%^BLACK%^g%^GREEN%^il%^GREEN%^ explodes and fumes rush through the open portal!%^RESET%^%^RESET%^",caster);
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

    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i]))
            continue;
        tell_object(targ,"%^RESET%^%^BOLD%^%^GREEN%^You choke on %^GREEN%^a%^BLACK%^c%^BLACK%^i%^GREEN%^d%^BLACK%^i%^BLACK%^c %^GREEN%^fu%^BLACK%^m%^BLACK%^e%^GREEN%^s!%^RESET%^%^RESET%^");
        tell_room(place,"%^BOLD%^%^GREEN%^"+targ->QCN+" %^RESET%^%^BOLD%^%^GREEN%^chokes on %^BLACK%^a%^GREEN%^cid%^BLACK%^i%^GREEN%^c %^BLACK%^f%^GREEN%^umes%^BLACK%^!%^RESET%^%^RESET%^",({targ}));
        damage_targ(targ,targ->return_target_limb(),sdamage,"acid");
    }
    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {
    if(objectp(place)) tell_object(place,"%^RESET%^%^BOLD%^%^GREEN%^The %^BLACK%^a%^BLACK%^c%^GREEN%^idic %^GREEN%^fo%^BLACK%^g%^GREEN%^ finally disperses!%^RESET%^%^RESET%^");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
