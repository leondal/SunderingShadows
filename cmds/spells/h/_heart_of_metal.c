//heart of metal, 3/24/2020, Odin

#include <priest.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;
#define MYTYPES ({ "silver", "cold iron" })

object mywpn;
string origtype, weaponarg, typearg, ashort;
int args;

void create()
{
    ::create();
    set_spell_name("heart of metal");
    set_spell_level(([ "mage" : 3, "cleric" : 3, "oracle" : 3, "inquisitor" : 3, "innate" : 3, "magus" : 3 ]));
    set_spell_sphere("alteration");
    set_mystery("metal");
    set_syntax("cast CLASS heart of metal on <weapon> with <type>");
    set_description("Using this spell, you temporarily lend the powers of either silver or cold iron to the target weapon. This will change its base damage type for the duration of the spell. It will last a number of rounds equal to twice your caster level.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_target_required();
    set_helpful_spell(1);
}

int preSpell()
{
    args = sscanf(arg, "%s with %s", weaponarg, typearg);
    if (!weaponarg) {
        tell_object(caster, "You must specify a target weapon for this power!");
        return 0;
    }
    if (!mywpn = present(weaponarg, caster)) {
        tell_object(caster, "You don't have any " + weaponarg + " in your inventory!");
        return 0;
    }
    if (!mywpn->is_weapon()) {
        tell_object(caster, "That " + weaponarg + " is not a weapon!");
        return 0;
    }
    if (args != 2) {
        tell_object(CASTER, "You need to specify both your weapon and the type of metal.");
        return 0;
    }
    if (member_array(typearg, MYTYPES) == -1) {
        tell_object(caster, "That is not a valid type of metal!");
        return 0;
    }
    origtype = mywpn->query_special_material_type();
    return 1;
}

void spell_effect(int prof)
{
    int mylevel;
    switch (typearg) {
    case "silver":
        ashort = " %^BOLD%^%^WHITE%^{{s%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^lv%^RESET%^%^WHITE%^e%^BOLD%^%^WHITE%^ry%^BOLD%^%^WHITE%^}}%^RESET%^";
        mywpn->set_special_material_type("silver");
        mywpn->remove_property("added short string");
        mywpn->set_property("added short string", ({ ashort }));
        mywpn->set_property("added short", ({ ashort }));
        if (interactive(caster)) {
            tell_object(caster, "%^BOLD%^%^WHITE%^You gather the very essence of silver about you infuse your " + weaponarg + " with its mystical powers.%^RESET%^");
        }
        tell_room(place, "%^BOLD%^%^WHITE%^As " + caster->QCN + " concentrates on " + caster->QP + " " + weaponarg + ", the weapon itself turns to pure silver!.%^RESET%^", caster);
        caster->remove_paralyzed();
        spell_successful();
        caster->set_property("spelled", ({TO}) );
        addSpellToCaster();
        mylevel = clevel;
        spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
        set_end_time();
        call_out("dest_effect",spell_duration);
        break;

    case "cold iron":
        ashort = " %^RESET%^%^RED%^{{cold iron}}%^RESET%^";
        mywpn->set_special_material_type("cold iron");
        mywpn->remove_property("added short string");
        mywpn->set_property("added short string", ({ ashort }));
        mywpn->set_property("added short", ({ ashort }));
        if (interactive(caster)) {
            tell_object(caster, "%^RESET%^%^RED%^You gather the very essence of cold iron about you infuse your " + weaponarg + " with its mystical powers.%^RESET%^");
        }
        tell_room(place, "%^RESET%^%^RED%^As " + caster->QCN + " concentrates on " + caster->QP + " " + weaponarg + ", the weapon itself turns to pure cold iron!.%^RESET%^", caster);
        caster->remove_paralyzed();
        spell_successful();
        caster->set_property("spelled", ({TO}) );
        addSpellToCaster();
        mylevel = clevel;
        spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 2;
        set_end_time();
        call_out("dest_effect",spell_duration);
        break;
    }
}

void dest_effect()
{
    if (objectp(caster)) {
        tell_object(caster, "%^RESET%^%^CYAN%^Your weapon reverts to its normal material.%^RESET%^");
    }
    if (objectp(mywpn)) {
        mywpn->remove_property_value("added short", ({ ashort }));
        mywpn->remove_property("added short string", ({ ashort }));
        mywpn->remove_property("added short string");
        mywpn->set_special_material_type(origtype);
    }
    if (objectp(TO)) {
        TO->remove();
    }
    ::dest_effect();
}
