//Adjusted bonus values and added validate function to adjust values over maxiumum allowed - Yves 12/18
/* from http://www.shadowgate.s4.bizhat.com/viewtopic.php?t=2980&mforum=shadowgate
   // going to attempt to make this fit as well as can be allowed to determine what an item's level should be based on its bonuses

   Overall directions:

   // currently this will do a valid limb check by comparing it to an item it inherits from /d/common if it's armor
   // generally the safest bet is to inherit your items from something in /d/common somewhere, and don't change the limbs

   -players currently have nine equipment slots: head, neck, torso, waist, left/right arm, left/right hand x2,
   left/right leg (or foreleg for wemic/centaur), and left/right foot (or hoof/forepaw for minotaur/wemic/centaur).
   Please ensure your items match the corresponding slot; bracers, bracelets, gloves and gauntlets should all be
   allocated to the arms slot; greaves should be on legs/forelegs; left/right hand should ONLY be used for rings
   and other trinkets - usually this will be a ROP and one other misc magical trinket.


   -all core equipment should generally pick up the standard enchantment for the level; please do not feel the need to
   downgrade enchantments anymore on "rare" item slots like boots and hats. Eg/ most L30+ areas should drop +5 items
   consistently for any slot; +2 items should not be found before around L12. The only exception here should be the
   second ring slot; if the ring/trinket you are making is not a ROP (and not locked down accordingly for stacking),
   it should NOT have an enchantment except in the rarest of cases. If you want it to carry AC, please put a magical
   armor bonus instead.


   -standard in-area items (non-boss drops) may sometimes pick up a secondary bonus as well, but usually these would
   be only one, usually at a lesser rate, or none at all. Eg/ a L30+ in-area item may be +5 with no bonuses,
   or with a +2 to stealth.


   -soloable boss-type items should generally pick up at least one full-rate secondary perk, or two if they are below
   the recommended rate. Remember that due to non-stacking bonuses, it is usually more beneficial to a player to have
   one big bonus rather than a bunch of little ones. Eg/ a L30+ boss item may be +5 enchantment, and in addition may
   include a +3 bonus to a saving throw, or +1/2 to all saves.


   -major boss-fights written to be non-soloable would be recommended to pick up two full-rate bonuses, rather than one,
   to represent the additional challenge, or three bonuses if they are below the full recommended rate. Eg/ a L30+ group
   boss (such as Arkhon) may give a +5 item with +3 to two skills, or +2 to a couple skills and a stat. Again, it's
   usually more to a player's benefit to have two large perks rather than three small ones.

   --------------------------------------------------


   Specific rates for bonus types:

   Enchantments: while they can be worn at +1/5 levels, area drop rates should be aimed at +1/7 levels. Thus, we should
   only see +3 items start appearing in L20+ areas, and +5 only mid 30's zones. This also means when the cap is boosted
   that we may potentially see up to +7 items as accessible drops, although these should only be on the very upper-most
   fights at L50 (ie Klauth & similar).


   Stats: given the relevance to our 3e-based stat system, these should only drop in even numbers (+2, +4, +6 - please
   do not implement odd numbers), and should scale at minimum +2/15 levels. Thereby, +2 items should only be found
   from areas L15+; +4 items should only be found from areas L30+; +6 items should only be found in areas L45+.


   Skills, saving throws: both of these areas work on a d20 and thereby become intensely valuable with only a few
   points, so need to be kept limited. Bonuses should only be granted at approx +1/10 level areas; this should
   give only the very best and rarest at +5 on the uppermost endgame creatures at the L50 cap.


   AC bonus, attack bonus, damage bonus, damage resistance: these quickly accumulate, given they affect all hits
   in a round, so need to be even more limited, recommended at approx +1/12 level areas. To this end in our L40-capped
   version the highest ever itemised was +3 (L35+ areas such as Arkhon), and should never exceed +4, only found on the
   uppermost endgame creatures at the L50 cap.


   Empowered or bonus spell slots: needs to be kept very limited as this stacks up quickly, particularly with
   multiclasses; recommended scaling +1/15 level areas. To this end in our L40-capped version the high-end items
   are +2, while endgame to the L50 cap will allow for +3 in L45+ areas.


   Spell penetration, magic resistance, and various resistance types: these are still on an opposed-percentage-based
   system, so need heavier values than most other perks to be equally relevant. Recommended scaling is in +10 increments
   at +10/15 levels; to this end +20 items should only be at L30+ areas, and +30 items only in the upper ends of the
   levelcap at L45+.


   ShieldMiss: this one should not scale in the same way as alternatives, specifically due to the fact that it is
   100-capped-percentage-system - no opposing stat will offset the benefit. Existing shields give 15-30% as a
   base figure (depending on size), and shieldMiss is additive & should thus only apply a small percentage at
   any level to remain reasonable. Recommended 10-20 only to apply here, as a tower shield with a 20 shieldMiss
   stat will instantly have the player blocking half of the attacks thrown at them regardless of level.


   Sight bonus: this one does not have critical scaling limits since it doesn't convey a direct combat boost.
   However to put it in perspective, +1-2 is a normal boost to a human & a reliable edge to an elf; +3-4 is a
   sizeable boost to allow most races to see in most conditions, and +5 tend to be rare/high-end items that
   give vision in nearly all circumstances.

 */

#include <std.h>
#include <daemons.h>
#include <valid_bonuses.h>

/**
 * @file
 */

inherit DAEMON;

void create()
{
    ::create();
}

varargs int valid_limb_check(object item, object tp)
{
    string* limbs, * base_limbs;
    string base_item, * inherits = ({});
    object base;
    int i;

    if (!objectp(item)) {
        return 0;
    }

    inherits = deep_inherit_list(item);
    limbs = item->query_limbs();

    // attempt to figure out the base item.  The first item in ee
    for (i = 0; sizeof(inherits), i < sizeof(inherits); i++) {
        if (strsrch(inherits[i], "/d/common/") != -1) {
            base_item = inherits[i];
            break;
        }
    }

    if (!base_item) {
        if (avatarp(tp)) {
            db(tp, base_name(item) + " does not seem to inherit from /d/common/  consider inheriting something "
               "from there or getting an inherit created to place into /d/common/ for the correct item type.\n");
            log_file("limbs", base_name(item) + " does not inherit from /d/common/ please add an item for "
                     "it to inherit or update to inherit correct item.\n\n");
        }
        return 0;
    }

    base = find_object_or_load(base_item);
    if (!objectp(base)) {
        return 0;
    }

    base_limbs = base->query_limbs();

    if (sizeof(base_limbs) != sizeof(limbs)) {
        if (avatarp(tp)) {
            db(tp, "Limbs of item are not the same as limbs of base item: \nbase item limbs: " + identify(base_limbs) + "item limbs: " + identify(limbs));
        }
        log_file("limbs", base_name(item) + " might have the wrong limbs set.\n\n");
        return 0;
    }

    for (i = 0; sizeof(base_limbs), i < sizeof(base_limbs); i++) {
        if (base_limbs[i] != limbs[i]) {
            if (avatarp(tp)) {
                db(tp, "Limbs of item are not the same as limbs of base item: \nbase item limbs: " + identify(base_limbs) + "item limbs: " + identify(limbs));
            }
            log_file("errors/limbs", base_name(item) + " might have the wrong limbs set.\n\n");
            return 0;
        }
    }

    return 1;
}

void old_bonuses(object item, object tp)
{
    string file, * lines = ({});
    int i, bad;

    if (!objectp(item)) {
        return;
    }

    file = base_name(item);
    if (!file_exists(file)) {
        file = file + ".c";
    }
    if (!file_exists(file)) {
        return;
    }
    lines = explode(read_file(file), "\n");

    // checks if the item sets things directly on the player,
    // sometimes these will be okay, but often they are bonues
    // getting set the old way, we should try to update them when possible
    for (i = 0; sizeof(lines), i < sizeof(lines); i++) {
        if (strsrch(lines[i], "TP->set") != -1) {
            log_file("errors/bonuses", file + " might have a bad bonus around line " + (i + 1) + "\n\n");
            db(tp, "The " + item->query_short() + " might have a bad bonus");
        }
        if (strsrch(lines[i], "ETO->set") != -1) {
            log_file("errors/bonuses", file + " might have a bad bonus around line " + (i + 1) + "\n\n");
            db(tp, "The " + item->query_short() + " might have a bad bonus");
        }
    }

    return;
}

// going to attempt to assign a level value to each bonus value
// and then we add the bonus values up to determine the sort of
// level that the item should be for

// should be able to call this function from player crafted items
// to ensure that they are okay to create
varargs int get_bonus_value(string bonus_name, string num, object item, object tp)
{
    string* other_valid_bonuses = ({ "empowered" });
    float value;

    if (!objectp(item)) {
        return 0;
    }

    other_valid_bonuses += VALID_BONUSES;

    if (member_array(bonus_name, other_valid_bonuses) == -1) {
        log_file("bonuses", base_name(item) + " has an invalid bonus: " + bonus_name + "\n\n");
        db(tp, base_name(item) + " has an invalid bonus: " + bonus_name);
    }

    // we'll likely need to fine tune these to be more precise
    // this should be close to the level needed for the item, but probably lower to leave
    // a little room for an additional bonus type in some instances
    // we'll probably want some wiggle room for big boss type monsters to have better stuff
    switch (bonus_name) {
    case "attack bonus":
    case "damage bonus":                    value = num * 8;        break;

    case "sight bonus":                     value = num * 8;            break;

    case "max hp bonus":                     value = num * 8;            break;

    case "magic resistance":                value = num * 12;            break;

    // stats
    case "strength":
    case "dexterity":
    case "constitution":
    case "intelligence":
    case "wisdom":
    case "charisma":                        value = num * 9;        break;


    // saving throws
    case "reflex":
    case "fortitude":
    case "will":                            value = num * 9;        break;


    // defense bonuses
    case "shieldMiss":                      value = num * 2;        break;

    case "armor bonus":                     value = num * 12;       break;


    // damage resistances
    case "untyped resistance":
    case "bludgeoning resistance":
    case "piercing resistance":
    case "slashing resistance":
    case "silver resistance":
    case "cold iron resistance":            value = num * 8;        break;

    case "damage resistance":               value = num * 8;        break;


    // spell resistances
    case "fire resistance":
    case "cold resistance":
    case "electricity resistance":
    case "acid resistance":
    case "sonic resistance":
    case "positive energy resistance":
    case "negative energy resistance":
    case "force resistance":
    case "divine resistance":
    case "mental resistance":               value = num * 1.5;            break;

    case "fire resistance percent":
    case "cold resistance percent":
    case "electricity resistance percent":
    case "acid resistance percent":
    case "sonic resistance percent":
    case "positive energy resistance percent":
    case "negative energy resistance percent":
    case "force resistance percent":
    case "divine resistance percent":
    case "mental resistance percent":               value = num * 15;            break;

    case "spell damage resistance":         value = num * 2;        break;


    // caster bonuses
    case "empowered":
    case "caster level":                    value = num * 15;       break;

    case "spell penetration":               value = num * 12;      break; //making symmetrical with magic resistance, this should put the max at 3 with klauth level gear giving 4


    // spell slots
    case "bonus_spell_slots_1":
    case "bonus_spell_slots_2":
    case "bonus_spell_slots_3":
    case "bonus_spell_slots_4":
    case "bonus_spell_slots_5":
    case "bonus_spell_slots_6":
    case "bonus_spell_slots_7":
    case "bonus_spell_slots_8":
    case "bonus_spell_slots_9":             value = num * 10;       break;

    case "bonus_spell_slots":               value = num * 15;       break;


    // skills
    case "academics":
    case "athletics":
    case "craft, armorsmith":
    case "craft, jeweller":
    case "craft, leatherwork":
    case "craft, tailor":
    case "craft, weaponsmith":
    case "craft, woodworker":
    case "disguise":
    case "dungeoneering":
    case "endurance":
    case "healing":
    case "influence":
    case "perception":
    case "rope use":
    case "stealth":
    case "spellcraft":
    case "survival":
    case "thievery":                        value = num * 8;        break;

    //Misc
    case "fast healing":                    value = num * 20;       break;
    }

    return abs(to_int(value));
}

string bonus_level(object item, object tp)
{
    mapping bonuses, level_info = ([]);
    string* bonus_names, info = "";
    int i, * values = ({}), flat_level, level, level_two, count;

    if (!objectp(item)) {
        return 0;
    }

    flat_level = item->query_property("enchantment") * 7;
    if ((item->query_property("magic") * 5) > flat_level) {
        flat_level = item->query_property("magic") * 5;
    }

    bonuses = item->query_item_bonuses();

    if (!sizeof(keys(bonuses))) {
        info += "The bonuses for this item are okay for level " + flat_level + " OR its bonuses are set incorrectly.  (Verify that it uses set_item_bonus for any bonuses)\n";
    }

    bonus_names = keys(bonuses);

    for (i = 0; i < sizeof(bonus_names); i++) {
        level = get_bonus_value(bonus_names[i], bonuses[bonus_names[i]], item, tp);

        if (level > flat_level) {
            log_file("bonuses", base_name(item) + " has a " + bonus_names[i] + " bonus that should require a level " + level + " item, but it seems to be a level " + flat_level + " item.\n\n");
            info += bonus_names[i] + " of " + bonuses[bonus_names[i]] + " should require level " + level + "\n";
        }

        level_info += ([ bonus_names[i] : level ]);
    }

    bonus_names = keys(level_info);

    // standard items, one bonus, usually at reduced rate - non boss items
    // solo boss items, one full rate bonus or multiple reduced rate bonuses
    // epic boss items, two full rate bonuses, or multiple reduced rate bonuses
    switch (sizeof(bonus_names)) {
    case 0: break;

    case 1:

        level = level_info[bonus_names[0]];
        if (level <= (flat_level * 0.8)) {
            info += bonus_names[0] + " is okay for a standard " + flat_level + " item\n";
        }else {
            info += bonus_names[0] + " consider reducing the bonus if it's a standard item, okay if it's difficult to aquire\n";
        }
        break;

    case 2:

        level = level_info[bonus_names[0]];
        level_two = level_info[bonus_names[1]];

        if (level_two > level) {
            i = level;
            level = level_two;
            level_two = i;
        }

        if (((level <= flat_level) && (level_two <= flat_level * 0.75)) || ((level <= (flat_level * 0.5)) && (level_two <= (flat_level * 0.5)))) {
            info += bonus_names[0] + " and " + bonus_names[1] + " are okay for a solo boss level " + flat_level + " item\n";
        }else {
            info += bonus_names[0] + " and/or " + bonus_names[1] + " should be reduced unless the item is very difficult to get.\n";
        }

        break;

    default:

        for (i = 0; i < sizeof(bonus_names); i++) {
            level = level_info[bonus_names[i]];
            if (level > (flat_level * 0.75)) {
                count++;
            }
        }

        switch (count) {
        case 0:
        case 1:
        case 2:

            info += "The bonuses are okay for a typical " + flat_level + " non-soloable boss monster\n";
            break;

        default:

            info += "This item should be incredibly difficult to get and only on top end creatures for " + flat_level + "\n";
            break;
        }
        break;
    }

    return info;
}

void db(object ob, string str)
{
    if (!objectp(ob)) {
        return;
    }
    tell_object(ob, str);
}

// return an int value representing the minimum level the item should be for
// tp is used so we have somebody to send messages to
varargs void item_check(object item, object tp)
{
    int flat_level;
    string bonus;

    if (!objectp(item)) {
        return;
    }

    db(tp, "%^RESET%^%^YELLOW%^Note: %^RESET%^%^YELLOW%^this command only tests item bonuses, not the frequency and effect of "
       "weapon/armor specials or other functions.\n\n%^RESET%^");

    db(tp, "Checking: " + item->query("short") + "\n");

    if (item->is_armor()) {
        valid_limb_check(item, tp);
    }
    item->old_bonuses(item, tp);
    bonus = bonus_level(item, tp);
    db(tp, bonus);
    return;
}

int validate(object ob)
{
    mapping bonuses;
    string* bonus_names, timestamp;
    int flat_level, bonus_value, num, allotted, expire, remaining, t;

    if (!objectp(ob)) {
        return 0;
    }
    if ((int)(environment(ob)->query("scaledlevel")) > 1) {
        return 0;
    }
    if (!ob->query_property("player enchanted")) {
        return 0;
    }
    if ((int)ob->query_property("enchantment") > 6) {
        while ((int)ob->query_property("enchantment") != 6) {
            ob->remove_property("enchantment");
            ob->set_property("enchantment", 6);
        }
    }

    flat_level = ob->query_property("enchantment") * 7;

    bonuses = copy(ob->query_item_bonuses());
    if (ob->query_property("hit") || ob->query_property("struck")) {
        bonuses += ([ "special" : flat_level ]);
    }
    bonus_names = keys(bonuses);

    if((ob->query_type() != "ring" || (member_array("left hand", ob->query_limbs()) == -1) && (member_array("right hand", ob->query_limbs()) == -1)) || ob->query_property("enchantment")) {
        for (int i = 0; i < sizeof(bonus_names); i++) {
            string bonus_name = bonus_names[i];
            num = bonuses[bonus_name];
            if (bonus_name != "special" &&
                bonus_name != "hit" &&
                bonus_name != "struck" &&
                bonus_name != "shieldMiss") {
                bonus_value = get_bonus_value(bonus_name, num, ob, TP);

                if (bonus_value > flat_level) {
                    while (bonus_value > flat_level) {
                        bonus_value = get_bonus_value(bonus_name, --num, ob, TP);
                    }
                    ob->set_item_bonus(bonus_name, num);
                }
            }
        }
    }

    if (sizeof(bonus_names) >= 3) {
        if (!ob->query_property("invalidate time")) {
            ob->set_property("invalidate time", time());
        }
        allotted = 60 * 60 * 8; //8 hours
        expire = (int)ob->query_property("invalidate time") + allotted;
        remaining = expire - time();

        if (remaining > 0) {
            t = remaining;
            timestamp = (t % 60) + "s";
            t /= 60;
            if (t % 60 > 0) {
                timestamp = t % 60 + "m " + timestamp;
            }
            t /= 60;
            if (t % 24 > 0) {
                timestamp = t % 24 + "h " + timestamp;
            }
            tell_object(TP, ob->query_short() + " has too many bonuses under current " +
                        "guidelines. See <help fixitem>.\n\n%^BOLD%^%^RED%^You have " + timestamp +
                        " remaining to fix the item before it becomes unusable. %^RESET%^"
                        );
        }else {
            tell_object(TP, ob->query_short() + " has too many bonuses under current " +
                        "guidelines and has not been fixed in the allotted time. See <help " +
                        "fixitem>.\n\n%^BOLD%^%^RED%^You will not be able to use this item " +
                        "until it has been adjusted.%^RESET%^"
                        );
            ob->unwear();
            ob->remove_property("wear_order");
            ob->move(TP);
        }
    }
    return 1;
}
