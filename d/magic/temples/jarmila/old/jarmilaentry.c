//Temple of Jarmila - created by Nienne 1/18
#include <std.h>
inherit "/std/templemisc";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);
   set_temple("jarmila");
   set_name("The temple gardens");
   set_short("%^YELLOW%^The temple gardens%^RESET%^");
   set_long("%^YELLOW%^The temple gardens%^RESET%^\n"
"%^BOLD%^%^WHITE%^A small but beautiful shrine stands here, honoring Jarmila, the champion of Antioch.  You get the impression that it will some day be much bigger, for there are "
"still workers outside adding extensions to the simple building, but what already stands here is magnificent even in its limited scope.  A %^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^i%^RESET%^"
"%^GREEN%^br%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^nt %^BOLD%^%^WHITE%^garden encircles the building, filled with the bright faces of %^RESET%^%^RED%^r%^BOLD%^%^RED%^o%^RESET%^%^RED%^s"
"%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^BOLD%^%^WHITE%^and %^YELLOW%^su%^RESET%^%^ORANGE%^n%^YELLOW%^jew%^BOLD%^%^WHITE%^e%^BOLD%^%^RED%^l%^YELLOW%^s%^BOLD%^%^WHITE%^.  A tidy %^RESET%^"
"%^ORANGE%^stone path %^BOLD%^%^WHITE%^leads to the building itself, which is made of %^RESET%^pristine white marble%^BOLD%^%^WHITE%^, twin columns bordering the open access to the "
"temple within.\n%^RESET%^");
   set_smell("default","The sweet smell of flowers fills the air.");
   set_listen("default","Gentle music drifts from somewhere in the temple.");
   set_exits(([
      "southeast": "/d/antioch/antioch2/rooms/trail6",
      "temple": "/d/magic/temples/jarmila/jarmila",
   ]));
}
