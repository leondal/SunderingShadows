
// Mathilda Foster, Retired Golden Guard - LoKi - 2021

#include <std.h>
#include <daemons.h>
inherit NPC;
object ob;

void create() {
   ::create();
   set_name("Mathilda Foster");
   set_short("%^YELLOW%^Mat%^RESET%^%^ORANGE%^h%^YELLOW%^ilda F%^RESET%^%^RED%^o%^YELLOW%^ster%^RESET%^");
   set_id(({ "mathilda","mathilda foster","foster"}));
   set_long("%^BOLD%^Wearing a %^RESET%^%^ORANGE%^simple "+
   "%^BOLD%^golden %^RESET%^%^ORANGE%^cloak, %^BOLD%^%^WHITE%^this "+
   "%^BLACK%^elderly %^WHITE%^human woman blends in perfectly with "+
   "any of the %^RESET%^%^CYAN%^revelers %^BOLD%^%^WHITE%^dancing and "+
   "singing around her. The only difference is that as you regard her, "+
   "she looks back with a %^MAGENTA%^calm %^WHITE%^and %^RESET%^%^MAGENTA%^"+
   "measured %^BOLD%^%^WHITE%^air. The %^ORANGE%^cloak %^WHITE%^she has "+
   "wrapped around her is tied at her throat with a brooch of "+
   "%^ORANGE%^shield of gold %^WHITE%^with a %^RED%^crimson rose upon "+
   "%^WHITE%^it. In her hands she holds a %^RESET%^%^ORANGE%^heavy "+
   "tome%^BOLD%^%^WHITE%^. She could be %^BLACK%^forty%^WHITE%^, or "+
   "%^BLACK%^eighty%^WHITE%^, it is hard to tell as she is in peak "+
   "physical condition and even with some gray streaks in her hair, "+
   "it still retains most of its %^ORANGE%^golden blond %^WHITE%^hue.%^RESET%^");
   set_race("human");
   set_stats("intelligence",20);
   set_stats("wisdom",18);
   set_stats("strength",16);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("cleric");
   set_mlevel("cleric",30);
   set_guild_level("cleric",30);
   set_alignment(4);
   set_gender("female");
   set_size(2);
   set_exp(0);
   set_overall_ac(-40);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(1, ({
      "%^RESET%^%^ORANGE%^Mathilda balances her book in her "+
	  "hands.%^RESET%^",
      "%^RESET%^%^MAGENTA%^With a smile, Mathilda greets an "+
	  "overzealous reveler.%^RESET%^",
      "%^BLACK%^%^BOLD%^Mathilda quietly spaks with a templar, "+
	  "who hurries off to where she points.%^RESET%^",
   }), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech %^ORANGE%^speak with a soft commanding tone");

    ob = new("/d/common/obj/armour/cloak_hooded");
       ob->set_short("%^YELLOW%^golden cloak%^RESET%^");
       ob->move(TO);
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear cloak");

    ob = new("/d/common/obj/weapon/sstaff");
       ob->move(TO);
       ob->set_short("%^ORANGE%^a heavy book%^RESET%^");
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wield staff");
}

void catch_say(string message){
    if(strsrch(message,"hello") != -1) {
      call_out("reply_hello",1,TP,message);
    }
    if(strsrch(message,"glow") != -1) {
      call_out("reply_glow",1,TP,message);
    }
    if(strsrch(message,"reveler") != -1) {
      call_out("reply_reveler",1,TP,message);
    }
    if(strsrch(message,"jarmila") != -1) {
      call_out("reply_jarmila",1,TP,message);
    }
    if(strsrch(message,"dragon") != -1) {
      call_out("reply_dragon",1,TP,message);
    }
    if(strsrch(message,"celebration") != -1) {
      call_out("reply_celebration",1,TP,message);
    }
    if(strsrch(message,"templar") != -1) {
      call_out("reply_templar",1,TP,message);
    }    
	if(strsrch(message,"rumor") != -1) {
      call_out("reply_rumors",1,TP,message);
    }
}

void reply_hello(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Mathilda turns to face you "+
	"with a smile.%^RESET%^\n");
    force_me("say What can I help you with child?");
    tell_room(ETO,"%^RESET%^%^ORANGE%^She shifts her book to her "+
	"other arm.\n%^RESET%^");
    force_me("say I assume you are here about the glow or the "+
	"revelers. My name is Mathilda, I am- I mean was.. a Paladin "+
	"of the Golden Guard.");
    tell_room(ETO,"%^YELLOW%^Mathilda closes her eyes a moment as "+
	"if enjoying a memory.%^RESET%^\n");
    force_me("say So.. What would you like to know about?");
    return 1;

}

void reply_glow(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Mathilda looks up at the "+
	"glow above.\n");
    force_me("say The glow appeared after a lance of pure light"+
"	struck the top of the hill.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^Turns to face you again.\n");
    force_me("say I know that there are rumors of what is up there "+
	"but we cannot rush blindly in can we? I know that several "+
	"sought a pilgrimage up the hill and did not return, until "+
	"the templar guard set up a proper perimeter.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^She frowns.%^RESET%^\n");
    force_me("say The glow has attracted all manner of beasts, "+
	"and not all are interested in singing and dancing.");
    return 1;

}

void reply_reveler(string msg, object who){
    tell_room(ETO,"%^BOLD%^A dancing and singing reveler runs "+
	"into both you and Mathilda.%^RESET%^\n");
    force_me("say Aren't they delightful?");
    tell_room(ETO,"%^RESET%^%^ORANGE%^Mathilda adjusts her "+
	"cloak.%^RESET%^\n");
    force_me("say The glow and the celebration has attracted "+
	"all manner of people. Some came with curiosity, some with "+
	"an eye to profit, even crime, but once they got here they "+
	"can only think of the celebration itself. The power of love, "+
	"is a powerful one.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^Mathilda regards you "+
	"carefully.%^RESET%^\n");
    force_me("say Now you're mostly immune I see... I hope that "+
	"bodes well for us.");
    return 1;

}

void reply_jarmila(string msg, object who){
    force_me("say Jarmila you say?");
    tell_room(ETO,"%^RESET%^%^ORANGE%^Mathilda smiles.\n");
    force_me("say If it is my Champion of the Rose on the hill "+
	"top I am filled with happiness for the realm. There has "+
	"been so much darkness.");
    tell_room(ETO,"%^RESET%^%^ORANGE%^Mathilda clutches her book "+
	"closely.\n");
    force_me("say Remember though. Even if her avatar rests there, "+
	"she is everywhere and she is always. That s just a reflection of her love.");
    return 1;

}

void reply_dragon(string msg, object who){
    tell_room(ETO,"%^RESET%^%^ORANGE%^Mathilda points up at "+
	"the sky\n");
    force_me("say Are you asking about that silver dragon on the wing?");
    tell_room(ETO,"%^RESET%^%^ORANGE%^Mathilda smiles.\n");
    force_me("say If I remember his shape, that is Zykiero.");
    tell_room(ETO," %^RED%^several lanterns are released into "+
	"the sky, filling it with a beautiful spread of fire.%^RESET%^\n");
    force_me("say He is young and brash, and arrived soon after the glow. "+
	"I think he is looking for war, and hopes this heralds it.");
    return 1;

}

void reply_monsters(string msg, object who){
    tell_room(ETO,"%^C008%^Mathilda looks pensive%^CRST%^\n");
    force_me("say Have you ever seen a foo creature?");
    tell_room(ETO,"%^C008%^Mathilda frowns.%^CRST%^\n");
    force_me("say They are so beautiful, but so dangerous.");
    force_me("say Once you get up there you're just an enemy to them. Remember that.");

}

void reply_celebration(string msg, object who){
    tell_room(ETO,"%^C184%^Mathilda smiles%^CRST%^\n");
    force_me("say Once people came they got caught up in "+
	"the glow.");
    tell_room(ETO,"%^C254%^Mathilda looks up as a silver dragon floats on the clouds.%^CRST%^\n");
    force_me("say Some call it the party of the dragon as well.");
    force_me("say I dont think he came for a party though.");

}

void reply_templar(string msg, object who){
    tell_room(ETO,"%^C141%^Mathilda nods%^CRST%^\n");
    force_me("say The templar came after the first group of revelers went up the hill.");
    tell_room(ETO,"%^C241%^Mathilda frowns.%^CRST%^\n");
    force_me("say If only we got here before that.");
    force_me("say The templar will continue to patrol and keep the party here.");

}

void reply_rumors(string msg, object who){
    tell_room(ETO,"%^C141%^Mathilda leans closer%^CRST%^\n");
    force_me("say There is a rumor the glow is a powerful force.");
    tell_room(ETO,"%^C241%^Mathilda looks around.%^CRST%^\n");
    force_me("say Perhaps even a god.");
    
}




