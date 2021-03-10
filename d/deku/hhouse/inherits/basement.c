#include <std.h>
#include <daemons.h>
#include "basement.h"
#include "door_stuff.h"

#include "/d/common/common.h"

inherit HAUNTING;

mixed query_exit_map(string myMap)
{
    string wh, *tmp;
    if(!objectp(TO)) return;
    wh = explode(base_name(TO), "br")[1];
    //wh = tmp[sizeof(tmp)-1];
    //wh = explode(wh, "br");
    //tell_object(TO, "wh = "+wh);
    switch(myMap)
    {
        case "mapone": 
            return MAPONE[wh];
            break;
        case "maptwo":
            return MAPTWO[wh];
            break;
        case "mapthree":		
            return MAPTHREE[wh];
            break;
    }
}

void adjust_room(string curMap)
{
    int x, flag, flag2;
    string *myExits;
    object *targ_rooms, targ_room;
    mapping tmp_map;
    if(!objectp(TO)) return;
    tmp_map = TO->query_exit_map(TO->query("using_map"));
    targ_rooms = ({});
    if(member_array(1, all_living(TO)->is_player()) != -1) 
    {
        flag2 = 1;
        tell_room(TO, "%^BOLD%^%^CYAN%^Time suddenly stands %^BOLD%^%^YELLOW%^still%^BOLD%^%^CYAN%^... and you are "+
        "unable to do anything at all....%^RESET%^");
        tell_room(TO, "%^BOLD%^%^RED%^A manical laughter erupts from the very air around you and a disembodied "+
        "voice %^BOLD%^%^BLACK%^BOOMS%^BOLD%^%^RED%^: %^RESET%^You will never find your way from here, this "+
        "place %^BOLD%^%^RED%^SHALL%^RESET%^ be your %^BOLD%^%^RED%^GRAVE!%^RESET%^");
        all_living(TO)->set_paralyzed(10000, "%^BOLD%^%^CYAN%^You are frozen as time stands still!%^RESET%^");

        tell_room(TO, "%^BOLD%^%^RED%^You watch in %^BOLD%^%^BLACK%^horror%^BOLD%^%^RED%^ as the room around you "+
        "repositions itself!%^RESET%^");
    }

    if(mapp(tmp_map)) 
    {
        myExits = keys(tmp_map);
        if(member_array("door", myExits) != -1)
        {
            tell_room(TO, "%^BOLD%^%^RED%^The door %^BOLD%^%^YELLOW%^VANISHES%^BOLD%^%^RED%^!%^RESET%^");
        }
        TO->clear_exits();            
    }
    TO->set("using_map", curMap);
    tmp_map = TO->query_exit_map(curMap);
    if(!mapp(tmp_map)) flag = 1;
    if(!flag) 
    {
        if(!sizeof(myExits = keys(tmp_map))) flag = 1;	
        for(x = 0; x < sizeof(myExits);x++)
        {
            if(tmp_map[myExits[x]] == BEXIT)
            {
                if(objectp(targ_room = find_object(BEXIT))) 
                {
                        if(!targ_room->query_property("being_adjusted")) targ_rooms += ({targ_room});
                }
                TO->add_exit(BEXIT, myExits[x]);
            }
            else
            {
                if(objectp(targ_room = find_object(BROOMS + tmp_map[myExits[x]]))) 
                {
                    if(!targ_room->query_property("being_adjusted")) targ_rooms += ({targ_room});
                }
                TO->add_exit(BROOMS + tmp_map[myExits[x]], myExits[x]);
                if(myExits[x] == "door")
                {
                    //tell_object(TO, "Should be setting a door....");
                    TO->set_door("door", BROOMS + tmp_map[myExits[x]], myExits[x]);
                    TO->set_door_description("door", HALLBD);
                    tell_room(TO, "%^BOLD%^%^BLACK%^A door %^BOLD%^%^YELLOW%^APPEARS%^BOLD%^%^BLACK%^!%^RESET%^");
                    continue;
                }
               // tell_object(TO, "Door did not get set....");
                continue;
            }   
        }
    }
    if(flag2) 
    {
        tell_room(TO, "%^BOLD%^%^CYAN%^Time suddenly speeds back up and you are finally able to move!%^RESET%^");
        all_living(TO)->set_paralyzed(0);
    }
    if(pointerp(targ_rooms)) 
    {
        for(x = 0;x < sizeof(targ_rooms);x++)
        {
            if(!objectp(targ_rooms[x])) continue;
            if(targ_rooms[x]->query_property("being_adjusted")) continue;
            targ_rooms[x]->check_adjustment();
            continue;
        }
    }
    TO->set_property("being_adjusted", -1);
    return;
}

void check_adjustment()
{
    int x, mapTime = 0;
    string *myExits, curMap, *tmp, *curMaps, using_map;
    if(base_name(TO) == BASEMENT || base_name(TO) == BR) return;	
    if(TO->query_property("being_adjusted")) return;
    curMaps = SAVE_D->query_array("haunted_house_map_state");
    tmp = SAVE_D->query_array("next_haunted_basement_change");
    if(!sizeof(tmp)) mapTime = 0;
    if(sizeof(tmp)) mapTime = tmp[0];
    if(time() >= mapTime) mapTime = 0;
    else mapTime -= time();
    using_map = TO->query("using_map");
    if(!sizeof(curMaps) || !mapTime) 
    {
        switch(random(3))
        {
            case 0:
                if(using_map != "mapone") curMap = "mapone";
                else curMap = "maptwo";
                break;
            case 1:
                if(using_map != "maptwo") curMap = "maptwo";
                else curMap = "mapthree";
                break;
            case 2:
                if(using_map != "mapthree") curMap = "mapthree";
                else curMap = "mapone";
                break;
        }
        mapTime = time() + 2100;		
        SAVE_D->remove_array("next_haunted_basement_change");
        SAVE_D->set_value("next_haunted_basement_change", mapTime);
        SAVE_D->remove_array("haunted_house_map_state");
        SAVE_D->set_value("haunted_house_map_state", curMap);
        mapTime -= time();
    }
    else curMap = curMaps[0];
    call_out("check_adjustment", mapTime);
    //if(!sizeof(TO->query_exits()) || (curMap != (string)TO->query("using_map"))) 
    if(curMap != (string)TO->query("using_map") && !TO->query_property("being_adjusted"))
    {	
        TO->adjust_room(curMap);
        TO->set_property("being_adjusted", 1);
    }
}

void create() 
{
    ::create();    
    //check_adjustment();
}

void reset()
{
    ::reset();
}

