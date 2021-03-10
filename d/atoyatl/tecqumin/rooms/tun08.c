#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "southeast" : ROOMS + "tun09" ,
                "west" : ROOMS + "tun07"]) );

}

string query_slope1(){
  return "west";
}

string query_slope2(){
  return "southeast";
}