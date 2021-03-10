#include "/d/dagger/aketon/short.h"
#include <move.h>

#define ITEM_SAVE "/d/save/aketon/1three1a"

inherit ROOM;

string trident_owner;

void create() {
   ::create();

   trident_owner = "";
   restore_me(ITEM_SAVE);
   if(!trident_owner)
      trident_owner = "";
   save_me(ITEM_SAVE);

   if(query_light())
      remove_property("light");
   set_property("light",1);
   set_short("Upon a beam");
   set_long("%^GREEN%^Upon a beam%^RESET%^
You are now crawling upon a beam which lays horrizontally on two large "
      "columns. It is so high that you cannot see clearly what is down "
      "there in the room.");
   set_items( (["cover":"A cover approximately the length of the beam.",
       "beam":"You notice a cover with a knob over the beam's upper side.",
       "columns":"They are large and some semicircular depressions are "
       "carved on them forming a trigonometric pattern.",
       "knob":"A small knob for you to get a hold of the cover."]) );
   set_property("no teleport",1);
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city coming from beneath "
      "you.");
   set_exits( (["floor":RPATH1+"1three1"]) );
   set_pre_exit_functions( ({"floor"}),({"floor_func"}) );
   set_heart_beat(1);
}

int floor_func() {
   tell_object(TP,"You climb down the beam using the column.");
   tell_room(ETP,TPQCN+" climbs down the beam.",TP);
   if( random(20) > TP->query_stats("dexterity") ) {
      tell_object(TP,"Ouch! You failed to hold onto one depression and "
         "fall heavily on the floor!");
      tell_room(ETP,"ACK! "+TPQCN+" falls as "+TP->query_objective()+
         "failed to grab a hold!",TP);
      TP->do_damage( "torso",roll_dice(4,TP->query_level()) );
      return 1;
   }
   return 1;
}

void init() {
   ::init();
   add_action("lift_func","lift");
   add_action("sneak_func","sneak");
   add_action("stand_func","stand");
   add_action("fall_func","stab");
   add_action("fall_func","crit");
   add_action("fall_func","steal");
   add_action("fall_func","pp");
   add_action("fall_func","hide_in_shadows");
   set_heart_beat(1);
}

int sneak_func(string str) {
   tell_object(TP,"Sneak on a beam!? Nuts??");
   return 1;
}

int stand_func(string str) {
   tell_object(TP,"As you stand up, you lost your balance and falls!");
   tell_room(ETP,TPQCN+" stands up, but "+TP->query_objective()+"lost "+
      TP->query_possessive()+" balance and falls from the beam!",TP);
   TP->move_player(RPATH1+"1three1");
   TP->do_damage( "torso",roll_dice(4,TP->query_level()) );
   return 1;
}

int lift_func(string str) {
   object obj;
   if(!str || str != "cover") {
      notify_fail("You cannot lift that!\n");
      return 0;
   }
   if(trident_owner == "") {
      obj = new(AOPATH+"mithril_trident");
      if(obj->move(TP) == MOVE_OK) {
         write("As you lift the cover, you find a strange trident within "
            "the hidden chamber!");
         obj->move(TP);
         obj->log_func("get");
         save_me(ITEM_SAVE);
         return 1;
      }
      else {
         write("You find a trident within the hidden chamber but you "
            "cannot carry that much!");
         return 1;
      }
   }
   else {
      write("You find nothing special in the hidden chamber.");
      write("%^MAGENTA%^A voice whispers to you: %^RESET%^"+
         capitalize(trident_owner)+" took the artifact.");
      return 1;
   }
   return 1;
}

int fall_func(string str) {
   tell_object(TP,"You lost balance and fall as you try to do that!");
   tell_room(ETP,TPQCN+" suddenly lost balance and falls off!",TP);
   TP->move_player(RPATH1+"1three1");
   TP->do_damage( "torso",roll_dice(4,TP->query_level()) );
   return 1;
}

void heart_beat() {
   string *ppl,*att;
   int i;
   ppl = all_inventory(TO);
   for(i = 0;i < sizeof(ppl);i++) {
      if( !userp(ppl[i]) )
         break;
      att = ppl[i]->query_attackers();
      if( att != ({}) ) {
         tell_object(ppl[i],"You lost balance and fall off the beam as "
            "you try to engage in combat!");
         tell_room(TO,ppl[i]->query_cap_name()+" suddenly lost balance "
            "and falls off the beam!",ppl[i]);
         ppl[i]->move_player(RPATH1+"1three1");
         ppl[i]->do_damage( "torso",roll_dice(4,ppl[i]->query_level()) );
      }
   }
}

string query_trident_owner() {
   return trident_owner;
}

void register_item(string item,string who) {
   if(item == "trident")
      trident_owner = who;
   save_me(ITEM_SAVE);
}

void reset_item(string item) {
   if(item == "trident")
      trident_owner = "";
   save_me(ITEM_SAVE);
}
