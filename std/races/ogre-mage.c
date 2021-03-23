#include <std.h>
inherit DAEMON;

void create()
{
    ::create();
}

// age at which each age cat starts: normal, middle, old, venerable
int* age_brackets()
{
    return ({ 20, 82, 116, 175 });
}

int* restricted_alignments(string subrace)
{
    return ({ 1, 4, 5, 7, 8, 9 });
}

string* restricted_classes(string subrace)
{
    return ({ "cleric", "bard", "ranger", "psion", "psywarrior", "paladin", "monk", "inquisitor", "oracle"});
}

// stats in order: str, dex, con, int, wis, cha
int* stat_mods(string subrace)
{
    return ({ 0, 0, 2, 0, 2, -2 });
}

mapping skill_mods(string subrace)
{
    return ([ "endurance" : 2 ]);
}

int natural_AC(string subrace)
{
    return 2;
}

int sight_bonus(string subrace)
{
    return -2;
}

mapping daily_uses(string subrace)   // needs charm person if possible down the track
{
    return ([ "levitate" : 1]);
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
    return ({ 12, 7, 8, 8, 3, 2 });
}

int* max_stats()
{
    return ({ 19, 18, 14, 17, 16, 14 });
}

int* stat_adj()
{
    return ({ 1, 0, 0, 0, -2, 0 });
}

int is_restricted()
{
    return 1;
}                                 // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name()
{
    return "ogre-mage";
}

// gets used in a forumla based on con to determine actual weight
int weight()
{
    return 13000;
}

int fingers()
{
    return 5;
}

mapping query_racial_innate(string subrace)
{
    return ([
                "levitate"      : (["type" : "spell", "casting level" : 0.5,
                                    "daily uses" : 1, "delay" : 1, "uses left" : 1,
                                    "refresh time" : -1, "level required" : 0,
                                    "class specific" : 0])]);
}

string* wielding_limbs()
{
    return ({ "right hand", "left hand" });
}

mapping monster_stat_rolls()
{
    return ([ "str" : 1, "con" : 1, "int" : -1, "wis" : 0, "dex" : 0, "cha" : -1 ]);
}

int size()
{
    return 3;
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
        return 102;
    }
    return 96;
}

int height_mod(string gender)
{
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender)
{
    if (gender == "male") {
        return 620;
    }
    return 600;
}

int weight_mod(string gender)
{
    return 8;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map = ([]);

    map["num"] = 4;

    switch (gender) {
    case "male":
        map["base"] = 810;
        switch (height) {
        case 114..116: map["adjust"] = -20; map["die"] = 15; break;
        case 117..123: map["adjust"] = 0;   map["die"] = 10; break;
        case 124..126: map["adjust"] = 0;   map["die"] = 15; break;
        case 127..129: map["adjust"] = 15;  map["die"] = 17; break;
        default:       map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 780;
        switch (height) {
        case 96..98:   map["adjust"] = -20; map["die"] = 15; break;
        case 99..105:  map["adjust"] = 0;   map["die"] = 10; break;
        case 106..108: map["adjust"] = 0;   map["die"] = 15; break;
        case 109..111: map["adjust"] = 10;  map["die"] = 17; break;
        default:       map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string* query_hair_colors(string who)
{
    string* choices = ({});
    choices += ({ "ebony" });
    choices += ({ "blonde" });
    choices += ({ "black", "blue-black", "dark green", "yellow", "white", "silver"});
    return choices;
}

string* query_eye_colors(string who)
{
    return ({ "dark brown", "black" });
}

string *query_subraces(object who) {
    return ({"fire", "water", "kuwa", "void"});
}

string* query_languages(string subrace)
{
    return (["required" : ({ "common", "giant", }), "optional" : ({ "undercommon", "orcish", "gnomish", "dwarvish", })]);
}
