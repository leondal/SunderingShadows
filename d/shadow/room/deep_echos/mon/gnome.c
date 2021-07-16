// Gnome that needs his machine fixed
#include <std.h>
#include <daemons.h>
#include "../deep_echo.h"
inherit "/std/monster";
int hasdrill, hascog;


create() {
  ::create();
  set_name("gnome");
  set_id(({"gnome","monster","jumpsuit gnome"}));
  set_gender("female");
  set_race("gnome");
  set_short("gnome wearing a jumpsuit");
  set_long("This gnome is wearing a thick"+
  " jumpsuit.  She wear a helmet with a light"+
  " attached to it and brown leather gloves."+
  "  She has many tools attached to her belt.");
  set_body_type("human");
  set_alignment(6);
  set_hd(6,8);
  set_stats("strength",8);
  set("aggressive",0);
  set_stats("intelligence", 16);
  set_stats("wisdom", 6);
  set_stats("charisma",10);
  set_stats("dexterity",10);
  set_size(1);
  set_property("swarm",0);
  set_wielding_limbs(({"right hand","left hand"}));
  set_overall_ac(12);
  set_hp(random(50)+10);
  set_max_level(3);
  set_emotes(2,({
   "Gnome looks frustrated.",
   "Gnome bangs at the machine with a hammer.",
   "Gnome looks around the areas, trying to find something.",
   "%^MAGENTA%^Gnome says:%^RESET%^ I need to fix this, stupid ogres took the parts.",
   "%^MAGENTA%^Gnome says:%^RESET%^ Where did that drill go?",
   "Gnome pours some water into a tank of the machine.",
   }),0);
}
// give 2 items for exit
void receive_given_item(object obj){
   string name, item;
   object *ppl;
   int i;
   if(!objectp(TP)) return;
   if(!ETO) return;
   name = TPQN;
   if(!objectp(obj)) return;
   item = obj->query_name();
   if((string)obj->query_name() != "%^BOLD%^%^BLACK%^giant drill%^RESET%^"
     && (string)obj->query_name() != "mithril cog") {
      force_me("say Ummm thanks, but this won't help.");
	  force_me("give "+obj->query_name()+" to "+name+"");
      return;
	  }

   switch (item){
     case "mithril cog" :
	   hascog = 1;
	   if(hasdrill != 1){
	     force_me("say hmm, missing the drill");
		 return;}
	 break;
	 
	 case "%^BOLD%^%^BLACK%^giant drill%^RESET%^":
	   hasdrill = 1;
	   if(hascog != 1){
	     force_me("say darn, still need that cog.");
		 return;}
	 break;}
	 
   tell_room(ETO,"The gnome takes the drill"+
   " and uses some tools to attach it back to the machine. "+
  "\n\n She pulls a lever and it starts moving again.");
   
   force_me("say thank ya much for the help, now we can get going again.");
  
   force_me("emote hops up on the machine puts some goggles on.  "+  
   "She flips a switch and steam starts billowing out of the machine.");
   TP->set_mini_quest("gnomely helper",1000000,"helped a gnome in echo mountain");
   tell_room(ETO,"The machine starts drilling, "+
   "heading off into the rock, leaving an impassable"+
   " pile of rocks as the exit falls back down.\n");

   ETO->poof();
   new(OBJ"beauty")->move(TO);
   force_me("give spear to "+name);
   force_me("say take that, some crazy fancy pants"+
   " had that he got himself"
   " killed down here though so you can keep it.");
   tell_object(TP,"You have finished the quest, %^CYAN%^'Gnomely Helper'!\n");
     
  ppl=filter_array(all_living(ETO),"is_non_immortal_player",FILTERS_D);
  
  tell_room(ETO, 
    "%^ORANGE%^You hop on the machine and are taken up,"+
	" leaving crumbling rocks in your wake.");
  for (i = 0; i < sizeof (ppl); i++){  //move out
	 ppl[i]->move("/d/shadow/room/mountain/road5"); 
   }
   TO->move("/d/shadowgate/void");
   TO->remove();
   obj->remove();
   return;
}
void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
   set_spoken("wizish");
   if(!msg || !objectp(who)) return;
    force_me("emote turns from the machine to look at you.");
    force_me("say Hi! Please help me, an ogre"+
	" took my drill, and a cog stuck down here."
	" I'll get you out when this thing is fixed.");
	force_me("emote asks pleadingly.");
     return;
}

