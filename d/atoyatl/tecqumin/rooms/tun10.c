#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "east" : ROOMS + "tun11" ,
                "southwest" : ROOMS + "tun09"]) );

}
string query_slope1(){
  return "southwest";
}

string query_slope2(){
  return "east";
}