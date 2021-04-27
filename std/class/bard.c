// on board discussion, added med armor proficiency to streamline game functionality for the class. N, 9/12.
#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/bard" }); } // temporary

int caster_class() { return 1; }

string *restricted_races() {
    return ({ "beastman","bugbear","dwarf","goblin","half-orc","hobgoblin",
        "kobold","orc","gnoll","half-ogre","ogre","ogre-mage","voadkyn" });
}

string *restricted_classes() { return ({ }); }

int *restricted_alignments() { // switched March 2016 to 3e standard, all non-lawful >> N <<
    return ({ 1, /*LG*/ 2, /*LN*/ 3, /*LE*/ });
}

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([ "charisma" : 14 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 0,1,1 }); }

string *combat_styles() {
    return ({});
}

string* class_feats(string myspec)
{
    return ({ "simple weapon proficiency",
                "martial weapon proficiency",
                "light armor proficiency",
                "medium armor proficiency",
                "dodge",
                "spell focus" });
}

mapping class_featmap(string myspec) {
    return ([ 1:({ "simple weapon proficiency", "martial weapon proficiency", "light armor proficiency","shield proficiency", "spell focus","inspire","inspire courage", "dodge", "countersong"}), 3:({"inspire competence"}), 5: ({ "indomitable" }), 7: ({ "force of personality" }), 8:({"dirge of doom"}), 9:({"inspire greatness"}), 10:({ "tools of the trade" }), 12:({"soothing song"}), 14:({"frightening tune"}), 15:({"inspire heroics"}), 20:({"deadly song"})]);
}

mapping query_cantrip_spells(object ob)
{
    return ([ "flare" : 1, "detect magic" : 1, "daze" : 1, "dancing lights" : 1, "resistance" : 1, "mending" : 1 ]);
}

string *class_skills()
{
    return ({ "academics","thievery","influence","spellcraft","athletics" });
}

int skill_points() { return 6; }

string old_save_type() { return "bard"; }

string new_save_type() { return "bard"; }

void advanced_func(object player)
{
    player->set_guild_level("bard",(int)player->query_class_level("bard"));
    player->set_advanced((int)player->query_advanced() + 1);
    return;
}

int hit_dice() { return 8; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 3; } // hitpoints per level above level 20

string armor_allowed() { return "bard"; }

string weapons_allowed() { return "bard"; }

int max_stance_offensive() { return 4; }

int max_stance_defensive() { return 4; }

int attack_bonus(object player)
{
    int bonus;
    float penalty, full_level, class_level;
    
    full_level = to_float(player->query_base_character_level());
    class_level = to_float(player->query_prestige_level("bard"));
    
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
    num = "/daemon/bonus_d.c"->attack_bonus("bard",player->query_class_level("bard"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "charisma";
}

mapping query_class_spells()
{
    return(([
        1 : ({"cure light wounds","dancing lights","daze","detect magic","expedious retreat","flare","legend lore","mending","monster summoning 1","resistance","sleep","summon companion","summon swarm","whispering wind" }),
        2 : ({"blindness","cats grace","cure moderate wounds","darkness","eagles splendor","foxs cunning","garble","hold person","invisibility","misdirection","monster summoning 2","sound burst","tongues" }),
        3 : ({"charm monster","clairvoyance","crushing despair","cure serious wounds","daylight","detect invisibility","dispel magic","displacement","fear","glitterdust","good hope","monster summoning 3","phantom steed" }),
        4 : ({"break curse","cure critical wounds","detect scrying","dimension door","freedom of movement","heroism","monster summoning 4","neutralize poison","secure shelter","shout" }),
        5 : ({"cacophonic shield","false vision","forgotten melody","greater dispel magic","healing circle","monster summoning 5","warriors constitution" }),
        6 : ({"animate object","greater shout","heroes feast","listening shadow","monster summoning 6","project image","regeneration" }),
    ]));
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
        case "bard":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
