#include <std.h>
#include "../arctic.h"
inherit CREATURE;

int hide = 0;

void create() 
{
        
    ::create();
    set_name("Yeti");
    set_id(({"Yeti", "yeti", "arcticmon"}));
    set_race("yeti");
    set_body_type("human");
    set_gender((random(2)?"male":"female"));
    set_size(3);
    set_short("yeti");
    set_long("%^RESET%^%^BOLD%^Shaggy white fur covers the body of the yeti "
             "making it very difficult to see in the snow.  "
             "The beast stands close to eight feet tall when "
             "on two feet, and weighs close to three hundred "
             "pounds.  Two very light blue eyes peer out from "
             "behind a protruding brow.  It has two huge clawed "
             "hands and fanglike teeth.%^RESET%^");
    set_hd(25,1);
    set_level(25);
    set_class("fighter");
    set_mlevel("fighter", 25);
    set_hp((random(250)+250));
    set_exp(5000);
    set_property("swarm", 1);
    set_overall_ac(-5);
    set_stats("strength",18);
    set_stats("dexterity",12);
    set_stats("intelligence",8);
    set_stats("wisdom",8);
    set_stats("constitution",21);
    set_stats("charisma",5);
    set_attacks_num(4);
    set_damage(3,3);
    set_base_damage_type("bludgeoning");
    add_limb("left claw", "left hand", 0, 0, 0);
    add_limb("right claw", "right hand", 0, 0, 0);
    add_limb("fangs", "head", 0, 0, 0);
    set_attack_limbs(({"right claw","left claw","fangs"}));
    set("aggressive", 20);
    set_speed(30);
    nogo("NOGO1");
    add_money("gold",random(100)+100);
    add_money("silver",random(1000)+1000);
    add_money("electrum",random(100)+100);
    set_resistance("cold",10);
}


void saveth(object obj)
{
    if(!ROLLSAVE(obj, PPD))
    {
        tell_object(obj,"%^CYAN%^You are frozen with "
        "fear as you stare into the eyes of the yeti!%^RESET%^");
        tell_room(ETO,"%^CYAN%^"+obj->QCN+" stares into the eyes of the "
        "yeti and freezes in place!%^RESET%^",obj);
        TP->set_paralyzed(20,"You are frozen in fear!.");
        return;
    }
    tell_object(obj, "%^CYAN%^You look into the eyes "
    "of the yeti but quickly turn away!%^RESET%^");
    tell_room(ETO,"%^CYAN%^"+obj->QCN+" looks into the eyes of the "
    "yeti buy quickly turns away!%^RESET%^",obj);
    return;
}

void init() 
{
    ::init();
    if(TP->query_invis() && !TP->query_true_invis() && TO->query_invis() && !TP->id("arcticmon")) //had to use !TP to preventy them from checking their own id()
    {
        tell_room(ETO, "%^RED%^A yeti appears suddenly and "
        "attacks!%^RESET%^");
        TO->set_hidden(0);
        hide = 0;
        kill_ob(TP,1);
        saveth(TP);
        return;
    }
}

void heart_beat() 
{    
    ::heart_beat();

    if(!objectp(TO)) { return; }

    if(!TO->query_invis() && sizeof(TO->query_attackers()) == 0) 
    {
        if(hide == 0) 
        {
            hide = 1; 
            if(!random(5)) 
            { 

                TO->set_hidden(1); 
                return;
            }
        }
    }

    if(TO->query_invis() && sizeof(TO->query_attackers()) > 0) 
    {
        hide = 0;
        TO->set_hidden(0);
        return;
    }

    if(sizeof(TO->query_attackers()) > 0) { hide = 0; return; }

    if(!random(100)) { hide = 0; return; }

    return;
}

