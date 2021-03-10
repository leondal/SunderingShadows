//updated by ~Circe~ 9/22/19 to current code

#include <std.h>
#include "../ruins.h"
inherit ROOM;

int count;

void create(){
   ::create();
   set_terrain(RUINS);
   set_travel(DIRT_ROAD);
   set_property("indoors",0);
   set_property("light",1);
   set_short("%^BOLD%^%^BLACK%^Desolate Ruins%^RESET%^");
   set_long("This was once the town square. People used to gather here, browsing through the vendor shops and chatting. Most of the street has been completely ripped to pieces, there is not even a clear path through the rubble to the north. The streets here have been scorched completely black, not just in a few places. Splinters of wood from the vendors shops can be found just about everywhere. The center of the battle must have been near here. To the north is a crumbling tower, but you see no way to reach it. It appears that most of the tower collapsed onto the main square. The bricks to the north almost appear to have been purposely stacked, as though they are covering something.");
   set_smell("default","Dust hangs in the air.");
   set_listen("default","The ruins are eerily quiet.");
   set_items(([
      ({"streets","street"}) : "The streets here have been razed by the earthquakes and completely blackened by mage fire. Splinters of wood from the vendor shops that used to occupy this area are all over the place. Huge bricks from the tower have fallen all over the town square, blocking the streets completely in many places.",
      "tower" : "To the north is the remains of what must have once been a large tower. Now it is about two stories in height, and it appears as though the upper portion of the tower collapsed onto the town square, blocking anyone from reaching it.",
      "bricks" : "Several bricks directly to the north have been carefully stacked around something it seems, purposely burying it. If you are strong enough, you might be able to %^BOLD%^unstack%^RESET%^ the bricks.",
   ]));
   set_exits(([
      "south" : ROOMS+"ruins17"
   ]));
   count = 0;
}

void init(){
   ::init();
   add_action("unstack","unstack");
}

void unstack(string str){
   int roll, might, bonus;
   object obj;
//   roll = 10 + roll_dice(2,10);
   roll = roll_dice(1,20) + (int)TP->query_skill("athletics"); 
//   might = TP->query_stats("strength");
//   bonus = TP->query_skill("athletics")/10; //adding a bonus bsed on athletics skill now that it is in game
   bonus = ((int)TP->query_stats("strength")-10)/2 - ((int)TP->query_stats("dexterity")-10)/2; // Athletics + STR bonus - DEX bonus, because Athletics skill already includes DEX but not STR.
   if(bonus < 0) bonus = 0;
//   might += bonus;
   roll += bonus;
   if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!interactive(TP)) return;
   if(!str) { return 0; }
   if(str != "bricks" && str != "brick"){
      tell_object(TP,"Unstack what?\n");
      return 1;
   }
//   if(count > 5){
   if(count > 2){
      tell_object(TP,"All the bricks have been cleared!\n");
      return 1;
   }
// Changed due to imms agreeing there should be no complete cutoff. Lujke June 2008
/*	if(might < 15) {
		tell_object(TP,"You try, but are not strong enough to lift the bricks.");
		tell_room(ETP,""+TP->query_cap_name()+" attempts to move the bricks"+
		" but is not strong enough.",TP);
		TP->set_paralyzed(15,"You are recovering from your efforts.");
		return 1; 
	} 
*/              
      
//   if(might < 15 && roll > might/2){
   if(roll < 10){
      tell_object(TP,"You attempt to move the heavy bricks but fail. This is going to be really hard work for someone as lacking in muscle as you. Maybe you should have worked out more, or made some friends.");
      tell_room(ETP,""+TPQCN+" attempts to move aside the heavy bricks but cannot. Try not to laugh at the weakling.",TP);
// reduce paralyze time to speed things up, 4 Dec 19, Uriel
//        TP->set_paralyzed(20,"You are recovering from your efforts.");
        TP->set_paralyzed(7,"You are recovering from your efforts.");
      return 1;
   }
// End of Lujke's changes
//   if(roll > might){
   if(roll < 13){
      tell_object(TP,"You attempt to move the heavy bricks but fail.");
      tell_room(ETP,""+TPQCN+" attempts to move aside the heavy bricks but cannot.",TP);
// reduce paralyze time to speed things up, 4 Dec 19, Uriel
//        TP->set_paralyzed(15,"You are recovering from your efforts.");
        TP->set_paralyzed(5,"You are recovering from your efforts.");
      return 1;
   }
// reduce brick count to speed things up, 4 Dec 19, Uriel
//   if(count > 4){
   if(count > 1){
      tell_object(TP,"You move aside the last of the heavy bricks.");
      tell_room(ETP,""+TPQCN+" moves aside the last of the heavy bricks.",TP);
      tell_room(ETP,"%^MAGENTA%^A glowing portal is revealed in the floor where the last of the bricks was!%^RESET%^");
      add_exit("/d/antioch/ruins/portal/entrance","portal");
      set_post_exit_functions(({"portal"}),({"GoThroughDoor"}));
//        TP->set_paralyzed(15,"You are recovering from your efforts.");
        TP->set_paralyzed(3,"You are recovering from your efforts.");
      count = count+1;
      add_item("bricks","The pile of bricks has been moved to the side, and there is a bare space on the ground that reveals a portal.");
      add_item("portal","There is a portal in the ground that leads to a strange place. Through the portal you can see a place of fire, smoke, and desolation. It looks dangerous, and you have to wonder if there will be a portal on the other side for you to get back out...");
      return 1;
   }else{
      tell_object(TP,"You exert a great deal of effort and manage to move aside one of the bricks.");
      tell_room(ETP,""+TPQCN+" exerts a great deal of effort and moves aside one of the bricks.",TP);
//        TP->set_paralyzed(15,"You are recovering from your efforts.");
        TP->set_paralyzed(3,"You are recovering from your efforts.");
      count = count+1;
      return 1;
   }
}

int GoThroughDoor(){
   tell_object(TP,"You become incredibly nauseated and disoriented as you jump through the portal.");
   return 1;
}
