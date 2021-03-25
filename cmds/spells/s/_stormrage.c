#include <spell.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

object tempob;
object* foes;
int dmg, x, y, count;

void create()
{
    ::create();
    set_spell_name("stormrage");
    set_spell_level(([ "cleric" : 8 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS stormrage");
    set_description("In using this spell, the caster calls upon the might of the weather, creating a powerful storm in an "
                    "area.  The storm takes several rounds to develop and a few more to recede.  With it comes stinging winds, hail, and "
                    "blasts of lightning.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(swept up in the throes of a %^RESET%^%^BLUE%^powerful %^BOLD%^%^BLACK%^storm)%^RESET%^");
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^" + caster->QCN + " lifts both hands, " +
        "chanting a spell of ancient might!%^RESET%^";
}

int preSpell()
{
    if (place->query_property("underwater")) {
        tell_object(caster, "%^BOLD%^That spell can only be cast in " +
                    "open air, not underwater.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int i;

    if (!objectp(caster) || !objectp(place)) {
        dest_effect();
        return;
    }
    tell_object(place, "%^BOLD%^%^BLACK%^Dark clouds %^BLUE%^begin " +
                "to gather and swirl as the %^CYAN%^wind %^BLUE%^picks up!%^RESET%^");
    count = 0;
    spell_successful();
    addSpellToCaster();
    call_out("do_storm", 2);
}

void do_storm()
{
    if (!objectp(caster) || !objectp(place)) {
        dest_effect();
        return;
    }
    if (caster->query_ghost() || caster->query_unconscious()) {
        tell_room(place, "%^BOLD%^%^BLACK%^The swirling mass of clouds dies down and dissipates.%^RESET%^", caster);
        dest_effect();
        return;
    }
    if (count > clevel * 4) {
        tell_room(place, "%^BOLD%^%^BLACK%^The swirling mass of clouds dies down and dissipates.%^RESET%^", caster);
        dest_effect();
        return;
    }
    foes = target_selector();
    foes -= ({ caster });

    define_base_damage(0);
    dmg = sdamage;

    switch (random(3)) {
    case 0:
        tell_object(caster, "%^BOLD%^%^BLUE%^The swirling winds " +
                    "bending to your will, scouring the area!");
        tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " directs the " +
                  "winds to scour all in their path!", caster);

        y = 2 + to_int((clevel - 5) / 2);
        if (sizeof(foes) < y) {
            y = sizeof(foes);
        }
        for (x = 0; x < sizeof(foes); x++) {
            if (!objectp(foes[x])) {
                continue;
            }
            if (foes[x]->query_true_invis()) {
                continue;
            }
            if (do_save(foes[x], 0)) {
                tell_object(foes[x], "%^BOLD%^%^WHITE%^Your skin burns as the edge of the windstorm buffets you!%^RESET%^");
                damage_targ(foes[x], foes[x]->return_target_limb(), (dmg / 2), "bludgeoning");
            }else {
                tell_object(foes[x], "%^BOLD%^%^WHITE%^You feel a horrid burning as your skin is scoured by the swirling winds!%^RESET%^");
                damage_targ(foes[x], foes[x]->return_target_limb(), dmg, "bludgeoning");
            }
        }
        count++;
        call_out("do_storm", ROUND_LENGTH);
        break;
    case 1:
        tell_object(caster, "%^BOLD%^%^BLACK%^The swirling winds form " +
                    "dark clouds, releasing " +
                    "%^CYAN%^hail%^BLACK%^ to batter your foes!%^RESET%^");
        tell_room(place, "%^BOLD%^%^BLACK%^The swirling winds form " +
                  "dark clouds, unleashing %^CYAN%^hail %^BLACK%^that suddenly hurtles " +
                  "toward the ground!%^RESET%^", caster);

        y = 2 + to_int((clevel - 5) / 2);
        if (sizeof(foes) < y) {
            y = sizeof(foes);
        }
        for (x = 0; x < sizeof(foes); x++) {
            if (!objectp(foes[x])) {
                continue;
            }
            if (foes[x]->query_true_invis()) {
                continue;
            }
            if (do_save(foes[x], 0)) {
                tell_object(foes[x], "%^BOLD%^%^RED%^A few of the hailstones still hit you!%^RESET%^");
                damage_targ(foes[x], foes[x]->return_target_limb(), (dmg / 2), "cold");
            }else {
                tell_object(foes[x], "%^BOLD%^%^RED%^You are battered by the hailstones!%^RESET%^");
                damage_targ(foes[x], foes[x]->return_target_limb(), dmg, "cold");
            }
        }
        count++;
        call_out("do_storm", ROUND_LENGTH);
        break;
    default:
        tell_object(caster, "%^BOLD%^%^BLACK%^Amid the swirling " +
                    "clouds and %^CYAN%^hail%^BLACK%^, you call forth " +
                    "%^YELLOW%^lightning %^BLACK%^to strike your foes!%^RESET%^");
        tell_room(place, "%^BOLD%^%^BLACK%^" + caster->QCN + " calls forth " +
                  "%^YELLOW%^lightning %^BLACK%^from the swirling clouds and " +
                  "%^CYAN%^hail%^BLACK%^, directing it to strike at " +
                  "" + caster->QP + " enemies!%^RESET%^", caster);

        y = 2 + to_int((clevel - 5) / 2);
        if (sizeof(foes) < y) {
            y = sizeof(foes);
        }
        for (x = 0; x < sizeof(foes); x++) {
            if (!objectp(foes[x])) {
                continue;
            }
            if (foes[x]->query_true_invis()) {
                continue;
            }
            if (do_save(foes[x], 0)) {
                tell_object(foes[x], "%^RESET%^%^ORANGE%^%^You feel the heat of " +
                            "the lightning but manage to avoid being struck directly!%^RESET%^");
                damage_targ(foes[x], foes[x]->return_target_limb(), to_int(dmg / 2), "electricity");
            }else {
                tell_object(foes[x], "%^YELLOW%^You are struck by a " +
                            "bolt of lightning!%^RESET%^");
                damage_targ(foes[x], foes[x]->return_target_limb(), dmg, "electricity");
            }
        }
        count++;
        call_out("do_storm", ROUND_LENGTH);
        break;
    }
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
