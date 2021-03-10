#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "west" : ROOMS + "tun18" ,
                "east" : ROOMS + "tun16"]) );

}

string query_slope1(){
  return "east";
}

string query_slope2(){
  return "west";
}