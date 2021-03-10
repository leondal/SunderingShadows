#include <std.h>
#include "../inherits/area_stuff.h"
inherit CVAULT;
string crack_destination, cracked_wall;
void set_crack_destination(string str) { crack_destination = str; }
void set_cracked_wall(string str) { cracked_wall = str; }
string query_cracked_wall() { return cracked_wall; }
void create() 
{
    PUZZLE_D->assign_puzzles();
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_name("a tomb within the mausoleum of the damned");
    set_short("%^BOLD%^%^BLACK%^Tomb within the mausoleum of the damned%^RESET%^");
    set_listen("default","Eerie moans and groans echo all around you.");
    set_smell("default","The aroma of death and decay hangs heavily here.");        
    set_long((:TO, "get_my_long":));
    PUZZLE_D->query_puzzle_description(TO);
}

string get_my_long()
{
    string ret;
    ret = PUZZLE_D->query_puzzle_description(TO);
    return ret;
}

string crack_description()
{
    string ret;
    ret = "%^BOLD%^%^WHITE%^These cracks litter the walls, the ceiling, and "+
          "even the floor of this once grand tomb. A permanent testmant to the abandonment "+
          "that it has suffered.%^RESET%^";
          
    if(crack_destination && cracked_wall)
    {
       ret += "%^BOLD%^%^WHITE%^ You notice that there is a much larger crack on the "+
       cracked_wall+"ern wall. You think that if you were desperate enough that you could "+
       "squeeze into it.%^RESET%^";
    }
    return ret;
}

void init()
{
    ::init();
    add_action("squeeze", "squeeze");
}

int squeeze(string str)
{
    string tar;
    object myDest;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    if(!stringp(crack_destination)) return 0;
    if(!stringp(cracked_wall)) return 0;
    if(file_exists(MAUS+crack_destination)) return 0;
    if(sscanf(str, "into %s", tar) != 1)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Try squeeze into "+cracked_wall+" crack.%^RESET%^");
        return 1;
    }
    if(tar != cracked_wall + " crack") 
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You cannot squeeze into the "+tar+".%^RESET%^");
        return 1;
    }
    if(!objectp(myDest = find_object_or_load(MAUS+crack_destination)))
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^There is something wrong with the destination. Notify Saide.%^RESET%^");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^WHITE%^You carefully squeeze into the "+tar+".%^RESET%^");
    if(!TP->query_invis()) 
    { 
        tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ carefully squeezes into "+
        "the "+tar+"!%^RESET%^", TP);
    }
    TP->move_player(myDest);
    if(!TP->query_invis()) 
    {
        tell_room(ETP, TPQCN+"%^BOLD%^%^WHITE%^ crawls out of a crack on the "+
        ETP->query_cracked_wall()+"ern wall!%^RESET%^", TP);
    }
    return 1;
}

void reset()
{
    ::reset();
    PUZZLE_D->assign_puzzles();
}


