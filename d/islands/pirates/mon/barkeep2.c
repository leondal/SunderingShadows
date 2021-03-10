#include <std.h>
#include "../piratedefs.h"
inherit "/std/barkeep";

create() {
   ::create();
   set_name("Captain Soren");
   set_id(({"soren","captain","waiter"}));
   set_short("Captain Soren, barkeep of the Seaman's Fare Inn");
   set_level(15);
   set_long("Soren is an older man, well into middle-age, who keeps the inn tidy and maintained here.  He "
"has dark hair and a short beard, but he seems to keep himself quite cleanly presented, despite the riff-raff"
" of the village around him.  He roams from table to table, filling orders and carrying meals.");
   set_gender("male");
   set_alignment(6);
   set_race("human");
   set_hd(10,0);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set("aggressive", 0);
   add_money("silver",random(30));
   set_body_type("human");
   set_currency("silver");
   remove_property("swarm");

   set_menu(
     ({"seafood basket","swordfish steak","fresh salmon","water","silent killer","rogues rum","ocean storm"}),
     ({"food","food","food","water","alcoholic","alcoholic","soft drink"}),
     ({10,18,14,2,25,15,12})
   );

   set_my_mess(({
     "The variety of seafood is perfectly cooked, with a lovely blend of flavours.\n",
     "The steak is thick and juicy, almost melting in your mouth!\n",
     "The salmon has a light, fresh taste with a salty overtone.\n",
     "The water is cool and refreshing.\n",
     "Gulp... your throat burns from the sharp taste of the alcohol, making your eyes water!\n",
     "The rum goes down smooth, leaving a sweet taste of spices that burn lightly on your tongue.\n",
     "The Ocean Storm washes a myriad of bubbly flavours across your tongue, so that you can never quite focus on just one.\n"
   }));

   set_your_mess(({
     "somehow manages to eat every bit of seafood in the basket.\n",
     "eats the juicy swordfish steak and licks their lips.\n",
     "devours some fresh salmon.\n",
     "drains the glass of clear water.\n",
     "tips back the shot in one swallow.\n",
     "takes a swig from the mug of rum.\n",
     "drains the glass of cloudy liquid.\n"
   }));

   set_menu_short(({
     "A basket of seafood",
     "A swordfish steak",
     "A piece of fresh salmon",
     "A glass of water",
     "A shotglass of dark liquid",
     "A mug of rum",
     "A glass of cloudy liquid"
   }));

   set_menu_long(({
     "%^WHITE%^%^BOLD%^A basket filled with all kinds of seafood:  various pieces of %^RESET%^%^WHITE%^fish%^BOLD%^, %^RED%^crustaceans%^WHITE%^, and %^RESET%^%^ORANGE%^crumbed calimari%^WHITE%^%^BOLD%^.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A swordfish steak, cooked to be hot and juicy, and served with a side of %^RESET%^%^ORANGE%^chips%^WHITE%^%^BOLD%^ and a small bowl of %^YELLOW%^tangy sauce%^WHITE%^.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A fresh piece of %^RED%^salmon%^WHITE%^, set with a sprig of %^GREEN%^green herbs%^WHITE%^.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A clear glass of %^CYAN%^water%^WHITE%^.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^By the name of Silent Killer, this is a shotglass of %^BLACK%^thick, dark liquid%^WHITE%^.  It has a rather %^GREEN%^sharp%^WHITE%^ smell to it.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A stocky mug of rum, with a %^RESET%^%^ORANGE%^rich amber hue%^WHITE%^%^BOLD%^.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^This tall glass is filled with cloudy, bubbly liquid that varies in shades from %^CYAN%^pale azure%^WHITE%^, through to %^BLACK%^dark gray%^WHITE%^ and %^BLUE%^cobalt blue%^WHITE%^.%^RESET%^\n"
   }));
}

void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}
