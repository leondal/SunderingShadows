#include <std.h>
#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("psionic repair");
    set_spell_level(([ "psion" : 1 ]));
    set_affixed_spell_level(3);
    set_spell_sphere("metacreativity");
    set_syntax(
        "cast CLASS psionic repair on OBJECT
        cast CLASS psionic repair on OBJECT at PLAYER");
    set_description("This spell will attempt to repair the item in question. If a player target is not specified, it will default to items carried in the caster's inventory. Unlike normal repairs, the reliability of the spell is based upon the caster's power. The spell cannot be cast in combat.

If used on a construct, this spell will repair it as efficiently as repair undead spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_casting_string()
{
    return "%^BOLD%^%^CYAN%^" + caster->QCN + " places a finger to " + caster->query_possessive() + " head and concentrates.%^RESET%^";
}

int preSpell()
{
    if (!arg) {
        tell_object(caster, "You must specify what to repair.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    string what, who;
    object ob, ob2;
    int state, myskill, diff, variant;

    if (sscanf(arg, "%s at %s", what, who) != 2) {
        what = arg;
        who = 0;
    }

    if (!who)
    {
        ob = present(what, caster);
        if (!objectp(ob)) {
            ob = present(what, place);
        }
    }
    else
    {
        if ((string)caster->realName(who) != "") {
            who = (string)caster->realName(who);
        }
        if (place && who && !ob2 = present(who, place)) {
            tell_object(caster, "That person isn't here.");
            dest_effect();
            return;
        }
        ob = present(what, ob2);
    }
    if (!objectp(ob)) {
        tell_object(caster, "That object is not present.");
        dest_effect();
        return;
    }

    if (ob->is_living() && member_array(ob->query_race(), ({"soulforged", "golem", "construct"})) != -1) {
        tell_object(ob,"%^BOLD%^%^CYAN%^You tremble as the spell passes over you and appears to be in better shape.");
        tell_room(place, "%^BOLD%^%^CYAN%^" + ob->QCN + " trembles as the spell passes over them and appear to be in better shape.");

        damage_targ(ob, ob->return_target_limb(), -sdamage * 7 / 6, "untyped");

        return;
    }

    if (!ob->query_property("repairtype") &&
        !ob->is_instrument() && !ob->is_armor() && !ob->is_weapon() && !ob->is_container() && !ob->is_carving()) {
        tell_object(caster, "That item cannot be repaired.");
        dest_effect();
        return;
    }
    if (ob->query_property("no repair")) {
        tell_object(caster, "That item cannot be repaired.");
        dest_effect();
        return;
    }

    state = ob->query_overallStatus();
    if (state >= 100) {
        tell_object(caster, "That object is not damaged.");
        dest_effect();
        return;
    }
    spell_successful();
    myskill = clevel;     // slightly diff DC to "repair cmd";
    //negated the +10 on DC so using straight clevel against it.

    diff = (int)ob->query_property("enchantment") * 3;
    if (diff < 0) {
        diff = diff * (-1);
    }
    variant = (myskill - diff) * 2;
    if (variant > 40) {
        variant = 40;
    }
    if (variant < -40) {
        variant = -40;                   // don't allow them to do more than 40% damage per repair
    }

    ob->repairMe(variant);

    if (variant < 0) {   //failed
        tell_room(place, "%^BOLD%^%^CYAN%^The " + what + " trembles as the psionic energy passes over it, but it appears that more harm than good has been done by its effects.");
        if (state == 0) {
            tell_room(place, "%^BOLD%^%^WHITE%^The " + what + " is too badly damaged and simply falls apart.");
            ob->remove();
        }
        dest_effect();
        return;
    }
    if (variant == 0) {//no diff
        tell_room(place, "%^BOLD%^%^CYAN%^The " + what + " trembles as the psionic energy passes over it, but you can see no noticeable "
                  "improvement to it.");
        dest_effect();
        return;
    }
    if (state == 100) {
        tell_room(place, "%^BOLD%^%^CYAN%^The " + what + " trembles as the psionic energy passes over it, and it looks as "
                  "good as new.");
    }else {
        tell_room(place, "%^BOLD%^%^CYAN%^The " + what + " trembles as the psionic energy passes over it, and it appears to be in "
                  "better shape.");
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
