// monster_d.c
#include <std.h>
#include <daemons.h>
#include <security.h>
#define MONSTER_FILE "/daemon/save/leveled_monster_list"

inherit DAEMON;
nosave int MAX_L5_CHAMPS = 8;
nosave int MAX_L10_CHAMPS = 12;
nosave int MAX_L15_CHAMPS = 16;
nosave int MAX_L20_CHAMPS = 20;
nosave int MAX_L25_CHAMPS = 24;
nosave int MAX_L30_CHAMPS = 30;
nosave int MAX_L35_CHAMPS = 36;
nosave int MAX_L40_CHAMPS = 42;
nosave int MAX_L45_CHAMPS = 48;
nosave int MAX_L50_CHAMPS = 50;
nosave int MAX_CHAMPS = 400;
nosave int CHAMP_CHANCE = 125;

nosave mapping CHAMP_SIZE = (["MAX_L5_CHAMPS" : MAX_L5_CHAMPS, "MAX_L10_CHAMPS" : MAX_L10_CHAMPS,
                       "MAX_L15_CHAMPS" : MAX_L15_CHAMPS, "MAX_L20_CHAMPS" : MAX_L20_CHAMPS,
                       "MAX_L25_CHAMPS" : MAX_L25_CHAMPS, "MAX_L30_CHAMPS" : MAX_L30_CHAMPS,
                       "MAX_L35_CHAMPS" : MAX_L35_CHAMPS, "MAX_L40_CHAMPS" : MAX_L40_CHAMPS,
                       "MAX_L45_CHAMPS" : MAX_L45_CHAMPS, "MAX_L50_CHAMPS" : MAX_L50_CHAMPS,
                       "MAX_CHAMPS" : MAX_CHAMPS]);

nosave mapping CURRENT_CHAMPIONS = ([]);

//list of monsters that exist in the game world by level
mapping MONSTER_LIST_BY_LEVEL;
string *MONSTER_LIST;
string *MONSTER_QUESTS;

void champion_monster(object mon);
varargs int check_champions(int lev, object mon);
varargs void create_champion(object mon, int manual);
int get_champ_level(int lev);
void add_mob_to_level_list(object mon);
void init_monster_list_by_level();
void monster_list_save();
void monster_list_restore();
mixed identify_champions() { return CURRENT_CHAMPIONS; }

void check_valid()
{
    if(!pointerp(MONSTER_LIST) || !sizeof(MONSTER_LIST) || !pointerp(MONSTER_QUESTS) || !sizeof(MONSTER_QUESTS))
    {
        monster_list_restore();
        if(!pointerp(MONSTER_LIST)) MONSTER_LIST = ({});
        if(!pointerp(MONSTER_QUESTS)) MONSTER_QUESTS = ({});
    }
}

varargs int check_champions(int lev, object mon)
{
    object champ, *champs, *to_remove;
    string lev_brack;
    int y;
    if(!mapp(CURRENT_CHAMPIONS)) CURRENT_CHAMPIONS = ([]);
    if(lev > 50) lev_brack = "MAX_CHAMPS";
    else lev_brack = "MAX_L"+lev+"_CHAMPS";
    if(!CURRENT_CHAMPIONS[lev_brack])
    {
        CURRENT_CHAMPIONS += ([lev_brack : ({})]);
        if(objectp(mon)) CURRENT_CHAMPIONS[lev_brack] += ({mon});
        return 1;
    }
    else
    {
        champs = CURRENT_CHAMPIONS[lev_brack];
        to_remove = ({});
        for(y = 0;y < sizeof(champs);y++)
        {
            if(objectp(champs[y]))
            {
                if(objectp(environment(champs[y]))) continue;
                else
                {
                    to_remove += ({champs[y]});
                    continue;
                }
            }
            else
            {
                to_remove += ({champs[y]});
                continue;
            }
            continue;
        }
        champs -= to_remove;
        CURRENT_CHAMPIONS[lev_brack] = champs;
        if(sizeof(CURRENT_CHAMPIONS[lev_brack]) >= CHAMP_SIZE[lev_brack]) return 0;
        else
        {
            if(objectp(mon))
            {
                CURRENT_CHAMPIONS[lev_brack] += ({mon});
            }
            return 1;
        }
    }
    return 0;
}

int get_champ_level(int lev)
{
    if(!intp(lev)) return 0;
    switch(lev)
    {
        case 0..5:
            return 5;
            break;
        case 6..10:
            return 10;
            break;
        case 11..15:
            return 15;
            break;
        case 16..20:
            return 20;
            break;
        case 21..25:
            return 25;
            break;
        case 26..30:
            return 30;
            break;
        case 31..35:
            return 35;
            break;
        case 36..40:
            return 40;
            break;
        case 41..45:
            return 45;
            break;
        case 46..50:
            return 50;
            break;
        default:
            return lev;
            break;
    }
    return lev;
}

varargs void create_champion(object mon, int manual)
{
    int champ_level, champ_bracket, mod;
    int cur_hp, cur_max_hp, cur_str, cur_dex, cur_con, cur_int, cur_wis, cur_cha, cur_level, cur_ac;
    int y;
    string *cur_classes, cur_class;
    if(!objectp(mon)) return;
    if(mon->query_property("is_champion_monster")) return;
    champ_level = mon->query_level();
    champ_bracket = get_champ_level(champ_level);
    if(!check_champions(champ_bracket) && !manual) return;
    if(random(CHAMP_CHANCE) && !manual) return;
    switch(random(10))
    {
        case 0..6:
            mod = 2;
            mon->set_property("added short",({ "%^RESET%^ (%^BOLD%^%^WHITE%^Strong%^RESET%^)"}));
            break;
        case 7..8:
            mod = 3;
            mon->set_property("added short",({ "%^RESET%^ (%^BOLD%^%^Elite%^RESET%^)"}));
            break;
        case 9:
            mod = 4;
            mon->set_property("added short",({ "%^RESET%^ (%^BOLD%^%^BLACK%^Heroic%^RESET%^)"}));
            break;
    }

    cur_max_hp = (int)mon->query_max_hp();
    cur_ac = (int)mon->query_ac();
    cur_str = (int)mon->query_stats("strength");
    cur_dex = (int)mon->query_stats("dexterity");
    cur_con = (int)mon->query_stats("constitution");
    cur_wis = (int)mon->query_stats("wisdom");
    cur_cha = (int)mon->query_stats("charisma");
    cur_int = (int)mon->query_stats("intelligence");
    //mon->set_overall_ac((cur_ac-(mod*2)));
    mon->set_overall_ac((cur_ac-mod));
    mon->set_attack_bonus(mod*2);
    mon->set_property("noMissChance", 1);
    mon->set_damage_bonus(mod);
    mon->set_stats("strength", (cur_str+mod));
    mon->set_stats("dexterity", (cur_dex+mod));
    mon->set_stats("consitution", (cur_con+mod));
    mon->set_stats("charisma", (cur_cha+mod));
    mon->set_stats("intelligence", (cur_int+mod));
    mon->set_stats("wisdom", (cur_wis+mod));
    mon->set_max_hp(((cur_max_hp * mod) + random(cur_max_hp*mod)));
    mon->set_hp(mon->query_max_hp());
    mon->add_money("platinum", roll_dice(3,1000*mod));
    mon->set_property("full attacks", 1);
    mon->set_property("is_champion_monster", 1);
    cur_classes = mon->query_classes();
    for(y = 0;y < sizeof(cur_classes);y++)
    {
        cur_class = cur_classes[y];
        cur_level = (int)mon->query_class_level(cur_class);
        mon->set_guild_level(cur_class, (cur_level+(mod)));
        mon->set_mlevel(cur_class, (cur_level+(mod)));
    }
    mon->set_property("add kits", 20);
    mon->set_new_exp(((int)mon->query_level()+mod*2), "boss");
    MONSTER_FEAT_D->setup_monster_feats(mon);
    mon->set("feats_enabled", 1);
    check_champions(champ_bracket, mon);
    foreach(object ob in all_inventory(mon))
    {
        if(!objectp(ob)) continue;
        if(ob->is_weapon() || ob->is_armour())
        {
            if(ob->query_creator() == file_name(mon)) ob->set_property("enchantment", 1+random(1));
        }
        continue;
    }
    return;
}

int check_max_health(object mon)
{
    int lev, mhp;
    if(!objectp(mon)) return 1;
    lev = mon->query_level();
    mhp = mon->query_max_hp();
    switch(lev)
    {
        case 0..5:
            if(mhp > 50) return 1;
            return 0;
        case 6..10:
            if(mhp > 125) return 1;
            return 0;
        case 11..15:
            if(mhp > 180) return 1;
            return 0;
        case 16..20:
            if(mhp > 400) return 1;
            return 0;
            break;
        case 21..25:
            if(mhp > 600) return 1;
            return 0;
            break;
        case 26..30:
            if(mhp > 800) return 1;
            return 0;
            break;
        case 31..35:
            if(mhp > 1000) return 1;
            return 0;
            break;
        case 36..40:
            if(mhp > 1500) return 1;
            return 0;
            break;
    }
    if(mhp > 2000) return 1;
    return 0;
}

void champion_monster(object mon)
{
    if(!objectp(mon)) return;
    if(mon->query_property("champion_check")) return;
    mon->set_property("champion_check", 1);
    add_mob_to_level_list(mon);
    if(userp(mon)) return;
    if(!mon->query("aggressive")) return;
    if(mon->is_guardsman() || mon->is_townsman()) return;
    if(mon->query_level() < 15) return;
    if(mon->is_merc()) return;
    if(mon->is_animal()) return;
    if(check_max_health(mon)) return;
    if(objectp(mon->query_property("minion"))) return;
    create_champion(mon);
    return;
}

int clean_up() { return 0; }

//Following functions are used to build a list of game-wide monsters by level - in order to later
//assign random monsters to areas - Saide, April 2017

void init_monster_list_by_level()
{
    monster_list_restore();
    if(!mapp(MONSTER_LIST_BY_LEVEL) || !sizeof(keys(MONSTER_LIST_BY_LEVEL)))
    {
        MONSTER_LIST_BY_LEVEL = (["level 5" : ({}), "level 10" : ({}), "level 15" : ({}), "level 20" : ({}),
        "level 25" : ({}), "level 30" : ({}), "level 35" : ({}), "level 40" : ({}),
        "level 45" : ({}), "level 50" : ({}), "level 55" : ({}), "level 60" : ({}),
        "level 65" : ({}), "level 70" : ({}), "level 75" : ({}), "level 80" : ({}),
        "level 85" : ({}), "level 90" : ({}), "level 95" : ({}), "level 100" : ({}),
        "level 105" : ({})]);
    }
}

int fix_level(int level)
{
    if(level >= 100) level = 105;
    else if(level >= 95) level = 100;
    else if(level >= 90) level = 95;
    else if(level >= 85) level = 90;
    else if(level >= 80) level = 85;
    else if(level >= 75) level = 80;
    else if(level >= 70) level = 75;
    else if(level >= 65) level = 70;
    else if(level >= 60) level = 65;
    else if(level >= 55) level = 60;
    else if(level >= 50) level = 55;
    else if(level >= 45) level = 50;
    else if(level >= 40) level = 45;
    else if(level >= 35) level = 40;
    else if(level >= 30) level = 35;
    else if(level >= 25) level = 30;
    else if(level >= 20) level = 25;
    else if(level >= 15) level = 20;
    else if(level >= 10) level = 15;
    else if(level >= 5) level = 10;
    else if(level >= 1) level = 5;
    return level;
}

int verify_valid_mon(object mon, string llev)
{
    string ffile;
    int lev;
    if(!objectp(mon)) return 0;
    if(mon->query_is_mount() || mon->is_merc() || mon->is_townsman() || mon->is_guardsman() ||
    mon->query_property("minion") || mon->query_property("spell_creature") || userp(mon) ||
    mon->is_vendor()) return 0;
    ffile = base_name(mon);
    if(strsrch(ffile, "/d/magic") != -1) return 0;
    if(strsrch(ffile, "/d/token_hunt") != -1) return 0;
    if(strsrch(ffile, "/d/player_houses/") != -1) return 0;
    if(strsrch(ffile, "realms/") != -1) return 0;
    if(mon->query_property("not random monster")) return 0;
    if(!mon->query("aggressive")) return 0;
    if(check_max_health(mon)) return 0;
    lev = to_int(explode(llev, "level ")[0]);
    if(mon->query_level() > (lev+4)) return 0;
    //tell_object(find_player("saide"), "ffile name ="+ffile+" is returning 1 (a valid monster)");
    return 1;
}

void add_mob_to_level_list(object mon)
{
    string mFile, LevelList;
    int mLev;
    if(!objectp(mon)) return;
    check_valid();

    if(!mapp(MONSTER_LIST_BY_LEVEL) || !sizeof(keys(MONSTER_LIST_BY_LEVEL))) init_monster_list_by_level();
    //stuff not to include

    mFile = base_name(mon);
    if(member_array(mFile, MONSTER_LIST) != -1) return; //already in the list.
    if(!intp(mLev = mon->query_level())) return;
    mLev = fix_level(mLev);
    if(!intp(mLev) || mLev < 5 || mLev > 105) return;
    LevelList = "level "+mLev;
    if(!verify_valid_mon(mon, LevelList)) return;
    if(!pointerp(MONSTER_LIST_BY_LEVEL[LevelList])) MONSTER_LIST_BY_LEVEL[LevelList] = ({});
    if(member_array(mFile, MONSTER_LIST_BY_LEVEL[LevelList]) != -1) return;
    MONSTER_LIST += ({mFile});
    MONSTER_LIST_BY_LEVEL[LevelList] += ({mFile});
    monster_list_save();
    return;
}

string *retrieve_monster_list(int lev)
{
    string LevelList, *mlist, *to_remove = ({});
    int x;
    if(lev > 14 && lev < 40) lev -= 6;
    else if(lev > 9) lev -= 5;

    if(!intp(lev = fix_level(lev))) return ({});
    LevelList = "level "+lev;
    if(!mapp(MONSTER_LIST_BY_LEVEL) || !sizeof(keys(MONSTER_LIST_BY_LEVEL))) init_monster_list_by_level();
    mlist = ({});
    if(!pointerp(mlist = MONSTER_LIST_BY_LEVEL[LevelList])) return ({});
    for(x = 0;x < sizeof(mlist);x++)
    {
        if(!file_exists(mlist[x]) && !file_exists(mlist[x]+".c"))
        {
            to_remove += ({mlist[x]});
            continue;
        }
        continue;
    }
    if(sizeof(to_remove))
    {
        mlist -= to_remove;
        MONSTER_LIST_BY_LEVEL[LevelList] = mlist;
        monster_list_save();
    }
    return mlist;
}

void verify_all_monsters()
{
    string *LList, *Lkeys, *remove_from_level;
    int x, y;
    object mon;
    if(!mapp(MONSTER_LIST_BY_LEVEL) || !sizeof(keys(MONSTER_LIST_BY_LEVEL))) init_monster_list_by_level();
    if(!pointerp(MONSTER_LIST)) MONSTER_LIST = ({});
    Lkeys = keys(MONSTER_LIST_BY_LEVEL);
    for(x = 0;x < sizeof(Lkeys);x++)
    {
        LList = MONSTER_LIST_BY_LEVEL[Lkeys[x]];
        if(!pointerp(LList) || !sizeof(LList)) continue;
        remove_from_level = ({});
        for(y = 0;y < sizeof(LList);y++)
        {
            if(!file_exists(LList[y]) && !file_exists(LList[y]+".c"))
            {
                remove_from_level += ({LList[y]});
                continue;
            }
            mon = new(LList[y]);
            if(!verify_valid_mon(mon, Lkeys[x]))
            {
                remove_from_level += ({LList[y]});
            }
            if(objectp(mon)) mon->remove();
            continue;
        }
        if(sizeof(remove_from_level))
        {
            LList -= remove_from_level;
            MONSTER_LIST_BY_LEVEL[Lkeys[x]] = LList;
            MONSTER_LIST -= remove_from_level;
        }
        continue;
    }
    monster_list_save();
    return;
}

void monster_list_save()
{
    seteuid(UID_ROOT);
    save_object(MONSTER_FILE);
    seteuid(geteuid());
}

void monster_list_restore()
{
    seteuid(UID_ROOT);
    restore_object(MONSTER_FILE);
    seteuid(geteuid());
}

void add_monster_quest(string quest)
{
    check_valid();
    if(member_array(quest, MONSTER_QUESTS) == -1)
    {
        MONSTER_QUESTS += ({quest});
        monster_list_save();
    }
    return;
}

void mass_monster_quests(string *queststoadd)
{
    check_valid();
    queststoadd -= MONSTER_QUESTS;
    if(sizeof(queststoadd))
    {
        MONSTER_QUESTS += queststoadd;
        monster_list_save();
    }
    return;
}

string *query_monster_quests()
{
    check_valid();
    return MONSTER_QUESTS;
}
