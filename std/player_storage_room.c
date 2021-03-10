/* /std/player_storage_room.c
a room to use for guild vaults or for storage rooms in high mortal
houses.  It has functions to deal with storing items and stealing
them from the vault.  The final file name of the room that inherits
player_storage_room.c is tied in to the commands.  So if you move
a file,  you need to make sure that the storage room is empty first

created 01/28/2010 -Ares
*/
#include <std.h>

inherit CVAULT;

#define STORAGE_D  "/daemon/player_storage_d.c"

int FREE; // this is set to 1 for houses, they don't cost anything to store items in them

void create()
{
    ::create();

    // vault size represents how many items can be stored.  If it's a HM house then 
    // we should only let the owner of the house store items in it.  In the case of
    // a guild we allow members of the guild to store things here.
    // price to increase vault size is new size * 500k for houses, and new size * 5million for guilds

    set_property("vault size",1);
}

void add_member(string name)     { STORAGE_D->add_member(TO,name); }
void remove_member(string name)  { STORAGE_D->remove_member(TO,name); }

string query_long(string str) 
{
    return ::query_long() +"\n%^RESET%^%^CYAN%^There is a small sign here that has a "
        "message scrawled onto it.%^RESET%^";
}

void init()
{
    ::init();
    add_action("steal_object","rob");
    add_action("store_object","store");
    add_action("retrieve_object","retrieve");
    add_action("display_objects","list");
    add_action("display_objects","show");
    add_action("price_check","check");
    add_action("read_sign","read");
    return;
}

int confirm_steal(string str,object player,object tools)
{
    if(!objectp(player)) { return 0; }
    if(!stringp(str) || str != "yes")
    {
        tell_object(player,"%^RESET%^%^BOLD%^Yeah, maybe you should wait until nobody's "
            "around...");
        return 1;
    }
    if(!objectp(tools) || !present(tools,player))
    {
        tell_object(player,"%^RESET%^%^BOLD%^You seem to have dropped your tools...");
        return 1;
    }
    STORAGE_D->steal_object(player,tools);
    return 1;
}

int steal_object(string str)
{
    object tools;

    if(!objectp(TP)) { return 0; }
    if(!objectp(tools = present("thief tools",TP)))
    {
        tell_object(TP,"%^RESET%^%^BOLD%^You would probably need some tools "
            "to break into the locks!%^RESET%^");
        return 1;
    }
    tell_object(TP,"%^RESET%^%^BOLD%^Are you sure you want to try to rob the "
        "storage boxes here?  Whoever owns them won't be pleased...\n"
        "enter yes to try to rob them, anything else to cancel.");
    input_to("confirm_steal",TP,tools);
    return 1;
}

int confirm_store_object(string str,object player,object obj)
{
    int num;
    if(!objectp(player)) { return 0; }
    if(!stringp(str) || str != "yes")
    {
        tell_object(player,"%^RESET%^%^BOLD%^Aborting...%^RESET%^");
        return 1;
    }
    if(!objectp(obj) || !present(obj,player))
    {
        tell_object(player,"%^RESET%^%^BOLD%^You seemed to have dropped the "
            "thing you were trying to put into storage.%^RESET%^");
        return 1;
    }
    STORAGE_D->store_object(player,obj,FREE);
    return 1;
}

int store_object(string str)
{
    object obj;
    int price;

    if(!objectp(TP)) { return 0; }
    if(!stringp(str) || str == "" || str == " ") { return 0; }

    if(!objectp(obj=present(str,TP)))
    {
        tell_object(TP,"%^RESET%^%^BOLD%^You don't seem to be carrying "
            "a "+str+".");
        return 1;
    }

    if(!FREE)
    {
        price = STORAGE_D->price_check(TP,obj);
        if(!price)
        {
            return 1;
        }
        tell_object(TP,"%^RESET%^%^BOLD%^Are you sure you want to put your "
            ""+obj->query_short()+" into storage?  It would cost you "
            ""+price+" gold coins.\nenter yes to put the item into "
            "storage, anything else to cancel.");
        input_to("confirm_store_object",TP,obj);
        return 1;
    }
    else
    {
        tell_object(TP,"%^RESET%^%^BOLD%^Are you sure you want to put your "
            ""+obj->query_short()+" into storage?\nenter yes to put the item "
            "into storage, anything else to cancel.");
        input_to("confirm_store_object",TP,obj);
        return 1;
    }
    return 1;
}

int display_objects(string str)
{
    mixed targ;
    object player;

    if(!objectp(TP)) { return 0; }

    if(avatarp(TP))
    {
        if(!stringp(str)) { targ = TP; }
        else
        {
            targ = str;
            player = TP;
        }
    }

    if(objectp(player)) { STORAGE_D->display_player_items(targ,player); }
    else { STORAGE_D->display_player_items(TP); }
    return 1;
}

int price_check(string str)
{
    object obj;
    int price;

    if(!objectp(TP)) { return 0; }
    if(!stringp(str) || str == "" || str == " ") { return 0; }

    if(!objectp(obj=present(str,TP)))
    {
        tell_object(TP,"%^RESET%^%^BOLD%^You don't seem to have a "
            ""+str+" on you.");
        return 1;
    }

    if(FREE)
    {
        tell_object(TP,"%^RESET%^%^BOLD%^It doesn't cost anything "
            "to put items into storage here.%^RESET%^");
        return 1;
    }

    price = STORAGE_D->price_check(TP,obj);

    tell_object(TP,"%^RESET%^%^BOLD%^It would cost "+price+" gold "
        "coins to put your "+obj->query_short()+" into storage.%^RESET%^");
    return 1;
}

int retrieve_object(string str)
{
    if(!objectp(TP)) { return 0; }
    if(!stringp(str) || str == "" || str == " ") { return 0; }

    if(!avatarp(TP))
    {
        if(!STORAGE_D->member_check(TP))
        {
            tell_object(TP,"%^RESET%^%^BOLD%^You aren't allowed to use "
                "these storage boxes.");
            return 1;
        }
    }
    STORAGE_D->retrieve_object(TP,str);
    return 1;
}

int read_sign(string str)
{
    if(!objectp(TP)) { return 0; }
    if(!stringp(str) || str != "sign") { return 0; }

    tell_object(TP,"%^RESET%^%^BOLD%^This is a storage room where players "
        "are allowed to store objects, usually for a fee.  The objects may "
        "then be picked up at a later time. Syntax are as follows:\n"
        "    store    <item>   stores an item that you have in your inventory.\n"
        "    retrieve <item>   picks an item up from storage.\n"
        "    list              shows all the items you have stored in this location.\n"
        "    show              same as list.\n"
        "    check <item>      this will tell you the cost to store an item here.\n"
        "    rob               if you're good with locks and you have some tools\n"
        "                      maybe you could rob the place.\n");

    if(avatarp(TP))
    {
        tell_object(TP,"    list <name>       shows all the items stored here by <name>\n");
    }
    return 1;
}
