//trader in Seneca - slightly unhinged, will expand more later by ~Circe~ in support of Odin 8/3/19
//tells different stories of where she gets her items, keeps getting jailed for running a business
//without a license, someone higher up in Seneca keeps bailing her out, but she doesn't know it
//has a 'pet' hedgehog that interacts with her
#include <std.h>
#include "/d/attaya/defs.h"

inherit NPC;

void create(){
   ::create();
   set_name("verity");
   set_id(({"verity","Verity","verity gallo","gallo","trader"}));
   set_short("Verity Gallo, trader extraordinaire");
   set_long("%^RESET%^%^CYAN%^Dressed in unusual skin-tight %^MAGENTA%^pants %^CYAN%^with slit sides closed with %^RESET%^metal loops%^CYAN%^, Verity Gallo is a somewhat enigmatic figure. Her considerable height is enhanced by %^BOLD%^%^BLACK%^high-heeled boots%^RESET%^%^CYAN%^, and she wears a %^BOLD%^%^BLUE%^cloak %^RESET%^%^CYAN%^thrown over her enormous backpack, as if to hide the contents. Countless %^ORANGE%^pouches %^CYAN%^and %^RESET%^sacks %^CYAN%^are scattered around her person, and she wears her hair loose in a riot of %^BOLD%^%^BLACK%^curls %^RESET%^%^CYAN%^that fall to her shoulders. %^RESET%^S%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r %^RESET%^ea%^BOLD%^r%^CYAN%^ri%^WHITE%^n%^RESET%^gs %^CYAN%^supporting %^BOLD%^gems %^RESET%^%^CYAN%^in shades of %^BOLD%^%^WHITE%^white %^RESET%^%^CYAN%^and %^BOLD%^bl%^BLUE%^u%^CYAN%^e%^RESET%^%^CYAN%^ line both her ears with a matching piece of jewelry through her right eyebrow. She is rarely, if ever, seen without a tiny %^ORANGE%^hedgehog %^CYAN%^perched on her shoulder or darting about around her feet. One small pouch at her hip looks curiously hedgehog-shaped.%^RESET%^");
   set_hd(35,10);
   set("aggressive", 0);
   set_level(35);
   set_gender("female");
   set_class("fighter");
   set_mlevel("fighter", 35);
   set_guild_level("fighter",35);
   set_alignment(5);
   set_race("human");
   add_money("gold", random(25));
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_overall_ac(-30);
   set_stats("strength",20);
   set_stats("intelligence",18);
   set_stats("wisdom",12);
   set_stats("dexterity",19);
   set_stats("constitution",17);
   set_stats("charisma",16);
   set_max_hp(350+random(50));
   set_hp(query_max_hp());
   set_exp(100);
   set_property("swarm",0);
   force_me("speech boast");
   call_out("summon_hedgehog",1);
   set_emotes(1,({
      "Verity swirls her cloak dramatically as she takes a seat on the steps.",
      "Lowering her pack, Verity riffles through the contents before cinching it closed and hoisting it again.",
      "With shifty eyes, Verity peers up and down the streets.",
      "%^RESET%^%^MAGENTA%^Verity says: %^RESET%^You haven't seen any guards around, have you?"
   }),0);
}

void summon_hedgehog(){
   object ob;
   ob=new("/d/attaya/newseneca/mon/clover.c");
   if ( (!objectp(ob)) || (!objectp(TO)) || (!objectp(ETO)) ) return;
   ob->move(ETO);
   tell_room(ETO,"A hedgehog emerges from the pocket at Verity's hip, yawning and blinking its eyes.");
   return;
}

void reset(){
   ::reset();
   if(!present("clover",ETO)){
      call_out("summon_hedgehog",1);
   }
}

void catch_say(string msg){
   if(!objectp(TO)) return;
   ::catch_say(msg);
   if(!objectp(TP)) return;
   if(interactive(TP)){
      call_out("reply_func",1,msg,TP);
      return;
   }
   return;
}

void reply_func(string msg, object who){
   string name;
   set_spoken("wizish");
   name = who->query_name();
   if(!msg || !objectp(who) || (wizardp(who) && who->query_invis())) return;
   if(strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 || strsrch(msg,"reeting") != -1 || strsrch(msg,"Hey") != -1){
      force_me("say Well, hello there! What can I do for ya? Are you looking for some quality merchandise? I got some right here, ya know.");
      force_me("emote winks and pats her backpack.");
      return;
   }
   if(strsrch(msg,"erchandise") != -1 || strsrch(msg,"stuff") != -1 || strsrch(msg,"rystal") != -1 || strsrch(msg,"sword") !=-1 || strsrch(msg,"trad") !=-1){
      switch (random(3)){
         case 0: force_me("emote hmms and glances around before clearing her throat.");
                 force_me("speech murmur in a low voice");
                 force_me("say I got ties to the Crystal Tower, if you know what I mean. If you find some stuff from there, maybe some things you don't want, bring 'em to me. Maybe I can find something to trade you.");
                 force_me("whisper "+name+" I heard Intruder has this enormous sword I've been tryin' to get my hands on. Think you can bring it to me?");
                 force_me("speech boast");
                 break;
         case 1: force_me("My family goes way back with the Crystal Tower. My great-great-great-great ... wait, how many is that? Anyway, my lots-of-greats grandmother was Tiergaina the Enchantress herself!");
                 force_me("emote gives a proud grin");
                 force_me("say I wouldn't mind gettin' my hands on that sword of Intruder's. I got a buyer all lined up. I'd get it myself if it wasn't for my bad back.");
                 break;
         default: force_me("emoteat "+name+" glances at $N suspiciously, narrowing her eyes.");
                  force_me("say Think you got what it takes to take on Intruder?");
                  force_me("say Bring back his sword to prove it. Maybe I'll have something for you.");
                  break;
      }
      return;
   }
   return;
}

//starting with one item - space to add more as Odin or whoever else codes them ~Circe~ 8/15/19
void receive_given_item(object obj) {
  string name, *ids;
  object obj2;

  if(!objectp(obj) || !objectp(TP) || !objectp(ETO)) return;
  switch(obj->query_name()){
    case "Bonestripper": // trade for Guardian of Tel-Quessir
      obj2 = new(OBJ+"guardianoftelquessir.c");
      trade_em(obj, obj2);
      break;
    default:
      ids = obj->query_id();
      force_me("say What makes you think I need that? I got twenty of 'em!");
      force_me("drop "+ids[0]);
      break;
  }
}

void trade_em(object obj, object obj2) {
   int ench;
   string *ids;
   if(!objectp(obj) || !objectp(obj2)) return;
   if(!objectp(TP) || !objectp(ETO)) return;
   ids = obj->query_id();
   force_me("say Hey! Just what I was looking for...");
   if(present("clover",ETO) && !random(3)){
      force_me("emote grins at Clover and holds the "+ids[0]+" out for the hedgehog to inspect.");
      tell_room(ETO,"Clover's nose twitches as she inspects the "+ids[0]+" and then squeaks, climbing up Verity before settling into a pouch at her hip.");
      force_me("laugh");
      force_me("say Looks like it's the real deal!");
   }
   force_me("emote slings her backpack onto the ground and rummages through it.");
   obj->remove();
   force_me("say Fair's fair ... here you go.");

   ench = (int)obj2->query_property("enchantment");
   if(ench < 0) { // no cursed items allowed!
      obj2->remove_property("enchantment");
      obj2->set_property("enchantment", (ench * -1));
   }
   ids = obj2->query_id();
   if((int)obj2->move(TP) != 0) {
      obj2->move(ETO);
      force_me("emote sets the "+ids[0]+" down.");
   }else{
      obj2->move(TP);
      force_me("emoteat "+TPQN+" hands the "+ids[0]+" to $N.");
   }
}
