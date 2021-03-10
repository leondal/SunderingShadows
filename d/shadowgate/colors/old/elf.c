#include <std.h>
#include <daemons.h>
#include <objects.h>

inherit ROOM;

int hair_set, eyes_set, race_set, cha, x, y, z;
string *possible, *choice, *race, subrace;

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
   switch(cha+x) {
      case 17..30:
         possible = allocate(5);
         choice = allocate(6);
         break;
      case 13..16:
         possible = allocate(2);
         choice = allocate(3);
         break;
      case 0..12:
         possible = allocate(1);
         choice = allocate(2);
         break;
   }
   if((string)TP->query_race() == "half-elf") {
      if(!random(3)) {
         TP->set("subrace","moon elf");
         subrace = "moon elf";
         race_set = 1;
         show_hair();
         return;
      }
   }
   show_race();
}

void show_race() {
   write("%^BOLD%^%^GREEN%^Please indicate the type of elf that you would like your character to be (see <help elf> for more details)");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   write("%^BOLD%^%^GREEN%^   sun elf");
   write("%^BOLD%^%^GREEN%^   moon elf");
   write("%^BOLD%^%^GREEN%^   wood elf");
   race = allocate(5);
   race[0] = "sun elf";
   race[1] = "moon elf";
   race[2] = "wood elf";
   if(OB_ACCOUNT->is_high_mortal((string)TP->query_true_name())) 
   {
       write("%^BOLD%^%^GREEN%^   wild elf");
       race[3] = "wild elf"; 
       write("%^BOLD%^%^GREEN%^   fey'ri");
       race[4] = "fey'ri"; 
   }
   write("");
   write("Usage:  pick "+race[0]);
   return;
}

void show_hair()
{
   write("%^BOLD%^%^GREEN%^As a moon elf you have fair skin.");
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like to have for this character.");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please be reasonable and consider how it fits with the rest of your character.");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch(cha+x) {
      case 17..30:
         write("%^BOLD%^%^GREEN%^   silver");
         write("%^BOLD%^%^GREEN%^   platinum");
         write("%^BOLD%^%^GREEN%^   ebony");
         possible[2] = "silver";
         possible[3] = "platinum";
         possible[4] = "ebony";
     case 13..16:
         write("%^BOLD%^%^GREEN%^   blue");
         possible[1] = "blue";
     case 0..12:
         write("%^BOLD%^%^GREEN%^   black");
         possible[0] = "black";
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
         write("%^BOLD%^%^GREEN%^   sapphire");
         write("%^BOLD%^%^GREEN%^   azure");
         write("%^BOLD%^%^GREEN%^   cyan");
         choice[3] = "sapphire";
         choice[4] = "azure";
         choice[5] = "cyan";
     case 13..16:
         write("%^BOLD%^%^GREEN%^   emerald");
         choice[2] = "emerald";
     case 0..12:
         write("%^BOLD%^%^GREEN%^   green");
         write("%^BOLD%^%^GREEN%^   blue");
         choice[0] = "green";
         choice[1] = "blue";
         break;
   }
   write("");
   write("Usage:  pick "+choice[0]);
}

int pick(string str)
{
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
      if(str == "sun elf") {
         TP->set("subrace","sun elf");
         TP->move(new("/d/shadowgate/colors/sunelf.c"));
         return 1;
      }
      if(str == "wood elf") {
         TP->set("subrace","wood elf");
         TP->move(new("/d/shadowgate/colors/woodelf.c"));
         return 1;
      }
      if(str == "wild elf") {
         TP->set("subrace","wild elf");
         TP->move(new("/d/shadowgate/colors/wildelf.c"));
         return 1;
      }
      if(str == "fey'ri") {
         TP->set("subrace","fey'ri");
         TP->move(new("/d/shadowgate/colors/sunelf.c"));
         return 1;
      }
      TP->set("subrace","moon elf");
      subrace = str;
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
