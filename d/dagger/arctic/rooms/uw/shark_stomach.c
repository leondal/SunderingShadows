#include <std.h>
#include "../../arctic.h"
inherit UNDERWATER;

void get_ring();

int FLAG;

void create()
{
    ::create();
    set_name("Inside a shark's stomach");
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_terrain(DEEP_WATER);
    set_travel(RUTTED_TRACK);
    set_property("light", -1);
    
    set_short("%^RED%^Inside a shark's stomach%^RESET%^");
        
    set_long("%^RED%^The bulbous lining of the sharks stomach "
        "presses against your sides and the acid burns you brutally.  "
        "Half digested remains of fish and humanoids and other unidentified "
        "creatures float in acrid stomach juices at waist level.  You know "
        "you must get out of here or be slowly digested alive!%^RESET%^");
    
    set_items(([
                "remains" : "%^RESET%^%^BOLD%^One set of humanoid remains has what "
                "appears to be a ring on the index finger.%^RESET%^",
                "ring" : "%^RESET%^%^BOLD%^The ring looks to be made of a green material.  "
                "Perhaps you could retrieve it.%^RESET%^"
              ]));
                
    
    set_smell("default", "The acidic smell of the digestive juices is overpowering.");
    set_listen("default", "You can hear the churning and grumbling of the sharks stomach.");


}

void init()
{
    ::init();
    add_action("get_ring", "retrieve");
    return;
}

void get_ring()
{
    object ob;

    if(!FLAG)
    {
        tell_object(TP, "%^RESET%^%^BOLD%^You manage to slip the ring off the "
            "half digested remains of some unfortunate humanoid creature.");
        tell_room(ETP, "%^RESET%^%^BOLD%^"+TP->QCN+" slips a ring off the "
            "finger of the half digested remains floating in the stomach juices.%^RESET%^", TP);
        ob = new(OBJ"lesserjade");
        ob->move(TO);
        FLAG = 1;
        return 1;
    }

    tell_object(TP, "%^RESET%^%^BOLD%^Someone has already retrieved the ring.%^RESET%^");
    return 1;
}

void set_functions()
{
    set_pre_exit_functions(({"gash"}),({"enter_gash"}));
    return;
}

int enter_gash()
{
    tell_object(TP, "%^RED%^You squirm your way out of the gash in "
        "the belly of the shark!%^RESET%^");
    tell_room(ETP, "%^RED%^"+TP->QCN+" squirms "+TP->QP+" way out of "
        "the gash in the belly of the shark!%^RESET%^", TP);
    return 1;

}