#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"

inherit GUARD_STEP;

void add_monsters();
object has_sacrifice(object ob);
void take_sacrifice();
void take_sacrifice2(object ghost, object sacrifice);
void take_sacrifice3();

int sacrifice_made, last_summoned;

void create() {
  ::create();
  set_exits( ([ "east" : ROOMS + "ziglow201" ,
                  "west" : ROOMS + "ziglow232",
                "up"   : ROOMS + "step3",
                "down" : ROOMS + "step1" ]) );
  last_summoned = 0;
  add_monsters();
}

void init(){
  ::init();
  if (!present("ghost warrior", TO) && last_summoned <time() - 600){
    tell_room(TO, "%^CYAN%^A %^RESET%^whisper%^CYAN%^ of a breeze stirs,"
                 +" the %^RESET%^chill%^CYAN%^ of it making the hairs on"
                 +" the back of your neck stand on end. It's almost as if"
                 +" you could feel a %^RESET%^presence%^CYAN%^"
                 +" approaching");
    last_summoned = time(); 
    call_out("add_monsters",2);
  }
}


void add_monsters(){
  int i;
  object ob;
  for (i=0;i<4;i++){
    ob = new(MOB + "ghost_warrior");
    ob->set_nogo(({ ROOMS +"ziglow201", ROOMS+"ziglow232",
   ROOMS+"step1", ROOMS+"step3"}));
    ob->set("aggressive", 0);
    ob->move(TO);
  }
  last_summoned = time();
}
