#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "northeast" : ROOMS + "tun10" ,
                "northwest" : ROOMS + "tun08"]) );

}
string query_slope1(){
  return "northwest";
}

string query_slope2(){
  return "northeast";
}