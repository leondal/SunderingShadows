#include <std.h>
#include <daemons.h>
#include "area_stuff.h"
#include <move.h>
inherit ROOM;
int searched;

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_property("no teleport", 1);
    set_property("scry proof", 1);
    set_climate("arctic");
    set_name("Inside an ebon chamber");
    set_short("%^BOLD%^%^BLACK%^Inside a %^BOLD%^%^CYAN%^fr%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^g"+
    "%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^d%^BOLD%^%^BLACK%^ ebon chamber%^RESET%^");
    
    
    set_long("%^BOLD%^%^BLACK%^You find yourself in a very large chamber composed of interlocked "+
    "%^BOLD%^%^WHITE%^ebon stones%^BOLD%^%^BLACK%^. The very first thing that you notice here is that "+
    "it is freezing, a %^BOLD%^%^CYAN%^cold%^BOLD%^%^BLACK%^ and %^BOLD%^%^CYAN%^frigid%^BOLD%^%^BLACK%^ "+
    "air hangs heavily in here, almost as if it has been somehow trapped by the %^BOLD%^%^WHITE%^stones"+
    "%^BOLD%^%^BLACK%^ or perhaps it is radiating outward from the stones. Strange %^BOLD%^%^CYAN%^"+
    "symbols%^BOLD%^%^BLACK%^ cover everything, you get the sense that they are serving as some "+
    "type of %^BOLD%^%^CYAN%^ward%^BOLD%^%^BLACK%^ but for what you are not sure. The entire chamber "+
    "looks ancient but seems so sturdy that no amount of time would ever have the power to erode it. "+
    "Entire suits of armor and large weapons are embedded in the walls, they look un-movable, even by "+
    "the mightiest of creatures. You are unsure what has caused them to become part of this chamber but "+
    "the %^BOLD%^%^CYAN%^symbols%^BOLD%^%^BLACK%^ cover them as well.%^RESET%^");
    

    set_listen("default", "%^CYAN%^\nYour footsteps echo through the chamber and loud "+
    "cracking sounds are heard all around you.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nThis place smells ancient and an odor of stagnation hangs "+
    "heavily here.%^RESET%^");

    set_items(([
        ({"symbols", "glowing symbols", "strange symbols", "ward"}) : "%^BOLD%^%^CYAN%^These strange symbols cover "+
        "everything in this chamber. They are not in any language that you have ever before encountered, in fact "+
        "you are unsure if they actually mean that you could understand at all. You do get some sense that they are "+
        "serving as a ward of some type, though you are not sure for what. Simply looking at them "+
        "fills you with a strong urge to %^BOLD%^%^BLACK%^observe%^BOLD%^%^CYAN%^ them. %^RESET%^",
        
        ({"chamber", "large chamber", "stones", "ebon stones", "walls", "floor", "ceiling"}) : "%^BOLD%^%^BLACK%^This chamber is massive and "+
        "composed entirely of interlocked ebon stones. The floor, the ceiling, and the walls are composed of these "+
        "same stones. Each is covered with %^BOLD%^%^CYAN%^strange symbols%^BOLD%^%^BLACK%^ and each is giving "+
        "off a %^BOLD%^%^WHITE%^freezing cold aura%^BOLD%^%^BLACK%^, which chills the entire chamber. The chamber "+
        "looks ancient but seems so sturdy that not even time would be enough to erode the stones which compose "+
        "it.%^RESET%^",
        
        ({"suits of armor", "large weapons", "armor"}) : "%^BOLD%^%^WHITE%^These ancient weapons and armor are "+
        "actually embedded in the ebon stone. It looks almost like the stone has grown around them and a slight layer "+
        "of stone has actually grown over the top of them. You are not sure how they were ever embedded in the walls but "+
        "you do not believe that they will ever be removed. They too are covered by the %^BOLD%^%^CYAN%^strange "+
        "symbols%^BOLD%^%^WHITE%^. You could search them but you are not sure if you would find anything worthwhile.%^RESET%^",      
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    
    set_property("traps_known_to_monsters", ELMON);
    set_property("random trap frequency", 15);
    set_property("random traps", "epic");
    set_search("default", "%^BOLD%^%^WHITE%^The large weapons and suits of armor might be worth searching.%^RESET%^");
    set_search("armor", (:TO, "armweapsrch":));
    set_search("large weapons", (:TO, "armweapsrch":));
    set_search("suits of armor", (:TO, "armweapsrch":));
    searched = random(8);
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^CYAN%^A frigid cold hangs heavily here.%^RESET%^";
}

void init()
{
    ::init();
    add_action("observe_symbols", "observe");
}

int armweapsrch(string str)
{
    object ob;
    string roomname;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!TP->query_invis())
    {
        tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ carefully searches the "+str+".%^RESET%^", TP);
    }
    if(searched != 1) 
    {
        if(!random(3))
        {
            tell_object(TP, "%^BOLD%^%^CYAN%^A disembodied voice whispers to you: %^RESET%^the first in the series is '%^BOLD%^nif%^RESET%^'.....");
        }
        tell_object(TP, "%^BOLD%^%^WHITE%^You carefully search the "+str+", but find nothing "+
        "that you could take and nothing worthwhile.%^RESET%^");
        searched = 0;
        if(!TP->query_invis()) tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ doesn't seem to find anything of value..%^RESET%^", TP);
        return 1;
    }
    searched = 0;
    if(!random(3))
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^A disembodied voice whispers to you: %^RESET%^the first in the series is '%^BOLD%^nif%^RESET%^'.....");
    }
    ob = new(ELOB+"orb");
    roomname = base_name(TO);
    if(strsrch(roomname, "tomb1_") != -1) ob->make_type("frozen");
    else if(strsrch(roomname, "tomb2_") != -1) ob->make_type("raging");
    else if(strsrch(roomname, "tomb3_") != -1) ob->make_type("burning");
    else if(strsrch(roomname, "tomb4_") != -1) ob->make_type("smoky");
    tell_object(TP, "%^BOLD%^%^WHITE%^You find a "+ob->query_short()+" hidden among the "+str+"!%^RESET%^");
    if(ob->move(TP) != MOVE_OK) 
    {
        tell_object(TP, "%^BOLD%^%^BLACK%^You drop the "+ob->query_short()+"!%^RESET%^");
        ob->move(TO);
    }
    if(!TP->query_invis()) tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ finds a "+ob->query_short()+" hidden among the "+str+"!%^RESET%^", TP);
    return 1;    
}


int observe_symbols(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    if(str != "symbols" && str != "strange symbols" && str != "glowing symbols") { return 0; }
    if (TP->query_bound() || 
    TP->query_unconscious() || 
    TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if(present("eldebarosymbolobservationxxsaide", TP))
    {
        tell_object(TP, "You are already observing the symbols!");
        return 1;
    }
    ob = new(ELOB+"symbol_observation");
    ob->move(TP);
    ob->start_observing();
    
    return 1;
}

void reset()
{
    ::reset();
    if(random(2)) return;
    if(!present("block of ice", TO)) 
    {
        new(ELOB+"ice_block")->move(TO);
        if(random(2)) new(ELOB+"ice_block")->move(TO);
        if(random(2)) new(ELOB+"ice_block")->move(TO);
    }
    searched = random(8);
}