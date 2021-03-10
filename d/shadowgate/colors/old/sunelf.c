#include <std.h>
#include <daemons.h>

inherit ROOM;

int hair_color, eye_color, cha, x, y;
int hair_set, eyes_set;
string *possible, *choice, subrace;

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
   subrace = TP->query("subrace");
   add_action("pick","pick");
   add_action("look_room","look");
   if(cha < 17) x = random(3);
   else if(cha > 16) x = random(5);
   switch(cha+x) {
      case 17..30:
         possible = allocate(8);
         choice = allocate(4);
         break;
      case 13..16:
         possible = allocate(3);
         choice = allocate(2);
         break;
      case 0..12:
         possible = allocate(2);
         choice = allocate(1);
         break;
   }
   show_hair();
}

void show_hair()
{
   if(subrace == "fey'ri") {
     write("%^BOLD%^%^GREEN%^As a fey'ri, you have general sun elf features and large batlike wings. You should also have one or more other fiendish features as sign of your heritage.");
     write("%^BOLD%^%^GREEN%^These may include fiery red eyes, fine scales all over the skin, a long pointed tail, batlike ears, or deep red skin.");
     write("%^BOLD%^%^GREEN%^Your racial innate ability 'alter self' should be used later to describe your alternative (non-fiendish) elven form.\n");
   }
   else write("%^BOLD%^%^GREEN%^As a sun elf you have bronzed skin.");
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like to have for this character.");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please be reasonable and consider how it fits with the rest of your character.");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch(cha+x) {
      case 17..30:
         write("%^BOLD%^%^GREEN%^   golden");
         write("%^BOLD%^%^GREEN%^   crimson");
         write("%^BOLD%^%^GREEN%^   scarlet");
         write("%^BOLD%^%^GREEN%^   auburn");
         write("%^BOLD%^%^GREEN%^   ebony");
         possible[3] = "golden";
         possible[4] = "crimson";
         possible[5] = "scarlet";
         possible[6] = "auburn";
         possible[7] = "ebony";
      case 13..16:
         write("%^BOLD%^%^GREEN%^   red");
         possible[2] = "red";
      case 0..12:
         write("%^BOLD%^%^GREEN%^   blonde");
         write("%^BOLD%^%^GREEN%^   black");
         possible[0] = "blonde";
         possible[1] = "black";
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
     case 17..30:
         write("%^BOLD%^%^GREEN%^   emerald");
         write("%^BOLD%^%^GREEN%^   golden");
         choice[2] = "emerald";
         choice[3] = "golden";
     case 13..16:
         write("%^BOLD%^%^GREEN%^   amber");
         choice[1] = "amber";
      case 0..12:
         write("%^BOLD%^%^GREEN%^   green");
         choice[0] = "green";
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
