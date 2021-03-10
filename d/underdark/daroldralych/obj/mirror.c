#include <std.h>
inherit "/d/magic/obj/mirror";

create() {
   ::create();
   set_long((:TO,"mirror_desc":));
}

string mirror_desc(){
   if(TO->query_property("magic mirror")) {
     return("%^BLUE%^The most eye-catching item in the room is the large rectangular %^CYAN%^mir%^BOLD%^r"
"%^RESET%^%^CYAN%^or%^BLUE%^ that spans a large portion of the left wall.  Its flawless surface is framed "
"by an ornate border of %^BOLD%^%^WHITE%^gl%^YELLOW%^e%^WHITE%^aming%^RESET%^%^BLUE%^ metal, forming the "
"silhouettes of dragons crawling around its edges.  The mirror itself is currently %^CYAN%^gl"
"%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^wing%^BLUE%^.%^RESET%^");
   }
   return("%^BLUE%^The most eye-catching item in the room is the large rectangular %^CYAN%^mir%^BOLD%^r"
"%^RESET%^%^CYAN%^or%^BLUE%^ that spans a large portion of the left wall.  Its flawless surface is framed "
"by an ornate border of %^BOLD%^%^WHITE%^gl%^YELLOW%^e%^WHITE%^aming%^RESET%^%^BLUE%^ metal, forming the "
"silhouettes of dragons crawling around its edges.%^RESET%^");
}