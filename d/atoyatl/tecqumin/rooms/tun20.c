#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "south" : ROOMS + "tun21",
                "east" : ROOMS + "tun19"]) );

}

string query_slope1(){
  return "east";
}


string query_slope2(){
  return "south";
}