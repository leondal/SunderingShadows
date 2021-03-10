#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("Aketon Tailor");
   set_long("%^BOLD%^Aketon Tailor%^RESET%^
This place is where every citizen of Aketon will go when they need some "
      "new formal clothing in special events like weddings and such. "
      "The tailor here will make you a suit or two for a price.\nThere is "
      "a sign on the wall here.");
    set_items( (["shop":"The shop is quite well lit by a chandelier.",
      ({"dressing","dressings","clothes"}):"Everyone wear these.",
      "sign":
      "%^GREEN%^--==--==--==--==--==--==--==--==--==--==--==--==--==--\n"
      "%^BLUE%^      1. A suit of tuxedo :       500  gold coins\n"
      "      2. A gentleman's jacket :   400  gold coins\n"
      "      3. A lady's jacket :        400  gold coins\n"
      "      4. A pair of trousers :     200  gold coins\n"
      "      5. A skirt :                200  gold coins\n\n"
      "All prices are halved for citizens, doubled for humans.\n"
      "%^GREEN%^--==--==--==--==--==--==--==--==--==--==--==--==--==--\n\n"
      "You can <buy item_number> now and then <pickup item_number> "
      "later."]) );
   set_smell("default","You smell colour dyes.");
   set_listen("default","You hear the sound of a pair of scissors cutting "
      "clothes from behind the curtain.");
   set_exits( (["north":RPATH1+"1one57"]) );
}

void reset() {
   ::reset();
   if( !present("bytukar") )
      new(MPATH+"bytukar")->move(TO);
}
