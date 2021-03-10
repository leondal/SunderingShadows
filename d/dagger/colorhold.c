#include <std.h>

inherit ROOM;

int hair_set, eyes_set, race_set;

void create(){
    ::create();
   set_light(3);
   set_property("indoors",1);
   set_property("no teleport",1);
    set_long(
@DESC
This is the chamber for setting your hair and eye color information.
You will pick a preferred range or combination depending on your race.

You will be given 3 chances to change your hair and eye color.

When finished, you will be returned to the world of ShadowGate.

NOTE: The options you choose should be your natural hair and eye color. If you shave your head bald, do not select bald, because in 2 weeks that could easily be undone, while these are permanent characteristics.

If you see the options of gray, white, bald, or silver these are typically meant for older characters, or those who have had a lot of stress in their life or encounters with ghosts (unless you are an elf, in which case silver will sometimes be a valid option).

    <go>   will begin the setting process
    <view> will display your current hair and eye color
    <done> will allow you to leave before your 3 tries are done

DESC
    );
}

void init()
{
   ::init();
   add_action("start_set","go");
   add_action("view_settings","view");
   add_action("leave_early","done");
   hair_set = 0;
   eyes_set = 0;
   race_set = 0;
   if((string)TP->query_race() == "kobold") {
      TP->set_hair_color("black");
      TP->set_eye_color("red");
      tell_object(TP,"As a kobold you don't have any choice, you have red eyes and black hair, have a nice day.");
      TP->move_player("/d/shadowgate/death/death_exit.c");
      return 1;
   }
   if(!TP->query("colors set"))
      TP->set("colors set",2);
   else
      TP->set("colors set",(int)TP->query("colors set")-1);
}

int start_set(string str){
   str = TP->query_race();
   if((string)TP->query_race() == "half-orc") {
      TP->move(new("/realms/crystal/colors/orc.c"));
      return 1;
   }
    if(TP->query("subrace")) TP->set("subrace",0);
   else {
      TP->move(new("/realms/crystal/colors/"+str+".c"));
      return 1;
   }
}

int view_settings(string str)
{
    write("Here are your current settings:");
    write("-------------------------------");
  write("Hair color: "+TP->query_hair_color());
   write("Eye color: "+TP->query_eye_color());
    return 1;
}

int leave_early(string str)
{
   if((int)TP->query_eye_color() == 0) {
      write("You cannot leave without setting your hair and eye colors.");
      return 1;
   }
   TP->move_player("/d/shadowgate/death/death_exit.c");
   return 1;
}
