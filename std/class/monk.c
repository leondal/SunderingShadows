#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit DAEMON;

void create()
{
    ::create();
}

string* search_paths()
{
    return ({});
}                                       // temporary

int caster_class()
{
    return 1;
}

string* restricted_races()
{
    return ({ "drow", "beastman", "bugbear", "centaur", "elf", "firbolg", "gnoll", "goblin", "halfling", "half-ogre", "half-orc",
              "hobgoblin", "kobold", "minotaur", "ogre", "ogre-mage", "orc", "voadkyn", "wemic", "yuan-ti" });
}

string* restricted_classes()
{
    return ({ });
}

int* restricted_alignments()
{
    return ({ 4, 5, 6, 7, 8, 9 });
}

string* restricted_gods()
{
    return ({});
}

mapping stat_requirements()
{
    return ([ "wisdom" : 15, "dexterity" : 15 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int* saving_throws()
{
    return ({ 1, 1, 1 });
}

string* combat_styles()
{
    return ({});
}

string* class_feats(string myspec)
{
    return ({ "simple weapon proficiency",
              "unarmored defense",
              "evasion",
              "dodge",
              "diamond soul",
              "perfect self",
              "flurry of blows",
              "stillness of mind",
              "stunning strike",
              "purity of body",
              "defensive roll", });
}

//Bringing it in accordance with SRDs, Il.
mapping class_featmap(string myspec)
{
    mapping myMap;
    myMap = ([ 1 : ({ "simple weapon proficiency", "unarmored defense", "spell focus" }),
               2 : ({ "dodge", "flurry of blows" }),
               5 : ({ "stunning strike" }),
               7 : ({ "evasion", "stillness of mind" }),
               10 : ({ "purity of body" }),
               14 : ({ "diamond soul" }),
               15 : ({ "timeless body" }),
               18 : ({ "empty body" }),
               19 : ({ "tongue of the sun and moon" }),
               20 : ({ "perfect self" }),
               21 : ({ "defensive roll" }),
               31 : ({ "unchained" }), ]);

    switch (myspec) {
    case "way of the fist":
    case "all":
        myMap += ([17 : ({ "quivering palm" })]);
        break;
    }
    return myMap;
}

string* class_skills()
{
    return ({ "endurance", "athletics" });
}

string* way_skills(string way)
{
    string* mySkills;
    mySkills = ({ "endurance", "athletics" });

    switch (way) {
    case "way of the elements":
        mySkills += ({ "spellcraft", "academics" });
        break;

    case "way of the shadow":
        mySkills += ({ "stealth", "perception" });
        break;

    case "way of the fist":
        mySkills += ({ "survival", "perception" });
        break;
    }
    return mySkills;
}

int skill_points()
{
    return 4;
}

string old_save_type()
{
    return "monk";
}

string new_save_type()
{
    return "monk";
}

void advanced_func(object player)
{
    player->set_guild_level("monk", (int)player->query_class_level("monk"));
    return;
}

int hit_dice(object ob)
{
    if(FEATS_D->has_feat(ob, "unchained"))
        return 10;
    
    return 8;
}                             // hit dice rolled for hitpoints each level

int default_hitpoints()
{
    return 4;
}                                     // hitpoints per level above level 20

string armor_allowed()
{
    return "barbarian";
}

string weapons_allowed()
{
    return "thief";
}

int max_stance_offensive()
{
    return 1;
}

int max_stance_defensive()
{
    return 1;
}

int attack_bonus(object player)
{
    int bonus;
    float penalty, full_level, class_level;
    
    full_level = to_float(player->query_base_character_level());
    class_level = to_float(player->query_prestige_level("monk"));
    
    //Full BAB with unchained capstone
    if(FEATS_D->has_feat(player, "unchained"))
        return class_level;
    
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
    if (!objectp(player)) {
        return 0;
    }
    num = "/daemon/bonus_d.c"->attack_bonus("monk", player->query_class_level("monk"), player);
    num = num / 7;
    return num;
}

string query_casting_stat()
{
    return "wisdom";
}

int unarmed_damage(object player)
{
    int myLev, amt = roll_dice(1, 4);
    if (!objectp(player)) {
        return roll_dice(1, 4);
    }
    myLev = (int)player->query_guild_level("monk");
    switch (myLev) {
    case 0..10:
        amt = roll_dice(1, 6);
        break;

    case 11..20:
        amt = roll_dice(1, 8);
        break;

    case 21..30:
        amt = roll_dice(1, 10);
        break;

    case 31..40:
        amt = roll_dice(1, 12);
        break;

    case 41..50:
        amt = roll_dice(1, 14);
        break;
        /*     break;
           case 26..30:
             return (roll_dice(1, 12) + roll_dice(1, 6));
             break;
           case 31..35:
             return (roll_dice(1, 12) + roll_dice(1, 8));
             break;
           case 36..50:
             return (roll_dice(1, 12) + roll_dice(1, 10));
             break;
           default:
             return (roll_dice(1, 12) + roll_dice(1, 10));*/
    }
    if (FEATS_D->usable_feat(player, "fists of fury")) {
        amt += roll_dice(1, 2);
    }
    return amt;
}

int effective_enchantment(object player)
{
    int amt;
    if (!objectp(player)) {
        return 0;
    }
    if (!(int)player->query_guild_level("monk")) {
        return 0;
    }
    amt = ((int)player->query_guild_level("monk") / 6);
    if (FEATS_D->usable_feat(player, "enchanted fists")) {
        amt += 1;
    }
    return amt;
}

int critical_multiplier(object player)
{
    if (!objectp(player)) {
        return 0;
    }
    return ((int)player->query_guild_level("monk") / 10);
}

int critical_damage(object player)
{
    if (!objectp(player)) {
        return 0;
    }else {
        return unarmed_damage(player);
    }
}

int caster_level_calcs(object player, string the_class)
{
    int level;
    if (!objectp(player)) {
        return 0;
    }
    switch (the_class) {
    case "monk":
    default:
        return player->query_class_level(the_class);
    }
    return 0;
}

// going to put all the various monk checks in here for ease of updating
varargs int monk_check(object player, string type, mixed extra)
{
    if (!objectp(player)) {
        return 0;
    }

    switch (type) {
    case "heal":

        if (!sizeof(player->query_attackers())) {
            return 1;
        }

        if (!objectp(extra) || extra != player) { // only allowed to heal themselves in combat
            tell_object(player, "%^YELLOW%^You can only heal yourself in combat.");
            return 0;
        }
        if (player->query_class_level("monk") < 6) {
            tell_object(player, "%^YELLOW%^You must be level 6 to heal yourself in combat.");
            return 0;
        }
        if (player->query_property("wholeness of body") > time()) {
            tell_object(player, "%^YELLOW%^You can't heal yourself in combat again yet.");
            return 0;
        }
        if (!USER_D->can_spend_ki(player, 3)) {
            tell_object(player, "%^YELLOW%^You don't have enough ki to heal yourself.");
            return 0;
        }
        if (!player->is_wielding("unarmed") && !player->is_wielding("small")) {
            tell_object(player, "%^YELLOW%^You must be wielding only small weapons or unarmed to heal yourself in combat.");
            return 0;
        }
        if (!player->is_ok_armour("barb")) {
            tell_object(player, "%^YELLOW%^You are wearing too much armor to heal yourself in combat.");
            return 0;
        }
        if ((player->query("monk way") != "way of the fist") && !FEATS_D->usable_feat(player, "grandmaster of the way")) {
            tell_object(player, "%^YELLOW%^Only monks with the way of the fist or grandmaster of the ways may heal themselves in combat.");
            return 0;
        }
        return 1;

    case "way of the fist":

        if (player->query("monk way") == "way of the fist" || FEATS_D->usable_feat(player, "grandmaster of the way")) {
            return 1;
        }
        return 0;

    case "way of the shadow":

        if (player->query("monk way") == "way of the shadow" || FEATS_D->usable_feat(player, "grandmaster of the way")) {
            return 1;
        }
        return 0;


    case "way of the elements":

        if (player->query("monk way") == "way of the elements" || FEATS_D->usable_feat(player, "grandmaster of the way")) {
            return 1;
        }
        return 0;
    }

    return 0;
}

string newbie_choice() { return "Monk Way"; }
string *query_newbie_stuff(int align)
{
    return ({"way of the fist", "way of the shadow", "way of the elements"});
}
void process_newbie_choice(object who, string str)
{
    if (!objectp(who) || !stringp(str)) {
        return;
    }
    who->set("monk way",str);
}
