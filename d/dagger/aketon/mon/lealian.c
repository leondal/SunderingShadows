#include "/d/dagger/aketon/short.h"

inherit BARKEEP;

void create() {
   ::create();
   set_name("lealian");
   set_id( ({"lealian","bartender","tender","clerk"}) );
   set_short("Lealian the bartender");
   set("aggressive",0);
   set_long("She tends the bar and listens to your stories.");
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
   set_menu( ({"wine","beer","ale","soda","water","coffee"}),
      ({"alcoholic","alcoholic","alcoholic","soft drink","water",
      "caffeine"}),({ 10, 7, 5, 3, 1, 5 }) );
   set_my_mess( ({"You savour the taste of the fine wine!\n",
      "You feel the beer flow down your throat!\n",
      "You down some ale.\n",
      "The soda tastes good going down.\n",
      "The water quenches your thirst.",
      "The hot coffee opens your eyes a bit."}) );
   set_your_mess( ({"savours the taste of the fine wine.\n",
      "slowly pours a mug of thick beer down the throat.\n",
      "drinks some hearty ale.\n",
      "sips on a soda.\n",
      "guzzles a glass of water.\n",
      "sips the bitter hot coffee.\n"}) );
   set_menu_short( ({"A fine wine",
      "A dark beer",
      "A pale ale",
      "A soda pop",
      "A mug of water",
      "A cup of coffee"}) );
   set_menu_long( ({"A fine wine from the lands acrossed the mountians.\n",
      "A dark beer brewed to the far west of here.\n",
      "A pale ale brewed in the farming fields outside Shadow.\n",
      "A carbonated soda pop from far away lands.\n",
      "A clear and filtered water, from nearby streams.\n",
      "A bitter strong coffee. Sure to help sober you up a bit.\n"}) );
}
