#include <std.h>
#include <daemons.h>

inherit ROOM;

int eye_color, cha, x;
int eyes_set;
string *choice;

int pick(string str);
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
   if((string)TP->query_gender() == "male") {
      TP->set_hair_color("black");
   }
   if((string)TP->query_gender() == "female") {
      TP->set_hair_color("golden");
   }
   add_action("pick","pick");
   add_action("look_room","look");
   if(cha < 9) x = 0;
   else if(cha > 8 && cha < 17) x = random(3);
   else if(cha > 16) x = random(5);
   switch((cha+x)) {
      case 18..30:
         choice = allocate(10);
         break;
      case 15..17:
         choice = allocate(9);
         break;
      case 12..14:
         choice = allocate(3);
         break;
      case 0..11:
         choice = allocate(1);
         break;
   }
   show_eyes();
}

void show_eyes() {
   write("%^BOLD%^%^GREEN%^Wemics do not get a choice in their hair color, it has already been set for you.");
   write("%^BOLD%^%^GREEN%^Please indicate the eye color that you would like your character to have.");
   write("");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please keep your character in mind when selecting.");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch((cha+x)) {
      case 18..30:
         write("%^BOLD%^%^GREEN%^   blue");
         choice[9] = "blue";
      case 15..17:
         write("%^BOLD%^%^GREEN%^   amber");
         write("%^BOLD%^%^GREEN%^   caramel");
         write("%^BOLD%^%^GREEN%^   emerald");
         write("%^BOLD%^%^GREEN%^   chocolate");
         write("%^BOLD%^%^GREEN%^   coffee");
         write("%^BOLD%^%^GREEN%^   sable");
         choice[3] = "amber";
         choice[4] = "caramel";
         choice[5] = "emerald";
         choice[6] = "chocolate";
         choice[7] = "coffee";
         choice[8] = "sable";
      case 12..14:
         write("%^BOLD%^%^GREEN%^   green");
         write("%^BOLD%^%^GREEN%^   brown");
         choice[1] = "green";
         choice[2] = "brown";
      case 0..11:
         write("%^BOLD%^%^GREEN%^   gold");
         choice[0] = "gold";
         break;
   }
   write("");
   write("Usage:  pick "+choice[0]);
}

int pick(string str)
{
   if(!eyes_set) {
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
   if(!eyes_set) {
      show_eyes();
      return 1;
   }
   return 0;
}
