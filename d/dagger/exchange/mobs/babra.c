// Azha Spice - Merchant Exchange - LoKi - 20-02-2008


#include <std.h>
#include <daemons.h>
inherit NPC;


void create() {
   object ob;
   ::create();
   set_name("trader");
   set_short("%^RESET%^%^ORANGE%^Babra Ta-Tok, M%^RESET%^%^YELLOW%^"+
"a%^RESET%^%^ORANGE%^ster of Spi%^RESET%^%^YELLOW%^c%^RESET%^"+
"%^ORANGE%^es%^RESET%^");
   set_id(({ "babra ta-tok","Babra Ta-Tok, Master of Spices",
"spices dealer","babra","ta-tok", "trader"}));
   set_long("%^RESET%^%^ORANGE%^A minotaur of great size and "+
"obvious strength, Babra towers over most humans. His body is "+
"humanoid, giant muscles and a barrel chest covered by a  "+
"%^RESET%^%^BOLD%^%^BLACK%^th%^RESET%^%^WHITE%^i%^RESET%^"+
"%^BOLD%^%^BLACK%^ck black %^RESET%^%^WHITE%^f%^RESET%^%^BOLD%^"+
"%^BLACK%^ur%^RESET%^%^ORANGE%^. The only clothing he is wearing"+
" is a large kilt with a strange %^RESET%^%^WHITE%^b%^RESET%^"+
"%^BOLD%^%^BLUE%^lue a%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^BLUE%^"+
"d gray ta%^RESET%^%^WHITE%^r%^RESET%^%^BOLD%^%^BLUE%^tan%^RESET%^"+
"%^ORANGE%^. His head is that of a bull, the only real difference "+
"being his eyes, which shine with obvious intelligence. %^RESET%^");
   set_race("minotaur");
   set_stats("intelligence",14);
   set_stats("wisdom",18);
   set_stats("strength",20);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_alignment(4);
   set_gender("male");
   set_size(3);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(2, ({
"%^RESET%^%^RED%^Babra bares his teeth at a gawker, chuckling deeply as they run off.%^RESET%^",
"%^RESET%^%^RED%^Babra hands over a pouch of spices to the staff of the cafe with a wide smile.%^RESET%^",
"%^RESET%^%^RED%^Crossing his immense arms, Babra looks over the trading floor and nods.%^RESET%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech speak thick tsvarnen accent");


    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->move(TO);
       ob->set_short("%^RESET%^%^WHITE%^l%^RESET%^%^BOLD%^"+
"%^BLUE%^arge k%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^BLUE%^lt "+
"with a %^RESET%^%^WHITE%^b%^RESET%^%^BOLD%^%^BLUE%^lue an%^RESET%^"+
"%^WHITE%^d %^RESET%^%^BOLD%^%^BLUE%^gray ta%^RESET%^%^WHITE%^r"+
"%^RESET%^%^BOLD%^%^BLUE%^tan%^RESET%^");
       ob->set_property("size",3);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear cloak");
}

void catch_say(string message){
   if(strsrch(message,"spice") != -1) {
      call_out("reply_fun",1,TP,message);
   }
}

void reply_fun(string msg, object who){
    tell_room(ETO,"%^RESET%^%^RED%^Babra glances over.%^RESET%^\n");
    force_me("say Pfft, you northeners know nothing of taste.");
    tell_room(ETO,"%^RESET%^%^RED%^Babra chuckles.\n%^RESET%^");
    force_me("say I have spices that would delight "+
"and entrance...");
    tell_room(ETO,"%^RESET%^%^RED%^Babra looks you over.\n%^RESET%^");
    force_me("say But I think your bodies... You cannot handle.");
    tell_room(ETO,"%^RESET%^%^RED%^Babra turns and walks away.\n%^RESET%^");    
    return 1;

}
