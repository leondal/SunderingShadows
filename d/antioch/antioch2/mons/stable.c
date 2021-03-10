#include <std.h>
inherit NPC;

void create() {
   ::create();
   set_nwp("riding",5);
   set_short("A young stable boy");
   set_id(({"stable boy","young stable boy","stable hand","boy","young boy","stablehand"}));
   set_gender("male");
   set_race("human");
   set_name("stable hand");
   set_body_type("human");
   set_long("This is a young stable boy of about fourteen"+
     " years in age. He has spent his entire life around horses"+
     " and knows how to handle them and care for them very well."+
     " His face and hands are a little dirty, probably from mucking"+
     " out the stalls. He's wearing a long sleeved blue cotton"+
     " shirt with numerous grass stains on it and some brown leather"+
     " britches that are quite worn. A pair of muddy looking brown"+
     " shoes cover his feet and a cap keeps his hair out of his"+
     " face.");
}
