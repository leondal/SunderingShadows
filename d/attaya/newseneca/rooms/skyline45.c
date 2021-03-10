//skyline45
#include <std.h>
#include "../seneca.h"

inherit SKYLINE;

void create(){
   ::create();
   set_long(::query_long()+"To the west stands a %^BOLD%^"+
      "majestic cathedral %^RESET%^with a single soaring "+
      "bell tower.  To the east is a %^ORANGE%^tan "+
      "stucco building %^RESET%^with a %^RED%^sign "+
      "%^RESET%^hanging above its door.\n");
   set_exits(([
      "east" : ROOMS"general_store",
      "north" : ROOMS"skyline44",
      "south" : ROOMS"skyline46"
   ]));
   add_item("cathedral","The cathedral to the west boasts towering "+
      "arches and vaulted ceilings, resplendent with %^BOLD%^"+
      "%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^%^CYAN%^s %^RESET%^and a bell tower that "+
      "soars over all.");
   add_item("building","%^ORANGE%^The building to the east is "+
      "covered with light tan stucco and features a %^RED%^red "+
      "tile roof%^ORANGE%^.  A matching %^RED%^sign %^ORANGE%^"+
      "that you could read hangs above the door.%^RESET%^");
   add_item("stucco building","%^ORANGE%^The building to the east is "+
      "covered with light tan stucco and features a %^RED%^red "+
      "tile roof%^ORANGE%^.  A matching %^RED%^sign %^ORANGE%^"+
      "that you could read hangs above the door.%^RESET%^");
   add_item("shop","%^ORANGE%^The building to the east is "+
      "covered with light tan stucco and features a %^RED%^red "+
      "tile roof%^ORANGE%^.  A matching %^RED%^sign %^ORANGE%^"+
      "that you could read hangs above the door.%^RESET%^");
   add_item("sign",({"A small rectangular white sign with a %^RED%^red "+
      "border %^RESET%^and %^RED%^lettering %^RESET%^hangs "+
      "above the door.  You could read it if you wish.",(:TO,"read_sign":),"wizish"}));
}

void read_sign(){
    string tmp;
    write("%^RED%^--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--%^RESET%^");
    tmp = "%^B_WHITE%^                                               
              %^RED%^Seneca Trading Post              
                                               
%^RESET%^%^RED%^--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--=*=--%^RESET%^";
   return tmp;
}
   