#include <std.h>
#include <spell.h>
inherit SPELL;

object fob, tob;

void create()
{
    ::create();
    set_spell_name("siphon magic");
    set_spell_level(([ "mage" : 5, "cleric" : 5, "inquisitor" : 5, "oracle" : 5, "magus" : 5 ]));
    set_mystery("spellscar");
    set_spell_sphere("abjuration");
    set_syntax(
        "cast CLASS siphon magic on OBJECT2 into OBJECT2");
    set_description("With this spell you can transfer enchantment value between objects of the same type.

This spell uses 66 260 gp as a material component.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^BOLD%^%^MAGENTA%^" + caster->QCN + " utters a short %^GREEN%^r%^CYAN%^h%^GREEN%^ym%^CYAN%^e %^MAGENTA%^under " + caster->QP + " breath.";
}

int preSpell()
{
    string sfob, stob;
    if (sscanf(arg, "%s into %s", sfob, stob) != 2) {
        tell_object(caster, "You must specify both object you take magic from and object you transfer it to.");
        return 0;
    }
    fob = present(sfob, caster);
    if (!caster->query_funds("gold", 66260)) {
        tell_object(caster, "You don't have enough money.");
        return 0;
    }
    if (!objectp(fob)) {
        tell_object(caster, "The first object is not present.");
        return 0;
    }
    tob = present(stob, caster);
    if (!objectp(tob)) {
        tell_object(caster, "The Ssecond object is not present.");
        return 0;
    }
    if (!(fob->is_weapon() || fob->is_armor())) {
        tell_object(caster, "The first object is neither a weapon nor an armor piece.");
        return 0;
    }
    if (!(tob->is_weapon() || tob->is_armor())) {
        tell_object(caster, "The second object is neither a weapon nor an armor piece.");
        return 0;
    }
    if (strsrch(base_name(fob), "/d/magic/") != -1 ||
        fob->query_property("monsterweapon")) {
        tell_object(TP, "You cannot siphon a conjured item!");
        return 1;
    }
    if (fob->query_weight() > 200) {
        tell_object(TP, "This is too large to siphon!");
        return 1;
    }
    if (tob->query_property("no repair")) {
        tell_object(TP, "This object can't accept magic!");
        return 1;
    }
    if (((fob->is_weapon() && !tob->is_weapon()) ||
         (!fob->is_weapon() && tob->is_weapon())) &&
        ((fob->is_armor() && !tob->is_armor()) ||
         (!fob->is_armor() && tob->is_weapon()))) {
        tell_object(caster, "Both objects must be of the same type.");
        return 0;
    }
    if (fob->query_property("no repair")) {
        tell_object(caster, "The first object refuses siphoning.");
        return 0;
    }
    if (fob->query_property("enchantment") < 1) {
        tell_object(caster, "The first object must be enchanted.");
        return 0;
    }
    if (fob->query_property("enchantment") > 7) {
        tell_object(caster, "The first object is too powerful.");
        return 0;
    }
    if (tob->query_property("player enchanted")) {
        tell_object(caster, "The second object must not be enchanted by adventurers.");
        return 0;
    }
    if (tob->query_property("enchantment") > fob->query_property("enchantment")) {
        tell_object(caster, "The second object must not have higher enchantment than the first one.");
        return 0;
    }
    if (tob->query_property("enchantment") < 0) {
        tell_object(caster, "The second object must not be cursed.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int enchantment;

    if (!objectp(fob) || !objectp(tob)) {
        tell_object(caster, "That object is no longer present.");
        dest_effect();
        return;
    }
    if (!caster->query_funds("gold", 66260)) {
        tell_object(caster, "You don't have enough money.");
        return;
    }

    caster->use_funds("gold", 66260);

    enchantment = fob->query_property("enchantment");

    fob->remove_property("enchantment");
    tob->remove_property("enchantment");
    tob->set_property("enchantment", abs(enchantment));
    tell_object(caster, "%^BOLD%^%^MAGENTA%^You place " + fob->query_short() + "%^BOLD%^%^MAGENTA%^ over " + tob->query_short() + "%^BOLD%^%^MAGENTA%^ and melt a golden pile beneath them, the vapor transfers the magic.%^RESET%^");
    tell_room(caster, "%^BOLD%^%^MAGENTA%^" + caster->QCN + " places " + fob->query_short() + "%^BOLD%^%^MAGENTA%^ over " + tob->query_short() + "%^BOLD%^%^MAGENTA%^ and melts a pile of gold beneath them into a vapor that carries magic.%^RESET%^", ({ caster }));
    dest_effect();
}
