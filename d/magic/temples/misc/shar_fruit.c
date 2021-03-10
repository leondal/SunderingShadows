#include <std.h>
inherit "/std/food";

void create(){
   ::create();
   set_name("dark fruit");
   set_id(({"fruit","dark fruit","shar fruit","food"}));
   set_strength(5);
   set_weight(1);
   set_short("%^BOLD%^%^BLACK%^D%^RED%^a%^BLACK%^rk Fru%^RED%^i%^BLACK%^t%^RESET%^");
   set_destroy();
   set_long("%^BOLD%^%^BLACK%^This sticky fru%^RED%^i%^BLACK%^t "+
      "looks similiar to a n%^RED%^e%^BLACK%^ct%^RED%^a%^BLACK%^"+
      "rine.  Its black and %^RED%^red %^BLACK%^p%^RED%^e%^BLACK%^"+
      "el is lightly covered in an oily substance that seeps from "+
      "its surface.%^RESET%^");
   set_my_mess("%^RED%^The sweet and tangy fruit seems to melt in "+
      "your mouth, coating your tongue in its sticky sap.%^RESET%^");
   set_your_mess("consumes the fruit greedily, licking away the "+
      "sticky sap.");
}
