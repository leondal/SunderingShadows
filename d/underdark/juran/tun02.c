#include <std.h>
#include "../underdark.h";
#include "juran.h";

inherit BTUNNEL;

void create() {
   ::create();
   set_exits( ([
      "lower" : TUNNEL+"tun03",
      "ascend" : TUNNEL+"tun01",
   ]) );
}
