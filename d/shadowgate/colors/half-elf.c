#include <std.h>
#include <daemons.h>

inherit ROOM;

string *races;
int cha, x, y;

int pick(string str);
void show_races();

void create() {
    ::create();
    set_property("no teleport",1);
    set_property("indoors",1);
    set_short("");
    set_long("");
}

void init() {
   if(!interactive(TP)) return;
   if(TP->query_base_stats("charisma") < 9) {
      TP->move(new("/d/shadowgate/colors/human.c"));
      return;
   }
   if((int)TP->query_lang("common") > 50 && (int)TP->query_lang("elven") > 50) {
      //can pick elven or human
      add_action("pick","pick");
      add_action("look_room","look");
      show_races();
   }
   else if((int)TP->query_lang("elven") < 51) {
      TP->move(new("/d/shadowgate/colors/human.c"));
   }
   else if((int)TP->query_lang("common") < 51) {
      TP->move(new("/d/shadowgate/colors/elf.c"));
   }
}

void show_races()
{
   write("%^BOLD%^%^GREEN%^You may decide which parent you take after the most, your"+
   " human side or your elven side.");
   write("%^BOLD%^%^GREEN%^pick either %^WHITE%^human%^GREEN%^ or %^WHITE%^elf");
}

int pick(string str)
{
   if(!str) return show_races();
   if(str == "human") {
      write("%^BOLD%^%^GREEN%^You have chosen human.");
      TP->move(new("/d/shadowgate/colors/human.c"));
      return 1;
   }
   else if(str == "elf") {
      write("%^BOLD%^%^GREEN%^You have chosen elven.");
      TP->move(new("/d/shadowgate/colors/elf.c"));
      return 1;
   }
   else return show_races();
}

int look_room(string str) {
   if(str) return 0;
   return show_races();
   return 1;
}
