#include <std.h>
#include "../tormdefs.h"
inherit MONSTER;

void create(){
   ::create();
  set_name("librarian");
  set_short("Erane Malater, Torm's city librarian");
  set_id(({"erane",
  "librarian","city librarian",
  }));
  set_long(
  "  Erane looks very familiar as if you've seen her face around somewhere before."
   "  She has mousy brown hair that is kept back in a bun, although a few wisps escape in places.  A pair of gold framed glasses rest on her face, sometimes slipping down so that she has to push them back.  She has gray eyes and is pale (unlike most of the rest of the citizens of Torm, it's probably from spending all her time holed up in the library)."
  "  She is in charge of organizing the scrolls that fill these shelves."
  "  Some say that she is the only one who can find things in the library."
  );
   set_race("elf");
   set_gender("female");
  set_body_type("humanoid");
   set_class("mage");
   set_level(1);
   set("aggressive",0);
   set_alignment(5);
   set_size(2);
   set_exp(1);
  new(OBJ+"eyeglasses.c")->move(TO);
  command("wear glasses");
}
