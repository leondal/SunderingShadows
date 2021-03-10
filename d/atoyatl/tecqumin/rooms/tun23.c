#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "south" : ROOMS + "tun24" ,
                "north" : ROOMS + "tun22",
                "east" : ROOMS + "alcove"]) );

}
string query_slope1(){
  return "north";
}

string query_slope2(){
  return "south";
}