#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(GRASSLANDS);
  set_travel(FOOT_PATH);
  set_name("Corner of main field and low field");
  set_short("%^GREEN%^A well tended m%^ORANGE%^a%^GREEN%^i%^BOLD%^%^YELLOW%^z%^RESET%^%^GREEN%^e"
           +" field");
  set_long( "This is the corner of the main field and the low field. A small area of raised earth separates the two fields." );
  set_exits( (["north" : TABAXROOM + "low_field", 
                "west" : TABAXROOM + "main_field",
              ]) );
}




/*
S3-S2-S1
HF-MF-LF

S3--S2--S1
 |      |
LF      HF
 |      |
CF1-MF-CF2
*/