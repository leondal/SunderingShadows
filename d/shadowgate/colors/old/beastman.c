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
   TP->set_hair_color("green");
   add_action("pick","pick");
   add_action("look_room","look");
   if(cha < 9) x = 0;
   else if(cha > 8) x = random(10);
   switch(cha+x) {
      case 14..30:
         choice = allocate(4);
         break;
      case 0..13:
         choice = allocate(3);
         break;
   }
   show_eyes();
}

void show_eyes() 
{
   write("%^BOLD%^%^GREEN%^As a beastman you will start with green fur, the shade can vary, and it is possible to change with effort since that is how beastmen communicate, but the actual color you see in score will not vary to reflect such changes.");
   write("%^BOLD%^%^GREEN%^Please indicate the eye color that you would like your character to have.");
   write("");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please keep your character in mind when selecting.");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch((cha+x)) {
      case 14..30:
         write("%^BOLD%^%^GREEN%^   yellow");
         choice[3] = "yellow";
      case 0..13:
         write("%^BOLD%^%^GREEN%^   brown");
         write("%^BOLD%^%^GREEN%^   black");
         write("%^BOLD%^%^GREEN%^   green");
         choice[0] = "brown";
         choice[1] = "black";
         choice[2] = "green";
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
