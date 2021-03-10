#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "southeast" : TEST + "tun12" ,
                "west" : TEST + "tun10"]) );

}
string query_slope1(){
  return "west";
}

string query_slope2(){
  return "southeast";
}