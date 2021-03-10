#include "/d/dagger/aketon/short.h"

inherit COUNCILROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Council chamber of Aketon");
   set_long("%^GREEN%^Council chamber of Aketon%^RESET%^
You have stepped into the council chamber of Aketon. Not many things "
      "here. Several large columns of wood stand around the place. Long "
      "benches line the edges. The dense leaves above make a perfect "
      "shelter for meetings to be held here. This is the conference area "
      "for councilers and leaders of Aketon to discuss issues of the city's "
      "management as well as affairs of war here.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","It is much quiet here, songs of lark fills your "
      "ear.");
   set_exits( (["north":RPATH1+"1four6",
      "west":RPATH1+"1four8",
      "northwest":RPATH1+"1four1"]) );
}
