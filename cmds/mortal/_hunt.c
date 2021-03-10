/* _hunt.c for NWPs - based somewhat on original /cmds/mortal/_hunt.c
trainers include - /d/newbie/mon/doran (5)
   /d/npc/shiper ( 
   Was to allow people to gather food while away from normal food sources
   By *Styx*  7/2002
   Terrain type determines type of game found, foraging and fishing are separate
   Size/quality of game & speed to kill improves with skill
--------------------------------------------------
Notes for future improvements ??
Per T to track the mobs they scare up.
  user->set_static("hunted monsters",({mon}));
per Garrett - so object * array; array =  get_static(); array -= ({0});
array += ({mon}); set_static(,array)
 the -= is to remove any 0's and indeed there is one if the mob is destroyed
  
  then like object * obj = (object *)user->get_static("hunted monsters");
  if (sizeof(obj) > 3) {say you don't find anything)
have the monster record who is hunting it then when it dieds
Someone <wiz> run your perform nwp at that point
OK, I guess I was thinking it would be easiest to have the killing blow do the nwp, but as I think about it now, that would require putting something in combat.c wouldn't it? 
~styx/bin  <wiz> Someone nods
(Styx) <wiz> So if it goes to whoever "found" it on death, that's easier then.  
run the nwp on the death - then remove that mon from the array on the user
??  example from /std/user to use to remove?? 
       static_user["channels"] -= restricted_channels;

deal with boat and ferry rooms
*/

#include <std.h>
#include <daemons.h>
//#include <move.h>

inherit DAEMON;

int pick_mons(object who, int diff);

int cmd_hunt(string str){
   int max_time, time, i, prof, hunted;
   if(TP->query_bound()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   prof = TP->query_skill("survival")+roll_dice(1,20);
   if(TP->query_blind()) {
      notify_fail("You can't hunt game blinded.\n");
      return 0;
   }
    if (TP->query_property("working")) {
        return notify_fail("You are already "+(string)TP->query_property("working")+".\n");
    }
   if((object)TP->query_attackers() != ({})) {
	notify_fail("You're too busy to be hunting game right now!\n");
        return 0;
   }
   if(!TP->query_skill("survival")) {
      notify_fail("You have no skill at wilderness survival.\nMaybe you should try to <forage for food> for now.\n");
      return 0;
   }
   if(!TP->query_time_delay("hunting",20)) {
      write("You need more time to study the area or for some wildlife to wander in before trying again.");
      return 1;
   }
   hunted = TP->get_static("hunted monsters");
   if(hunted > 3) {
      notify_fail("You've found your limit for now.  Go kill some of them " 
                  "before stirring up any more will you?\n");
      return 0;
   }

   tell_room(ETP,TPQCN+" seems to be studying the area.",TP);
   write("You start peering around for signs of game to hunt.\n");
   TP->set_time_delay("hunting");
   switch(prof) {
      case 0..5 :    max_time = 40;   break;
      case 6..10 :   max_time = 35;   break;
      case 11..15:   max_time = 30;   break;
      case 16..20:   max_time = 25;   break;
      case 21..25:   max_time = 20;   break;
      case 26..30:   max_time = 15;   break;
      case 31..5000: max_time = 10;   break;
   }
   time = random(max_time)+1;
   input_to("stop_hunt",0, TP);
   call_out("emote_fun", 10, TP);
   call_out("fin_hunt", time, TP);
   return 1;
}

int stop_hunt(string str, object who){
    remove_call_out("emote_fun");
    remove_call_out("fin_hunt");
    write("You stop hunting.");
    tell_room(environment(who),who->query_cap_name()+" stops hunting.",who);
    return 1;
}

int emote_fun(object who){
    if((object)who->query_attackers() != ({})) {
	write("Your hunting seems to have been interrupted!\n");
        remove_call_out("fin_hunt");
	return 1;
    }
    tell_room(environment(who), who->query_cap_name()+" is peering and sneaking around as if looking for something.", who);
   switch(random(11)) {
       case 0: tell_object(who,"Surely there is something besides insects "
                  "to scare up!\n");   
           break;
       case 1: tell_object(who,"Was that a snake that just slithered away?\n");
           break;
       case 2: tell_object(who,"Hmm, maybe you should be foraging instead??\n");
           break;
       case 3: tell_object(who,"You see movement out of the corner of your "
                 "eye, or was it just your shadow?\n");
           break;
       case 4: tell_object(who,"Maybe you should sit still and quiet and see "
                  "if the animals will come to you.\n");
           break;
       case 5: tell_object(who,"Don't you hate it when you get outsmarted by "
                 "bunnies and squirrels.\n");
           break;
       case 6: tell_object(who,"Hunting is so much easier if all the game "
                 "hasn't been scared off by your thrashing about.\n");
           break;
       case 7: tell_object(who,"This takes a long time!!\n");
           break;
       case 8: tell_object(who,"Damn, surely there is SOMETHING worthwhile "
               "somewhere here... isn't there??\n");
           break;
       case 9: tell_object(who,"Are you SURE you want to find whatever "
               "might be hiding around here??\n");
           break;
       case 10: tell_object(who,"You know, maybe you should be worried "
                  "about how dangerous the game you locate might be.\n");
           break;
   }
call_out("emote_fun", 8, who);
return 1;
}

int fin_hunt(object who){
  int wis, intel, prof, diff, terrain_type;
  string terrain, msg0, msg1;
  object mon;
  remove_call_out("emote_fun");
  prof = who->query_skill("survival")+roll_dice(1,20);
  terrain = environment(who)->query_terrain();
  terrain_type = TERRAIN_GROUPS[terrain];
  switch(terrain_type) {
     case 0 :	msg0 = "Not many game animals around here for some reason.";
		diff = 5;	    	break;
     case 1 :	msg0 = "There is plenty of cover for all sorts of game here.  "
                       "Are you just inept at hunting?";
		diff = 1;	break;
     case 2 :	msg0 = "There should at least be snakes, birds, bunnies, or "
                       "something here... should you just forage for roots?";
		diff = 3;	break;
     case 3 :	msg0 = "It may not be ideal, but there is bound to be some sort "
                       "of game around here... somewhere.";
		diff = 5;	break;
     case 4 :	msg0 = "Will the alligators or snakes get you before you "
                       "find them....";
                msg1 = " gets filthy and wet poking around in the slimy water."; 
     		diff = 10;	break;
     case 5 :	msg0 = "Well, most animals have to eat too.  Did you really "
                       "expect to find much game in an area this barren?";
     		diff = 15;	break;
     case 6 :	msg0 = "Ice and snow... maybe there are snow bunnies or "
                       "wolves here somewhere.  Maybe you can even find them "
                       "before you freeze to death.";
                msg1 = " shivers from skulking around in the snow and ice.";
     		diff = 15;	break;
     case 7 : 	msg0 = "Let's see... mushrooms, fungus, bugs, spiders.  There "
                       "should at least be snakes, rats, or bats around here.";
     		diff = 10;	break;
     case 8 : 	msg0 = "You might have better luck trying to fish, but maybe "
     		       "there are snakes, frogs, or such around to hunt.";
     		diff = 12;	break;
     case 9 :	msg0 = "What do you expect to find in a civilized area "
                       "except maybe vermin?";
     		diff = 18;	break;
     case 10:	msg0 = "Let's see, inside a building... what kind of hunter "
		       "goes hunting indoors, even rats or bats?";
                msg1 = " looks pretty foolish trying to hunt game indoors."; 
		diff = 20;	break;
   }
  msg0 = msg0+"\nIt looks like you need to be stealthier or look elsewhere.";
  if(!msg1)  msg1 = " stops hunting and looks disappointed.";

  if(prof < (diff*2)) { 
    tell_object(who,msg0);
    tell_room(environment(who),who->query_cap_name()+msg1,who);
    destruct(TO);
    return 1;
  }
  pick_mons(who, diff);
  destruct(TO);
  return 1;
}

int pick_mons(object who, int diff) {
  int prof, terrain_type;
  object mon;
  int hunted;
  string terrain, what;
  string *list1, *list2;
  if(!objectp(who) || !objectp(environment(who)) )  return 0;
  terrain = environment(who)->query_terrain();
  if(avatarp(who))  
     write("For ref. for immortals the terrain is:  "+identify(terrain));
  prof = who->query_skill("survival")+roll_dice(1,20);

  terrain_type = TERRAIN_GROUPS[terrain];
// arrays to randomize from, put them in more than once to increase chance?
  switch(terrain_type) {
    case 1 :	// forest, jungle, savannah
       list1 = ({"squirrel", "fowl", "fowl", "rabbit", "rabbit", "badger", "weasel", "fox" });
       list2 = ({"bear", "deer", "elk", "boar", "fox", "lynx", "wolf", "sloth", "wolverine" });
       break;
    case 2 :	// meadows, garden, grassland, cemetery
	list1 = ({"squirrel", "rabbit", "rabbit", "fowl", "fowl", "badger", "groundhog", "prairie dog" });
	list2 = ({"fox", "fox", "weasel", "deer", "deer", "bison", "antelope", "coyotte" });
	break;
    case 3 :	// mountains
        list1 = ({"mountain goat", "weasel", "rabbit", "fowl", "fowl" }); 
        list2 = ({"bear", "bear", "deer", "lynx", "wolf", "wolf", "bobcat", "bobcat", "elk", "mink", "wolverine", "puma", "puma" });
        break;
    case 4 :	// swamp, marsh
	list1 = ({"water snake", "turtle", "fowl", "fowl", "snake" });
	list2 = ({"boar", "alligator", "boar", "fowl", "crocodile" });
 	break;
    case 5 : 	// rocky, barren, desert
	list1 = ({"snake", "snake", "rat" });
	list2 = ({"armadillo", "jackrabbit" });
    	break;
    case 6 : 	// snow, ice, glacier
	list1 = ({"wolf", "wolf", "walrus", "rabbit", "seal", "fowl" });
	list2 = ({"caribou", "moose", "reindeer", "polar bear", "mammoth", "walrus"});
	break;
    case 7 :	// caves, tunnels
    	list1 = ({"bat", "snake", "rat" }); 
    	list2 = ({"bear", "mountain lion", "bobcat", "giant bat" }); 
	break;
    case 8 : 	// shore, beach, shallow water
	list1 = ({"water snake", "frog", "turtle" });
	list2 = ({"snapping turtle", "otter", "beaver", "giant frog" });
	break;
    case 9 :  	// city, village
    	list1 = ({"rat", "rat", "bat", "snake" });
    	list2 = ({"rat", "rat", "bat", "snake" });
	break;
    case 10: 	// inside buildings
	list1 = ({"rat", "rat", "rat", "bat", "snake" });
    	list2 = ({"rat", "rat", "rat", "bat", "snake" });
	break;
    default:  	
	list1 = ({"rat", "rat", "rat", "bat", "snake", "snake" });
    	list2 = ({"rat", "rat", "rat", "bat", "snake", "snake" });
    break;
  }
  if(random(prof) < (5 + (prof/3)))	what = list1[random(sizeof(list1))];
      else 				what = list2[random(sizeof(list2))];
  mon = new("/cmds/mortal/hunted_mon");
  mon->do_desc(what, prof);
//  hunted = ({});   // not sure if I need this
  hunted = who->get_static("hunted monsters");
//  hunted -= ({0});  // per Garrett's suggestion to get rid of any that are now 0's
  hunted ++;
  who->set_static( "hunted monsters", hunted );
  mon->move(environment(who));
  tell_room(environment(who),who->query_cap_name()+" scares up "
              +mon->query_short()+".",who);
  tell_object(who,"%^BOLD%^You manage to scare up "+lower_case(mon->query_short())+
                  " to try to kill!\n");
}

int help(){
   write(
@STYX
   Syntax: <hunt>
   
   This command allows those who are skilled in survival to locate game to hunt and kill for sport or the skins, etc.  Obviously you will be more successful in some areas than others and the type of game found will differ by the terrain.  You do need to kill the animal(s) you find to benefit of course.  The type and challenge/value of the mobs you manage to find will shift as you improve also.

Success rate and time required are also improved by higher levels in the skill but are also affected by the terrain.

see also:  forage, skills
STYX
   );
   return 1;
}
