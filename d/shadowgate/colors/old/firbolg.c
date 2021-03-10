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
   x = random(10);
   if(cha > 8) y = random(5);
   switch(cha+y) {
      case 16..40:
         choice = allocate(13);
         break;
      case 9..15:
         choice = allocate(5);
         break;
      case 0..8:
         choice = allocate(3);
         break;
   }
   switch(cha+x) {
      case 18..40:
         possible = allocate(9);
         break;
      case 13..17:
         possible = allocate(7);
         break;
      case 0..12:
         possible = allocate(3);
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
      case 18..40:
         write("%^BOLD%^%^GREEN%^   black");
         write("%^BOLD%^%^GREEN%^   brown");
         possible[7] = "black";
         possible[8] = "brown";
     case 13..17:
         write("%^BOLD%^%^GREEN%^   golden");
         write("%^BOLD%^%^GREEN%^   auburn");
         write("%^BOLD%^%^GREEN%^   scarlet");
         write("%^BOLD%^%^GREEN%^   crimson");
         possible[3] = "golden";
         possible[4] = "auburn";
         possible[5] = "scarlet";
         possible[6] = "crimson";
     case 0..12:
         write("%^BOLD%^%^GREEN%^   blonde");
         write("%^BOLD%^%^GREEN%^   red");
         write("%^BOLD%^%^GREEN%^   gray");
         possible[0] = "blonde";
         possible[1] = "red";
         possible[2] = "gray";
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
   switch((cha+y)) {
      case 16..40:
         write("%^BOLD%^%^GREEN%^   silver");
         write("%^BOLD%^%^GREEN%^   emerald");
         write("%^BOLD%^%^GREEN%^   sapphire");
         write("%^BOLD%^%^GREEN%^   azure");
         write("%^BOLD%^%^GREEN%^   cyan");
         write("%^BOLD%^%^GREEN%^   sable");
         write("%^BOLD%^%^GREEN%^   chocolate");
         write("%^BOLD%^%^GREEN%^   coffee");
         choice[5] = "silver";
         choice[6] = "emerald";
         choice[7] = "sapphire";
         choice[8] = "azure";
         choice[9] = "cyan";
         choice[10] = "sable";
         choice[11] = "chocolate";
         choice[12] = "coffee";
      case 9..15:
         write("%^BOLD%^%^GREEN%^   green");
         write("%^BOLD%^%^GREEN%^   hazel");
         choice[3] = "green";
         choice[4] = "hazel";
      case 0..8:
         write("%^BOLD%^%^GREEN%^   brown");
         write("%^BOLD%^%^GREEN%^   blue");
         write("%^BOLD%^%^GREEN%^   gray");
         choice[0] = "brown";
         choice[1] = "blue";
         choice[2] = "gray";
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
