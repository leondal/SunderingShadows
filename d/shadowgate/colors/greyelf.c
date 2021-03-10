#include <std.h>
#include <daemons.h>

inherit ROOM;

int hair_color, eye_color, cha, x, y;
int hair_set, eyes_set;
string *possible, *choice;

int pick(string str);
void show_hair();
void show_eyes();
void show_race();

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
   if(cha < 17) x = random(3);
   else if(cha > 16) x = random(5);
   possible = allocate(3);
   switch(cha+x) {
      case 17..30:
         choice = allocate(3);
         break;
      case 0..16:
         choice = allocate(2);
         break;
   }
   show_hair();
}

void show_hair()
{
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like to have for this character.");
   write("%^BOLD%^%^GREEN%^It is strongly advised that you the grey elves section of the help elves file, hair choice will determine your eye color options.");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please be reasonable and consider how it fits with the rest of your character.");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   write("%^BOLD%^%^GREEN%^   silver");
   write("%^BOLD%^%^GREEN%^   blonde");
   write("%^BOLD%^%^GREEN%^   golden");
   possible[0] = "silver";
   possible[1] = "blonde";
   possible[2] = "golden";
   write("");
   write("Usage:  pick "+possible[0]);
}

void show_eyes() {
   write("%^BOLD%^%^GREEN%^Please indicate the eye color that you would like your character to have.");
   write("");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please keep your character in mind when selecting.");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch(cha+x) {
      case 17..30:
         write("%^BOLD%^%^GREEN%^   amethyst");
         choice[2] = "amethyst";
     case 0..16:
         write("%^BOLD%^%^GREEN%^   violet");
         write("%^BOLD%^%^GREEN%^   purple");
         choice[0] = "violet";
         choice[1] = "purple";
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
     if(str == "silver") {
        write("%^BOLD%^%^GREEN%^Your hair color is now silver, you have"+
        " amber eyes.");
      TP->set_eye_color("amber");
        TP->move(new("/d/shadowgate/align_set"));
        return 1;
     }
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
