#include "/d/antioch/areadefs.h"
inherit "/std/monster";

void create() {
     ::create();
  set_name("prisoner");
  set_id(({"prisoner","inmate"}));
  set_short("a prisoner");
  set_long("He may well be the meanest person you have seen in this place.  He looks like he has been here for a long time and has become attached to the place.");
  set_level(15);
  set("aggressive",18);
set_alignment( 9 );
set_gender("male");
  set_body_type("human");
  set_size(3);
  set_race("human");
  set_hd(19,0);
  set_hp(100);
  set_exp(2500);
}

void init(){
  ::init();
  tell_room(environment(this_object()),"%^MAGENTA%^The prisoner says: %^RESET%^Get out of my cell!!\n");
}
