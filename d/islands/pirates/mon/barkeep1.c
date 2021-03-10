#include <std.h>
#include "../piratedefs.h"
inherit "/std/barkeep";

object stuff;

create() {
   ::create();
   set_name("Ga'tanth");
   set_id(({"ga'tanth","barkeep","gatanth"}));
   set_short("Ga'tanth, barkeep of the Lazy Sailor Tavern");
   set_level(15);
   set_long("Ga'tanth stands behind the bar, waiting to take orders from the rough sorts that have gathered "
"in his tavern.  His partial ogrish ancestry is obvious from his size and crude appearance, but the pirates "
"don't seem to care.  He's clad in fairly rough garb and light armor, but from the weapons he carries at his "
"side, he's probably quite used to the harsh ways of the pirate life.");
   set_gender("male");
   set_alignment(6);
   set_race("half-ogre");
   set_size(3);
   set_hd(20,0);
   set_max_hp(query_hp());
   set("aggressive", 0);
   add_money("silver", random(30));
   set_body_type("human");
   set_class("thief");
   set_mlevel("thief",20);
   set_guild_level("thief",20);
   add_search_path("/cmds/thief");
   set_thief_skill("move silently",120);
   set_thief_skill("hide in shadows",120);
   set_thief_skill("pick pockets",120);
   set_scrambling(1);
   remove_property("swarm");
   set_exp(0);

   stuff = new("/d/common/obj/armour/padded");
   stuff->move(TO);
   stuff->set_property("enchantment",2);
   stuff->set_size(3);
   TO->force_me("wear padded");
   new(OBJ"thiefnote")->move(TO);

   set_currency("silver");
   set_menu(
     ({"fish and chips","seafood surprise","chowder","water","ale","boom-boom","whiskey","burning horizon"}),
     ({"food","food","food","water","alcoholic","alcoholic","alcoholic","alcoholic"}),
     ({8,7,5,1,5,10,12,25})
   );
   set_my_mess(({
     "A layer of grease remains on your fingers from the fish and chips.\n",
     "The fishy taste of the seafood surprise leaves a distinct tang in your mouth.\n",
     "You make short work of the seafood chowder, which warms you from the inside.\n",
     "The water is refreshing enough, if a little stale and murky.\n",
     "You chug the ale, slamming the mug back down on the table.\n",
     "The rough taste of the alcohol makes you cough and gasp for air.\n",
     "You take a swig of the whiskey flask, sending a light burning sensation down your throat, and warmth through your body.\n",
     "Even with the flame extinguished, the drink still burns fiercely at your throat as you drink it down.\n"
   }));
   set_your_mess(({
     "eats the entire plate of fish and chips, licking grease from their fingers.\n",
     "makes short work of the plate of seafood pieces.\n",
     "scarfs down a bowl of thick chowder.\n",
     "drains most of the murky water in the glass.\n",
     "chugs down an ale, and slams the mug back down on the table.\n",
     "coughs loudly as if they are trying to clear their throat, after drinking the glass of dull alcohol.\n",
     "takes a swig from the flask of whiskey.\n",
     "blows out the flame on the alcohol before swallowing the shot.\n"
   }));
   set_menu_short(({
     "A plate of fish and chips",
     "A little plate of seafood pieces",
     "A bowl of thick liquid",
     "A murky glass of water",
     "A mug of ale",
     "A glass of dull alcohol",
     "A small flask of whiskey",
     "A flame-topped shotglass of alcohol"
   }));
   set_menu_long(({
     "%^WHITE%^%^BOLD%^This large platter has a piece of %^RESET%^%^ORANGE%^battered fish%^WHITE%^%^BOLD%^ upon it, surrounded on all sides by greasy %^YELLOW%^potato chips%^WHITE%^.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^Filling this bowl is a mixture of various different seafood pieces.  It's hard to tell what some of them even are, except that they have a similar smell and texture to fish.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A wooden bowl of %^RESET%^%^RED%^chowder%^WHITE%^%^BOLD%^, hot enough that steam rises off the thick liquid, carrying a salty seafood aroma with it.%^RESET%^",
     "%^WHITE%^%^BOLD%^A tall glass of water, though it seems a little %^BLACK%^murky%^WHITE%^.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A thick mug of ale, %^RESET%^%^ORANGE%^amber-hued%^WHITE%^%^BOLD%^ with a thick head of froth on top.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^A glass of %^BLACK%^dull-coloured%^WHITE%^ alcohol, known as 'boom-boom'.  It has a distinctly strong aroma, rising from the surface of the liquid.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^This flask holds a small quantity of strong-smelling %^RESET%^%^ORANGE%^whiskey%^WHITE%^%^BOLD%^.  It would probably have quite a potent kick.%^RESET%^\n",
     "%^WHITE%^%^BOLD%^Livid %^BLUE%^b%^CYAN%^l%^BLUE%^ue fl%^CYAN%^a%^BLUE%^mes%^WHITE%^ dance across the top of the liquid.  The idea is to blow out the flames, and quickly drink the alcohol afterwards.\n"
   }));
}
