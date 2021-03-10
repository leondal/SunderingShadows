#include <magic.h>
#include "summoned_monster.h"

inherit WEAPONLESS;

object cast;
object lastroom = 0;

void create()
{
    ::create();
    set_name("astral projection");
    set_id(({"atral projection","projection",}));
    set_hd(4, 1);
    set_hp(query_hd() * 8);
    set_class("fighter");
    set_stats("strength", 20);
    set_stats("intelligence", 8);
    set_stats("wisdom", 20);
    set_stats("dexterity", 20);
    set_race("human");
    set_damage(2, 10);
    set_attacks_num(5);
    set_base_damage_type("slashing");
    set_gender("other");
    set_overall_ac(4);

    set_property("silent_equip",1);

    set_monster_feats(( {
                "opportunity strikes", "swipe",
                    }));

    set_alignment(5);
    add_action("look_around", "look");
}

look_around()
{
    int i;
    object * inv = all_inventory(ETO);
    string * oexits;

    tell_object(cast, "%^BOLD%^%^WHITE%^[A]%^RESET%^ " + ETO->query_long());
    for (i = 0; i < sizeof(inv); ++i) {
        if (!living(inv[i]))
            continue;
        if (inv[i]->id("scryx222")) {
            continue;
        }
        if (inv[i]->query_invis())
            continue;
        if (inv[i]->query_hidden())
            continue;
        if (!inv[i]->is_detectable())
            continue;

        send_living_name(inv[i]);
    }

    oexits = ETO->query_obvious_exits();
    if(sizeof(oexits))
    {
        tell_object(cast, "%^BOLD%^%^WHITE%^[A] %^CYAN%^Obvious exits: " + implode(sort_array(oexits, 1), ", "));
    }
    else
    {
        tell_object(cast, "%^BOLD%^%^WHITE%^[A] %^CYAN%^There are no obvious exits.");
    }
}

// From /d/magic/obj/scry_object.c
/**
 * Returns living name based on their profile if appliable
 */
int send_living_name(object target)
{
    string known, str;
    int i, j;

    if (target->is_monster()) {
        str = target->query_short();
        message("living_item", "%^CYAN%^BOLD%^[A] %^RED%^" + str, cast);
        return 1;
    }
    if (objectp(cast) && cast->knownAs(target->query_true_name())) {
        known = cast->knownAs(target->query_true_name());
    }
    str = target->getWholeDescriptivePhrase();
    if (known)
        str = capitalize(known) + ", " + str;
    message("living_item", "%^CYAN%^BOLD%^[A] %^RED%^" + str, cast);
    known = 0;
    return 1;
}

void setup_servant(object caster, int clevel)
{
    int level;

    if (!objectp(caster)) {
        return;
    }

    cast = caster;
    level = clevel;

    set_level(clevel);
    set_mlevel("fighter", clevel);
    set_guild_level("fighter", clevel);
    set_level(clevel);
    set_hd(clevel, 8);
    set_max_hp(clevel * 18 + 100);
    set_hp(query_max_hp());
    set_overall_ac(4 - clevel);
    set_attacks_num(clevel / 8 + 2);
    set_skill("spellcraft", clevel * 4 / 3);
    set_skill("perception", clevel);

    {
        string deity = caster->query_diety();
        string normalizedDeity;
        object wpn;
        int ench;

        normalizedDeity = replace_string(deity, " ", "_");
        if (deity == "godless")
            normalizedDeity = "kismet";

        wpn = new("/d/magic/obj/weapons/" + normalizedDeity + "");
        ench = clevel / 7;
        if (ench < 0)
            ench = 0;
        if (ench > 9)
            ench = 9;
        wpn->set_property("enchantment", ench);
        wpn->move(TO);
        wpn->set_property("monster weapon", 1);
        TO->force_me("wield weapon in left hand");
    }

    call_out("protect", ROUND_LENGTH);
}

catch_tell(string str)
{
    if (!objectp(cast)) {
        die();
        return;
    }
    tell_object(cast, "%^BOLD%^%^WHITE%^[A]%^RESET%^ " + str);
}

int move(mixed dest)
{
    ::move(dest);
    look_around();
    lastroom = ETO;
}

void protect()
{
    object *foes, foe;

    if(!objectp(cast))
        return;

    if(lastroom != ETO)
    {
        look_around();
        lastroom = ETO;
    }

    call_out("protect",ROUND_LENGTH);
    foes=cast->query_attackers();

    foreach(foe in foes)
    {
        if(!objectp(foe))
            continue;
        if(!present(foe,ENV(TO)))
            continue;
        TO->kill_ob(foe);
    }
}

void die(object obj)
{
    ::die();
    if (objectp(cast)) {
        cast->remove_property("has_elemental");
        tell_object(cast, "%^BOLD%^%^WHITE%^Death of your projection shocks you!");
        cast->set_paralyzed(8, "%^BOLD%^%^WHITE%^You are in shock!");
        cast->cause_typed_damage(cast, cast->return_target_limb(), cast->query_level() * 6, "mental");
    }
    return;
}
