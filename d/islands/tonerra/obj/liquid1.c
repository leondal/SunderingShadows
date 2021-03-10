//red

#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("%^RED%^red liquid");
   set_short("Vial containing %^RED%^red liquid%^RESET%^");
   set_id(({"liquid1","liquid","red","red liquid","vial"}));
   set_long(
@OLI
   This fetid red liquid froths slightly.  No telling what chemical is in it.
OLI
   );
   set_value(2000);
   set_weight(10);
}
