#include <std.h>
#include <daemons.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

int step1;
int step2;
int step3;
string *asked;

create() {
   ::create();
   set_name("the translucent spirit");
   set_short("translucent spirit");
   set_id(({ "spirit","ghost","translucent spirit","sionne","Sionne"}));
   set_long("%^BLUE%^What seems at first nothing more than a whisp of fog, is actually a returned "
"spirit.  The spirit's transparent features resemble a female human, with long, straight hair cascading "
"over the back of the heavy-plated armor that encase her body.  Her hands are clasped before her, and "
"you can see a delicate bracelet around one of her wrists.  At her side is a holster, holding a long "
"sceptre.  Her face carries a look of deep sadness within the dark pools of her eyes, which follow your "
"every move.");
   set_race("spirit");
   set_body_type("human");
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
   set_max_hp(2000);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_attack_limbs( ({"left hand"}) );
   set_attacks_num(0);
   set_base_damage_type("slashing");
   set_damage(1,2);
   //set_mob_magic_resistance("average");
   set_emotes(1, ({"%^BLUE%^The spirit floats slowly through the air.",
"%^BLACK%^%^BOLD%^The spirit's mournful gaze passes over you.",
"%^ORANGE%^The spirit flickers and nearly disappears from view.",
"%^CYAN%^The spirit swirls around you, and you nearly lose sight of it.",
"%^MAGENTA%^The spirit's eyes glow with despair.",
"%^RED%^The spirit moans mournfully."}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech whisper");
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
   asked = SAVE_D->query_array("NBsionnequest_asked");
   if(!msg || !objectp(who)) return;
   if(who->query_quests()) {
     if(member_array("Sionne's final rest",who->query_quests()) != -1) {
       if(!random(5)) { force_me("say %^CYAN%^%^BOLD%^Thank you for your help, now the balance is restored, and "
"my friends can rest."); }
       tell_room(ETO,"The spirit smiles softly.\n");
       return;
     }
   }
   if(member_array(name, asked) != -1) {
     if(!random(3)) { force_me("say %^CYAN%^%^BOLD%^Do you have word of Archemond's passing?"); }
     if(!random(3)) { force_me("say %^CYAN%^%^BOLD%^Please, if you have the amulet, give it to me that I "
"might end its evil once and for all."); }
     return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 || strsrch(msg,"reeting") != -1 || strsrch(msg,"eya") != -1) && !step1){
      tell_room(ETO,"The spirit turns her sorrowful gaze upon "+who->QCN+".\n",who);
      tell_object(who,"The spirit turns her sorrowful gaze upon you.\n");
      force_me("say %^CYAN%^%^BOLD%^An adventurer... We were just like you, once.");
      tell_room(ETO,"A glitter of hope enters the spirit's eyes.\n");
      force_me("say %^CYAN%^%^BOLD%^Perhaps you could help me?");
      step1 = 1;
      return;
   }
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 || strsrch(msg,"how") != -1) && step1 && !step2) {
      force_me("say %^CYAN%^%^BOLD%^I am, or was once, a priestess of Lysara's fold.  Sionne of the "
"Ashes I was called, though that was long ago.");
      tell_room(ETO,"A whistful expression comes over the spirit.\n");
      force_me("say %^CYAN%^%^BOLD%^So many decades ago, we travelled... seven of us, as unlikely a "
"group as you're ever to meet.  Myself and my beloved, Lachlan Crenulon, a magus of Mystra's calling.");
      tell_room(ETO,"The spirit sighs softly.\n");
      force_me("say %^CYAN%^%^BOLD%^And with us also, the bardess of the Moonmaiden, Rhiannon Eiryanah, "
"once known across the realms but now lost from history's pages.  Beside her walked her two closest "
"friends: the elf Rhykavain, ranger of the Oak Father, though even his god no longer hears his pleas... "
"and the rogue Eylean, one of Akadi's own and as fickle as the goddess herself.");
      tell_room(ETO,"The spirit smiles as she remembers.\n");
      force_me("say %^CYAN%^%^BOLD%^and the little ones too, Kaali and Gelthek.  Gelthek, warrior of "
"Tempus, as gruff as a dwarf could ever be, and as unmoving as a stone.  And his exact contrast, the "
"halfling Kaali, a rogue that left her life in the hands of Lady Luck.");
      tell_room(ETO,"The spirit pauses.\n");
      force_me("say %^CYAN%^%^BOLD%^but I stray.  Do you still wish to know the task I would ask of "
"you?");
      step2 = 1;
      return;
   }
   if((strsrch(msg,"task") != -1 || strsrch(msg,"help") != -1 || strsrch(msg,"course") != -1 || strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1) && step2 && !step3) {
     tell_room(ETO,"The spirit nods slowly.\n");
     force_me("say %^CYAN%^%^BOLD%^a cult that called themselves 'the Faithful of the True Voice' had "
"been established within this very building.  Though they seemed harmless at first, eventually their "
"leader, a magus by the name of Archemond, demanded that the nearby village send several of their people "
"to be sacrificed.  My friends were in the village at the time, taking rest from our travels, and we "
"offered to deal with the cult's evil once and for all.");
     tell_room(ETO,"The spirit's expression darkens.\n");
     force_me("say %^CYAN%^%^BOLD%^for a long time, my Lachlan watched them, learning about them through "
"the powers his magecraft granted him.  Upon the day he set out, he placed a binding upon this building, "
"preventing them from ever leaving again.  Then, we set out...");
     tell_room(ETO,"The spirit sighs, shaking her head sadly.\n");
     force_me("say %^CYAN%^%^BOLD%^not one of us returned that day.  The true wickedness of the cult lay "
"within the amulet worn by the cult-leader, Archemond: it allowed him to drain the life from anyone "
"nearby.  He took the lives of every single follower of his, forcing their spirits to walk the halls "
"here, trapped in undeath.  And then... with the power he gained from this, he gave me and my friends "
"the same fate, forcing them to be his eternal guardians.");
     tell_room(ETO,"The spirit pauses before continuing.\n");
     force_me("say %^CYAN%^%^BOLD%^for my faith to my god, Lysara freed me from my binding within the "
"building, but in return, I cannot pass on to his realms until my friends are also freed.  Like this, I "
"haven't the power I need to free them, and so I must ask help from the living.");
     tell_room(ETO,"The spirit looks up again.\n");
     force_me("say %^CYAN%^%^BOLD%^would you help me in this task?");
     step3 = 1;
     return;
   }
   if((strsrch(msg,"task") != -1 || strsrch(msg,"help") != -1 || strsrch(msg,"yea") != -1 || strsrch(msg,"Yea") != -1 || strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1) && step3) {
     if(member_array(name, asked) == -1) { SAVE_D->set_value("NBsionnequest_asked", name); }
     tell_room(ETO,"The spirit looks over to the old building.\n");
     force_me("say %^CYAN%^%^BOLD%^within the walls of this building the leader still resides, preserved "
"by whatever unnatural force is held in the amulet.  He will not part with it unless his spirit already "
"walks Lysara's halls.");
     tell_room(ETO,"The spirit closes her dark eyes.\n");
     force_me("say %^CYAN%^%^BOLD%^he has wards upon the doors, that you will need sigils to break.  You "
"will need to find them, in order to reach Archemond himself.");
     force_me("say %^CYAN%^%^BOLD%^his soul is long due to pass from this realm, as are those of my "
"friends, and my own.  Bring me the amulet, and I will give you what blessings I have left, before I "
"leave this plane.");
     tell_room(ETO,"The spirit looks back to "+who->QCN+".\n",who);
     tell_object(who,"The spirit looks back to you.\n");
     force_me("say %^CYAN%^%^BOLD%^my hopes go with you, "+who->QCN+"");
     return;
  }
}

void receive_given_item(object obj){
   string name;
   name = TPQN;
   if(!objectp(obj)) return;
   if((string)obj->query_name() != "amulet of the true voice") {
      force_me("say %^CYAN%^%^BOLD%^My thanks, but I have no need of this.");
      force_me("give "+obj->query_name()+" to "+name+"");
      return;
   }
   if(member_array("Sionne's final rest",TP->query_quests()) != -1){
      force_me("say %^CYAN%^%^BOLD%^my thanks, for bringing me this item of evil, no more will it remain "
"on this plane.");
      tell_room(ETO,"The spirit closes her translucent hands around the amulet and speaks a few words of "
"prayer.\n\nThe amulet shimmers and disappears!\n");
      obj->remove();
      return;
   }
   tell_room(ETO,"The spirit looks over the amulet, a soft smile spreading across her face.\n");
   force_me("say %^CYAN%^%^BOLD%^finally, we can move on from this place and take our true rest.");
    if (!asked) asked= ({});
   if(member_array(TPQN, asked) != -1) { SAVE_D->remove_name_from_array("NBsionnequest_asked", TPQN); }
   tell_room(ETO,"The spirit closes her translucent hands around the amulet and speaks a few words of "
"prayer.\n\nThe amulet shimmers and disappears, as a bright light flashes from the glass windows "
"of the building behind you.\n");
   obj->remove();
   force_me("say %^CYAN%^%^BOLD%^my thanks, traveller, for ending the imbalance here.  It's not much in "
"repayment for what you've done, but I will give you what blessings I can.");
   tell_room(ETO,"The spirit moves forward through the air, placing her transparent hands upon "
+TP->QCN+"'s head, and speaking a prayer over "+TP->QO+".\n",TP);
   tell_object(TP,"The spirit moves forward through the air, placing her transparent hands upon your "
"head and speaking a prayer over you.\n\nYou feel newfound strength coursing through your veins!\n");
   tell_room(ETO,"The spirit drifts back again.\n");
   force_me("say %^CYAN%^%^BOLD%^may death only find you when it is your time, and may Lysara's own "
"hand guide you safely from this life to the next.");
   call_out("reward",1);
}

void reward(){
   object *questors;
   int i,j;
   questors = ({});
   questors = filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
   j= sizeof(questors);
   if(!j) return;
   for(i=0;i<j;i++){
      if(!objectp(questors[i])) { continue; }
      if(member_array("Sionne's final rest",questors[i]->query_quests()) == -1 && member_array("Killed Archemond",questors[i]->query_mini_quests()) != -1){
         questors[i]->set_quest("Sionne's final rest");
         questors[i]->fix_exp(2000000);
         questors[i]->remove_mini_quest("Killed Archemond");
		 tell_object(questors[i],"%^WHITE%^%^BOLD%^You have finished the quest, 'Sionne's final rest'!\n");
	  }
   }
   tell_room(ETO,"The spirit smiles softly, her body becoming more and more translucent, until she "
"finally disappears.\n");
   TO->remove();
   return;
 }


void heart_beat() {
   ::heart_beat();
   if(sizeof(TO->query_attackers()) > 0) {
     tell_room(ETO,"%^WHITE%^%^BOLD%^The spirit looks at you with deep sadness, and disappears!");
     TO->remove();
   }
   return;
}
