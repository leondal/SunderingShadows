// Torm Arms Dealer - Merchant Exchange - LoKi - 20-02-2008


#include <std.h>
#include <daemons.h>
inherit NPC;



void create() {
   object ob;
   ::create();
   set_name("trader");
   set_short("%^RESET%^%^ORANGE%^Watts Baragoff, Ar%^RESET%^%^BOLD%^%^BLACK%^"+
"m%^RESET%^%^ORANGE%^s D%^RESET%^%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^aler%^RESET%^");
   set_id(({ "watts baragoff","Watts Baragoff, Arms Dealer",
"arms dealer","watts","watts baragoff", "trader"}));
   set_long("%^RESET%^%^ORANGE%^The %^RESET%^%^BOLD%^%^BLACK%^armor "+
"%^RESET%^%^ORANGE%^this human wears barely covers him, and the %^RESET%^"+
"%^BOLD%^%^BLACK%^plate %^RESET%^%^ORANGE%^looks like it is almost ready "+
"to burst from the man's excessive girth. His pudgy face is framed with "+
"%^RESET%^%^RED%^cu%^RESET%^%^ORANGE%^r%^RESET%^%^RED%^ly bro%^RESET%^"+
"%^ORANGE%^w%^RESET%^%^RED%^n hair%^RESET%^%^ORANGE%^. Most of his face "+
"however is hidden behind a large %^RESET%^%^WHITE%^handlebar mustach %^RESET%^"+
"%^ORANGE%^greased to perfection. %^RESET%^%^WHITE%^Steel gray eyes %^RESET%^"+
"%^ORANGE%^have a shine to them as they dart quickly to different spots in "+
"the room. %^RESET%^");
   set_race("human");
   set_stats("intelligence",16);
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
   set_emotes(5, ({
"%^BLACK%^%^BOLD%^Watts looks over your equipment with a "+
"trained eye.%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Watts mutters something about "+
"war.%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Watts speaks quietly with a man, "+
"handing over a certificate.%^RESET%^",
}), 0);
   set_property("no bows",1);
   set_property("no steal",1);
   set_spoken("wizish");
   command("speech speak in a quick tenor");
ob = new("/d/dagger/exchange/obj/watts_key");
       ob->move(TO);

    ob = new("/d/common/obj/armour/fullplate");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear plate");

    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->move(TO);
       ob->set_short("%^RESET%^RED%^A rich red cloak%^RESET%^");
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear cloak");
}

void catch_say(string message){
   if(strsrch(message," war") != -1) {
      call_out("reply_fun",1,TP,message);
   }

    if(strsrch(message,"what are you looking for") != -1) {
      call_out("reply_tears",1,TP,message);
    }

    if(strsrch(message,"tears of the lost") != -1) {
      call_out("reply_about_tears",1,TP,message);
    }

}

void reply_tears(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Watts grins.\n");
    force_me("say Im looking for a weapon... One that is ultimate power. It's a dagger called the.. tears.. something...");
    return 1;

}

void reply_about_tears(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Watts seems to get excited.\n");
    force_me("say Yes! The Tears of the Lost! Find it and give it to me!");
    return 1;

}

void reply_fun(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Watts grins.\n");
    force_me("say War!.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^Watt's mustach quivers as "+
"he grabs his sides.\n%^RESET%^");
    force_me("say War, war is great! Forget honor, duty.. "+
"think profit!");
    tell_room(ETO,"%^BLACK%^%^BOLD%^Watts looks over the "+
"railing to the trading floor.\n%^RESET%^");
    force_me("say They say, in war.. no one wins...");
    tell_room(ETO,"%^BLACK%^%^BOLD%^Watts puts on a sad "+
"face for a moment, then bursts into laughter.\n%^RESET%^");
    force_me("say well, I say that the one who sold both "+
"sides the weapons... wins at least a little. As long as "+
"you were paid up front.");
    return 1;

}
void receive_given_item(object obj){
   string name;
   name = TPQN;
   if(!objectp(obj)) return;
   if((string)obj->query_name() != "tears of the lost") {
      force_me("say This isnt quite what I'm looking for.");
      force_me("give "+obj->query_name()+" to "+name+"");
      return;
   }

   tell_room(ETO,"The man takes the dagger and smiles.\n");
   force_me("say Yes, I don't know how you found it, but this is exactly what my client requires!");
   
   tell_room(ETO,"%^BLACK%^%^BOLD%^The man produces a small key and hands it over.\n");
   obj->remove();
   
// new("/d/dagger/exchange/obj/watts_key.c")->move(TO);
   force_me("say Here is a key to my warehouse. I think I left a trunk there while packing up for the storm");
   force_me("give key to "+name+"");
   return;
}
