#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
//not sure if this does anything -H 11/14/20
#define TRUST ({"elf","voadkyn","firbolg","gnome","wemic","half-elf","dwarf","human","half-orc","halfling","dryad","saurian","squole","nymph","kitsune","wemic","deva"})
#define DISTRUST ({"beastman","drow","half-drow","orc","goblin","hobgoblin","bugbear","ogre","half-ogre","gnoll","ogre-mage","kobold","ratkin","shade","troll","minotaur"})

int step1;
int step2;
int step3;
string *asked;

void create(){
   ::create();
   set_name("sirith");
   set_id(({"sirith","human","male human","gray-haired human"}));
   set_short("%^RESET%^%^CYAN%^Sirith, a gray-haired male human%^RESET%^");
   set_long("%^CYAN%^Sirith seems to be getting on in age, with %^WHITE%^gray hair %^CYAN%^and a few wrinkles "
"upon his face.  Despite this, his %^ORANGE%^hazel %^CYAN%^eyes are bright and sharp, always alert as he "
"watches people pass him by on the street.  He is garbed in a %^BOLD%^%^BLACK%^simple robe%^RESET%^%^CYAN%^ "
"tied at the waist, and carries with him some sort of %^ORANGE%^old tome%^CYAN%^.%^RESET%^");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(10,3);
   set_max_level(10);
   set_size(2);
   set_alignment(5);
   set_overall_ac(5);
   set_max_hp(random(10)+60);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(10);
   set_class("mage");
   set_mlevel("mage",10);
   set_guild_level("mage",10);
   set_stats("intelligence", 18);
   set_stats("wisdom", 18);
   set_stats("strength", 6);
   set_stats("charisma", 9);
   set_stats("dexterity", 16);
   set_stats("constitution", 12);
   set_property("full attacks",1);
   set_property("alignment adjustment",-1);
   add_money("electrum",random(300));
   new("/d/common/obj/armour/robe")->move(TO);
   command("wear robe");
   new("/d/newbie/obj/misc/lpouch.c")->move(TO);
   set_spell_chance(90);
   set_spells(({"color spray","burning hands","lightning bolt","magic missile"}));
   set_spoken("wizish");
   set_emotes(1,({
     "%^MAGENTA%^Sirith ponders%^RESET%^: There must be some way to retrieve it...",
     "%^MAGENTA%^Sirith queries%^RESET%^: Are you seeking an adventure?",
     "Sirith looks you up and down.",
     "Sirith rubs his hands together, looking down the trail leading south.",
     "Sirith opens his book and scribbles down a few notes.",
     "Sirith studies a few people as they pass by on the street.",
   }), 0);
   set_new_exp(1, "very low");
}

void catch_say(string msg){
   call_out("reply_func",1,msg,TP);
}

void reply_func(string msg, object who){
//Note - quests are stored on the player.o, not by name. 
//"who" returns the player object, so need to query the name for the other arrays.
   object current;
   string race;
   string name;
   set_spoken("wizish");
   race = who->query_race();
   name = who->query_name();
   asked = SAVE_D->query_array("NBmynewbquest_asked");
   if(!msg || !objectp(who)) return;
   if (objectp(current) && who != current) {
     force_me("emote waves you away as he speaks to "+who->query_cap_name()+".");
     return;
   }
   if(who->query_quests()) 
   {
     if(member_array("Sirith's Task",who->query_quests()) != -1) 
     {
        if(!random(4)) 
        {
            force_me("say My thanks again for your help, friend!");
            force_me("nod "+name+"");
        }
        return;
     }
     if(member_array("Ignored Sirith's Task", who->query_quests()) != -1)
     {
         if(!random(4))
         {
             force_me("say thanks again for nothing!");
             force_me("frown "+name+"");
         }
         return;
     }
   }
//a repeat command, just in case someone forgets the instructions
   if((strsrch(msg,"repeat") != -1 || strsrch(msg,"Repeat") != -1) && (member_array(name, asked) != -1)){
      force_me("emote nods.\n");
      force_me("say The task is simple - the abomination that remains in the graveyard's tomb cannot be saved, but he can be destroyed.");
      force_me("say Do this for me, and retrieve whatever item he may be carrying.  I wish to study it.");
      return;
   }
   if(member_array(name, asked) != -1) {
     if(!random(3))
      force_me("say Did you manage to retrieve it?");
     if(!random(3))
      force_me("say If you did get the item, please give it to me.");
     if(random(3))
      force_me("say If you need me to %^YELLOW%^repeat%^RESET%^ my task, just say so.");
      return;
   }
   if((strsrch(msg,"ello") != -1 || strsrch(msg,"Hi") != -1 ||
      strsrch(msg,"reeting") != -1 || strsrch(msg,"who") != -1) && !step1){
      step1 = 1;
      force_me("emote considers for a moment.\n");
      force_me("say Greetings, stranger.  My name is Sirith, I'm a mage of no little skill.");
      force_me("say Perhaps you can help me with something?  I will be sure to reward you for your effort.");
      return;
   }   
   if((strsrch(msg,"help") != -1 || strsrch(msg,"yes") != -1 || 
    strsrch(msg,"Yes") != -1 || strsrch(msg,"will") != -1 || 
    strsrch(msg,"how") != -1  || strsrch(msg,"assist") != -1 || 
    strsrch(msg,"okay") != -1)&& step1 && !step2)        {
      force_me("say Wonderful.  I am here in Offestry to seek an artifact for my studies.");
      force_me("emote taps the cover of his book.");
      force_me("say As the town's story goes, a hero of theirs was buried in a tomb just south of here, after he died in an orc raid.");
      force_me("say However, some drow wizardry has been used to turn his body into a creature of undeath.  And for such magic to work, there must be an item carried by the undead beast.  I wish to study it, will you retrieve it for me?");
      step2 = 1;
      return;
   }
   if((strsrch(msg,"retrieve") != -1 || strsrch(msg,"help") != -1 ||
   strsrch(msg,"yes") != -1 || strsrch(msg,"Yes") != -1 || 
   strsrch(msg,"okay") != -1) && step2 == 1) {
      if(member_array(name, asked) == -1) {
         SAVE_D->set_value("NBmynewbquest_asked", name);
      }
      force_me("say Very good.  I will wait here, just bring it back to me and we can talk reward.");
      force_me("emote peers down the road leading to the south.");
      force_me("say It's not far from here.  Be careful, there are dangers and horrors that lurk in that graveyard...");
      step3 == 1;
      return;
  }
  switch(random(10)){
      case 0: force_me("say Have you found the item yet?"); break;
      case 1: force_me("say Beware the graveyard... evil things lurk there."); break;
      case 2: force_me("say I hear there's an elf and a half-orc around, both willing to reward travellers for their help in a task."); break;
      case 3: force_me("emote seems to be concentrating on studying notes in his book."); break;
      case 4: force_me("emote looks at you thoughtfully."); break;
      case 5: force_me("emote considers the passersby."); break;
      default: force_me("emote glances at you briefly, then turns to scribble some notes in his book, apparently pre-occupied."); break;
   }
   return;
}

void receive_given_item(object obj){
   object item;
   int size;
   asked = SAVE_D->query_array("NBmynewbquest_asked");
   if(!objectp(obj)) return;
   if(member_array("Sirith's Task",TP->query_quests()) != -1) 
   {
      force_me("say My thanks for your help, friend.");
      force_me("emoteat "+TPQN+" inclines his head toward $N.");
      return;
   }
   if(member_array("Ignored Sirith's Task", TP->query_quests()) != -1)
   {
       force_me("say Thanks for nothing!");
       force_me("emoteat "+TPQN+" scowls deeply at $N.");
       return;
   }
   if(member_array(TPQN, asked) == -1) {
     force_me("say Thank you for the gift.  Do I know you?");
     return;
   }   
   if(!(member_array("myringz",(string)obj->query_id()) != -1)) {
     force_me("say Thank you, but this isn't any help.");
     //force_me("give "+obj->query_name()+" to "+TP->query_name()+"");
     force_me("drop "+ obj->query_name()+"");
     return;
   }
   if(member_array("myringz",(string)obj->query_id()) != -1) {
      force_me("emote turns the ring over in his hand, studying it carefully.\n");
      force_me("say Perfect.  I shall have to study it at length.");
      force_me("emote puts the ring into his pocket.\n");
      force_me("say And as promised, I shall reward you for your work.");
      obj->remove();
      if(objectp(obj = present("newbiemassobject", TP))) 
      {
          if((int)obj->query_myTask() == 2) obj->advance_task();
          obj->adjust_my_align(25 + random(25));
      }
      if(member_array(TPQN, asked) != -1) 
        SAVE_D->remove_name_from_array("NBmynewbquest_asked", TPQN);
//to clean up the array after it's not needed any more
      if(member_array("Sirith's Task",TP->query_quests()) == -1){
        add_money("gold",400+random(100));
        force_me("give "+query_money("gold")+" gold coins to "+TPQN);
        TP->set_quest("Sirith's Task");
        //TP->fix_exp(750,TP);
        tell_object(TP,"You have finished Sirith's Task!");
        "/cmds/avatar/_note.c"->cmd_note("add "+TPQN+" retrieved the ring for Sirith (newbie quest).");
      }
      return;
   }
   return;
}

void reset() {
    ::reset();
    step1 = 0;
    step2 = 0;
    step3 = 0;
}
