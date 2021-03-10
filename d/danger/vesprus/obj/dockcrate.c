#include <std.h>
inherit "/std/bag_logic";
int i,k;


void create() {

    ::create();
    set_id( ({"chest", "lkchest","crate","wooden crate",}) );
    set_name("%^RESET%^%^ORANGE%^crate%^RESET%^");
    set_short("%^RESET%^%^ORANGE%^A large shipping crate%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This is a four foot cubical wooden crate used to ship goods.  The lid has been securely nailed shut to prevent tampering.%^RESET%^");
    set_open_long("%^RESET%^%^ORANGE%^This is a four foot cubical wooden crate.  The lid has been pryed off and the contents are visible.%^RESET%^");
    set_closed_long("%^RESET%^%^ORANGE%^This is a 4 foot cubical crate used to ship goods.  The lid has been
securely nailed down to prevent any tampering.%^RESET%^");
    set_no_clean(1);
    set_weight(295);
    set_value(10);
    set_max_internal_encumbrance(290);
    set_possible_to_close(1);
    switch(random(8)){
       case 0:
          k=random(10)+15;
          for(i=0;i<k;i++){ 
          new("/d/danger/vesprus/obj/banana.c")->move(TO);
          }
       break;
       case 1:
          k=random(20)+15;
          for(i=0;i<k;i++){ 
          new("/d/danger/vesprus/obj/nugget.c")->move(TO);
          }
       break;
       case 2:
          for(i=0;i<20;i++){ 
          new("/d/danger/vesprus/obj/cbox.c")->move(TO);
          }
       break;
       case 3:
          k=random(20)+15;
          for(i=0;i<k;i++){ 
          new("/d/danger/vesprus/obj/cluster.c")->move(TO);
          }
       break;
       case 4:
          k=random(10)+15;
          for(i=0;i<k;i++){ 
          new("/d/danger/vesprus/obj/rapple.c")->move(TO);
          }
       break;
       case 5:
          for(i=0;i<10;i++){ 
          new("/d/danger/vesprus/obj/wflask.c")->move(TO);
          }
       break;
       case 6:
          k=random(10)+15;
          for(i=0;i<k;i++){ 
          new("/d/antioch/valley/obj/gem.c")->move(TO);
          }
       break;
       case 7:
          k=random(5)+5;
          for(i=0;i<k;i++){ 
          new("/d/danger/vesprus/obj/rawfish.c")->move(TO);
          }
          for(i=0;i<5;i++){ 
          new("/d/danger/vesprus/obj/ice.c")->move(TO);
          }
       break;
      return 1;
   }
    set_closed(1);
}
