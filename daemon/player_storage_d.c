//ACTIVELY USED

/* /daemon/player_storage_d.c
daemon for handling gear stored by players.  The environment of the player while
they are using the functions for the daemon is used to determine where the location
of the storage lockers are since there can be multiple lockers in different places
tracked with the daemon.  So you'll have to make sure a storage room is empty before
you move the file, else nobody will be able to retrieve items from that storage room

created 01/27/2010 -Ares
*/

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <move.h>

inherit DAEMON;

#define BREAK "%^RESET%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- %^RESET%^"

#define SAVE_FILE "/daemon/save/player_storage"
#define SAVE_PATH "/d/save/player_storage/"
#define QTN       query_true_name()

#define MAX_COST  500000
#define MIN_COST  10000

mapping __SavedInfo;
mapping __FailedStealing;
mapping __Members;

int member_check(object player);
int add_member(object room,string player);
int remove_member(object room,string player);
int check_stealing(object player,string person,string location);
int steal_object(object player,object tools);
varargs int store_object(object player,object obj,int free);
int confirm_retrieve(string str,object obj,string file,string short);
int retrieve_object(object obj,string str);
varargs void display_player_items(mixed player,object tp);
int price_check(object player,object obj);
int buy_storage(object player,int cost);
string build_file_name(object player);
int HOSTILE_RESTORE(object player,string targ,string file,string location);
int RESTORE_OBJECT(object player,string file,string location);
string SAVE_OBJECT(object player,object obj,string location);
string PLAYER_PATH(object player); 
void SAVE();


void create()
{
    ::create();

    __SavedInfo      = ([]);
    __FailedStealing = ([]);
    __Members        = ([]);
  
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());  
}

int member_check(object player)
{
    string *members,place,name;
    
    if(!objectp(player)) { return 0; }
    if(!objectp(environment(player))) { return 0; }

    place = base_name(environment(player));
    name = player->QTN;

    if(!mapp(__Members)) { __Members = ([]); }
    if(!pointerp(__Members[place]) || !sizeof(__Members[place])) 
    { 
        tell_object(player,"You aren't allowed to use the storage boxes here.");
        return 0; 
    }
    members = __Members[place];

    if(member_array(name,members) == -1) 
    { 
        tell_object(player,"You aren't allowed to use the storage boxes here.");
        return 0; 
    }
    return 1;
}

int add_member(object room,string player)
{
    string place;

    if(!stringp(player) || !user_exists(player)) { return 0; }
    if(!objectp(room)) { return 0; }

    place = base_name(room);

    if(!mapp(__Members)) { __Members = ([]); }
    if(!pointerp(__Members[place])) { __Members[place] = ({}); }
    __Members[place] += ({ player });
    __Members[place] = distinct_array(__Members[place]);
    SAVE();
    return 1;
}

int remove_member(object room,string player)
{
    string place;

    if(!stringp(player)) { return 0; }
    if(!objectp(room)) { return 0; }

    place = base_name(room);

    if(!mapp(__Members)) { return 0; }
    if(!pointerp(__Members[place])) { return 0; }
    if(member_array(player,__Members[place]) == -1) { return 0; }
    __Members[place] -= ({ player });
    __Members[place] = distinct_array(__Members[place]);
    SAVE();
    return 1;
}

int check_stealing(object player,string person,string location)
{
    string name;

    if(!objectp(player)) { return 0; }
    if(!stringp(person) || person == "" || person == " ") { return 0; }
    if(!stringp(location) || location == "" || location == " ") { return 0; }

    if(!sizeof(__FailedStealing)) { return 1; }
    name = player->QTN;
    if(!mapp(__FailedStealing[name])) { return 1; }
    if(!mapp(__FailedStealing[name][location])) { return 1; }
    if(__FailedStealing[name][location][person])
    {
        if(__FailedStealing[name][location][person] < time()) { return 1; }
    }
    return 0;
}

int steal_object(object player,object tools)
{
    mapping boxes=([]),tmp,map;
    string place,*people,*possible=({}),person,file,*items;
    int i,j,num,skill,targ_lvl,lvl,DC;

    if(!objectp(player)) { return 0; }
    if(!userp(player)) { return 0; }
    if(!objectp(tools))
    {
        tell_object(player,"You're going to need something to pick the "
            "lock with.");
        return 1;
    }

    place = base_name(environment(player));

    people = keys(__SavedInfo);

    if(!sizeof(people))
    {
        tell_object(player,"It seems like everything is empty, there's nothing "
            "to steal!");
        return 1;
    }

    for(i=0;i<sizeof(people);i++)
    {
        tmp = __SavedInfo[people[i]]["stored"];

        items = keys(tmp);

        if(!sizeof(items)) { continue; }

        for(j=0;j<sizeof(items);j++)
        {
            if(tmp[items[j]]["location"] != place) { continue; }
            if(!mapp(boxes[people[i]])) { boxes[people[i]] = ([]); }
            boxes[people[i]] += ([ tmp[items[j]]["file"] : tmp[items[j]] ]);
        }
    }

    if(!sizeof(boxes))
    {
        tell_object(player,"It seems like everything is empty, there's nothing "
            "to steal!");
        return 1;
    }

    people = keys(boxes);

    // can only try to steal from each person at a vault once per day 
    for(i=0;i<sizeof(people);i++)
    {
        if(!check_stealing(player,people[i],place)) { continue; }
        if(people[i] == (string)player->QTN) { continue; }
        possible += ({ people[i] });
    }

    if(!sizeof(possible))
    {
        tell_object(player,"The locks must all be jammed, you're going to have "
            "to wait for the owners to fix them before you'll ever be able to "
            "get your tools to work in them again!");
        return 1;
    }

    person = possible[random(sizeof(possible))];
    while(!user_exists(person) && (num < sizeof(possible)))
    {
        person = possible[random(sizeof(possible))];
        num++;
    }
    if(!user_exists(person))
    {
        tell_object(player,"It seems like everything is empty, there's nothing "
            "to steal!");
        return 1;
    }

    if(objectp(find_player(person))) { targ_lvl = (int)find_player(person)->query_base_character_level(); }
    else { targ_lvl = "/adm/daemon/user_call.c"->user_call(person,"query_base_character_level"); }
    skill = player->query_skill("dungeoneering");

    DC += targ_lvl + roll_dice(1,20) + (targ_lvl/10);

    if(!mapp(__FailedStealing[player->QTN])) 
    { 
        __FailedStealing[player->QTN] = ([]); 
        SAVE();
    }
    if(!mapp(__FailedStealing[player->QTN][place])) 
    { 
        __FailedStealing[player->QTN][place] = ([]); 
        SAVE();
    }

    if((skill + roll_dice(1,20)) < DC)
    {
        __FailedStealing[player->QTN][place] += ([ person : (time() + 86400) ]);
        SAVE();
        if(objectp(tools))
        {
            tell_object(player,"You break your tools!");
            tools->break_picks();
        }
        tell_object(player,"The lock jams!");
        return 1;
    }

    if(!sizeof(boxes[person]))
    {
        __FailedStealing[player->QTN][place] += ([ person : (time() + 86400) ]);
        SAVE();
        tell_object(player,"You open the lock but there is nothing inside, damn!");
        return 1;
    }

    items = keys(boxes[person]);
    file = items[random(sizeof(items))];

    if(HOSTILE_RESTORE(player,person,file,place))
    {
        __FailedStealing[player->QTN][place] += ([ person : (time() + 86400) ]);
        SAVE();
        tell_object(player,"You open the lock and find something inside!");
        return 1;
    }

    tell_object(player,"You open the lock but there is nothing inside, damn!");
    return 1;
}

varargs int store_object(object player,object obj,int free)
{
    string name,file,short,*ids,path,*items;
    mapping info;
    int price,vault_size,stored;

    if(!objectp(player)) { return 0; }
    if(!objectp(obj))    { return 0; }
    if(!objectp(environment(player))) { return 0; }
    if(!member_check(player)) { return 0; }
    if(obj->is_container())
    {
        tell_object(player,"You can't put a container into storage.");
        return 0;
    }

    name = player->QTN;
    if(!mapp(__SavedInfo[name])) 
    { 
        __SavedInfo[name] = ([ "name" : name, "stored" : ([]), ]);
    }

    info = __SavedInfo[name];

    if(!sizeof(keys(info["stored"]))) { stored = 0; }
    else { stored = sizeof(keys(info["stored"])); }
    vault_size = (int)environment(player)->query_property("vault size");
    path = base_name(obj);
    short = obj->query_short();
    ids = obj->query_id();
    if(obj->query_worn() || obj->query_wielded())
    {
        tell_object(player,"You can't put something into storage if you're wearing "
            "or wielding it.");
        return 1;
    }

    if(stored >= vault_size)
    {
        tell_object(player,"You already have "+stored+" items stored here, "+vault_size+" "
            "is the maximum you are allowed at this location.");
        return 1;
    }

    if(!free)
    {
        price = price_check(player,obj);
        if(!buy_storage(player,price))
        {
            tell_object(player,"You can't afford to store your "+obj->query_short()+", it would "
                "cost "+price+" gold coins.");
            return 0;
        }
        else
        {
            tell_object(player,"You pay "+price+" gold coins to put your "
                ""+obj->query_short()+" into storage.");
        }
    }

    if(!file=SAVE_OBJECT(player,obj,base_name(environment(player))))
    {
        tell_object(player,"Error saving!");
        return 0;
    }


    info["stored"] += ([ file : ([ "file" : file, 
                                   "path" : path, 
                                   "short" : short, 
                                   "ids" : ids,
                                   "time" : time(), 
                                   "location" : base_name(environment(player)),
                                   "free" : free,]),  ]);
    SAVE();
    return 1;
}

int confirm_retrieve(string str,object obj,string file,string short)
{
    if(!objectp(obj)) { return 1; }
    if(!stringp(file)) { return 1; }
    if(!objectp(environment(obj))) { return 1; }

    if(!str || str != "yes")
    {
        tell_object(obj,"%^RESET%^%^BOLD%^Aborting...%^RESET%^");
        return 1;
    }

    if(RESTORE_OBJECT(obj,file,base_name(environment(obj))))
    {
        tell_object(obj,"%^RESET%^%^BOLD%^You take your "+short+" out of storage.%^RESET%^");
        return 1;
    }

    tell_object(obj,"%^RESET%^%^BOLD%^Your "+short+" seems to be missing from the "
        "storage locker!%^RESET%^");
    return 1;
}

int retrieve_object(object obj,string str)
{
    mapping map,id_list=([]);
    string name,*items,*ids;
    int i,j,num=1;

    if(!objectp(obj)) { return 0; }
    if(!objectp(environment(obj))) { return 1; }
    if(!member_check(obj)) { return 1; }

    name = obj->QTN;
    map = __SavedInfo[name]["stored"];

    if(!map || !sizeof(map)) { return 1; }

    items = keys(map);

    for(i=0;i<sizeof(items);i++)
    {
        if(!pointerp(map[items[i]]["ids"]) || !sizeof(map[items[i]]["ids"])) { continue; }        
        ids = map[items[i]]["ids"];
        for(j=0;j<sizeof(ids);j++)
        {
            if(strsrch(str,ids[j]) == -1) { continue; }
            if(num == 1) { id_list += ([ ids[j] : map[items[i]]["file"], ]); }
            else { id_list += ([ ""+ids[j]+" "+num+"" : map[items[i]]["file"], ]); }
            num ++;
        }
    }

    if(!sizeof(id_list))
    {
        tell_object(obj,"%^RESET%^%^BOLD%^You don't seem to have a "+str+" stored here.%^RESET%^");
        return 1;
    }

    items = keys(id_list);

    if(member_array(str,items) == -1)
    {
        tell_object(obj,"%^RESET%^%^BOLD%^You don't seem to have a "+str+" stored here.%^RESET%^");
        return 1;
    }

    tell_object(obj,"%^RESET%^%^BOLD%^Take "+map[id_list[str]]["short"]+" out of storage?\nenter yes to "
        "confirm, anything else to abort.%^RESET%^");
    input_to("confirm_retrieve",obj,map[id_list[str]]["file"],map[id_list[str]]["short"]);
    return 1;
}

varargs void display_player_items(mixed player,object tp)
{
    object ob;
    string name,room,*items,display="";
    mapping info;
    int i;

    if(objectp(player)) 
    { 
        ob = player;
        if(!member_check(ob)) { return; }
        name = player->QTN;
        room = base_name(environment(player));
    }
    else if(objectp(tp))
    { 
        ob = tp;
        if(player) { name = lower_case(player); }
    }

    if(!name || name == "" || name == " ") { return; }

    if(!mapp(__SavedInfo[name]) || !sizeof(__SavedInfo[name]))
    {
        tell_object(ob,""+name+" has no items in storage.");
        return;
    }

    info = __SavedInfo[name]["stored"];

    if(!info || !sizeof(info))
    {
        tell_object(ob,""+name+" has no items in storage");
        return;
    }

    items = keys(info);

    if(room)
    {
        display += "%^MAGENTA%^You have the following objects stored at "+room->query_short()+"\n";
    }

    display += BREAK+"\n";

    for(i=0;i<sizeof(items);i++)
    {
        if(room)
        {
            if(info[items[i]]["location"] != room) { continue; }
        }
        display += "\t "+info[items[i]]["short"]+"\n";
    }

    display += "\n"+BREAK+"\n";

    tell_object(ob,display);
    return;
}

int price_check(object player,object obj)
{
    int value,enchantment,price;

    if(!objectp(player)) { return 0; }
    if(!objectp(obj)) { return 0; }
    if(!member_check(player)) { return 0; }

    value = (int)obj->query_value();
    enchantment = absolute_value((int)obj->query_property("enchantment"));

    price = value * enchantment;
    if(price < MIN_COST) { price = MIN_COST; }
    if(price > MAX_COST) { price = MAX_COST; }

    return price;
}

int buy_storage(object player,int cost)
{
    if(!objectp(player)) { return 0; }
    if((int)player->query_gold_equiv() < cost) { return 0; }
    player->use_funds("gold",cost);
    return 1;
}


string build_file_name(object player)
{
    string *files;
    int i;

    if(!objectp(player)) { return 0; }

    files = get_dir(PLAYER_PATH(player));
    if(!sizeof(files)) { return "ob0"; }
    for(i=0;i<sizeof(files);i++)
    {
        if(!file_exists(PLAYER_PATH(player)+"ob"+i+".o")) { return "ob"+i+""; }
    }
    return "ob"+( sizeof(files))+"";    
}

int HOSTILE_RESTORE(object player,string targ,string file,string location)
{
    mapping info;
    object obj;
    string path,dir;
    if(!objectp(player)) { return 0; }
    if(!stringp(targ)) { return 0; }
    if(!stringp(file)) { return 0; }
    if(!stringp(location)) { return 0; }

    info = __SavedInfo[targ];

    dir = SAVE_PATH+""+targ+"/"+file+".o";
    if(!file_exists(dir))   { return 0; }
    path = read_file(dir,1,1);
    path = replace_string(path,"\n","");
    path = replace_string(path,"#","/");    
    if(!file_exists(path))  { return 0; }
    obj = new(path);
    if(!objectp(obj))       { return 0; }
    log_file("player_storage",""+player->QTN+" stole "+base_name(obj)+" from "+targ+"'s "
        "storage vault at "+location+" "+ctime(time())+"\n");
    map_delete(info["stored"],file);
    obj->restore_me(replace_string(dir,".o",""));
    if(obj->move(player) != MOVE_OK)
    {
        tell_object(player,"You drop it as fast as you get it!");
        obj->move(environment(player));
    }
    rm(dir);
    SAVE();
    return 1;
}

int RESTORE_OBJECT(object player,string file,string location)
{
    mapping info;
    object obj;
    string path,dir;
    if(!stringp(file))      { return 0; }
    if(!objectp(player))    { return 0; }
    if(!stringp(location))  { return 0; }

    info = __SavedInfo[player->QTN];

    dir = PLAYER_PATH(player)+file+".o";
    if(!file_exists(dir))   { return 0; }
    path = read_file(dir,1,1);
    path = replace_string(path,"\n","");
    path = replace_string(path,"#","/");    
    if(!file_exists(path))  { return 0; }
    obj = new(path);
    if(!objectp(obj))       { return 0; }
    map_delete(info["stored"],file);
    log_file("player_storage",""+player->QTN+"'s "+base_name(obj)+" was restored "
        "at "+location+" on "+ctime(time())+"\n");
    obj->restore_me(replace_string(dir,".o",""));
    if(obj->move(player) != MOVE_OK)
    {
        tell_object(player,"You drop it as fast as you get it!");
        obj->move(environment(player));
    }
    rm(dir);
    SAVE();
    return 1;
}

string SAVE_OBJECT(object player,object obj,string location)
{
    string file;
    if(!objectp(player))    { return 0; }
    if(!objectp(obj))       { return 0; }
    if(!stringp(location))  { return 0; }
    if(!get_dir(PLAYER_PATH(player))) { mkdir(PLAYER_PATH(player)); }
    file = build_file_name(player);
    obj->save_me(PLAYER_PATH(player)+file);
    log_file("player_storage",""+player->QTN+"'s "+base_name(obj)+" was stored at "+location+" "
        "on "+ctime(time())+"\n");
    obj->move("/d/shadowgate/void");
    obj->remove();
    SAVE();
    return file;    
}

string PLAYER_PATH(object player)
{
    string path;
    if(!objectp(player)) { return 0; }
    path = SAVE_PATH+""+player->QTN+"/";
    return path;
}
    
void SAVE()
{
    seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
    seteuid(getuid());
    return;
}

int clean_up() { return 1; }