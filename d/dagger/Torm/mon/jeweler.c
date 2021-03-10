#include <std.h>
#include "../tormdefs.h"
inherit "/d/dagger/Torm/mon/dayvendor.c";

void create()
{
   ::create();
   remove_std_db();
   remove_dbs(({"vendor"}));
   set_name("Teil");
   set_short("Teil, a spritely jeweler");
   set_id(({"teil","jeweler","sprite","male","spritely jeweler","Teil","vendor"}));
   set_long(
   "Teil is a rather friendly sea sprite who's taken up the odd occupation"+
   " of jeweler for his race, and chosen to deal with humans and other"+
   " less spritely races.  His face his pleasant enough and he's quite"+
   " cheerful and has an air of innocence to him.  His hair is the color of"+
   " sea weed and his eyes are an ocean blue.  His skin is light blue in"+
   " color and you can see the webbing between his fingers and toes, as"+
   " well as a set of gills on his neck. "
   );
   set_property("always interact",1);
   set_gender("male");
   set_race("sprite");
   set_body_type("human");
   set_alignment(5);
   add_money("gold",random(100));
   set_level(10);
   set_storage_room(TSP+"jewelry_storage");
   set_property("no attack",1);
   set_hd(10,5);
   set_items_allowed("clothing");
     set_nwp("jewelling",20);
   set_exp(10);
}
