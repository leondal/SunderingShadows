#include <std.h>
#include <daemons.h>

inherit ROOM;

int hair_color, eye_color, cha, x, y;
int hair_set, eyes_set;
string *possible, *choice;

int pick(string str);
void show_hair();
void show_eyes();

void create() {
    ::create();
    set_property("no teleport",1);
    set_property("indoors",1);
    set_short("");
    set_long("");
}

void init() {
   if(!interactive(TP)) return;
   cha = TP->query_base_stats("charisma");
   add_action("pick","pick");
   add_action("look_room","look");
   if(cha < 13) x = 0;
   else if(cha > 12) x = random(3);
   switch(cha+x) {
      case 17..30:
         possible = allocate(4);
         choice = allocate(7);
         break;
      case 16:
         possible = allocate(4);
         choice = allocate(6);
         break;
      case 14..15:
         possible = allocate(3);
         choice = allocate(6);
         break;
      case 13:
         possible = allocate(3);
         choice = allocate(2);
         break;
      case 0..12:
         possible = allocate(1);
         choice = allocate(2);
         break;
   }
   show_hair();
}

void show_hair()
{
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like to have for this character.");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please be reasonable and consider how it fits with the rest of your character.");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch((cha+x)) {
      case 16..30:
         write("%^BOLD%^%^GREEN%^   silver");
         possible[3] = "silver";
      case 13..15:
         write("%^BOLD%^%^GREEN%^   blonde");
         write("%^BOLD%^%^GREEN%^   brown");
         possible[1] = "blonde";
         possible[2] = "brown";
      case 0..12:
         write("%^BOLD%^%^GREEN%^   white");
         possible[0] = "white";
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
   switch((cha+x)) {
      case 17..30:
         write("%^BOLD%^%^GREEN%^   blue");
         choice[6] = "blue";
      case 14..16:
         write("%^BOLD%^%^GREEN%^   brown");
         write("%^BOLD%^%^GREEN%^   chocolate");
         write("%^BOLD%^%^GREEN%^   coffee");
         write("%^BOLD%^%^GREEN%^   sable");
         choice[2] = "brown";
         choice[3] = "chocolate";
         choice[4] = "coffee";
         choice[5] = "sable";
      case 0..13:
         write("%^BOLD%^%^GREEN%^   black");
         write("%^BOLD%^%^GREEN%^   red");
         choice[0] = "black";
         choice[1] = "red";
         break;
   }
   write("");
   write("Usage:  pick "+choice[0]);
}

int pick(string str)
{
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
