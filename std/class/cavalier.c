#include <std.h>
#include <dieties.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({  }); } // temporary

int caster_class() { return 0; }

int is_locked_class()
{
    return 1;
}

string *restricted_races() {
    return ({"beastman","bugbear","dwarf","elf","gnome","goblin","half-elf","half-orc","halfling","hobgoblin",
        "kobold","orc","drow","firbolg","gnoll","half-drow","half-ogre","ogre","ogre-mage","voadkyn","wemic" });
}

string *restricted_classes() { return ({ "bard","barbarian","thief","warlord","ranger","paladin","antipaladin" }); }

int *restricted_alignments() {
    return ({ 4, /*NG*/5, /*N*/6, /*NE*/7, /*CG*/8, /*CN*/9  /*CE*/ });
}

string *restricted_gods() {
    return ({ "akadi","anhur","beshaba","cyric","istishia","malar","mask","mielikki","oghma","shaundakul",
        "talos","tempus","tymora" });
}

mapping stat_requirements() {
    return ([ "strength" : 12, "charisma" : 12 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 1,0,0 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec) {
    return ({ "light armor proficiency", "medium armor proficiency", "heavy armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "parry" });
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "light armor proficiency", "medium armor proficiency", "heavy armor proficiency", "shield proficiency", "simple weapon proficiency", "martial weapon proficiency", "parry" }), 3 : ({ "mounted combat" }), 7 : ({ "indomitable" }), 9 : ({ "ride-by attack" }), 11 : ({ "charge" }), 14 : ({ "force of personality" }), 17 : ({ "leadership" }), ]);
}

string *class_skills()
{
    return ({ "academics","athletics","endurance","influence" });
}

int skill_points() { return 4; }

string old_save_type() { return "cavalier"; }

string new_save_type() { return "cavalier"; }

void advanced_func(object player)
{
    int prof,level;
    if(!objectp(player)) { return; }

    level = (int)player->query_base_character_level();

    player->set_guild_level("cavalier",(int)player->query_class_level("cavalier"));

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

int hit_dice() { return 12; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 4; } // hitpoints per level above level 20

string armor_allowed() { return "fighter"; }

string weapons_allowed() { return "fighter"; }

int max_stance_offensive() { return 5; }

int max_stance_defensive() { return 5; }

int attack_bonus(object player)
{
    int level;
    level = (int)player->query_prestige_level("cavalier");
    return level;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("cavalier",player->query_class_level("cavalier"),player);
    num = num / 7;
    return num;
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "cavalier":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
