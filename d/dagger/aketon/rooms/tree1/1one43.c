#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("Aketon Garment Outlet");
   set_long("%^BOLD%^Aketon Garment Outlet%^RESET%^
This shop is one of the oldest shops in this large elven city. It deals in "
      "all kinds of garments you can find in this realm. People all over "
      "the place come here looking for the best garment they need. The "
      "shop owner purchased good quality clothings from other cities and "
      "sells them here. You are guaranteed you can find the one suit you need "
      "most here. A counter is here and a clerk will serve your needs. "
      "There are a few customers here.");
   set_items( (["shop":"This is an old shop, people come here for some "
      "new clothing.",
      ({"garment","garments"}):"These are brend new garments you can buy "
      "here.",
      "customers":"They are fitting, choosing and chatting with each "
      "other.",
      "counter":"A rose wood counter."]) );
   set_smell("default","You smell the scent of fibrics.");
   set_listen("default","You hear ladies talking about the clothings.");
   set_exits( (["east":RPATH1+"1one44"]) );
}

void reset() {
   ::reset();
   if( !present("devian") )
      new(MPATH+"devian")->move(TO);
}
