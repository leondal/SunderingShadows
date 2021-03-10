#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Half way upon the tree");
   set_long("%^GREEN%^Half way upon the tree%^RESET%^
You have come to the middle portion of the tree. Some large houses were "
      "built around the stairs you are standing on. Branches here are less "
      "dense and you can almost see through the leaves if not blocked "
      "by the houses built on the surroundings. It is much quieter than "
      "the lower levels of this city. A sign is hanging on the horizontal "
      "beam above your head. Four large columns supports the roof. The "
       "passage leads east and west. And the stairway continues to lead up "
      "and down.");
   set_items( (["branches":"Large branches of the tree which extends to "
      "all direction.",
        "leaves":"Umm... without these the tree will die sooner or longer.",
       "houses":"Some houses are built around you. Looks like they are "
       "connected together by some corridors.",
       "sign":"Aketon Elder Quarter\n\nNo trespassing is allowed.\nReturn "
       "before it is too late.\nTrespasser will be killed!",
       "beam":"A supporting beam above your head reseting ontop of the "
       "large columns. It is placed there quite strange.",
       "columns":"They are large and some semicircular depressions are "
       "carved on them forming a trigonometric pattern.",
       "depressions":"They form a beautiful trigonometirc pattern and "
       "each of them are large enough allowing you to put your feet into "
       "it.",
       "stairway":"The stairs you used. It leads up and down from here.",
       "passage":"It leads east and west into the corridors."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city coming from beneath "
      "you.");
   set_exits( (["up":RPATH1+"1four1",
      "down":RPATH1+"1step5",
      "east":RPATH1+"1three12",
      "west":RPATH1+"1three11"]) );
   set_search("beam","You are not that tall!");
   set_pre_exit_functions( ({"up","east","west","down"}),
      ({"up_func","enter_func","enter_func","down_func"}) );
   find_object_or_load(RPATH1+"1three2");
   find_object_or_load(RPATH1+"1three21");
}

int up_func() {
   object obj;
   if((string)TPQN == "shawdor" || (string)TPQN == "chelspan") return 0;
   if( obj = present("standing guard") ) {
      if( (int)SAVE_D->is_member("aketon_list",TPQN) == -1 ) {
         obj->force_me("say No visitors other than registered citizens!");
         return 0;
      }
      else {
         obj->force_me("say Citizens are welcomed to visit our mayor.");
         return 1;
      }
   }
   return 1;
}

int down_func() {
   if((string)TPQN == "shawdor" || (string)TPQN == "chelspan") return 0;
   return 1;
}

int enter_func() {
   object obj;
   if((string)TPQN == "shawdor" || (string)TPQN == "chelspan") return 1;
   if( obj = present("standing guard") ) {
      if( (int)SAVE_D->is_member("aketon_list",TPQN) == -1 ) {
         obj->force_me("say No visitors other than registered citizens!");
         return 0;
      }
      else {
         obj->force_me("say All citizens are welcomed to visit the "
            "elders.");
         return 1;
      }
   }
   return 1;
}

void init() {
   ::init();
   add_action("climb_func","climb");
   add_action("sneak_func","sneak");
}

int sneak_func(string str) {
   tell_object(TP,"The guards keep watching you!");
   return 1;
}

int climb_func(string str) {
   object mount;
   string *ids;
   if(!str) {
      write("Climb what?\n");
      return 1;
   }
   if(str != "column") {
      write("You cannot climb that!");
      return 1;
   }
   if(present("standing guard")) {
      tell_object(TP,"The guards are watching your action very closely.");
      return 1;
   }
   if( mount = TP->query_in_vehicle() ) {
      ids = mount->query_id();
      TP->force_me("dismount "+ids[0]);
      tell_object(TP,"You decided your mount cannot climb up there.");
   }
   tell_object(TP,"You climb up the column by holding onto the "
      "depressions.");
   tell_room(ETP,TPQCN+" climbs up the column like a monkey!!",TP);
   if( random(20) > TP->query_stats("dexterity") ) {
      tell_object(TP,"Ouch! You failed to hold onto one depression and "
         "fall heavily on the floor!");
      tell_room(ETP,"ACK! "+TPQCN+" falls as "+TP->query_objective()+
         "failed to grab a hold!",TP);
      TP->do_damage( "torso",roll_dice(4,TP->query_level()) );
      return 1;
   }
   TP->move_player(RPATH1+"1three1a");
   return 1;
}

void reset() {
   ::reset();
   if(!present("standing guard")) {
      new(MPATH+"guardD")->move(TO);
      new(MPATH+"guardD")->move(TO);
      new(MPATH+"guardD")->move(TO);
   }
   else if(!present("standing guard 2")) {
      new(MPATH+"guardD")->move(TO);
      new(MPATH+"guardD")->move(TO);
   }
   else if(!present("standing guard 3"))
      new(MPATH+"guardD")->move(TO);
   else
      return;
}
