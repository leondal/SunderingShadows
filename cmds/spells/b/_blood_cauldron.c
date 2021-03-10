#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create()
{
    ::create();
    set_spell_name("blood cauldron");
    set_spell_level(([ "innate":5]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS blood cauldron");
    set_damage_desc("negative energy");
    set_description("You create a storm of necrotic energy that destroys every living in sight. Any humanoid caught in the storm will replenish your health and bloodlust at the expense of its life .");
    set_verbal_comp();
    set_somatic_comp();
    set_blood_magic();
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(pl%^RESET%^%^RED%^%^BOLD%^un%^RESET%^%^RED%^ge%^BOLD%^%^BLACK%^%^RESET%^%^RED%^d in%^BOLD%^%^BLACK%^to %^RESET%^%^RED%^a %^RESET%^%^RED%^blood%^BOLD%^s%^RESET%^%^RED%^to%^BOLD%^%^BLACK%^rm)%^RESET%^");
}

string query_cast_string()
{
    tell_room(place,"%^MAGENTA%^You feel unnatural %^BOLD%^%^BLACK%^fe%^RESET%^%^MAGENTA%^ar as " +caster->QCN+" begins to concentrate.%^WHITE%^");
    return "display";
}

void spell_effect(int prof)
{
    tell_room(place,"%^BOLD%^%^BLACK%^Barrage of blood storm fills the area at " +caster->QCN+"'s command.%^RESET%^");
    caster->add_bloodlust(-100);
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
    foes = filter_array(foes, (: $1->query_property("minion") != $2:), caster);

    define_base_damage(2);

    tell_room(place, "%^BOLD%^%^RED%^The blood storm razes all life within.");
    for (i = 0; i < sizeof(foes); i++) {
        targ = foes[i];
        if (targ->query_property("negative energy affinity")) {
            continue;
        }

        if (!objectp(targ = foes[i])) {
            continue;
        }

        tell_object(targ, "%^BOLD%^%^BLACK%^You feel at an ebb as you slowly die.%^RESET%^");
        damage_targ(targ, targ->return_target_limb(), sdamage, "negative energy");

        if (RACE_D->is_valid_blooddrain_target(targ, caster)) {
            caster->add_bloodlust(100);
            caster->cause_typed_damage(caster, "torso", roll_dice(1, 4), "negative energy");
        }
    }
    counter--;
    place->addObjectToCombatCycle(TO,1);
}


void dest_effect()
{
    if (objectp(place)) {
        tell_object(place, "%^RESET%^%^BOLD%^%^RED%^The blood storm comes to an end.");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
