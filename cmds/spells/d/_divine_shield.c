#include <priest.h>

object dshld;

void create()
{
    ::create();
    set_author("cythera");
    set_spell_name("divine shield");
    set_spell_level(([ "paladin" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS divine shield");
    set_description("Calling out for protection against the forces that the caster must battle, this prayer creates a divine shield that will offer protection to the priest, helping him to defend himself.\n\n*NOTE*\nEach shield will have a few keywords to it, but all will have the name of the shield and 'shield' for purpose of wielding, unwielding, and showing it off.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    tell_object(caster, "%^BOLD%^%^RED%^Holding out your arm, you begin" +
                " to recite in a steady metered tone.");

    tell_room(place, "%^BOLD%^%^RED%^Holding out " + caster->QP + " arm," +
              " " + caster->QCN + " begins to recite in a steady metered" +
              " tone.", caster);

    return "display";
}

void spell_effect(int prof)
{
    int ench = 0;
    string deity = caster->query_diety();
    string normalizedDeity = deity;
    string fname;

    if (deity == "lord shadow") {
        normalizedDeity = "lord_shadow";
    }
    if (deity == "the faceless one") {
        normalizedDeity = "the_faceless_one";
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^ORANGE%^The air begins to waver and " +
                    "solidify around your arm, as a divine shield manifests.");

        if (objectp(place)) {
            tell_room(place, "%^ORANGE%^The air begins to waver and solidfy " +
                      "around " + caster->QCN + "'s arm, as a divine shield manifests.!", caster);
        }

        if (file_exists("/d/magic/obj/shields/" + normalizedDeity + ".c")) {
            fname = "/d/magic/obj/shields/" + normalizedDeity;
        } else {
            fname = "/d/magic/obj/shields/kismet";
        }


        if (file_exists(fname + ".c")) {
            dshld = new(fname + "");
            ench = clevel / 7;
            if (ench < 1) {
                ench = 1;
            }
            if (ench > 5) {
                ench = 5;
            }
            dshld->set_property("enchantment", ench);
            while ((int)(dshld->query_property("enchantment")) < 0) {
                dshld->remove_property("enchantment");
                dshld->set_property("enchantment", ench);
            }
            dshld->move(caster);
            addSpellToCaster();
            caster->remove_paralyzed();
            caster->force_me("wear shield");
            spell_successful();
            spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 10;
            set_end_time();
            call_out("dest_effect", spell_duration);
            addSpellToCaster();
            return;
        }else {
            tell_object(caster, "Oh no! Demonic squirrels have stolen your " +
                        "weapon, please bug report with who your deity is and that" +
                        " you were trying to cast this spell.");
            if (objectp(dshld)) {
                dshld->remove();
            }
            return;
        }
    }
}

void dest_effect()
{
    if (objectp(dshld) && objectp(caster)) {
        tell_object(caster, "%^BOLD%^%^RED%^The divine shield fades away as the" +
                    " spell expires.");
        tell_room(environment(caster), "%^BOLD%^The shield around " + caster->QCN + "'s" +
                  " arm fades away.", caster);
        dshld->remove();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
