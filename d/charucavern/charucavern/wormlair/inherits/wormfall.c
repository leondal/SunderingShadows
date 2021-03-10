#include <std.h>
#include "area_stuff.h"
#include <daemons.h>
#include <move.h>
#include </d/common/common.h>

inherit VAULT;

int position_in_tunnel;
string fall_to, grab_onto, land_on;

void create() 
{
    ::create();
}

int set_position(int x) { position_in_tunnel = x;}
int query_pos() { return position_in_tunnel; }
void set_fall_to(string loc) { fall_to = WROOMS+loc; }
void set_grab_onto(string str) { grab_onto = str; }
void set_land_on(string str) { land_on = str; }
int query_grab_onto() 
{
    if(stringp(grab_onto)) return 1;
    return 0;
}
int query_land_on()
{
    if(stringp(land_on)) return 1;
    return 0;
}

mixed build_grid()
{
    string myLoc, *tmp, roomName;
    int x, start;
    mapping myGrid;
    if(!objectp(TO)) return;
    myLoc = base_name(TO);
    tmp = explode(myLoc, "_");
    if(sizeof(tmp) != 2) return;
    start = tmp[1];
    roomName = tmp[0];
    myGrid = ([]);
    start = to_int(start);
    while(start <= 6)
    {
        if(!file_exists(roomName +"_" + start+".c"))
        {
            start++;
            continue;
        }
        if((roomName + "_" + start) == fall_to) 
        {
            start++; 
            continue;
        }
        if(!sizeof(keys(myGrid))) myGrid = ([ start : roomName + "_" + start ]);
        else myGrid += ([ start : roomName + "_" + start ]);
        start++;
    }
    if(sizeof(keys(myGrid))) myGrid += (["land" : fall_to]);
    else myGrid = (["land" : fall_to]);
    return myGrid;
}


int climb_ok(string verb) 
{
    string *tmp;
    mapping myGrid;
    int start, dam, suc;
    myGrid = build_grid();
    if(!mapp(myGrid)) return 1;
    if(!objectp(TO)) return 1;
    tmp = explode(base_name(TO), "_");
    if(sizeof(tmp) != 2) return 1;
    if(!objectp(TP)) return 1;
    start = tmp[1];
    start = to_int(start);
    
    suc = CLIMB_D->check_climb(10 + roll_dice(1, 10) + roll_dice(1, 10) + roll_dice(1, 10), TP);
    //suc = -1;
    //suc = 0;
    if (suc == -1) 
    {    
        //tell_room(TO, "Landing spot = "+identify(myGrid["land"]));
        if(base_name(TO) != myGrid["land"]) 
        {   
            tell_room(TO, TPQCN+"%^RESET%^%^ORANGE%^ falls into the %^BOLD%^%^BLACK%^darkness!%^RESET%^", TP);
            tell_object(TP, "%^RESET%^%^ORANGE%^You fall into the %^BOLD%^%^BLACK%^darkness!%^RESET%^");
        }
        start++;
        dam = roll_dice(1, 12);
        while(start <= 6)
        {
            if(!myGrid[start])
            {
                start++;
                continue;
            }
            TP->move(myGrid[start]);
            if(!TP->query_invis()) tell_room(ETP, TPQCN+"%^RESET%^%^ORANGE%^ falls into the %^BOLD%^%^BLACK%^darkness!%^RESET%^", TP);
            tell_object(TP, "%^RESET%^%^ORANGE%^You continue falling into the %^BOLD%^%^BLACK%^darkness!%^RESET%^");
            dam += roll_dice(1, 12);
            start++;
        }
        if(base_name(TO) != myGrid["land"]) 
        {
            TP->move(myGrid["land"]);
            if(!TP->query_invis()) tell_room(ETP, TPQCN+"%^RESET%^%^ORANGE%^ falls from the passageway and slams into the "+land_on+"!%^RESET%^", TP);
            tell_object(TP, "%^RESET%^%^ORANGE%^You slam into the "+land_on+"!%^RESET%^");
        }
        else 
        {
            if(!TP->query_invis()) tell_room(ETP, TPQCN+"%^RESET%^%^ORANGE%^ falls and slams into the "+land_on+"!", TP);
            tell_object(TP, "%^RESET%^%^ORANGE%^You fall and slam into the "+land_on+"!%^RESET%^");
        }      
        
        TP->cause_typed_damage(TP, "torso", dam, "untyped");
        TP->force_me("look");
        return 0;
    }    
    if (suc == 0) 
    {
        if(base_name(TO) != myGrid["land"]) 
        {   
            tell_room(TO, TPQCN+"%^RESET%^%^ORANGE%^ falls into the %^BOLD%^%^BLACK%^darkness!%^RESET%^", TP);
            tell_object(TP, "%^RESET%^%^ORANGE%^You fall into the %^BOLD%^%^BLACK%^darkness!%^RESET%^");
        }
        start++;
        dam = roll_dice(1, 12);
        if(start <= 6) 
        {
            dam += roll_dice(1, 12);
            tell_object(TP, "%^RESET%^%^ORANGE%^You manage to grab hold "+grab_onto+"!%^RESET%^");
            TP->move(myGrid[start]);
            if(!TP->query_invis()) tell_room(ETP, TPQCN+"%^RESET%^%^ORANGE%^ falls from the %^BOLD%^%^BLACK%^darkness%^RESET%^"+
            "%^ORANGE%^ above and manages to grab hold "+grab_onto+"!%^RESET%^");
        }
        else
        {
            dam+= roll_dice(1, 12);
            if(base_name(TO) != myGrid["land"]) 
            {
                TP->move(myGrid["land"]);
                if(!TP->query_invis()) tell_room(ETP, TPQCN+"%^RESET%^%^ORANGE%^ falls from the passageway and slams into the "+land_on+"!%^RESET%^", TP);
                tell_object(TP, "%^RESET%^%^ORANGE%^You slam into the "+land_on+"!%^RESET%^");
            }
            else 
            {
                if(!TP->query_invis()) tell_room(ETP, TPQCN+"%^RESET%^%^ORANGE%^ falls and slams into the "+land_on+"!", TP);
                tell_object(TP, "%^RESET%^%^ORANGE%^You fall and slam into the "+land_on+"!%^RESET%^");
            }
            
        }
        TP->cause_typed_damage(TP, "torso", dam, "untyped");
        TP->force_me("look");
        return 0;
    }
    return 1;
}


void reset()
{
	::reset();
}
