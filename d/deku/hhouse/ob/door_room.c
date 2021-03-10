#include <std.h>
#include "../inherits/area_stuff.h"
inherit ROOM;
object MyRoomOwner;
void set_owner(object who);

void create()
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);

    set_terrain(VILLAGE);
    set_travel(SLICK_FLOOR);
    set_name("A chamber within the mind");
    set_had_players(1);

    set_listen("default","Your own thoughts fill the air around you!");
    set_smell("default","\nYour sense of smell is overwhelmed by strange yet "+
    "familiar odors.");
}

/*void init()
{
    ::init();
    add_action("quit_func", "quit");
}*/

/*int quit_func(string str)
{
    tell_object(TP, "%^BOLD%^%^WHITE%^You must leave here first!%^RESET%^");
    return 1;
}*/


void set_owner(object who)
{
    if(objectp(who)) MyRoomOwner = who;
}

void setup_room(object who)
{
    string myRoomType, defaultExit = "/d/deku/town/road5", mycol, *tmp, *exits = ({}), *num = ({});
    int x;
    object myDest;
    mapping myInfo;
    if(!objectp(who))
    {
        myRoomType = "neutral";
        myInfo = (["exit" : defaultExit]);
    }
    else
    {
        MyRoomOwner = who;
        TO->set_property("teleport proof", who->query_level());
        if(objectp(environment(who))) defaultExit = base_name(environment(who));
        myInfo = (["exit": defaultExit]);
        if(mapp(who->query_rem_rooms())) myInfo += who->query_rem_rooms();
        switch(who->query_alignment())
        {
            case 1: case 4: case 7:
                myRoomType = "good";
                break;
            case 2: case 5: case 8:
                myRoomType = "neutral";
                break;
            case 3: case 6: case 9:
                myRoomType = "evil";
                break;
        }
    }
    switch(myRoomType)
    {
        case "good":
            mycol = "%^BOLD%^%^WHITE%^";

            set_long(mycol + "The room around you is quite hazy and it is difficult "+
            "to make out any solid shapes about it. There is, however, a feeling of "+
            "peace here, as if the culmination of all your work throughout the realm "+
            "has been realized. You are sure of yourself here and hopeful of tomorrow. "+
            "The past has gone and with it all of its failures, disappointments, and "+
            "problems. You are left with the here and now and a brilliant future. "+
            "You are truly at rest within this peaceful chamber! Only a slight "+
            "nagging feeling pulls at your soul, as if something is not right or "+
            "perhaps not real.%^RESET%^");
            break;

        case "neutral":
            mycol = "%^BOLD%^%^CYAN%^";

            set_long(mycol +"The room around you is quite hazy and it is difficult "+
            "to make out any solid shapes about it. There is, however, a feeling of "+
            "harmony here, so strong in fact that it almost feels tangible. As if "+
            "the realm has finally reached a point of total and complete balance and "+
            "all things are now even. The past, with all of its inequalities, all the "+
            "disagreements, all of the fighting, is now faded away. You are left with the here and "+
            "now and a amazing future that promises to maintain order! You are truly "+
            "in harmony here within this chamber. Only a slight nagging feeling pulls at "+
            "your soul, as if something is not right or perhaps not real.%^RESET%^");
            break;

        case "evil":
            mycol = "%^BOLD%^%^BLACK%^";

            set_long(mycol + "The room around you is quite hazy and it is difficult "+
            "to make out any solid shapes about it. There is, however, a feeling of "+
            "control here, so powerful that you know whatever you could possibly want "+
            "is within reach. As if the realm has finalized realized the validity of your "+
            "authority and submitted itself to your whims. The past, with all of those who "+
            "stood in your way, those who didn't believe in you, and those who thought you "+
            "'evil' is now trampled beneath your feet. You are left with the here and "+
            "now and a future where all shall bow down before you! You are truly in control "+
            "within this chamber. Only a slight nagging feeling pulls at your soul, as if "+
            "something is not right or perhaps not real.%^RESET%^");
            break;
    }
    set_short(mycol +"A chamber within the mind%^RESET%^");

    tmp = keys(myInfo);
    for(x = 0;x < sizeof(tmp);x++)
    {
        if(!objectp(myDest = find_object_or_load(myInfo[tmp[x]]))) continue;
        if(myDest->query_property("no teleport")) continue;
        TO->add_exit(myInfo[tmp[x]], replace_string(tmp[x], " ",""));
        exits += ({replace_string(tmp[x], " ","")});
        num += ({"GoThroughDoor"});
        continue;
    }

    set_post_exit_functions(exits, num);
}

void check_contents(string dest, object who)
{
    string myMove;
    object *myObs;
    int x;
    if(!stringp(dest) && !objectp(who)) return;
    myObs = all_inventory(TO);
    if(!sizeof(myObs))
    {
        TO->remove();
        return;
    }
    if(!stringp(dest))
    {
        if(objectp(who)) myMove = base_name(environment(who));
    }
    if(stringp(dest))
    {
        myMove = TO->query_exit(dest);
    }
    for(x = 0;x < sizeof(myObs);x++)
    {
        if(living(myObs[x]))
        {
            tell_object(myObs[x], "%^BOLD%^%^WHITE%^You are pulled from here as the chamber "+
            "around you begins to fade away!%^RESET%^");
            myObs[x]->move(myMove);
            if(!myObs[x]->query_true_invis())
            {
                tell_room(environment(myObs[x]), myObs[x]->QCN + "%^BOLD%^%^WHITE%^ materializes here, "+
                "looking quite shaken!%^RESET%^", myObs[x]);
            }
            myObs[x]->force_me("look");
            continue;
        }
        else
        {
            myObs[x]->move(myMove);
            tell_room(environment(myObs[x]), myObs[x]->query_short() + "%^BOLD%^%^WHITE%^ materializes here!%^RESET%^");
            continue;
        }
    }
    "/daemon/virtual_room_d.c"->destroy_virtual_room(TO->query("my_virtual_name"), myMove);
    TO->remove();
}

int GoThroughDoor(mixed door)
{

    tell_room(ETP, "%^BOLD%^%^WHITE%^Suddenly a door materializes and opens, then quickly disappears.");

    if(objectp(TP) && objectp(MyRoomOwner))
    {
        if(TP == MyRoomOwner)
        {
            call_out("check_contents", 1, query_verb(), TP);
        }
    }


    return 1;
}
