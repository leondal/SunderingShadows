// note: lib-based bonuses not in the template here:
// regen: /std/user.c in heart_beat()
// MR: /std/Object.c in query_property section
// on-use "shadowstep" command: /cmds/mortal/_shadowstep.c
#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 18, 300, 450, 600 }); }

int query_unbound_age()
{
    return 1;
}

int *restricted_alignments(string subrace) { return ({ 1, 2, 4, 5, 7, 8 }); }

string *restricted_classes(string subrace) { return ({ "druid", "ranger" }); }

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "jarmila","kreysneothosies","callamir","the faceless one","lysara","kismet","nimnavanon","varda" });
}

int *stat_mods(string subrace) { // stats in order: str, dex, con, int, wis, cha
    return ({ 0, 2, 0, 0, -2, 2 });
}

mapping skill_mods(string subrace) { return ([ "stealth" : 2, "academics":2]); }


int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) { return 3; }

mapping daily_uses(string subrace) { return ([ "shadow travel" : 1,]); }

mapping query_racial_innate(string subrace) {
	return ([
                    "shadow travel" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    "shadow stride" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    ]);
}

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 3, 3, 3, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 18, 18, 18 }); }
int *stat_adj()  { return ({ 0, 0, 0, 0, 0, 0 }); }

int is_restricted() { return 1; } // restricted races by approval

int is_rollable() { return 0; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "shade"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 9999; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 0, "wis" : 0, "dex" : 0, "cha" : 0 ]); }

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
    if(gender == "male") return 60;
    return 55;
}

int height_mod(string gender) {
    return 20;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 120;
    return 85;
}

int weight_mod(string gender) {
    return 8;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 8;

    switch(gender)
    {
    case "male":
        map["base"] = 150;
        switch(height)
        {
        case 60..65: map["adjust"] = -40; map["die"] = 15; break;
        case 66..74: map["adjust"] = -10; map["die"] = 10; break;
        case 75..80: map["adjust"] = 20;  map["die"] = 15; break;
        case 81..86: map["adjust"] = 30;  map["die"] = 25; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    default:
        map["base"] = 110;
        switch(height)
        {
        case 55..60: map["adjust"] = -10; map["die"] = 14; break;
        case 61..69: map["adjust"] = -5;  map["die"] = 10; break;
        case 70..75: map["adjust"] = 0;   map["die"] = 15; break;
        case 76..81: map["adjust"] = 15;  map["die"] = 15; break;
        default:     map["adjust"] = 0;   map["die"] = 10; break;
        }
    }

    return map;
}

string *query_hair_colors(string who) {
    string *choices = ({});
    choices += ({"ebony"});
    choices += ({"sable"});
    choices += ({"black", "brown", "gray"});
    return choices;
}

string *query_eye_colors(string who) {
    string *choices = ({});
    choices += ({"violet", "purple"});
    choices += ({"sable", "chocolate", "coffee"});
    choices += ({"black", "gray", "brown"});
    return choices;
}

int is_pk_race()
{
    return 1;
}

string *query_languages(string subrace)
{
    return (["required":({"common",}),"optional":({"abyssal","yuan-ti","infernal",})]);
}
