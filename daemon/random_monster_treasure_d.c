/*==============================================================================================================================================
Random Monster Treasure - Saide

Simply add set_property("treasure_type", LevelCat) on any item 
to have it show up in this treasure daemon - monsters will 
sometimes have treasure from this daemon

for example set_property("treasure_type", "5A") will have an object
show up sometimes on any monster level 1 - 5 with the treasure type A

treasure types on monsters are determined by their health - so a level 1 monster 
with very low health would theoretically potentially have some treasure
from any object with the above property set on it. 

It's also possible to do 
set_property("treasure level", x)
set_property("treasure type, A|B|C|D|E)
on a monster to manually set it to have x type of treasure

Hopefully this can eventually make it so that we have random treasure drops as opposed
to gear that only comes from x or y area. 

================================================================================================================================================*/

#include <std.h>
#include <daemons.h>
#include <security.h>

#define L5T "/daemon/rmt5_d"
#define L10T "/daemon/rmt10_d"
#define L15T "/daemon/rmt15_d"
#define L20T "/daemon/rmt20_d"
#define L25T "/daemon/rmt25_d"
#define L30T "/daemon/rmt30_d"
#define L35T "/daemon/rmt35_d"
#define L40T "/daemon/rmt40_d"

#define TREASURE_FILE "/daemon/save/random_monster_treasure"
#define VALID_TREASURE_TYPES ({"A", "B", "C", "D", "E"})
#define TREASURE_VALUES (["A" : 2, "B" : 4, "C" : 6, "D" : 8, "E" : 10])
#define MAX_TYPES (["E" : ({"A", "B", "C", "D", "E"}), "D" : ({"A", "B", "C", "D"}), "C" : ({"A", "B", "C"}), "B" : ({"A", "B"}), "A" : ({"A"}),])


#define ML5H 140
#define ML10H 280
#define ML15H 320
#define ML20H 600
#define ML25H 800
#define ML30H 1000
#define ML35H 1400
#define ML40H 2000
inherit DAEMON;
mapping TreasureMap;

void treasure_table_save();
void treasure_table_restore();
void BuildTreasureTable();
mapping queryTreasureMap();
int fix_level(int level);


void treasure_table_save()
{
    seteuid(UID_ROOT);
    save_object(TREASURE_FILE);
    seteuid(geteuid());    
}

void treasure_table_restore()
{
    seteuid(UID_ROOT);
    restore_object(TREASURE_FILE);
    seteuid(geteuid());    
}

void BuildTreasureTable()
{
    int x = 5;
    
    if(!mapp(TreasureMap)) 
    {
        if(file_exists(TREASURE_FILE + ".o")) treasure_table_restore();
    }
    if(!mapp(TreasureMap) || !sizeof(keys(TreasureMap)))
    {
        TreasureMap = ([]);
        while(x < 45)
        {
            TreasureMap += ([x : (["A": ({}), "B" : ({}), "C" : ({}), "D" : ({}), "E" : ({})]) ]);
            x+= 5;
        }        
    }
    treasure_table_save();
}

mapping queryTreasureMap() 
{ 
    BuildTreasureTable();
    return copy(TreasureMap);
}

int fix_level(int level)
{
    if(level >= 40) level = 40;
    else if(level >= 35) level = 35;
    else if(level >= 30) level = 30;
    else if(level >= 25) level = 25;
    else if(level >= 20) level = 20;
    else if(level >= 15) level = 15;
    else if(level >= 10) level = 10;
    else if(level >= 1) level = 5;
    else level = 0;
    return level;
}

void add_treasure(object ob)
{
    string *level_files, file, *lets, type;
    int x, level;
    
    if(!objectp(ob)) return;    
    type = ob->query_property("treasure_type");
    if(interactive(ob)) return;
    if(!stringp(type)) return;    
    lets = explode(type, "");
    if(sizeof(lets) < 2) return;
    for(x = 0;x < sizeof(lets);x++)
    {
        if(member_array(lets[x], VALID_TREASURE_TYPES) != -1) 
        {
            type = lets[x];
            break;
        }
    }   
    lets -= ({type});
    level = to_int(implode(lets, ""));
    
    if(!intp(level)) return;
    if(!level = fix_level(level)) return;
    
    if(member_array(type, VALID_TREASURE_TYPES) == -1) return;
    if(!mapp(TreasureMap)) BuildTreasureTable();
    if(living(ob)) return;
    if(!TreasureMap[level]) return;
    if(!TreasureMap[level][type]) return;
    
    level_files = TreasureMap[level][type];
    
    file = base_name(ob);
    if(strsrch(file, "/realms/") != -1) return;
    if(!stringp(file)) return;
    
    //it's already in the mapping
    if(member_array(file, level_files) != -1) return;
    level_files += ({file});
    //remove copies if they somehow exist
    level_files = distinct_array(level_files);
    
    TreasureMap[level][type] = level_files;
    treasure_table_save();
    return;    
}

mixed get_treasure(string type, int level)
{
    string file, *level_files, lvs, o_type, *types;
    object MyOb;
    int x, y, flag, o_level, val;
    mapping tmp;
    
    if(!stringp(type)) return;
    if(!intp(level)) return;
    o_level = level;
    o_type = type;
    level = random(level)+1;
    if(!o_level = fix_level(o_level)) return;
    if(!level = fix_level(level)) return;
    
    if(member_array(type, VALID_TREASURE_TYPES) == -1) return;
    if(!mapp(TreasureMap)) BuildTreasureTable();
    
    if(!random(3))
    {
        switch(o_level)
        {
            case 5: case 10: 
                MyOb = new("/d/common/obj/potion/healing.c");
                break;
            case 15: case 20:
                MyOb = new("/d/common/obj/potion/extra_heal.c");
                break;
            case 25: case 30:
                MyOb = new("/d/common/obj/potion/advanced_heal.c");
                break;
            case 35: case 40: case 45: case 50: case 55: case 60:
                MyOb = new("/d/common/obj/potion/legendary_heal.c");
                break;
        }
        val = TREASURE_VALUES[type];
        MyOb->set_uses((val/2) + random(val));
        tmp = (["object" : MyOb, "points" : val]);
        return tmp;
    }    
    
    if(!TreasureMap[level]) return;
    if(o_level == level || level >= o_level)
    {
        types = MAX_TYPES[o_type];
        type = types[random(sizeof(types))];
        val = TREASURE_VALUES[type];
    }
    else
    {
        types = VALID_TREASURE_TYPES;   
        type = types[random(sizeof(types))];
        val = (TREASURE_VALUES[type]/2);
    }
   
    if(!TreasureMap[level][type]) return;    
    level_files = TreasureMap[level][type];
    //tell_object("/std/user#6", "It is getting to this point");
    x = 2;
    //try 2 times to make an object - Saide
    //tell_object("/std/user#6", "val = "+val+" and type = "+type+" and level = "+level+" and level_files = "+identify(level_files));
    while(x--)
    {
        y = sizeof(level_files);
        if(!y) break;
        file = level_files[random(y)];
        
        if(!file_exists(file+".c") && !file_exists(file)) 
        {
            level_files -= ({file});
            flag = 1;
            continue;
        }
        
        if(catch(MyOb = new(file)))
        {
            //tell_object("/std/user#6", "Something is broke with the OBJECT");
            level_files -= ({file});
            flag = 1;
            continue;
        }
        //if(!objectp(targ)) return;
        break;
    }
    
    if(flag) treasure_table_save();
    if(objectp(MyOb)) 
    { 
        //tell_object("/std/user#6", "It should be an okay object....");
        tmp = (["object" : MyOb, "points" : val]);
        return tmp;
    }
    else return 0;
}

void assign_treasure(object ob)
{
    string type;
    int x, level, chance, failsafe;
    float myhp, max, perc;
    mixed MyOb;
    mapping tmp; 
    if(!objectp(ob)) return;    
  
    if(ob->query_property("has_random_treasure") || (int)ob->query_property("no random treasure")) return;
    ob->set_property("has_random_treasure", 1);    
    if(interactive(ob)) return;
    if(ob->query_property("minion")) return;
    
    if(living(ob)) 
    {
        if(ob->query_property("treasure level"))
        {
            level = ob->query_property("treasure level");
        }
        else level = ob->query_level();
        if(!intp(level)) return;
        if(!level = fix_level(level)) return;
        if(ob->query_property("treasure type")) type = ob->query_property("treasure type");
        else
        {
    
            switch(level) 
            {
                case 5:
                    max = to_float(ML5H);
                    break;
                case 10:
                    max = to_float(ML10H);
                    break;
                case 15:
                    max = to_float(ML15H);
                    break;
                case 20:
                    max = to_float(ML20H);
                    break;
                case 25:
                    max = to_float(ML25H);
                    break;
                case 30:
                    max = to_float(ML30H);
                    break;
                case 35:
                    max = to_float(ML35H);
                    break;
                case 40:
                    max = to_float(ML40H);
                    break;
                default:
                    max = to_float(ML5H);
                    break;
            }        
            myhp = to_float(ob->query_max_hp());
            perc = (myhp / max);
            if(perc >= 1) type = "E";
            else if(perc >= 0.80 && perc < 1) type = "D";
            else if(perc >= 0.60 && perc < 0.80) type = "C";
            else if(perc >= 0.40 && perc < 0.60) type = "B";
            else if(perc >= 0.00 && perc < 0.40) type = "A";
            else type = "A";
        }
    }
    else 
    {
        level = ob->query_property("treasure level");
        type = ob->query_property("treasure type");
        if(!intp(level)) return;
        if(!level = fix_level(level)) return;
    }    
    if(!stringp(type)) return;
    if(member_array(type, VALID_TREASURE_TYPES) == -1) return;
    if(!ob->query_property("treasure type")) ob->set_property("treasure type", type);
    if(!ob->query_property("treasure level")) ob->set_property("treasure level", level);
    
    switch(type)
    {
        case "A": 
            chance = 3;
            break;
        case "B":
            chance = 6;
            break;
        case "C":
            chance = 8;
            break;
        case "D":
            chance = 9;
            break;
        case "E":
            chance = 10;
            break;
        default:
            chance = 3;
    }
    x = TREASURE_VALUES[type];
    if(!intp(x)) x = 1;
    failsafe = 0;
    chance = WORLD_EVENTS_D->treasure_drop_rate_event(chance, ob);
    while(x)
    {
        tmp = ([]);
        failsafe++;
        x--;
        if(failsafe > 11) break;
        if(roll_dice(1, 100) > chance) continue;
        if(!mapp(tmp = get_treasure(type, level))) continue;
        if(!sizeof(keys(tmp))) continue;
        if(!objectp(MyOb = tmp["object"])) continue;
        MyOb->move(ob);
        if(tmp["points"]) x -= tmp["points"];
        if(x < 0) x = 0;
        continue;
    }
    return;    
}
