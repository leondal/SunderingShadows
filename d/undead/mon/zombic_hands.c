#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    ::create();
    set_name("Zombic Hand");
    set_id(({"hands","hand","zombie","zombic"}));
    set_short("%^YELLOW%^Zombic Hand%^RESET%^");
    set_long("This hand is all that remains of some poor soul who strayed too far "
        "from the stable paths within the bog. They were pulled under and "
        "transformed into Zombies. Now, thier only purpose is to pull others to "
        "the same fate that befell them.");
    set_overall_ac(3);
    set_race("zombic hand");
    set_body_type("hand");
    add_limb("palm","palm",0,0,0);
    add_limb("index finger","index finger",0,0,0);
    add_limb("middle finger","middle finger",0,0,0);
    add_limb("ring finger","ring finger",0,0,0);
    add_limb("pinky finger","pinky finger",0,0,0);
    add_limb("thumb","thumb",0,0,0);
    set_hd(15,8);
    set_max_hp(50);
    set_hp(50);
    set_exp(5000);
    set_new_exp(25,"normal");
    set_size(1);
    set_stats("strength",18);
    set_attacks_num(2);
    set_attack_limbs(({"palm","index finger","middle finger","ring finger","pinky finger","thumb"}));
    set_property("no dominate",1);
    set_alignment(9);
    set_emotes(9,({"%^RED%^The Hands begin to %^BOLD%^claw%^RESET%^%^RED%^ at your ankles!",
        "%^BOLD%^You hear a %^BLUE%^moaning%^RESET%^%^BOLD%^ from beneath the surface of the bog!",}),1);
    set("aggressive","aggfunc");
    set_resistance("negative energy",5);
    set_resistance("positive energy",-5); 
}

void aggfunc() 
{
    if(!objectp(TP)) { return; }
    if(TP->query_true_invis()) { return; }
    call_out("pull1",1,TP);
    TO->kill_ob(TP,1);
}

void pull1(object targ) 
{
    if(!objectp(targ))      { return; }
    if(!objectp(TO))        { return; }
    if(!present(targ,ETO))  { return; }    
    tell_object(targ,"%^BLUE%^The Hands now have you firmly in thier grasp!");
    tell_room(ETO,"%^BLUE%^The Hands have siezed "+targ->QCN+"'s ankles firmly!",targ);
    call_out("pull2",35,targ);
}

void pull2(object targ) 
{
    if(!objectp(targ))      { return; }
    if(!objectp(TO))        { return; }
    if(!present(targ,ETO))  { return; }
    tell_object(targ,"%^RED%^The Hands are pulling you down %^BOLD%^through%^RESET%^%^RED%^ the surface!");
    tell_room(ETO,"%^RED%^"+targ->QCN+" is being pulled through the surface!%^RESET%^",targ);
    call_out("pull3",40,targ);
}

void pull3(object targ) 
{
    if(!objectp(targ))      { return; }
    if(!objectp(TO))        { return; }
    if(!present(targ,ETO))  { return; }
    tell_object(targ,"%^YELLOW%^Suddenly you feel the floor of the bog fall out from under you, and the water begins to fill your lungs as you slowly fade out.");
    tell_room(ETO,"%^YELLOW%^"+targ->QCN+" is pulled beneath the surface!",targ);
    targ->set_paralyzed(100,"You are under the bog, you can't breathe!");
    targ->move_player(MAZ"room");
    call_out("pull4",20,targ);
    return 1;
}

void pull4(object targ)
{
    if(!objectp(targ))      { return; }
    if(!objectp(TO))        { return; }
    if(!present(targ,ETO))  { return; }
    targ->set_paralyzed(0);
    tell_object(targ,"%^YELLOW%^You have been pulled through the bog and into a maze!");
    tell_room(environment(targ),"%^YELLOW%^Drops to the floor, a sloppy mess from the "
        "bog above!%^RESET%^",targ);
    return;
}

void init()
{
    string *exits;
    int i,j;

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!objectp(TP)) { return; }
    if(!interactive(TP)) { return; }

    ::init();
    exits = ETO->query_exits();
    j = sizeof(exits);
    for(i=0;i<j;i++)
    add_action("noway",exits[i]);
}

int noway(string str)
{
    if (TO->query_hp() < 0) 
    {
        while (remove_call_out("pull1") != -1) ;
        while (remove_call_out("pull2") != -1) ;
        while (remove_call_out("pull3") != -1) ;
        TO->die();
        return 0;
    }
    write("%^YELLOW%^You cannot escape the grip of the Hands!");
    tell_room(ETO,"%^YELLOW%^"+TPQCN+" struggles but cannot escape the grip of the hands",TP);
    return 1;
}
