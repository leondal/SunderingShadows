#include <std.h>
#include <daemons.h>
#include <move.h>
#include "../area_stuff.h"

#define WYNDARELEM "eldebarowyndarelementalhearts"

inherit NPC;
int IS_EXPLAINING;

mapping MyItems = (["a simple ring" : ELOB+"rop", "a strange malleable substance" : ELOB+"changeling_cover",
"a thick leather cord" : ELOB+"belt_of_summoning", "a short charcoal cloak" : ELOB+"cloak_of_invisibility",
"a serrated sickle" : ELOB+"the_reaping", "a smooth hollow orb" : ELOB+"orb_of_magical_disruption",
"a gleaming longbow" : ELOB+"bow_of_destruction", "a simple azure robe" : ELOB+"robes_of_power",
"a dark leather coif" : ELOB+"coif_of_silence", "a tear shaped amulet" : ELOB+"augmented_tear",
"a heavy oak lance" : ELOB+"lance_of_thorns", "a brilliant flowing garment" : ELOB+"shroud_of_light",
"a flowing dark garment" : ELOB+"shroud_of_darkness", "a curved dark bladed short sword" : ELOB+"mind_guard",
"a curved dark bladed dagger" : ELOB+"mind_pierce", "rough bladed silver axe" : ELOB+"brutal_allocation",
"a large viciously spiked club" : ELOB+"violent_smasher"]);

string get_my_long()
{
    string ret;
    ret = "%^RESET%^%^CYAN%^This man stands a little over six feet tall. His body is muscular and "+
    "well toned, from what you can tell, most of it is hidden beneath a simple %^BOLD%^azure robe"+
    "%^RESET%^%^CYAN%^. His round face is framed with long flowing %^BOLD%^%^YELLOW%^blonde hair"+
    "%^RESET%^%^CYAN%^ that is slightly disheveled. He has very %^BOLD%^intense%^RESET%^%^CYAN%^ "+
    "%^BOLD%^%^GREEN%^green eyes%^RESET%^%^CYAN%^ that look extremely intelligent, patient, and "+
    "gl%^BOLD%^i%^RESET%^%^CYAN%^mm%^BOLD%^e%^RESET%^%^CYAN%^r with a hint of something else that "+
    "you recognize as a profound worry.";
    if(objectp(TP))
    {
        if((int)TP->query("KilledArsheeva"))
        {
            ret += "%^RESET%^%^CYAN%^ He looks deep into your eyes for a brief moment, and then "+
            "a voice inside your mind whispers 'thank you....' I know that you have saved my brother "+
            "from his eternal torment. I will repay you, simply %^BOLD%^%^WHITE%^<%^CYAN%^"+
            "visualize%^BOLD%^%^WHITE%^>%^RESET%^%^CYAN%^ to see what I can offer.%^RESET%^";
        }
        else 
        {
            ret += "%^RESET%^%^CYAN%^ He looks deep into your eyes for a brief moment. You think "+
            "that perhaps you should greet him.%^RESET%^";
        }
    }
    else
    {
        ret += "%^RESET%^%^CYAN%^ He looks deep into your eyes for a brief moment. You think "+
        "that perhaps you should greet him.%^RESET%^";
    }
    return ret;
}

void create() 
{
    object ob;
    ::create();
    set_name("dyveryll wyndar");
    set_id(({"wyndar", "dyveryll wyndar", "psionist of lysara", "human", "dyveryll"}));
    set_gender("male");
    set_race("human");

    set_short("%^RESET%^%^CYAN%^Dyv%^BOLD%^e%^RESET%^%^CYAN%^ryll "+
    "Wynd%^BOLD%^a%^RESET%^%^CYAN%^r, proud psionist of %^BOLD%^%^WHITE%^"+
    "Lysara%^RESET%^");

    set_long((:TO, "get_my_long":));    
    
    set_class("psion", 50);    
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

    set_hp(15000);
	ob = new(ELOB+"robes_of_power");
    ob->move(TO);
    ob->set_property("monsterweapon", 1);
    command("wear robe");
    set_new_exp(1, "very low");
}

void init()
{
    ::init();
    add_action("visualize", "visualize");
    return;
}

int visualize(string str)
{
    object Item;
    string *tmp, act, targ, me;
    int amt, x;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!intp(amt = TP->query("KilledArsheeva"))) return 0;   
    if(amt < 1) return 0;
    if(!stringp(str))
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^Images suddenly fill your mind....");
        tmp = keys(MyItems);
        if(!sizeof(tmp))
        {
            tell_object(TP, "%^B_CYAN%^%^YELLOW%^Something went wrong, Notify Saide!");
            return 1;
        }
        for(x = 0;x < sizeof(tmp);x++)
        {
            tmp[x] = tmp[x] + "\n";
            continue;
        }
        TP->more(tmp);
        tell_object(TP, "%^BOLD%^%^WHITE%^You can <%^BOLD%^%^CYAN%^visualize on 'item'%^BOLD%^%^WHITE%^> to get "+
        "some history about any item.\n%^BOLD%^%^WHITE%^You can <%^BOLD%^%^CYAN%^visualize for 'item'%^BOLD%^%^WHITE%^> "+
        "if you have decided that you want the item. You may still choose "+amt+" items.%^RESET%^");
        return 1;
    }
    if(sscanf(str, "%s %s", act, targ) != 2)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You can <%^BOLD%^%^CYAN%^visualize on 'item'%^BOLD%^%^WHITE%^> to get "+
        "some history about any item.\n%^BOLD%^%^WHITE%^You can <%^BOLD%^%^CYAN%^visualize for 'item'%^BOLD%^%^WHITE%^> "+
        "if you have decided that you want the item. You may still choose "+amt+" items.%^RESET%^");
        return 1;
    }
    /*tell_object(TP, "act = "+act);
    tell_object(TP, "targ = "+targ);
    return 1;*/
    tmp = keys(MyItems);
    if(member_array(targ, tmp) == -1)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^It is beyond my power to conjure up any such item.%^RESET%^");
        return 1;
    }
    if(act == "on")
    {
       Item = new(MyItems[targ]);
       tell_object(TP, "%^BOLD%^%^WHITE%^The history of "+targ+" is : \n");
       tell_object(TP, (string)Item->query_lore()+"\n");
       if(objectp(Item)) Item->remove();
       return 1;
    }
    else if(act == "for")
    {
        me = TO->query_short();
        Item = new(MyItems[targ]);
        
        tell_object(TP, me +"%^BOLD%^%^CYAN%^ chants a quick phrase, conjuring up "+
        Item->query_short()+"%^BOLD%^%^CYAN%^ and handing it to you!%^RESET%^");
        
        tell_room(ETO, me+"%^BOLD%^%^CYAN%^ chants a quick phrase, conjuring up "+
        Item->query_short()+"%^BOLD%^%^CYAN%^ and handing it to "+TP->QCN+
        "!%^RESET%^", TP);
        amt--;
        TP->delete("KilledArsheeva");
        if(amt > 0) TP->set("KilledArsheeva", amt);
        if(Item->move(TP) != MOVE_OK)
        {
            tell_object(TP, "%^BOLD%^%^RED%^You are unable to carry "+Item->query_short()+
            "%^BOLD%^%^RED%^ and drop it!%^RESET%^");
            tell_room(ETO, TPQCN+"%^BOLD%^%^RED%^ drops "+Item->query_short()+
            "%^BOLD%^%^RED%^!%^RESET%^", TP);
            Item->move(ETO);
        }
        return 1;        
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You can <%^BOLD%^%^CYAN%^visualize on 'item'%^BOLD%^%^WHITE%^> to get "+
        "some history about any item.\n%^BOLD%^%^WHITE%^You can <%^BOLD%^%^CYAN%^visualize for 'item'%^BOLD%^%^WHITE%^> "+
        "if you have decided that you want the item. You may still choose "+amt+" items.%^RESET%^");
        return 1;
    }
    return 0;
}

void vanish()
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();
    tell_room(ETO, me+"%^RESET%^%^CYAN%^ suddenly opens a door and steps through... the door "+
    "instantly vanishes along with him!%^RESET%^");
    TO->move("/d/shadowgate/void");
    if(objectp(TO)) TO->remove();
}

void die(object ob)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vanish();
    return;
}

void catch_say(string msg)
{
    if(!objectp(TO)) return;
    ::catch_say(msg);    
    if(!objectp(TP)) return;
    if(interactive(TP)) 
    {
        call_out("response",1,msg,TP);
        return;
    }
}

void do_brother_explain(object ob, int step)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(ob)) return;
    switch(step)
    {
        case 0:
            command("speech say with an obvious sadness");
            command("say The brother that I speak of, is Arsheeva Wyndar. "+
            "He considered himself a warrior-priest of our Lord, Lysara. "+
            "In truth, he was what you might refer to as a monk, but....");
            command("emote smiles briefly his eyes full of sadness.");
            break;
        case 1:
            command("say he was no stranger to combat. He fought and "+
            "defeated evil, the spawn of Nightmares, without hesitation.");
            command("emote chuckles quietly to himself.");
            command("say I am not intending to seem braggish... he was never "+
            "that way himself, at all. He was much more humble than I.");
            break;
        case 2:
            command("say but my brother, he was powerful. Some of us thought "+
            "that maybe Lysara himself had touched him, this is how powerful he "+
            "had become.");
            command("emote stares off in the distance, obviously quite disturbed");
            command("say Something on this island, coming from the island itself "+
            "perhaps, seeped into him, in such a profound way.");
            command("say he killed almost every living thing in the western camp...");
            break;
        case 3:
            command("say only a few men were able to get out before he got to "+
            "them. Only a couple of those were able to speak afterwards... ");
            command("say they say that he used his power and just killed everyone... "+
            "and as if in agony he ripped all of his clothing off...");
            command("emote sighs for a long drawn out moment");
            break;
        case 4:
            command("say they said that he seemed to be fighting against something, "+
            "viciously fighting... but that he eventually succumbed...");
            command("say he just wandered off into the desert and has not been seen or "+
            "heard from since. My attempts to speak to him have failed, though our entire lives "+
            "we have been able to talk telepathically... no longer...");
            break;
        case 5:
            command("say if you are determined to help, I suggest that you start in "+
            "what is left of the western camp.");
            command("emote wipes his green eyes before continuing");
            command("say I believe that you will likely have to find.... and stop "+
            "my brother...");
            break;
        case 6:
            command("say this will be no easy task. Before my brother was possessed "+
            "I had never seen another creature able to stand against him in battle... not in "+
            "all of my years.");
            command("say if something is able to control his mind and bend it to "+
            "a perverse will... then I fear that your task will be even more "+
            "difficult. He will not go down easily.");
            command("say perhaps there is some part of him left, if what the men say is "+
            "true, that will allow him to fight against whatever is possessing him.");            
            break;
        case 7:
            command("say should you succeed.. should you find the strength to end my "+
            "brother's torment, then return to me, and I will reward you.");
            command("say I only wish that I could do more to help you. For now, I will "+
            "stay here and protect the camp. We will be working on regrouping and formulating "+
            "a plan to find out what it is that we battle against and hopefully find a way to "+
            "destroy it.");
            break;
    }
    if(step < 7)
    {
        step++;
        call_out("do_brother_explain", 20, ob, step);
        return;
    }
    else 
    {
        IS_EXPLAINING = 0;
        return;
    }
}

void do_elemental_explain(object ob, int step)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(ob)) return;
    switch(step)
    {
        case 1:
            command("speech speak thoughtfully");
            command("say there are some elementals roaming the island now. "+
            "Storm elementals to be precise and they are quite powerful. "+
            "We are curious about what created them and what powers them now.");
            break;
        case 2:
            command("say they did not start showing up until the darkness seeped out "+
            "of the island, so we believe that they are connected. One of our men "+
            "reportedly witnessed one defeated and when it died, there was "+
            "a chunk of strange material left behind.");
            break;
        case 3:
            command("say it is our desire to study this material, to see if it might "+
            "be of some use in allowing us to figure out exactly what it is that we "+
            "battle against... and hopefully to allow us to find a way to stop it.");
            break;
        case 4:
            command("say should you defeat one of these creatures and find some of this "+
            "material return it to me and I will see that you are paid well for your trouble.");
            break;
    }
     if(step < 4)
    {
        step++;
        call_out("do_elemental_explain", 20, ob, step);
        return;
    }
    else 
    {
        IS_EXPLAINING = 0;
        return;
    }
}

void do_mission_explain(object ob, int step)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(ob)) return;
    switch(step)
    {
        case 0:
            command("speech say with an air of determination");
            command("say Our mission here was simple.... or so we "+
            "thought. For many years the island of Eldebaro has been "+
            "plagued by undead, as you likely know. We were tasked with "+
            "finding the source of the evil spawning the undead and eliminating "+
            "it.");
            break;
        case 1:
            command("say We have undertaken such tasks multitudes of times in "+
            "the past. We have always been successful...");
            command("emote sighs deeply before continuing.");
            command("say it is true that there have been times of great loss. "+
            "We are no stranger to suffering, by any means. This time, however, we "+
            "were woefully unprepared.");
            break;
        case 2:
            command("say we quickly realized at least a portion of the power "+
            "of the evil when some of our men began showing signs of what "+
            "could be termed possession.");
            command("say my brother and I responded swiftly though, most of the "+
            "men were sent back to our home and we established two camps. This one, "+
            "on the south eastern side of the Island, which I have been working to "+
            "protect. The other on the south western side of The Island.");
            break;
        case 3:
            command("say what happened... defies my understanding and my ability "+
            "to explain... but somehow....");
            command("emote frowns deeply and then just shakes his head before continuing");
            command("say somehow my brother himself, was possessed. The men, they had "+
            "been possessed by something that I could expel, something that was "+
            "easy to detect even.");
            command("say whatever it was that grabbed my brother... did so quietly...");
            command("emote stares off blankly for a few moments");
            break;
        case 4:
            command("emote shakes his head and seems more focused before continuing");
            command("say it was only quiet for a little while. Then it was "+
            "tremendously loud! It seized my brother, causing him to go on a rampage.");
            command("say only a few of our men were able to get out of the western camp and "+
            "they were so disturbed by what they witnessed that most of them were mute.");
            break;
        case 5:
            command("say if you truly mean to help, then you must take care. You must "+
            "take caution to a level the likes of which you have never before known.");
            command("say I am afraid that I am not sure what exactly it is that you "+
            "might find. But the western camp... or what remains of it, would be a good "+
            "place to start.");
            command("say a word of warning, if you have somehow not noticed, the island "+
            "has been overrun, literally, with other foul beasts, and some of our own men "+
            "wander the land now. After my brother.... a darkness seeped out of the land and "+
            "drove many of them insane.");
            break;
    }
    if(step < 5)
    {
        step++;
        call_out("do_mission_explain", 20, ob, step);
        return;
    }
    else 
    {
        IS_EXPLAINING = 0;
        return;
    }
}

void response(string msg, object ob)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(ob)) return;
    if(!stringp(msg)) return;
    if(IS_EXPLAINING) return;
    if(strsrch(msg, "ello") != -1 || strsrch(msg, "reeting") != -1 ||
    strsrch(msg, "howdy") != -1 || (strsrch(msg, "hi") != -1 && strsrch(msg, "him") == -1))
    {
        command("speech say with an obvious sadness");
        command("say Greetings Adventure. I wish that I were in higher spirits. "+
        "Our %^BOLD%^%^CYAN%^mission%^RESET%^ here was set to be a grand one, afterall. However, "+
        "my %^BOLD%^%^CYAN%^brother%^RESET%^ has fallen victim...");
        command("emote sighs deeply and rubs his forehead in exasperation");
        command("say I fear that I have said enough for now, if you are interested in being of "+
        "help, then let me know.");
        return;
    }    
    if(strsrch(msg, "help") != -1) 
    {
        command("speech say with an air of determination");
        command("say if you are truly interested in being helpful. I can tell you briefly "+
        "about the %^BOLD%^%^CYAN%^elementals%^RESET%^ that roam the island. "+
        "I can explain to you what our %^BOLD%^%^CYAN%^mission%^RESET%^ was. I am also willing to talk about "+
        "my %^BOLD%^%^CYAN%^brother%^RESET%^ and I must confess that he is what troubles "+
        "me the most right now.%^RESET%^");
        command("emoteat "+ob->query_name()+" looks at $N carefully, as if awaiting $P response.");
        return;
    }
    if(strsrch(msg, "mission") != -1)
    {
        IS_EXPLAINING = 1;
        do_mission_explain(ob, 0);
        return;        
    }
    if(strsrch(msg, "brother") != -1)
    {
        IS_EXPLAINING = 1;
        do_brother_explain(ob, 0);
        return;
    }
    if(strsrch(msg, "elemental") != -1)
    {
        IS_EXPLAINING = 1;
        do_elemental_explain(ob, 0);
        return;
    }
    return;
}

void heart_beat()
{
    if(!objectp(TO)) return;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(sizeof(TO->query_attackers()))
    {
        vanish();
        return;
    }
    return;
}

int get_count()
{
    int *saved_arr;
    int amt;
    if(!pointerp(saved_arr = SAVE_D->query_array(WYNDARELEM)) || !sizeof(saved_arr))
    {
        amt = 1;
        SAVE_D->remove_array(WYNDARELEM);
        SAVE_D->set_value(WYNDARELEM, amt);
        return amt;
    }
    else amt = saved_arr[0];
    amt++;
    SAVE_D->remove_array(WYNDARELEM);
    SAVE_D->set_value(WYNDARELEM, amt);
    return amt;
}


void receive_given_item(object ob)
{
    string tmp, *tmp_array;
    int amt;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(ob)) return;
    if(!objectp(TP)) return;
    if(!ob->id("eldebaro_heart_of_the_storm_xxx"))
    {
        command("emote frowns and shakes his head before speaking.");
        command("say I have no use for this item.");
        tmp_array = ob->query_id();
        if(!sizeof(tmp_array)) return;
        tmp = tmp_array[0];
        command("give "+tmp+" to "+TP->query_name());
        return;
    }
    command("emote smiles warmly for a brief moment.");
    command("say thank you, I believe this material might "+
    "be of use to us eventually.");
    command("emote tucks the material away in his robe.");
    command("say we will work on unlocking the secrets of it "+
    "soon.");
    command("emoteat "+TP->query_name() +" tosses $N a large pouch of gold coins");
    TP->add_money("gold", (8000 + random(5000)));
    ob->remove();
    amt = get_count();
    if(amt == 1)
    {
        command("say thank you, this is the first piece of the material that "+
        "we have collected.");
        return;
    }
    command("say to date we have collected "+amt+" pieces of the material.");
    return;    
}

void set_paralyzed(int time,string message) { return;}

void set_tripped(int time, string message) { return; }
