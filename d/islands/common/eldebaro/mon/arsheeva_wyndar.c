#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit WEAPONLESS;
mapping AttackerInfo;
object *myImpaled, *myShadowed;

string MYQUEST = "%^BOLD%^%^CYAN%^Achieved:%^BOLD%^%^WHITE%^ "+
                "Freed The Tormented Lysaraian Monk,%^BOLD%^%^WHITE%^ "+
                "Arsh%^BOLD%^%^BLACK%^ee%^WHITE%^v%^BLACK%^a %^BOLD%^%^WHITE%^Wynd%^BLACK%^"+
                "a%^WHITE%^r%^RESET%^";
                
int myPhase, myCount, myChance;
void getImpaled();
void adjust_me();


string get_my_short()
{
    string ret;
    ret = "%^BOLD%^%^WHITE%^Arsh%^BOLD%^%^BLACK%^ee%^WHITE%^v%^BLACK%^a %^BOLD%^%^WHITE%^Wynd%^BLACK%^"+
    "a%^WHITE%^r, Crazed Monk of Lysara%^RESET%^";
    ret += RUNEPLACE->ar_desc();
    return ret;
}

void create() 
{
    object ob;
    ::create();
    set_name("arsheeva wyndar");
    set_id(({"arsheeva", "arsheeva wyndar", "human", "arsheeva wyndar crazed", "monk", 
    "wyndar", "monk of lysara"}));
    set_gender("male");
    set_race("human");
    add_attack_bonus(10);
    add_damage_bonus(15);
    set_short((:TO, "get_my_short":));

    set_long("%^BOLD%^%^GREEN%^This simple looking man is completely nude, his "+
    "body is gaunt and frail. He stands only around six feet tall and has "+
    "long %^RESET%^%^ORANGE%^dark hair%^BOLD%^%^GREEN%^ that is stringy and "+
    "unkept. His eyes are an intense %^BOLD%^%^YELLOW%^bright yellow%^BOLD%^%^GREEN%^ "+
    "hue that look incredibly sad and are sunken into his skull. Strangely he has tattoos all over most "+
    "of his body that are incredibly detailed. Some are small and seem to be "+
    "of various magical runes, others are larger and depict life like battles "+
    "of a cloaked man fighting against hordes of undead. You ascertain that the "+
    "man in those battles was either this man or someone related to him, as some of "+
    "features are strikingly similar. An %^BOLD%^%^BLACK%^immense darkness%^BOLD%^"+
    "%^GREEN%^ hangs heavily over him and he looks %^BOLD%^%^RED%^ENRAGED%^BOLD%^"+
    "%^GREEN%^.%^RESET%^");    
    
    set_class("monk", 50);    
    set("monk way", "way of the fist");
    USER_D->init_ki(TO);
    set_alignment(2);
    set_size(2);
    set_stats("strength",15);
    set_stats("constitution",30);
    set_stats("wisdom",30);
    set_stats("intelligence",14);
    set_stats("dexterity",30);
    set_stats("charisma",15);

    set_property("no disarm", 1);
    set_property("no hold", 1);
    set_property("no death", 1);
    set_property("no paralyze", 1);
    set_property("full attacks", 1);
    set_property("no crit", 1);
    set_property("no tripped", 1);
    set_damage(1,12);
    set_attacks_num(7);
    set("aggressive",0);
    set_overall_ac(-30);

    set_mob_magic_resistance("average");
    set_property("weapon resistance", 4);

    set_hp(8000);
	
    set_new_exp(40, "boss");
    set_funcs(({"quivering_palm"}));
    set_func_chance(25);
    set_monster_feats(({
        "defensive roll", 
        "quivering palm", 
        "tongue of the sun and moon", 
        "diamond body", 
        "purity of body", 
        "empty soul",
    }));

    myImpaled = ({});
    myPhase = 1;
    myCount = 1;
    myChance = 5;
    AttackerInfo = ([]);
    set_moving(1);
    set_speed(30);
    set_nogo(({ELROOMSD+"47"}));
}

void clear_impaled()
{
    int x;
    mixed *toRemove;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!sizeof(myImpaled)) return;
    toRemove = ({});
    for(x = 0;x < sizeof(myImpaled);x++)
    {
        if(!objectp(myImpaled[x])) 
        {
            toRemove += ({myImpaled[x]});
            continue;
        }
        if(objectp(environment(myImpaled[x])))
        {
            if(ETO != environment(myImpaled[x])) toRemove += ({myImpaled[x]});
        }
        continue;
    }
    myImpaled -= toRemove;
    return;
}

void getImpaled()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    clear_impaled();
    if(!pointerp(myImpaled)) return;
    if(!sizeof(myImpaled)) return;
     return myImpaled[random(sizeof(myImpaled))];
}

int do_damage(string limb, int damage) 
{
    object myVic;
    if(objectp(myVic = getImpaled()))
    {
        return myVic->do_damage(limb, damage);
    }
    if((string)RUNEPLACE->ar_desc() != "") return 0;
    return ::do_damage(limb, damage);
}

void die(object ob) 
{
    string me, tmp, *tmpquests;
    int Amt, flag;
    object MyOb, *MyKillers;
    if(myPhase >= 5) 
    {
        TO->set("is_dying");
        me = TO->query_short();
        tell_room(ETO, me +"%^BOLD%^%^CYAN%^ collapses and gasps for air, his sunken "+
        "%^BOLD%^%^CYAN%^eyes suddenly becoming aware of what he has done.....\n\n%^RESET%^");

        tell_room(ETO, "%^RESET%^%^CYAN%^He speaks with a sense of urgency:%^RESET%^ You must "+
        "warn the others... what dwells beneath is ALL consuming... NONE in this "+
        "world are safe. Kayan Freeholm MUST NOT BE ALLOWED TO LEAVE HIS TOMB!!!%^RESET%^");
        MyKillers = TO->query_attackers();
        MyKillers = filter_array(TO->query_attackers(), "is_player", FILTERS_D);
        for(Amt = 0;Amt < sizeof(MyKillers);Amt++)
        {
            if(!objectp(MyKillers[Amt])) continue;
            if(environment(MyKillers[Amt]) != ETO) continue;
            MyKillers[Amt]->delete("KilledArsheeva");
            MyKillers[Amt]->set("KilledArsheeva", 2);
            tmpquests = (string *)MyKillers[Amt]->query_mini_quests();
            if(member_array(MYQUEST, tmpquests) != -1) continue;
            MyKillers[Amt]->set_mini_quest(MYQUEST, 10000000, MYQUEST);
            tell_object(MyKillers[Amt], "%^BOLD%^%^WHITE%^You have freed the tormented "+
            "Lysaraian Monk, Arsheeva Wyndar, but you know that whatever had "+
            "possessed him still lives... somewhere.%^RESET%^");
        }
        message("info", "%^BOLD%^%^BLACK%^A massive storm over the Island of "+
        "Eldebaro breaks up for a moment.... before reforming and strengthening!!! As "+
        "%^BOLD%^M%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^nst%^WHITE%^ou"+
        "%^BLACK%^s shadows swoop through the clouds, you recognize "+
        "that something %^BOLD%^%^RED%^DREADFUL%^BOLD%^%^BLACK%^ is stirring there!!%^RESET%^", users());
        WORLD_EVENTS_D->inject_event((["The Winds of Change" : (["start message" : "%^BOLD%^%^WHITE%^The winds of change blow across the "+
        "face of the world... and suddenly you are %^BOLD%^%^CYAN%^RENEWED%^BOLD%^%^WHITE%^ as a powerful force has been dealt a weaking blow, "+
        "%^BOLD%^%^RED%^at least for now%^BOLD%^%^WHITE%^... and you are left feeling more hopeful about your future. For the next %^BOLD%^%^CYAN%^"+
        "four hours%^BOLD%^%^WHITE%^ all experience gained with award an additional %^BOLD%^%^CYAN%^25%^BOLD%^%^WHITE%^!%^RESET%^",
        "event type" : "exp bonus", "length" : 240, "notification" : "25% Bonus Exp", 
        "event name" : "The Winds of Change", "modifier" : 25, "announce" : 1, "announce to" : "world" ]),]));  
        foreach(object usr in users())
        {
            if(!objectp(usr)) continue;
            if((int)usr->query_hp() < (int)usr->query_max_hp()) continue;
            tell_object(usr, "%^BOLD%^%^WHITE%^Your wounds are healed as the winds renew you!%^RESET%^");
            usr->set_hp((int)usr->query_max_hp());
            continue;
        }
        return ::die(ob);
    }
     
    else adjust_me();
    return;
}

int add_impaled(object ob)
{
    if(!objectp(ob)) return 0;	
    if(!pointerp(myImpaled)) myImpaled = ({});
    if(member_array(ob, myImpaled) != -1) return 0;
    myImpaled += ({ob});
    return 1;
}

int remove_impaled(object ob)
{
    if(!objectp(ob)) return 0;
    if(!pointerp(myImpaled)) 
    {
        myImpaled = ({});
        return 1;
    }
    if(member_array(ob, myImpaled) == -1) return 0;
    myImpaled -= ({ob});
    return 1;
}

int check_my_attackers()
{
    object *myEnemies;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    myEnemies = TO->query_attackers();
    myEnemies -= myImpaled;
    myEnemies = filter_array(myEnemies, "is_non_immortal_player", FILTERS_D);
    if(!sizeof(myEnemies)) return 1;
    if(sizeof(myEnemies) < 2) return 1;
    return 0;   
}

varargs void impale_them()
{
    object *myEnemies, myTarg, mySpear, *myTmp;
    string me, spearSh; 
    int x;
    myEnemies = TO->query_attackers();
    me = TO->query_short();
    myEnemies -= myImpaled;
    if(!sizeof(myEnemies)) return;
    myTmp = filter_array(myEnemies, "is_non_immortal_player", FILTERS_D);
    myEnemies = filter_array(myEnemies, "is_non_player", FILTERS_D);
    if(sizeof(myTmp) < 2 && sizeof(myTmp)) myTarg = myTmp[0];
    else
    {
        myEnemies -= myImpaled;
        if(!sizeof(myEnemies)) return;
        myTarg = myEnemies[random(sizeof(myEnemies))];
    }
    mySpear = new(ELOB+"arsheeva_spear");
    spearSh = mySpear->query_short();
    tell_room(ETO, me + "%^BOLD%^%^CYAN%^ motions toward "+myTarg->QCN+" "+
    "and a "+spearSh+" flies through the air, "+
    "toward "+myTarg->QO+"!\n\n", myTarg);
    
    tell_object(myTarg, me +"%^BOLD%^%^CYAN%^ motions toward you and "
    "a "+spearSh+" flies through the air toward you!%^RESET%^\n\n");
  
    tell_room(ETO, "%^BOLD%^%^WHITE%^For a very brief instant "+
    "a %^BOLD%^%^CYAN%^g%^BOLD%^%^MAGENTA%^l%^BOLD%^%^YELLOW%^i"+
    "%^BOLD%^%^RED%^t%^BOLD%^%^CYAN%^t%^BOLD%^%^MAGENTA%^e%^BOLD%^"+
    "%^YELLOW%^r%^BOLD%^%^RED%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^MAGENTA%^g"+
    "%^BOLD%^%^WHITE%^ trail connects "+me+" and "+myTarg->QCN+
    " before vanishing.... you realize that they are now somehow "+
    "linked together!%^RESET%^\n\n", myTarg);
    
    tell_object(myTarg, "%^BOLD%^%^WHITE%^For a very brief instant "+
    "a %^BOLD%^%^CYAN%^g%^BOLD%^%^MAGENTA%^l%^BOLD%^%^YELLOW%^i"+
    "%^BOLD%^%^RED%^t%^BOLD%^%^CYAN%^t%^BOLD%^%^MAGENTA%^e%^BOLD%^"+
    "%^YELLOW%^r%^BOLD%^%^RED%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^MAGENTA%^g"+
    "%^BOLD%^%^WHITE%^ trail connects "+me+" and you.... you are "+
    "somehow linked!%^RESET%^\n\n");
  
    mySpear->set_controller(TO);
    mySpear->move(ETO);
    mySpear->impale(myTarg);
    mySpear->impale_notify();      
    return;
}

void assign_attacks(int step)
{
    object *liv;
    int x;
    if(!objectp(TO)) return;
    switch(step)
    {
        case 0:
            if(!mapp(AttackerInfo)) AttackerInfo = ([]);
            liv = all_living(ETO);
            for(x = 0;x < sizeof(liv);x++)
            {
                AttackerInfo += ([ liv[x] : liv[x]->query_attackers() ]);
                continue;
            }
            liv->cease_all_attacks();
            tell_room(ETO, "%^BOLD%^%^GREEN%^All combat ceases as "+TO->query_short()+
            "%^BOLD%^%^GREEN%^ roars loudly, his eyes %^BOLD%^%^RED%^ENRAGED!%^RESET%^");
            
            liv->set_paralyzed(10000, "%^BOLD%^%^RED%^You are completely unable to move!%^RESET%^");
            
            break;
        case 1: 
            if(!mapp(AttackerInfo)) return;
            liv = keys(AttackerInfo);
            for(x = 0;x < sizeof(liv);x++)
            {
                if(!objectp(liv[x])) continue;
                liv[x]->set_attackers(AttackerInfo[liv[x]]);
                continue;
            }
            liv->set_paralyzed(0);
            break;
    }
    return;
}

void clear_shadows()
{
    object mon;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    while(objectp(mon = present("eldebaroshadowevil", ETO))) 
    {
        mon->remove_shadow();
        continue;
    }
    return;
}

void explain_myself(int step)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    switch(myPhase)
    {
        case 2:
            switch(step)
            {
                case 1:            
                    tell_room(ETO, me +" stands up and looks around casually for a few moments...");
                    break;
                case 2:
                    command("speech speak slowly");
                    command("say We came here to find the source of evil... and eradicate it for our "+
                    "Lord Lysara... we were woefully unprepared for what we found.");
                    command("emote seems to be fighting against something unseen");
                    break;
                case 3:
                    command("speech speak firmly");
                    command("say I am sorry for what I do!! Please forgive me Lysara!! YOU MUST "+
                    "STOP ME!!!");                    
                    break;
            }
            step++;
            if(step > 3) { assign_attacks(1); return; }
            else call_out("explain_myself", 10, step);
            return;
            break;
        case 3:
            switch(step)
            {
                case 1:
                    tell_room(ETO, me +" stands up again and SCREAMS loudly!%^RESET%^");
                    command("speech speak quickly");
                    command("say time is growing shorter as we fight... we battle against "+
                    "the impossible!");
                    break;
                case 2:
                    command("say we found a tomb in which dwells an evil beyond what we "+
                    "were able to comprehend... and now....");
                    break;
                case 3:
                    command("emote suddenly seems ENRAGED!!!");
                    command("speech spat harshly");
                    command("say like such weak fools would understand... WHY DO I BOTHER???");
                    break;               
            }
            step++;
            if(step > 3) { assign_attacks(1); return; }
            else call_out("explain_myself", 10, step);
            return;
            break;
        case 4:
            switch(step)
            {
                case 1:
                    command("emote looks around and frowns deeply");
                    command("say why would I expect such ignorant beings would ever be able "+
                    "to possibly comprehend what it is that we fight against???!??!");
                    break;
                case 2:
                    command("emote shakes his head quickly, obviously fighting against something");
                    command("speech say hesitantly");
                    command("say disregard all of that... you must put me down... that is the first "+
                    "step, please HURRY!! you are losing time");
                    break;
                case 3:
                    command("emote cackles insanely and shakes his head quickly again");
                    command("speech spat harshly");
                    command("say after I murder you I should find everything you have "+
                    "ever touched and sacrifice it to Kayan!!!");
                    break;
            }
            step++;
            if(step > 3) { assign_attacks(1); return; }
            else call_out("explain_myself", 10, step);
            return;
            break;
        case 5:
            switch(step)
            {
                case 1:
                    command("emote shakes his head fiercly fighting something internally...");
                    command("speech say softly");
                    command("say yes, you are close to victorious.. YOU MUST NOT GIVE UP!");
                    break;
                case 2:
                    command("emote laughs loudly and roars in RAGE!!");
                    command("speech spat harshly");
                    command("say I am going to wear your entrails... so those who come looking "+
                    "for you will know what awaits them!!!");
                    break;
                case 3:
                    command("emote closes his eyes and focuses deeply");
                    command("speech say softly");
                    command("say soon I shall meet my Lord Lysara, but your battle is just now "+
                    "beginning... a darkness rises from the depths of this land, a darkness so "+
                    "profound that the entire world will shake!!");
                    break;
            }
            step++;
            if(step > 3) { assign_attacks(1); return; }
            else call_out("explain_myself", 10, step);
            return;
            break;
    }
    return;
}

void adjust_me()
{
    int flag;
    object ob; 
    string me;
    if(!objectp(TO)) return;

    myPhase++;
    assign_attacks(0);
    me = TO->query_short();
    clear_shadows();
    switch(myPhase)
    {
        case 1:
            myChance = 10;
            set_funcs(({"quivering_palm"}));
            set_func_chance(25);
            TO->set_hp(TO->query_max_hp());            
            break;
        case 2:
            myChance = 8;         
            set_funcs(({"quivering_palm", "myshadow"}));
            set_func_chance(35);		
            command("emote kneels down on the sandy ground and begins weeping loudly!");		
            tell_room(ETO, me +"%^BOLD%^%^CYAN%^'s body is suddenly made whole again!%^RESET%^");  
            TO->set_hp(TO->query_max_hp());
            break;
        case 3:
            myChance = 6;
            set_funcs(({"quivering_palm", "myshadow", "wave_of_power"}));
            command("emote kneels down on the sandy ground again and sighs deeply....");
            tell_room(ETO, me +"%^BOLD%^%^CYAN%^'s body is suddenly made whole again!%^RESET%^");  
            TO->set_hp(TO->query_max_hp());            
            set_func_chance(45);
            break;
        case 4:
            myChance = 5;
            command("emote stretches his gaunt body and shakes his head in obvious exasperation....");
            tell_room(ETO, me +"%^BOLD%^%^CYAN%^'s body is suddenly made whole again!%^RESET%^");  
            TO->set_hp(TO->query_max_hp()); 
            set_func_chance(55);
            set_funcs(({"quivering_palm", "myshadow", "wave_of_power", "rage_against_them"}));
            break;
        case 5:
            command("speech say calmly");
            command("say you have almost defeated me... my body can only continue awhile longer...");
            tell_room(ETO, me +"%^BOLD%^%^CYAN%^'s body is suddenly made whole again!%^RESET%^");  
            TO->set_hp(TO->query_max_hp()); 
            set_func_chance(75);
            set_funcs(({"quivering_palm", "myshadow", "wave_of_power", "rage_against_them", "devour_soul"}));
            break;
	}
    if(myPhase == 1) { assign_attacks(1); }
    else call_out("explain_myself", 4, 1);
    return;
}

void heart_beat()
{
    string me;
    object *myEnemies, myTarg, mon;
    if(!objectp(TO)) return;
    if(TO->query("is_dying")) return;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
	
    myEnemies = TO->query_attackers();
    me = TO->query_short();
    if((int)TO->query_hp() < ((int)TO->query_max_hp() / 12)) 
    {
        if(myPhase < 5) 
        {
            adjust_me();
            return;
        }
    }	

    if(!random(myChance) && (int)TO->query_hp() < (int)TO->query_max_hp()) 
    {
        tell_room(ETO, me + "%^BOLD%^%^CYAN%^ focuses deeply, instantly "+
        "mending some of his wounds!%^RESET%^");
        TO->heal(150 + roll_dice(12,12));
    }

    if(!sizeof(myEnemies)) 
    {
        myCount++;
        if(myCount > 600) 
        {
            myPhase = 0;
            adjust_me();
            myCount = 0;
        }
        return;
    }
    if(!random(myChance))
    {
        if(objectp(mon = present("eldebaroshadowevil", ETO))) mon->interact();
    }
    if(!random(myChance) || check_my_attackers()) 
    {
        impale_them();
    }
    return;
}

void rage_against_them(object targ)
{
    object *myEnemies;
    string me;
    int hits;
    
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;    
    me = TO->query_short();
    myEnemies = TO->query_attackers();
    myEnemies = filter_array(myEnemies, "is_non_immortal_player", FILTERS_D);
    if(sizeof(myEnemies)) targ = myEnemies[random(sizeof(myEnemies))];
    if(!objectp(targ)) return;
    
    tell_room(ETO, me +"%^BOLD%^%^CYAN%^ focuses deeply and suddenly "+
    "appears right in front of "+targ->QCN+", %^BOLD%^%^RED%^ENRAGED%^BOLD%^%^CYAN%^!%^RESET%^", targ);
    
    tell_object(targ, me +"%^BOLD%^%^CYAN%^ focuses deeply and suddenly "+
    "appears right in front of you, %^BOLD%^%^RED%^ENRAGED%^BOLD%^%^CYAN%^!%^RESET%^");
    hits = roll_dice(1,4);
    while(hits--)
    {
        if(!(int)BONUS_D->process_hit(TO, targ, 0, 0, 0, 1))
        {
            tell_object(targ, me +"%^BOLD%^%^WHITE%^ punches quickly at you, "+
            "but you manage to avoid the attack!");
            tell_room(ETO, me+"%^BOLD%^%^WHITE%^ punches quickly at "+targ->QCN+
            "%^BOLD%^%^WHITE%^, but "+targ->QS+" manages to avoid the attack!%^RESET%^", targ);
            continue;
        }
        tell_object(targ, me+"%^BOLD%^%^BLACK%^ punches you squarely in the "+
        "head!%^RESET%^");
        tell_room(ETO, me+"%^BOLD%^%^BLACK%^ punches "+targ->QCN+"%^BOLD%^%^BLACK%^ "+
        "squarely in the head!%^RESET%^", targ);
        targ->cause_typed_damage(targ, "head", roll_dice(12,6), "bludgeoning");
        continue;
    }
    return;    
}

void devour_soul(object targ)
{
    string me;
    int myHeal;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    tell_object(targ, me +"%^BOLD%^%^GREEN%^ focuses on you and you feel "+
    "something pulling at your soul!%^RESET%^");
    tell_room(ETO, me +"%^BOLD%^%^GREEN%^ focuses on "+targ->QCN+
    " and "+targ->QCN+"%^BOLD%^%^GREEN%^ looks weakened!%^RESET%^", targ);
    if(!interactive(targ))
    {
        tell_object(targ, "%^BOLD%^%^GREEN%^You feel your soul completely "+
        "devoured before everything goes black!%^RESET%^");
        tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^ falls forward, dead! "+me+
        " seems empowered!%^RESET%^", targ);
        myHeal = (int)targ->query_hp();
        TO->heal(myHeal);
        targ->die();
        return;
    }
    tell_object(targ, "%^BOLD%^%^GREEN%^You feel as if your soul has been "+
    "wounded and your entire body is %^BOLD%^%^RED%^WRACKED%^BOLD%^%^GREEN%^ "+
    "with immense pain as "+me+" looks empowered!!%^RESET%^");
    tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^'s body suddenly %^BOLD%^%^RED%^"+
    "SHAKES%^BOLD%^%^GREEN%^ violently as "+me+" seems empowered!%^RESET%^", targ);
    myHeal = ((int)targ->query_hp()/4);
    TO->heal(myHeal);
    targ->cause_typed_damage(targ, "torso", myHeal, "divine");
    return;
}

void wave_of_power(object targ)
{
    object *myEnemies;
    string me;
    int x, dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    myEnemies = TO->query_attackers();
    if(!sizeof(myEnemies)) return;
    
    tell_room(ETO, me +"%^BOLD%^%^CYAN%^ waves his arms around quickly forming magical "
    "runes that seems to float in the air for a brief moment... before exploding "+
    "in a wave of %^BOLD%^%^RED%^POWER%^BOLD%^%^CYAN%^!%^RESET%^");
    
    for(x = 0;x < sizeof(myEnemies);x++)
    {
        if(!objectp(myEnemies[x])) continue;
        if(ETO != environment(myEnemies[x])) continue;
        if(myEnemies[x]->reflex_save(50))
        {
            tell_object(myEnemies[x], "%^BOLD%^%^CYAN%^You manage to "+
            "move out of the way just in time to avoid the force of the "+
            "wave!%^RESET%^");
            continue;
        }
        tell_object(myEnemies[x], "%^BOLD%^%^CYAN%^The wave of power "+
        "washes over you - it %^BOLD%^%^RED%^BURNS%^BOLD%^%^CYAN%^ "+
        "tremendously!!!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^CYAN%^The wave of power washes over "+
        myEnemies[x]->QCN+"%^BOLD%^%^CYAN%^!%^RESET%^", myEnemies[x]);
        myEnemies[x]->cause_typed_damage(myEnemies[x], myEnemies[x]->return_target_limb(), roll_dice(40,10), "fire");
        continue;
    }
    return;
}

void quivering_palm(object targ)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    TO->remove_property("using quivering palm");
    command("quivering_palm "+targ->query_name());
    return;
}

void myshadow(object targ)
{
    object mon, *myEnemies;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    if(!pointerp(myShadowed)) myShadowed = ({});
    if(member_array(targ, myShadowed) != -1)
    {
        myEnemies = TO->query_attackers();
        myEnemies -= myShadowed;
        if(!sizeof(myEnemies)) return;
        targ = myEnemies[random(sizeof(myEnemies))];
    }
    myShadowed += ({targ});
    tell_object(targ, me +"%^BOLD%^%^MAGENTA%^ stares at you.... "+
    "his eyes deeply depressed.... and you realize that "+
    "something is suddenly behind you!%^RESET%^");

    tell_room(ETO, me +"%^BOLD%^%^MAGENTA%^ stares at "+
    targ->QCN+"%^BOLD%^%^MAGENTA%^.... his eyes deeply depressed... and "+
    "suddenly there is something right behind "+targ->QCN+"!%^RESET%^", targ);

    mon = new(ELMON+"shadow");
    mon->move(ETO);
    mon->focus_on(targ);
    mon->lasts_for(roll_dice(1,6));    
    return;
}

void remove()
{
    RUNEPLACE->clear_arrays("arsheeva");
    return ::remove();
}

void set_paralyzed(int time,string message) { return;}

void set_tripped(int time, string message) { return; }
