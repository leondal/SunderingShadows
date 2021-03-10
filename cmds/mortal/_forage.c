/* _forage.c for NWPs - based on original /cmds/mortal/_hunt.c  
   Was to allow people to gather food while away from normal food sources
   By *Styx*  7/2002
   Added to use terrain type, hunt for game and fishing are separate
   Quality of food & speed improves with skill
Setting trainers as:
/d/newbie/mon/doran (level 5)
/d/tharis/conforest/mons/deladrenia (flower/herbalist lady) 
   - use her for the herbalist later too?
/d/antioch/antioch2/mons/andy.c (ration store guy)
/d/laerad/mon/sage (the one who moves around in parnelli, set to level 15)
/d/dagger/road/mon/elranglead
/d/islands/tonerra/mon/chumba (tonerra food storage, level 20)

*/

#include <std.h>
#include <daemons.h>
#include <move.h>

inherit DAEMON;

int create_food(object who, int diff);
void food(object ob, string which);

// herbalism functions
void pick_herb(object player);

int cmd_forage(string str){
   int max_time, time, i, reps;
   int success, prof;

   if((object)TP->query_attackers() != ({})) {
     notify_fail("Get real, not while fighting!\n\n");
     return 0;
   }
   if(TP->query_bound()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(TP->query_blind()) {
      notify_fail("Sorry, I don't think you'll find anything while blinded.");
      return 1;
   }
/* I always kind of liked this message, but caves and such should be foragable.
if(environment(TP)->query_property("indoors")) {
     tell_room(ETP, TPQCN+" wants to make rock soup.",TP);
     notify_fail("Rocks, hmm, could make rock soup .... but not on this mud!\n");
     return 0;
   }
*/ 
   prof = TP->query_skill("survival")+roll_dice(1,20);
   if(TP->query_blind()) prof = 0;
   if(!str || (str != "for food" && str != "for herbs")) {
      notify_fail("Please specify <forage for herbs> or <forage for food>?\n");
      return 0;
   }
// Once herbs are implemented, the real stuff needs to move down with the
// food-related stuff after the NWP is performed, etc. (I think)  *Styx*
  // if(str == "for herbs") {
  //    notify_fail("Sorry, foraging for herbs is not implemented yet.\n");
  //    return 0;
  // }
   if(!TP->query_time_delay("forage",20)) {
      write("You need more time to study the area before you try again.");
      return 1;
   }
   TP->set_time_delay("forage");
// moved the perform nwp to the finish step so they can't start and just quit
// and still get the exp.
   switch(prof) {
      case 0..5 :    max_time = 60;   break;
      case 6..10 :   max_time = 55;   break;
      case 11..15:   max_time = 50;   break;
      case 16..20:   max_time = 40;   break;
      case 21..25:   max_time = 30;   break;
      case 26..30:   max_time = 20;   break;
      default:       max_time = 10;   break;
   }
   time = random(max_time)+1;

   if(str == "for food") {
      tell_room(ETP,TPQCN+" starts foraging for some food.",TP);
      write("You start foraging for food.\nRemember:  it might be poisoned.\n");

     input_to("stop_hunt",0, TP);
     call_out("emote_fun", 10, TP);
     call_out("fin_hunt", time, TP);
     return 1;
   }


   if(str == "for herbs")
   {
       tell_room(ETP,TPQCN+" starts foraging for herbs.",TP);
       tell_object(TP,"You start foraging for herbs.  Hopefully they grow around here.");

       input_to("stop_hunt",0,TP);

       call_out("herb_emotes",10,TP);
       call_out("finished_herbing",time,TP);
       return 1;
   }

   return 1;
}

int stop_hunt(string str, object who){
    remove_call_out("emote_fun");
    remove_call_out("fin_hunt");
    remove_call_out("herb_emotes");
    remove_call_out("finished_herbing");
    write("You stop foraging.  Not that desperate after all eh?");
    tell_room(environment(who),who->query_cap_name()+" stops foraging.",who);
    return 1;
}

int emote_fun(object who){
    if((object)who->query_attackers() != ({})) {
	write("Your foraging seems to have been interrupted!\n");
        remove_call_out("fin_hunt");
	return 1;
    }
    tell_room(environment(who), who->query_cap_name()+" appears to be poking around looking for something.", who);
    switch(random(11)) {
       case 0: tell_object(who,"Bugs and snails shouldn't be THIS hard to "
                  "catch!\n");
           break;
       case 1: tell_object(who,"You just missed one there.  Bloody leaves.\n");
           break;
       case 2: tell_object(who,"Hmm are these mushrooms edible??\n");
           break;
       case 3: tell_object(who,"Okay even when foraging for snails, try "
                 "to SURPRISE them.\n");
           break;
       case 4: tell_object(who,"If worse comes to worst maybe you CAN "
                  "eat dandelions.\n");
           break;
       case 5: tell_object(who,"I hate it when I get outsmarted by insects "
                 "and arachnids.\n");
           break;
       case 6: tell_object(who,"Foraging is so much easier if there is "
                 "actually something edible around.\n");
           break;
       case 7: tell_object(who,"This takes a long time!!\n");
           break;
       case 8: tell_object(who,"Damn, surely there is SOMETHING worthwhile "
               "somewhere here... isn't there??\n");
           break;
       case 9: tell_object(who,"I want food, I want it now!!\n");
           break;
       case 10: tell_object(who, "Maybe you want to settle for rock soup?\n");
	   break;
   }
call_out("emote_fun", 8, who);
return 1;
}

int fin_hunt(object who){
  int wis, intel, prof, diff, terrain_type;
  string terrain, msg0, msg1;
  remove_call_out("emote_fun");
  prof = who->query_skill("survival")+roll_dice(1,20);
  terrain = environment(who)->query_terrain();
  terrain_type = TERRAIN_GROUPS[terrain];
  switch(terrain_type) {
     case 0 :	msg0 = "Pickings seem to be a little slim here.";
		diff = 5;	    	break;
     case 1 :	msg0 = "This area should be full of nuts and berries at the "
                       "least.  Are you just inept at foraging?";
		diff = 0;	break;
     case 2 :	msg0 = "There is enough plantlife around that surely you can "
                       "find something if you have a clue what to look for.";
		diff = 1;	break;
     case 3 :	msg0 = "It may not be ideal, but there is bound to be something "
                       "edible around here... somewhere.";
		diff = 3;	break;
     case 4 :	msg0 = "Surely you can find snails or slugs or SOMETHING even "
                       "here.  Are you sure you want to that badly though?";
                msg1 = " gets filthy and wet poking around in the slimy water."; 
     		diff = 7;	break;
     case 5 :	msg0 = "Not much vegetation now is there?  So are you really "
                       "hungry enough to eat roots or bugs?";
     		diff = 7;	break;
     case 6 :	msg0 = "Ice and snow... maybe if you dig deep enough and are "
                       "really good at this you'll find something... maybe "
                       "even before you freeze to death.";
                msg1 = " shivers from digging around in the snow and ice.";
     		diff = 9;	break;
     case 7 : 	msg0 = "Let's see... mushrooms, fungus, bugs, spiders.  Sure, "
                       "there ought to be something edible here somewhere.";
     		diff = 6;	break;
     case 8 : 	msg0 = "Surely there are mussels, seaweed, or clams here if "
     		       "you know how to find them and what's edible.";
     		diff = 5;	break;
     case 9 :	msg0 = "Digging through the trash in the streets?";
     		diff = 8;	break;
     case 10:	msg0 = "Looks like the cupboards are bare, or are you inept "
			"at even finding household leftovers?";
		diff = 2;	break;
     case 11:	msg0 = "Looks like you cleaned up well or the rats ate it all.";
		diff = 6;	break;
   }
  msg0 = msg0+"\nIt looks like you need to look harder or elsewhere.";
  if(!msg1)  msg1 = " stops foraging and looks disappointed.";
//this does need to be down here so the diff. gets set even if don't need msgs.
  if(prof < (random(20)+(diff*2)) ) { 
//  roll = random(20)+1;   if(wis < roll) {   <<<<<< it was....
    tell_object(who,msg0);
    tell_room(environment(who),who->query_cap_name()+msg1,who);
    destruct(TO);
    return 1;
  }
  tell_room(environment(who),who->query_cap_name()+" seems to find something.",who);
  tell_object(who,"You manage to find some food you hope to be good.\n");
  create_food(who, diff);
  destruct(TO);
  return 1;
}

int create_food(object who, int diff) {
  int prof, terrain_type, filling;
  object ob;
  string terrain;
  if(!objectp(who) || !objectp(environment(who)) )  return 0;
  terrain = environment(who)->query_terrain();
  if(avatarp(who))  
     write("For ref. for immortals the terrain is:  "+identify(terrain));
  prof = who->query_skill("survival")+roll_dice(1,20);
  ob = new("std/food");
  ob->set_name("food");  //this needs to be before the set_mess stuff

  terrain_type = TERRAIN_GROUPS[terrain];
  switch(terrain_type) {
    case 1..2 :	
	switch(random(9)) {
	  case 0..2:  food(ob, "berries");	break;
	  case 3..4:  food(ob, "nuts");		break;
	  case 5..6:  food(ob, "fruit");	break;
	  case 7:  food(ob, "snails");		break;
	  case 8:  food(ob, "mushrooms");	break;
	}
	break;
    case 3 :
        switch(random(7)) {
          case 0..1:  food(ob, "roots");	break;
	  case 2..3:  food(ob, "berries");	break;
	  case 4:  food(ob, "nuts");		break;
	  case 5:  food(ob, "snails");		break;
          case 6:  food(ob, "bugs");		break;
        }
        break;
    case 4 :
        switch(random(3)) {
           case 0:  food(ob, "snails");		break;
 	   case 1..2:  food(ob, "bugs");	break;
 	}
 	break;
    case 5 : 
        switch(random(3)) {
           case 0:  food(ob, "roots");		break;
 	   case 1:  food(ob, "nuts");		break;
 	   case 2:  food(ob, "bugs");		break;
 	}
 	break;
    case 6 : 
       switch(random(3)) {
          case 0..1:  food(ob, "roots");	break;
	  case 2:     food(ob, "nuts");		break;
       }
       break;
    case 7 :
       switch(random(4)) {
          case 0:  food(ob, "roots");		break;
          case 1:  food(ob, "fungus");		break;
          case 2:  food(ob, "snails");		break;
          case 3:  food(ob, "mushrooms");	break;
       }
       break;
    case 8 :  food(ob, "shellfish");		break;
    case 9 :  food(ob, "junk");			break;
    case 10: 
       switch(random(7)) {
          case 0:  food(ob, "leftovers");	break;
          case 1:  food(ob, "nuts");		break;
          case 2:  food(ob, "fruit");		break;
          case 3:  food(ob, "berries");		break;
          case 4:  food(ob, "roots");		break;
          case 5:  food(ob, "bugs");		break;
          case 6:  food(ob, "junk");		break;
       }
       break;
    case 11: 
       switch(random(5)) {
          case 0:  food(ob, "junk");		break;
          case 1:  food(ob, "bugs");		break;
          case 2:  food(ob, "leftovers");	break;
          case 3:  food(ob, "fungus");		break;
          case 4:  food(ob, "snails");		break;
       }
       break;
       
    default:  food(ob, "roots");		break;
  }
   filling = random(15) - random(6) + ((prof - diff)/2);  
 // was (rand 16 - 19 plus wisdom 
   ob->set_strength(filling);
   if(filling <  0 ) {
      ob->set_poison(-filling/2);
      ob->set_your_mess("starts to vomit from the bad food.");
      ob->set_my_mess("You feel sick and then start to vomit.  The food must have been poisoned.");
   }      
   ob->set_value(0);
   ob->set_destroy();
   ob->set_weight(1);
   if((int)ob->move(who) != MOVE_OK) ob->move(environment(who));
}

void food(object ob, string which) {
  switch(which) {
    case "berries" :
	ob->set_short("handful of berries");
	ob->set_id(({"food", "berries"}));
	ob->set_long("A handful of nice, edible looking berries");
	ob->set_your_mess("enjoys a handful of berries.");
	ob->set_my_mess("You eat the berries eagerly.");
	break;
   case "nuts":
	ob->set_short("handful of nuts");
	ob->set_id(({"food", "nuts"}));
	ob->set_long("A handful of small but edible looking nuts.");
	ob->set_your_mess("enjoys a few crunchy nuts.");
	ob->set_my_mess("The nuts crunch as you eat them.");
	break;
   case "fruit":
	ob->set_short("some fruit");
	ob->set_id(({"food", "fruit"}));
	ob->set_long("A nice juicy looking fruit from a nearby tree.");
	ob->set_your_mess("seems to enjoy the tasty fruit.");
	ob->set_my_mess("The fruit is just sweet enough to be delicious.");
	break;
   case "snails":
	ob->set_short("some snail meat");
	ob->set_id(({"food", "snail meat", "snail", }));
	ob->set_long("The meat from a couple of nice plump snails.");
	ob->set_your_mess("gags a little as the snail meat slides down.");
	ob->set_my_mess("You gag a little but manage to gulp down the "
	                 "snail meat.");
	break;
   case "roots":
	ob->set_short("some edible looking roots");
	ob->set_id(({"food", "roots"}));
	ob->set_long("A few roots with the dirt and surface cleaned off "
	             "that look reasonably edible.");
	ob->set_your_mess("gnaws on the roots hungrily.");
	ob->set_my_mess("You pick some stringy bits of root from your teeth.");
	break;
   case "bugs":
	ob->set_short("%^BOLD%^%^BLACK%^A few (dead) insects%^RESET%^");
	ob->set_id(({"food", "bugs", "insects"}));
	ob->set_long("Some dead insects that would be good protein... if "
	             "you're that hungry that is.");
	ob->set_your_mess("gulps down the insects and swallows hard.");
	ob->set_my_mess("You gulp down the insects and swallow hard.");
	break;
   case "fungus":
	ob->set_short("%^ORANGE%^An edible looking fungus%^RESET%^");
	ob->set_id(({"food", "fungus"}));
	ob->set_long("%^ORANGE%^A dry, brownish fungus that looks like "
	             "it might be edible.");
	ob->set_your_mess("chews on the fungus slowly.");
	ob->set_my_mess("You chew on the fungus slowly.");
	break;
   case "mushrooms":
	ob->set_short("%^ORANGE%^A plump mushroom%^RESET%^");
	ob->set_id(({"food", "mushroom"}));
	ob->set_long("%^ORANGE%^A nicely plump and edible looking "
	             "mushroom.");
	ob->set_your_mess("gulps the mushroom down hungrily.");
	ob->set_my_mess("You gulp the mushroom down hungrily.");
	break;
   case "shellfish":
	ob->set_short("A healthy looking shellfish");
	ob->set_id(({"food", "shellfish"}));
	ob->set_long("A nice chunk of shellfish, right out of the shell.");
	ob->set_your_mess("slurps the shellfish down.");
	ob->set_my_mess("The shellfish slides right down.");
	break;
   case "leftovers":
	ob->set_short("Someone's leftover food");
	ob->set_id(({"food", "leftover", "leftovers"}));
	ob->set_long("Some cold but tasty looking leftovers.");
	ob->set_your_mess("nibbles at the cold food.");
	ob->set_my_mess("You nibble at the leftovers.");
	break;
   case "junk":
	ob->set_short("Scraps of discarded food");
	ob->set_id(({"food", "scraps", "leftovers"}));
	ob->set_long("Some scraps of discarded food.  Maybe some of it is "
	             "still edible.");
	ob->set_your_mess("picks at the edible looking bits of the scraps.");
	ob->set_my_mess("You pick at the edible looking bits of the scraps.");
	break;
   }
   return;
}   
   
   

int help(){
   write(
@STYX
   Syntax: <forage for> [food] 
                    or  [herbs] 

   This command allows you to forage for food, more successfully in some areas than others.  It helps reduce the amount of food you need to carry, trips to civilization  for meals, or eating clerical food.  Do remember that the food might be poisoned.

Success rate, time required, and how edible(**) it will be are improved by higher levels in the survival skill, but are also affected by the terrain.  **We do expect some to be glad to find snails or fungus and others to be revolted by those.  Some races might eat almost anything, some would be thrilled to find nuts or berries, while others might strongly dislike anything besides meat, i.e. think RP as well as convenience.

Note:  Forage for herbs is available to those with the herbalism NWP.  Those herbs will have various uses to those with that NWP.
STYX
   );
   return 1;
}





/// ******************************************
/// Herbalism Stuff


void herb_emotes(object player)
{
    if(!objectp(player) || sizeof(player->query_attackers()))
    {
        remove_call_out("finished_herbing");
        return 1;
    }


    tell_room(environment(player),player->QCN+" appears to be poking around looking for something.",player);

    switch(random(10))
    {
    case 0: tell_object(player,"You carefully inspect the terrain."); break;
    case 1: tell_object(player,"You pull on the leaves of a few plants, but they aren't the right kind."); break;
    case 2: tell_object(player,"You begin collecting a few samples that look promising.  Maybe you'll find something here yet."); break;
    case 3: tell_object(player,"Is there really anything useful here?"); break;
    case 4: tell_object(player,"A tightly bundled wad of plants catches your eye!"); break;
    case 5: tell_object(player,"Ouch!  Something just bit the end of your finger!"); break;
    case 6: tell_object(player,"What's that over in the distance?  Could it be exactly what you're looking for?"); break;
    case 7: tell_object(player,"By the gods, there are so many plants to make herbs from!"); break;
    case 8: tell_object(player,"Just a few more like this, and you'll really have something!"); break;
    case 9: tell_object(player,"Dried flowers, these should be useful."); break;
    }

    call_out("herb_emotes", 8, player);
    
    return 1;
}


int finished_herbing(object player)
{
    string *bad_terrains=({"city","village","stone building","wood building","hut","boats",
        "built cave","built tunnel","glacier","barren","deep water","ice"});

    int skill_level, i;
    string terrain;

    if(!objectp(player)) { return 1; }

    remove_call_out("herb_emotes");
    skill_level = (int)player->query_skill("survival") + roll_dice(1,20);

    skill_level = (skill_level / 5) + 1;

    terrain = environment(player)->query_terrain();

    if(member_array(terrain,bad_terrains) != -1)
    {
        tell_object(player,"You can't seem to find any herbs here.");
        tell_room(environment(player),""+player->QCN+" gives up the search.",player);
        destruct(TO);
        return 1;
    }


    if(skill_level > 0)
    {
        tell_object(player,"You find a few plants that you think you can use.");
        tell_object(player,"You carefully prepare the herbs and put them into "
            "pouches.");

        tell_room(environment(player),""+player->QCN+" finds several plants and begins "
            "to prepare them and put them into pouches.",player);
        
        for(i=0;i<skill_level;i++)
        {
            pick_herb(player);
        }
    }

    destruct(TO);
    return 1;
}

void pick_herb(object player) {
    if(!objectp(player)) return;
    new("/d/common/obj/brewing/herb_inherit")->move(environment(player));
    return 1;
}