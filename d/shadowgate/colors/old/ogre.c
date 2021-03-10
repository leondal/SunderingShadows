#include <std.h>
#include <daemons.h>

inherit ROOM;

int hair_color, cha, x;
int hair_set;
string *possible;

int pick(string str);
void show_hair();

void create() {
    ::create();
    set_property("no teleport",1);
    set_property("indoors",1);
    set_short("");
    set_long("");
    possible = allocate(3);
}

void init() {
   if(!interactive(TP)) return;
   cha = TP->query_base_stats("charisma");
   TP->set_eye_color("purple");
   add_action("pick","pick");
   add_action("look_room","look");
   show_hair();
}

void show_hair() {
   write("%^BOLD%^%^GREEN%^All ogres have purple eyes.");
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like your character to have, your choice will also affect your skin color (see help ogre for more details).");
   write("");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please keep your character in mind when selecting.");
   write("%^BOLD%^%^GREEN%^<===============>");
   write("%^BOLD%^%^GREEN%^   black");
   write("%^BOLD%^%^GREEN%^   blue-black");
   write("%^BOLD%^%^GREEN%^   dark green");
   possible[0] = "black";
   possible[1] = "blue-black";
   possible[2] = "dark green";
   write("");
   write("Usage:  pick "+possible[0]);
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
   return 0;
}
