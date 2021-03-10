//inherit for an "identifier" mob that will id or detect magic
//important code for this mob - you will need to set_id_uses();
//and set_detect_uses();, which will set the number of identify
//and detect magic spells the mob has, respectively
//You may also set_price() if you wish.  Price is altered based
//on the player's level and charisma.  Identify prices are set
//up to be 5 times the price of detect, but you can change this
//by doing set_highmod() on your particular mob if you want.
//The base code as it is will make characters level 10 and under
//pay 70 gold for detect and 350 gold for identify.  Higher
//level characters will be charged much, much more.  With the
//current numbers in place, a level 20 would be charged 2800 for
//a detect magic and 8400 for an identify.
//coded by ~Circe~ 6/12/05

//Adding the ability for identifiers to also use study to reveal lore
//For now, the study price is the same as the detect price
//~Circe~ 7/25/13

#include <std.h>
inherit NPC;

#define LOG "player/identifier_npc"
object current;
object *failedStuff;
//failedStuff defined here and initiated in create because
//local variables don't exist after the function is done
int id_uses, detect_uses;
int price = 35;
int newprice,truePrice;
int oldSpeed;
string myenchant;
int highmod = 12;

void create(){
   ::create();
   set_property("no steal",1);
   set_property("no animate",1);
   failedStuff = ({});
}

void init(){
   ::init();
   add_action("ask_em","ask");
}

set_price(int p){
   price = p;
}

void set_speed(int s){
   ::set_speed(s);
   oldSpeed = s;
}

string query_long(string str){
   string longD = ::query_long(str);
   longD += "\n"+QCN+" will identify magical auras on items if you are "+
      "willing to pay. Simply say for "+QO+" to <detect this [item]> or "+
      "<identify this [item]> you carry.  Alternatively, you could ask "+QS+" "
      "to <study this [item]> to learn the lore on the particular object.  "
      "%^BOLD%^You need to make sure the item in "+
      "question is the first such item in your inventory and use the "+
      "syntax listed above, even if it comes out 'identify this boots'"+
      ".\n%^BOLD%^%^RED%^You may also "+
      "type <ask detect>, <ask identify>, or <ask study> to see what prices "+QS+" "+
      "would charge you.";
   return longD;
}

void catch_say(string str){
   if(strsrch(lower_case(str),"identify") != -1 || strsrch(lower_case(str),"detect") != -1 || strsrch(lower_case(str),"study") != -1) {
      call_out("do_interact",1,str,TP);
   }
}

int augmentPrice(object player){
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
   default: return newprice;
   }
}

int get_detect_price(object player){
   int mylevel = player->query_highest_level();
   if(mylevel < 11){
      mylevel = 2;
      newprice = (mylevel*price);
   }else{
      newprice = (mylevel*price*highmod)/3;
   }
   truePrice = augmentPrice(player);
   return truePrice;
}

int get_id_price(object player){
   int mylevel = player->query_highest_level();
   if(mylevel < 11){
      mylevel = 2;
      newprice = (mylevel*price*5);
   }
   newprice = (mylevel*price*highmod);
   truePrice = augmentPrice(player);
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
   set_speed(oldSpeed);
   return;
}

int query_detect_uses(){
   return detect_uses;
}

void set_detect_uses(int x){
   detect_uses = x;
   return;
}

int query_id_uses(){
   return id_uses;
}

void set_id_uses(int x){
   id_uses = x;
   return;
}

int query_highmod(){
   return highmod;
}

void set_highmod(int x){
   highmod = x;
   return;
}

void do_interact(string str, object player){
   object thing;
   int mylevel, i;
   string junk,which,stuff,morejunk;
   object *ppl;
   if (objectp(current) && player != current) {
      force_me("emote waves you away as "+QS+" concentrates on something else.");
      return;
   }
   if (!objectp(current)) {
      if (player->query_invis()) {
         force_me("emote gazes off into nowhere, looking for the source of the voice.");
         return;
      }
      if (sscanf(str, "%s identify this %s", junk,stuff) != 2) {
         if (sscanf(str, "%s detect this %s", junk,stuff) != 2) {
            if (sscanf(str, "%s study this %s", junk,stuff) != 2) {
            force_me("say Please say something like 'identify this "+
               "dagger', 'detect this cloak', or 'study this shield'.  If you are having "+
               "difficulties, you may wish to not use color or "+
               "punctuation in your speech.");
            return;
            }
         }
      }
      if(strsrch(str,"identify") != -1){
         which = "identify";
      }
      if(strsrch(str,"detect") != -1){
         which = "detect";
      }
      if(strsrch(str,"study") != -1){
         which = "study";
      }
      sscanf(stuff,"%s %s",stuff,morejunk);
      if(which == "detect" && !detect_uses){
         force_me("say I'm sorry, but I cannot perform "+
            "another detect magic spell at the moment.");
         return;
      }
      if(which == "identify" && !id_uses){
         force_me("say I'm sorry, but I cannot perform "+
            "another identify spell at the moment.");
         return;
      }
      force_me("emote considers for a moment.");
      if(which == "detect"){
         truePrice = get_detect_price(player);
      }
      if(which == "study"){
         truePrice = get_detect_price(player);
      }
      if(which == "identify"){
         truePrice = get_id_price(player);
      }
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
            if(which == "identify"){
               force_me("say I have tried to identify that "+stuff+" "+
                  "recently and cannot tell you any more about it.");
               return;
            }
         }
         tell_room(ETO, QCN+" collects some gold from "+player->QCN+".",player);
         tell_object(player, QCN+" collects "+truePrice+" gold from you.");
         player->use_funds("gold",truePrice);
         current = player;
         ::set_speed(0);
         switch(which){
            case "detect": force_me("say Well, then, you wish to know "+
                           "if that "+stuff+" you carry is magical.");
                           tell_room(ETO,"%^CYAN%^"+QCN+" concentrates "+
                           "carefully.");
                           if(!present(current,ETO)) return;
                           if(!present(thing,current)){
                              force_me("say You seem to have lost "+
                                 "the "+stuff+".");
                              return;
                           }
                           myenchant = determine_enchant(thing);
                           force_me("emote studies the object carefully.");
                           force_me("say I detect "+myenchant+" on "+
                           "that "+stuff+".");
                           detect_uses--;
                           call_out("endstuff",1);
                           break;
             case "identify": force_me("say Ahh,  you wish to know what "+
                              "sort of enchantment is on that "+stuff+".");
                              tell_room(ETO,"%^CYAN%^Blinking several "+
                              "times, "+QCN+" chants a short phrase.");
                              tell_room(ETO,"%^BOLD%^%^CYAN%^"+QCN+" "+
                              "touches the "+stuff+" and reveals its "+
                              "magical nature to all.");
// removing this - these NPCs are rare as is. Failing a L1 spell seems overkill. N, 8/12.
/*                              if(!random(7)){
                                 failedStuff += ({thing});
                                 id_uses--;
                                 log_file(LOG,""+TO->QCN+" %^BOLD%^%^RED%^failed to identify %^RESET%^"+
                                 ""+(string)thing->query_short()+" for "+
                                 ""+(string)player->QCN+" at "+ctime(time())+".\n");
                                 failure(stuff);
                                 return;
                              }*/
                              if((int)thing->query_property("enchantment") < 0){
                                 failedStuff += ({thing});
                                 id_uses--;
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
                              id_uses--;
                              call_out("endstuff",1);
                              break;
            case "study": force_me("say I see. You wish to know "+
                           "the lore behind that "+stuff+" you carry.");
                           tell_room(ETO,"%^CYAN%^"+QCN+" concentrates "+
                           "carefully.");
                           if(!present(current,ETO)) return;
                           if(!present(thing,current)){
                              force_me("say You seem to have lost "+
                                 "the "+stuff+".");
                              return;
                           }
                           force_me("emote studies the object carefully.");
                           force_me("say The story behind that "+stuff+" is: "+(string)thing->query_lore()+".");
                           call_out("endstuff",1);
                           break;
             default: tell_room(ETO,"Something seems to be wrong.  Please "+
                      "ask for a wiz or bug report it.");
                      break;
          }
          return;
      }
      force_me("emote waves you away as "+QS+" concentrates on something else.");
      return;
   }
}

void endstuff(){
   force_me("say Your patronage is appreciated.  I trust you'll "+
      "remember my services in the future.");
   set_speed(oldSpeed);
   current = 0;
}

void reset(){
   ::reset();
   if(!detect_uses){
      detect_uses += 2;
   }
   if(!id_uses){
      id_uses += 2;
   }
}

int ask_em(string str){
   int mylevel;
   if(!str){
      tell_object(TP,"You need to <ask detect>, <ask identify>, or <ask study>.");
      return 1;
   }
   if (objectp(current) && TP != current) {
      force_me("emote waves you away as "+QS+" concentrates on something else.");
      return 1;
   }
   if(str == "detect"){
      get_detect_price(TP);
      tell_object(TP,"It would cost "+truePrice+" gold for me to detect "+
         "magic for you.");
   }
   if(str == "study"){
      get_detect_price(TP);
      tell_object(TP,"It would cost "+truePrice+" gold for me to study an object for you.");
   }
   if(str == "identify"){
      get_id_price(TP);
      tell_object(TP,"It would cost "+truePrice+" gold for me to identify "+
         "an item for you.");
   }
   tell_room(ETO,""+TPQCN+" seems to be discussing something with the mage.",TP);
   return 1;
}
