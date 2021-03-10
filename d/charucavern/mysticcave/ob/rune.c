#include <std.h>
#include "../inherits/area_stuff.h"
#include <daemons.h>

#define RUNEDEED "%^BOLD%^%^RED%^D%^RESET%^%^ORANGE%^e%^BOLD%^%^RED%^str%^RESET%^%^ORANGE%^o%^BOLD%^%^RED%^y%^RESET%^%^ORANGE%^e"\
"%^BOLD%^%^RED%^d The Charu Cavern %^BOLD%^%^CYAN%^R%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^n%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^s"

inherit OBJECT;
int health, count;
string myType, MC;

void create() 
{
    ::create();
    set_name("a glowing rune");
    set_value(0);
    set_property("no animate", 1);
    set_weight(10000);
    health = 200;
}

void make_me(string which)
{
   if(!stringp(which)) 
   {    
       TO->remove();
       return;
   }
   myType = which;
   switch(which) 
   {  
       case "red":
           MC = "%^BOLD%^%^RED%^";
           set_name("a bizarre blood red rune");

           set_id(({"rune", "red rune", "bizarre rune", "blood red rune"}));
 
           set_short("%^BOLD%^%^RED%^A bizarre, bl%^RESET%^%^RED%^"+
           "oo%^BOLD%^d red rune%^RESET%^");

   	       set_long("%^BOLD%^%^RED%^This strange crystal formation is covered "+
           "with %^BOLD%^%^CYAN%^magical symbols%^BOLD%^%^RED%^. It stands almost "+
           "six feet tall and has been wrapped with a thick %^BOLD%^%^WHITE%^silver"+
           "%^BOLD%^%^RED%^ wire, almost as if someone or something was planning to "+
           "make it into a necklace. It is a bl%^RESET%^%^RED%^oo%^BOLD%^d red "+
           "hue and gives off a strange aura that pulls at your mind and spirit and "+
           "comes close to enraging you. There is obviously a potent magic at work here. "+
           "You have an almost uncontrollable urge to %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^"+
           "smash%^BOLD%^%^WHITE%^> %^BOLD%^%^RED%^it.%^RESET%^");
         
           break;
       case "green":
 
           MC = "%^BOLD%^%^GREEN%^";
           set_name("a strange emerald rune");
 
           set_id(({"rune", "emerald rune", "strange rune", "strange emerald rune"}));

           set_short("%^BOLD%^%^GREEN%^a strange %^RESET%^%^GREEN%^e%^BOLD%^m%^RESET%^"+
           "%^GREEN%^e%^BOLD%^r%^RESET%^%^GREEN%^a%^BOLD%^ld rune%^RESET%^");

           set_long("%^BOLD%^%^GREEN%^This rune is composed from a large chunk of "+
           "emerald that stands almost three feet tall. It has lines and cracks "+
           "that crisscross it more frequently toward the bottom. It is covered with "+
           "%^BOLD%^%^CYAN%^magical symbols%^BOLD%^%^GREEN%^ which pulsate constantly. "+
           "It is giving off a sickly green aura that almost makes you gag just being "+
           "near it. There is obviously a potent magic at work here. "+
           "You think that you could %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^smash%^BOLD%^%^WHITE%^> %^BOLD%^"+
           "%^GREEN%^it, if you were so inclined.%^RESET%^");

           break;
       case "gray":
           MC =  "%^BOLD%^%^BLACK%^";
           set_name("a dull gray rune");

           set_id(({"rune", "gray rune", "dull rune", "dull gray rune"}));

           set_short("%^BOLD%^%^BLACK%^a dull gr%^RESET%^%^WHITE%^a%^BOLD%^"+
           "%^BLACK%^y rune%^RESET%^");

           set_long("%^BOLD%^%^BLACK%^This rune stands almost eight feet tall. "+
           "It is made from a large chunk of "+
           "gray stone. It has been etched with strange %^BOLD%^%^CYAN%^magical "+
           "symbols%^BOLD%^%^BLACK%^ that constantly shift forms. It is giving "+
           "off a strange, unnatural darkness, that seeps into the air "+
           "around it. There is something disturbing about the aura, in "+
           "fact it quite terrifying. You cannot place your finger on what it "+
           "is but you are sure your best course of action would be "+
           "to %^BOLD%^%^WHITE%^<%^BOLD%^%^CYAN%^smash%^BOLD%^%^WHITE%^> "+
           "%^BOLD%^%^BLACK%^this rune now, before it is too late.%^RESET%^");
           break;
       default:
           TO->remove();
           break;
    }
    call_out("checkEffect", 10);
    return;
}

void init()
{
    ::init();   
    add_action("smash_function","smash");
}

void checkEffect()
{ 
    int x;
    object *vics;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vics = all_living(ETO);
    call_out("checkEffect", 10);
    if(!sizeof(vics)) return;
    for(x = 0;x < sizeof(vics);x++)
    {
        if(vics[x]->query_true_invis()) continue;
        if(strsrch(base_name(vics[x]), CRMON) != -1) continue;
        if(vics[x]->will_save(16)) continue;
        switch(myType) 
        {
            case "red":
                
                tell_object(vics[x], TOQCN+"%^BOLD%^%^RED%^ saps away some of your very "+
                "%^BOLD%^%^CYAN%^lifeforce%^BOLD%^%^RED%^!%^RESET%^");

                tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ saps away some of "+vics[x]->QCN+
                "%^BOLD%^%^RED%^'s very %^BOLD%^%^CYAN%^lifeforce%^BOLD%^%^RED%^!%^RESET%^", vics[x]);
               
                vics[x]->cause_typed_damage(vics[x], 0, roll_dice(6,6), "negative energy");
                continue;
            case "green":

                tell_object(vics[x], "%^BOLD%^%^GREEN%^The aura given off by "+TOQCN+
                " suddenly becomes more than you can tolerate and you vomit "+
                "violently!%^RESET%^");

                tell_room(ETO, "%^BOLD%^%^GREEN%^The aura given off by "+TOQCN+
                " suddenly becomes more than "+vics[x]->QCN+"%^BOLD%^%^GREEN%^ can "+
                "stand and "+vics[x]->QS+"%^BOLD%^%^GREEN%^ vomits violently!%^RESET%^", vics[x]);

                vics[x]->set_paralyzed(4 + random(4), "%^BOLD%^%^GREEN%^You are recovering!%^RESET%^");

                continue;
           case "gray":

               tell_object(vics[x], "%^BOLD%^%^BLACK%^You are suddenly mortified beyond "+
               "words by "+TOQCN+"!%^RESET%^");

               tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^BLACK%^ is suddenly mortified "+
               "beyond words by "+TOQCN+"!%^RESET%^", vics[x]);
                
               vics[x]->run_away();
               continue;
        }
    }
    return;
}

void check_deed_state(object who, int flag)
{
    if(!objectp(who)) return;
    if(!flag) 
    {
        if(!who->query("smashed "+myType+" rune")) who->set("smashed "+myType+" rune", 1);
        if(who->query("smashed gray rune") && who->query("smashed red rune") &&
        who->query("smashed green rune")) 
        {
            who->set_mini_quest(RUNEDEED, 100000, RUNEDEED);
            flag = 1;
        }
        else return;
    }
    if(flag) 
    {
        if(who->query("smashed gray rune")) who->delete("smashed gray rune");
        if(who->query("smashed red rune")) who->delete("smashed red rune");
        if(who->query("smashed green rune")) who->delete("smashed green rune");
        return;
    }
}

void check_broken(object who)
{
    object *liv, *tmp, frag;
    int x, redd = 0, grayd = 0, greend = 0, bossd = 0, frags = 3 + random(3);
    SAVE_D->remove_array("charu_cavern_rune_"+myType);
    SAVE_D->remove_array("charu_cavern_rune_"+myType+"_delay");
    SAVE_D->set_value("charu_cavern_rune_"+myType+"_delay", time() + 7200);
    if(!objectp(who)) return;
    liv = all_living(environment(who));
    if(!sizeof(liv)) return;
   /* for(x = 0;x < sizeof(liv);x++)
    {
        if(!objectp(liv[x])) continue;
        if(!interactive(liv[x])) continue;
        if(member_array(RUNEDEED, liv[x]->query_mini_quests()) != -1) 
        {
            check_deed_state(liv[x], 1);
            continue;
        }
        check_deed_state(liv[x], 0);
        continue;
    }*/
    while(frags--)
    {
        frag = new(CROB+"rune_shard");
        frag->set_my_type(myType, MC);
        frag->move(ETO);
        continue;
    }
    tmp = SAVE_D->query_array("charu_cavern_rune_red_delay");
    if(sizeof(tmp)) redd = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_rune_green_delay");
    if(sizeof(tmp)) greend = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_rune_gray_delay");
    if(sizeof(tmp)) grayd = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_boss_delay");
    if(sizeof(tmp)) bossd = tmp[0];
        
    if(redd >= time() && grayd >= time() && greend >= time() && time() >= bossd)
    {
        if(objectp(ETO)) ETO->place_boss();
    }
    
    return;
}

int smash_function(string what) 
{
    object keeper;
    int dam;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(what)) return 0;
    if(TO != present(what, ETO)) return 0;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(objectp(keeper = present("rune keeper", ETO))) 
    {
        tell_object(TP, keeper->query_short() + "%^BOLD%^%^RED%^ will not let you close enough to "+
        "smash the rune!%^RESET%^");
        return 1;
    }
    dam = roll_dice(3, 8)+10;
    health -= dam;
    if(health > 0) 
    {
        tell_object(TP, "%^BOLD%^%^RED%^You use all of your strength and try to "+
        "smash the rune, but it does not break!%^RESET%^");

        tell_room(ETO, TPQCN+"%^BOLD%^%^RED%^ uses of all "+TP->QP+" strength and "+
        "tries to smash the rune, but it does not break!%^RESET%^", TP);

        TP->set_paralyzed(2, "%^BOLD%^%^RED%^You are busy trying to smash the rune!%^RESET%^");
        return 1;
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^RED%^You use all of your strength and "+
        "with a %^BOLD%^%^YELLOW%^TH%^BOLD%^%^BLACK%^U%^BOLD%^%^YELLOW%^ND"+
        "%^BOLD%^%^BLACK%^E%^BOLD%^%^YELLOW%^R%^BOLD%^%^BLACK%^I%^BOLD%^%^YELLOW%^"+
        "NG%^BOLD%^%^BLACK%^ BOOM%^BOLD%^%^RED%^ the rune shatters!%^RESET%^");

        tell_room(ETO, TPQCN +"%^BOLD%^%^RED%^ uses all of "+TP->QP+" strength "+
        "and with a %^BOLD%^%^YELLOW%^TH%^BOLD%^%^BLACK%^U%^BOLD%^%^YELLOW%^ND"+
        "%^BOLD%^%^BLACK%^E%^BOLD%^%^YELLOW%^R%^BOLD%^%^BLACK%^I%^BOLD%^%^YELLOW%^"+
        "NG%^BOLD%^%^BLACK%^ BOOM%^BOLD%^%^RED%^ the rune shatters!%^RESET%^", TP);
        check_broken(TP);
        TO->remove();
    }
    return 1;
}		

int get() { return 0; }