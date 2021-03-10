#include <std.h>

inherit NPC;

void create() 
{  
    object ob;
    ::create();  
    
    set_race("minotaur");    
    
    set_id( ({ "mizati", "massive male minotaur", "minotaur", "male minotaur"}) );
    set_body_type("minotaur");
    set_class("fighter");
    set_alignment(5);
    set_hd(30,12);
    set_hp(750);
    set_max_hp(query_hp());    
    
    set_stats("strength", 24 + random(3));
    set_stats("constitution", 24 + random(4));
    set_stats("dexterity", 11 + random(3));
    set_stats("wisdom", 12 + random(3));
    set_stats("intelligence", 12 + random(3));
    set_stats("charisma", 11 + random(3));
    set_overall_ac(-20);
    set_mob_magic_resistance("average");
    set_gender("male");
    set_name("mizati");
    set_short("%^BOLD%^%^BLACK%^Mizati, A massively muscular %^BOLD%^%^WHITE%^"+
    "minotaur%^BOLD%^%^BLACK%^ with two broken horns%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^This minotaur is massive. His entire body "+
    "ripples with muscles. His head is approxiately 2 feet around and "+
    "inset somewhat lopsidedly in about the center of it are two big "+
    "%^BOLD%^%^YELLOW%^yellow eyes%^BOLD%^%^BLACK%^ which appear "+
    "intelligent and inviting. Atop his head are two %^BOLD%^%^WHITE%^off white"+
    "%^BOLD%^%^BLACK%^ horns, both of which are broken in half. The one on the "+
    "right side looks more recent. His chest has been emblazoned with a "+
    "large '%^BOLD%^%^GREEN%^X%^BOLD%^%^BLACK%^', almost as if someone "+
    "or something branded him as property. His arms and legs are more like tree "+
    "trunks than appendages and he is planted firmly here with massive hooves "+
    "which have been kept neatly trimmed. He is unarmored and carries only a "+
    "massive morningstar which he slings around idly yet carefully when not pacing.%^RESET%^");   
    
    ob = new("/d/common/obj/weapon/giant_morningstar");
    ob->set_property("enchantment", 3);
    ob->move(TO);
    ob->set_item_bonus("strength", 1);
    ob->set_size(4);
    if(random(4)) ob->set_property("monsterweapon", 1);
    command("wield star");
    add_money("silver", 125 + random(55));
    add_money("gold", 175 + random(85));
    add_money("copper", 255 + random(65));    
    set_new_exp(30, "normal");        
    set_monster_feats(({"rush", "impale", "sweepingblow"}));
    ob = new("/d/charucavern/diseases/deep_flu");
    ob->move(TO);
    ob->set_incubation_period(0);
    ob->set_infected(TO);
} 

void catch_say(string msg)
{
    ::catch_say(msg);
    if(!objectp(TP)) return;
    if(interactive(TP)) 
    {
        call_out("response",1,msg,TP);
    }
}

void response(string msg, object ob)
{
    if(!objectp(TO)) return;
    if(!objectp(ob)) return;
    if(strsrch(msg, "hello") != -1 || strsrch(msg, "hi") != -1
    || strsrch(msg, "howdy") != -1 || strsrch(msg, "greeting") != -1 
    || strsrch(msg, "salutation") != -1 || strsrch(msg, "whaddup") != -1
    || strsrch(msg, "hai") != -1 || strsrch(msg, "whatsup") != -1)
    {
        command("speech say gruffly");
        command("emoteat "+ob->query_name()+" turns to $N briefly before speaking");
        command("speak wizish");
        command("say Salutations. I welcome you to our encampment. I am, however, quite "+
        "preoccupied at the moment. You might speak to Xelhor or Gydore, whichever you can find, "+
        "if you are up for helping out around here.");
        command("emote finishing speaking and continues pacing");
        return;
    }
}

