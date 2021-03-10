#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 3, 3, 3, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 18, 18, 18 }); }
int *stat_adj()  { return ({ 0, 0, 0, 0, 0, 0 }); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 17, 45, 60, 90 }); }

int *restricted_alignments() { return ({}); }

string *restricted_classes() { return ({}); }

int is_restricted() { return 1; } // restricted races by approval



// Stuff needed to replace what was in the old race database

string race_name() { return "elven-dragon"; }

int sight_bonus() { return 4; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 100000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 5, "con" : 5, "int" : 5, "wis" : 5, "dex" : 5, "cha" : 5 ]); }

int size() { return 3; }

int natural_AC() { return 4; }


string *limbs()
{
    return ({   "head",
                "right forearm",
                "right hand",
                "left forearm",
                "left hand",
                "right rear leg",
                "right rear claw",
                "left rear leg",
                "left rear claw",
                "right wing",
                "left wing",
                "tail",  });

}