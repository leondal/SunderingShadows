#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("no teleport",1);
   set_light(3);
    set_long(
@DESC
This is the chamber for setting your hair and eye color information.
You will pick a preferred range or combination depending on your race.

NOTE: The options you choose should be your natural hair and eye color. If you shave your head bald, do not select bald, because in 2 weeks that could easily be undone, while these are permanent characteristics.

 %^BOLD%^%^RED%^If you see the options of %^WHITE%^gray, white, bald, or silver%^RED%^ these are typically meant for older characters, or those who have had a lot of stress in their life or encounters with ghosts (except for the elves, in which case silver will sometimes be a valid option).%^RESET%^

    <go>   will begin the setting process

DESC
    );
}

void init()
{
   ::init();
   add_action("start_set","go");
}

int start_set(string str){
   str = TP->query_race();
/*   if((string)TP->query_race() == "half-orc") { // added new half-orc room to match half-elf selection. N, 2/12.
      TP->move(new("/d/shadowgate/colors/orc.c"));
      return 1;
   }*/
//   else {
      TP->move(new("/d/shadowgate/colors/"+str+".c"));
      return 1;
//   }
}
