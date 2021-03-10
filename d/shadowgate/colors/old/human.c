#include <std.h>
#include <daemons.h>
#include <objects.h>

inherit ROOM;

int hair_color, eye_color, cha, x, y;
int hair_set, eyes_set, race_set;
string *possible, *choice,*race;

int pick(string str);
void show_hair();
void show_eyes();
void show_race();

void create() 
{
    ::create();
    set_property("no teleport",1);
    set_property("indoors",1);
    set_short("");
    set_long("");
    race = ({"heartlander","zin'charu","aesatri","attayan","tsarven","morinnen","tonaz'tlacar","senzokuan","maalish"});
}

void init() {
   if(!interactive(TP)) return;
   cha = TP->query_base_stats("charisma");
   add_action("pick","pick");
   add_action("look_room","look");
   if(cha < 9) x = 0;
   else if(cha > 8 && cha < 17) x = random(3);
   else if(cha > 16) x = random(8);
   switch((cha+x)) {
      case 25..40:
         choice = allocate(17);
         possible = allocate(14);
         break;
      case 24:
         choice = allocate(15);
         possible = allocate(14);
         break;
      case 18..23:
         choice = allocate(13);
         possible = allocate(14);
         break;
      case 16..17:
         choice = allocate(13);
         possible = allocate(11);
         break;
      case 13..15:
         choice = allocate(5);
         possible = allocate(11);
         break;
      case 9..12:
         choice = allocate(5);
         possible = allocate(7);
         break;
      case 0..8:
         choice = allocate(3);
         possible = allocate(7);
         break;
   }

    if(OB_ACCOUNT->is_high_mortal(TP->query_true_name())) 
    { 
        race = race + ({ "tiefling","aasimar","air genasi","earth genasi","fire genasi","water genasi" });
    }
    
    show_race();
}


void show_race()
{
    int i;
    write("%^BOLD%^%^GREEN%^Please indicate the subrace that you would like your character to be (see <help human> for more details)");
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
   switch((cha+x)) {
      case 18..40:
         write("%^BOLD%^%^GREEN%^   ebony");
         write("%^BOLD%^%^GREEN%^   golden");
         write("%^BOLD%^%^GREEN%^   silver");
         possible[11] = "ebony";
         possible[12] = "golden";
         possible[13] = "silver";
     case 13..17:
         write("%^BOLD%^%^GREEN%^   sable");
         write("%^BOLD%^%^GREEN%^   auburn");
         write("%^BOLD%^%^GREEN%^   scarlet");
         write("%^BOLD%^%^GREEN%^   crimson");
         possible[7] = "sable";
         possible[8] = "auburn";
         possible[9] = "scarlet";
         possible[10] = "crimson";
     case 0..12:
         write("%^BOLD%^%^GREEN%^   black");
         write("%^BOLD%^%^GREEN%^   brown");
         write("%^BOLD%^%^GREEN%^   blonde");
         write("%^BOLD%^%^GREEN%^   red");
         write("%^BOLD%^%^GREEN%^   white");
         write("%^BOLD%^%^GREEN%^   gray");
         write("%^BOLD%^%^GREEN%^   bald");
         possible[0] = "black";
         possible[1] = "brown";
         possible[2] = "blonde";
         possible[3] = "red";
         possible[4] = "white";
         possible[5] = "gray";
         possible[6] = "bald";
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
   switch((cha+x)) {
      case 25..40:
         write("%^BOLD%^%^GREEN%^   violet");
         write("%^BOLD%^%^GREEN%^   purple");
         choice[15] = "violet";
         choice[16] = "purple";
      case 24:
         write("%^BOLD%^%^GREEN%^   yellow");
         write("%^BOLD%^%^GREEN%^   amber");
         choice[13] = "yellow";
         choice[14] = "amber";
      case 16..23:
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
    if(!race_set)
    {
        if(!str)
        {
            show_race();
            return 1;
        }
        str = lower_case(str);
        if(member_array(str,race) == -1)
        {
            write("That is not a valid option: "+str);
            show_race();
            return 1;
        }
        TP->set("subrace",str);
        race_set = 1;
        show_hair();
        return 1;
    }

   if(!hair_set) 
   {
      if(!str) 
      {
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
   else if(!eyes_set) 
   {
      if(!str) 
      {
         show_eyes();
         return 1;
      }
      str = lower_case(str);
      if(member_array(str, choice) == -1) 
      {
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