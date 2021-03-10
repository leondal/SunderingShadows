#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({  }); } // temporary

int caster_class() { return 1; }

string *restricted_races() {
    return ({  });
}

string *restricted_classes() {
    return ({ });
}

int *restricted_alignments() {
    return ({7, 8, 9});
}

string *restricted_gods() {
    return ({ "akadi","anhur","beshaba","cyric","istishia","malar","mask","mielikki","oghma","shaundakul",
        "talos","tempus","tymora" });
}

string *combat_styles() {
    return ({});
}

mapping stat_requirements() {
    return ([ "strength" : 12, "charisma" : 12 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 1,0,0 }); }

int skill_points() { return 4; }

string *class_feats(string myspec) {
    return ({ "light armor proficiency", "medium armor proficiency", "heavy armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "parry" });
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "light armor proficiency", "medium armor proficiency", "heavy armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "parry", "smite" }), 2 : ({ "layonhands" }), 3 : ({ "divine health", "aura of courage" }), 4 : ({ "channel" }), 6 : ({ "indomitable" }), 7 : ({ "force of personality" }), 8 : ({ "aura of resolve" }), 11 : ({ "aura of fury" }), 13 : ({ "dedication" }), 17 : ({ "aura of justification" }), 20 : ({ "champion" }) ]);
}

string *class_skills()
{
    return ({ "academics","athletics","endurance","influence" });
}

string old_save_type() { return "paladin"; }

string new_save_type() { return "paladin"; }

void advanced_func(object player)
{
    int i,prof,level;
    if(!objectp(player)) { return; }

    level = (int)player->query_base_character_level();

    player->set_guild_level("paladin",(int)player->query_class_level("paladin"));

    prof = 100;

    if (level > 30)
    {
        prof += (level - 30)/2;
    }
    if (level > 20)
    {
        prof = prof + ((level>30)?10:level - 20);
    }
    prof = prof + 2 * (level>20?20:level);

    player->set("max lance", prof+20);
    player->set("max medium blades",prof);
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
    level = (int)player->query_prestige_level("paladin");
    return level;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("paladin",player->query_class_level("paladin"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "charisma";
}

mapping query_class_spells()
{
    return (([ ]));
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "paladin":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
