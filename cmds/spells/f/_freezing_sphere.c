// variation of fireball
//    Frost Sphere - Cythera 5/05
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int effect, x, i, y;
string tmp, YOU, HIM;
object victim, tempob, * foes, * oldfoes, * tempfoes, * watchers, * allies;

void damage();

void create()
{
    ::create();
    set_author("cythera");
    set_spell_name("freezing sphere");
    set_spell_level(([ "mage" : 6, "magus" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS freezing sphere on TARGET");
    set_description("Freezing sphere creates a frigid globe of cold energy that streaks from your fingertips to the location you select, where it explodes in a burst, dealing cold damage to each creature in the area.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^CYAN%^" + caster->QCN + " chants rapidly," +
        " creating an sphere of frost in " + caster->QP + " hand.";
}

void spell_effect(int prof)
{
    YOU = caster->QCN;

    if (!present(target, caster->is_room() ? caster : environment(caster))) {
        tell_object(caster, "%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    spell_successful();
    if (!interactive(caster) && !caster->query_invis()) {
        YOU = caster->QCN;
    }
    HIM = target->QCN;
    foes = target_selector();
    if (member_array(target, foes) != -1) {
        foes -= ({ target });
    }

    tmp = "";
    if (interactive(caster)) {
        tmp = "'s finger";
    }
    tell_object(target, "%^BOLD%^%^CYAN%^An sphere of frost and ice " +
                "speeds through the air from " + YOU + tmp + ", heading straight for you!");
    if (living(caster)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^An sphere of frost and ice" +
                    " speeds through the air from your hand, heading straight for " + HIM + "!");
    }
    tell_room(place, "%^BOLD%^%^CYAN%^An sphere of frost and ice speeds through" +
              " the air from " + YOU + tmp + ", heading straight for " + HIM + "!", ({ caster, target }));
    tell_object(target, "%^BOLD%^%^WHITE%^The frost sphere explodes as it hits you!", target);
    tell_room(environment(target), "%^BOLD%^%^WHITE%^The sphere of frost explodes" +
              " as it hits " + target->QCN + "!", target);
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
        } else {
            foes += ({ tempob });
        }
        oldfoes -= ({ tempob });
    }
    y = clevel;

    if (do_save(target)) {
        damage_targ(target, "torso", to_int(sdamage / 2), "cold");
    } else {
        damage_targ(target, "torso", sdamage, "cold");
    }
    for (x = 0; x < sizeof(foes); x++) {
        if (!objectp(foes[x])) {
            continue;
        }
        tell_room(environment(foes[x]), "%^BOLD%^%^CYAN%^Shards of ice and frost freeze " + foes[x]->QCN + "!", foes[x]);
        tell_object(foes[x], "%^BOLD%^%^CYAN%^You are struck with shards of ice and frost from the sphere.");
        if (do_save(foes[x])) {
            damage_targ(foes[x], "torso", to_int(sdamage / 2), "cold");
        } else {
            damage_targ(foes[x], "torso", sdamage, "cold");
        }
    }
    sdamage /= 2;
    for (x = 0; x < sizeof(allies); x++) {
        if (!objectp(allies[x])) {
            continue;
        }
        tell_room(environment(allies[x]), "%^BOLD%^%^CYAN%^Shards of ice and" +
                  " frost strike " + allies[x]->QCN + "!", allies[x]);
        tell_object(allies[x], "%^BOLD%^%^CYAN%^Shards of ice and frost freeze you from the sphere!");
        if (do_save(allies[x])) {
            damage_targ(allies[x], "torso", to_int(sdamage / 2), "cold");
        } else {
            damage_targ(allies[x], "torso", sdamage, "cold");
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
