
#include <std.h>

inherit TOWNSMAN;
void create() {
   ::create();
set_name("quincy");
set_id( ({ "quincy", "healer"}) );
   set_short("Quincy, Doctor of Daggerdale");
   set("aggressive", 0);
   set_level(19);
set_long("He is a elderly doctor, who tends to the injured \n"+
   "people of Daggerdale.");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(4);
   set("race", "human");
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_level(19);
}

