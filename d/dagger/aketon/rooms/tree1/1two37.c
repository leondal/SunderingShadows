#include "/d/dagger/aketon/short.h"

inherit DAEMONROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Inside the barracks");
   set_long("%^%^BOLD%^%^RED%^Inside the barracks%^RESET%^
You have entered one of the many barracks of the Aketon military. This is "
      "the place where the soldiers rest and spend their leisure time. "
      "Several soldiers are playing cards. Some are chatting with each "
      "other. The whole place is very tidy and everything is in its "
      "place. The only exceptions are those weapons and armours used by "
      "the soldiers. You can tell they have strict rules reguarding their "
      "daily lift as well. The military believes that only strict rules "
      "can build up a strong force which is what this city needs most in "
      "defending any closeby threats.");
   set_items( (["barracks":"This is the place where the soldiers rest.",
      "soldiers":"Most of them are resting here, but some are guarding "
      "the place from enemies.",
      "place":"The place is very tidy. This shows the Aketon military has "
      "some strict rules about a soldier's daily life.",
      ({"weapons","armours"}):"They were put on the bed and floor. If any "
      "incident happens the soldiers can use them in shortest time.",]) );
   set_smell("default","You smell the body scent of the soldiers.");
   set_listen("default","You hear soldiers marching outside.");
   set_exits( (["north":RPATH1+"1two30",
      "southeast":RPATH1+"1two44",
      "south":RPATH1+"1two43",
      "southwest":RPATH1+"1two42"]) );
}

void reset() {
   if( !present("local infantry") && random(4) ) {
      if( !random(4) ) {
         new(MPATH+"infantry")->move(TO);
         new(MPATH+"infantry")->move(TO);
      }
      else
         new(MPATH+"infantry")->move(TO);
   }
   if( !present("local archer") && random(4) ) {
      if( !random(4) ) {
         new(MPATH+"archer")->move(TO);
         new(MPATH+"archer")->move(TO);
      }
      else
         new(MPATH+"archer")->move(TO);
   }
   if( !present("local scout") && random(4) ) {
      if( !random(4) ) {
         new(MPATH+"scout")->move(TO);
         new(MPATH+"scout")->move(TO);
      }
      else
         new(MPATH+"scout")->move(TO);
   }
   if( !present("heavy cavalry") && random(4) ) {
      if( !random(4) ) {
         new(MPATH+"cavalry")->move(TO);
         new(MPATH+"cavalry")->move(TO);
      }
      else
         new(MPATH+"cavalry")->move(TO);
   }
}
