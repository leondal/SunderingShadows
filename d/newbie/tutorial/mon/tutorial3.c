//Added lance into the weapons part - Cythera //3/05 :)
//Added new weapontypes from creation and adjusted the merged ones. Nienne 3/07
#include <std.h>
inherit NPC;

void create() {
   ::create();
   set_name("elf");
   set_id(({"elven man","male elf","tutorial3"}));
   set_short("A slender, dark-haired male elf with emerald eyes");
   set_long("A slender elven man is standing in the room near you.  He has shoulder-length ebony hair and "
"emerald eyes, and is clad in simple forest garments.  He is watching you, with the sort of expression that "
"he seems like he is waiting for you to say or do something.");
   set_alignment(5);
   set_race("elf");
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
   call_out("step_1",6,TP);
   add_action("no_kill","kill");
   add_action("step_2","i");
   add_action("step_2","inventory");
   add_action("step_3","wear");
   add_action("step_4","remove");
   add_action("step_5","wield");
   add_action("step_6","unwield");
   add_action("step_7","discern");
//   add_action("step_8", "skillneeded");
   add_action("step_9","help");
   add_action("step_10","drink");
   add_action("step_11","money");
   add_action("side_fun","ask");
}

int no_kill(string str) {
   tell_object(TP,"%^RESET%^%^MAGENTA%^The elf smiles and shakes his head:%^RESET%^ Sorry, but you really "
"don't want to fight for real right now.");
   return 1;
}

void step_1(object target) {
   if(!objectp(target)) return 0;
   if(!objectp(TO)) return 0;
   if(!present(target,ETO)) return 0;
   if(target->query("newbtutorial3") > 1) tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The elf turns to you "
"and says:%^RESET%^ Hello there.  Do you want to start again at where we left off?  If you can't remember "
"where you were up to, just %^YELLOW%^<ask>%^RESET%^ me.\n\nHe smiles at you.");
   else {
     tell_object(target,"\n\n%^RESET%^%^MAGENTA%^The elven man turns to you as you enter:%^RESET%^ Greetings, "
"stranger.  I'm here to teach you about how to use your equipment and belongings.\n\nHe smiles warmly.\n\n"
"%^MAGENTA%^He speaks:%^RESET%^ The first thing I have to teach you is how to see what belongings you have.  "
"All you need to do is type %^YELLOW%^<inventory>%^RESET%^, or just %^YELLOW%^<i>%^RESET%^ for short.  Have a "
"try yourself.");
     target->set("newbtutorial3",1);
   }
}

int step_2(string str) {
   object ob;
   string tpsize;
   if((int)TP->query("newbtutorial3") != 1) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Just type %^YELLOW%^<inventory>"
"%^RESET%^, or %^YELLOW%^<i>%^RESET%^.");
     return 1;
   }
   TP->set("newbtutorial3",2);
   TP->force_me("inventory");
   switch((int)TP->query_size()) {
     case 1: tpsize = "small"; break;
     case 2: tpsize = "normal"; break;
     case 3: tpsize = "large"; break;
   }
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf nods:%^RESET%^ Ok, now to use what you have.  Because of "
"your size, you will always need to find %^YELLOW%^"+tpsize+"%^RESET%^ clothing and armor to use.  The robe "
"you found earlier should already be the right size, so let's try to put it on.  Try typing %^YELLOW%^<wear "
"robe>%^RESET%^.");
   return 1;
}

int step_3(string str) {
   if((int)TP->query("newbtutorial3") != 2) return 0;
   if(!str || str != "robe") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Type %^YELLOW%^<wear robe>%^RESET%^ by "
"itself.");
     return 1;
   }
   TP->set("newbtutorial3",3);
   TP->force_me("wear robe");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elven man says:%^RESET%^ Good, now you can wear what you find.  "
"Remember, if you ever want to use a shield you should %^YELLOW%^wear%^RESET%^ it too, don't wield it!\n\nHe "
"grins.\n\n%^MAGENTA%^He continues:%^RESET%^ Now that you can put it on, let's try taking it off.  Type "
"%^YELLOW%^<remove robe>%^RESET%^.");
   return 1;
}

int step_4(string str) {
   string twep;
   if((int)TP->query("newbtutorial3") != 3) return 0;
   if(!str || str != "robe") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Just type %^YELLOW%^<remove robe>%^RESET%^ by "
"itself.");
     return 1;
   }
   TP->set("newbtutorial3",4);
   TP->force_me("remove robe");
   if(TP->is_class("antipaladin") || TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("thief")) twep = "sword";
   else twep = "dagger";
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf nods approvingly:%^RESET%^ Right, now you can properly use "
"clothes, jewelry and armor, they all work the same way.  Weapons are a little different.  You will need to "
"%^YELLOW%^wield%^RESET%^ any weapon you want to use.  Let's try that now, with the weapon you found in the "
"last room.  Try %^YELLOW%^<wield "+twep+">%^RESET%^.");
   return 1;
}

int step_5(string str) {
   string twep;
   if((int)TP->query("newbtutorial3") != 4) return 0;
   if(TP->is_class("antipaladin") || TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("thief")) twep = "sword";
   else twep = "dagger";
   if(!str || str != twep) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Just try %^YELLOW%^<wield "+twep+">%^RESET%^.");
     return 1;
   }
   TP->set("newbtutorial3",5);
   TP->force_me("wield "+str+"");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf smiles and says:%^RESET%^ Good, now you can wield weapons.  "
"You can't hit things with them unless you have wielded them, so always remember to before you go into a fight"
", if you want to use them.  However, if you want to cast spells or do other things with your hands empty, you "
"will need to stop wielding the weapon again.  Let's try to %^YELLOW%^unwield%^RESET%^ your weapon now, by "
"typing %^YELLOW%^<unwield "+twep+">%^RESET%^.");
   return 1;
}

int step_6(string str) {
   string twep;
   if((int)TP->query("newbtutorial3") != 5) return 0;
   if(TP->is_class("antipaladin") || TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("thief")) twep = "sword";
   else twep = "dagger";
   if(!str || str != twep) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Just try %^YELLOW%^<unwield "+twep+
">%^RESET%^.");
     return 1;
   }
   TP->set("newbtutorial3",6);
   TP->force_me("unwield "+twep+"");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf continues:%^RESET%^ Good, that's what you need to do to use "
"your weapon.  You will also find sheathes and holsters to keep your weapons in, if you want them to be safe "
"from thieves when you are not using them.  Instead of using %^YELLOW%^<get>%^RESET%^ and then %^YELLOW%^<wield"
">%^RESET%^ to retrieve a weapon, you can just type %^YELLOW%^<draw weaponname>%^RESET%^ from a sheath to take "
"it out and wield it in one action.  To put it away again, use %^YELLOW%^<sheath weaponname>%^RESET%^.\n\n"
"%^RESET%^%^MAGENTA%^He says:%^RESET%^ Now, you may want to know how much damage a particular weapon does. Type %^YELLOW%^<discern "
+twep+">%^RESET%^ to see. You can also see what armor class your equipment offers with this command.");
   return 1;
}

int step_7(string str) {
   string twep,tprof;
   if((int)TP->query("newbtutorial3") != 6) return 0;
   if(TP->is_class("antipaladin") || TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("thief")) {
     twep = "sword"; tprof = "martial"; }
   else { twep = "dagger"; tprof = "simple"; }
   if(!str || str != twep) 
   {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Just try %^YELLOW%^<discern "+twep+
">%^RESET%^.");
     return 1;
   }
   TP->set("newbtutorial3",7);
   TP->force_me("discern "+twep+"");
/*
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf smiles and nods:%^RESET%^ Good.  You can see how much damage the "
+twep+" does. Now, the most important part of using a weapon is your proficiency with "
"it.  You will need training in a type of weapon in order to use it well without hurting yourself.  Let's "
"first check what sort of training you need to properly use the weapon you have. "
"Type %^YELLOW%^<skillneeded "+twep+">%^RESET%^ to see.");
*/
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf smiles and nods:%^RESET%^ Good.  You can see how much damage the "
+twep+" does. Let's learn a little about feats.  You can see this by typing %^YELLOW%^<help feats>%^RESET%^, so try that.");
   TP->set("newbtutorial3",8);
   return 1;
}

/*
int step_8(string str) 
{
   string twep,tprof;
   if((int)TP->query("newbtutorial3") != 7) return 0;
   if(TP->is_class("antipaladin") || TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("thief")) {
     twep = "sword"; tprof = "martial"; }
   else { twep = "dagger"; tprof = "simple"; }
   if(!str || str != twep) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Just try %^YELLOW%^<skillneeded "+twep+
">%^RESET%^.");
     return 1;
   }
   TP->set("newbtutorial3",8);
   TP->force_me("skillneeded "+twep+"");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf smiles and nods:%^RESET%^ Good.  You can see that the "
+twep+" needs the %^YELLOW%^"+tprof+" weapon proficiency%^RESET%^ feat, which comes with your class.  "
"Let's learn a little about feats.  You can see this by typing %^YELLOW%^<help feats>%^RESET%^, so try that.");
   return 1;
}
*/

int step_9(string str) {
   string tprof;
   object ob;
   if((int)TP->query("newbtutorial3") != 8) return 0;
   if(!str || str != "feats") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Just type %^YELLOW%^<help feats>%^RESET%^ to see "
"some information about feats.");
     return 1;
   }
   if(TP->is_class("antipaladin") || TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("thief")) tprof = "martial";
   else tprof = "martial";
   TP->set("newbtutorial3",9);
   TP->force_me("help feats");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf continues:%^RESET%^ Ok.  These are the basic commands to "
"use feats.  As it says, you can use %^YELLOW%^<feats list>%^RESET%^ to list what you have so far - if you try this "
"later you will see that %^YELLOW%^"+tprof+" weapon profiencity%^RESET%^ is on your list.  Other weapon feats "
"will allow you to use other weapons effectively in combat, while other feats may give you other skills and "
"abilities, both in and out of combat.  You can also use %^YELLOW%^<feats allowed>%^RESET%^ to see how many "
"feats you can spend right now - you should get one at level one (now!), and will gain another every three "
"levels, but remember they cost experience to buy!  You can look at %^YELLOW%^<help feats>%^RESET%^ at any "
"time, and %^YELLOW%^<help featname>%^RESET%^ for specifics about each one.\n\nHe smiles warmly.\n\n"
"%^MAGENTA%^He speaks:%^RESET%^ Now, next I will teach you about a very important item you can use when you "
"travel.\n");
   ob = new("/d/newbie/tutorial/mypotion");
   ob->move(TO);
   TO->force_me("give kit to "+TPQN+"");
   tell_object(TP,"\n%^RESET%^%^MAGENTA%^He says:%^RESET%^ This is a kit of healing vials.  If you get hurt "
"in a fight, you can use them to get healthy again.  The %^YELLOW%^<heal>%^RESET%^ command also works out of "
"combat, but it is very slow without proper training.  These kits are extra special because you can also using "
"them during combat, so you don't die before you beat what you are fighting!  To use the kit I have given you"
", try typing %^YELLOW%^<drink vial>%^RESET%^.");
   return 1;
}

int step_10(string str) {
   object ob;
   if((int)TP->query("newbtutorial3") != 9) return 0;
   if(!str || str != "vial") {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Just type %^YELLOW%^<drink vial>%^RESET%^ to "
"get some health back.");
     return 1;
   }
   TP->set("newbtutorial3",10);
   if(ob = present("newbvial",TP)) ob->remove();
   tell_object(TP,"You quickly quaff a dose of the %^BOLD%^%^CYAN%^brilliant blue potion%^RESET%^.");
   if(newbiep(TP) && (int)TP->query("offtutorial") < 3) {
     tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Good!  You can buy more vials like "
"these from healers, which you should be able to find in the cities you visit, and maybe other places too.  "
"These kits will only work while you are a newbie though - you will need to find different ones before you "
"leave the offestry area!  For now, here are some more to get you started when you journey.\n");
     ob = new("/d/common/obj/potion/newbie_healing");
     ob->set_uses(5); 
     ob->move(TO);
     TO->force_me("give kit to "+TPQN+"");
   }
   else tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Good!  You can buy more vials like "
"these from healers, which you should be able to find in the cities you visit, and maybe other places too.\n");
   tell_object(TP,"\n%^RESET%^The elf smiles.\n\n%^MAGENTA%^He speaks:%^RESET%^ That leaves only one simple "
"command to teach you.  There is one thing you possess that won't show up when you type in %^YELLOW%^inventory"
"%^RESET%^.  That is, how much money you have.  You can see how rich you are by typing %^YELLOW%^<money"
">%^RESET%^, so try that now.");
   return 1;
}

int step_10b(object myplayer) {
   object ob;
   if((int)myplayer->query("newbtutorial3") != 9) return 0;
   myplayer->set("newbtutorial3",10);
   if(newbiep(myplayer) && (int)myplayer->query("offtutorial") < 3) {
     tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Good!  You can buy more vials like "
"these from healers, which you should be able to find in the cities you visit, and maybe other places too.  "
"These kits will only work while you are a newbie though - you will need to find different ones before you "
"leave the offestry area!  For now, here are some more to get you started when you journey.\n");
     ob = new("/d/common/obj/potion/newbie_healing");
     ob->set_uses(5); 
     ob->move(TO);
     TO->force_me("give kit to "+myplayer->query_name()+"");
   }
   else tell_object(myplayer,"\n\n%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Good!  You can buy more vials like "
"these from healers, which you should be able to find in the cities you visit, and maybe other places too.\n");
   tell_object(myplayer,"\n%^RESET%^The elf smiles.\n\n%^MAGENTA%^He speaks:%^RESET%^ That leaves only one simple "
"command to teach you.  There is one thing you possess that won't show up when you type in %^YELLOW%^inventory"
"%^RESET%^.  That is, how much money you have.  You can see how rich you are by typing %^YELLOW%^<money"
">%^RESET%^, so try that now.");
   return 1;
}

int step_11(string str) {
   if((int)TP->query("newbtutorial3") != 10) return 0;
   if(str) {
     tell_object(TP,"%^RESET%^%^MAGENTA%^The elf says:%^RESET%^ Just type %^YELLOW%^<money>%^RESET%^ to see "
"how much of it you have.");
     return 1;
   }
   TP->set("newbtutorial3",11);
   TP->force_me("money");
   tell_object(TP,"\n\n%^RESET%^%^MAGENTA%^The elf smiles and speaks:%^RESET%^ Great!  Now you can see how "
"much money you have.  You can also put money into banks in the various towns so it is safe from thieves, but "
"just remember that all town banks are separate.  If you put money in the bank here in Offestry, you won't be "
"able to withdraw it in a different city, so take it with you when you graduate from being a newbie!  Now, you "
"know everything I am here to teach, so when you're ready you can go %^YELLOW%^<east>%^RESET%^ to the next "
"part of the tutorial, or just %^YELLOW%^<e>%^RESET%^ for short.");
   return 1;
}

int side_fun(string str) {
   int tracker;
   string twep;
   tracker = (int)TP->query("newbtutorial3");
   if(!tracker) {
     call_out("step_1",2,TP);
     return 1;
   }
   if(TP->is_class("antipaladin") || TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("fighter") || TP->is_class("bard") || TP->is_class("ranger") || TP->is_class("thief")) twep = "sword";
   else twep = "dagger";
   tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Have you forgotten where you were up to? "
" Ok, let's try again.");
   switch(tracker) {
     case 1: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Try to type %^YELLOW%^"
"<inventory>%^RESET%^ or just %^YELLOW%^<i>%^RESET%^ to see what you're carrying."); break;
     case 2: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Try typing %^YELLOW%^<wear robe"
">%^RESET%^ to put it on."); break;
     case 3: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Try typing %^YELLOW%^<remove "
"robe>%^RESET%^ to take it off."); break;
     case 4: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Try typing %^YELLOW%^<wield "
+twep+">%^RESET%^ to wield your weapon."); break;
     case 5: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Try typing %^YELLOW%^<unwield "
+twep+">%^RESET%^ to release your weapon."); break;
     case 6: tell_object(TP, "%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Try typing %^YELLOW%^<discern "+
     twep+">%^RESET%^ to learn how many damage the weapon does."); break;
     case 7: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Try typing %^YELLOW%^"
"<skillneeded "+twep+">%^RESET%^ to see what skill you need to know, to use it properly."); break;
     case 8: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Type %^YELLOW%^<help feats>%^RESET%^"
" to see what feats you know."); break;
     case 9: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Type %^YELLOW%^<drink "
"vial>%^RESET%^ to get some health back."); break;
     case 10: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ Type %^YELLOW%^<money>%^RESET%^"
" to see how much of it you have."); break;
     case 11: tell_object(TP,"%^RESET%^%^MAGENTA%^The slender elf says:%^RESET%^ I've taught you all I can, "
"whenever you're ready you can go %^YELLOW%^<east>%^RESET%^ into the next room, or just %^YELLOW%^<e>%^RESET%^ "
"for short."); break;
   }
   return 1;
}
