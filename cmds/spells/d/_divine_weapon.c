#include <priest.h>
#include <magic.h>
#include <spell.h>

object dwpn;

void create()
{
    ::create();
    set_author("cythera/nienne");
    set_spell_name("divine weapon");
    set_spell_level(([ "cleric" : 2, "paladin" : 1, "druid" : 2, "inquisitor": 2, "ranger" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS divine weapon");
    set_description("It is not uncommon for a priest or knight to be drawn into combat to protect her faith or deity. For that reason the gods have blessed their servants with a prayer that grants them a divine weapon.  Each faith has a different weapon, some say magical copies of the favored weapons on their patron gods.  With this spell, a divine spellcaster will create a magical weapon in their hand.

%^BOLD%^%^RED%^N.B.:%^RESET%^ Each weapon will have a few keywords to it, but all will have the name of the weapon and 'weapon' for purpose of wielding, unwielding, and showing it off.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^" + caster->QCN + " holds " + caster->QP + " hand out" +
        " as " + caster->QS + " begins to chant.";
}

void spell_effect(int prof)
{
    int ench;
    string deity = caster->query_diety();
    string normalizedDeity = deity;
    normalizedDeity = replace_string(deity, " ", "_");
    if (deity == "godless") {
        normalizedDeity = "kismet";
    }
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^BLUE%^" + capitalize(CASTER->query_diety()) + " " +
                    "hears your prayer, and in your hand a divine weapon appears!");
    }
    tell_room(place, "%^BOLD%^%^BLUE%^A weapon appears in " + caster->QCN + "'s hand!", caster);
    if (file_exists("/d/magic/obj/weapons/" + normalizedDeity + ".c") || file_exists("/d/magic/obj/weapons/" + normalizedDeity + "_knights.c")) {
        if (caster->is_class("paladin")) {
            dwpn = new("/d/magic/obj/weapons/" + normalizedDeity + "_knights");
        }else {
            dwpn = new("/d/magic/obj/weapons/" + normalizedDeity + "");
        }
        if(normalizedDeity == "cevahir")
            dwpn->set_size(caster->query_size() + 1);
        else
            dwpn->set_size(caster->query_size());
        ench = clevel / 7;
        if (ench < 0) {
            ench = 0;
        }
        if (ench > 9) {
            ench = 9;
        }
        dwpn->set_property("enchantment", ench);
        while ((int)(dwpn->query_property("enchantment")) < 0) {
            dwpn->remove_property("enchantment");
            dwpn->set_property("enchantment", ench);
        }
        dwpn->move(caster);

        caster->remove_paralyzed();
        addSpellToCaster();
        caster->force_me("wield weapon");
        spell_successful();
        return;
    }else {
        tell_object(caster, "Error: No weapon matching your god has been found. Pleae, file a bug report.");
        return;
    }
}

void dest_effect()
{
    if (objectp(dwpn) && objectp(caster)) {
        tell_object(caster, "%^BOLD%^The divine weapon fades away as the" +
                    " spell expires.");
        tell_room(environment(caster), "%^BOLD%^The weapon in " + caster->QCN + "'s" +
                  " hand fades away.", caster);
        dwpn->remove();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
