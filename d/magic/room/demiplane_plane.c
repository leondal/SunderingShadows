#include <std.h>
#include <magic.h>

inherit ROOM;

object entry, rope;
string roomName;
string castname;
nosave int clevel;

mapping extraitems=([]);

void create() {
   ::create();
   set_light(1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors", 1);
   set_short("%^BOLD%^%^BLUE%^a small demiplane%^RESET%^");
   set_short("%^CYAN%^Nowhere%^RESET%^");
   set_long(
       "%^CYAN%^Nowhere
%^CYAN%^You stand in the middle of nothing, surrounded by a white haze.
"
   );
   set_property("no pocket space",1);
   //This exit should display only if someone somehow logs into base
   //object (server crast, or if they log out before caster).
   //TODO: Implement name-based loading of object to allow demiplane persistence.
   set_exits((["out":"/d/shadow/room/forest/road30"]));
}

void init() {
   ::init();
   add_action("pull_up_rope", "close");
   add_action("lower_rope", "open");
   add_action("set_plane_property", "set");
   add_action("set_plane_feature", "feature");
}

int set_plane_feature(string str)
{
    string tmp, cargs;
    if(!regexp(str,"^[add|remove|list|clear]"))
        return 0;
    if(TP->query_name()!=castname)
        return 0;
    if(regexp(str,"^add"))
    {
        if(sizeof(extraitems)>20)
        {
            write("You have too many features. Maximum twenty are allowed.");
            return 1;
        }
        if(sscanf(str,"add %s as %s",cargs,tmp)!=2)
        {
            write("You must provide feature name and its description.");
            return 1;
        }
        if(!sizeof(extraitems))
            extraitems=([]);

        extraitems+=([cargs:tmp]);
        restore_items();
        save_space();
        write("Feature '"+cargs+"' added as: "+tmp);
    }

    if(regexp(str,"^remove"))
    {
        if(sscanf(str,"remove %s",cargs)!=1)
        {
            write("You must provide feature name.");
            return 1;
        }
        map_delete(extraitems,cargs);
        restore_items();
        save_space();
        write("Feature "+cargs+" removed.");
    }

    if(regexp(str,"^list"))
    {
        string item;
        if(sizeof(extraitems))
        {
            write("%^BOLD%^%^RED%^There are "+sizeof(extraitems)+" features present:");
            foreach(item in keys(extraitems))
            {
                write(item);
            }
        }
        else
            write("%^BOLD%^%^RED%^There no features present.");
    }

    if(regexp(str,"^clear"))
    {
        extraitems=([]);
        restore_items();
        save_space();
        write("All features were removed");
    }

    return 1;
}

int set_plane_property(string str)
{
    string tmp, cargs;
    if(!regexp(str,"^plane [long|short|smell|seal]"))
        return 0;
    if(TP->query_name()!=castname)
        return 0;
    if(regexp(str,"^plane long"))
    {
        if(sscanf(str,"plane long %s",cargs)!=1)
        {
            write("You must provide description");
            return 1;
        }
        TO->set_long(query_short()+"\n"+cargs+"\n");
        save_space();
        TP->force_me("look");
    }

    if(regexp(str,"^plane short"))
    {
        if(sscanf(str,"plane short %s",cargs)!=1)
        {
            write("You must provide description");
            return 1;
        }
        TO->set_short(cargs);
        if(sizeof(explode(TO->query_long(),"\n"))>0)
            TO->set_long(cargs+"\n"+explode(TO->query_long(),"\n")[1]+"\n");
        save_space();
        TP->force_me("look");
    }

    if(regexp(str,"^plane smell"))
    {
        if(sscanf(str,"plane smell %s",cargs)!=1)
        {
            write("You must provide description");
            return 1;
        }
        TO->set_smell("default",cargs);
        save_space();
        TP->force_me("look");
    }

    if(regexp(str,"^plane listen"))
    {
        if(sscanf(str,"plane listen %s",cargs)!=1)
        {
            write("You must provide description");
            return 1;
        }
        TO->set_listen("default",cargs);
        save_space();
        TP->force_me("look");
    }

    if(regexp(str,"^plane seal"))
    {
        if(sscanf(str,"plane seal %s",cargs)!=1)
        {
            write("<set plane seal on|off>");
            return 1;
        }
        if(cargs == "on")
        {
            TO->set_property("teleport proof",clevel);
            write("The plane has been locked from interdimensional travel.");
        }
        if(cargs == "off")
        {
            TO->remove_property("teleport proof");
            write("The plane has been unlocked to interdimensional travel.");
        }
        save_space();
    }

    return 1;
}

void set_entry(object ob, object rp, string where)
{
  entry = ob;
  rope = rp;
  roomName = where;
}

void set_castname(string str)
{
    castname = str;
}

int pull_up_rope(string str)
{
   object *inv;
   int x;

   if(str != "door")
       return 0;
   inv = all_inventory(TO);

   tell_room(TO, "%^ORANGE%^"+TPQCN+" locks the door to material plane.",TP);
   tell_object(TP, "%^ORANGE%^You lock the door to material plane.");
   rope->raise();
   TO->remove_exit("door");
   return 1;
}

int lower_rope(string str)
{
   if(str != "door")
       return 0;
   tell_room(TO, "%^ORANGE%^An old door reappears.",TP);
   tell_object(TP,"%^ORANGE%^You summon the door to material plane.");
   rope->lower();
   if(!objectp(entry))
	entry = find_object_or_load(roomName);
   TO->add_exit(base_name(entry), "door");
   return 1;
}

void save_space()
{
    set_exits(([]));
    mkdir("/d/save/summons/"+castname);
    save_object("/d/save/summons/"+castname+"/demiplane");
}

void restore_space()
{
    if(file_exists("/d/save/summons/"+castname+"/demiplane.o"))
    {
        restore_object("/d/save/summons/"+castname+"/demiplane.o");
    }
    restore_items();
}

void restore_items()
{
    string item;
    TO->set_items(([]));
    if(sizeof(extraitems))
        foreach(item in keys(extraitems))
        {
            add_item(item,extraitems[item]);
        }
}

void vape_items()
{
    extraitems = ([]);
    restore_items();
}

void destroy_space() {
   object *inv;
   int x;

   inv = all_inventory(TO);
   if(!objectp(entry))
       entry = find_object_or_load(roomName);
   tell_room(TO,"%^ORANGE%^Everything arround you disappears and you appear somewhere else.");

   save_space();

   for(x=0;x<sizeof(inv);x++)
       inv[x]->move(entry);
   "/daemon/virtual_room_d.c"->destroy_virtual_room(TO->query("my_virtual_name"), entry);
   TO->remove();
}
