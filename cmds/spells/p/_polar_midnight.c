#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;
int prevlight;


void create()
{
    ::create();
    set_spell_name("polar midnight");
    set_spell_level(([ "druid":9,"oracle":9, "cleric":9]));
    set_spell_sphere("alteration");
    set_mystery( ({ "darkness", "lunar", "winter" }) );
    set_syntax("cast CLASS polar midnight");
    set_damage_desc("cold, exhaustion");
    set_description("You plunge an area into the brutal chill of the arctic night. Illumination conditions are dropped by to negative level, and all creatures in the area take cold damage. A failed save each round causes them to become exhausted.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
    aoe_spell(1);
    set_aoe_message("%^RESET%^%^%^BLUE%^(%^BOLD%^%^BLACK%^in deepest darkness%^RESET%^%^BLUE%^)%^RESET%^");
}

string query_cast_string()
{
    tell_room(place,"%^RESET%^%^BLUE%^As "+caster->QCN+" voices a few syllables, the place becomes darker and colder.");
    return "display";
}

void spell_effect(int prof)
{
    tell_room(place,"%^BOLD%^%^BLACK%^Extreme cold and darkness falls onto the area!");
    prevlight=place->query_light();
    if(prevlight>-2)
        place->set_light(-2);
    counter = clevel * 2;
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

    message("info", "%^BOLD%^%^BLACK%^The brutal chill of the arctic night permeates the area!%^RESET%^", place);
    foes = target_selector();
    foes -= ({ caster });

    define_base_damage(0);//reroll each turn
    for(i=0;i<sizeof(foes);i++) {
        if(!objectp(targ = foes[i]))
            continue;
        if(!do_save(foes[i],0))
        {
            "/std/effect/status/exhausted"->apply_effect(foes[i],1);
        }
        tell_object(targ,"%^BOLD%^%^BLACK%^The cold slips deep into your bones!");
        damage_targ(targ,targ->return_target_limb(),sdamage,"cold");
    }
    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect() {
    if(objectp(place))
    {
        place->set_light(prevlight);
        tell_object(place,"%^BOLD%^%^BLUE%^The darkness recedes, and the place becomes a bit warmer.%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
