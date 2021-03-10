#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create()
{
    ::create();
    set_spell_name("entropic storm");
    set_spell_level(([ "mage":9, "cleric":9]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS entropic storm");
    set_damage_desc("untyped");
    set_description("You create a gateway to the destructive void between the realm of shadows and realm of the death itself on the Shadow Plane, causing everyone in the area to die.");
    set_verbal_comp();
    set_somatic_comp();
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(e%^RESET%^%^MAGENTA%^mbr%^BOLD%^a%^RESET%^%^MAGENTA%^c%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^d b%^BOLD%^%^BLACK%^y %^RESET%^%^MAGENTA%^th%^BOLD%^%^BLACK%^e %^RESET%^%^MAGENTA%^d%^BOLD%^e%^RESET%^%^MAGENTA%^at%^BOLD%^%^BLACK%^h)%^RESET%^");
}

string query_cast_string()
{
    tell_room(place,"%^MAGENTA%^You feel unnatural %^BOLD%^%^BLACK%^pa%^RESET%^%^MAGENTA%^nic as " +caster->QCN+" begins to chant, invoking the very %^BOLD%^%^BLACK%^death %^RESET%^%^MAGENTA%^itself.%^WHITE%^");
    return "display";
}

void spell_effect(int prof)
{
    tell_room(place,"%^BOLD%^%^BLACK%^Colors of the world disappear as the death answers " +caster->QCN+"'s call.%^RESET%^");
    counter = clevel * 3;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object *foes=({}),targ;
    int i;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    if (!objectp(caster) || !objectp(place) || !present(caster, place) || counter < 0) {
        dest_effect();
        return;
    }

    foes = target_selector();
    foes -= ({ caster });

    define_base_damage(2);

    tell_room(place, "%^BOLD%^%^BLACK%^The deadly shadows swoop across the area.");
    for (i = 0; i < sizeof(foes); i++) {
        if (!objectp(targ = foes[i])) {
            continue;
        }

        tell_object(targ, "%^BOLD%^%^BLACK%^You feel at an ebb as you slowly die.%^RESET%^");
        damage_targ(targ, targ->return_target_limb(), sdamage, "untyped");

    }
    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect()
{
    if (objectp(place)) {
        tell_object(place, "%^RESET%^%^BOLD%^%^BLACK%^%^B_MAGENTA%^The entropic storm comes to an end.");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
