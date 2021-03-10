#include <std.h>
#include <dirs.h>

inherit DAEMON;

#define BASE_CLASS find_object_or_load(DIR_CLASSES+"/sorcerer.c")

void create()
{
    ::create();
}

string *query_base_classes() { return ({ "sorcerer" }); }

int is_prestige_class() { return 1; }

string *search_paths() { return BASE_CLASS->search_paths(); } // temporary

int caster_class() { return BASE_CLASS->caster_class(); }

string *restricted_races() { return BASE_CLASS->restricted_races(); }

string *restricted_classes() { return BASE_CLASS->restricted_classes(); }

int *restricted_alignments() { return BASE_CLASS->restricted_alignments(); }

string *restricted_gods() { return BASE_CLASS->restricted_gods(); }

string requirements() // string version, maybe we'll need this, maybe not, can remove later if not
{
    string str;
    str = "Prerequisites:\n"
        "    20 Sorcerer levels (level adjustments considered part of required levels)\n"
        "    20 Charisma stat, before equipment modifiers\n";

    return str;
}


int prerequisites(object player)
{
    mapping skills;
    object race_ob;
    string race;
    if (!objectp(player)) {
        return 0;
    }

    race = player->query("subrace");
    if (!race) {
        race = player->query_race();
    }
    race_ob = find_object_or_load(DIR_RACES + "/" + player->query_race() + ".c");
    if (!objectp(race_ob)) {
        return 0;
    }
    skills = player->query_skills();

    if ((player->query_class_level("sorcerer")) < 20) {
        return 0;
    }
    if (player->query_base_stats("charisma") < 20) {
        return 0;
    }
    return 1;
}

mapping stat_requirements() { return ([ "charisma" : 20 ]); }

int *saving_throws() { return BASE_CLASS->saving_throws(); }

string *combat_styles() { return BASE_CLASS->combat_styles(); }

string *class_feats(string myspec) { return BASE_CLASS->class_feats(); }

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "versatile_arcanist":
        case "sorcerer":
            level = player->query_class_level("sorcerer");
            level += player->query_class_level("versatile_arcanist");
            return level;

        default:
            return player->query_class_level(the_class);
    }
    return 0;
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "greater spell knowledge" }), 4 : ({ "master of elements" }), 7 : ({ "master of versatility" }), ]);
}

string *class_skills()
{
    return BASE_CLASS->class_skills();
}

int skill_points() { return BASE_CLASS->skill_points(); }

string old_save_type() { return BASE_CLASS->old_save_type(); }

string new_save_type() { return BASE_CLASS->new_save_type(); }

// unsure on this one, will have to investigate
void advanced_func(object player) { return BASE_CLASS->advance_func(player); }

int hit_dice() { return BASE_CLASS->hit_dice(); }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return BASE_CLASS->default_hitpoints(); } // hitpoints per level above level 20

string armor_allowed() { return BASE_CLASS->armor_allowed(); }

string weapons_allowed() { return BASE_CLASS->weapons_allowed(); }

int max_stance_offensive() { return BASE_CLASS->max_stance_offensive(); }

int max_stance_defensive() { return BASE_CLASS->max_stance_defensive(); }

int attack_bonus(object player) { return 0; }

int number_of_attacks(object player) { return BASE_CLASS->number_of_attacks(player); }

string newbie_choice() { return BASE_CLASS->newbie_choice(); }

string *query_newbie_stuff() { return BASE_CLASS->query_newbie_stuff(); }

void process_newbie_choice(object who, string str) { return BASE_CLASS->process_newbie_choice(who,str); }

string query_casting_stat() { return BASE_CLASS->query_casting_stat(); }

mapping query_class_spells() { return BASE_CLASS->query_class_spells(); }


// used for master of versatility to reorder spell mappings to allow the sorcerer
// to keep casting as long as they have enough combined spell levels to cast the spell
// should only get called when the caster doesn't have the correct spell level prepared
// I wish I was better at math
mapping reorder_memorized(object ob, int lvl)
{
    mapping memorized = ([]);
    int i, j, total, num, needed, *levels = allocate(10);

    if(!objectp(ob)) { return ([]); }

    memorized = ob->query_all_memorized("sorcerer");

    for(i=1;i<10;i++)
    {
        num = memorized[i]["generic"];
        levels[i] = num;
        total += (num * i);
    }

    // if we don't have enough total spell levels then there's nothing to do, return original memorized mapping
    if(total < lvl) { return memorized; }

    needed = lvl;

    while(needed && (j < 100) )
    {
        j++;
        if(lvl > 1)
        {
            for( i = (lvl - 1); i > 0; i--) // first run in descending order
            {
                if(!levels[i]) { continue; }
                if( (needed - i) < 0) { continue; }
                needed = needed - i;
                levels[i] = levels[i] - 1;
            }
        }

        if(needed) // then run in ascending order
        {
            for(i = 1; i < 10; i++)
            {
                if(!levels[i]) { continue; }
                if( (needed - i) < 0) { continue; }
                needed = needed - i;
                levels[i] = levels[i] - 1;
            }
        }

        // should be getting close now, make sure we have first level slots to fill up any extra points required
        if(needed && !levels[1])
        {
            for(i=2;i<10;i++)
            {
                if(!levels[i]) { continue; }

                levels[1] = i;
                levels[i] = levels[i] - 1;
            }
        }
    }

    if(!needed) { levels[lvl] = 1; }

    for(i=1;i<sizeof(levels);i++)
    {
        if(!levels[i]) { levels[i] = 0; }
        memorized[i]["generic"] = levels[i];
    }

    return memorized;
}
