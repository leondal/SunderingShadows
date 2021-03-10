// Father Belanos - The SIlver Thread - LoKi - 20-02-2008


#include <std.h>
#include <daemons.h>
inherit NPC;


void create(){
   object ob;
   ::create();
   set_name("belanos");
   set_short("%^RESET%^%^ORANGE%^Fat%^RESET%^%^BOLD%^%^BLACK%^h"+
"%^RESET%^%^ORANGE%^er B%^RESET%^%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^"+
"lanos%^RESET%^");
   set_id(({ "belanos","father belanos,Father Belanos"}));
   set_long("%^RESET%^%^ORANGE%^An elderly man leaning heavily "+
"on his crooked staff, Father Belanos has the look of a man who "+
"has seen a thousand more things then any human dare see. His "+
"%^RESET%^%^BOLD%^%^WHITE%^lo%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^"+
"%^WHITE%^g whi%^RESET%^%^WHITE%^t%^RESET%^%^BOLD%^%^WHITE%^e h"+
"%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^ir %^RESET%^%^ORANGE%^"+
"drifts down past his shoulders and his %^RESET%^%^BOLD%^%^BLACK%^"+
"s%^RESET%^%^WHITE%^l%^RESET%^%^BOLD%^%^BLACK%^ate gray e%^RESET%^"+
"%^WHITE%^y%^RESET%^%^BOLD%^%^BLACK%^es%^RESET%^%^ORANGE%^ show "+
"a compassion that even the best actor could never hope to replicate."+
" He wears a simple brown robe that bears the signs of constant travel."+
" His skin is a %^RESET%^%^RED%^suntanned hue %^RESET%^%^ORANGE%^and "+
"it is obvious this man spends a lot of time outside. His hands are "+
"marked with a series of %^RESET%^%^BOLD%^%^BLACK%^tribal tattoos "+
"%^RESET%^%^ORANGE%^common with the islands, though they have faded "+
"with age. Around his neck hands a %^RESET%^%^BOLD%^%^WHITE%^si%^RESET%^"+
"%^WHITE%^m%^RESET%^%^BOLD%^%^WHITE%^ple silv%^RESET%^%^WHITE%^e%^RESET%^"+
"%^BOLD%^%^WHITE%^r nec%^RESET%^%^WHITE%^k%^RESET%^%^BOLD%^%^WHITE%^lace"+
" %^RESET%^%^ORANGE%^without any pendant. %^RESET%^");
   set_race("human");
   set_stats("intelligence",20);
   set_stats("wisdom",18);
   set_stats("strength",16);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_alignment(4);
   set_gender("male");
   set_size(2);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(1, ({
"%^RESET%^%^ORANGE%^Belanos leans on his staff and looks around.%^RESET%^",
"%^RESET%^%^ORANGE%^Belanos fingers the %^RESET%^%^BOLD%^silver necklace%^RESET%^%^ORANGE%^ thoughtfully.%^RESET%^",
"%^RESET%^%^ORANGE%^Belanos sings softly in a language you can't recognize.%^RESET%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech speak in a soft reassuring voice");

    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->set_short("%^RESET%^ORANGE%^A simple cloak%^RESET%^");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear cloak");

    ob = new("/d/common/obj/weapon/sstaff");
       ob->move(TO);
       ob->set_short("%^RESET%^ORANGE%^A crooked walking staff%^RESET%^");
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wield staff");
}

void catch_say(string message){
    if(strsrch(message,"silver thread") != -1) {
      call_out("reply_thread",1,TP,message);
    }
    if(strsrch(message,"vasha") != -1) {
      call_out("reply_vasha",1,TP,message);
    }
    if(strsrch(message,"sebastian") != -1) {
      call_out("reply_sebastian",1,TP,message);
    }
    if(strsrch(message,"erik") != -1) {
      call_out("reply_erik",1,TP,message);
    }
    if(strsrch(message,"watts") != -1) {
      call_out("reply_watts",1,TP,message);
    }
    if(strsrch(message,"why are you here") != -1) {
      call_out("reply_why",1,TP,message);
    }
    if(strsrch(message,"askurin") != -1) {
      call_out("reply_askurin",1,TP,message);
    }
}

void reply_thread(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Father Belanos turns...\n");
    force_me("say What was that?");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He chuckles softly...\n");
    force_me("say You know, if you have a secret organization for long enough, "+
"its not really a secret. Though I blame Vasha... Little girl has a big mouth. "+
"Yes, we're here. But never think you can rest because we're here. We can only "+
"help when help is needed. Actually... You probably heard from that ranger.. "+
"Delain... Never had a head for secrecy that one.%^RESET%^");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He leans heavily on his staff and looks at you again.%^RESET%^\n");
    force_me("say That doesn't matter really. You just have to keep up "+
"the fight. No silver streak of godly goodness, no vast army of paladins "+
"will help you now. You have to make a difference. Find Erik Kathor to "+
"learn more.");
    return 1;

}

void reply_vasha(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Father Belanos chuckles...\n");
    force_me("say What can I say about Vasha?");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He thinks carefully...\n");
    force_me("say When I was first told that someone found a black dragon "+
"egg, I braced for the worst. When I learned it was being raised by "+
"Mielikkians, well I almost fell off my chair.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He chuckles.%^RESET%^\n");
    force_me("say I was proved wrong though. And no matter "+
"what Sebastian says, Vasha is a good girl. I don't know where "+
"she is these days, but she is doing good for the silver thread.");
    return 1;

}

void reply_sebastian(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Father Belanos looks you over.\n");
    force_me("say Say what you want about Sebastian.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He stands straighter.\n");
    force_me("say Sebastian has done all he can for the forces of "+
"light. For all his strict talk, he is a teddy bear when he wants to be. ");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He chuckles.%^RESET%^\n");
    force_me("say Okay, not so much a teddy bear. But he is stalwart in his "+
"protection of the north. With Askurin in the west and Erik for Shadow, and "+
"myself, well I left the islands to follow Watts.");
    return 1;

}

void reply_watts(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Father Belanos frowns.\n");
    force_me("say I knew Watts when he was just a thief selling stolen daggers.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He grips his staff tigher.\n");
    force_me("say Now he deals in weapons no mortal should hold. Disgusting "+
"weapons formed from the worst magic. I left my station in the islands "+
"to follow him here. I cannot return until I have put right what he upturned. ");
    tell_room(ETO,"%^RESET%^%^ORANGE%^His expression softens.%^RESET%^\n");
    force_me("say But evil always turns on itself in the end... Right?");
    return 1;

}

void reply_erik(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Father Belanos laughs.\n");
    force_me("say Don't think of asking me about Erik.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He ponders.\n");
    force_me("say He isnt human, I'm sure of that. No one stays a cute "+
"kid like him for twenty years without some serious power.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He nods to himself.%^RESET%^\n");
    force_me("say But no one knows demons like him. No one on this earth, "+
"or.. other places. I hear he went off with some gnomes to a mining platform.");
    return 1;

}

void reply_why(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Father Belanos ponders.\n");
    force_me("say Yes, this isn't my home.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He ponders.\n");
    force_me("say I am here to follow Watts. I need to know what he brought "+
"from the islands, and what he seeks.");
    return 1;

}

void reply_askurin(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Father Belanos nods.\n");
    force_me("say So you've heard of Askurin.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He smiles to himself.\n");
    force_me("say I think Askurin has the purest soul I've ever met. "+
"Though the purest of anything is usually the easiest marred.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^He frowns.%^RESET%^\n");
    force_me("say I am sure that Askurin will find his Lord's forgiveness..."+
" But then we won't have his wisdom, and Vasha will probably leave with him.");
    return 1;

}
void receive_given_item(object obj){
   string name;
      name = TPQN;
         if(!objectp(obj)) return;
            if((string)obj->query_name() == "tears of the lost") {
                  force_me("say So this is what Watts has been after. I fear he is collecting relics for an unholy cause.");
                        tell_room(ETO,"The man takes the dagger and frowns.\n");
                              force_me("say I need to know who these relics are going to! I will curse this so it will be no use to him.");
                                    tell_room(ETO,"The man chants in an unknown tongue and the dagger begins to glow.\n");
                                          obj->set_property("enchantment",-4);
                                                force_me("give "+obj->query_name()+" to "+name+"");
                                                      return;
                                                         }
                                                         
                                                               force_me("say Sorry, not looking for donations.");
                                                                     force_me("give "+obj->query_name()+" to "+name+"");
                                                                        return;
                                                                        }
