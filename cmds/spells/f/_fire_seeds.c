//Fire Seeds for druids
//Partially based on fireball
//Coded by ~Circe~ 3/19/13

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#define WILD_TERRAINS ({ "heavy forest", "light forest", "jungle", "dense jungle", "scrub lands", "grasslands", "savannah", "desert", "desert rocks", "rocky", "hills", "branches", "old mounts", "new mounts", "swamp", "marsh", "snow", "meadows", "beach", "shore", "nat cave", "built cave", "built tunnel", "nat tunnel", "cemetery", "garden" })

inherit SPELL;

int effect, x, i, y;
object victim, tempob, * foes, * oldfoes, * allies;
void damage();

void create()
{
    ::create();
    set_spell_name("fire seeds");
    set_spell_level(([ "druid" : 6, "oracle" : 6, ]));
    set_mystery("flame");
    set_spell_sphere("fire");
    set_syntax("cast CLASS fire seeds on TARGET");
    set_description("Upon casting this spell, a druid scoops up seeds from "
                    "the surrounding wilderness and enchants them before hurling them "
                    "at his foes.  The seeds explode upon impact, burning his foes.  The "
                    "druid will make an attempt to damage only foes, but that is not always "
                    "possible, and targets have a chance to avoid the brunt of the spell for "
                    "half damage.  This spell can be cast only in the wilderness.\n\n"
                    "%^BOLD%^NOTE:%^RESET%^ If you receive a message that you cannot cast "
                    "the spell in a certain room because of the terrain and you think you "
                    "received the message in error, please <bug here> and let us know so we "
                    "can see if the terrain needs to be adjusted.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_immunities(({ "fire" }));
    set_save("reflex");
}

/* int preSpell() { */
/*     string myterrain = environment(caster)->query_terrain(); */
/*     if(member_array(myterrain,WILD_TERRAINS) == -1){ */
/*         tell_object(caster, "You cannot find any seeds to cast that spell in this terrain!"); */
/*         tell_object(caster, "Terrain type = "+myterrain+""); */
/*         return 0; */
/*     } */
/*     return 1; */
/* } */

string query_cast_string()
{
    return "%^RESET%^%^RED%^" + caster->QCN + " kneels, scooping a handful of seeds "
        "from the ground as " + caster->QS + " chants, " + caster->QP + " eyes on " + target->QCN + ".\%^RESET%^";
}

void spell_effect(int prof)
{
    if (!present(target, caster->is_room()?caster:environment(caster))) {
        tell_object(caster, "%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    spell_successful();
    spell_kill(target, caster);
    if (!interactive(caster) && !caster->query_invis()) {
        foes = ({});
    }
    if (!living(caster)) {
        foes = target_selector();
    }
    if (!objectp(target)) {
        return;
    }
    if (sizeof(foes) > 0) {
        if (member_array(target, foes) != -1) {
            foes -= ({ target });
        }
    }


    foes = target_filter(foes);

    if (interactive(caster)) {
        tell_object(target, "%^RESET%^%^ORANGE%^" + caster->QCN + " hurls the seeds directly at you!%^RESET%^");
    }
    if (living(caster)) {
        tell_object(caster, "%^RESET%^%^ORANGE%^You hurl the seeds at " + target->QCN + "!%^RESET%^");
    }
    tell_room(place, "%^BOLD%^%^RED%^" + caster->QCN + " hurls the seeds "
              "at " + target->QCN + ", and they explode in a riot of flames!%^RESET%^", ({ caster, target }));
    tell_object(target, "%^BOLD%^%^RED%^The seeds explode, engulfing you in flames!%^RESET%^");
    tell_object(caster, "%^BOLD%^%^RED%^The seeds explode, engulfing "
                "" + target->QCN + " in sizzling flames!%^RESET%^");
    oldfoes = foes;
    foes = ({});
    allies = ({});
    y = 2 + to_int((clevel - 5) / 2);
    if (sizeof(oldfoes) < y) {
        y = sizeof(oldfoes);
    }
    for (x = 0; x < y; x++) {
        tempob = oldfoes[random(sizeof(oldfoes))];
        if (do_save(tempob)) {
            allies += ({ tempob });
        }else {
            foes += ({ tempob });
        }
        oldfoes -= ({ tempob });
    }
    y = clevel;
    if (do_save(target)) {
        damage_targ(target, "torso", to_int(sdamage / 2), "fire");
    }else {
        damage_targ(target, "torso", sdamage, "fire");
    }
    for (x = 0; x < sizeof(foes); x++) {
        if (!objectp(foes[x])) {
            continue;
        }
        tell_room(environment(foes[x]), "%^BOLD%^%^WHITE%^The fiery blast from the seeds slams into " + foes[x]->QCN + "!", foes[x]);
        tell_object(foes[x], "%^BOLD%^%^WHITE%^The fiery blast from the seeds slams into you!");
        if (do_save(foes[x])) {
            damage_targ(foes[x], "torso", to_int(sdamage / 2), "fire");
        }else {
            damage_targ(foes[x], "torso", sdamage, "fire");
        }
    }
    for (x = 0; x < sizeof(allies); x++) {
        if (!objectp(allies[x])) {
            continue;
        }
        tell_room(environment(allies[x]), "%^RESET%^%^ORANGE%^" + allies[x]->QCN + " is singed by the blast from the seeds!%^RESET%^", allies[x]);
        tell_object(allies[x], "%^RESET%^%^ORANGE%^You are singed by the blast from the seeds!%^RESET%^");
        if (do_save(allies[x])) {
            damage_targ(allies[x], "torso", to_int(sdamage / 4), "fire");
        }else {
            damage_targ(allies[x], "torso", sdamage / 2, "fire");
        }
    }
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
