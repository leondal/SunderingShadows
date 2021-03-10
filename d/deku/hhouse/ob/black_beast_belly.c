#include <std.h>
#include "../inherits/area_stuff.h"
inherit ROOM;
object myBeast;
object myBeastRoom;
string myRoom;

void vomit()
{
    tell_room(TO, "%^BOLD%^%^GREEN%^You are suddenly vomitted forth from the stomach of "+
    "the beast!%^RESET%^");
    if(objectp(myBeast)) myBeast->destroy_rune();
    if(objectp(myBeastRoom)) all_inventory(TO)->move(myBeastRoom);
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
    set_name("Belly of the beast");
    set_short("Inside the belly of the black beast");
    set_property("no sticks",1);
    set_property("no teleport", 1);
    set_long("%^BOLD%^%^GREEN%^You are inside the belly of the "+
    "%^BOLD%^%^BLACK%^m%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^"+
    "nstr%^BOLD%^%^WHITE%^ou%^BOLD%^%^BLACK%^s bl%^BOLD%^%^WHITE%^"+
    "a%^BOLD%^%^BLACK%^ck b%^BOLD%^%^WHITE%^ea%^BOLD%^%^BLACK%^st%^BOLD%^%^GREEN%^. "+
    "You stand waist deep in a thick acidic goo that burns away "+
    "at your flesh with every moment you remain in here. "+
    "The walls around you are made a prohibitably thick fatty "+
    "black substance and you know there is no hope of ever "+
    "escaping from this place. You do not even spot the "+
    "slimy tube in which you were swallowed down. You have found "+
    "the place in which you will die.%^RESET%^");

    set_listen("default","The sound of bubbling goo and deep, "+
    "shallow breaths are all that you can hear.");
    set_smell("default","\nA stench beyond horrific invades all of "+
    "your senses.");
    call_out("check_contents", 5);
}

void init()
{
    ::init();
    add_action("quit_func", "quit");
}

int quit_func(string str)
{
    tell_object(TP, "%^BOLD%^%^RED%^You realize that leaving here would result in your death!%^RESET%^");
    return 1;
}

void set_my_beast(object targ)
{
    object rune;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    myBeast = targ;
    myBeastRoom = environment(targ);
    myRoom = base_name(myBeastRoom);
    if(!objectp(myBeast) || !objectp(myBeastRoom)) 
    {
        vomit();
    }
    else
    {
        rune = new(HHOB+"beast_rune");
        rune->move(TO);
    }
}

void check_contents()
{
    object *vics;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(myBeast)) 
    {
        vomit();
        return;
    }
    vics = all_living(TO);
    for(x = 0;x < sizeof(vics);x++)
    {
        if(vics[x]->query_true_invis()) continue;
        tell_object(vics[x], "%^BOLD%^%^RED%^You are burned by the acidic goo!%^RESET%^");
        vics[x]->cause_typed_damage(vics[x], 0, roll_dice(6, 10), "acid");
        continue;
    }
    call_out("check_contents", 5);
}



