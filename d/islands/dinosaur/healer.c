#include <std.h>

inherit HEALER;

void create(){
    ::create();
    set_light(2);
   set_climate("tropical");
    set_property("training", 1);
    set_indoors(1);
    set_short("A small canvas tent");
    set_long(
      "This small canvas tent is filled almost to bursting with vials of ointments and potions.  Between two blazing torches stands a small, lightweight, wooden table.  As you look around you can see small shapes moving in the shadows of the tent.  You can see that this tent was made to be able to be moved quickly."
    );
    set_smell("default", "The pungent aroma from the salves work their way into your nose.");
    set_listen("default", "You can hear little but the crackle as the wood of the torches burn.");
    set_name("Kalarg");
    set_exits( ([
      "out" : "/d/shadowgate/adv_main.c",
    ]) );
    set_cl_price(20);
    set_cs_price(60);
    set_cc_price(200);
    set_bp_price(150);
    set_cb_price(500);
}

void reset(){
    ::reset();
    if(!present("kalarg"))
      new("/d/islands/dinosaur/mon/kalarg.c")->move(TO);
}
