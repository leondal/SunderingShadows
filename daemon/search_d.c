#include <std.h>
#include <daemons.h>
#include <security.h>
#include <move.h>

inherit DAEMON;

#include <components.h>

#define DEFAULT_CHANCE  ([ "mundane": 10,"misc": 10,"weapon": 10,"armor": 10,"jewelry": 10,"clothing": 10 ])
#define SAVE_FILE       "/daemon/save/search_treasures"
#define LOG_FILE        "search_daemon"

mapping __WeaponTable;
mapping __ArmorTable;
mapping __JewelryTable;
mapping __ClothingTable;
mapping __MiscTable;
mapping __MundaneTable;

mapping __AreaLevels;
mapping __ItemLevels;

string *__MiscItems;
string *__MundaneItems;
string *__Weapons;
string *__Armor;
string *__Jewelry;
string *__Clothing;

string *__Excluded;
string *__Special;


int exception_filter(string file_name);
int special_filter(string file_name);
mapping get_map(string type);
string *get_array(string type);
int remove_file_from_array(string type,string file_name);
string type_filter(mixed item);
int get_amount(mapping map,string file_name);
int get_item_level(string file_name);
int get_room_level(string file_name);
int set_item_level(string file_name,string what,int level,object player);
int set_level_by_object(object ob,int level,object player);
int get_min_level(string file_name,string type);
int add_object_to_list(string common_name,string file_name,string type,int amount,int level);
int add_object(object item);
int add_objects(object *items);
varargs int add_special_item(mixed item,string type);
varargs int add_excluded_item(mixed item,string type);
varargs int remove_excluded_item(mixed item,string type);
varargs int remove_special_item(mixed item,string type);
int change_item_type(mixed item,string old_type,string new_type);
int delete_item_from_table(mixed item,string type);
int change_item_level(mixed item,int level);
int change_item_amount(mixed item,int amount);
int get_item_amount(mixed item);
int name_exists(string name,string type,string file_name);
void change_item_name(string type,mixed item,string name);
varargs int is_item_locked(mixed item,string type);
varargs int lock_item(mixed item, string type);
varargs int unlock_item(mixed item, string type);
string sort_alpha(string one, string two);
void display_array(string which,object player);
void display_levels(string what,object player);
void display_table(string type,object player);
void clean_table(string type,string item);
string get_item_file(string type,string item);
string get_file_from_name(string name,string type);
string pick_file(string str,string *files);
int get_chance(int level,int amount);
string *search_table(string *tables,int area_level,int player_level);
varargs void do_search_func(object room,object player,mapping percents);
int wizard_spell_filter(string str);
object create_special_object(string file_name,object player);
void create_item(object player,string file_name);
void create_items(object player,string *items);
void SAVE();



void create()
{
    ::create();

    __WeaponTable    = ([]);
    __ArmorTable     = ([]);
    __JewelryTable   = ([]);
    __ClothingTable  = ([]);
    __MiscTable      = ([]);
    __MundaneTable   = ([]);
    __AreaLevels     = ([]);
    __ItemLevels     = ([]);
    __MiscItems      = ({});
    __MundaneItems   = ({});
    __Weapons        = ({});
    __Armor          = ({});
    __Jewelry        = ({});
    __Clothing       = ({});
    __Special        = ({});
    __Excluded       = ({});

    restore_object(SAVE_FILE);

}

int exception_filter(string file_name)
{
    if(!stringp(file_name)) { return 0; }
    if(!pointerp(__Excluded)) { return 1; }
    if(member_array(file_name,__Excluded) != -1) { return 0; }
    return 1;
}

int special_filter(string file_name)
{
    if(!stringp(file_name)) { return 0; }
    if(!pointerp(__Special)) { return 1; }
    if(member_array(file_name,__Special) != -1) { return 0; }
    return 1;
}

mapping get_map(string type)
{
    if(!stringp(type)) { return ([]); }
    switch(lower_case(type))
    {
    case "mundane":  return __MundaneTable;
    case "misc":     return __MiscTable;
    case "weapon":   return __WeaponTable;
    case "armor":    return __ArmorTable;
    case "jewelry":  return __JewelryTable;
    case "clothing": return __ClothingTable;
    default:         return notify_fail("Valid types are mundane, misc, weapon, armor, jewelry and clothing");
    }
    return 0;
}

string *get_array(string type)
{
    if(!stringp(type)) { return ({}); }
    switch(lower_case(type))
    {
    case "mundane":  return __MundaneItems;
    case "misc":     return __MiscItems;
    case "weapon":   return __Weapons;
    case "armor":    return __Armor;
    case "jewelry":  return __Jewelry;
    case "clothing": return __Clothing;
    default:         return notify_fail("Valid types are mundane, misc, weapon, armor, jewelry and clothing");
    }
    return 0;
}

int remove_file_from_array(string type,string file_name)
{
    if(!stringp(type))      { return 0; }
    if(!stringp(file_name)) { return 0; }
    switch(lower_case(type))
    {
    case "mundane":  __MundaneItems -= ({ file_name }); break;
    case "misc":     __MiscItems -= ({ file_name }); break;
    case "weapon":   __Weapons -= ({ file_name }); break;
    case "armor":    __Armor -= ({ file_name }); break;
    case "jewelry":  __Jewelry -= ({ file_name }); break;
    case "clothing": __Clothing -= ({ file_name }); break;
    case "special":  __Special -= ({ file_name }); break;
    case "excluded": __Excluded -= ({ file_name }); break;
    default:         return notify_fail("Valid types are mundane, misc, weapon, armor, jewelry and clothing");
    }
    SAVE();
    return 1;
}

string type_filter(mixed item)
{
    string file_name,type;
    if(objectp(item)) { file_name = base_name(item); }
    else if(stringp(item))
    {
        if(strsrch(item,"/") != -1) 
        { 
            if(!file_exists(item+".c")) { return 0; }
            else { file_name = item; }
        }
    }
    else { return 0; }

    if(member_array(file_name,__MiscItems) != -1)         { type = "misc"; }
    else if(member_array(file_name,__MundaneItems) != -1) { type = "mundane"; }
    else if(member_array(file_name,__Weapons) != -1)      { type = "weapon"; }
    else if(member_array(file_name,__Armor) != -1)        { type = "armor"; }
    else if(member_array(file_name,__Jewelry) != -1)      { type = "jewelry"; }
    else if(member_array(file_name,__Clothing) != -1)     { type = "clothing"; }
    else if(item->is_armor())                             { type = "armor"; }
    else if(item->is_weapon())                            { type = "weapon"; }
    else if(item->is_clothing())                          { type = "clothing"; }
    else if(item->is_jewelry())                           { type = "jewelry"; }
    else if(!item->query_property("magic"))               { type = "mundane"; }
    else                                                  { type = "misc"; }
    return type;
}

int get_amount(mapping map,string file_name)
{
    int amount;
    mapping tmp;
    if(!mapp(map))            { return 0; }
    if(!stringp(file_name))   { return 0; }
    if(!mapp(map[file_name])) { return 0; }
    tmp = map[file_name];
    amount = tmp["amount"];
    return amount;
}

int get_item_level(string file_name)
{
    string file,*areas=({}),*files=({});
    int num,i;
    if(!stringp(file_name)) { return 0; }
    num = strsrch(file_name,"/",-1);
    file = file_name[0..num];    
    areas = keys(__ItemLevels);
    if(sizeof(areas))
    {
        for(i=0;i<sizeof(areas);i++)
        {   
            files += ({ areas[i][0..num] });
        }
    }
    if(member_array(file,files) == -1) { return 1; }
    return to_int(__ItemLevels[file]);
}

int get_room_level(string file_name)
{
    string file,*areas=({}),*files=({});
    int num,i;
    if(!stringp(file_name)) { return 0; }
    num = strsrch(file_name,"/",-1);
    file = file_name[0..num];    
    areas = keys(__AreaLevels);
    if(sizeof(areas))
    {
        for(i=0;i<sizeof(areas);i++)
        {   
            files += ({ areas[i][0..num] });
        }
    }
    if(member_array(file,files) == -1) { return 1; }
    return to_int(__AreaLevels[file]);
}

int set_item_level(string file_name,string what,int level,object player)
{
    if(!stringp(file_name)) { return -1; }
    if(!intp(level))        { return -1; }
    if(!objectp(player))    { return -1; }
    if(!stringp(what))      { return -1; }
    log_file(LOG_FILE,""+capitalize((string)player->query_true_name())+" set "+file_name+" to level "+level+"\n");
    if(what == "room")      { __AreaLevels += ([ file_name : level ]); }
    else if(what == "item") { __ItemLevels += ([ file_name : level ]); }
    SAVE();
    return 1;
}

int set_level_by_object(object ob,int level,object player)
{    
    string file,what;
    int num;
    if(!objectp(ob))     { return 0; }
    if(!intp(level))     { return 0; }
    if(!objectp(player)) { return 0; }
    if(ob->is_room()) { what = "room"; }
    else { what = "item"; }
    file = base_name(ob);
    if(!stringp(file)) { return 0; }
    num = strsrch(file,"/",-1);
    file = file[0..num];
    set_item_level(file,what,level,player);
    return 1;
}

int get_min_level(string file_name,string type)
{
    mapping tmp,tmp2;
    int level;
    if(!stringp(file_name)) { return 0; }
    if(!stringp(type)) { return 0; }
    if(!mapp(tmp=get_map(type))) { return 0; }
    if(!mapp(tmp2=tmp[file_name])) { return 0; }
    level = tmp2["level"];
    return level;
}

int add_object_to_list(string common_name,string file_name,string type,int amount,int level)
{
    mapping tmp;
    int num;
    if(!stringp(common_name))        { return 0; }
    if(!stringp(file_name))          { return 0; }
    if(!file_exists(file_name+".c")) { return 0; }
    if(!stringp(type))               { return 0; }
    if(!intp(amount))                { return 0; }
    if(amount < 1)   { amount = 1; }
    if(amount > 99)  { amount = 99; }

    switch(type)
    {
    case "misc":
        if(num = get_amount(__MiscTable,file_name)) { amount += num; if(num < 1) { num = 1; } if(num > 99) { num = 99; } } 
        if(!mapp(tmp=__MiscTable[file_name]))
        {
            __MiscTable += ([ file_name : ([ "name" : common_name, "file" : file_name, "amount" : amount, "level" : level, "locked" : 0 ]), ]);
        }
        else { tmp["amount"] = amount; }
        __MiscItems += ({ file_name });
        __MiscItems = distinct_array(__MiscItems);
        break;
    case "mundane":
        if(num = get_amount(__MundaneTable,file_name)) { amount += num; if(num < 1) { num = 1; } if(num > 99) { num = 99; } } 
        if(!mapp(tmp=__MundaneTable[file_name]))
        {
            __MundaneTable += ([ file_name : ([ "name" : common_name, "file" : file_name, "amount" : amount, "level" : level, "locked" : 0 ]), ]);
        }
        else { tmp["amount"] = amount; }
        __MundaneItems += ({ file_name });
        __MundaneItems = distinct_array(__MundaneItems);
        break;
    case "weapon":
        if(num = get_amount(__WeaponTable,file_name)) { amount += num; if(num < 1) { num = 1; } if(num > 99) { num = 99; } } 
        if(!mapp(tmp=__WeaponTable[file_name]))
        {
            __WeaponTable += ([ file_name : ([ "name" : common_name, "file" : file_name, "amount" : amount, "level" : level, "locked" : 0 ]), ]);
        }
        else { tmp["amount"] = amount; }
        __Weapons += ({ file_name });
        __Weapons = distinct_array(__Weapons);
        break;
    case "armor":
        if(num = get_amount(__ArmorTable,file_name)) { amount += num; if(num < 1) { num = 1; } if(num > 99) { num = 99; } } 
        if(!mapp(tmp=__ArmorTable[file_name]))
        {
            __ArmorTable += ([ file_name : ([ "name" : common_name, "file" : file_name, "amount" : amount, "level" : level, "locked" : 0 ]), ]);
        }
        else { tmp["amount"] = amount; }
        __Armor += ({ file_name });
        __Armor = distinct_array(__Armor);
        break;
    case "jewelry":
        if(num = get_amount(__JewelryTable,file_name)) { amount += num; if(num < 1) { num = 1; } if(num > 99) { num = 99; } } 
        if(!mapp(tmp=__JewelryTable[file_name]))
        {
            __JewelryTable += ([ file_name : ([ "name" : common_name, "file" : file_name, "amount" : amount, "level" : level, "locked" : 0 ]), ]);
        }
        else { tmp["amount"] = amount; }
        __Jewelry += ({ file_name });
        __Jewelry = distinct_array(__Jewelry);
        break;
    case "clothing":
        if(num = get_amount(__ClothingTable,file_name)) { amount += num; if(num < 1) { num = 1; } if(num > 99) { num = 99; } } 
        if(!mapp(tmp=__ClothingTable[file_name]))
        {
            __ClothingTable += ([ file_name : ([ "name" : common_name, "file" : file_name, "amount" : amount, "level" : level, "locked" : 0 ]), ]);
        }
        else { tmp["amount"] = amount; }
        __Clothing += ({ file_name });
        __Clothing = distinct_array(__Clothing);
        break;
    default:
        return 0;
        break;
    }
    SAVE();
    return 1;
}

int add_object(object item)
{
    return 1;  //Disabling for now until I update the code -Ares
 /*   string type,file_name,common_name;
    int min_level;
    if(!objectp(item)) { return 0; }
    
    common_name = item->query("short");
    file_name = base_name(item);
    if(!exception_filter(file_name)) { return 0; }
    type = type_filter(item);
    min_level = (int)item->query_property("level");
    if(!min_level)
    {
        if(!min_level=get_min_level(file_name,type)) { min_level = get_item_level(file_name); }
    }
    if(add_object_to_list(common_name,file_name,type,1,min_level)) { return 1; }
    return 0;*/
}

int add_objects(object *items)
{
    int i;
    if(!pointerp(items)) { return 0; }
    for(i=0;i<sizeof(items);i++)
    {
        if(!objectp(items[i])) { continue; }
        add_object(items[i]);
    }
    return 1;
}

varargs int add_special_item(mixed item,string type)
{
    string file_name;
    if(objectp(item))
    {     
        file_name = base_name(item);
    }
    else if(stringp(item))
    {
        if(strsrch(item,"/") != -1)
        {
            if(!file_exists(item+".c"))         { return 0; }
            file_name = item;
        }
        else if(strsrch(item,"/") == -1 && stringp(type)) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
    }
    __Special += ({ file_name });
    SAVE();
    return 1;
}

varargs int add_excluded_item(mixed item,string type)
{
    string file_name;
    if(objectp(item))
    {     
        file_name = base_name(item);
    }
    if(stringp(item))
    {
        if(strsrch(item,"/") != -1)
        {
            if(!file_exists(item+".c"))         { return 0; }
            file_name = item;
        }
        else if(strsrch(item,"/") == -1 && stringp(type)) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
    }
    __Excluded += ({ file_name });
    SAVE();
    return 1;
}

varargs int remove_excluded_item(mixed item,string type)
{
    string file_name;
    if(objectp(item))
    {     
        file_name = base_name(item);
    }
    if(stringp(item))
    {
        if(strsrch(item,"/") != -1)
        {
            if(!file_exists(item+".c"))         { return 0; }
            file_name = item;
        }
        else if(strsrch(item,"/") == -1 && stringp(type)) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
    }
    if(member_array(file_name,__Excluded) == -1) { return 0; }
    __Excluded -= ({ file_name });
    SAVE();
    return 1;
}

varargs int remove_special_item(mixed item,string type)
{
    string file_name;
    if(objectp(item))
    {     
        file_name = base_name(item);
    }
    if(stringp(item))
    {
        if(strsrch(item,"/") != -1)
        {
            if(!file_exists(item+".c"))         { return 0; }
            file_name = item;
        }
        else if(strsrch(item,"/") == -1 && stringp(type)) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
    }
    if(member_array(file_name,__Special) == -1) { return 0; }
    __Special -= ({ file_name });
    SAVE();
    return 1;
}

int change_item_type(mixed item,string old_type,string new_type)
{
    string file_name,common_name;
    mapping tmp,tmp2;
    int amount,level;
    if(!stringp(old_type)) { return 0; }
    if(!stringp(new_type)) { return 0; }
    if(objectp(item))
    {     
        file_name = base_name(item);
    }
    if(stringp(item))
    {
        if(strsrch(item,"/") != -1)
        {
            if(!file_exists(item+".c"))         { return 0; }
            file_name = item;
        }
        else if(strsrch(item,"/") == -1) 
        { 
            if(!file_name=get_file_from_name(item,old_type)) { return 0; }
        }
    }

    if(!mapp(tmp=get_map(old_type))) { return 0; }
    if(!mapp(tmp2=tmp[file_name])) { return 0; }
    amount = tmp2["amount"];
    level = tmp2["level"];
    common_name = tmp2["name"];
    map_delete(tmp,file_name);
    remove_file_from_array(old_type,file_name);
    add_object_to_list(common_name,file_name,new_type,amount,level);
    return 0;
}

int delete_item_from_table(mixed item,string type)
{
    string file_name;
    mapping tmp,tmp2;
    if(!stringp(type)) { return 0; }
    if(objectp(item))
    {     
        file_name = base_name(item);
    }
    if(stringp(item))
    {
        if(strsrch(item,"/") != -1)
        {
            if(!file_exists(item+".c"))         { return 0; }
            file_name = item;
        }
        else if(strsrch(item,"/") == -1) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
    }
    if(!mapp(tmp=get_map(type))) { return 0; }
    if(!mapp(tmp2=tmp[file_name])) { return 0; }
    map_delete(tmp,file_name);
    remove_file_from_array(type,file_name);
    return 0;
}

int change_item_level(mixed item,int level)
{
    mapping tmp,tmp2;
    string file_name,type;
    if(!intp(level)) { return 0; }
    type = type_filter(item);    
    if(objectp(item)) { file_name = base_name(item); }
    if(stringp(item))
    {
        if(strsrch(item,"/") == -1) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
        else if(strsrch(item,"/") != -1) 
        { 
            if(!file_exists(item+".c")) { return 0; }
            else { file_name = item; }
        }
    }
    if(!mapp(tmp=get_map(type)))    { return 0; }
    if(!mapp(tmp2=tmp[file_name]))  { return 0; }
    tmp2["level"] = level;
    SAVE();
    return level;
}

int change_item_amount(mixed item,int amount)
{
    mapping tmp,tmp2;
    string file_name,type;
    if(!intp(amount)) { return 0; }
    type = type_filter(item);    
    if(objectp(item)) { file_name = base_name(item); }
    if(stringp(item))
    {
        if(strsrch(item,"/") == -1) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
        else if(strsrch(item,"/") != -1) 
        { 
            if(!file_exists(item+".c")) { return 0; }
            else { file_name = item; }
        }
    }
    if(!mapp(tmp=get_map(type)))    { return 0; }
    if(!mapp(tmp2=tmp[file_name]))  { return 0; }
    tmp2["amount"] += amount;
    SAVE();
    return amount;
}

int get_item_amount(mixed item)
{
    mapping tmp,tmp2;
    string file_name,type;
    type = type_filter(item);
    if(stringp(item))
    {
        if(strsrch(item,"/") != -1) 
        { 
            if(!file_exists(item+".c")) { return 0; }
            else { file_name = item; }
        }
    }
    if(!mapp(tmp=get_map(type)))    { return 0; }
    if(!mapp(tmp2=tmp[file_name]))  { return 0; }
    return tmp2["amount"];
}

int name_exists(string name,string type,string file_name)
{
    mapping tmp,tmp2;
    int i;
    string *info,*names=({});
    if(!stringp(name)) { return 0; }
    if(!stringp(type)) { return 0; }
    if(!mapp(tmp=get_map(type)))    { return 0; }
    if(!mapp(tmp2=tmp[file_name]))  { return 0; }
    info = keys(tmp);
    if(sizeof(info))
    {
        for(i=0;i<sizeof(info);i++)
        {
            names += ({ tmp[info[i]]["name"] });
        }
    }
    if(member_array(name,names) != -1)
    {
        write("That name already exists, choose another.");
        return 1;
    }
    return 0;
}
    
void change_item_name(string type,mixed item,string name)
{
    mapping tmp,tmp2;
    string file_name;
    int i;
    if(!stringp(name)) { return 0; }    
    if(objectp(item)) { file_name = base_name(item); }
    if(stringp(item))
    {
        if(strsrch(item,"/") == -1) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
        else if(strsrch(item,"/") != -1) 
        {         
            if(!file_exists(item+".c")) { return 0; }
            else { file_name = item; }
        }
    }
    if(name_exists(name,type,file_name)) { return 0; }
    if(!mapp(tmp=get_map(type)))         { return 0; }
    if(!mapp(tmp2=tmp[file_name]))       { return 0; }
    tmp2["name"] = name;
    SAVE();
    return;
}

varargs int is_item_locked(mixed item,string type)
{
    mapping tmp,tmp2;
    string file_name;
    int i;
    if(objectp(item)) { file_name = base_name(item); }
    if(stringp(item))
    {
        if(strsrch(item,"/") == -1) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
        else if(strsrch(item,"/") != -1) 
        {         
            if(!file_exists(item+".c")) { return 0; }
            else { file_name = item; }
        }
    }
    if(!mapp(tmp=get_map(type)))         { return 0; }
    if(!mapp(tmp2=tmp[file_name]))       { return 0; }
    if(tmp2["locked"] > 0);
    return 1;
}

varargs int lock_item(mixed item, string type)
{
    mapping tmp,tmp2;
    string file_name;
    int i;
    if(objectp(item)) { file_name = base_name(item); }
    if(stringp(item))
    {
        if(strsrch(item,"/") == -1) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
        else if(strsrch(item,"/") != -1) 
        {         
            if(!file_exists(item+".c")) { return 0; }
            else { file_name = item; }
        }
    }
    if(!mapp(tmp=get_map(type)))         { return 0; }
    if(!mapp(tmp2=tmp[file_name]))       { return 0; }
    tmp2["locked"] = 1;
    SAVE();
    return 1;
}

varargs int unlock_item(mixed item, string type)
{
    mapping tmp,tmp2;
    string file_name;
    int i;
    if(objectp(item)) { file_name = base_name(item); }
    if(stringp(item))
    {
        if(strsrch(item,"/") == -1) 
        { 
            if(!file_name=get_file_from_name(item,type)) { return 0; }
        }
        else if(strsrch(item,"/") != -1) 
        {         
            if(!file_exists(item+".c")) { return 0; }
            else { file_name = item; }
        }
    }
    if(!mapp(tmp=get_map(type)))         { return 0; }
    if(!mapp(tmp2=tmp[file_name]))       { return 0; }
    tmp2["locked"] = 0;
    SAVE();
    return 1;
}

string sort_alpha(string one, string two) 
{ 
    string tmp1,tmp2;
    one = FILTERS_D->filter_colors(one);
    two = FILTERS_D->filter_colors(two);
    tmp1 = one[6..28];
    tmp2 = two[6..28];
    if(strcmp(tmp1,tmp2) < 0)       { return -1; }
    else if(strcmp(tmp1,tmp2) == 0) { return 0; }
    else return 1;
}

void display_array(string which,object player)
{
    string *info,*display=({});
    int i;
    if(!stringp(which)) { return; }
    if(!objectp(player)) { return; }

    switch(lower_case(which))
    {
    case "misc":        info = __MiscItems;     break;
    case "mundane":     info = __MundaneItems;  break;
    case "weapon":      info = __Weapons;       break;
    case "armor":       info = __Armor;         break;
    case "jewelry":     info = __Jewelry;       break;
    case "clothing":    info = __Clothing;      break;
    case "excluded":    info = __Excluded;      break;
    case "special":     info = __Special;       break;
    default:            info = ({});            break;
    }
    for(i=0;i<sizeof(info);i++)
    {
        display += ({ "%^RESET%^       "+info[i]+"" });
    }
    display = sort_array(display,"sort_alpha",TO);

    tell_object(player,"\n%^BOLD%^%^BLUE%^-=-=-=%^RESET%^BOLD%^ File Name %^BOLD%^%^BLUE%^=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    player->more(display);
    return;
}

void display_levels(string what,object player)
{    
    string *info,*display=({});
    mapping tmp;
    int i;
    if(!objectp(player)) { return 0; }
    if(!stringp(what)) { return 0; }
    if(what == "room") { tmp = __AreaLevels; }
    else { tmp = __ItemLevels; }
    if(!mapp(tmp)) { return 0; }
    info = keys(tmp);
    for(i=0;i<sizeof(info);i++)
    {
        display += ({ "%^RESET%^%^CYAN%^  "+arrange_string(tmp[info[i]],4)+"%^RESET%^    "+info[i]+"" });
    }
    display = sort_array(display,"sort_alpha",TO);
       
    tell_object(player,"\n%^RESET%^%^BOLD%^Level %^BOLD%^%^BLUE%^-=-%^RESET%^%^BOLD%^ File Name %^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    player->more(display);
    return;
}

void display_table(string type,object player)
{
    string display,*files,*info=({});
    mapping tmp;
    int i;
    if(!stringp(type))              { return 0; }
    if(!objectp(player))            { return 0; }
    switch(type)
    {
    case "weapons": type = "weapon";    break;
    case "armors":  type = "armor";     break;
    case "clothes": type = "clothing";  break;
    case "other":   type = "mundane";   break;
    default:        type = type;        break;
    }
    if(!mapp(tmp=get_map(type)))    { return 0; }
    files = keys(tmp);
    if(!pointerp(files))            { return 0; }

    for(i=0;i<sizeof(files);i++)
    {
        if(tmp[files[i]]["locked"] == 0)
        {
            info += ({ "%^RESET%^%^CYAN%^ "+arrange_string(tmp[files[i]]["level"],3)+"%^RESET%^%^BOLD%^"+arrange_string(tmp[files[i]]["amount"],4)+"%^RESET%^"+arrange_string(tmp[files[i]]["name"],23)+""+tmp[files[i]]["file"]+"" });
        }
        else
        {
            info += ({ "%^RESET%^%^CYAN%^ "+arrange_string(tmp[files[i]]["level"],3)+"%^RESET%^%^BOLD%^%^RED%^"+arrange_string(tmp[files[i]]["amount"],4)+"%^RESET%^"+arrange_string(tmp[files[i]]["name"],23)+""+tmp[files[i]]["file"]+"" });
        }
    }    
    info = sort_array(info,"sort_alpha",TO);

    tell_object(player,"\n%^RESET%^%^BOLD%^Lvl Num Name %^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-%^RESET%^%^BOLD%^ File %^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    player->more(info);
    return;
}

void clean_table(string type,string item)
{
    mapping tmp;
    if(!mapp(tmp=get_map(type))) { return 0; }
    remove_file_from_array(type,item);
    map_delete(tmp,item);
    SAVE();
    return;
}
   
string get_item_file(string type,string item)
{
    mapping tmp,tmp2;
    string file_name;
    if(!stringp(type))   { return 0; }
    if(!stringp(item))   { return 0; }
    
    if(strsrch(item,"/") != -1)
    {
        file_name = item;  
    }
    if(strsrch(item,"/") == -1)
    {
        if(!file_name=get_file_from_name(item,type)) { return 0; }
    }

    if(!mapp(tmp=get_map(type))) { return 0; }
    if(!mapp(tmp2=tmp[file_name]))    { return 0; }        
    if(member_array(file_name,get_array(type)) != -1)
    {
        if(!file_exists(file_name+".c"))
        {
            clean_table(type,file_name);
        }
    }
    return file_name;
}

string get_file_from_name(string name,string type)
{
    mapping tmp,name_map=([]);
    string *info,*names,*files,*final_names=({}),*final_files=({});
    int i;
    if(!stringp(name)) { return 0; }
    if(!stringp(type)) { return 0; }
    if(!mapp(tmp=get_map(type))) { return 0; }
    name = lower_case(name);
    info = keys(tmp);
    if(sizeof(info))
    {
        for(i=0;i<sizeof(info);i++)
        {
            name_map += ([ tmp[info[i]]["file"] : tmp[info[i]]["name"] ]);
        }
    }
    names = values(name_map);
    files = keys(name_map);
    if(sizeof(names))
    {
        for(i=0;i<sizeof(names);i++)
        {
            tmp = lower_case(names[i]);
            tmp = FILTERS_D->filter_colors(tmp);
            if(name == tmp) 
            {
                final_names += ({ names[i] });
                final_files += ({ files[i] });
            }
        }
    }
    if(!sizeof(final_names)) { return -1; }
    if(sizeof(final_names) == 1) { return final_files[0]; }
    for(i=0;i<sizeof(final_names);i++)
    {
        if(i==0) { write(" 0 "+arrange_string(final_names[i],25)+" "+final_files[i]+""); }
        else { write(" "+arrange_string(i,2)+" "+arrange_string(final_names[i],25)+" "+final_files[i]+""); }
    }
    write("Enter the number of the item you wish to select.");
    write("Enter ** or a blank space to abort.");
    return input_to("pick_file",final_files);
}

string pick_file(string str,string *files)
{
    int num;
    if(!str)                                    { return 0; }
    if(!pointerp(files))                        { return 0; }
    if(str == "**" || str == "" || str == " ")  { return 0; }
    num = to_int(str);
    if(!intp(num)) { return 0; }
    return files[num];
}

int get_chance(int level,int amount)
{
    int chance;
    if(!intp(level)) { return 0; }
    if(!intp(amount)) { return 0; }
    switch(level)
    {
    case 0..5:
        chance = amount;
        if(chance > 35)      { chance = 35; }
        else if(chance < 10) { chance = 10; }
        break;
    case 6..10:
        chance = amount;
        if(chance > 30)      { chance = 30; }
        else if(chance < 10) { chance = 10; }
        break;
    case 11..15:
        chance = amount;
        if(chance > 25)      { chance = 25; }
        else if(chance < 5)  { chance = 5; }
        break;
     case 16..20:
        chance = amount;
        if(chance > 20)      { chance = 20; }
        else if(chance < 5)  { chance = 5;  }
        break;
    case 21..25:
        chance = amount;
        if(chance > 15)      { chance = 15; }
        else if(chance < 3)  { chance = 3;  }
        break;
    case 26..30:
        chance = amount;
        if(chance > 10)      { chance = 10; }
        else if(chance < 3)  { chance = 3;  }
        break;
    case 31..35:
        chance = amount;
        if(chance > 5)       { chance = 5; }
        else if(chance < 2)  { chance = 2; }
        break;
    case 36..40:
        chance = amount;
        if(chance > 3)       { chance = 3; }
        else if(chance < 2)  { chance = 2; }
        break;
    default:
        chance = amount;
        if(chance > 2)       { chance = 2;  }
        else if(chance < 1)  { chance = 1; }
        break;
    }
    return chance;
}

// Filters through the tables that passed the first check and then passes the items
// that aren't too high level along to make sure the chance to find them isn't too high.
string *search_table(string *tables,int area_level,int player_level)
{
    mapping tmp;
    int i,j,amount,chance,num,max;
    string *files,*items=({}),*types=({}),*stuff=({});
    if(!pointerp(tables))   { return 0; }
    if(!intp(area_level))   { return 0; }
    if(!intp(player_level)) { return 0; }
    max = player_level - area_level;
    if(max < 1) { max = 1; }
    if(max > 5) { max = 5; }

    for(i=0;i<sizeof(tables);i++)
    {
        if(!tmp=get_map(tables[i])) { continue; }
        files = keys(tmp);
        for(j=0;j<sizeof(tmp);j++)
        {
            num = tmp[files[j]]["level"];
            amount = tmp[files[j]]["amount"];
            if(num > area_level) { continue; }
            if(num > player_level) { continue; }
            chance = get_chance(num,amount);
            if(chance < roll_dice(1,100)) { continue; }
            items += ({ files[j] });
            types += ({ tables[i] });
        }
    }
    if(sizeof(items))
    {
        for(i=0;i<sizeof(items);i++)
        {
            stuff += ({ get_item_file(types[i],items[i]) });
        }
    }
    if(sizeof(stuff) > max)
    {
        items = stuff;
        stuff = ({});
        while(max)
        {
            i = random(sizeof(items));
            stuff += ({ items[i] });
            items -= ({ items[i] });
            max--;
        }
    }
    for(i=0;i<sizeof(stuff);i++)
    {
        if(get_item_amount(stuff[i]) > 1)
        {
            change_item_amount(stuff[i],-1);
        }
    }
    return stuff;            
}

// Defaults to 1 out of 10 chance to get to roll on the item table.  This can be adjusted
// with the percents mapping.  If they get to roll, then each table is looped through to find
// items that are below both the area level for the area, and the players level.  
// level 0-5        40% of amount, max of 35% min of 10%  total adjusted max 35 out of 1000
// level 5-10       30% of amount, max of 30% min of 10%  total adjusted max 30 out of 1000
// level 10-15      10% of amount, max of 25% min of 5%   total adjusted max 25 out of 1000
// level 15-20       6% of amount, max of 20% min of 5%   total adjusted max 20 out of 1000
// level 20-25       5% of amount, max of 15% min of 3%   total adjusted max 15 out of 1000
// level 25-30       4% of amount, max of 10% min of 3%   total adjusted max 10 out of 1000
// level 30-35       3% of amount, max of 5%  min of 2%   total adjusted max 5  out of 1000
// level 35-40       2% of amount, max of 3%  min of 2%   total adjusted max 3  out of 1000
// level 40+         1% of amount, max of 2%  min of 1%   total adjusted max 2  out of 1000
varargs int do_search_func(object room,object player,mapping percents)
{
    int player_level, area_level,i;
    string room_file,*chance,*which=({}),*found;
    if(!objectp(room)) { return 0; }
    if(!objectp(player)) { return 0; }
    if(!mapp(percents)) { percents = DEFAULT_CHANCE; }
    chance = keys(percents);
    if(sizeof(chance))
    {
        for(i=0;i<sizeof(chance);i++)
        {
            if(roll_dice(1,100) > (int)percents[chance[i]]) { continue; }
            which += ({ chance[i] });
        }
    }
    if(!sizeof(which)) { return 0; } 
    player_level = (int)player->query_level();
    room_file = base_name(room);
    area_level = get_room_level(room_file);
    found = search_table(which,area_level,player_level);
    if(!sizeof(found)) { return 0; }
    create_items(player,found);
    return 1;
}

// only returns things in the directory with _ as first character and
// nothing after the .c..  ie .bak
int wizard_spell_filter(string str)
{
    int length;
    if(!stringp(str)) { return 0; }
    if(strsrch(str,"_") != 0) { return 0; }
    length = strsrch(str,".c");
    if(length == -1) { return 0; }
    str = replace_string(str,".c","");
    if(strlen(str) != length) { return 0; }
    return 1;
}

object create_special_object(string file_name,object player)
{
    object obj;
    string *info,name;
    int i,amount;
    if(!stringp(file_name)) { return 0; }
    if(!objectp(player))    { return 0; }
    file_name = replace_string(file_name,".c","");

    switch(file_name)
    {
    case "/d/common/obj/potion/healing":
        obj = new("/d/common/obj/potion/healing");
        obj->set_uses(roll_dice(1,12));
        return obj;
    case "/d/common/obj/potion/extra_heal":
        obj = new("/d/common/obj/potion/extra_heal");
        obj->set_uses(roll_dice(1,12));
        return obj;
    case "/d/magic/store_comp":
        obj = new("/d/magic/store_comp");
        info = keys(COMPONENTS);
        name = info[random(sizeof(info))];
        amount = roll_dice(1,12);
        obj->set_name(name);
        obj->set_id(({name,"component"}));
        obj->set_short(capitalize(name)+" (a spell component)");
        obj->set_long("             " + amount + " " +capitalize(name)+""
            ". \n" + obj->query_long());
        obj->set_comp_quantity(to_int(amount));
        return obj;
    case "/d/magic/safe_scroll":
        obj = new("/d/magic/safe_scroll");
        info = get_dir("/cmds/wizard/");
        info = filter_array(info,"wizard_spell_filter",TO);
        name = info[random(sizeof(info))];
        name = replace_string(name,".c","");
        name = replace_string(name,"_","",1);
        name = replace_string(name,"_"," ");
        obj->set_spell_name(name);
        return obj;
    case "/d/magic/scribed_scroll":
        obj = new("/d/magic/scribed_scroll");
        info = get_dir("/cmds/wizard/");
        info = filter_array(info,"wizard_spell_filter",TO);
        name = info[random(sizeof(info))];
        name = replace_string(name,".c","");
        name = replace_string(name,"_","",1);
        name = replace_string(name,"_"," ");
        obj->set_spell_name(name);
        return obj;
    case "/d/magic/scroll":
        obj = new("/d/magic/scroll");
        info = get_dir("/cmds/wizard/");
        info = filter_array(info,"wizard_spell_filter",TO);
        name = info[random(sizeof(info))];
        name = replace_string(name,".c","");
        name = replace_string(name,"_","",1);
        name = replace_string(name,"_"," ");
        obj->set_spell_name(name);
        return obj;
    default:
        break;
    }
    return 0;
}

void create_item(object player,string file_name)
{
    object obj;
    if(!objectp(player))                { return; }
    if(!stringp(file_name))             { return; }
    if(!objectp(environment(player)))   { return; }
    if(!file_exists(file_name+".c"))    { return; }
    if(pointerp(__Special) && member_array(file_name,__Special) != -1)
    {
        obj=create_special_object(file_name,player);
    }
    else { obj = new(file_name); }
    obj->move(environment(player));
    return;
}
 
void create_items(object player,string *items)
{
    int i;
    if(!objectp(player)) { return; }
    if(!pointerp(items)) { return; }
    for(i=0;i<sizeof(items);i++)
    {
        if(!file_exists(items[i]+".c")) { continue; }
        create_item(player,items[i]);
    }
    return;
}

void SAVE()
{
    seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
    seteuid(getuid());
    return;
}

