// modified to support new /std/races files. -N, 10/10.
#include <std.h>
#include <daemons.h>
#include <rooms.h>
#include "ansi.h"
#include <objects.h>
inherit ROOM;

#define CLS ESC+"[H"+ESC+"[2J"

int race_set, age_set, height_set, weight_set, body_set, hair_set, eyes_set, max_weight;
string gen, *possible, *okraces; // holds possible body type values

void pick_race();
int pick(string str);
void race_adjust(string str);

void create() {
   ::create();
   set_short("The Character Basics Room");
   set_property("no teleport", 1);
   set_long("%^BOLD%^%^WHITE%^You are standing in a small room with white walls and a tiled ceramic floor.  On the wall "
"there is a list of instructions that read:\n"
"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"%^CYAN%^Step 1.  %^YELLOW%^Here, thou shalt <pick> your character's physical details.\n"
"%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
"%^WHITE%^  Shouldst thou need to read these intructions again, thou shalt type <look> and thou willt be informed.\n");
   set_property("light",2);
   possible = allocate(3);
}

void init() {
   string *fullraces, file, racename, myname, *mapnames;
   int i,lvladjust, isrestrict;
   ::init();
   gen = TP->query_gender();

// pickup of all non-LA races as valid rollables in creation. -N, 10/10.
// please <eval "/daemon/mapping_d.c"->set_value("la races","name","name")> to allow a char of that name to roll LA races; 
// please <eval "/daemon/mapping_d.c"->remove_name_from_array("la races","name")> to remove after they have rolled.

   fullraces = get_dir("/std/races/");
   if(!sizeof(fullraces)) {
     write("%^BOLD%^%^GREEN%^Races have not initialized! Please contact a wiz.");
     return;
   }
   okraces = ({});
   myname = TP->query_name();
   mapnames = "/daemon/mapping_d.c"->query_values("la races");
   if(!sizeof(mapnames)) mapnames = ({});
   for(i=0;i<sizeof(fullraces);i++) 
   {
     file = "/std/races/"+fullraces[i];
     if(file_exists(file)) {
       lvladjust = (int)file->level_adjustment("");
       if(!OB_ACCOUNT->is_high_mortal((string)TP->query_true_name()))
       {
        isrestrict = (int)file->is_restricted();
       }
       racename = (string)file->race_name();
//       if(!lvladjust || member_array(myname,mapnames) != -1) okraces += ({ racename });
       if(!isrestrict || member_array(myname,mapnames) != -1) okraces += ({ racename });
     }
   }
   pick_race();
}

void alertAges(){
   write("%^BOLD%^%^GREEN%^Please indicate the age category that this character falls into.");
   write("%^BOLD%^%^GREEN%^Refer to the <help age> for the differences between age categories.");
   write("%^BOLD%^%^GREEN%^Please note that simply by picking an age group you will not be guaranteed to reach that category.");
   write("%^BOLD%^%^GREEN%^<===============>");
   write("%^BOLD%^%^GREEN%^   Child");
   write("%^BOLD%^%^GREEN%^   Normal");
   write("%^BOLD%^%^GREEN%^   Middle aged");
   write("%^BOLD%^%^GREEN%^   Old");
   write("%^BOLD%^%^GREEN%^   Venerable");
   write("");
   write("Usage:  pick old");
}

void pick_race() {
   int i;
   write("%^BOLD%^Excellent, thou hast finished choosing thy stats.");
   write("%^BOLD%^Now thou must pick a race to become.");
   write("%^BOLD%^%^GREEN%^This is the list from which thou canst choose:");
   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-");

   if(!sizeof(okraces)) {
     write("%^BOLD%^%^GREEN%^Races have not initialized! Please contact a wiz.");
     return;
   }
   for(i=0;i<sizeof(okraces);i++) { write("%^BOLD%^%^MAGENTA%^  "+okraces[i]+"%^RESET%^"); }

   write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-");
   write("%^BOLD%^%^WHITE%^Note: only races with no level adjustment can be rolled in creation, unless you have already linked to an account with experienced characters.\n");
   write("%^BOLD%^%^WHITE%^Please refer to <help request characters> for details on playing level-adjustment races.\n");
   write("%^BOLD%^Type %^BLACK%^<%^CYAN%^pick racename%^BLACK%^> %^WHITE%^to pick your character's race.");
   write("%^YELLOW%^Syntax example: %^WHITE%^pick dwarf %^YELLOW%^will make you a dwarf.");
   add_action("pick","pick");
   return 1;
}

void show_weights() {
    write("%^BOLD%^%^GREEN%^Please indicate the build that this character falls into.");
    write("%^BOLD%^%^GREEN%^This setting will affect the weight of your character, relative to racial averages and height.");
    write("%^BOLD%^%^GREEN%^Pick a number on a scale of 1-7.");
    write("%^BOLD%^%^GREEN%^The descriptions offered are examples of a body type falling under each value.");
    write("");
    write("%^BOLD%^%^GREEN%^Please note that this is not a guarantee of getting a certain weight.");
    write("%^BOLD%^%^GREEN%^<===============>");
    write("%^BOLD%^%^GREEN%^  1 Scrawny");
    write("%^BOLD%^%^GREEN%^  2 ...");
    write("%^BOLD%^%^GREEN%^  3 ...");
    write("%^BOLD%^%^GREEN%^  4 Average");
    write("%^BOLD%^%^GREEN%^  5 ...");
    write("%^BOLD%^%^GREEN%^  6 ...");
    write("%^BOLD%^%^GREEN%^  7 Heavy");
    write("");
    write("Usage:  pick 3");
}

void show_heights() {
    write("%^BOLD%^%^GREEN%^Please indicate the height range that this character falls into.");
    write("%^BOLD%^%^GREEN%^This setting will be relative to racial height averages.");
    write("");
    write("%^BOLD%^%^GREEN%^Please note that this is not a guarantee of falling into a certain height range.");
    write("%^BOLD%^%^GREEN%^<===============>");
    write("%^BOLD%^%^GREEN%^   Short");
    write("%^BOLD%^%^GREEN%^   Average");
    write("%^BOLD%^%^GREEN%^   Tall");
    write("");
    write("Usage:  pick short");
}

void show_body_types() {
    write("%^BOLD%^%^GREEN%^Please indicate the build that describes this character.");
    write("%^BOLD%^%^GREEN%^<===============>");
    switch(100*(int)TP->query_player_weight()/max_weight) {
    case 0..65:
        write("%^BOLD%^%^GREEN%^   frail");
        write("%^BOLD%^%^GREEN%^   gaunt");
        write("%^BOLD%^%^GREEN%^   scrawny");
        possible[0] = "frail";
        possible[1] = "gaunt";
        possible[2] = "scrawny";
        break;
    case 66..75:
        write("%^BOLD%^%^GREEN%^   skinny");
        write("%^BOLD%^%^GREEN%^   slight");
        write("%^BOLD%^%^GREEN%^   lean");
        possible[0] = "skinny";
        possible[1] = "slight";
        possible[2] = "lean";
        break;
    case 76..90:
        write("%^BOLD%^%^GREEN%^   slender");
        write("%^BOLD%^%^GREEN%^   slim");
        write("%^BOLD%^%^GREEN%^   thin");
        possible[0] = "slender";
        possible[1] = "slim";
        possible[2] = "thin";
        break;
    case 91..110:
        write("%^BOLD%^%^GREEN%^   svelte");
        write("%^BOLD%^%^GREEN%^   average");
        write("%^BOLD%^%^GREEN%^   plump");
        possible[0] = "svelte";
        possible[1] = "average";
        possible[2] = "plump";
        break;
    case 111..120:
        write("%^BOLD%^%^GREEN%^   well-built");
        write("%^BOLD%^%^GREEN%^   hardy");
        write("%^BOLD%^%^GREEN%^   stocky");
        possible[0] = "well-built";
        possible[1] = "hardy";
        possible[2] = "stocky";
        break;
    case 121..130:
        write("%^BOLD%^%^GREEN%^   portly");
        write("%^BOLD%^%^GREEN%^   stout");
        write("%^BOLD%^%^GREEN%^   brawny");
        possible[0] = "portly";
        possible[1] = "stout";
        possible[2] = "brawny";
        break;
    default:
        write("%^BOLD%^%^GREEN%^   massive");
        write("%^BOLD%^%^GREEN%^   rotund");
        write("%^BOLD%^%^GREEN%^   heavy");
        possible[0] = "massive";
        possible[1] = "rotund";
        possible[2] = "heavy";
        break;
    }
    write("");
    write("Usage:  pick "+possible[0]);
}

int pick(string str) {
   int fail,num,*weights,i;

   if(!race_set) {
      fail = 0;
      if(!str) {
         write("To pick a race, type '%^BOLD%^pick [racename] %^RESET%^' where racename is the race from the following list:");
         write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-");

   if(!sizeof(okraces)) {
     write("%^BOLD%^%^GREEN%^Races have not initialized! Please contact a wiz.");
     return 1;
   }
   for(i=0;i<sizeof(okraces);i++) { write("%^BOLD%^%^MAGENTA%^  "+okraces[i]+"%^RESET%^"); }

         write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-");
         return 1;
      }
      str = lower_case(str);
      if(member_array(str, okraces) == -1)  {
        write("%^YELLOW%^Sorry, that is not a valid race. Please try again.");
        return 1;
      }
      TP->set_race(str);
      write("%^BOLD%^Thou art now a %^YELLOW%^"+str+"!\n\n");
      TP->init_lang();
      race_set = 1;
      alertAges();
      return 1;
   }
   else if (!age_set) {
      if (!str ) {
         alertAges();
         return 1;
      }
      switch(str){
      case "child":
         if((string)TP->query_race() == "shade") {
           write("%^BOLD%^Shades are not born, but made, and only upon reaching adulthood. Please select a different age bracket.");
           alertAges();
           return 1;
         }
         num = -10 - random(8);
         break;
      case "normal":
         num = random(30);
         break;
      case "middle aged":
         num = 60+random(50);
         break;
      case "old":
         num = 100+random(140);
         break;
      case "venerable":
         num = 250+random(250);
         break;
      default:
         alertAges();
         return 1;
      }
      TP->setPlayerAgeCat(num);
      age_set = 1;
      show_heights();
      return 1;
   }
   if(!height_set) {
       if(!str) {
           show_heights();
           return 1;
       }
       switch(lower_case(str)) { // this now feeds 1-100%. Heavy randomness removed. N, 1/14.
       case "short":
           num = 1+random(30); // 1-30%
           break;
       case "average":
           num = 31+random(40); // 31-70%
           break;
       case "tall":
           num = 71+random(30); // 71-100%
           break;
       default:
           write("That is not a valid option: "+str);
           show_heights();
           return 1;
       }
       TP->set_player_height(PLAYER_D->calc_height(TP, num));
       height_set = 1;
       show_weights();
       return 1;
   }
   else if(!weight_set) {
       if(!str) {
           show_weights();
           return 1;
       }
       switch(lower_case(str)) {
       case "1":
           num = 50+random(60);
           break;
       case "2":
           num = 60+random(50);
           break;
       case "3":
           num = 70+random(45);
           break;
       case "4":
           num = 90+random(30);
           break;
       case "5":
           num = 85+random(50);
           break;
       case "6":
           num = 90+random(50);
           break;
       case "7":
           num = 95+random(60);
           break;
       default:
           write("That is not a valid option: "+str);
           show_weights();
           return 1;
       }
       weights = PLAYER_D->calc_weight(TP, num); // returns weight, max possible weight
       TP->set_player_weight(weights[0]);
       max_weight = weights[1];
       weight_set = 1;
       show_body_types();
       return 1;
   }
   else if(!body_set) {
       if(!str) {
           show_body_types();
           return 1;
       }
       str = lower_case(str);
       if(member_array(str, possible) == -1) {
           write("That is not a valid option: "+str);
           show_body_types();
           return 1;
       }
       TP->set_body_type(str);
       body_set = 1;

     if((string)TP->query_race() == "kobold") {
       TP->set_hair_color("bald");
       TP->set_eye_color("red");
       write("As a kobold you are hairless with red eyes, and scaly skin somewhere between black and reddish-brown.");
       //TP->move(new("/d/shadowgate/class_set"));
       TP->move(new("/d/shadowgate/align_set"));
       return 1;
     }
     else TP->move_player(new("/d/shadowgate/color_set"));
     return 1;
   }
}
