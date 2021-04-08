// Bonuses in lib: +2 vs charm spells and sleep immunity, see /std/magic/spell
// character level +10 MR, /std/Object.c
//unrestricting ranger based on talk with Nienne ~Circe~ 4/27/11
//Changes made to integrate a new subrace - Ssri Tel Quessir - based
//on a plot run by Loki 11/1/11
// Ssri Tel Quessir now removed by plot, major elven rite. N, 1/14.
#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 102, 175, 233, 350 }); }

int *restricted_alignments(string subrace) {
    return ({ 1, 2, 4, 5, 7, 8 });
}

string *restricted_classes(string subrace) {
  return ({ "psion", "psywarrior", "monk", "druid" });
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "anhur","helm","lathander","mielikki","oghma","sune","torm","tymora","tyr" });
}

// stats in order: str, dex, con, int, wis, cha
int *stat_mods(string subrace) { return ({ 0, 2, -2, 2, 0, 0 }); }

mapping skill_mods(string subrace) { return ([ "perception" : 2 ]); }

int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) {
    return -2;
}

mapping daily_uses(string subrace) {
    return ([ "faerie fire" : 1, "darkness" : 1 ]);
}

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 8, 12, 4, 10, 8, 8 }); }
int *max_stats() { return ({ 18, 20, 16, 19, 18, 16 }); }
int *stat_adj() { return ({ 0, 2, -1, 1, 0, -2 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "drow"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 8000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping query_racial_innate(string subrace){
        return (["darkness" : (["type" : "spell", "casting level" : 0.5,
				   "daily uses" : 1, "delay" : 1, "uses left" : 1,
				   "refresh time" : -1, "level required" : 0,
				   "class specific" : 0]),
		   "faerie fire" : (["type" : "spell", "casting level" : 0.5,
				   "daily uses" : 1, "delay" : 1, "uses left" : 1,
				   "refresh time" : -1, "level required" : 0,
				   "class specific" : 0]), ]);
}

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 5, "wis" : 8, "dex" : 3, "cha" : 1 ]); }

int size() { return 2; }

string *limbs() {
    return ({  "head",
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
int height_base(string gender) {
    if(gender == "male") return 53;
    return 55;
}

int height_mod(string gender) {
    return 12;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 80;
    return 85;
}

int weight_mod(string gender) {
    return 6;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 3;

    switch(gender)
    {
    case "male":
        map["base"] = 70;
        switch(height)
        {
        case 50..52: map["adjust"] = -15; map["die"] = 15; break;
        case 53..57: map["adjust"] = 0;   map["die"] = 10; break;
        case 58..60: map["adjust"] = 0;   map["die"] = 15; break;
        case 61..63: map["adjust"] = 5;   map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 90;
        switch(height)
        {
        case 55..60: map["adjust"] = -15; map["die"] = 15; break;
        case 61..69: map["adjust"] = 0;   map["die"] = 10; break;
        case 70..75: map["adjust"] = 0;   map["die"] = 15; break;
        case 76..81: map["adjust"] = 15;  map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    choices += ({"platinum"});
    choices += ({"silver"});
    choices += ({"white"});
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    choices += ({"blue"});
    choices += ({"violet", "purple"});
    choices += ({"brown", "yellow", "amber"});
    choices += ({"black", "red"});
    return choices;
}

int is_pk_race()
{
    return 1;
}

string *query_languages(string subrace)
{
    return (["required":({"drow","undercommon"}),"optional":({"elven", "common", "draconic", "beast", "gnomish", "goblin", "orcish",})]);
}
