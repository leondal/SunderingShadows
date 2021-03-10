#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "east" : TEST + "tun11" ,
                "southwest" : TEST + "tun09"]) );

}
string query_slope1(){
  return "southwest";
}

string query_slope2(){
  return "east";
}