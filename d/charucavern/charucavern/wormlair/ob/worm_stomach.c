#include <std.h>
#include "../inherits/area_stuff.h"
#define FS WROOMS + "wormtun1_1"
inherit ROOM;
object myBeast;
object myBeastRoom;
string myRoom;
mapping MyStomachHealth;


void spill_out()
{
    tell_room(TO, "%^BOLD%^%^GREEN%^You suddenly spill out from the stomach of "+
    "worm!%^RESET%^");
    if(objectp(myBeastRoom)) all_inventory(TO)->move(myBeastRoom);
    else
    {
        if(stringp(myRoom)) all_inventory(TO)->move(myRoom);
        else all_inventory(TO)->move(FS);
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
    set_name("Stomach of a purple worm");
    set_short("Inside the stomach of a purple worm");
    set_property("no sticks",1);
    set_property("no teleport", 1);
    
    set_long("%^BOLD%^%^GREEN%^You are inside the stomach of a %^RESET%^"+
    "%^MAGENTA%^purple%^BOLD%^%^GREEN%^ worm. There is little room to move "+
    "within here and the thick flesh of the creature hugs you tightly. A thick "+
    "acidic slime covers you and threatens to cut off your ability to breath "+
    "if you do not get out of here soon. You think that you could probably "+
    "<%^BOLD%^%^RED%^claw%^BOLD%^%^GREEN%^> your way out of here. You think that "+
    "it will not be a pleasant experience, but neither is the alternative should "+
    "you remain here much longer.%^RESET%^");

    set_listen("default","The sound of rumbling echoes all around you.");
    set_smell("default","\nThe smell of rot and decay invades your senses.");
    
    call_out("check_contents", 5);
    
}

void init()
{
    ::init();
    add_action("quit_func", "quit");
    add_action("claw_func", "claw");
}

int damage_stomach(object who, int dam)
{
    int x;
    if(!objectp(who)) return 0;
    if(!mapp(MyStomachHealth))
    {
        MyStomachHealth = ([who : (40 - dam)]);
    }
    else if(MyStomachHealth[who])
    {
        x = MyStomachHealth[who];
        x -= dam;
        MyStomachHealth[who] = x;
    }
    else
    {
        MyStomachHealth += ([who : (40 - dam)]);
    }
    x = MyStomachHealth[who];
    if(x <= 0) 
    {
        map_delete(MyStomachHealth, who);
        x = 0;
    }
    return x;
}


int claw_func(string str)
{
    int health;
    if(!objectp(TP)) return 0;
    
    TP->set_paralyzed(8, "%^BOLD%^%^RED%^You are busy trying to claw your way out!%^RESET%^");
    switch(random(3)) 
    {
        case 0:
            tell_object(TP, "%^BOLD%^%^BLACK%^You claw and tear at the thick flesh!%^RESET%^");
            break;
        case 1:
            tell_object(TP, "%^BOLD%^%^RED%^You rip and claw at the thick flesh, desperately trying to free yourself!%^RESET%^");
            break;
        case 2:
            tell_object(TP, "%^BOLD%^%^GREEN%^You claw with all of your might at the thick flesh, trying to tear a way out!%^RESET%^");
            break;
    }
    health = damage_stomach(TP, roll_dice(1, 12));
    if(health <= 0) 
    {
        if(objectp(myBeast))
        {
            tell_room(environment(myBeast), "%^BOLD%^%^WHITE%^A hole is suddenly %^BOLD%^%^RED%^ripped%^BOLD%^%^WHITE%^ "+
            "in the flesh of "+myBeast->query_short()+" and "+TP->QCN+" crawls out!%^RESET%^");
        }
        tell_object(TP, "%^BOLD%^%^WHITE%^You manage to %^BOLD%^%^RED%^tear%^BOLD%^%^WHITE%^ a hole in the "+
        "flesh and quickly crawl through it!%^RESET%^");
        if(objectp(myBeastRoom))
        {
            TP->move(myBeastRoom);
        }
        else
        {
            if(stringp(myRoom)) TP->move(myRoom);
            else TP->move(FS);
        }
        TP->force_me("look");
        if(objectp(myBeast)) 
        {
            tell_room(ETP, "%^BOLD%^%^BLACK%^The hole in the side of "+myBeast->query_short()+"%^BOLD%^%^BLACK%^ "+
            "instantaneously %^BOLD%^%^WHITE%^seals%^BOLD%^%^BLACK%^ itself shut!%^RESET%^");
            return 1;
        }
        return 1;       
    }
    return 1;
}

int quit_func(string str)
{
    tell_object(TP, "%^BOLD%^%^RED%^You realize that quitting here would likely result in your death!%^RESET%^");
    return 1;
}

void set_my_room(object targ)
{
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    myBeastRoom = targ;
}

void set_my_worm(object targ, object vic)
{
    object rune;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    myBeast = targ;
    myBeastRoom = environment(targ);
    myRoom = base_name(myBeastRoom);
    if(!objectp(myBeast) || !objectp(myBeastRoom) || !objectp(vic)) 
    {
        spill_out();
    }
    if(!mapp(MyStomachHealth)) MyStomachHealth = ([vic : 40]);
    else if(MyStomachHealth[vic]) MyStomachHealth[vic] = 40;
    else MyStomachHealth += ([vic : 40]);
}

void check_contents()
{
    object *vics;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(myBeast)) 
    {
        spill_out();
        return;
    }
    vics = all_living(TO);
    for(x = 0;x < sizeof(vics);x++)
    {
        if(vics[x]->query_true_invis()) continue;
        if(!interactive(vics[x])) 
        {
            vics[x]->force_me("claw");
        }
        tell_object(vics[x], "%^BOLD%^%^RED%^You are burned by the thick %^BOLD%^%^GREEN%^"+
        "acidic%^BOLD%^%^RED%^ slime!%^RESET%^");
        vics[x]->cause_typed_damage(vics[x], 0, roll_dice(2, 8), "acid");
        continue;
    }
    if(objectp(myBeast)) 
    {
        if(environment(myBeast) != myBeastRoom) myBeastRoom = environment(myBeast);
    }
    call_out("check_contents", 5);
}



