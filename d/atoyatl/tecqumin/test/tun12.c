#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "south" : TEST + "tun13" ,
                "northwest" : TEST + "tun11"]) );

}
string query_slope1(){
  return "northwest";
}

string query_slope2(){
  return "south";
}