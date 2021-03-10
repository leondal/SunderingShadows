#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({  }); } // temporary

int caster_class() { return 1; }

string *restricted_races() {
    return ({ "bugbear","dwarf","gnome","goblin","half-orc","halfling","hobgoblin","kobold","orc", "firbolg","gnoll","half-ogre","ogre","ogre-mage" });
}

string *restricted_classes() { return ({}); }

int *restricted_alignments() { return ({}); }

// removing deity restrictions from ranger & druid. N, 3/17.
/*string *restricted_gods() { return ({
"auppenser","bane","beshaba","cyric","helm","mask","mystra","oghma","sune","torm
","tymora" });
}*/
string *restricted_gods() { return ({}); }

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 1,1,0 }); }

mapping stat_requirements()
{
    return ([ "dexterity" : 12, "wisdom" : 12 ]);
}

string *combat_styles() {
    return ({ "dual wield", "archery", "twohanded"});
}

string *class_feats(string myspec) {
    return ({ "ambidexterity",
              "light armor proficiency",
              "simple weapon proficiency",
              "martial weapon proficiency",
              "track",
              "evasion"});
}

mapping class_featmap(string myspec)   // "dual wield" is default setting
{
    if (!myspec || myspec == "") {
        return ([ 1 : ({ "favored enemy", "ambidexterity", "light armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "track" }), 3 : ({ "rangers endurance", "favored terrain" }), 4 : ({ "animal companion" }), 5 : ({ "whirl" }), 7 : ({ "hunters bond" }), 9 : ({ "two weapon fighting", "evasion" }), 10 : ({ "quarry" }), 11 : ({ "second favored enemy" }), 13 : ({ "improved two weapon fighting", "second favored terrain" }), 17 : ({ "unassailable parry", "third favored enemy" }), 18 : ({ "improved quarry" }), 19 : ({ "third favored terrain" }), 21 : ({ "seen it before" }), ]);
    }

    switch (myspec) {
    case "archery":
        return ([ 1 : ({ "favored enemy", "point blank shot", "light armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "track" }), 3 : ({ "rangers endurance", "favored terrain" }), 4 : ({ "animal companion" }), 5 : ({ "manyshot" }), 7 : ({ "hunters bond" }), 9 : ({ "deadeye", "evasion" }), 10 : ({ "quarry" }), 11 : ({ "second favored enemy" }), 13 : ({ "preciseshot", "second favored terrain" }), 17 : ({ "shot on the run", "third favored enemy" }), 18 : ({ "improved quarry" }), 19 : ({ "third favored terrain" }), 21 : ({ "seen it before" }), ]);
        break;
    case "twohanded":
        return ([ 1 : ({ "favored enemy", "sweepingblow", "light armor proficiency","shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "track" }), 3 : ({ "rangers endurance", "favored terrain" }), 4 : ({ "animal companion" }), 5 : ({ "blade block" }), 7 : ({ "hunters bond" }), 9 : ({ "impale", "evasion" }), 10 : ({ "quarry" }), 11 : ({ "second favored enemy" }), 13 : ({ "light weapon", "second favored terrain" }), 17 : ({ "strength of arm", "third favored enemy" }), 18 : ({ "improved quarry" }), 19 : ({ "third favored terrain" }), 21 : ({ "seen it before" }), ]);
        break;
    case "mounted":
        return ([ 1 : ({ "favored enemy", "mounted combat", "light armor proficiency","shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "track" }), 3 : ({ "rangers endurance", "favored terrain" }), 4 : ({ "animal companion" }), 5 : ({ "ride-by attack" }), 7 : ({ "hunters bond" }), 9 : ({ "charge", "evasion" }), 10 : ({ "quarry" }), 11 : ({ "second favored enemy" }), 13 : ({ "trample", "second favored terrain" }), 17 : ({ "third favored enemy" }), 18 : ({ "improved quarry" }), 19 : ({ "third favored terrain" }), 21 : ({ "seen it before" }), ]);
        break;
    default:
        return ([ 1 : ({ "favored enemy", "ambidexterity", "light armor proficiency","shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "track" }), 3 : ({ "rangers endurance", "favored terrain" }), 4 : ({ "animal companion" }), 5 : ({ "whirl" }), 7 : ({ "hunters bond" }), 9 : ({ "two weapon fighting", "evasion" }), 10 : ({ "quarry" }), 11 : ({ "second favored enemy" }), 13 : ({ "improved two weapon fighting", "second favored terrain" }), 17 : ({ "unassailable parry", "third favored enemy" }), 18 : ({ "improved quarry" }), 19 : ({ "third favored terrain" }), 21 : ({ "seen it before" }), ]);
        break;
    }
}

string *class_skills()
{
    return ({ "athletics","endurance","stealth","survival" });
}

int skill_points() { return 4; }

string old_save_type() { return "ranger"; }

string new_save_type() { return "ranger"; }

void advanced_func(object player)
{
    player->set_guild_level("ranger",(int)player->query_class_level("ranger"));
}

int hit_dice() { return 10; }  // down to cleric equiv. with the new ranger spells in!
                              // back up to d10 as per d20PFSRD

int default_hitpoints() { return 3; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int level;
    level = (int)player->query_prestige_level("ranger");
    return level;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("ranger",player->query_class_level("ranger"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "wisdom";
}

mapping query_class_spells()
{
    return(([ ]));
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "ranger":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
