#include "/d/antioch/areadefs.h"
#include <std.h>
inherit "/std/monster";

void create(){
  ::create();
  set_name("prisoner");
  set_id(({"prisoner","man","inmate"}));
  set_short("a prisoner in chains");
  set_long(
  "This man seems to have accepted his fate as a prisoner in this place.  "
  "But you wonder if there is some way you can help him to get free..."
  );
  set_gender("male");
  set_race("human");
  set_body_type("human");
  set_size(2);
  set_hd(15,0);
  set_hp(100);
  set_level(12);
  set("aggressive",0);
}

void init(){
  ::init();
  add_action("free_prisoner","free");
  }

int free_prisoner(string str){
  if(!str){
    notify_fail("Free what?\n");
    return 0;
  }
  if((str!="man")&&(str!="prisoner")&&(str!="inmate")){
    notify_fail("You can't free that!\n");
    return 0;
  }
  tell_object(TP,"You help the prisoner remove his chains.\n");
  tell_room(ETP,TPQCN+" helps the prisoner remove his chains.\n",TP);
  tell_room(ETP,"%^MAGENTA%^Prisoner says: %^RESET%^Thank you for helping me, now I will help you.\n");
    tell_room(ETP,"%^MAGENTA%^Prisoner says: %^RESET%^There is talk of a large pile of gold hidden in one of the cells.\n");
  tell_room(ETP,"%^MAGENTA%^Prisoner says: %^RESET%^It may just be a rumor, but I do not know.\n");
  tell_room(ETP,"%^MAGENTA%^Prisoner says: %^RESET%^Good luck, my friend, and thank you.\n");
  remove();
  return 1;
}
