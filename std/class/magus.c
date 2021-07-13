#include <std.h>
#include <daemons.h>
#include <dirs.h>

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
    return ([ "intelligence" : 14, ]);
}

int *saving_throws() { return ({ 1,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({ "simple weapon proficiency",
                "martial weapon proficiency",
                "light armor proficiency",
                "spell focus"});
}

mapping class_featmap(string myspec) {
    return ([ 1 : class_feats() + ({"arcane pool", "spell combat", "magus armor"}), 2 : ({"spellstrike"}), 4 : ({"spell recall"}), 7 : ({"medium armor proficiency"}), 10 : ({"fighter training"}), 11 : ({"improved spell recall"}), 13 : ({"heavy armor proficiency"}), 16 : ({"spell counterstrike"}), 19 : ({ "greater spell access" }), 20 : ({"legendary blade"})]);
}

mapping query_cantrip_spells(object ob)
{
    return ([ "acid splash" : 1, "detect magic" : 1, "daze" : 1, "dancing lights" : 1, "resistance" : 1, "ray of frost" : 1, "disrupt undead" : 1 ]);
}

string *class_skills()
{
    return ({ "perception", "athletics", "academics", "dungeoneering", "spellcraft" });
}

int skill_points() { return 4; }

string old_save_type() { return "magus"; }

string new_save_type() { return "magus"; }

void advanced_func(object player)
{
    player->set_guild_level("magus",(int)player->query_class_level("magus"));
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
    class_level = to_float(player->query_prestige_level("magus"));
    
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
    num = "/daemon/bonus_d.c"->attack_bonus("magus", player->query_class_level("magus"), player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "intelligence";
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
        case "magus":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}

int fighter_training(object player)
{
    int fighter_level = 0;
    if (FEATS_D->usable_feat(player, "fighter training")) {
        fighter_level += player->query_class_level("magus") / 2;
    }
    return fighter_level;
}

int spell_combat(object player)
{
    int damage_mod = 1;
    if (player->query_class_level("magus") > 7) {
        damage_mod ++;
    }
	if (player->query_class_level("magus") > 13) {
		damage_mod ++;
	}
    return damage_mod;
}