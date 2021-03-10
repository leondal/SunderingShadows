#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFCE;

void create()
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^There is a %^RESET%^%^MAGENTA%^large crack"+
    "%^RESET%^%^BOLD%^%^BLUE%^ on the east wall and on the west wall of the cellar here. The cellar appears to end here. "+
    "An opening to the northwest offers the only exit.%^RESET%^");
    set_exits( ([ "northwest" : FFCR"7"]) );
    TO->add_item(({"crack", "east crack", "west crack", "large crack",
    "large cracks"}), "%^RESET%^%^MAGENTA%^These cracks, upon closer inspection, appear to open behind the wall "+
    "into what appear to be dirt tunnels.  You could %^RESET%^squeeze into %^MAGENTA%^either "+
    "one of them if you were bold enough to do so. You could also possible %^RESET%^peer%^MAGENTA%^"+
    " into them to get a better look at what lies on the other side.%^RESET%^");
}

void init()
{
    ::init();
    add_action("peer_function","peer");
    add_action("squeeze_function", "squeeze");
}

int do_peer_stuff(string where)
{
    int i;
    string target_room, targ;
    object *objects_in_room, troom, spider;
    if(!objectp(TP)) return 1;
    if(where != "east crack" && where != "west crack") return 0;
    targ = explode(where, " ")[0];
    if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
    || TP->query_tripped())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    tell_object(TP, "You peer intently into the crack on the "+
    targ +" wall.");

    if(!TP->query_invis())
    {
        tell_room(TO,TPQCN+"%^MAGENTA%^ peers through the "+
        "crack on the "+targ + " wall.%^RESET%^",TP);
    }
    if(where == "east crack") target_room = FFTR"1";
    if(where == "west crack") target_room = FFTR"16";
    troom = to_object(target_room);
    if(!objectp(troom)) return 1;
    tell_object(TP,troom->query_short());
    objects_in_room = all_inventory(to_object(target_room));
    for(i == 0; i<sizeof(objects_in_room); i++)
    {
        if(!objects_in_room[i]->query_invis())
        {
            //spiders might notice you peering into the room and come through the
            //crack after you? - Saide
            if(!objectp(TP)) return 1;
            tell_object(TP,objects_in_room[i]->query_short());
            spider = objects_in_room[i];
            if(spider->id("feyrenspidermob"))
            {
                if(!random(3) && !TP->query_invis())
                {
                    tell_object(TP, spider->QCN+ " seems to notice "+
                    "your gaze and climbs through the crack on the "+
                    targ + " wall after you!%^RESET%^");

                    tell_room(TO, spider->QCN + " climbs into the room "+
                    "through the crack on the "+targ+" wall and "+
                    "attacks "+TPQCN+"!%^RESET%^", TP);

                    spider->move(TO);
                    spider->force_me("kill "+TPQCN);
                }
            }
        }
    }
    return 1;
}

int squeeze_function(string str, string what, string where)
{
    object TR;
    string targ, ntarg, targ_room;
    if(!str) return 0;
    if(!objectp(TP)) return 0;
    if(sscanf(str, "%s %s", what, where))
    {
        if(what != "into") return 0;
        where = lower_case(where);
        if(where != "east crack" && where != "west crack") return 0;
        targ = explode(where, " ")[0];
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
        || TP->query_tripped())
        {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
        if(where == "east crack") targ_room = FFTR"1";
        if(where == "west crack") targ_room = FFTR"16";
        tell_object(TP, "%^BOLD%^%^MAGENTA%^You carefully squeeze "+
        "through the crack on the "+targ+" wall into the dirt tunnel "+
        "beyond.%^RESET%^");

        if(!TP->query_invis())
        {
            tell_room(TO, TPQCN + " %^BOLD%^%^MAGENTA%^carefully squeezes "+
            "through the crack on the "+targ+" wall!%^RESET%^", TP);
        }

        if(targ == "east") ntarg = "west";
        if(targ == "west") ntarg = "east";
        //targ_room = FFCR"1";
        TP->move_player(targ_room);
        TR = to_object(targ_room);
        if(!objectp(TR)) return 0;

        if(!TP->query_invis())
        {
            tell_room(TR, TPQCN +" %^BOLD%^%^MAGENTA%^enters from the "+
            "crack on the "+ntarg+" wall!%^RESET%^", TP);
        }
        return 1;
    }
    return 0;
}


int peer_function(string str,string what,string where)
{
    if(!str) return 0;
    if(sscanf(str,"%s %s",what,where))
    {
        if(what != "into") return 0;
        where = lower_case(where);
        if(where == "east crack" || where == "west crack")
        {
            do_peer_stuff(where);
            return 1;
        }
        else return 0;
    }
    return 0;
}
