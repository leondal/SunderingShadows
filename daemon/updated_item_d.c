/*==============================================================================================================================================
A daemon to keep up with items that have been updated. 

Add an item to the daemon via iupdate command

keeps up with the file name of the item and the time that it was updated, if a copy is loaded with the inventory daemon (yuck_d)
after that time, check the item update on the item, if it's less than the time the item was updated, then 
replace the loaded item with a new version 

Saide - April 2017

================================================================================================================================================*/

#include <std.h>
#include <daemons.h>
#include <security.h>
#define UPDATED_ITEMS_SAVE "/daemon/save/updated_items_list"
inherit DAEMON;

mapping UPDATED_ITEMS;
void updated_items_save()
{
    seteuid(UID_ROOT);
    save_object(UPDATED_ITEMS_SAVE);
    seteuid(geteuid());    
}

void updated_items_restore()
{
    seteuid(UID_ROOT);
    restore_object(UPDATED_ITEMS_SAVE);
    seteuid(geteuid());    
}

void verify_updated_items_mapp()
{
    if(!mapp(UPDATED_ITEMS)) updated_items_restore();
    if(!mapp(UPDATED_ITEMS)) 
    {
        UPDATED_ITEMS = ([]);
    }
    return;
}

void create()
{
    verify_updated_items_mapp();
    return;
}

int check_update(object ob)
{
    int last_update, item_updated;
    string target_file, *updated_files_list;
    if(!objectp(ob)) return 0;
    verify_updated_items_mapp();
    target_file = base_name(ob);
    if(!sizeof(updated_files_list = keys(UPDATED_ITEMS)) ||
    member_array(target_file, updated_files_list) == -1) return 0;
    last_update = UPDATED_ITEMS[target_file];
    if(ob->query("player enchanted")) return 0;
    if(ob->query("updated time") > last_update || intp(item_updated = ob->query_updated_time()) && item_updated > last_update) return 0;
    else return 1;    
    return 0;
}

void register_item_for_update(object ob, object who)
{
    int last_update;
    string target_file, *updated_files_list;
    if(!objectp(who)) return;
    if(!objectp(ob))
    {
        tell_object(who, "Cannot register item. It appears invalid?");
        return;
    }
    verify_updated_items_mapp();
    target_file = base_name(ob);
    if(!sizeof(updated_files_list = keys(UPDATED_ITEMS)) ||
    member_array(target_file, updated_files_list) == -1)
    {
        UPDATED_ITEMS += ([target_file : time()]);
        tell_object(who, "Attemping to add file "+target_file+
        " to the list of items that will be auto updated for players on relog.");
    }
    else
    {
        UPDATED_ITEMS[target_file] = time();
        tell_object(who, "Adjusting the update time for file "+target_file+
        ".");        
    }
    updated_items_save();
    return;
}
