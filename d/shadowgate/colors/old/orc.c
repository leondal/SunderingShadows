#include <std.h>
#include <daemons.h>
#include <objects.h>

inherit ROOM;

int race_set, hair_set, eyes_set, cha, x, y;
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
    race = ({ "gray orc" });
    //race = allocate(1); //until level adjust races are handled properly, removing from selection. -N, 10/10.
    possible = allocate(2);
    choice = allocate(3);
}

void init() {
   if(!interactive(TP)) return;
   cha = TP->query_base_stats("charisma");
   add_action("pick","pick");
   add_action("look_room","look");
   if(OB_ACCOUNT->is_high_mortal(TP->query_true_name())) 
    {
    race = race + ({ "mountain orc","orog","tanarukk" });
    }
   show_race();
}

void show_race() {
   int i;
   write("%^BOLD%^%^GREEN%^Please indicate the type of orc that you would like your character to be (see <help orc> for more details)");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   for(i=0;i<sizeof(race);i++)
   {
      write("%^BOLD%^%^GREEN%^   "+race[i]+"");
   }
   
   write("");
   write("Usage:  pick "+race[0]);
   return;
}

void show_hair()
{
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like to have for this character.");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please be reasonable and consider how it fits with the rest of your character.");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   write("%^BOLD%^%^GREEN%^   black");
   write("%^BOLD%^%^GREEN%^   gray");
   possible[0] = "black";
   possible[1] = "gray";
   write("");
   write("Usage:  pick "+possible[0]);
}

void show_eyes() {
   write("%^BOLD%^%^GREEN%^Please indicate the eye color that you would like your character to have.");
   write("");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please keep your character in mind when selecting.");
   write("%^BOLD%^%^GREEN%^<===============>");
   write("%^BOLD%^%^GREEN%^   yellow");
   write("%^BOLD%^%^GREEN%^   orange");
   write("%^BOLD%^%^GREEN%^   red");
   choice[0] = "yellow";
   choice[1] = "orange";
   choice[2] = "red";
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
      if(str == "mountain orc") {
         TP->set("subrace",str);
         TP->set_hair_color("black");
         TP->set_eye_color("red");
         write("As a mountain orc you automatically have black hair and red eyes.");
         TP->move(new("/d/shadowgate/align_set"));
         return 1;
      }
      if(str == "orog") {
         TP->set("subrace",str);
         TP->set_hair_color("black");
         TP->set_eye_color("white");
         write("As an orog you automatically have black hair and white eyes.");
         TP->move(new("/d/shadowgate/align_set"));
         return 1;
      }
      if(str == "tanarukk") {
         TP->set("subrace",str);
         race_set = 1;
         show_hair();
         return 1;
      }
      TP->set("subrace","gray orc");
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
