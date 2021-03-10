#include "/d/dagger/aketon/short.h"

inherit BARKEEP;

void create() {
   ::create();
   set_name("jilian");
   set_id( ({"jilian","waitress","clerk"}) );
   set_short("Jilian the waitress");
   set("aggressive",0);
   set_long("She runs the inn and serves you food.");
   set_gender("female");
   set_alignment(2);
   set("race","elf");
   add_money( "gold",random(100) );
   set_body_type("human");
   set_level(20);
   set_hd(20,4);   
   set_exp(10);
   set_hp(200);
   set_max_hp(query_hp());
   set_menu( ({"jerboa leg","wolf meat","sparrow special"}),
      ({"food","food","food"}),({20,35,50}) );
   set_my_mess( ({"You gags on some jerboa legs.\n",
      "You gobbles down some wolf meat.\n",
      "You enjoys the special cuisine of Aketon."}) );
   set_your_mess( ({"gags on some jerboa legs.\n",
      "gobbles down some wolf meat.\n",
      "enjoys the sparrow special.\n"}) );
   set_menu_short( ({"Jerboa leg",
      "Wolf meat",
      "Sparrow special"}) );
   set_menu_long( ({"Fried legs from local jerboas.\n",
      "Meat of wolfs found in the Kilkean forest.\n",
      "A mix of some special animals from the Kilkean forest, it is the "
      "favourite cuisine of the Aketon hunters.\n"}) );
}
