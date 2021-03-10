#include <std.h>
#include <daemons.h>

inherit ROOM;

int hair_color, eye_color, cha, x, y, z;
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
   if(cha > 13) x = random(3);
   if(cha > 17) x += random(3);
   switch(cha+x) {
      case 20..40:
         possible = allocate(5);
         choice = allocate(8);
         break;
      case 18..19:
         possible = allocate(5);
         choice = allocate(6);
         break;
      case 16..17:
         possible = allocate(4);
         choice = allocate(6);
         break;
      case 14..15:
         possible = allocate(4);
         choice = allocate(3);
         break;
      case 0..13:
         possible = allocate(3);
         choice = allocate(3);
         break;
   }
   show_hair();
}

void show_hair()
{
   write("%^BOLD%^%^GREEN%^As a shade you have skin somewhere from gray to inky black.");
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like to have for this character.");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please be reasonable and consider how it fits with the rest of your character.");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch((cha+x)) {
      case 18..40:
         write("%^BOLD%^%^GREEN%^   ebony");
         possible[4] = "ebony";
      case 14..17:
         write("%^BOLD%^%^GREEN%^   sable");
         possible[3] = "sable";
      case 0..13:
         write("%^BOLD%^%^GREEN%^   black");
         write("%^BOLD%^%^GREEN%^   brown");
         write("%^BOLD%^%^GREEN%^   gray");
         possible[0] = "black";
         possible[1] = "brown";
         possible[2] = "gray";
         break;
   }
   write("");
   write("Usage:  pick "+possible[0]);
}

void show_eyes() {
   write("%^BOLD%^%^GREEN%^As a shade your eyes are of a single uniform color with no pupils.");
   write("%^BOLD%^%^GREEN%^Please indicate the eye color that you would like your character to have.");
   write("");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please keep your character in mind when selecting.");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch((cha+x)) {
      case 20..40:
         write("%^BOLD%^%^GREEN%^   violet");
         write("%^BOLD%^%^GREEN%^   purple");
         choice[6] = "violet";
         choice[7] = "purple";
      case 16..19:
         write("%^BOLD%^%^GREEN%^   sable");
         write("%^BOLD%^%^GREEN%^   chocolate");
         write("%^BOLD%^%^GREEN%^   coffee");
         choice[3] = "sable";
         choice[4] = "chocolate";
         choice[5] = "coffee";
      case 0..15:
         write("%^BOLD%^%^GREEN%^   black");
         write("%^BOLD%^%^GREEN%^   gray");
         write("%^BOLD%^%^GREEN%^   brown");
         choice[0] = "black";
         choice[1] = "gray";
         choice[2] = "brown";
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
