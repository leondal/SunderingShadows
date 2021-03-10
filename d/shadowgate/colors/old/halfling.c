#include <std.h>
#include <daemons.h>

inherit ROOM;

int race_set, hair_set, eyes_set, cha, x;
string *possible, *choice, *race;

int pick(string str);
void show_race();
void show_hair();
void show_eyes();

void create() {
    ::create();
    set_property("no teleport",1);
    set_property("indoors",1);
    set_short("");
    set_long("");
    possible = allocate(3);
    choice = allocate(2);
}

void init() {
   if(!interactive(TP)) return;
   cha = TP->query_base_stats("charisma");
   add_action("pick","pick");
   add_action("look_room","look");
   if(cha < 9) x = 0;
   else if(cha > 8 && cha < 16) x = random(3);
   else if(cha > 15) x = random(5);
   switch(cha+x) {
      case 19..30:
         possible = allocate(10);
         choice = allocate(10);
         break;
      case 13..18:
         possible = allocate(8);
         choice = allocate(8);
         break;
      case 0..12:
         possible = allocate(4);
         choice = allocate(4);
         break;
   }
   show_race();
}

void show_race() {
   write("%^BOLD%^%^GREEN%^Please indicate the type of halfling that you would like your character to be (see <help halfling> for more details)");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   write("%^BOLD%^%^GREEN%^   lightfoot halfling");
   write("%^BOLD%^%^GREEN%^   strongheart halfling");
   write("%^BOLD%^%^GREEN%^   ghostwise halfling");
   race = allocate(3);
   race[0] = "lightfoot halfling";
   race[1] = "strongheart halfling";
   race[2] = "ghostwise halfling";
   write("");
   write("Usage:  pick "+race[0]);
   return;
}

void show_hair() {
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like to have for this character.");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from.  Please be reasonable and consider how it fits with the rest of your character.");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch(cha+x) {
      case 19..30:
         write("%^BOLD%^%^GREEN%^   ebony");
         write("%^BOLD%^%^GREEN%^   golden");
         possible[8] = "ebony";
         possible[9] = "golden";
      case 13..18:
         write("%^BOLD%^%^GREEN%^   sable");
         write("%^BOLD%^%^GREEN%^   auburn");
         write("%^BOLD%^%^GREEN%^   scarlet");
         write("%^BOLD%^%^GREEN%^   crimson");
         possible[4] = "sable";
         possible[5] = "auburn";
         possible[6] = "scarlet";
         possible[7] = "crimson";
      case 0..12:
         write("%^BOLD%^%^GREEN%^   black");
         write("%^BOLD%^%^GREEN%^   brown");
         write("%^BOLD%^%^GREEN%^   blonde");
         write("%^BOLD%^%^GREEN%^   red");
         possible[0] = "black";
         possible[1] = "brown";
         possible[2] = "blonde";
         possible[3] = "red";
         break;
   }
   write("");
   write("Usage:  pick "+possible[0]);
}

void show_eyes() {
   write("%^BOLD%^%^GREEN%^Please indicate the eye color that you would like your character to have.");
   write("");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please keep your character in mind when selecting.");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch(cha+x) {
      case 19..30:
         write("%^BOLD%^%^GREEN%^   emerald");
         write("%^BOLD%^%^GREEN%^   sapphire");
         choice[8] = "emerald";
         choice[9] = "sapphire";
      case 13..18:
         write("%^BOLD%^%^GREEN%^   azure");
         write("%^BOLD%^%^GREEN%^   sable");
         write("%^BOLD%^%^GREEN%^   chocolate");
         write("%^BOLD%^%^GREEN%^   coffee");
         choice[4] = "azure";
         choice[5] = "sable";
         choice[6] = "chocolate";
         choice[7] = "coffee";
      case 0..12:
         write("%^BOLD%^%^GREEN%^   blue");
         write("%^BOLD%^%^GREEN%^   green");
         write("%^BOLD%^%^GREEN%^   brown");
         write("%^BOLD%^%^GREEN%^   hazel");
         choice[0] = "blue";
         choice[1] = "green";
         choice[2] = "brown";
         choice[3] = "hazel";
         break;
   }
   write("");
   write("Usage:  pick "+choice[0]);
}

int pick(string str) {
   if(!race_set) {
      if(!str) {
         show_race();
         return 1;
      }
      str = lower_case(str);
      if(member_array(str, race) == -1) {
         write("That is not a valid option: "+str);
         show_race();
         return 1;
      }
      if(str == "strongheart halfling" || str == "ghostwise halfling") {
         TP->set("subrace",str);
         TP->move(new("/d/shadowgate/colors/ghosthalfling.c"));
         return 1;
      }
      TP->set("subrace","lightfoot halfling");
      race_set = 1;
      show_hair();
      return 1;
   }
   if(!hair_set) {
      if(!str) {
        show_hair();
        return 1;
     }
     str = lower_case(str);
     if(member_array(str, possible) == -1) {
         write("That is not a valid option: "+str);
         show_hair();
         return 1;
     }
     TP->set_hair_color(str);
     hair_set = 1;
     show_eyes();
     return 1;
   }
   else if(!eyes_set) {
      if(!str) {
         show_eyes();
         return 1;
      }
      str = lower_case(str);
      if(member_array(str, choice) == -1) {
         write("That is not a valid option: "+str);
         show_eyes();
         return 1;
      }
      TP->set_eye_color(str);
      eyes_set = 1;
      TP->move(new("/d/shadowgate/align_set"));
      return 1;
   }
}

int look_room(string str) {
   if(str) return 0;
   if(!race_set) {
      show_race();
      return 1;
   }
   if(!hair_set) {
      show_hair();
      return 1;
   }
   if(!eyes_set) {
      show_eyes();
      return 1;
   }
   return 0;
}
