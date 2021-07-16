#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

int step1;
int step2;
int step3;
string *asked;

void create() {
   ::create();
   set_name("Shannon Doren");
   set_short("%^RESET%^%^MAGENTA%^Shannon Doren, %^RESET%^%^CYAN%^La"+
"%^RESET%^%^BOLD%^%^CYAN%^d%^RESET%^%^CYAN%^y of Myst%^RESET%^%^BOLD%^"+
"%^CYAN%^e%^RESET%^%^CYAN%^ry%^RESET%^");
   set_id(({ "Shannon Doren","Shannon Doren, Lady of Mystery","Shannon","shannon","shannon doren"}));
   set_long("%^RESET%^%^ORANGE%^This woman looks to be in her twenties, but her face is marred "+
"with obvious %^RESET%^%^BOLD%^%^BLACK%^anguish %^RESET%^%^ORANGE%^and %^RESET%^%^BOLD%^%^BLACK%^"+
"worry%^RESET%^%^ORANGE%^. Her %^RESET%^%^YELLOW%^lo%^RESET%^%^BOLD%^%^WHITE%^n%^RESET%^%^YELLOW%^"+
"g blond h%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^YELLOW%^ir %^RESET%^%^ORANGE%^falls over her "+
"shoulders and frames a thin face. Her eyes are the color of %^RESET%^%^GREEN%^emer%^RESET%^%^BOLD%^"+
"%^GREEN%^a%^RESET%^%^GREEN%^ld%^RESET%^%^ORANGE%^, shining with great power. She is dressed in a "+
"%^RESET%^%^BLUE%^lo%^RESET%^%^BOLD%^%^BLUE%^n%^RESET%^%^BLUE%^g blue %^RESET%^%^BOLD%^%^BLUE%^r%^RESET%^"+
"%^BLUE%^obe %^RESET%^%^ORANGE%^trimmed with %^RESET%^%^BOLD%^%^WHITE%^white%^RESET%^%^ORANGE%^. In "+
"one hand she clenches a %^RESET%^%^WHITE%^worn book%^RESET%^%^ORANGE%^, the other is balled into a "+
"fist. She looks up at the floating fortress with ill hidden hatred. %^RESET%^.");
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
   set_gender("female");
   set_size(2);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_attack_limbs( ({"left hand"}) );
   set_attacks_num(3);
   set_base_damage_type("slashing");
   set_damage(1,2);
   set_mob_magic_resistance("average");
   set_emotes(1, ({".",
"%^RESET%^%^CYAN%^Shannon Looks up at the floating fortress with a sneer%^RESET%^",
"%^RESET%^%^MAGENTA%^Shannon mutters something about duty...%^RESET%^",}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech speak in an even tone");
}

void reset() {
   ::reset();
   step1 = 0;
   step2 = 0;
   step3 = 0;
}

void catch_say(string msg){
   call_out("reply_fun",1,msg,TP);
}

void reply_fun(string msg, object who){
   string name;
   name = who->query_name();
   asked = SAVE_D->query_array("gith_quest_asked");
   if(!msg || !objectp(who)) return;
   if(who->query_quests()) {
     if(member_array("Isolated the Githyanki",who->query_quests()) != -1) {
       force_me("say Thank you for freeing my husband.");
       tell_room(ETO,"The woman smiles.\n");
       return;
     }
   }
   if(member_array(name, asked) != -1) {
     if(!random(3)) { force_me("say Please, have you seen my husband?"); }
     if(!random(3)) { force_me("say It has been so long, I hope he is alright."); }
     return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
strsrch(msg,"reeting") != -1 || strsrch(msg,"eya") != -1) && !step1){
      tell_room(EETO,"The woman looks over "+who->QCN+".\n",ETO);
      tell_object(ETO,"The woman looks upon you.\n");
      force_me("say Adventurati, this far in the desert?");
      tell_room(EETO,"The woman looks up at the fortress floating in the air.\n");
      force_me("say Please would you help me?");
      step1 = 1;
      return;
   }
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 ||
strsrch(msg,"Yes") != -1 || strsrch(msg,"yea") != -1 || strsrch(msg,"Yea")
!= -1 || strsrch(msg,"how") != -1) && step1 && !step2) {
      force_me("say This fortress appeared several weeks ago, a god-isle from "+
"the astral plane.");
      tell_room(EETO,"The woman looks up at the floating fortress with ill-hidd"+
"en hatred.\n");
      force_me("say We sent a delegation to negotiate with them, there is so much"+
" power in that fortress.");
      tell_room(ETO,"She closes her eyes.\n");
      force_me("say They sent my husband. Little did we know that the fortress "+
"is a Githyanki stronghold. A nest of Tiamat's killers. They have him captive and"+
" bound. We cannot rescue him until he is freed, but we can't get in to do it. ");
      tell_room(ETO,"She opens her eyes and looks pleadingly.\n");
      force_me("say Will you help us rescue him?");
      tell_room(ETO,"The woman looks back up at the fortress.\n");
      step2 = 1;
      return;
   }
   if((strsrch(msg,"task") != -1 || strsrch(msg,"help") != -1 ||
strsrch(msg,"course") != -1 || strsrch(msg,"yes") != -1 ||
strsrch(msg,"Yes") != -1 || strsrch(msg,"yea") != -1 || strsrch(msg,"Yea")
!= -1) && step2 && !step3) {
     tell_room(ETO,"The woman nods.\n");
     force_me("say I have researched a spell, a way I can forcibly pull"+
" him out of the fortress.");
     tell_room(ETO,"Her grip tightens on her book, and she nods.\n");
     force_me("say I can do it. But I need an item he has held recently,"+
" and nothing in our home has worked.");
     tell_room(ETO,"The woman glances at the ring on her left hand.\n");
     force_me("say When you find him, have him give you his wedding ring,"+
" that will work.");
     step3 = 1;
     return;
   }
   if((strsrch(msg,"task") != -1 || strsrch(msg,"help") != -1 ||
strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 || strsrch(msg,"yes")
!= -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1) && step3) {
     if(member_array(name, asked) == -1) {
SAVE_D->set_value("gith_quest_asked", name); }
     tell_room(ETO,"The woman looks up at the fortress.\n");
     force_me("say If you step on the rune I have drawn on the ground here."+
" When you step on it, it will fly you to the fortress.");
     tell_room(ETO,"The woman smirks.\n");
     force_me("say Even though we have not been successful in rescuing him, "+
"we were able to punch a hole in the side of the fortress.");
     force_me("say Please, save my husband.");
     return;
  }
}

void receive_given_item(object obj){
   string name;
   name = TPQN;
   asked =SAVE_D->query_array("gith_quest_asked");
   if(!objectp(obj)) return;
   if((string)obj->query_name() != "doren wedding ring") {
      force_me("say This isn't my husband's ring.");
      force_me("give "+obj->query_name()+" to "+name+"");
      return;
   }
   if(member_array("Isolated the Githyanki",TP->query_quests()) != -1){
      force_me("say How did you get this? My husband is home safe...");
      tell_room(ETO,"The woman looks up at the fortress and frowns.\n");
      force_me("say I hope...");
      obj->remove();
      return;
   }
   tell_room(ETO,"The woman takes the ring and looks it over.\n");
   force_me("say Yes, this is his ring, it will work perfectly!");
   if(member_array(TPQN, asked) != -1) {
SAVE_D->remove_name_from_array("gith_quest_asked", TPQN); }
   tell_room(ETO,"T%^RESET%^%^MAGENTA%^he woman starts to chant softly, the whole area is filled with power, "+
"you hear a thunderous crash and the fortress seems to tilt for a moment.%^RESET%^\n");
   obj->remove();
   force_me("say I have broken through their wards and taken him. He is once again at home."+
" I give you my thanks. Though, now that they are stuck here, I wonder what the Githyanki "+
"will do?");
   TP->set_quest("Isolated the Githyanki");
   TP->fix_exp(2000000,TP);
   tell_room(ETO,"%^%^RED%^The woman closes her eyes and casts a spell of recall.%^RESET%^\n");
   tell_object(TP,"You have finished the quest, 'Isolated the Githyanki'!\n");
   TO->remove();
   return;
}