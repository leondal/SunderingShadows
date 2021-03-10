#include <std.h>
#include "../inherits/area_stuff.h"
inherit CVAULT;
string crack_destination, cracked_wall;
void set_crack_destination(string str) { crack_destination = str; }
void set_cracked_wall(string str) { cracked_wall = str; }
string query_cracked_wall() { return cracked_wall; }
void assign_monsters()
{
    if(base_name(TO) != HALL && !random(2)) 
    { 
        switch(random(6)) 
        {
            case 0..1:
                set_monsters(({GY_MOBS +"ghoul", GY_MOBS+"gy_juju"}),({random(2) + 1, random(2) + 1}));                
                break;
            case 2:
                set_monsters(({GY_MOBS+"gy_juju", GY_MOBS+"gy_skeleton"}),({random(2) + 1, random(3) + 2}));                
                break;
            case 3:
                set_monsters(({GY_MOBS+"gy_babu", GY_MOBS+"gy_skeleton"}),({random(2) + 1, random(2) + 1}));
                break;
            case 4:
                set_monsters(({GY_MOBS+"ghoul", GY_MOBS+"gy_skeleton"}),({1 + random(2), 2 + random(2)}));                
                break;
            case 5:
                break;
            default: break;
        } 
        set_repop(roll_dice(6,10));
    }
}

void create() 
{
    assign_monsters();
    ::create();
    set_property("light",-1);
    set_property("indoors",1);
    set_terrain(CEMETERY);
    set_travel(FOOT_PATH);
    set_name("tunnel within the mausoleum of the damned");
    set_short("%^BOLD%^%^BLACK%^Tunnel within the mausoleum of the damned%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^You are within what you recognize instantly as "+
    "an unfinished section of the '%^BOLD%^%^RED%^mausoleum of the damned"+
    "%^BOLD%^%^BLACK%^'. There are portions of %^BOLD%^%^WHITE%^white stone"+
    "%^BOLD%^%^BLACK%^ which attaches roughly with a much older %^RESET%^"+
    "%^RED%^red stone%^BOLD%^%^BLACK%^. It appears that someone or "+
    "something had started replacing the old stone at some distance point "+
    "in the past before abruptly stopping. A %^RESET%^%^CYAN%^faint magic"+
    "%^BOLD%^%^BLACK%^ radiates outward from the %^RESET%^%^RED%^red stone"+
    "%^BOLD%^%^BLACK%^ providing a slightly disconcerting warmth. You are "+
    "not sure what this place used to be, but there is an almost overwhelming "+
    "sense of dr%^RESET%^%^RED%^ea%^BOLD%^%^BLACK%^d here. The walls are "+
    "very close together and the floor is rough. Surprising though this portion of "+
    "the mausoleum is withstanding the continous onslaught from the "+
    "dirt above remarkably well.%^RESET%^");
    
    set_listen("default","Eerie moans and groans echo all around you.");
    set_smell("default","The aroma of death and decay hangs heavily here."); 
     
    set_items(([
       ({"structure", "mausoluem" }) : "%^BOLD%^%^WHITE%^This ancient structure "+
       "has obviously been abandoned. It looks as if it were left in a half finished state. "+
       "There are portions of the white stone attached to an older red stone. The floor "+
       "is rough and the walls are much closer together here.%^RESET%^",
       ({"stone", "stones", "walls", "wall", "floor", "ceiling", 
       "white stone", "red stone"}) : "%^BOLD%^%^WHITE%^The stone "+
       "composing this portion of the mausoleum is mostly an older red stone. However, there "+
       "has been an almost pure white stone attached to portions of it. It leaves the "+
       "impression that someone or something was working on renovating this portion "+
       "of the of the mausoleum at some point in the distant past before "+
       "abruptly stopping. The older red stone provides a slightly disconcerting "+
       "warmth from a faint and ancient magic.%^RESET%^",        
    ] ));    
    
    set_property("traps_known_to_monsters", GY_MOBS);
    set_property("random trap frequency", 30);
    set_property("random traps", "mid");
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

string crack_description()
{
    string ret;
    ret = "%^BOLD%^%^WHITE%^ This large crack extends most of the height of the "+
    cracked_wall+"ern wall. You think that if you were desperate enough that you could "+
    "squeeze into it.%^RESET%^";
    return ret;
}

void reset()
{
    ::reset();
    assign_monsters();
    return;
}
