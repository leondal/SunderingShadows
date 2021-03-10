#include <std.h>
#include <magic.h>
#include <rooms.h>
#include "../inherits/area_stuff.h"

inherit OBJECT;

object tent_room;
string UNIQ_ID;

void set_my_tent(string str) { UNIQ_ID = str; }
string query_my_tent() { return UNIQ_ID; }

void register_tent_room(object ob)
{
    if(!objectp(ob)) return;
    tent_room = ob;
}

mixed query_tent_room() { return tent_room; }

void create() 
{
    ::create();
    set_name("entry into a tent");
    set_id( ({ "tent entry", "tent", "tent_entry_object"}) );
    set_short("%^RESET%^%^GREEN%^A tent");;
    set_long("%^RESET%^%^GREEN%^This tent is made from a very "+
    "%^BOLD%^%^GREEN%^thick%^RESET%^%^GREEN%^ and heavy "+
    "%^BOLD%^%^GREEN%^fabric%^RESET%^%^GREEN%^. The majority of it has "+
    "been coated with a %^BOLD%^%^BLACK%^thick malleable substance %^RESET%^%^GREEN%^"+
    "in order to seal it from moisture that might seep in from the "+
    "weather. Thankfully there have been %^BOLD%^%^WHITE%^air vents "+
    "%^RESET%^%^GREEN%^ installed on each wall of it in order to allow "+
    "circulation for whoever might be inside of it. It is big enough that "+
    "it would be possible for many people to fit comfortably inside of it "+
    "at the same time. "+
    "There is a large opening, covered with a %^BOLD%^%^GREEN%^thinner material"+
    "%^RESET%^%^GREEN%^, that you could %^BOLD%^%^CYAN%^enter%^RESET%^%^GREEN%^ "+
    "if you were so inclined. You could also %^BOLD%^%^CYAN%^peer%^RESET%^%^GREEN%^ "+
    "into it if you wanted to see who or what was inside of it.%^RESET%^");
    
    set_property("no animate",1);
    set_value(0);
    set_weight(100000);
    set_heart_beat(1);
}

void init() 
{
    ::init();
    add_action("entry_func", "enter");
    add_action("peer_func", "peer");
}

int is_tent() { return 1; }

void real_enter(object who)
{
    if(!objectp(TO)) return;
    if(!objectp(who)) return;
    if(!objectp(tent_room)) 
    {
        tell_object(who, "ERROR: Something is wrong with the tent room. Notify saide of this message!");
        return;
    }
    who->move_player(tent_room);
    who->query_followers()->move_player(tent_room);
    return;
}

int entry_func(string str)
{
    object targ;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!objectp(ETP)) return 0;
    if(TP->query_unconscious() || TP->query_bound()
    || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!stringp(str)) return 0;
    if(!objectp(targ = present(str, ETP)))
    {
        return 0;
    }
    if(!targ->is_tent()) return 0;
    targ->real_enter(TP);
    return 1;
}

int peer_func(string str)
{
    object targ, targ_room;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!objectp(ETP)) return 0;
    if(TP->query_unconscious() || TP->query_bound()
    || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!stringp(str)) return 0;
    if(!objectp(targ = present(str, ETP)))
    {
        return 0;
    }
    if(!targ->is_tent()) return 0;
    if(!objectp(targ_room = targ->query_tent_room())) return 0;
    if (TP->light_blind_remote(0,targ_room,1)) 
	{
        message("my_action",TP->light_blind_fail_message(TP->light_blind_remote(0,targ_room,1)),TP);
  	}
    message("room_description", (string)targ_room->query_short(0) || "Unknown" ,TP);
    message("room_exits", (string)targ_room->query_short_exits(), TP);
    message("Nliving_item", (string)targ_room->describe_living_contents(({})), TP);
    message("Ninanimate_item", (string)targ_room->describe_item_contents(({})), TP);
    
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(tent_room)) TO->remove();
    return;
}

int query_filth()
{
    if(objectp(tent_room)) return tent_room->query_filth();
    return 0;
}

int take_down_tent(object who, object tentbag)
{
    object *inv;
    int x;
    if(!objectp(who)) return 0;
    if(!objectp(tent_room))
    {
        tell_object(who, "ERROR: There is something wrong with your tent when "+
        "trying to take it down, let saide known this message.");
        return 0;
    }
    inv = all_inventory(tent_room);
    for(x = 0;x < sizeof(inv);x++)
    {
        if(living(inv[x]))
        {
            tell_object(who, "%^BOLD%^%^RED%^There is still something alive inside "+
            "your tent!%^RESET%^");
            return 0;
        }
        continue;
    }
     "/daemon/virtual_room_d.c"->destroy_virtual_room(tent_room->query("my_virtual_name"), environment(who));
    if(sizeof(inv)) 
    {
        tell_object(who, "%^BOLD%^%^GREEN%^Several objects spill out of the tent!%^RESET%^");
        inv->move(environment(who));
    }
    if(objectp(tentbag)) tentbag->set_filth(query_filth());
    tent_room->remove();
    return 1;    
}
