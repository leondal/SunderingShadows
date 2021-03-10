#include <std.h>
#include "../undead.h"

inherit CREATURE;

void init() 
{
    ::init();
    add_action("no_cast","rebuke");
}

void create() 
{
    ::create();
    set_name("Barliagus the Cataboligne");
    set_id(({"barliagus the cataboligne","demon","cataboligne","barliagus"}));
    set_short("Barliagus the Cataboligne");
    set_long("Barliagus is a very minor demon. He is considered a member of Catabolignes, "
        "a type of demon that enjoys manipulating human agents. They treat their earthyly "
        "servants well and are even known to manifest themselves to protect them, though "
        "this is rare.");
    set_race("demon");
    set_body_type("human");
    set_gender("male");
    set_hd(35,8);
    set_size(3);
    set_overall_ac(-15);
    set_property("magic",1);
    set_class("fighter");
    set_mlevel("fighter",35);
    set_hp(1000);
    set_property("swarm",1);
    set_stats("strength",22);
    set_stats("dexterity",19);
    set_stats("constitution",22);
    set("aggressive",25);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_property("no death", 1);
    set_property("no dominate", 1);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    set_alignment(9);
    set_exp(90000);
    set_new_exp(25,"boss");
    set_funcs(({"circle","desoul","bolt","healing","impaler","fire"}));
    set_func_chance(65);
    new(OBJS"whip_of_spikes")->move(TO);
    command("wield whip");
    set_resistance("electricity",15);
}

void die(object ob) 
{
    tell_room(ETO,"%^BOLD%^RED%^Barliagus tells you: %^RESET%^You may have won "
        "this time, but don't think I won't be back!",TO);
    tell_room(ETO,"%^BOLD%^%^CYAN%^Barliagus whispers to you: %^RESET%^I'll be "
        "waiting for you in hell, then you will be mine.",TO);
    ::die(ob);
    return;
}

int no_cast(string str) 
{
    object targ;
    targ = TP;
    command("say "+TP->QCN+", do you really think after thousands of years I "
        "wouldn't have learned how to get around the puny magics of a being like you?");
    command("say You shall pay for your folly, with your soul!");
    tell_object(targ,"%^RED%^Barliagus summons his infamous barbed whip and lashes out at "
        "you with it!");
    tell_object(targ,"%^BLUE%^The whip entwines around your neck cutting deeply "
        "into your flesh.");
    tell_room(environment(targ),"%^RED%^Barliagus summons his infamous barbed whip and "
        "lashes "+targ->QCN+" with it!",targ);
    tell_room(environment(targ),"Blood pours fourth from "+targ->QCN+"'s neck as they "
        "scream to what ever god they believe in for help!",targ); 
    TO->execute_attack();
    TO->execute_attack();
    TO->execute_attack();
    return 1;
}

void impaler(object targ) 
{
    if(ROLLSAVE(targ,PPD)) 
    {
        tell_object(targ,"%^BOLD%^Barliagus swings around and hurts you with his giant "
            "barbed tail!");   
        tell_room(ETO,"%^BOLD%^Barliagus swings around and hurts "+targ->QCN+" "
            "with his giant barbed tale!%^RESET%^",targ);
        targ->do_damage("torso",roll_dice(5,6));
        return 1;
    } 

    tell_object(targ,"%^BOLD%^Barliagus swings around and impales you with his giant barbed "
        "tale!");   
    tell_room(ETO,"%^BOLD%^Barliagus swings around and impales "+targ->QCN+" "
        "with his giant barbed tale!%^RESET%^",targ);
    targ->do_damage("torso",roll_dice(10,6));
    tell_object(targ,"%^BOLD%^%^RED%^You feel the barbs of the tail tearing at your "
        "insides and are unable to fight due to the pain!\n");    
    targ->set_paralyzed(roll_dice(3,6),"%^BOLD%^Your insides feel as if they are tearing out!");
    return 1;
}

void fire(object targ) 
{
    tell_object(targ,"%^BOLD%^%^RED%^Barliagus creates a ball of fire in his hand, "
        "hurls it at you!%^RESET%^");
    tell_room(ETO,"%^RED%^Barliagus creates a ball of fire and hurls it "
        "at "+targ->QCN+"!%^RESET%^",targ);
    
    if(ROLLSAVE(targ,BW)) 
    {
        targ->do_damage("torso",roll_dice(8,6));
        tell_object(targ,"%^BOLD%^%^BLUE%^The fires of hell burn bright as you are consumed "
            "by the flame!");
        targ->set_paralyzed(random(10)+15,"%^BOLD%^You are caught and blinded in "
            "the blazing flames!%^RESET%^");
        targ->set_temporary_blinded(roll_dice(1,6));
        return 1;
    } 

    targ->do_damage("torso",roll_dice(4,6));
    return 1;
}

void healing(object ob) 
{
    tell_room(ETO,"%^BOLD%^Barliagus gorges himself on your spilled blood, his wounds "
        "begin to heal.\n%^RED%^Barliagus begins to grow in size, it is obvious he draws "
        "great strength from the blood of an enemy.",TO);
    TO->add_hp(roll_dice(10,10));
    TO->add_stat_bonus("strength",1);
    return;
}

void circle(object targ)
{
    if(!targ) return 0;
    if(random(40) > targ->query_stats("dexterity"))
    {
        tell_object(targ, "%^BLUE%^Barliagus grabs you in his mighty jaws and crushes you "
            "between his giant fangs!");
        tell_room(ETO,"%^BLUE%^Barliagus grabs "+targ->QCN+" in his mighty jaws and "
            "crushes "+targ->QO+"!%^RESET%^",targ);
        targ->do_damage("torso",roll_dice(10,10));
        return 1;
    }
    tell_object(targ, "%^BOLD%^Barliagus snaps his angry maw at you but misses!");
    tell_room(ETO,"%^BOLD%^Barliagus snaps his angry maw at "+targ->QCN+" but misses!",targ);
    return;
}

void bolt(object targ)
{
    if(!targ) return 0;
    if(random(50) > targ->query_stats("wisdom"))
    {
        tell_object(targ,"%^BOLD%^%^BLACK%^Barliagus sends a barrage of razor sharp spikes "
            "at you!");  
        tell_room(ETO,"%^BOLD%^%^BLACK%^Barliagus sends a barrage of razor sharp spikes from "
            "his body at "+targ->QCN+"!",targ);
        targ->do_damage("torso", roll_dice(6,10));
        return 1;
    }

    tell_object(targ,"%^BOLD%^%^BLACK%^Barliagus lets loose a barrage of spikes that "
        "impact all around you!");
    tell_room(ETO,"%^BOLD%^%^BLACK%^Barliagus lets loose a barrage of spikes that impact "
        "all around "+targ->QCN+"!",targ);
    tell_object(targ,"%^BOLD%^%^RED%^Some of the spikes bounce around and hit you!"); 
    targ->do_damage("torso", roll_dice(2,10));
    return 1;
}

void desoul(object targ)
{
    if(!targ) return 0;
    if(random(35) > targ->query_stats("wisdom"))
    {
        tell_room(ETO, "%^BLUE%^The fires of Hell glow strong as Barliagus calls forth "
            "their full powers.");
        tell_room(ETO, "%^BOLD%^%^BLACK%^Now "+targ->QCN+" you shall witness the full "
            "powers of hell!",targ);
        force_me("emote throws his head back and cackles.");
        force_me("say Now that I have crushed your body, I shall take your very soul!");
        tell_room(ETO, "%^BOLD%^%^RED%^Barliagus plunges his fist into "+targ->QCN+"'s chest, "
            "grinning all the while.",targ);
        tell_room(ETO, "%^BLUE%^Barliagus pulls his talons forth from "+targ->QCN+"'s chest, "
            "in his hand you see a glowing ball of light!",targ);
        tell_object(targ, "%^BLUE%^Barliagus wretches your soul from your body and holds "
            "it high!");
        tell_object(targ, "%^BOLD%^%^RED%^You watch as Barliagus crushes your soul within "
            "his fist!");
        tell_room(ETO, "%^BOLD%^%^RED%^You watch as Barliagus crushes the ball of light "
            "within his mighty fist!",targ);
        force_me("say Now to finish of the rest of you, so that you may join me in Hell!");
        targ->set_hp(5);
        return 1;
    }
    tell_object(targ, "Barliagus grabs you by the scruff of your neck and holds you up "
        "for examination.");
    tell_object(targ, "Barliagus hisses as he smashes your face into the floor with all "
        "his strength.");
    targ->do_damage("torso", roll_dice(5,10));
    tell_room(environment(targ), "Barliagus grabs "+targ->QCN+" by the scruff of their "
        "neck and raises them to his face for examination. He then procedes to smash "
        "their face into the ground with all of his strength.",targ);
    return 1;
}

void heart_beat() 
{
    int i;
    object *fodder;

    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;

    if((int)TO->query_hp() < (int)TO->query_max_hp()) { TO->add_hp(roll_dice(2,6)); }

    fodder = filter_array(all_living(ETO), "is_fodder", CREATURE);
    
    if(!sizeof(fodder)) { return; }

    for(i=0;i<sizeof(fodder);i++) 
    {
        tell_room(ETO,"%^BOLD%^Barliagus begins to work his evil upon "+fodder[i]->QCN+"!");
        tell_room(ETO,"%^RED%^The "+fodder[i]->QCN+" is dragged kicking and screaming to "
            "the pits of hell!");
        fodder[i]->remove();
        continue;
    }

}


