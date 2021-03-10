#include <std.h>
inherit DAEMON;

#include <bloodlines.h>

void create() { ::create(); }

string *search_paths() { return ({  }); }

int caster_class() { return 1; }

string *restricted_races() {
    return ({ "beastman","bugbear","dwarf","hobgoblin","orc",
        "firbolg","gnoll","half-ogre","ogre","wemic","ogre-mage" });
}

string *restricted_classes() { return ({ "mage","psion"}); }

int *restricted_alignments() { return ({}); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return (["charisma" : 16 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 0,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({ "simple weapon proficiency",
              "spell focus" });
}

mapping class_featmap(string myspec) {
    return ([ 1 : ({ "simple weapon proficiency", "spell focus", }) ]);
}

string *class_skills()
{
    return ({ "academics","perception","influence","spellcraft" });
}

int skill_points() { return 4; }

string old_save_type() { return "mage"; }

string new_save_type() { return "mage"; }

void advanced_func(object player)
{
    player->set_guild_level("sorcerer",(int)player->query_class_level("sorcerer"));
    return;
}

int hit_dice() { return 6; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 2; } // hitpoints per level above level 20

int max_con_bonus() { return 2; } // max amount of the con bonus that can be added to hitpoints each level

string armor_allowed() { return "mage"; }

string weapons_allowed() { return "mage"; }

int max_stance_offensive() { return 1; }

int max_stance_defensive() { return 1; }

int attack_bonus(object player)
{
    int bonus;
    float penalty, full_level, class_level;
    
    full_level = to_float(player->query_base_character_level());
    class_level = to_float(player->query_prestige_level("sorcerer"));
    
    if(full_level < 20.00)
    {
        bonus = (to_int(class_level) * 1 / 2);
        return bonus;
    }
    
    // Above 20
    // 1/2 BAB gets full penalty to BAB
    // Weighted average of class level compared to total level
    penalty = (10.00 * (class_level / full_level));
    bonus = to_int(class_level - penalty);
    
    return bonus;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("mage",player->query_class_level("sorcerer"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "charisma";
}

mapping query_class_spells()
{
    return (([
    1 : ({"armor","burning hands","chill touch","color spray","darkness","daze","detect magic","identify","light","magic missile","shield","shocking grasp","sleep","summon companion","summon swarm" }),
    2 : ({"acid arrow","augmentation","blindness","clairvoyance","darkvision","detect invisibility","hideous laughter","invisibility","misdirection","ray of enfeeblement","rope trick","scorcher","spider climb","web" }),
    3 : ({"acid orb","blink","dispel magic","fireball","fly","frost orb","garble","heroism","hold person","lightning bolt","lightning orb","monster summoning 1","protection from scrying","sonic orb","tongues","vampiric touch","water breathing" }),
    4 : ({"animate dead","bestow curse","black tentacles","detect scrying","fire shield","greater invisibility","gust of wind","ice storm","monster summoning 2","shout","sonic shield","static field","wall of fire" }),
    5 : ({"acid breath","ball lightning","break curse","cone of cold","conjure elemental","domination","lower resistance","monster summoning 3","passwall","telepathic bond","teleport" }),
    6 : ({"chain lightning","contingency","dragon scales","faithful phantom guardians","foresight","mind fog","monster summoning 4","planar beacon","transformation","warriors constitution" }),
    7 : ({"finger of death","greater dispel magic","heart of stone","mages sword","magic mirror","monster summoning 5","powerword stun","prismatic spray","project image","spell turning","teleport without error" }),
    8 : ({"disintegrate","drawmij's instant summons","greater shout","incendiary cloud","monster summoning 6","stoneskin" }),
    9 : ({"animus blast","dimensional lock","freedom of movement","gate","hellball","meteor swarm","monster summoning 7","phantasmal killer","powerword kill","prying eyes","timestop" }),
    ]));
}

string newbie_choice() { return "Bloodline"; }
string *query_newbie_stuff() { return sort_array(keys(BLOODLINE_DESC),1); }
void process_newbie_choice(object who, string str)
{
    if(!objectp(who) || !stringp(str))
        return;
    who->set_bloodline(str);
}


void newbie_func(object who)
{
    object ob, ob2;
    int i;
    if(!objectp(who)) return;

    ob = new("/d/magic/comp_bag");
    ob->move(who);

    tell_object(who, "%^BOLD%^%^WHITE%^You are given a bag for components "+
    "to help you out in the world of ShadowGate.%^RESET%^");
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "sorcerer":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
