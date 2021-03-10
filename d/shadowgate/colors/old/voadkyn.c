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
   TP->set_hair_color("bald");
   add_action("pick","pick");
   add_action("look_room","look");
   if(cha < 9) x = 0;
   else if(cha > 8 && cha < 17) x = random(3);
   else if(cha > 16) x = random(5);
   switch((cha+x)) {
      case 21..30:
         choice = allocate(17);
         break;
      case 20:
         choice = allocate(15);
         break;
      case 16..19:
         choice = allocate(13);
         break;
      case 9..15:
         choice = allocate(5);
         break;
      case 0..8:
         choice = allocate(3);
         break;
   }
   show_eyes();
}

void show_eyes() {
   write("%^BOLD%^%^GREEN%^All voadkyns are bald, there are no exceptions.");
   write("%^BOLD%^%^GREEN%^Please indicate the eye color that you would like your character to have.");
   write("");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from, please keep your character in mind when selecting.");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch((cha+x)) {
      case 21..30:
         write("%^BOLD%^%^GREEN%^   yellow");
         write("%^BOLD%^%^GREEN%^   amber");
         choice[15] = "yellow";
         choice[16] = "amber";
      case 20:
         write("%^BOLD%^%^GREEN%^   violet");
         write("%^BOLD%^%^GREEN%^   purple");
         choice[13] = "violet";
         choice[14] = "purple";
      case 16..19:
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
