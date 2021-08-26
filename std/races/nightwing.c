// note: lib-based bonuses not in the template here:
// regen: /std/user.c in heart_beat()
// MR: /std/Object.c in query_property section


// Light aversion
// This race will get -4 saves, skills in anything above 0 light level.
// gains +8 to stealth in light -1 or below.
// Race should be paired with undead template for all of the undead traits

#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 18, 300, 450, 600 }); }

int query_unbound_age()
{
    return 1;
}

int unarmed_enchantment(object player)
{
    return player->query_base_character_level() / 6;
}

int *restricted_alignments(string subrace) { return ({ 9 }); }

string *restricted_classes(string subrace) { return ({ "cleric", "ranger", "paladin", "inquisitor", "druid" }); }

// this only affects rolling in creation; does not prevent dedication to a deity in-game, to allow for character evolution. N, 3/16.
string *restricted_deities(string subrace) {
    return ({ "jarmila","kreysneothosies","callamir","lysara","nimnavanon", });
}

int *stat_mods(string subrace) { // stats in order: str, dex, con, int, wis, cha
    return ({ 2, 4, 0, 0, -2, -2 });
}

mapping skill_mods(string subrace, object ob) { 

    if(total_light(environment(ob)) < 0)
        return ([ "stealth" : 8, "academics": -2, "perception" : 2]);
        
    return ([ "stealth" : -4, "academics": -4, "perception" : -4]);
}


int natural_AC(string subrace) { return 10; }

int sight_bonus(string subrace) { return -5; }

mapping daily_uses(string subrace) { return ([ "shadow travel" : 1,]); }

mapping query_racial_innate(string subrace) {
	return ([
                    "deeper darkness" : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    "command undead"  : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    "fear"            : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    "alter self"      : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    "detect magic"    : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
                    "invisibility"    : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),                    
                    "shadow travel"   : (["type" : "spell", "daily uses" : -1,"level required" : 0,]),
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

string race_name() { return "nightwing"; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 100000; }

int fingers() { return 3; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 0, "wis" : 0, "dex" : 0, "cha" : 0 ]); }

int size() { return 3; }

string *limbs()
{
    return ({   "head",
                "right foreleg",
                "right foreclaw",
                "left foreleg",
                "left foreclaw",
                "right rear leg",
                "right rear claw",
                "left rear leg",
                "left rear claw",
                "right wing",
                "left wing",
                "tail",  });
}

// minimum height for the race = base, max height for the race = base + mod
int height_base(string gender) {
    return 180;
}

int height_mod(string gender) {
    return 20;
}

// minimum weight for the race = base, max weight for the race = base + (modifier x height mod)
// height mod = player height minus base height.
int weight_base(string gender) {
    return 4000;
}

int weight_mod(string gender) {
    return 8;
}

// used by /daemon/player_d
mapping weight_values(string gender, int height)
{
    mapping map = ([]);

    map["num"] = 17;
    
    map["base"] = 4000;
    switch (height) {
        case 110..120: map["adjust"] = -100; map["die"] = 12; break;
        case 121..140: map["adjust"] = 0;   map["die"] = 12; break;
        case 141..180: map["adjust"] = 0;   map["die"] = 12; break;
        case 181..200: map["adjust"] = 100;  map["die"] = 12; break;
        default:       map["adjust"] = 0;   map["die"] = 12; break;
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
    choices += ({"red", "silver" });
    return choices;
}

int is_pk_race()
{
    return 1;
}

string *query_languages(string subrace)
{
    return (["required":({"common",}),"optional":({"undercommon","abyssal",})]);
}

int unarmed_damage_bonus(object me, object you)
{
    int level = me->query_character_level();
    
    return roll_dice(1 + level / 10, 6);
}
