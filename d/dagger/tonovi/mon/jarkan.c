#include "/d/dagger/tonovi/town/short.h"

inherit TOWNSMAN;

void create(){
    ::create();
   set_nwp("healing", 20);
    set_name("jarkan");
    set_short("Jarkan the Healer");
    set_id( ({"jarkan", "healer", "jarkan the healer"}) );
    set_long(
    "The healer of this town is here, ready to provide you with his wares."
    );
    set_gender("male");
    set_race("human");
      set_alignment(6);
    set_body_type("humanoid");
    set_hd(1,1);
    set_exp(5);
}
