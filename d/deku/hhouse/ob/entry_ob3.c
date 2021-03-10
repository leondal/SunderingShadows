#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

inherit OBJECT;

int delay;
string dest;

void create() 
{
    ::create();
    set_name("strange glowing door");
    set_id(({"door", "glowing door", "strange door",
    "strange glowing door", "doorway", "hhsaideentryobject"}));

    set_short("%^BOLD%^%^CYAN%^A strange %^BOLD%^%^YELLOW%^"+
    "glowing%^BOLD%^%^CYAN%^ door%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^This mysterious door wavers and "+
    "fades constantly, as if it could bl%^BOLD%^%^YELLOW%^i%^BOLD%^%^CYAN%^"+
    "nk out of %^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^x%^BOLD%^%^YELLOW%^i"+
    "%^BOLD%^%^WHITE%^s%^BOLD%^%^YELLOW%^t%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^"+
    "n%^BOLD%^%^WHITE%^c%^BOLD%^%^YELLOW%^e%^BOLD%^%^CYAN%^"+
    " at any moment. It is outlined "+
    "by what looks to be %^BOLD%^%^BLACK%^blackened bones%^BOLD%^%^CYAN%^ "+
    "that are cracked and chipped. There is no apparently method in which "+
    "in can be opened, instead you believe that you could simply "+
    "%^BOLD%^%^WHITE%^<%^BOLD%^%^MAGENTA%^enter%^BOLD%^%^WHITE%^>"+
    "%^BOLD%^%^CYAN%^ it, if you were so inclined. You believe "+
    "this doorway will take you %^BOLD%^%^RED%^downstairs%^BOLD%^%^CYAN%^"+
    " but that it is a one way journey.%^RESET%^");

    set_property("no animate",1);
    set_weight(0);
    set_heart_beat(1);
    delay = ((5+random(6)) * 60);
}

int get() { return 0; }

int set_delay(int x) { delay = x; }

int enter_function(string what) 
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(what)) return 0;
    if(stringp(what)) 
    {
        if(!TO->id(what)) return 0;
    }
    if(TO != present(what, ETO)) return 0;
	
    tell_object(TP, "%^BOLD%^%^BLUE%^Risking %^BOLD%^%^CYAN%^"+
    "life%^BOLD%^%^BLUE%^ and %^BOLD%^%^RED%^limb%^BOLD%^%^BLUE%^ "+
    "you bravely enter the doorway and find yourself "+
    "somewhere else!%^RESET%^");
	
    if(!TP->query_invis())
    {
        tell_room(ETO, "%^BOLD%^%^BLUE%^Risking %^BOLD%^%^CYAN%^"+
        "life%^BOLD%^%^BLUE%^ and %^BOLD%^%^RED%^limb%^BOLD%^%^BLUE%^ "+
        TPQCN+"%^BOLD%^%^BLUE%^ bravely enters the doorway and "+
        "vanishes!%^RESET%^", TP);
    }
    if(!stringp(dest)) 
    {
        tell_object(TP, "ERROR: Something went wrong with THIRD DOOR.");
        return 1;
    }
    TP->move(dest);
    if(!TP->query_invis())
    {
        tell_room(ETP, TPQCN +"%^BOLD%^%^CYAN%^ materializes out of thin air!%^RESET%^", TP);
    }
    TP->force_me("look");
    return 1;
}		

void init()
{
    ::init();   
    add_action("enter_function", "enter");
}

varargs void pick_room(string file)
{
    string *rooms, room, *tmp;
    object MyRoom;
    if(!objectp(TO)) return;
    if(!stringp(file)) rooms = get_dir(HHROOMS+"sfh*.c");
    if(objectp(ETO)) 
    {
        tell_room(ETO, TO->query_short() + "%^BOLD%^%^WHITE%^"+
        " wavers and shifts, then simply blinks out of "+
        "%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^x%^BOLD%^%^YELLOW%^i"+
        "%^BOLD%^%^WHITE%^s%^BOLD%^%^YELLOW%^t"+
        "%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^"+
        "n%^BOLD%^%^WHITE%^c%^BOLD%^%^YELLOW%^e%^BOLD%^%^WHITE%^!");
        if(sizeof(rooms)) 
        {
            tmp = explode(base_name(ETO), "/");
            rooms -= ({tmp[sizeof(tmp)-1]});
        }
    }
    if(!stringp(file)) 
    {
        room = rooms[random(sizeof(rooms))];
        room = HHROOMS + room;
    }
    else room = file;
    
    if(catch(MyRoom = find_object_or_load(room))) 
    {
        //tell_object(environment(previous_object()), "%^B_CYAN%^%^YELLOW%^ERROR: room for door 3 FAILED to LOAD%^RESET%^");
        return;
    }    
    if(!objectp(MyRoom)) 
    {
       //tell_object(environment(previous_object()), "%^B_CYAN%^%^YELLOW%^ERROR: room for door 3 FAILED to LOAD%^RESET%^");
        return;
    }
    if(!sizeof(MyRoom->query_exits()) && !strlen(MyRoom->query_long()))
    {
        //tell_object(environment(previous_object()), "Room "+identify(MyRoom)+ " has no exits before TO is placed.");
    }
    //move_object(TO, MyRoom);
    move_object(MyRoom);
    
    SAVE_D->remove_array("hhouse_entry_ob3");
    SAVE_D->set_value("hhouse_entry_ob3", TO);
    
    if(room != file) 
    {
        SAVE_D->remove_array("hhouse_entry_ob3_location");
        SAVE_D->set_value("hhouse_entry_ob3_location", room);
    }
    
    rooms = get_dir(HHROOMS+"ff*") - get_dir(HHROOMS+"ffr*") - get_dir(HHROOMS+"ffiw*");
    dest = HHROOMS + rooms[random(sizeof(rooms))];
    if(objectp(ETO)) 
    {
        tell_room(ETO, TO->query_short() + "%^BOLD%^%^WHITE%^"+
        " materializes here!%^RESET%^");
    }
    return;
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) pick_room();
    delay--;
    if(delay > 0) return;
    delay = ((5+random(6)) * 60);    
    pick_room();
    return;	  
}

