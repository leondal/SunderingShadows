#include <std.h>
#include <daemons.h>
#include <objects.h>

inherit OBJECT;
void create() 
{
    ::create();
    set_short("");
    set_long("");
    set_property("no drop", 1);
    set_property("death keep", 1);
    set_id(({"setter object"}));
    set_weight(0);
    set_property("no animate", 1);
    set_property("soulbound", 1);
}

varargs string *query_hair_colors(int cha, string subclass) 
{ 
    string *choices = ({});
    switch(cha+x) 
    {
        case 17..30:
            choices += ({"golden", "crimson", "scarlet", "auburn", "ebony"});
        case 13..16:
            choices += ({"red", "blonde", "stable"});
        case 0..12:
            choices += ({"brown", "black"});
            break;
    }
    return choices;
}

varargs string *query_eye_colors(int cha, string subclass) 
{
    string *choices = ({});
    switch(cha) 
    {
        case 17..30:
            choices += ({"emerald", "sable"});
        case 0..16:
            choices += ({"brown", "green", "hazel"});
            break;
    }
    return choices;
}

void init() {
   if(!interactive(TP)) return;
   cha = TP->query_base_stats("charisma");
   add_action("pick","pick");
   add_action("look_room","look");
   if(cha < 9) x = 0;
   else if(cha > 8 && cha < 16) x = random(3);
   else if(cha > 15) x = random(5);
   switch(cha+x) {
      case 19..30:
         possible = allocate(7);
         choice = allocate(6);
         break;
      case 13..18:
         possible = allocate(5);
         choice = allocate(4);
         break;
      case 0..12:
         possible = allocate(5);
         choice = allocate(2);
         break;
   }
   show_race();
}

void show_race() {
   write("%^BOLD%^%^GREEN%^Please indicate the type of gnome that you would like your character to be (see <help gnome> for more details)");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   write("%^BOLD%^%^GREEN%^   rock gnome");
   write("%^BOLD%^%^GREEN%^   forest gnome");
   race = allocate(3);
   race[0] = "rock gnome";
   race[1] = "forest gnome";
   if(OB_ACCOUNT->is_high_mortal((string)TP->query_true_name())) 
   {
      write("%^BOLD%^%^GREEN%^   deep gnome");
      race[2] = "deep gnome";
   }
   write("");
   write("Usage:  pick "+race[0]);
   return;
}

void show_hair() {
   write("%^BOLD%^%^GREEN%^As a rock gnome you have tan to woody-brown skin.");
   write("%^BOLD%^%^GREEN%^Please indicate the hair color that you would like to have for this character.");
   write("%^BOLD%^%^GREEN%^The descriptions offered are the colors you may choose from.  Please be reasonable and consider how it fits with the rest of your character.");
   write("");
   write("%^BOLD%^%^GREEN%^<===============>");
   switch(cha+x) {
      case 19..30:
         write("%^BOLD%^%^GREEN%^   silver");
         write("%^BOLD%^%^GREEN%^   golden");
         possible[5] = "silver";
         possible[6] = "golden";
      case 0..18:
         write("%^BOLD%^%^GREEN%^   brown");
         write("%^BOLD%^%^GREEN%^   blonde");
         write("%^BOLD%^%^GREEN%^   gray");
         write("%^BOLD%^%^GREEN%^   white");
         write("%^BOLD%^%^GREEN%^   bald");
         possible[0] = "brown";
         possible[1] = "blonde";
         possible[2] = "gray";
         possible[3] = "white";
         possible[4] = "bald";
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
      case 19..30:
         write("%^BOLD%^%^GREEN%^   violet");
         write("%^BOLD%^%^GREEN%^   amethyst");
         choice[4] = "violet";
         choice[5] = "amethyst";
      case 13..18:
         write("%^BOLD%^%^GREEN%^   sapphire");
         write("%^BOLD%^%^GREEN%^   azure");
         choice[2] = "sapphire";
         choice[3] = "azure";
      case 0..12:
         write("%^BOLD%^%^GREEN%^   blue");
         write("%^BOLD%^%^GREEN%^   gray");
         choice[0] = "blue";
         choice[1] = "gray";
         break;
   }
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
      if(str == "forest gnome") {
         TP->set("subrace","forest gnome");
         TP->move(new("/d/shadowgate/colors/forestgnome.c"));
         return 1;
      }
      if(str == "deep gnome") {
         TP->set("subrace","deep gnome");
         TP->move(new("/d/shadowgate/colors/deepgnome.c"));
         return 1;
      }
      TP->set("subrace","rock gnome");
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
