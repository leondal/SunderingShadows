#include <std.h>
#include "../inherits/area_stuff.h"
inherit ROOM;
object myOrigin, myWeb;
string myRoom;
int myHealth;

void expel()
{
    tell_room(TO, "%^BOLD%^%^GREEN%^The web around you suddenly gives "+
    "away and you are freed!%^RESET%^");
    if(objectp(myWeb)) myWeb->destroy();
    if(objectp(myOrigin)) all_inventory(TO)->move(myOrigin);
    else
    {
        if(stringp(myRoom)) all_inventory(TO)->move(myRoom);
        else all_inventory(TO)->move(FFROOMS+"1");
    }
    TO->remove();
}

void create() 
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("Inside the glowing web");
    set_short("Inside the glowing web");
    set_property("no sticks",1);
    set_property("no teleport", 1);
    set_long("%^BOLD%^%^GREEN%^You are surrounded by the %^BOLD%^"+
    "%^CYAN%^glowing%^BOLD%^%^GREEN%^ mass of thick web and it clings tightly "+
    "to you. If you have any hope of getting out of here your best bet "+
    "is to <%^BOLD%^%^CYAN%^tear%^BOLD%^%^GREEN%^> at the strands and hope "+
    "for the best.%^RESET%^");

    set_listen("default","Sounds are muffled by the exceedingly "+
    "thick web.");
    set_smell("default","\nDecay lingers in the air.");
    call_out("check_contents", 8);
    myHealth = 125 + random(46);
}

void init()
{
    ::init();
    add_action("tear_act", "tear");
    add_action("quit_func", "quit");
}

int quit_func(string str)
{
    tell_object(TP, "%^BOLD%^%^RED%^You realize that leaving here would result in your death!%^RESET%^");
    return 1;
}

void damage_web(int amt)
{
    myHealth += amt;
    tell_room(TO, "%^BOLD%^%^WHITE%^You feel the mass of web shaking as strands "+
    "are torn away from the outside!%^RESET%^");
    if(myHealth <= 0) expel();
}
int query_web_health() { return myHealth; }

int tear_act(string arg)
{
    int dam;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    dam = (int)TP->query_stats("strength") + (int)TP->query_stats("dexterity");
    dam += roll_dice(1, 20);
    myHealth -= dam;

    tell_object(TP, "%^BOLD%^%^WHITE%^You quickly tear away strands of the web, struggling "+
    "to break free!%^RESET%^");

    TP->set_paralyzed(8, "%^BOLD%^%^WHITE%^You are tearing away strands of the web!%^RESET%^");
    if(objectp(myWeb)) myWeb->struggling();

    if(myHealth <= 0) 
    {
        expel();
    }
    return 1;
}

void set_origin(object ob)
{
    if(!objectp(TO)) return;
    if(!objectp(ob)) 
    {
        expel();
        return;
    }
    myOrigin = ob;
    myRoom = base_name(ob);
    return;
}

void set_web(object ob)
{
    if(!objectp(TO)) return;
    if(objectp(ob)) 
    {
        myWeb = ob; 
    }
    return;
}

void check_contents()
{
    if(!objectp(TO)) return;
    if(!objectp(myOrigin) || !stringp(myRoom)) 
    {
        expel();
        return;
    }
    call_out("check_contents", 8);
}



