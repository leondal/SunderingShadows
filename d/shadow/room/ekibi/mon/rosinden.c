//Rosinden, member of the Gnomish Explorers' League
//Circe 3/13/05
#include <std.h>
#include <daemons.h>
#include "../ekibi.h"

inherit VENDOR;

int step1;
int step2;

void create(){
   ::create();
   set_name("rosinden");
   set_short("Rosinden, member of the Gnomish Explorers' League");
   set_id(({"rosinden","Rosinden","experimenter","explorer"}));
   set_long("Rosinden is a young female gnome with %^ORANGE%^"+
      "woody brown skin %^CYAN%^and %^BOLD%^%^WHITE%^white "+
      "hair %^RESET%^%^CYAN%^kept sensibly short.  Her eye "+
      "color is impossible to tell, as she wears thick, "+
      "%^MAGENTA%^violet-colored goggles%^CYAN%^.  She squints "+
      "constantly, hinting that perhaps the goggles do more "+
      "harm than good.  Her rather large ears bristle with "+
      "%^YELLOW%^earrings %^RESET%^%^CYAN%^ - everything from "+
      "%^BOLD%^%^WHITE%^silver hoops %^RESET%^%^CYAN%^to "+
      "%^BOLD%^%^BLUE%^sapphire studs%^RESET%^%^CYAN%^.  "+
      "Her plump frame is covered in a long %^RESET%^lab "+
      "coat %^CYAN%^made of %^BOLD%^p%^MAGENTA%^a%^RED%^t%^ORANGE%^c"+
      "%^YELLOW%^h%^GREEN%^e%^BLUE%^s %^RESET%^%^CYAN%^of "+
      "all hues.  Her tiny feet are dwarfed in stout "+
      "%^ORANGE%^boots %^CYAN%^clearly meant to protect her "+
      "toes among all the chemicals and equipment.\n\n"+
      "%^GREEN%^Rosinden keeps a few items around she's willing to sell.  "+
      "You can <%^BOLD%^help shop%^RESET%^%^GREEN%^> to see "+
      "how to buy and sell things.  %^BOLD%^If you are in need "+
      "of an extractor, you can <ask rosinden> for one.%^RESET%^"
   );
   set_race("gnome");
   set_gender("female");
   set_items_allowed("misc");
   set_hd(10,4);
   set_max_hp(75+random(50));
   set_hp(query_max_hp());
   set_overall_ac(0);
   set_alignment(5);
   set_class("mage");
   set_class("cleric");
   set_mlevel("mage",10);
   set_mlevel("cleric",10);
   set_level(10);
   set_stats("intelligence",18);
   set_stats("wisdom",18);
   set_stats("charisma",16);
   set_stats("strength",9);
   set_stats("constitution",8);
   set_stats("dexterity",14);
   set_spells(({
      "limb attack",
      "lightning bolt",
      "magic missile",
      "flame strike",
      "scorcher"
	}));
   set_spell_chance(50);
   set_exp(100);
   set("aggressive",0);
   add_money("gold",random(50));
   set_storage_room("/d/shadow/room/ekibi/rosinden_storage");
   force_me("speech say in a rapid, high-pitched cadance");
   set_mymaxvalue(6);
}

void init(){
   ::init();
   add_action("ask_em","ask");
}

int ask_em(string str){
   if(!str || str == "rosinden"){
      force_me("say Here you are, then!");
      new(OBJ"extractor")->move(TO);
      force_me("give extractor to "+TPQN+"");
      return 1;
   }
   tell_object(TP,"You might want to try to <ask rosinden>");
   return 1;
}

void receive_given_item(object obj){
   object ob;
   if(!objectp(obj)) return;
   if(!objectp(TP)) return;
   if((string)obj->query_name() == "faerzress sample") {
      obj->remove();
      force_me("say Oh, this is perfect!  Thank you!");
      force_me("emote turns and adds the faerzress sample to a "+
         "small box of stones.");
      force_me("say Now I can continue my experiments!  The "+
         "League will be most interested in my findings, I'm sure.");
      force_me("emote thinks a moment.");
      force_me("say I don't have much, as you can see, but let's "+
         "see what kind of reward I can find for you.");
      if(!userp(TP))  return;
      if(member_array("Rosinden's Mission",TP->query_mini_quests()) == -1) {
         tell_object(TP,"%^BOLD%^%^BLUE%^You've just finished "+
            "Rosinden's Mission!%^RESET%^");
         TP->set_mini_quest("Rosinden's Mission",50000,"%^BOLD%^%^CYAN%^Rosinden's Mission%^RESET%^");
      }
      tell_object(TP,"Rosinden hands you a small money pouch.");
      TP->add_money("gold",20+random(20));
      return;
   }
   if((string)obj->query_name() == "gnomish extractor"){
      force_me("say Ahh, many thanks!  You have no idea how many "+
         "people just wander off with my tools.");
      force_me("emote smiles and puts the extractor away, then "+
         "returns to her work.");
      obj->remove();
      return;
   }
   force_me("say Thanks, but this isn't quite what I'm looking for.");
   force_me("emote smiles and puts the item away.");
   obj->remove();
   return;
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name. 
//"who" returns the player object, so need to query the name for the other arrays.
   object current;
   object obj;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   if(!msg || !objectp(who)) return;
   if (objectp(current) && who != current) {
     force_me("emote squints and seems absorbed in her conversation "+
        "with "+who->QCN+".");
     return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"ail") != -1) && !step1){
      if(member_array("Rosinden's Mission",TP->query_mini_quests()) != -1) {
         force_me("say Ahh, back again, are ya?  Well, then..."+
            "I still need faerzress, if you're interested.");
         force_me("say If you need a new extractor, just <ask rosinden>.");
         force_me("emote grins and squints through her goggles.");
         return;
      }
      force_me("emote looks up from her work and squints.");
      force_me("say Well, greetings to ya!");
      force_me("say I don't have a lot of space, but you're welcome "+
         "to come in if ya want.");
      force_me("grin "+name+" and wrinkles her nose");
      force_me("say Oh, hey...you wouldn't be interested in helping "+
         "out a poor gnome, would ya?");
      step1 = 1;
      return;
   }
   if((strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 ||
      strsrch(msg,"kay") != -1 || strsrch(msg,"elp") != -1) && step1 && !step2){
      force_me("say I'm experimenting, see, for my League.  I "+
         "need to find this stone...faerzress, the drow call it.");
      force_me("say There are some caves nearby...seek some out "+
         "and bring it back to me, if ya want.  I'll reward you "+
         "with what I can.  Plus, you'll be helping science!");
      force_me("say Sound like a fair deal?");
      step2 = 1;
      return;
   }   
   if((strsrch(msg,"deal") != -1 || strsrch(msg,"fair") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"kay") != -1 || 
   strsrch(msg,"good") != -1 || strsrch(msg,"Yes") != -1 || strsrch(msg,"Good") !=-1) && step2 == 1) {
      force_me("say Perfect!");
      force_me("emote claps her hands excitedly, then searches "+
         "through a pile of things on a table, squinting and leaning "+
         "in close while she chatters away.");
      force_me("say See, I'm trying to prove myself to the League, "+
         "and I have this theory.  I just KNOW I'm right...");
      force_me("say Halflings found the caves ages ago, but...oh, well, "+
         "you need to be on your way I'm sure.  Just feel free to ask me "+
         "about halflings or the caverns any time now, you hear?");
      force_me("emote holds out a strange contraption.");
      obj = new(OBJ"extractor");
      obj->move(TO);
      force_me("give extractor to "+name+"");
      force_me("say Now, take this into the caverns and extract some "+
         "of the faerzress.  Bring it back to me, and I'll give you "+
         "what I can.");
      force_me("emote grins then mutters to herself and turns back "+
         "to her work, scratching her head.");
      step1 = 0;
      step2 = 0;
      return;
  }
   if(strsrch(msg,"alfling") != -1) {
      force_me("emote pauses for a moment and squints, wrinkling her nose.");
      force_me("say The halflings, the halflings...oh, you'll be "+
         "meaning about the cave, right?");
      force_me("emote nods and draws up to her full height, looking "+
         "the part of professor.");
      force_me("say Yes, well, the halflings...there was a small "+
         "band of them, oh, about twenty years ago.  They found "+
         "some caves near here and what they found was so disturbing "+
         "that when they returned, all they would say was 'ekibi', "+
         "which you - I have no doubt - know means 'bad' in their language.");
      force_me("say That group never went back, but one of their "+
         "number reported their findings to my League - the Gnomish "+
         "Explorers' League, of course.");
      force_me("emote smiles with a hint of pride, adjusting her "+
         "%^MAGENTA%^violet-colored goggles%^RESET%^.");
      force_me("say The League has sent me out here to discover the truth.");
      return;
  }
   if(strsrch(msg,"cave") != -1 || strsrch(msg,"avern") != -1 ||
   strsrch(msg,"kibi") != -1){
      force_me("say The Ekibi Caverns get their name from the "+
         "halflings who first discovered them.  They're filled "+
         "with all sorts of monstrous insects!");
      force_me("nod quickly");
      force_me("say They've grown into giants, you see, and I "+
         "think I know why.  There's a stone down there, "+
         "faerzress, the drow call it...anyway, I think it's "+
         "the source.  That's why I'm doing all these experiements "+
         "here.");
      force_me("say The caverns are just northeast of here, if you "+
         "have a hankering to go looking.  Hey, if you do, bring "+
         "me back a sample of faerzress, will you?");
      force_me("emote returns to her work.");
      return;
   }
   if(strsrch(msg,"aerzress") != -1 || strsrch(msg,"sample") != -1 || strsrch(msg,"stone") != -1) {
      force_me("say Faerzress stone?");
      force_me("emote pauses a moment and adjusts her %^MAGENTA%^"+
         "violet-colored goggles%^RESET%^.");
      force_me("say Well, it's a drow name, really, but it's "+
         "becoming more common now.  It's a purplish stone that "+
         "seems to glow...it's caused all sorts of havoc in the "+
         "underdark.");
      force_me("say I think it's in these caverns.  Oh, probably "+
         "in small amounts, mind you, but there nonetheless.");
      force_me("say That's why the insects in the Ekibi Caverns get so big.");
      force_me("emote nods resolutely.");
      force_me("say If you have a sample, you can simply <give> it to me.");
      return;
  }
}
