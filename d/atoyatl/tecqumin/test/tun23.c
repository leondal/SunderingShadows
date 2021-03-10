#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "south" : TEST + "tun24" ,
                "north" : TEST + "tun22",
                "east" : TEST + "alcove"]) );

}
string query_slope1(){
  return "north";
}

string query_slope2(){
  return "south";
}