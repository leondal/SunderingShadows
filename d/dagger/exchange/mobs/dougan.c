// Torm Arms Dealer - Merchant Exchange - LoKi - 20-02-2008


#include <std.h>
#include <daemons.h>
inherit NPC;
int flag;
object ob;

void create() {
   ::create();
   set_name("dougan");
   set_short("%^RESET%^%^BOLD%^%^WHITE%^Dougan Frost, %^RESET%^%^BOLD%^%^BLACK%^"+
"C%^RESET%^%^GREEN%^o%^RESET%^%^BOLD%^%^BLACK%^mman%^RESET%^%^GREEN%^d%^RESET%^%^BOLD%^"+
"%^BLACK%^er of the Dr%^RESET%^%^GREEN%^a%^RESET%^%^BOLD%^%^BLACK%^goon Irregula"+
"%^RESET%^%^GREEN%^r%^RESET%^%^BOLD%^%^BLACK%^s%^RESET%^");
   set_id(({ "dougan frost","Dougan Frost Commander of the Dragoons, dragoon",
"commander","Dougan","Frost"}));
   set_long("%^RESET%^%^ORANGE%^Dougan is a human in his mid thirties. He has the "+
"look of a grizzled veterem of countless engagements. His deeply %^RESET%^%^RED%^"+
"tanned skin %^RESET%^%^ORANGE%^is marred by several %^RESET%^%^WHITE%^scars %^RESET%^"+
"%^ORANGE%^and his short brown hair has the signs of %^RESET%^%^BOLD%^%^BLACK%^early "+
"gray%^RESET%^%^ORANGE%^. He wears scuffed studded leather and %^RESET%^%^BOLD%^%^BLACK%^"+
"iron shoulder plates %^RESET%^%^ORANGE%^decorated with the insignia of the Dragoons. "+
"Two sheaths hang at his sides. A %^RESET%^%^GREEN%^gre%^RESET%^%^BOLD%^%^BLACK%^e%^RESET%^"+
"%^GREEN%^n and b%^RESET%^%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^ack cl%^RESET%^%^BOLD%^"+
"%^BLACK%^o%^RESET%^%^GREEN%^ak %^RESET%^%^ORANGE%^drapes casually over his shoulders"+
".%^RESET%^");
   set_race("human");
   set_stats("intelligence",13);
   set_stats("wisdom",13);
   set_stats("strength",18);
   set_stats("charisma",16);
   set_stats("dexterity",18);
   set_stats("constitution",17);
   set_class("fighter");
   set_mlevel("fighter",35);
   set_guild_level("fighter",35);
   set_alignment(4);
   set_gender("male");
   set_size(2);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(500);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(5, ({
"%^BLACK%^%^BOLD%^Dougan looks you over and nods.%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Dougan looks over some reports on his desk.%^RESET%^",
"%^RESET%^%^BOLD%^%^BLACK%^Dougan intones in a soft yet commanding voice '%^RESET%^I dont "+
"want any trouble in the exchange. This is my comfy retirement.'%^RESET%^",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech intone in a soft yet commanding voice");

    ob = new("/d/attaya/obj/shoulderplate.c");
       ob->move(TO);
       ob->set_property("size",2);
       ob->set_property("monsterweapon",1);
       ob->set_obvious_short("%^BLACK%^%^BOLD%^iron shoulderplates%^RESET%^");
       command("wear plate");

    ob = new("/d/common/obj/armour/helm");
       ob->move(TO);
       ob->set_short("%^RESET%^%^GREEN%^gre%^RESET%^%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^n and b%^RESET%^%^BOLD%^%^BLACK%^l%^RESET%^%^GREEN%^ack cl%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^ak%^RESET%^");
       ob->set_property("enchantment",3);
       ob->set_property("monsterweapon",1);
       command("wear helm");

    ob = new("/d/common/obj/sheath/jeweled_msheath.c");
       ob->move(TO);
       ob->set_property("monsterweapon",1);
       command("wear sheath");

    ob = new("/d/common/obj/sheath/jeweled_msheath.c");
       ob->move(TO);
       ob->set_property("monsterweapon",1);
       command("wear sheath");

    ob = new("/d/attaya/obj/cursed.c");
       ob->move(TO);
       ob->set_property("size",2);
       ob->set_property("monsterweapon",1);
       command("sheath sword");

    ob = new("/d/attaya/obj/cursed.c");
       ob->move(TO);
       ob->set_property("size",2);
       ob->set_property("monsterweapon",1);
       command("sheath sword");

}

void catch_say(string message){
   if(strsrch(message,"rules") != -1) {
      call_out("reply_rules",1,TP,message);
   }
   if(strsrch(message,"dragoon") != -1) {
      call_out("reply_dragoon",1,TP,message);
   }
}

void reply_rules(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Dougan gestures to the sign.\n");
    force_me("say If you can read...");
    tell_room(ETO,"%^BLACK%^%^BOLD%^He chuckles softly and adjusts"+
" his shoulderplates.\n%^RESET%^");
    force_me("say This is my place, and the rules are easy to "+
"follow. Don't cause trouble, dont contribute to trouble. Keep "+
"your weapons sheathed and your magic and fingers to themselves. "+
"Easy right?");
    return 1;

}

void reply_dragoon(string msg, object who){
    tell_room(ETO,"%^BLACK%^%^BOLD%^Dougan gestures to the insignia on his "+
"shoulderplates.\n");
    force_me("say I formed the Dragoons a few years back. Thought I'd use "+
"all that gold I saved up for something, and I didn't feel like owning an inn.");
    tell_room(ETO,"%^BLACK%^%^BOLD%^He chuckles and looks around.\n%^RESET%^");
    force_me("say The Dragoon Irregulars... Some hate us, some love us. "+
"We hold the contract for the Exchange. So my word... Is law.");
    return 1;

}

heart_beat() {
  object atkr;

  if(!objectp(TO)) return;
  ::heart_beat();
  atkr = query_current_attacker();
  if(!atkr) {
    flag = 0;
    if(ob=present("sword")){
        force_me("sheath sword");
        force_me("sheath sword");
    }
    return;
  }
  if(flag) return;

 tell_room(environment(TO), "Dougan leaps over and desk and rushes "+atkr->query_cap_name()+" drawing two wicked swords...");
  force_me("draw sword");
  force_me("draw sword");
  force_me("poseclear");
  flag = 1;
  force_me("rush "+atkr->query_name());
}
