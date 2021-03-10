//peralin - new rogue guildmaster for tabor. Ibby/Nienne, 12/06
//adapted to load the holy symbol for The Faceless One instead of Mask ~Circe~ 7/18/19
#include <std.h>
inherit "/std/fence";

void create() {
   ::create();
   set_name("peralin");
   set_id( ({ "peralin","Peralin","shop keeper"}) );
   set_short("Peralin Adams, a short wiry human");
   set_long("Standing at an unimpressive four foot five, this scrappy little man is "
"nonetheless very well built. His limbs are taut and wirey, and his stance reminds you "
"more of a cat ready to pounce, then of a shop keeper. He wears dark green and red "
"clothing, seeming to favor those shades. He wields no weapons, but you are sure he could "
"quickly get one from one of his many sheaths. His dark green eyes flash from behind "
"curly red hair.");
   set_gender("male");
   set_alignment(5);
   set_level(19);
   set_class("thief");
   set_race("human");
   set_diety("the faceless one");
   new("/d/magic/symbols/the_faceless_one_symbol")->move(TO);
   force_me("wear symbol");
   add_money("gold", random(500));
   set_property("no bump", 1);
   set_hd(19,3);
   set_exp(10);
}

int should_interact(object ob) { return 1;}
