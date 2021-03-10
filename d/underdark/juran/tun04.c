#include <std.h>
#include "../underdark.h";
#include "juran.h";

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "north" : TUNNEL+"tun03",
      "southeast" : TUNNEL+"tun05",
   ]) );
}
