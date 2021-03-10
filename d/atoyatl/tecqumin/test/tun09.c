#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "northeast" : TEST + "tun10" ,
                "northwest" : TEST + "tun08"]) );

}
string query_slope1(){
  return "northwest";
}

string query_slope2(){
  return "northeast";
}