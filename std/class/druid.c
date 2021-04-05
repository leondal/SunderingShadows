#include <std.h>
#include <daemons.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/druids" }); } // temporary

int caster_class() { return 1; }


string *restricted_races() {
    return ({ "ogre","ogre-mage","goblin","bugbear","dwarf","gnoll","half-ogre","half-orc","halfling","hobgoblin","wemic","drow","goblin","kobold","orc" });
}

string *restricted_classes() { return ({ }); }

int *restricted_alignments() { return ({ 1,3,7,9 }); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([ "wisdom" : 14 ]);
}

int *saving_throws() { return ({ 1,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({
        "light armor proficiency",
        "simple weapon proficiency"
    });
}

// Time for a redo! Nienne, 9/15.
mapping class_featmap(string myspec)
{
    return ([
                1 : ({ "light armor proficiency", "medium armor proficiency", "simple weapon proficiency", "shield proficiency", "spell focus", "divine domain" }),
                3 : ({ "tracklessstep" }),
                4 : ({ "shapeshift" }),
                9 : ({ "venom immunity" }),
                11 : ({ "wild speech", "wild knowledge" }),
                15 : ({ "timeless body" }),
            ]);
}

mapping query_cantrip_spells(object ob)
{
    return ([ "create water" : 1, "detect magic" : 1, "detect poison" : 1, "guidance" : 1, "resistance" : 1, "light" : 1, "mending" : 1 ]);
}

string *class_skills()
{
// disguise temporarily disabled, please restore the first line when the command is installed. N, 1/14.
//    return ({ "healing","perception","disguise","survival" });
    return ({ "healing","perception","endurance","survival" });
}


int skill_points() { return 4; } // should be 4 as non-rogue, not sure why someone moved it to 5. N, 4/15.

string old_save_type() { return "cleric"; }

string new_save_type() { return "cleric"; }

void advanced_func(object player)
{
    player->set_guild_level("druid",(int)player->query_class_level("druid"));
    return;
}

int hit_dice() { return 8; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 3; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int bonus;
    float penalty, full_level, class_level;
    
    full_level = to_float(player->query_base_character_level());
    class_level = to_float(player->query_prestige_level("druid"));
    
    if(full_level < 20.00)
    {
        bonus = (to_int(class_level) * 3 / 4);
        return bonus;
    }
    
    // Above 20
    // 3/4 BAB gets half penalty to BAB
    // Weighted average of class level compared to total level
    penalty = (10.00 * (class_level / full_level)) / 2.00;
    bonus = to_int(class_level - penalty);
    
    return bonus;
}

int number_of_attacks(object player)
{
    object shape;
    string shape_race;
    int num;
    if(!objectp(player)) { return 0; }
    // same number of attacks as cleric
    num = "/daemon/bonus_d.c"->attack_bonus("cleric",player->query_class_level("druid"),player);
    num = num / 7;

    if(FEATS_D->usable_feat(player,"natural fighting"))
    {
        shape = player->query_property("shapeshifted");
        if(objectp(shape))
        {
            shape_race = shape->query_shape_race();
            switch(shape_race)
            {
                case "wolf":
                case "dragon":
                    num += 2;
                    break;
                case "cat":
                    num += 3;
                    break;
                case "bear":
                    num += 1;
                    break;
                default:
                    break;
            }
        }
    }

    return num;
}

string query_casting_stat(){
   return "wisdom";
}

mapping query_class_spells()
{
    return(([

    ]));
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "druid":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}

string *query_bonus_languages()
{
    return ({"sylvan", "elven", "auran", "aquan", "terran", "ignan"});
}
