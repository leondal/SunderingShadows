#include <std.h>
#include "crypt.h"
inherit ROOM;

#define Messages ({\
"You can hear the Crypt Keepers demonic laughter as you fall...",\
"Your beginning to feel like a real fool as you realize he had planned that.",\
"You should have known there would be traps laid...",\
"You fall through utter darkness and silence...",\
"Occassionally you come close to the edge of this pit to brush your fingers against its sides...",\
"The sides are slimy and you decide to keep your hands to yourself...",\
"It is so dark here...",\
"So silent...",\
"You seem to keep falling forever...",\
"Falling...",\
"           Falling...",\
"                      Falling...",\
"                                 Falling...",\
"                                            Falling...",\
"                                                       Falling...",\
"                                                                  Falling...",\
"Suddenly you can hear something!",\
"It is MUSIC!",\
"Its a bit on the erie side but hey as least you can hear something.",\
"You begin to get a bit excited as you hear some movement below you...",\
"Maybe it is your friends...",\
"Hmmmm your mind wanders back to that pouch of gold...",\
"Then again maybe it isn't a friend but a foe below...",\
"One things for sure you will NEVER look at a pouch of gold the same way ever again!",\
})

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("indoors", 1);
  set_property("light", 1);
  set_short("You are falling forever it seems.");
  set_long("Forever dark until the light");
  set_exits( ([]) );
}
void do_fall(int x, object who) {
  int hurt;
  if(!who) return;
  if(environment(who) != this_object()) return;
  message("my_action","%^BOLD%^%^RED%^"+ Messages[x] +"\n\n", who);
  x++;
    if(x <24) call_out("do_fall", 1, x, who); else {
  who->move_player("/d/koenig/town/crypt6");
  if(random(5) == 0) {
    tell_object((who), "You rub your bruises.");
    hurt = (int)who->query_hp();
    hurt = (hurt > 10) ? 10 : (hurt -1);
    who->do_damage("torso", hurt);
    } else tell_object((who), "\nYou rub your pride.");
  }
}
  void start_fall() {
  if(!this_player()) return;
  call_out("do_fall", 1, 0, this_player());
}
