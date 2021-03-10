#include <std.h>
#include "../tecqumin.h"


inherit OBJECT;
int query_number();


create(){
  ::create();
  set_id(({"waystation","waystation"+query_number()}));
}


int query_number(){
  // this number will indicate how many stages along the path this
  // waystation is from the final destination. The higher the number, the
  // further away it is. Each stage will be the equivalent of 5 rooms
  // distance. Default is -5 so that a waystation with the default setting
  // will never be found

  return -5;
}
