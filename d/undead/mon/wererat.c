#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
   ::create();
   set_name("Were-Rat");
   set_id(({"were-rat","rat","were"}));
   set_short("%^BOLD%^A Were-Rat%^RESET%^");
   set_long("The Were-Rat are creatures of cowardice and shadow.  They always prefer "
        "to attack an injured foe, and will very often run away of the odds turn "
        "against them.  However, when backed into a corner, the Were-Rat is a truly "
        "dangerous creature.  In it's main form, it's body is covered in an oily "
        "fur.  It is about the size of a normal man and has about as much "
        "intelligence.");
   set_overall_ac(0);
   set_race("Were-Rat");
   set_body_type("human");
   set_hd(25,0);
   set_hp(500);
   set_exp(24000);
   set_new_exp(25,"high");
   set_size(2);
   set_stats("strength",19);
   set_stats("intelligence",11);
   set_stats("dexterity",21);
   set_stats("charisma",2);
   set_stats("constitution",18);
   set_stats("wisdom",14);
   set_money("gold",roll_dice(10,100));
   set_class("fighter");
   set_class("thief");
   set_mlevel("fighter",25);
   set_mlevel("thief",25);
   add_search_path("/cmds/thief");
   add_search_path("/cmds/fighter");
   set_property("full attacks",1);
   set_alignment(5);
   set_speed(20);
   nogo("one");
   set_emotes(5, ({"%^RED%^The Were-Rat %^BOLD%^*SNAPS*%^RESET%^%^RED%^ at you visciously!",
        "%^GREEN%^%^BOLD%^The Were-Rat %^RESET%^%^BOLD%^glares %^RESET%^%^GREEN%^%^BOLD%^at you through it's %^YELLOW%^%^BOLD%^yellow eyes.%^RESET%^",
        "%^BOLD%^The Were-Rat seems to flash a smile at you for a moment at it lunges!.",}),1);
   set_wimpy(10);
   set_funcs(({"bite"}));
   set_func_chance(30);
   set_speed(25);
   new(OBJS"ratblade.c")->move(TO);
   command("wield sword");
    add_money("gold",random(3000));
    add_money("platinum",random(100));
}

void init() 
{
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!objectp(TP)) { return; }

    if(!interactive(TP)) { return; }
    if(TP->query_true_invis()) { return; }

    if(TP == TO) { return; }
    if((int)TO->query_hp() < 1) { return; }
    
    if((int)TO->query_hp() < 50) 
    {
        tell_room(ETO,"%^BLUE%^%^BOLD%^In desparation the %^BOLD%^Were-Rat turns and lashes "
            "out ferociously!");
        command("rush "+TPQN+"");
        return 1;
    }

    TO->kill_ob(TP,1);
    if(!TO->query_scrambling()) { command("scramble"); } 

    return 1;
}

void bite(object targ)
{
    if(!objectp(targ)) return;

    tell_object(targ,"%^BOLD%^The Were-Rat %^RED%^%^BOLD%^*BITES*%^RESET%^%^BOLD%^ down on "
        "your arm and begins to %^YELLOW%^RIP%^RESET%^%^BOLD%^ at you violently!");
    tell_room(ETO,"%^BOLD%^The Were-Rat %^RED%^%^BOLD%^*BITES*%^RESET%^%^BOLD%^ down "
        "on "+targ->QCN+"'s arm and begins to %^YELLOW%^RIP%^RESET%^%^BOLD%^ violently!",targ);
    targ->do_damage(targ->return_target_limb(),roll_dice(2,10));
    targ->do_damage(targ->return_target_limb(),roll_dice(2,6));
    targ->do_damage(targ->return_target_limb(),roll_dice(2,4));
    return;
}

