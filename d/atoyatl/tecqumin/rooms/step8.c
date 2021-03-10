#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"

inherit GUARD_STEP;

void add_monsters();
object has_sacrifice(object ob);
void take_sacrifice();
void take_sacrifice2(object ghost, object sacrifice);
void take_sacrifice3();

int sacrifice_made;
int last_summoned;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow216" ,
                  "west" : ROOMS + "ziglow217",
                "up"   : ROOMS + "step9",
                "down" : ROOMS + "step7"]) );
  add_monsters();
  last_summoned = 0;
}

void init(){
  ::init();
  if (!present("ghost warrior", TO) && last_summoned <time() - 600){
    tell_room(TO, "%^CYAN%^A %^RESET%^whisper%^CYAN%^ of a breeze stirs,"
                 +" the %^RESET%^chill%^CYAN%^ of it making the hairs on"
                 +" the back of your neck stand on end. It's almost as if"
                 +" you could feel a %^RESET%^presence%^CYAN%^"
                 +" approaching");
    call_out("add_monsters",2);
    last_summoned = time();
  }
}


void add_monsters(){
  int i;
  object ob;
  for (i=0;i<4;i++){
    ob = new(MOB + "ghost_warrior");
    ob->set_nogo(({ ROOMS +"ziglow216", ROOMS+"ziglow217",
   ROOMS+"step7", ROOMS+"step9"}));
    ob->set("aggressive", 0);
    ob->move(TO);
  }
  last_summoned = time();
}
