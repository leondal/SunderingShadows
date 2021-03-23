#include <std.h>
inherit DAEMON;

void create()
{
    ::create();
}

int* age_brackets()
{
    return ({ 12, 22, 80, 120 });
}

int* restricted_alignments(string subrace)
{
    return ({ 1, 3, 7, 9 });
}

string* restricted_classes(string subrace)
{
    return ({ "warlock", "psion", "psywarrior", });
}

string* restricted_deities(string subrace)
{
    return ({ });
}

// stats in order: str, dex, con, int, wis, cha
int* stat_mods(string subrace)
{
    return ({ 0, 2, 2, -2, 0, 0 });
}

mapping skill_mods(string subrace)
{
    return ([ "athletics" : 2 ]);
}

int natural_AC(string subrace)
{
    return 0;
}

int sight_bonus(string subrace)
{
    return 4;
}

mapping daily_uses(string subrace)
{
    return ([]);
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
    return ({ 4, 4, 4, 4, 4, 4 });
}

int* max_stats()
{
    return ({ 18, 18, 18, 18, 18, 18 });
}

int* stat_adj()
{
    return ({ 0, 0, 0, 0, 0, 0 });
}

int is_restricted()
{
    return 0;
}                                 // restricted races by approval

int is_rollable() { return 0; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name()
{
    return "squole";
}

// gets used in a forumla based on con to determine actual weight
int weight()
{
    return 8000;
}

int fingers()
{
    return 5;
}

string* wielding_limbs()
{
    return ({ "right hand", "left hand" });
}

mapping monster_stat_rolls()
{
    return ([ "str" : -1, "con" : -1, "int" : 0, "wis" : 0, "dex" : 0, "cha" : 0 ]);
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
              "neck",
              "tail" });
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender)
{
    return 60;
}

int height_mod(string gender)
{
    return 5;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender)
{
    return 90;
}

int weight_mod(string gender)
{
    return 20;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map = ([]);

    map["num"] = 3;

    switch (gender) {
    case "male":
        map["base"] = 90;
        switch (height) {
        case 55..57: map["adjust"] = -10; map["die"] = 15; break;

        case 58..62: map["adjust"] = 0;   map["die"] = 10; break;

        case 63..65: map["adjust"] = 0;   map["die"] = 15; break;

        case 66..68: map["adjust"] = 15;  map["die"] = 15; break;

        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }

    default:
        map["base"] = 70;
        switch (height) {
        case 50..52: map["adjust"] = -15; map["die"] = 15; break;

        case 53..57: map["adjust"] = 0;   map["die"] = 10; break;

        case 58..60: map["adjust"] = 0;   map["die"] = 15; break;

        case 61..63: map["adjust"] = 5;   map["die"] = 15; break;

        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string* query_eye_colors(string subrace)
{
    return ({ "green", "blue", "red" });
}

string* query_hair_colors(string subrace)
{
    return ({ "green", "blue", "red" });
}

string* query_subraces(object who)
{
    return ({ "ice", "magma", "ooze" });
}

string* query_languages(string subrace)
{
    return (["required" : ({ "common", }), "optional" : ({ "elven", "aquan", "infernal", "dwarven", })]);
}
