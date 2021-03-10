#include <std.h>
#include <daemons.h>
#include "/d/token_hunt/token_hunt.h"

inherit DAEMON;

#define SAVE_FILE   INV_PATH"directories"
#define POP_LOW     15
#define POP_MID     15
#define POP_HIGH    15
#define MON_FILE    FILE_PATH"token_monster"

int type_check(string type);
void clean_monsters();
int track_monster(string type,object mob);
object *query_monsters(string type);
string *monster_locations(string type);
int add_directory(string type,string dir);
string *query_directories(string type);
int add_excluded_room(string room);
int check_excluded(string room);
string select_room(string type);
void add_monsters(string type,int num);
void check_population();

mapping DIRS,PLAYER_TOKENS;
nosave mapping MONS;
string *EXCLUDED;

void create()
{
    mapping test;
    ::create();
    DIRS = ([]);
    MONS = ([]);
    EXCLUDED = ({});
    PLAYER_TOKENS = ([]);
    restore_object(SAVE_FILE);
}

int type_check(string type)
{
    if(!stringp(type) || type == " " || type == "") { return 0; }
    if(type != "low" && type != "mid" && type != "high") { return 0; }
    return 1;
}

void clean_monsters()
{
    int i;
    object *mons=({});

    if(!pointerp(MONS["low"])) { MONS["low"] = ({}); }
    if(!pointerp(MONS["mid"])) { MONS["mid"] = ({}); }
    if(!pointerp(MONS["high"])) { MONS["high"] = ({}); }
    mons = MONS["low"];
    mons = distinct_array(mons);
    if(sizeof(mons))
    {
        if(!objectp(mons[i])) { MONS["low"] -= ({ 0 }); }
    }

    mons = MONS["mid"];
    mons = distinct_array(mons);
    if(sizeof(mons))
    {
        if(!objectp(mons[i])) { MONS["mid"] -= ({ 0 }); }
    }

    mons = MONS["high"];
    mons = distinct_array(mons);
    if(sizeof(mons))
    {
        if(!objectp(mons[i])) { MONS["high"] -= ({ 0 }); }
    }
    return;
}

int track_monster(string type,object mob)
{
    if(!type_check(type)) { return 0; }
    if(!objectp(mob)) { return 0; }
    if(!pointerp(MONS[type])) { MONS[type] = ({}); }
    MONS[type] += ({ mob });
    return 1;
}

object *query_monsters(string type)
{
    if(!type_check(type)) { return ({}); }
    if(!pointerp(MONS[type])) { return ({}); }
    return MONS[type];
}

string *monster_locations(string type)
{
    object *monsters=({});
    string *locations=({}),short_desc;
    int i;

    if(!type_check(type)) { return ({}); }
    if(!pointerp(MONS[type])) { return ({}); }
    monsters = MONS[type];
    for(i=0;i<sizeof(monsters);i++)
    {
        if(!objectp(monsters[i])) { continue; }
        if(!objectp(environment(monsters[i]))) { continue; }
        short_desc = (string)environment(monsters[i])->query_short();
        if(!short_desc || short_desc == "" || short_desc == " ")
        {
            short_desc = "Unknown";
        }
        locations += ({ short_desc });
    }
    locations = distinct_array(locations);
    return locations;
}

string *true_locations(string type)
{
    object *mons;
    string *display=({});
    int i;

    if(!sizeof(mons=query_monsters(type))) { return ({}); }
    for(i=0;i<sizeof(mons);i++)
    {
        if(!objectp(mons[i])) { continue; }
        if(!objectp(environment(mons[i]))) { continue; }
        display += ({ ""+base_name(environment(mons[i]))+"" });
    }
    return display;
}

int add_directory(string type,string dir)
{
    if(!type_check(type)) { write("test 1");return 0; }
    if(!stringp(dir) || dir == " " || dir == "") { write("test 2");return 0; }
    if(!sizeof(get_dir(dir)) || sizeof(get_dir(dir)) == 1) { write("test 3");return 0; }

    if(!pointerp(DIRS[type])) { DIRS[type] = ({}); }
    DIRS[type] += ({ dir });
    save_object(SAVE_FILE);
    return 1;
}

int remove_directory(string type,string dir)
{
    if(!stringp(dir) || dir == " " || dir == "") { return 0; }
    DIRS[type] -= ({ dir });
    save_object(SAVE_FILE);
    return 1;
}

string *query_directories(string type)
{
    if(!type_check(type)) { return ([]); }
    if(!pointerp(DIRS[type])) { DIRS[type] = ({}); }
    return DIRS[type];
}

int add_excluded_room(string room)
{
    if(!stringp(room)) { return 0; }
    EXCLUDED += ({ room });
    save_object(SAVE_FILE);
    return 1;
}

int check_excluded(string room)
{
    if(!stringp(room)) { return 0; }
    if(member_array(room,EXCLUDED) == -1 && member_array(room+".c",EXCLUDED) == -1) { return 0; }
    return 1;
}

int filter_valid_rooms(string str)
{
    int length;
    string test;
    if(!stringp(str)) { return 0; }
    length = strlen(str);
    test = str[length-2..length];
    if(test == ".c") { return 1; }
    return 0;
}

string select_room(string type)
{
    object choice;
    string room,*dirs,*excluded,*rooms,dir;
    int i;

    if(!type_check(type)) { return "/d/shadowgate/void"; }

    if(!pointerp(DIRS[type]))
    {
        DIRS[type] = ({});
        return "/d/shadowgate/void";
    }
    dirs = DIRS[type];
    if(!sizeof(dirs)) { return "/d/shadowgate/void"; }

    while(!objectp(choice) && (i < 25))
    {
        i++;
        dir = dirs[random(sizeof(dirs))];
        rooms = get_dir(dir);
        if(!sizeof(rooms)) { continue; }
        rooms = filter_array(rooms,"filter_valid_rooms",TO);
        if(!sizeof(rooms)) { continue; }
        room = rooms[random(sizeof(rooms))];
        if(strsrch(room,".c") == -1) { continue; }
        room = ""+dir+""+room+"";
        if(!file_exists(room) && !file_exists(room+".c")) { continue; }
        if(check_excluded(room)) { continue; }
        choice = find_object_or_load(room);
        if(!objectp(choice)) { continue; }
    }
    return base_name(choice)+".c";
}

int is_token_monster(object ob)
{
    if(!objectp(ob)) { return 0; }
    if(!ob->id("token monster")) { return 0; }
    return 1;
}

void add_monsters(string type,int num)
{
    object mob,room_ob,*mobs=({});
    string room,party;
    int i,j,rand;

    party = "token_monster_party";



    for(i=0;i<num;i++)
    {
        room = select_room(type);
        room_ob = find_object_or_load(room);
        if(!objectp(room_ob)) { continue; }
        room_ob->set_had_players(2);
        if(!random(10))
        {
            rand = roll_dice(1,3);
            for(j=0;j<rand;j++)
            {
                mob = new(MON_FILE);
                mob->set_monster_level(type);
                //"/adm/daemon/party_d.c"->add_member(mob,party);
                mob->move(room_ob);
                if(objectp(mob)) { track_monster(type,mob); }
            }
        }
        mob = new(MON_FILE);
        mob->move(room_ob);
        if(objectp(mob))
        {
            mob->set_monster_level(type);
            //"/adm/daemon/party_d.c"->add_member(mob,party);
            track_monster(type,mob);
        }
    }

    if(rand)
    {
        mobs = all_living(room_ob);
        mobs = filter_array(mobs,"is_token_monster",TO);
        for(i=0;i<sizeof(mobs);i++)
        {
            if(!objectp(mobs[i])) { continue; }
            j = i + 1;
            if(j == sizeof(mobs)) { j = 0; }
            if(!objectp(mobs[j])) { continue; }
            if(j) { mobs[i]->add_follower(mobs[j]); }
            //mobs[j]->set_moving(0);
            //mobs[j]->set_speed(0);
            mobs[i]->add_protector(mobs[j]);
        }
    }
    return;
}

void check_population()
{
    int i,j,x;
    object *mobs=({});
    string *types = ({ "low","mid","high" });
    int *nums = ({ POP_LOW,POP_MID,POP_HIGH });

    string *dirs=({});
    if(!pointerp(DIRS["low"])) { return; }
    dirs = DIRS["low"];
    if(!sizeof(dirs)) { return; }
    if(!pointerp(DIRS["mid"])) { return; }
    dirs = DIRS["mid"];
    if(!sizeof(dirs)) { return; }
    if(!pointerp(DIRS["high"])) { return; }
    dirs = DIRS["high"];
    if(!sizeof(dirs)) { return; }

    for(i=0;i<sizeof(types);i++)
    {
        mobs = query_monsters(types[i]);
        if(!sizeof(mobs))
        {
            add_monsters(types[i],nums[i]);
        }
        for(j=0;j<sizeof(mobs);j++)
        {
            clean_monsters();
        }
        mobs = query_monsters(types[i]);
        add_monsters(types[i],(nums[i] - sizeof(mobs)));
    }
    return;
}

int clean_up() { return 1; }

void set_player_tokens(object player,mapping tokens)
{
    string name;
    if(!objectp(player)) { return; }
    if(!mapp(tokens)) { return; }
    if(!interactive(player)) { return; }
    name = player->query_true_name();
    if(!mapp(PLAYER_TOKENS)) { PLAYER_TOKENS = ([]); }
    PLAYER_TOKENS[name] = tokens;
    save_object(SAVE_FILE);
    return;
}

mapping get_player_tokens(string name)
{
    if(!stringp(name)) { return ([]); }
    if(!mapp(PLAYER_TOKENS)) { PLAYER_TOKENS = ([]); }
    if(!mapp(PLAYER_TOKENS[name])) { return ([]); }
    return PLAYER_TOKENS[name];
}
