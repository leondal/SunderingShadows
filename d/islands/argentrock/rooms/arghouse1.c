#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit ROOM;

int lever_found,kronibus_avai,fernibus_avai,flag;

void create() {
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set("short","%^RED%^Dark chamber");
   set("long","%^RED%^Dark chamber
%^RESET%^%^CYAN%^You have entered a hidden chamber behind the shelves in the study. There is not much here and there is no light. You can barely see a pile of %^WHITE%^bone%^BOLD%^%^WHITE%^s%^RESET%^%^CYAN%^ and skulls at the corner of the chamber. On the %^BOLD%^%^BLUE%^w%^CYAN%^alls%^RESET%^%^CYAN%^ around you, there are %^BOLD%^%^CYAN%^mark%^BLUE%^s%^RESET%^%^CYAN%^ of a strange nature.%^RESET%^
");
   set_property("indoors",1);
   set_property("light",0);
   set_property("no teleport",1);
   set_listen("default","You hear your heart beating rapidly like a "+
      "hopping bunny.");
    set_smell("default","Smells of rotten meat fill your nostrils.");
   set_items( (["lever": (: TO, "lever_vis" :),
      ({"walls","marks"}):"As you look close at the marks, you realize "+
      "that it is the scratching of some fierce beast.",
       ({"bones","skulls","pile"}):"A large pile of humanoids bones. "+
       "You feel a chill run up your spine."
   ]) );
   set_search("pile", (: TO, "search_pile" :) );
   set_search("bones", (: TO, "search_pile" :) );
   kronibus_avai = 1;
   fernibus_avai = 1;
   lever_found = 0;
}

void search_pile() {
   if(kronibus_avai != 0) {
       write("As you search the pile, a monster arises from the bones!");
       say("As "+TPQCN+" searches the pile and a monster arises from the "+
         "bones!");
      new(MON"kronibus")->move(TO);
      kronibus_avai--;
   }
   else if(fernibus_avai != 0) {
       write("As you search the pile, another monster rarises from the "+
         "bones!");
       say("As "+TPQCN+" searches the pile, another monster arises from "+
         "the bones!");
      new(MON"fernibus")->move(TO);
      fernibus_avai--;
   }
   else {
      if(!present("skeletal warrior")) {
         write("You find a lever hidden within the pile of bones.");
         say(TPQCN+" finds a lever hidden within the pile of bones.");
         lever_found = 1;
      }
      else {
         write("The skeletal warrior won't allow you!");
      }
   }
}

void init() {
   ::init();
   add_action("pull_lever","pull");
   add_action("no_offer","offer"); //To prevent accidentally trapping players, 4 Dec 19, Uriel
   add_action("no_offer","offerall"); //To prevent accidentally trapping players, 4 Dec 19, Uriel
   add_action("no_bury","bury"); //To prevent accidentally trapping players, 4 Dec 19, Uriel
}

int no_offer(string str) {
   write("You may not offer anything to the gods in this place.");
   return 1;
} // Added this function to prevent accidental trapping of players, 4 Dec 19, Uriel
 
int no_bury(string str) {
   write("You may not bury corpses in this place.");
   return 1;
} // Added this function to prevent accidental trapping of players, 4 Dec 19, Uriel
 
int pull_lever(string str) {
   if(!str) {
      notify_fail("Pull what?\n");
      return 0;
   }
   if(str == "lever") {
      if(lever_found == 0) {
         notify_fail("Hmm.. where is the lever?\n");
         return 0;
      }
      else if(present("kronibus")) {
         write("Kronibus the Skeletal Warrior won't allow you to "+
            "touch it!");
         say("As "+TPQCN+" tries to pull the lever, Kronibus stands "+
            "in "+TP->query_possessive()+" way!");
         return 1;
      }
      else if(present("fernibus")) {
         write("Fernibus the Skeletal Warrior won't allow you to "+
            "touch it!");
         say("As "+TPQCN+" tries to pull the lever, Fernibus stands "+
            "in "+TP->query_possessive()+" way!");
         return 1;
      }
      else if( !present("corpse of kronibus the skeletal warrior") ||
         !present("corpse of fernibus the skeletal warrior") ) {
         notify_fail("You are not powerful enough to pull the lever, "+
            "you need a longer arm!\n");
         return 0;
      }
      else {
         write("You pick up a femur of the lifeless skeleton and "+
            "use it as the arm of the lever.\nYou pull the lever "+
            "with full strength.\nSuddenly the room shakes, the wall "+
            "behind you turns and a way out appears.");
         say(TPQCN+" pick up the femur of the lifeless skeleton and "+
            "uses it as the arm of the lever.\n"+TPQCN+" then pulls "+
            "the lever with full strength.\nSuddenly the room shakes"+
            ", the wall behind "+TP->query_objective()+" turns and a "+
             "way out appears.");
         add_exit(PATH+"arghouse2","out");
         add_pre_exit_function("out","lock_it");
         return 1;
      }
   }
   else {
      notify_fail("You can't pull that!\n");
      return 0;
   }
}

int lock_it() {
   if(!flag) {
       write("%^BOLD%^RED%^As you walk passed the exit, the wall starts to "+
         "turn and shut.");
       say("%^BOLD%^RED%^As "+TPQCN+" walks passed the exit, the wall "+
         "starts turn and shut.");
      call_out("reset",15);
      flag = 1;
   }
   return 1;
}

string lever_vis(string str) {
   if(lever_found)
      return "A lever similar to the one you found in the study except "+
         "that this one has a much shorter arm.";
   else
      return "You do not see a lever here!";
}

void reset() {
   ::reset();
   kronibus_avai = 1;
   fernibus_avai = 1;
   lever_found = 0;
   flag = 0;
   if( sizeof( TO->query_exits() ) ) {
      remove_exit("out");
      tell_room(TO,"%^BOLD%^RED%^The wall slowly turns and shuts again.");
   }
}
