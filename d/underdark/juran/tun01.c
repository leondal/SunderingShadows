#include <std.h>
#include "../underdark.h";
#include "juran.h";

inherit BENTRY;

void create() {
   ::create();
   set_exits( ([
      "lower" : TUNNEL+"tun02",
      "surface" : "/d/shadow/juran/city/a6"
   ]) );
}
