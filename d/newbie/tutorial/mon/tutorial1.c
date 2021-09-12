#include <std.h>
inherit NPC;

void create() 
{
   ::create();
   set_name("man");
   set_id(({"man","tutorial1"}));
   set_short("%^BOLD%^%^RED%^An average male human with %^RESET%^%^ORANGE%^dusky tan hair%^RESET%^");
   set_long("%^RESET%^%^CYAN%^There is a human man standing in the middle of the room.  He is fairly average "
"and non-descript, wearing simple clothes and with %^ORANGE%^short, dusky tan hair%^CYAN%^.  He is watching "
"you with an expectant expression, as though he is waiting for you to say or do something.  You're sure if you "
"can't remember where you were up to with your training, you could %^YELLOW%^<ask>%^RESET%^%^CYAN%^ him.");
   set_alignment(5);
   set_race("human");
   set_class("fighter");
   set_body_type("human");
   set_property("no attack",1);
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("male");
}

void init() {
   ::init();
   call_out("step_1",4,TP);
   add_action("no_kill","kill");
   add_action("step_2","nod");
   add_action("step_3","score");
   add_action("step_4","stats");
   add_action("step_5","languages");
   add_action("step_6","speak");
   add_action("step_7","say");
   add_action("step_8","emote");
   add_action("side_fun","ask");
}

int no_kill(string str) {
    tell_object(TP,"%^RESET%^%^MAGENTA%^The man chides:%^RESET%^ Sorry, but you really don't want to fight for "
"real right now.");
    return 1;
}

void step_1(object target) {
   if(!objectp(target)) return 0;
   if(!objectp(TO)) return 0;
   if(!present(target,ETO)) return 0;
   if(target->query("newbtutorial") > 1){
      tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The man turns to you and says:"
      "%^RESET%^ Hello again!  Do you want to start again at where we left off?  If you can't remember where you "
      "were up to, just %^YELLOW%^<ask>%^RESET%^ me.\n\nThe man smiles.");
      return;
   }else{
      tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The man turns to you and says:%^RESET%^ Welcome, newcomer, "
         "to Sundering Shadows!  I am always glad to see fresh faces, it gets very lonely here sometimes.\n\n"
         "%^MAGENTA%^He shakes his head and continues:%^RESET%^ I am here to teach you the first basic commands.  Just "
         "%^YELLOW%^<nod>%^RESET%^ when you're ready.\n\nThe man smiles.");
      target->set("newbtutorial",1);
      return;
   }
}

int step_2(string str) {
   if((int)TP->query("newbtutorial") != 1) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Just %^YELLOW%^<nod>%^RESET%^ when you're "
"ready to start.");
     return 1;
   }
   TP->set("newbtutorial",2);
   TP->force_me("nod");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Good, let's begin with one of the most "
"important commands.  Type %^YELLOW%^<score>%^RESET%^.");
   return 1;
}

int step_3(string str) {
   if((int)TP->query("newbtutorial") != 2) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Just type %^YELLOW%^<score>%^RESET%^ by "
"itself.");
     return 1;
   }
   TP->set("newbtutorial",3);
   TP->force_me("score");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The man smiles, speaking:%^RESET%^ This command will tell you "
"about your character.  You should be able to see what level and class/es you are, what your hit-points "
"are, how much money you have, if you're hungry, thirsty or poisoned, and many other things besides.\n\n"
"He pauses, before continuing.\n\n%^MAGENTA%^He says:%^RESET%^ You can use this to know when to eat or drink, "
"when to advance to the next level, and so on.\n\n%^MAGENTA%^He says:%^RESET%^ Next, try typing %^YELLOW%^<"
"stats>%^RESET%^.");
   return 1;
}

int step_4(string str) {
   if((int)TP->query("newbtutorial") != 3) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Just type %^YELLOW%^<stats>%^RESET%^ by "
"itself.");
     return 1;
   }
   TP->set("newbtutorial",4);
   TP->force_me("stats");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The man says:%^RESET%^ These are your character's statistics.  How "
"strong and wise you are, how charismatic and several other things besides.  You can gain a new stat every four "
"levels, but remember this will cost you experience!  You can look at %^YELLOW%^<help stats>%^RESET%^ at any "
"time to find out how many you can buy, and what the syntax is.\n\n%^MAGENTA%^He smiles, saying:%^RESET%^ Now "
"type in %^YELLOW%^<languages>%^RESET%^.");
   return 1;
}

int step_5(string str) {
   string spoken;
   if((int)TP->query("newbtutorial") != 4) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Just type %^YELLOW%^<languages>%^RESET%^ by "
"itself.");
     return 1;
   }
   TP->set("newbtutorial",5);
   TP->force_me("languages");
   if((int)TP->query_lang("common") == 100) spoken = "common";
   else {
     switch((string)TP->query_race()) {
       case "beastman": case "gnoll": case "wemic": spoken = "beast"; break;
       case "bugbear": case "goblin": case "hobgoblin": spoken = "goblin"; break;
       case "kobold": spoken = "draconic"; break;
       case "ogre": case "half-ogre": case "ogre-mage": spoken = "ogrish"; break;
       case "orc": case "half-orc": spoken = "orcish"; break;
       case "drow": case "half-drow": spoken = "drow"; break;
       case "dwarf": spoken = "dwarvish"; break;
       case "elf": case "half-elf": spoken = "elven"; break;
       case "gnome": spoken = "gnomish"; break;
       case "halfling": spoken = "halfling"; break;
       case "firbolg": case "voadkyn": spoken = "giant"; break;
       default: spoken = "undercommon"; break;
     }
   }
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The man says:%^RESET%^ These are the languages your character can "
"speak, and how well they speak them (out of 100%).  You should know your native language perfectly, and you "
"may also know parts of others.  Other characters in the game can help you improve your knowledge of a language"
", or perhaps teach you a new one if you are intelligent enough.\n\n%^RESET%^%^MAGENTA%^He says:%^RESET%^ You "
"can change your spoken language by typing %^YELLOW%^<speak languagename>%^RESET%^.  For now, try to speak "
"your character's native language, by typing %^YELLOW%^<speak "+spoken+">%^RESET%^.");
   return 1;
}

int step_6(string str) {
   string spoken;
   if((int)TP->query_lang("common") == 100) spoken = "common";
   else {
     switch((string)TP->query_race()) {
       case "beastman": case "gnoll": case "wemic": spoken = "beast"; break;
       case "bugbear": case "goblin": case "hobgoblin": spoken = "goblin"; break;
       case "kobold": spoken = "kobold"; break;
       case "ogre": case "half-ogre": case "ogre-mage": spoken = "ogrish"; break;
       case "orc": case "half-orc": spoken = "orcish"; break;
       case "drow": case "half-drow": spoken = "drow"; break;
       case "dwarf": spoken = "dwarvish"; break;
       case "elf": case "half-elf": spoken = "elven"; break;
       case "gnome": spoken = "gnomish"; break;
       case "halfling": spoken = "halfling"; break;
       case "firbolg": case "voadkyn": spoken = "giant"; break;
       default: spoken = "undercommon"; break;
     }
   }
   if((int)TP->query("newbtutorial") != 5) return 0;
   if(!str || str != spoken) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Try to type %^YELLOW%^<speak "+spoken+
">%^RESET%^ to speak your native language.");
     return 1;
   }
   TP->set("newbtutorial",6);
   TP->force_me("speak "+spoken+"");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^He says:%^RESET%^ Great!  Now that you've set your language, let's "
"try to say something, with %^YELLOW%^<say>%^RESET%^.");
   return 1;
}

int step_7(string str) {
   if((int)TP->query("newbtutorial") != 6) return 0;
   if(!str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Try to actually %^YELLOW%^<say>%^RESET%^ some "
"words.");
     return 1;
   }
   TP->set("newbtutorial",7);
   TP->force_me("say "+str+"");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The man nods and replies:%^RESET%^ Ok, now you can talk!  There's "
"only one thing left for me to teach you.\n\n%^MAGENTA%^He goes on to say:%^RESET%^ The other main part of "
"communicating is emotes.  Emotes are the actions your character can do, waving your arms, blowing your nose, "
"or just about anything else you can do in real life.  You can always just nod, smile, wave, and many other "
"simple commands, but emotes give you much more variety and creativity.\n\n%^MAGENTA%^He smiles and continues:"
"%^RESET%^ Have a go now. Try to %^YELLOW%^<emote>%^RESET%^ doing something.");
   return 1;
}

int step_8(string str) {
   if((int)TP->query("newbtutorial") != 7) return 0;
   if(!str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Try to actually %^YELLOW%^<emote>%^RESET%^ an "
"action.");
     return 1;
   }
   TP->set("newbtutorial",8);
   TP->force_me("emote "+str+"");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The man smiles warmly, saying:%^RESET%^ Wonderful!  You've learnt "
"everything I can teach you.  You should also read up on emoteat - %^YELLOW%^help emoteat%^RESET%^ - which will allow you to perform more "
"advanced and targeted actions directed at others in the world. In the next room you'll learn about moving around and interacting with places.  "
"You can make a start on that here, actually.\n\nThe man looks around, thinking for a moment.\n\n%^MAGENTA%^He "
"says:%^RESET%^ If you %^YELLOW%^<look>%^RESET%^, or use %^YELLOW%^<l>%^RESET%^ for short, you'll see that "
"there is one exit to this room.  You can type the name of any exit to go in that direction.  So, to move into "
"the next room, type %^YELLOW%^<east>%^RESET%^, or just %^YELLOW%^<e>%^RESET%^ for short.  Good luck!");
   return 1;
}

int side_fun(string str) {
   int tracker;
   string spoken;
   tracker = (int)TP->query("newbtutorial");
   if(!tracker) {
     call_out("step_1",2,TP);
     return 1;
   }
   if((int)TP->query_lang("common") == 100) spoken = "common";
   else {
     switch((string)TP->query_race()) {
       case "beastman": case "gnoll": case "wemic": spoken = "beast"; break;
       case "bugbear": case "goblin": case "hobgoblin": spoken = "goblin"; break;
       case "kobold": spoken = "kobold"; break;
       case "ogre": case "half-ogre": case "ogre-mage": spoken = "ogrish"; break;
       case "orc": case "half-orc": spoken = "orcish"; break;
       case "drow": case "half-drow": spoken = "drow"; break;
       case "dwarf": spoken = "dwarvish"; break;
       case "elf": case "half-elf": spoken = "elven"; break;
       case "gnome": spoken = "gnomish"; break;
       case "halfling": spoken = "halfling"; break;
       case "firbolg": case "voadkyn": spoken = "giant"; break;
     }
   }
   tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Have you forgotten where you were up to?  Ok, "
"let's try again.\n");
   switch(tracker) {
     case 1: tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Just %^YELLOW%^<nod>%^RESET%^ when "
"you're ready to start."); break;
     case 2: tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Start by typing %^YELLOW%^<score>"
"%^RESET%^."); break;
     case 3: tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Try typing %^YELLOW%^<stats>%^RESET%^"
"."); break;
     case 4: tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Type %^YELLOW%^<languages>%^RESET%^ to "
"see which languages you can speak."); break;
     case 5: tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Try typing %^YELLOW%^<speak "+spoken+
">%^RESET%^ to speak your native language."); break;
     case 6: tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Try to %^YELLOW%^<say>%^RESET%^ "
"something, to learn to speak."); break;
     case 7: tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ Try to %^YELLOW%^<emote>%^RESET%^ "
"something, to do an action."); break;
     case 8: tell_object(TP,"%^RESET%^%^MAGENTA%^The man says:%^RESET%^ I can't teach you anything more here.  "
"Just go %^YELLOW%^<east>%^RESET%^ to the next room, or %^YELLOW%^<e>%^RESET%^ for short, where you can learn "
"further."); break;
   }
   return 1;
}

