#include <std.h>
inherit NPC;

void create() {
   ::create();
   set_name("halfling");
   set_id(({"short halfling","tutorial2","shaani"}));
   set_short((:TO,"my_desc":));
   set_long("A little halfling is standing in the room near you.  She is very short, only about three feet "
"tall, with bright blue eyes and ebony curls to her shoulders.  She is clad in rather garish clothing, all of "
"bright colours that don't really match.  She is watching you, with the sort of expression that she seems like "
"she is waiting for you to say or do something.");
   set_alignment(5);
   set_race("halfling");
   set_class("fighter");
   set_body_type("human");
   set_property("no attack",1);
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("female");
}

string my_desc() {
   if ((int)TP->query("newbtutorial2") < 2) {
     return("A short female halfling with ebony curls");
   }
   return ("Shaani, a short female halfling with ebony curls");
}

void init() {
   ::init();
   call_out("step_1",4,TP);
   add_action("no_kill","kill");
   add_action("step_2","recognize");
   add_action("step_3","get");
   add_action("step_4","search");
   add_action("step_5","peer");
   add_action("step_6","follow");
   add_action("side_fun","ask");
}

int no_kill(string str) {
    tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani giggles and skips away, saying:%^RESET%^ Sorry, but you really "
"don't want to fight for real right now.");
    return 1;
}

void step_1(object target) {
   if(!objectp(target)) return 0;
   if(!objectp(TO)) return 0;
   if(!present(target,ETO)) return 0;
   if(target->query("newbtutorial2") > 1) tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The halfling turns to you "
"and says:%^RESET%^ Hello again!  Do you want to start again at where we left off?  If you can't remember "
"where you were up to, just %^YELLOW%^<ask>%^RESET%^ me.\n\nShe grins at you.");
   else {
     tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The halfling grins and speaks:%^RESET%^ Hiya!  My name's "
"Shaani, I'm here to teach you all about moving around, and interacting with stuff!\n\nShe claps her hands.\n\n"
"%^MAGENTA%^She says brightly:%^RESET%^ Ok!  First thing you should try to use is %^YELLOW%^recognize%^RESET%^."
"  It's really helpful when you meet people, so you can remember who they are.  Let's try it on me!  Since I'm "
"a halfling, type in %^YELLOW%^<recognize halfling as shaani>%^RESET%^.");
     target->set("newbtutorial2",1);
   }
}

int step_2(string str) {
   object ob;
   if((int)TP->query("newbtutorial2") != 1) return 0;
   if(!str || (str != "halfling as shaani" && str != "halfling as Shaani")) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The halfling shakes her head:%^RESET%^ No no, just type %^YELLOW%^<"
"recognize halfling as shaani>%^RESET%^ to recognize me.");
     return 1;
   }
   TP->set("newbtutorial2",2);
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^Shaani smiles and nods:%^RESET%^ There you go!  Now you know who I "
"am.  You can do that to anyone, using %^YELLOW%^recognize race as name%^RESET%^.  Now, let's go through some "
"basic actions.\n\nShaani drops a robe.\n\n%^MAGENTA%^Shaani speaks:%^RESET%^ The most basic action is "
"%^YELLOW%^get%^RESET%^.  It lets you pick things up.  Try to %^YELLOW%^<get robe>%^RESET%^ from the "
"floor.");
   ob = new("/d/common/obj/armour/robe");
   ob->move(ETP);
   ob->set_size(TP->query_size());
   return 1;
}

int step_3(string str) {
   if((int)TP->query("newbtutorial2") != 2) return 0;
   if(!str || str != "robe") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani shakes her head:%^RESET%^ No no, just type %^YELLOW%^<get robe>"
"%^RESET%^ by itself.");
     return 1;
   }
   TP->set("newbtutorial2",3);
   TP->force_me("get robe");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^Shaani grins and speaks:%^RESET%^ You're doing great!  Now, another "
"very important action is %^YELLOW%^search%^RESET%^.  It lets you look around more closely, and sometimes find "
"hidden things.  You can just type %^YELLOW%^<search>%^RESET%^ by itself to search the whole room, or "
"%^YELLOW%^<search objectname>%^RESET%^ to search somewhere specific.  Searching can often give you really "
"good hints about actions you can take in a room.\n\nShaani points at the crate beside her.\n\n%^MAGENTA%^"
"Shaani winks and says:%^RESET%^ That crate looks a little out of place, doesn't it?  Let's try to %^YELLOW%^"
"<search crate>%^RESET%^ to see if there's anything in it.");
   return 1;
}

int step_4(string str) {
   if((int)TP->query("newbtutorial2") != 3) return 0;
   if(!str || str != "crate") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani shakes her head:%^RESET%^ No no, just type %^YELLOW%^<search "
"crate>%^RESET%^ by itself.");
     return 1;
   }
   TP->set("newbtutorial2",4);
   if(TP->is_class("barbarian") || TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("thief")) new("/d/common/obj/weapon/longsword")->move(TP);
   else new("/d/common/obj/weapon/dagger")->move(TP);
   tell_object(TP,"You find a weapon inside the crate!\n");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^Shaani smiles and continues:%^RESET%^ Great, now you can search to "
"find things!  Now, the next command is a very important one, so you don't go walking around blindly and get "
"in trouble.  The %^YELLOW%^peer%^RESET%^ command allows you to look out of a room exit, to see what is there"
".  This really helps so you don't walk in on dragons unaware!\n\nShaani smiles and points to the south.\n\n"
"%^MAGENTA%^Shaani says:%^RESET%^ Try to %^YELLOW%^<peer south>%^RESET%^, <peer south 1> or just %^YELLOW%^<peer s>%^RESET%^, "
"to see what is in the next room. Remember that in larger areas you can specify how many rooms you want to peer "+
"through, which will give you an idea of what monsters or treasures might await you.");
   return 1;
}

int step_5(string str) {
   if((int)TP->query("newbtutorial2") != 4) return 0;
   if(!str || (str != "south" && str != "s")) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani shakes her head:%^RESET%^ No no, just type %^YELLOW%^<peer "
"south>%^RESET%^, or %^YELLOW%^<peer s>%^RESET%^, to see where you're going.");
     return 1;
   }
   TP->set("newbtutorial2",5);
   TP->force_me("peer south");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^Shaani grins and nods:%^RESET%^ Ok, now you know heaps of useful "
"things!  I have one more thing to teach you, about moving around.  It's called the %^YELLOW%^follow%^RESET%^ "
"command.  When someone offers to let you follow them, it looks like this.\n\nYou have been invited to follow "
"Shaani.\n\n%^MAGENTA%^Shaani continues:%^RESET%^ All you have to do is type %^YELLOW%^<follow playername>"
"%^RESET%^ to follow them around, although you have to make sure you have %^YELLOW%^recognized%^RESET%^ them "
"first.  Try to follow me by typing %^YELLOW%^<follow shaani>%^RESET%^, so I can lead you into the next room!");
   return 1;
}

int step_6(string str) {
   if((int)TP->query("newbtutorial2") != 5 && (int)TP->query("newbtutorial2") != 6) return 0;
   if(!str || str != "shaani") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani shakes her head:%^RESET%^ No no, just type %^YELLOW%^<follow "
"shaani>%^RESET%^ so we can go to the next room!");
     return 1;
   }
   tell_object(TP,"%^RESET%^You are now following Shaani.\n\n%^RESET%^%^MAGENTA%^Shaani smiles:%^RESET%^ Great!"
"  You can use the follow command to let people follow you.  Have a look at %^YELLOW%^<help follow>%^RESET%^ "
"later, for other ways to use the command.  For now, you're all done here!  Let's go to the next room!");
   TP->set("newbtutorial2",6);
   call_out("move_me",5,TP);
   return 1;
}

void move_me(object target) {
   if(!objectp(target)) return 0;
   if(!objectp(TO)) return 0;
   if(!present(target,ETO)) return 0;
   tell_object(target,"%^GREEN%^%^BOLD%^Shaani skips out to the south.\n");
   target->force_me("south");
   tell_object(target,"%^RESET%^%^MAGENTA%^Shaani grins and says:%^RESET%^ Ok, I've taught you all I can, good "
"luck!\n\nShaani waves, and disappears!");
}

int side_fun(string str) {
   int tracker;
   string spoken;
   tracker = (int)TP->query("newbtutorial2");
   if(!tracker) {
     call_out("step_1",2,TP);
     return 1;
   }
   tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani says:%^RESET%^ Have you forgotten where you were up to?  Ok, "
"let's try again.");
   switch(tracker) {
     case 1: tell_object(TP,"%^RESET%^%^MAGENTA%^The halfling says:%^RESET%^ Just type %^YELLOW%^<recognize "
"halfling as shaani>%^RESET%^."); break;
     case 2: tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani says:%^RESET%^ Try to type %^YELLOW%^<get robe>"
"%^RESET%^ to pick it up."); break;
     case 3: tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani says:%^RESET%^ Type %^YELLOW%^<search crate>%^RESET%^ "
"to see if there's anything in it."); break;
     case 4: tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani says:%^RESET%^ Try to %^YELLOW%^<peer south>%^RESET%^, "
"or %^YELLOW%^<peer s>%^RESET%^, so you can see where you're going."); break;
     case 5..6: tell_object(TP,"%^RESET%^%^MAGENTA%^Shaani says:%^RESET%^ Try to use %^YELLOW%^<follow shaani>"
"%^RESET%^, so we can go to the next room!"); break;
   }
   return 1;
}
