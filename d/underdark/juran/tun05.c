#include <std.h>
#include "../underdark.h";
#include "juran.h";

inherit BEND;

void create() {
   ::create();
   new(MON+"warrior1.c")->move(TO);
   new(MON+"warrior1.c")->move(TO);
   new(MON+"warrior1.c")->move(TO);
   new(MON+"slave")->move(TO);
   new(MON+"slave")->move(TO);
   new(MON+"slave")->move(TO);
   new(MON+"slave")->move(TO);
   set_exits( ([
      "northwest" : TUNNEL+"tun04",
   ]) );
}
