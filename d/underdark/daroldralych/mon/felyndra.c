#include <std.h>
#include "../defs.h"
inherit "/std/psychic";
#define LOG "identifier_usage"

object *failedStuff;
int price, newprice, truePrice;
string myenchant;

void create() {
   ::create();
   set_name("felyndra");
   set_id(({"felyndra","arcanist","psychic","Felyndra","drow","seeress","master seeress","identifier"}));
   set_short("%^RESET%^%^MAGENTA%^Felyndra Ghorred'Malac, master seeress%^RESET%^");
   set_long("%^MAGENTA%^Felyndra is as much a picture of artful finery as her surrounds.  Her %^GREEN%^wi"
"%^ORANGE%^l%^GREEN%^lo%^ORANGE%^w%^GREEN%^y %^MAGENTA%^figure is draped in a series of %^CYAN%^la"
"%^MAGENTA%^ye%^BOLD%^%^MAGENTA%^r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d s%^MAGENTA%^i%^CYAN%^lk%^BOLD%^%^CYAN%^s"
"%^RESET%^%^MAGENTA%^, which become startlingly revealing when she moves.  Delicate %^BOLD%^%^WHITE%^je"
"%^YELLOW%^w%^BOLD%^%^WHITE%^el%^BOLD%^%^MAGENTA%^r%^BOLD%^%^WHITE%^y %^RESET%^%^MAGENTA%^bands her fingers"
", wrists and ankles, while a series of tiny beads bind her hair back in an intricate netting.  Her %^RED%^sc"
"%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^r%^RESET%^%^RED%^let %^MAGENTA%^eyes gleam with a startling intensity, as "
"if seeing right through her surrounds.  One of the many rings on her fingers bears a house insignia.%^RESET%^");
   set_alignment(6);
   set_race("drow");
   set_class("mage");
   set_class("fighter");
   set_body_type("human");
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("female");
   set_property("no bow",1);
   price = 140;
   force_me("speak wizish");
   force_me("speech convey in a soothing tone");
   failedStuff = ({});
}

string query_long(string str){
   string longD = "%^MAGENTA%^Felyndra is as much a picture of artful finery as her surrounds.  Her %^GREEN%^wi"
"%^ORANGE%^l%^GREEN%^lo%^ORANGE%^w%^GREEN%^y %^MAGENTA%^figure is draped in a series of %^CYAN%^la"
"%^MAGENTA%^ye%^BOLD%^%^MAGENTA%^r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d s%^MAGENTA%^i%^CYAN%^lk%^BOLD%^%^CYAN%^s"
"%^RESET%^%^MAGENTA%^, which become startlingly revealing when she moves.  Delicate %^BOLD%^%^WHITE%^je"
"%^YELLOW%^w%^BOLD%^%^WHITE%^el%^BOLD%^%^MAGENTA%^r%^BOLD%^%^WHITE%^y %^RESET%^%^MAGENTA%^bands her fingers"
", wrists and ankles, while a series of tiny beads bind her hair back in an intricate netting.  Her %^RED%^sc"
"%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^r%^RESET%^%^RED%^let %^MAGENTA%^eyes gleam with a startling intensity, as "
"if seeing right through her surrounds.  One of the many rings on her fingers bears a house insignia.%^RESET%^";
   longD += "\n\nFelyndra can provide arcane assistance if you are willing to pay.  You can say <speak to "
"whomever> to contact another adventurer.  You can also say <identify this [item]> to reveal information on "
"items that you carry.  Finally, you may type <ask price> to see what she would charge you for her services.";
   return longD;
}

void init(){
   ::init();
   add_action("ask_em","ask");
}

void catch_say(string str){
   if (objectp(current) && TP != current) {
      force_me("emote waves you away as she concentrates on something else.");
      return;
   }
   if(strsrch(lower_case(str),"identify") != -1) {
     call_out("do_id",1,str,TP);
     return;
   }
   if(strsrch(lower_case(str),"speak to") != -1 || strsrch(lower_case(str),"telepathy to") != -1) call_out("do_interact",1,str,TP);
}

int augmentPriceID(object player){
   int cha;
   cha = player->query_stats("charisma");
   switch (cha) {
   case 0..3:      return  newprice*2;
   case 4..6:      return (newprice*17)/10;
   case 7..10:     return (newprice*15)/10;
   case 11..13:    return (newprice*12)/10;
   case 14..16:    return  newprice;
   case 17..19:    return (newprice*4)/5;
   case 20..25:    return  newprice/2;
   }
}

int get_detect_price(object player){
   int mylevel = player->query_highest_level();
   newprice = (mylevel*price);
   truePrice = augmentPriceID(player);
   return truePrice;
}

void determine_enchant(object thing){
   int num = thing->query_property("enchantment");
   switch(num){
      case -1: case 1:  myenchant = "a faint blue glow";
               break;
      case -2: case 2:  myenchant = "a blue glow";
               break;
      case -3: case 3:  myenchant = "a bright blue glow";
               break;
      case -4: case -5: case -6: case -7: case -8: case -9: case -10:
      case 4: case 5: case 6: case 7: case 8: case 9: case 10:  
                myenchant = "a very bright blue glow";
                break;
      default: myenchant = "no magical aura";
               break;
   }
   return myenchant;
}

void failure(string stuff){
   force_me("emote frowns and blinks a few times.");
   force_me("say There is something wrong with the aura around "+
      "that "+stuff+".  I cannot tell you more about it.");
   current = 0;
   return;
}

void do_id(string str, object player){
   object thing, *ppl;
   int mylevel, i;
   string junk,stuff,morejunk;
   if (objectp(current) && player != current) {
      force_me("emote waves you away as she concentrates on something else.");
      return;
   }
   if (!objectp(current)) {
      if (player->query_invis()) {
         force_me("emote gazes off into nowhere, looking for the source of the voice.");
         return;
      }
      if (sscanf(str, "%s identify this %s", junk,stuff) != 2) {
          force_me("say Please say something like 'identify this "+
             "dagger' or 'speak to bob'.  If you are having "+
             "difficulties, you may wish to not use color or "+
             "punctuation in your speech.");
          return;
      }
      sscanf(stuff,"%s %s",stuff,morejunk);
      force_me("emote considers for a moment.");
      truePrice = get_detect_price(player);
      if (!player->query_funds("gold",truePrice)) {
	   force_me("say You don't have enough to pay me.  It will cost you "+
            ""+truePrice+" gold.");
	   return;
      }else{
         if(!thing = present(stuff,player)){
            force_me("say You don't seem to have any "+stuff+".");
            return;
         }
         if(member_array(thing,failedStuff) != -1){
            force_me("say I have tried to identify that "+stuff+" "+
               "recently and cannot tell you any more about it.");
            return;
         }
         tell_room(ETO, QCN+" collects some gold from "+player->QCN+".",player);
         tell_object(player, QCN+" collects "+truePrice+" gold from you.");
         player->use_funds("gold",truePrice);
         current = player;
         force_me("say Ahh,  you wish to know what "+
                              "sort of enchantment is on that "+stuff+".");
                              tell_room(ETO,"%^CYAN%^Blinking several "+
                              "times, "+QCN+" chants a short phrase.");
                              tell_room(ETO,"%^BOLD%^%^CYAN%^"+QCN+" "+
                              "touches the "+stuff+" and reveals its "+
                              "magical nature to all.");
                              if((int)thing->query_property("enchantment") < 0){
                                 failedStuff += ({thing});
                                 log_file(LOG,""+TO->QCN+" %^BOLD%^%^RED%^failed to identify %^RESET%^"+
                                 ""+(string)thing->query_short()+" for "+
                                 ""+(string)player->QCN+" at "+ctime(time())+" "+
                                 "(%^BOLD%^%^RED%^CURSE%^RESET%^).\n");
                                 failure(stuff);
                                 return;
                              }
                              ppl = all_inventory(ETO);
                              if(!present(current,ETO)) return;
                              if(!present(thing,current)){
                                 force_me("say You seem to have lost "+
                                    "the "+stuff+".");
                                 return;
                              }
                              for(i=0;i<sizeof(ppl);i++){
                                 if(interactive(ppl[i])){
                                    thing->add_identified(ppl[i]->query_name());
                                 }
                              }
                              log_file(LOG,""+(string)player->QCN+" had a "+
                              ""+(string)thing->query_short()+" %^BOLD%^%^MAGENTA%^identified %^RESET%^by "+
                              ""+TO->QCN+" at "+ctime(time())+".\n");
                              call_out("endstuff",1);
          return;
      }
      force_me("emote waves you away as she concentrates on something else.");
      return;
   }
}

void endstuff(){
   force_me("say Your patronage is appreciated.  I trust you'll "+
      "remember my services in the future.");
   current = 0;
}

int ask_em(string str){
   int myprice, myprice2;
   if(!str){
      tell_object(TP,"You need to <ask price>");
      return 1;
   }
   if (objectp(current) && TP != current) {
      force_me("emote waves you away as she concentrates on something else.");
      return 1;
   }
   if(str != "price"){
      tell_object(TP,"What are you asking for?");
      return 1;
   }
   myprice = get_detect_price(TP);
   myprice2 = augmentPrice(TP);
   tell_object(TP,"It would cost "+myprice+" gold for me to identify an item "+
         "for you, or "+myprice2+" to contact someone.");
   log_file(LOG,""+(string)TPQCN+" asked "+TO->QCN+" "+
         "for an %^CYAN%^identify %^RESET%^price at "+ctime(time())+".\n");
   tell_room(ETO,""+TPQCN+" seems to be discussing something with Felyndra.",TP);
   return 1;
}