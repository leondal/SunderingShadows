#include <std.h>
#include "token_hunt.h"

inherit OBJECT;

void create()
{
    ::create();
    set_id(({"marker","token marker"}));
    set_long("This is a token marker, use 'mark here as <level>' where level is "
        "high, mid, or low.  You can also list <level> to see a listing of all "
        "the directories for each group.  You can now also do unmark here as <level> "
        "to remove a directory, so shifters will no longer appear there.");
    set_short("token marker");
    set_weight(1);
}


int unmark_spot(string str)
{
    string *info=({}),dir;
    object ob,token_d;
    if(!stringp(str)) { return 0; }
    info = explode(str," ");
    if(sizeof(info) != 3) { return 0; }
    if(info[0] != "here") { return 0; }
    if(info[1] != "as") { return 0; }
    if(info[2] != "high" && info[2] != "mid" && info[2] != "low")
    {
        tell_object(TP,"Valid levels are high, mid and low");
        return 1;
    }    
    if(!objectp(ob = EETO)) { return 1; }

    dir = arrange_string(base_name(ob),strsrch(base_name(ob),"/",-1)+1);

    if(!objectp(token_d=find_object(INV_PATH"token_location_d")))
    {
        token_d = find_object_or_load(INV_PATH"token_location_d");
    }

    if(token_d->remove_directory(info[2],dir))
    {
        tell_object(TP,"removed "+dir+" from list of directories for "+info[2]+"");
        return 1;
    }
    tell_object(TP,"Directory NOT removed.");    

    return 1;
}

int mark_spot(string str)
{
    string *info=({}),dir;
    object ob,token_d;
    if(!stringp(str)) { return 0; }
    info = explode(str," ");
    if(sizeof(info) != 3) { return 0; }
    if(info[0] != "here") { return 0; }
    if(info[1] != "as") { return 0; }
    if(info[2] != "high" && info[2] != "mid" && info[2] != "low")
    {
        tell_object(TP,"Valid levels are high, mid and low");
        return 1;
    }    
    if(!objectp(ob = EETO)) { return 1; }

    dir = arrange_string(base_name(ob),strsrch(base_name(ob),"/",-1)+1);

    if(!objectp(token_d=find_object(INV_PATH"token_location_d")))
    {
        token_d = find_object_or_load(INV_PATH"token_location_d");
    }

    if(token_d->add_directory(info[2],dir))
    {
        tell_object(TP,""+dir+" added as directory for "+info[2]+"");
        return 1;
    }
    tell_object(TP,"Directory NOT added.");    

    return 1;
}

int list_directories(string str)
{
    object token_d;
    string *info=({});
    int i;

    if(!stringp(str)) { return 0; }
    if(str != "high" && str != "mid" && str != "low") { return 0; }

    if(!objectp(token_d=find_object(INV_PATH"token_location_d")))
    {
        token_d = find_object_or_load(INV_PATH"token_location_d");
    }
    info = token_d->query_directories(str);

    for(i=0;i<sizeof(info);i++)
    {
        tell_object(TP,info[i]);
    }
    return 1;
}

void init()
{
    if(!objectp(TP)) { return; }
    if(!avatarp(TP)) 
    {
        TO->remove();
        return;
    }
    add_action("mark_spot","mark");
    add_action("unmark_spot","unmark");
    add_action("list_directories","list");
    return;
}
