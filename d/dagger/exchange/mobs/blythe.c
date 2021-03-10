// Tonovi Slave Trader - Merchant Exchange - LoKi - 20-02-2008


#include <std.h>
#include <daemons.h>
inherit NPC;


void create() {
   object ob;
   ::create();
   set_name("trader");
   set_short("%^RESET%^%^BOLD%^%^BLACK%^Blythe Dargon, T%^RESET%^%^WHITE%^o"+
"%^RESET%^%^BOLD%^%^BLACK%^novi Sla%^RESET%^%^WHITE%^v%^RESET%^%^BOLD%^"+
"%^BLACK%^e Tra%^RESET%^%^WHITE%^d%^RESET%^%^BOLD%^%^BLACK%^er%^RESET%^");
   set_id(({ "blythe dargon","Blythe Dargon, Tonovi Slave Trader",
"slave trader","blythe","blythe dargon", "trader"}));
   set_long("%^RESET%^%^BOLD%^%^BLACK%^This stout human is dressed in a "+
"suit of black studded leather that has been polished to a perfect shine. "+
"An expensive %^RESET%^%^WHITE%^er%^RESET%^%^BOLD%^%^WHITE%^m%^RESET%^%^WHITE%^"+
"ine cl%^RESET%^%^BOLD%^%^WHITE%^o%^RESET%^%^WHITE%^ak %^RESET%^%^BOLD%^%^BLACK%^"+
"drapes casually over his shoulders.  The %^RESET%^%^ORANGE%^hi%^RESET%^%^BOLD%^"+
"%^BLACK%^l%^RESET%^%^ORANGE%^t of a sw%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^"+
"rd %^RESET%^%^BOLD%^%^BLACK%^is exposed at his belt and his hand rests casually on "+
"the pommel. As he moves you also see a %^RESET%^%^RED%^bar%^RESET%^%^BOLD%^%^RED%^"+
"b%^RESET%^%^RED%^ed whip %^RESET%^%^BOLD%^%^BLACK%^hanging within reach. His features"+
" are sharp and his clean shaven face has a look of authority. %^RESET%^%^BOLD%^%^CYAN%^"+
"Ic%^RESET%^%^BOLD%^%^BLUE%^e%^RESET%^%^BOLD%^%^CYAN%^ blu%^RESET%^%^BOLD%^%^BLUE%^e"+
"%^RESET%^%^BOLD%^%^CYAN%^ %^RESET%^%^BOLD%^%^BLACK%^eyes look past bushy black "+
"eyebrows with a casual stare. His %^RESET%^%^WHITE%^long black hair %^RESET%^%^BOLD%^"+
"%^BLACK%^is tied up in a neat pony tail. %^RESET%^");
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
   set_emotes(1, ({
"%^BLACK%^%^BOLD%^Looking at the certificate in his hands, Blythe grumbles.%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Blythe peers over the cafe's edge, frowning at the trading board.%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Blythe rests his hand on the hilt of his blade and taps at the pommel absent-mindedly.%^RESET%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech speak in an gruff harsh tone");


    ob = new("/d/common/obj/armour/studded");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear studded");

    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->move(TO);
       ob->set_short("%^RESET%^BOLD%^An ermine cloak%^RESET%^");
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear cloak");
}

void catch_say(string message){
   if(strsrch(message,"slave") != -1) {
      call_out("reply_fun",1,TP,message);
   }
}

void reply_fun(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Blythe turns.\n");
    force_me("say Slaves are a dangerous business.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^Blythe taps the hilt of his whip.\n%^RESET%^");
    force_me("say Besides the obvious risk to the keeper, you have to deal with the red tape. Tonovi is the worst for that. When you buy slaves, make sure you have a licence from Tonovi. Else, well... You don't want to know.%^RESET%^");
    tell_room(ETO,"%^BLACK%^%^BOLD%^Blythe chuckles, then leans against the railing to watch the trading floor.\n%^RESET%^");
    return 1;

}
