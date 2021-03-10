#include <std.h>

#define VOID "/d/shadowgate/void.c"

inherit DAEMON;

int container_filter(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(obj->is_container()) { return 1; }
    return 0;
}

int bad_objects_filter(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(base_name(obj) == "/d/magic/scroll") { return 0; }
    if(living(obj)) { return 0; }
    if(base_name(obj) == "/d/magic/comp_bag") { return 0; }
    if(base_name(obj) == "/d/magic/psi_comp_bag") { return 0; }
    if(base_name(obj) == "/d/token_hunt/tokens") { return 0; }
    if(base_name(obj) == "/std/bboard") { return 0; }
    if(base_name(obj) == "/d/token_hunt/obj/high/na_compbag.c") { return 0; }
    if(base_name(obj) == "/d/token_hunt/obj/high/na_satchel.c") { return 0; }
    if(obj->id("sheath")) { return 0; }
    if(obj->id("vial")) { return 0; }
    if(obj->id("token")) { return 0; }
    if(obj->id("golden ring")) { return 0; }
    if(obj->id("scroll case")) { return 0; }
    if(strsrch(base_name(obj),"/d/magic/") != -1) { return 0; }
    return 1;
}

    
int filter_descs(object obj)
{
    object temp_obj;

    if(!objectp(obj)) { return 0; }

    temp_obj = new(base_name(obj));

    if( ( (string)temp_obj->query("short") != (string)obj->query("short") )  &&  ( (string)temp_obj->query_obvious_short() != (string)obj->query("short") ) ) { return 1; }
    if( ( (string)temp_obj->query("long")  != (string)obj->query("long") ) && ( (string)temp_obj->query_obvious_long() != (string)obj->query("short")) ) { return 1; }

    temp_obj->remove();
    return 0;
}


string fix_desc(string str)
{
    int end;
    string fixed;

    if(!stringp(str) || str == "" || str == " ") { return ""; }

    end = strsrch(str,"(size");
    
    if(end == -1) { return str; }

    fixed = str[0..(end-1)];

    return fixed;
}


void renew_object(object obj)
{
    string file;
    object new_item;

    if(!objectp(obj)) { return 0; }

    file = base_name(obj);

    if(catch(new_item = new(file)))
    {
        return;
    }
    new_item->move(ETP);

    obj->move(VOID);
    obj->remove();
}


void renew_object_special(object obj)
{
    string file,short_desc,long_desc;
    object new_item;

    if(!objectp(obj)) { return 0; }

    file = base_name(obj);

    short_desc = obj->query("short");
    long_desc = obj->query("long");
    long_desc = fix_desc(long_desc);

    if(catch(new_item = new(file)))
    {
        return;
    }

    new_item->set("short",short_desc);
    new_item->set("long",long_desc);

    new_item->move(ETP);

    obj->move(VOID);
    obj->remove();
    return;
}



int cmd_refresh(string str)
{
    object *objs,*containers,*inv,*special,*ppl;
    int i,j;

    objs = all_inventory(ETP);
    objs = filter_array(objs,"bad_objects_filter",TO);
    containers = filter_array(objs,"container_filter",TO);

    for(i=0;i<sizeof(containers);i++)
    {
        inv = all_inventory(containers[i]);
        if(sizeof(inv))
        {
            for(j=0;j<sizeof(inv);j++)
            {
                if(!objectp(inv[j])) { continue; }
                inv[j]->move(ETP);
            }
        }
    }

    objs = all_inventory(ETP);
    objs = filter_array(objs,"bad_objects_filter",TO);

    special = filter_array(objs,"filter_descs",TO);

    objs = objs - special;

    if(sizeof(special))
    {
        for(i=0;i<sizeof(special);i++)
        {
            if(!objectp(special[i])) { continue; }
            renew_object_special(special[i]);
        }
    }
    
    if(sizeof(objs))
    {
        for(i=0;i<sizeof(objs);i++)
        {
            if(!objectp(objs[i])) { continue; }
            renew_object(objs[i]);
        }
    }

    objs = all_inventory(ETP);
    objs = filter_array(objs,"bad_objects_filter",TO);

    ppl = all_living(ETP);
    ppl = filter_array(ppl,"is_player","/daemon/filters_d.c");

    if(sizeof(objs))
    {
        for(i=0;i<sizeof(objs);i++)
        {
            if(!objectp(objs[i])) { continue; }

            for(j=0;j<sizeof(ppl);j++)
            {
                if(interactive(ppl[j]))
                {
                    objs[i]->add_identified(ppl[j]->query_name());
                    tell_object(TP,"Identifying object "+identify(objs[i])+"");
                }
            }
        }
    }

    tell_object(TP,"Operation Complete...");
    return 1;
}


int help(string str)
{
    tell_object(TP,"Syntax: refresh\n"
        "This command will renew all of the objects in the room.  It's useful for updating out of date "
        "gear from players who have been away from the game for a while.");
    return 1;
}

