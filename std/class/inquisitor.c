
#include <std.h>
inherit DAEMON;

int is_prestige_class() { return 0; }

void create() { ::create(); }

string *search_paths() { return ({  }); }

int caster_class() { return 1; }

string *restricted_races() {
    return ({  });
}

string *restricted_classes() { return ({ }); }

int *restricted_alignments() { return ({ }); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([ "wisdom" : 14, ]);
}

int *saving_throws() { return ({ 1,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({ "simple weapon proficiency",
                "exotic weapon proficiency",
                "light armor proficiency",
                "medium armor proficiency",
                "spell focus",
                "shield proficiency"});
}

mapping query_cantrip_spells(object ob)
{
    return ([ "create water" : 1, "detect magic" : 1, "detect poison" : 1, "guidance" : 1, "resistance" : 1, "light" : 1, "mending" : 1 ]);
}

mapping class_featmap(string myspec) {
    return ([ 1 : class_feats()+({"judgement","monster lore", }), 2 : ({ "track" }), 3:({"force of personality"}), 5: ({"bane"}), 6: ({"leadership"}), 8: ({"second judgement"}), 11: ({"stalwart"}), 14: ({"exploit weakness"}),16 : ({"third judgement"}), 17 : ({"slayer"}), 20 : ({"true judgement"})]);
}

string *class_skills()
{
    return ({ "perception","survival","athletics","academics","influence" });
}

int skill_points() { return 6; }

string old_save_type() { return "cleric"; }

string new_save_type() { return "cleric"; }

void advanced_func(object player)
{
    player->set_guild_level("inquisitor",(int)player->query_class_level("inquisitor"));
    player->set_advanced((int)player->query_advanced() + 1);
    return;
}

int hit_dice() { return 8; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 4; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int bonus;
    float penalty, full_level, class_level;
    
    full_level = to_float(player->query_base_character_level());
    class_level = to_float(player->query_prestige_level("inquisitor"));
    
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
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("inquisitor",player->query_class_level("inquisitor"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "wisdom";
}

mapping query_class_spells()
{
    return(([]));
}

void newbie_func(object who)
{
    object ob;
    if(!objectp(who)) return;
    return 1;
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "inquisitor":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
