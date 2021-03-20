// Bonuses in lib:
// lightfoot halfling: +1 luck to all saves, see /daemon/saving_throw_d
#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 20, 50, 67, 100 }); }

int *restricted_alignments(string subrace) { return ({ 3, 6, 9 }); }

string *restricted_classes(string subrace) {
    if(!subrace || subrace == "") return ({ "mage", "magus",  "ranger", "psion", "psywarrior",  "paladin", "monk", "warlock", "druid","inquisitor" });
    switch(subrace) {
    case "ghostwise halfling": return ({ "mage", "magus",  "bard", "sorcerer", "monk", "warlock", }); break;
      case "strongheart halfling": return ({ "mage", "magus",  "ranger", "psion", "psywarrior", "sorcerer", "monk", "warlock", "druid" }); break;
    default: return ({ "mage", "magus",  "ranger", "psion", "psywarrior",  "paladin", "monk", "warlock", "druid", "inquisitor" }); break;
    }
}

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    if(!subrace || subrace == "") return ({ "shar","mask","bane","beshaba","cyric","auril","talos" });
    switch(subrace) {
      case "ghostwise halfling": return ({ "shar","bane","beshaba","cyric","auril","talos","helm" }); break;
      default: return ({ "shar","mask","bane","beshaba","cyric","auril","talos" }); break;
    }
}

int *stat_mods(string subrace) { // stats in order: str, dex, con, int, wis, cha
    if(!subrace || subrace == "") return ({ -2, 2, 0, 0, 0, 2 });
    switch(subrace) {
      case "strongheart halfling": return ({ -2, 0, 2, 0, 0, 2 }); break;
      default: return ({ -2, 2, 0, 0, 0, 2 }); break;
    }
}

mapping skill_mods(string subrace) {
    if(!subrace || subrace == "") return ([ "stealth" : 2, "athletics" : 2 ]);
    switch(subrace) {
      case "strongheart halfling": return ([ "stealth" : 2, "survival" : 2 ]); break;
      case "ghostwise halfling": return ([ "stealth" : 2 ]); break;
      default: return ([ "stealth" : 2, "athletics" : 2 ]); break; // lightfoot halfling default
    }
}


int natural_AC(string subrace) { return 0; }

int sight_bonus(string subrace) { return 2; }

mapping daily_uses(string subrace) {
    if(!subrace || subrace == "") return ([]);
    switch(subrace) {
      case "ghostwise halfling": return ([ "telepathic bond" : 1, "ghost step" : 1 ]); break;
      default: return ([]); break;
    }
}

int misc_bonuses(string subrace, string bonus) { return 0; }

// ---------------------------------------------------------------------------------------------------
// Below: mods prior to racial overhaul; some may still be in use in some places. -N, 10/10.

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 6, 8, 9, 6, 3, 3 }); }
int *max_stats() { return ({ 17, 19, 18, 18, 17, 18 }); }
int *stat_adj() { return ({ -1, 1, 0, 0, 0, 0 }); }

int is_restricted() { return 0; } // restricted races by approval

int is_rollable() { return 1; } // rollable in creation

// Stuff needed to replace what was in the old race database

string race_name() { return "halfling"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 7000; }

mixed query_racial_innate(string subrace)
{
	if(!subrace || subrace == "") return 0;
	switch(subrace)
	{
		case "ghostwise halfling" :
			return (["telepathic bond" : (["type" : "spell", "casting level" : 0.5,
				   "daily uses" : 1, "delay" : 1, "uses left" : 1,
				   "refresh time" : -1, "level required" : 0,
			         "class specific" : 0]),
	                     "ghost step" : (["type" : "spell", "casting level" : 0.5,
				   "daily uses" : 1, "delay" : 1, "uses left" : 1,
				   "refresh time" : -1, "level required" : 0,
				   "class specific" : 0]),]);
			break;
			return 0;
		default:
			break;
			return 0;
	}
	return 0;
}

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : -2, "con" : -3, "int" : -1, "wis" : 0, "dex" : 9, "cha" : -4 ]); }

int size() { return 1; }

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
    if(gender == "male") return 28;
    return 26;
}

int height_mod(string gender) {
    return 8;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    if(gender == "male") return 30;
    return 25;
}

int weight_mod(string gender) {
    return 1;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map=([]);

    map["num"]  = 5;

    switch(gender)
    {
    case "male":
        map["base"] = 52;
        switch(height)
        {
        case 32..36: map["adjust"] = -10; map["die"] = 6; break;
        case 37..43: map["adjust"] = 0;   map["die"] = 4; break;
        case 44..48: map["adjust"] = 0;   map["die"] = 6; break;
        case 49..52: map["adjust"] = 5;   map["die"] = 6; break;
        default:     map["adjust"] = 0;   map["die"] = 4; break;
        }
    default:
        map["base"] = 48;
        switch(height)
        {
        case 30..34: map["adjust"] = -10; map["die"] = 6; break;
        case 35..41: map["adjust"] = 0;   map["die"] = 4; break;
        case 42..46: map["adjust"] = 0;   map["die"] = 6; break;
        case 47..50: map["adjust"] = 5;   map["die"] = 6; break;
        default:     map["adjust"] = 0;   map["die"] = 4; break;
        }
    }

    return map;
}

string *query_hair_colors(string subrace) {
    string *choices = ({});
    if(!stringp(subrace) || subrace == "lightfoot halfling") {
        choices += ({"ebony", "golden"});
        choices += ({"sable", "auburn", "scarlet", "crimson"});
        choices += ({"black", "brown", "blonde", "red"});
    }
    else if(subrace == "ghostwise halfling" || subrace == "strongheart halfling") {
        choices += ({"ebony"});
        choices += ({"sable"});
        choices += ({"black", "brown"});
    }
    return choices;
}

string *query_eye_colors(string subrace) {
    string *choices = ({});
    if(!stringp(subrace) || subrace == "lightfoot halfling") {
        choices += ({"emerald", "sapphire"});
        choices += ({"azure", "sable", "chocolate", "coffee"});
        choices += ({"blue", "green", "brown", "hazel"});
    }
    if(subrace == "ghostwise halfling" || subrace == "strongheart halfling") {
        choices += ({"sable", "chocolate", "coffee"});
        choices += ({"brown"});
        choices += ({"black"});
    }
    return choices;
}

string *query_subraces(object who) {
    return ({"lightfoot halfling", "strongheart halfling", "ghostwise halfling"});
}

string *query_languages(string subrace)
{
    return (["required":({"halfling","common"}),"optional":({"elven","gnomish","dwarvish","goblin"})]);
}
