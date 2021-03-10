#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/fighter" }); } // temporary

int caster_class() { return 0; }

string *restricted_races() { return ({}); }

string *restricted_classes() { return ({ }); }

int *restricted_alignments() { return ({ }); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 1,0,0 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec) {
    return ({  });
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "light armor proficiency", "medium armor proficiency", "heavy armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", }), 2 : ({ "bravery" }), 3 : ({ "armor training" }), 5 : ({ "weapon training" }), 19 : ({ "armor mastery" }), 20 : ({ "weapon mastery" })]);
}

string *class_skills()
{
    return ({ "athletics","endurance","healing","perception" });
}

int skill_points() { return 4; }

string old_save_type() { return "fighter"; }

string new_save_type() { return "fighter"; }

void advanced_func(object player)
{
    player->set_guild_level("fighter",(int)player->query_class_level("fighter"));
    return;
}

int hit_dice() { return 10; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 4; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int level;
    level = (int)player->query_prestige_level("fighter");
    return level;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("fighter",player->query_class_level("fighter"),player);
    num = num / 7;
    return num;
}

string newbie_choice() { return "Fighting Style"; }
string *query_newbie_stuff() { return ({ "peasant","swashbuckler","thug","soldier","dervish" }); }
void process_newbie_choice(object who, string str)
{
    if(!objectp(who) || !stringp(str)) return;
    who->set_fighter_style(str);
    //tell_object(who, "CYAN%^You learned the ways of fighting within the "+capitalize(str)+" style.");
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "fighter":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
