// Bonuses in lib:
// shield/gold; +2 saves vs spells - see /std/magic/spell. +2 vs poisons, not implemented yet.
#include <std.h>
#include <objects.h>
inherit DAEMON;

void create()
{
    ::create();
}

// age at which each age cat starts: normal, middle, old, venerable
int* age_brackets()
{
    return ({ 40, 125, 167, 250 });
}

int* restricted_alignments(string subrace)
{
    if (!subrace || subrace == "") {
        return ({ 3, 6, 9 });
    }
    switch (subrace) {
    case "duergar":
    case "gray dwarf": return ({ 1, 4, 7 }); break;

    default: return ({ 3, 6, 9 }); break;
    }
}

string* restricted_classes(string subrace)
{
    if (!subrace || subrace == "") {
        return ({ "mage", "magus",  "ranger", "psion", "psywarrior", "paladin", "sorcerer", "druid", "warlock" });
    }
    switch (subrace) {
    case "duergar":
    case "gray dwarf": return ({ "mage", "magus",  "bard", "ranger", "paladin", "sorcerer", "druid", "warlock" }); break;

    case "gold dwarf": return ({ "mage", "magus",  "ranger", "psion", "psywarrior", "sorcerer", "druid", "warlock" }); break;

    default: return ({ "mage", "magus",  "ranger", "psion", "psywarrior", "paladin", "sorcerer", "druid", "warlock" }); break;
    }
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string* restricted_deities(string subrace)
{
    if (!subrace || subrace == "") {
        return ({ "shar", "mask", "bane", "beshaba", "cyric", "auril", "talos" });
    }
    switch (subrace) {
    case "duergar":
    case "gray dwarf": return ({ "anhur", "helm", "lathander", "mielikki", "oghma", "selune", "sune", "torm", "tymora", "tyr" }); break;

    case "shield dwarf": return ({ "shar", "mask", "bane", "beshaba", "cyric", "talos" }); break;

    default: return ({ "shar", "mask", "bane", "beshaba", "cyric", "auril", "talos" }); break;
    }
}

int* stat_mods(string subrace)   // stats in order: str, dex, con, int, wis, cha
{
    if (!subrace || subrace == "") {
        return ({ 0, 0, 2, 2, 0, -2 });
    }
    switch (subrace) {
    case "gold dwarf": return ({ 0, -2, 2, 0, 2, 0 }); break;

    case "duergar":
    case "gray dwarf": return ({ 0, 0, 2, 0, 2, -2 }); break;

    default: return ({ 0, 0, 2, 0, 2, -2 }); break;   //shield dwarf is default
    }
}

mapping skill_mods(string subrace)
{
    if (!subrace || subrace == "") {
        return (["perception" : 2]);
    }
    switch (subrace) {
    case "duergar":
    case "gray dwarf": return ([ "stealth" : 2, "perception" : 2 ]); break;

    default: return (["perception" : 2]); break;   //gold and shield dwarves get 2 perception
    }
}

int natural_AC(string subrace)
{
    return 0;
}

int sight_bonus(string subrace)
{
    if (!subrace || subrace == "") {
        return 2;
    }
    switch (subrace) {
    case "duergar":
    case "gray dwarf": return -2; break;                   // copying darkvis races; uncertain if accurate

    default: return 2; break;
    }
}

mapping daily_uses(string subrace)
{
    if (!subrace || subrace == "") {
        return ([]);
    }
    switch (subrace) {
//      case "duergar": case "gray dwarf": return ([ "invisibility" : 1, "enlarge" : 1 ]); break; //when enlarge is done.
    case "duergar":
    case "gray dwarf": return ([ "invisibility" : 1 ]); break;

    default: return ([]); break;
    }
}

int misc_bonuses(string subrace, string bonus)
{
    return 0;
}

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int* min_stats()
{
    return ({ 8, 3, 12, 3, 3, 3 });
}

int* max_stats()
{
    return ({ 18, 17, 19, 18, 18, 16 });
}

int* stat_adj()
{
    return ({ 0, 0, 1, 0, 0, -1 });
}

int is_restricted()
{
    return 0;
}                                 // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name()
{
    return "dwarf";
}

// gets used in a forumla based on con to determine actual weight
int weight()
{
    return 6000;
}

int fingers()
{
    return 4;
}

string* wielding_limbs()
{
    return ({ "right hand", "left hand" });
}

mapping monster_stat_rolls()
{
    return ([ "str" : 2, "con" : 4, "int" : -1, "wis" : 4, "dex" : 3, "cha" : -4 ]);
}

mixed query_racial_innate(string subrace)
{
    if (!subrace || subrace == "") {
        return 0;
    }
    switch (subrace) {
    case "gray dwarf":
    case "duergar":
        return (["invisibility" : (["type" : "spell", "casting level" : 0.5,
                                    "daily uses" : 1, "delay" : 1, "uses left" : 1,
                                    "refresh time" : -1, "level required" : 0,
                                    "class specific" : 0])]);

        break;

    default:
        return 0;

        break;
    }
}

int size()
{
    return 2;
}

string* limbs()
{
    return ({ "head",
              "right arm",
              "right hand",
              "left arm",
              "left hand",
              "left leg",
              "left foot",
              "right leg",
              "right foot",
              "waist",
              "neck" });
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender)
{
    if (gender == "male") {
        return 42;
    }
    return 40;
}

int height_mod(string gender)
{
    return 10;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender)
{
    if (gender == "male") {
        return 130;
    }
    return 100;
}

int weight_mod(string gender)
{
    return 12;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map = ([]);

    map["num"] = 4;

    switch (gender) {
    case "male":
        map["base"] = 130;
        switch (height) {
        case 43..45: map["adjust"] = -20; map["die"] = 15; break;

        case 46..50: map["adjust"] = 0;   map["die"] = 10; break;

        case 51..53: map["adjust"] = 0;   map["die"] = 15; break;

        case 54..56: map["adjust"] = 20;  map["die"] = 20; break;

        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }

    default:
        map["base"] = 105;
        switch (height) {
        case 41..43: map["adjust"] = -20; map["die"] = 15; break;

        case 44..48: map["adjust"] = 0;   map["die"] = 10; break;

        case 49..51: map["adjust"] = 0;   map["die"] = 15; break;

        case 52..54: map["adjust"] = 15;  map["die"] = 20; break;

        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string* query_hair_colors(string subrace)
{
    string* choices = ({});
    if (!stringp(subrace) || subrace == "shield dwarf") {
        choices += ({ "golden" });
        choices += ({ "scarlet", "crimson", "blonde" });
        choices += ({ "brown", "red", "gray", "white" });
    }else if (subrace == "gold dwarf") {
        choices += ({ "ebony" });
        choices += ({ "sable" });
        choices += ({ "black", "brown" });
    }
    if (subrace == "gray dwarf") {
        return ({ "bald" });
    }
    return choices;
}

varargs string* query_eye_colors(string subrace)
{
    string* choices = ({});
    if (!stringp(subrace) || subrace == "shield dwarf") {
        choices += ({ "silver", "emerald", "sapphire" });
        choices += ({ "azure" });
        choices += ({ "blue", "green" });
    }
    if (subrace == "gold dwarf") {
        choices += ({ "sable", "chocolate", "coffee" });
        choices += ({ "hazel" });
        choices += ({ "brown" });
    }
    if (subrace == "gray dwarf") {
        return ({ "black" });
    }
    return choices;
}

string* query_subraces(object who)
{
    string* subraces;
    subraces = ({ "shield dwarf", "gold dwarf" });
    if (OB_ACCOUNT->is_experienced(who->query_true_name()) || OB_ACCOUNT->is_high_mortal(who->query_true_name()) || avatarp(who) || who->query("is_valid_npc")) {
        subraces += ({ "gray dwarf" });
    }
    return subraces;
}

int is_pk_race(string subrace)
{
    if (!subrace || subrace == "") {
        return 0;
    }
    if (subrace == "duergar" ||
        subrace == "gray dwarf") {
        return 1;
    }
}

string* query_languages(string subrace)
{
    switch (subrace) {
    case "duergar":
    case "grey dwarf":
        return (["required" : ({ "dwarvish", "undercommon" }), "optional" : ({ "giant", "gnomish", "goblin", "orcish", "terran", "common" })]);

        break;

    default:
        return (["required" : ({ "dwarvish", "common" }), "optional" : ({ "giant", "gnomish", "goblin", "orcish", "terran", "undercommon" })]);

        break;
    }
}
