#include <std.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;
int attacked;

void create() 
{
    object ob;
    ::create();
    set_name("howne");
    set_id(({"howne", "ranger", "insane ranger", "worm keeper", "howne, the worm keeper"
    "keeper", "saidewormkeeperhowne"}));
    set_race("human");
    set_short("%^RESET%^%^MAGENTA%^H%^BOLD%^o%^RESET%^%^MAGENTA%^wn%^BOLD%^e"+
    ", %^RESET%^%^MAGENTA%^Th%^BOLD%^e %^RESET%^%^MAGENTA%^W%^BOLD%^o%^RESET%^"+
    "%^MAGENTA%^rm K%^BOLD%^ee%^RESET%^%^MAGENTA%^p%^BOLD%^e%^RESET%^%^MAGENTA%^r%^RESET%^");
    
    set_long("%^BOLD%^%^MAGENTA%^The man before you stands nearly six feet tall. He is "+
    "very thin and gaunty looking and his skin is very %^BOLD%^%^WHITE%^pale%^MAGENTA%^. "+
    "He is also caked in thick layers of dirt and grime. He gives off a strange "+
    "odor of filth with a hint of something else that is not identifiable. "+
    "His eyes are a very deep almost %^RESET%^%^MAGENTA%^purple hue%^BOLD%^ and they "+
    "look almost hollow inside. His head is covered with a deep purple coif "+
    "and a very scraggly and matted beard juts out from his face. He wears a suit "+
    "of deep purple armor and carries two deep purple blades which he is constantly "+
    "using to scratch off some grime and dirt. There are marks on many parts of his thin "+
    "and gaunty body where he has actually cut himself with his blades.%^RESET%^");   
    
    set_class("ranger");
    set_guild_level("ranger", 16);
    set_mlevel("ranger",16);
    set("aggressive","kill_em");
    set_alignment(8);
    set_stats("strength",19);
    set_stats("intelligence",9);
    set_stats("wisdom",18);
    set_stats("dexterity",19);
    set_stats("charisma",8);
    set_stats("constitution",12);
    
    set_detecting_invis(1);
    set_gender("male");
    set_hp(850 + random(55));
    set_new_exp(16, "boss");
    
    ob = new(WOB+"purple_worm_blade");
    //if(!random(2)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield sword");
    
    ob = new(WOB+"purple_worm_blade");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield sword");
    
    ob = new(WOB+"worm_guise");
    ob->move(TO);
    if(!random(2)) ob->set_property("monsterweapon", 1);
    command("wear leather");
    
    ob = new(WOB+"purple_worm_coif");
    ob->move(TO);
    if(!random(2)) ob->set_property("monsterweapon", 1);
    command("wear coif");
    
    set_funcs(({"call_worms"}));
    set_func_chance(25);

    set_property("full attacks", 1);
    
}

void heart_beat() 
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(sizeof(TO->query_current_attackers()) < 1 && attacked == 1) 
    {
        attacked = 0;
        return;
    }
}

void worm_answer(object targ)
{
    string me, wworm;
    object MyWorm;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(present("worm 2", ETO)) return;
    me = TO->query_short();
    
    if(!random(3)) return;
    switch(random(3))
    {
        case 0:
            wworm = "greater_purple_worm";
            break;
        case 1:
            wworm = "adult_purple_worm";
            break;
        case 2:
            wworm = "young_purple_worm";
            break;
    }
    MyWorm = new(WMON+wworm);
    tell_room(ETO, MyWorm->query_short()+ "%^BOLD%^%^MAGENTA%^ bursts through the stone and earth, as if "+
    "answering "+me+"%^BOLD%^%^MAGENTA%^'s call.......%^RESET%^");
    MyWorm->move(ETO);
    MyWorm->set_property("minion", TO);
    TO->add_follower(MyWorm);
    MyWorm->set_moving(0);
    MyWorm->set_speed(0);
    if(!random(4))
    {
        if((int)TO->query_hp() <= 50) 
        {
            TO->set_hp((int)TO->query_hp() * 2);
            MyWorm->swallow(TO);
            MyWorm->burrow();
            return;
        }
    }
    tell_room(ETO,"%^BOLD%^%^MAGENTA%^.... and attacks "+targ->QCN+"%^BOLD%^%^MAGENTA%^!%^RESET%^", targ);
    
    tell_object(targ, "%^BOLD%^%^MAGENTA%^.... and attacks you!%^RESET%^");
    MyWorm->force_me("kill "+targ->query_name());
    MyWorm->swallow(targ);
    return;   
}


void call_worms(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    
    me = TO->query_short();
    
    tell_room(ETO, me + "%^RESET%^%^MAGENTA%^ turns to face "+targ->QCN+
    " and whistles loudly!%^RESET%^", targ);
    
    tell_object(targ, me +"%^RESET%^%^MAGENTA%^ turns to face you and "+
    "whistles loudly!%^RESET%^");
    
    command("say come get em boys, "+targ->QS+" looks ripe for the eating!");
    call_out("worm_answer", 6, targ);
    return;    
}

void kill_em() 
{
    string msg;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(TP)) return;
    if(!TP->is_player()) return;
    if(strsrch(base_name(TP), WMON) != -1) return;
    if(TP->query_true_invis()) return;
    if(attacked) return;
    switch(random(4)) 
    {
        case 0: 
            msg = "what in the HELLS are you doing to my WORMS?!?!?!";
            break;
        case 1:
            msg = "I AM TELLING YOU TO GET THE HELL OUT OF HERE!!!";
            break;
        case 2:
            msg = "You like KILLING defenseless WORMS???? THEN DIE COWARD!!!!";
            break;
        case 3:
            msg = "Let's SEE HOW YOU LIKE BEING INSIDE THE BELLY OF A WORM!!!";
            break;
    }	
    command("speech growl with rage");
    command("say "+msg);
    if(!objectp(TP)) return;
    command("kill "+TPQN);
    if(!random(2)) call_worms(TP);
    attacked = 1;
    return;
}