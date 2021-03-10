#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
  set_name("prisoner");
  set_id(({"prisoner","inmate"}));
  set_short("a prisoner");
  set_long("It appears that being locked up in this place has driven him insane.  He looks fairly harmless.");
  set("aggressive",8);
  set_alignment(8);
set_gender("male");
  set_body_type("human");
  set_size(3);
  set_race("human");
  set_hd(19,0);
  set_hp(100);
  set_exp(700);
  set_level(10);
  set_emotes(5,({
    "The prisoner mumbles something about gold in the prison.",
    "%^MAGENTA%^Prisoner says: %^RESET%^It's not really gold, you know.",
    "The prisoner cowers in the corner.",
    "%^MAGENTA%^Prisoner says: %^RESET%^Have you come to take me home now?"
  }),0);
  set_emotes(5,({
    "The prisoner screams in terror!",
    "The prisoner tries to get away from you.",
    "%^MAGENTA%^Prisoner says: %^RESET%^Leave me alone!  I didn't hurt you!"
  }),1);
}
