#include <std.h>
inherit NPC;

void create() {
   ::create();
   set_name("firbolg");
   set_id(({"towering firbolg","tutorial4"}));
   set_short("A towering firbolg with red hair and a matching beard");
   set_long("Across the room stands a firbolg, towering over you.  He looks like a human, except far larger.  "
"He has scruffy red hair that he wears long, and a beard that matches.  He is watching you, with the sort of "
"expression that he seems like he is waiting for you to say or do something.");
   set_alignment(5);
   set_race("firbolg");
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
   add_action("step_2","kill");
   add_action("step_3","con");
   add_action("step_4","flee");
   add_action("step_5","wimpy");
   add_action("step_6","wimpydir");
   add_action("step_7","party");
   add_action("step_8","nod");
   add_action("side_fun","ask");
}

void step_1(object target) {
   if(!objectp(target)) return 0;
   if(!objectp(TO)) return 0;
   if(!present(target,ETO)) return 0;
   if(target->query("newbtutorial4") > 1) tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The firbolg turns to you "
"and says:%^RESET%^ Hello there.  Do you want to start again at where we left off?  If you can't remember "
"where you were up to, just %^YELLOW%^<ask>%^RESET%^ me.\n\nHe smiles down at you.");
   else {
     tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The tall firbolg looks down at you and says:%^RESET%^ Hello "
"there.  Come to learn how to play, have you?  Well, I can teach you the basics about fighting, so you can "
"survive if you get attacked.\n\nThe firbolg hmms.\n\n%^MAGENTA%^He rumbles:%^RESET%^You should already know "
"about weapons and how to wield them.  Now, the first command in a fight is easy.  If you want to attack "
"something, just type %^YELLOW%^<kill targetname>%^RESET%^.  You can try it on me to start with, I won't rough "
"you up.  Try typing %^YELLOW%^<kill firbolg>%^RESET%^.");
     target->set("newbtutorial4",1);
   }
}

int step_2(string str) {
   object ob;
   string tpsize;
   if((int)TP->query("newbtutorial4") != 1) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles a laugh:%^RESET%^ Now, now.  We've tried that "
"already so let's do something else.");
     return 1;
   }
   if(!str || str != "firbolg") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles:%^RESET%^ Just type %^YELLOW%^<kill firbolg>"
"%^RESET%^, to try attacking me.");
     return 1;
   }
   TP->set("newbtutorial4",2);
   tell_object(TP,"\n\nYou take a swing at the firbolg, and he grins and holds up his hands to ward you off."
"\n\n%^RESET%^%^MAGENTA%^He nods and says:%^RESET%^ Good, that's how you start a fight.  Some monsters will "
"attack you as soon as they see you though, so remember to use %^YELLOW%^<peer>%^RESET%^ like you were taught "
"before, so that you don't walk in on them before you're ready.\n\nHe smiles down at you.\n\n%^MAGENTA%^He "
"continues:%^RESET%^  Next, let's try out the very useful command %^YELLOW%^con%^RESET%^.  This lets you see "
"how healthy anyone is, including the monsters you're fighting, so you know if you're winning.  Try it out by "
"typing %^YELLOW%^<con firbolg>%^RESET%^.");
   return 1;
}

int step_3(string str) {
   if((int)TP->query("newbtutorial4") != 2) return 0;
   if(!str || str != "firbolg") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles:%^RESET%^ Type %^YELLOW%^<con firbolg>%^RESET%^ "
"by itself.");
     return 1;
   }
   TP->set("newbtutorial4",3);
   TP->force_me("con firbolg");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The firbolg smiles and says:%^RESET%^ As you can see, I'm quite "
"healthy.  The monsters you fight won't be though, hopefully.\n\nHe winks.\n\n%^MAGENTA%^He speaks:%^RESET%^ "
"The next command will help you get out of a fight quickly.  Normally, if you are fighting a creature and want "
"to run away, you can try to walk out an exit, but it will take you some time to escape.  Getting out of a "
"fight quicker can be done two ways.  The first one is just by typing %^YELLOW%^<flee>%^RESET%^, which will "
"cause you to escape through a random room exit.  Be careful though, this can be dangerous if there are other "
"monsters nearby and you run straight into them!  Try typing it now, just so I know you have the idea.");
   return 1;
}

int step_4(string str) {
   if((int)TP->query("newbtutorial4") != 3) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles:%^RESET%^ Just type %^YELLOW%^<flee>%^RESET%^ by "
"itself.");
     return 1;
   }
   TP->set("newbtutorial4",4);
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The firbolg smiles reassuringly:%^RESET%^ Good.  Now, the second "
"way to get out of a fight quickly takes planning.  You can set it before you go into a fight, so if you get "
"in trouble you'll automatically run away.  The command is called %^YELLOW%^wimpy%^RESET%^.  You can set it "
"to what percentage of health you want to be at, before you run away, up to a maximum of 50%.  This is done by "
"%^YELLOW%^<wimpy on percentage>%^RESET%^.  Let's try setting your wimpy, so that when you get to less than "
"30% of your health, you run away.  Type in %^YELLOW%^<wimpy on 30>%^RESET%^.");
   return 1;
}

int step_5(string str) {
   if((int)TP->query("newbtutorial4") != 4) return 0;
   if(!str || str != "on 30") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles:%^RESET%^ Just try %^YELLOW%^<wimpy on 30>"
"%^RESET%^ to set your wimpy command.");
     return 1;
   }
   TP->set("newbtutorial4",5);
   tell_object(TP,"\nWimpy mode on at 30 %.\n\n%^RESET%^%^MAGENTA%^The firbolg speaks:%^RESET%^ Right, now "
"you're safe to run out of a fight if you get into trouble.  Remember once you're done with it, to type "
"%^YELLOW%^<wimpy off>%^RESET%^ to turn it back off again.  There's one other command that works with "
"%^YELLOW%^wimpy%^RESET%^, and it is called %^YELLOW%^<wimpydir>%^RESET%^.  It stands for 'wimpy direction', "
"and allows you to set what direction you want to run in when your health gets low.  Let's try to set your "
"wimpydir now, so that you run south.  Type in %^YELLOW%^<wimpydir south>%^RESET%^.");
   return 1;
}

int step_6(string str) {
   if((int)TP->query("newbtutorial4") != 5) return 0;
   if(!str || str != "south") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles:%^RESET%^ Just try %^YELLOW%^<wimpydir south>"
"%^RESET%^ to set your wimpy direction.");
     return 1;
   }
   TP->set("newbtutorial4",6);
   TP->force_me("wimpydir south");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The firbolg speaks:%^RESET%^ Right, now you will run south "
"automatically, if you're in trouble.  Remember also, if your wimpy happens and there is no 'south' exit in "
"the room, it will just choose one for you randomly to run.\n\nThe firbolg thinks for a moment, about what "
"else to teach you.\n\n%^MAGENTA%^He says:%^RESET%^ You should know about parties too.  If you find another "
"player and you want to go and fight monsters together, you already know how to %^YELLOW%^follow%^RESET%^ "
"them.  But to share the experience you get from fighting, you will need to be in a %^YELLOW%^party%^RESET%^.  "
"There are three commands you will need to know for this.  They are: %^YELLOW%^<party form name>%^RESET%^, "
"%^YELLOW%^<party add playername>%^RESET%^, and %^YELLOW%^<party join name>%^RESET%^.  We'll try the first one "
"for now, so make your own party called '"+TP->query_name()+"party'.  Just type %^YELLOW%^<party form "
+TP->query_name()+"party>%^RESET%^.");
   return 1;
}

int step_7(string str) {
   if((int)TP->query("newbtutorial4") != 6) return 0;
   if(!str || str != "form "+TP->query_name()+"party") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles:%^RESET%^ Just try typing %^YELLOW%^<party form "
+TP->query_name()+"party>%^RESET%^.");
     return 1;
   }
   TP->set("newbtutorial4",7);
   TP->force_me("party form "+TP->query_name()+"party");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The towering firbolg says:%^RESET%^ Now you have your very own "
"party!  You can't use the other commands yet, but they work like this. %^YELLOW%^<party add playername>"
"%^RESET%^ will invite another player to join your party.  They won't be able to join unless you invite them "
"first.  %^YELLOW%^<party join partyname>%^RESET%^ will let you join a party, if someone invites you - just "
"make sure that you type the name in exactly as they have written it, or it will not work.\n\nHe smiles.\n\n"
"%^MAGENTA%^He says:%^RESET%^ That's almost everything I have to teach you, except for one thing.  Just "
"%^YELLOW%^<nod>%^RESET%^ when you think you're ready for me to teach you.");
   return 1;
}

int step_8(string str) {
   if((int)TP->query("newbtutorial4") != 7) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles:%^RESET%^ Just %^YELLOW%^<nod>%^RESET%^ when "
"you're ready to learn the last command.");
     return 1;
   }
   TP->set("newbtutorial4",8);
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^He smiles and speaks:%^RESET%^ Good.  The last thing I have to "
"teach you isn't a command, it's just a convenient word you to use.  You'll notice whenever you use a command "
"that is aimed at someone, you can use either their race, or their name if you have used %^YELLOW%^<recognize>"
"%^RESET%^ on them like you were taught before.  If Fred the firbolg is standing in the room with you, you can "
"type %^YELLOW%^<kill firbolg>%^RESET%^ or %^YELLOW%^<kill fred>%^RESET%^, and they will both work.\n\n"
"%^MAGENTA%^He says:%^RESET%^ There is one more though, that works for anything you are already fighting.  You "
"can use %^YELLOW%^attacker%^RESET%^ for this.  %^YELLOW%^<con attacker>%^RESET%^ will tell you how healthy "
"the creature you're fighting is, and %^YELLOW%^<look attacker>%^RESET%^ will let you look at him.  It's very "
"useful if you're suddenly attacked and you don't know what to look at, or where to aim spells if you have "
"them.  If there are a group of creatures attacking you, try using %^YELLOW%^attacker 1%^RESET%^, %^YELLOW%^"
"attacker 2%^RESET%^, and such.\n\nHe smiles and steps back, leaving the exit clear.\n\n%^MAGENTA%^He rumbles:"
//"%^RESET%^ That's all I have to teach you now.  You can leave, good luck in your adventures!");
"%^RESET%^ That's all I have to teach you now.  You can go to the next room, good luck.");
   return 1;
}

int side_fun(string str) {
   int tracker;
   tracker = (int)TP->query("newbtutorial4");
   if(!tracker) {
     call_out("step_1",2,TP);
     return 1;
   }
   tell_object(TP,"%^RESET%^%^MAGENTA%^The firbolg rumbles:%^RESET%^ Have you forgotten where you were up to? "
" Ok, let's try again.");
   switch(tracker) {
     case 1: tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ Try to type %^YELLOW%^<kill firbolg>"
"%^RESET%^ to attack me."); break;
     case 2: tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ Try typing %^YELLOW%^<con firbolg>%^RESET%^ "
"to see how healthy I am."); break;
     case 3: tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ Try typing %^YELLOW%^<flee>%^RESET%^.");
 break;
     case 4: tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ Try typing %^YELLOW%^<wimpy on 30>%^RESET%^ "
"to set your wimpy command to 30%."); break;
     case 5: tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ Try typing %^YELLOW%^<wimpydir south>"
"%^RESET%^ to set your wimpy direction."); break;
     case 6: tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ Try typing %^YELLOW%^<party form "+
TP->query_name()+"party>%^RESET%^ to make your very own party!."); break;
     case 7: tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ Just <%^YELLOW%^<nod>%^RESET%^ when you're "
"ready to learn the last command here."); break;
     case 8: tell_object(TP,"%^RESET%^%^MAGENTA%^He says:%^RESET%^ There's nothing more I can teach you, you're"
//" free to go!  Type %^YELLOW%^<out>%^RESET%^ to leave.");
" free to go!  Type %^YELLOW%^<north>%^RESET%^ or just %^YELLOW%^<n>%^RESET%^ to go to the next room.");
 break;
   }
   return 1;
}
