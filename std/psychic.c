//psychic.c

#include <std.h>

inherit TOWNSMAN;


object current;
object target;
int oldSpeed;
int flag;

int price = 100;
/*****
string * strippable = ({ });
void init_strippable() {
 int iter = 0;

  for (iter=0;iter<256;iter++) {
    if (iter == 32)
      continue;
    if ((iter > 64) && (iter < 91))
      continue;
    if ((iter > 96) && (iter < 123))
      continue;
    write("init "+iter);
     strippable += ({ sprintf("%c",iter) });
  }


}
***/


void create(){
   ::create();
//   init_strippable();
}

set_price(int p){
   price = p;
}

/*****
string filter_colors(string str) {
  string tmp;
  while (sscanf(str, "%*s%%^%s%%^%*s", tmp) > 2)
    str = replace_string(str, "%^"+tmp+"%^", "");
  return str;
}

string filter_alphabet(string str) {
  int iter=0;
  if (!sizeof(strippable)) {
    for (iter=1;iter<255;iter++) {
      if (iter == 32)
        continue;
      if ((iter > 64) && (iter < 91))
        continue;
      if ((iter > 96) && (iter < 123))
        continue;
      strippable += ({ sprintf("%c",iter) });
    }
  }
  for(iter=0;iter<sizeof(strippable);iter++)
    str=replace_string(str,strippable[iter],"");
  return str;
}
***/

string query_long(string str){
   string longD = ::query_long(str);

   longD += "\n"+QCN+" will give you psychic help if you are willing to pay. Simply ask "+QO+" to speak to whomever you wish.";
   return longD;
}

void catch_say(string str){
   if (strsrch(lower_case(str),"speak to") != -1 || strsrch(lower_case(str),"telepathy to") != -1 || TP == current) {
      call_out("do_interact",1,str,TP);
   }
}

int augmentPrice(object player){
   int cha;
   cha = player->query_stats("charisma");
   switch (cha) {
   case 0..3:      return  price*2;
   case 4..6:      return (price*17)/10;
   case 7..10:     return (price*15)/10;
   case 11..13:    return (price*12)/10;
   case 14..16:    return  price;
   case 17..19:    return (price*4)/5;
   case 20..25:    return  price/2;
   }
}

void do_interact(string str, object player){
   int truePrice;
   string who, stuff;
   object whoO;

//   if ("/daemon/filters_d.c"->PsiBroken() && (!random(1)) ) {
   if (objectp(current) && player != current && objectp(target)) {
      force_me("emote waves you away as "+QS+" concentrates on something else.");
      return;
   }
   truePrice = augmentPrice(player);
   if (!objectp(current)) {
      if (player->query_invis()) {
         force_me("emote gazes off into nowhere, looking for the source of the voice.");
         return;
      }
      // *****************force_me("say I heard: "+str);
      str=(string)"/daemon/filters_d"->filter_colors(str);
      str=(string)"/daemon/filters_d"->filter_alphanumeric(str);
      str=lower_case(str);
      // *****************force_me("say I cleared it to be: "+str);
      if (sscanf(str, "%s speak to %s",stuff, who) != 2) {
         if (sscanf(str, "%s telepathy to %s",stuff, who) != 2) {
            force_me("say Please ask something like \"Please help me speak to Tuco\".");
            return;
         }
      }
      sscanf(who,"%s %s",who,stuff);
      force_me("emote concentrates for a moment, eyes closed.");
      if (!player->query_funds("gold",truePrice)) {
	force_me("say you haven't the money to pay me. For you it will cost "+truePrice+" gold");
	return;
      }
      whoO = find_player(player->realName(who));
      //      write(who); write(identify(whoO)); write(player->realName(who));
      if (!objectp(whoO) || whoO->query_invis()) {
         force_me("say I can't make a connection to that person, or you are not telling me what you know them as.");
         return;
      }
      
      if(whoO == player)
      {
          force_me("say You want to talk to yourself?  You don't need me for that.");
          return;
      }
      
      /*      if (!player->query_funds("gold",truePrice)) {
         force_me("say you haven't the money to pay me. For you it will cost "+truePrice+" gold");
         return;
	 } else { */
/* changed from this so others in the room wouldn't see "you" *Styx*  11/26/03
         force_me("emote seems to force you to hand over "+truePrice+" gold.");
*/
	 tell_room(ETO, QCN+" collects "+truePrice+" gold from "+player->QCN+".", player);
	 tell_object(player, QCN+" collects "+truePrice+" gold from you.");
         player->use_funds("gold",truePrice);
         current = player;
         force_me("say Now you wish to communicate with "+whoO->QCN+". I will relate whatever you say to "+whoO->QO+".");
         force_me("emote concentrates for a moment, then "+QP+" eyes seem to glaze over.");
         target = whoO;
         tell_player(target,QCN+" has established a mental connection with you.\n");
         
         set_property("allowed tell",({target->query_name()}));
         target->set_property("allowed tell", ({query_name()}));
	 target->set("reply",query_name());
	 if (!target->query_disguised() || !wizardp(target))
	   set("reply",target->getParsableName());
	 else
	   set("reply",target->query_vis_name());
	 set("reply object",target);
	 target->set("reply object",TO);
         flag = 1;
         force_me("reply "+current->QCN+" has hired me to speak to you through these methods. You must use \"reply\" to speak to me.");
         call_out("end_this",random(30)+60);
         ::set_speed(0);
         return;
   } else {
     if (!objectp(target)) {
	force_me("say It would appear that my mental connection has ended.");
         target = 0;
         current = 0;
         return;
      }
      if (player = current) {
	flag = 1;
	force_me("reply "+str);
	return;
      }
   }

}

void set_speed(int s){
   ::set_speed(s);
   oldSpeed = s;
}

void receive_message(string cl, string msg) {
   ::receive_message(cl,msg);
   if (cl == "reply" && !flag) {
      force_me("say "+msg);
   }
   flag = 0;
}

void end_this(){
  string * array;
   if (objectp(target)) {
      tell_object(target,"Your mental connection has lapsed.");
    array = copy((string *)target->query_property("allowed tell"));
    array -= ({ TO->query_true_name() });
      target->remove_property("allowed tell");
    target->set_property("allowed tell",array);
      target = 0;
   }
   force_me("say I have lost the connection, our business is at an end.");
   remove_property("allowed tell");
   set_speed(oldSpeed);
   current = 0;
}

string getNameAsSeen(object ob) { return TO->query_name(); }
string getParsableName() { return capitalize(TO->query_name()); }
int is_npc_psychic() { return 1;}
