#include <std.h>
inherit BARKEEP;
int moving;

void create() {
  ::create();
  set_name("Catherine");
  set_id(({"barmaid","barkeep","catherine","waitstaff"}));
  set_property("always interact",1);
  set_short("Catherine the barmaid");
  set("aggressive", 0);
  set_alignment(5);
  set_level(10);
  set_long(
   "Tall, blonde, and busty, Catherine grins from across the room at you.  She has a very dark tan and %^BLUE%^%^BOLD%^sea blue%^RESET%^%^CYAN%^ eyes that are framed by dark lashes.  She introduces herself as Catherine to all who enter."
   "  She's wearing a very low cut blouse and one might suppose she's looking for tips anyway she can."
  );
  set_moving(1);
  set_speed(1200);
  set_gender("female");
  set_race("half-elf");
  set_hd(10,0);
  set_exp(10);
  set_max_hp(query_hp());
  add_money("copper", random(200));
  set_body_type("human");
  set_currency("gold");
  set_menu(({
  "salmon filet",
  "crab bisque",
  "watercress salad",
  "seafood fettucini",
  "sashimi",
  "water",
  "mint tea",
  "hurricane",
  "seabreeze",
  "pale ale",
  }),
  ({ "food", "food", "food", "food", "food", "water", "water", 
     "alcoholic", "alcoholic", "alcoholic", }),
  ({   25,15,10,25,40,1,2, 10,15,10,  }));
  set_my_mess(({
  "The warm, tender flakes of the salmon melt in your mouth.",
  "The bisque has a deliciously light flavor and is incredibly creamy.",
  "The watercress salad is most interesting, though an acquired taste.",
  "The sauce these noodles are doused in certainly brings out the delicate flavor of the crab, baby clams and shrimp in a good way.",
  "The sashimi is cool and light, the sauce has a nice tangy flavor.",
  "The water is cool and refreshing with a twist of lemon.",
  "The mint tea cools you down and leaves your mouth feeling fresh.",
  "Woo, that last little bit of Rum she added sure wants to snap your hair back.",
  "A light airy fruit cocktail and quite nice going down.",
  "You lick the foam from your lips as you consider that fine light ale.",
  }));
  set_your_mess(({
  "seems to enjoy the salmon filet.",
  "eats the entire bowl of creamy crab bisque.",
  "slowly eats the watercress salad.",
  "enjoys a delicious looking noodle dish.",
  "dips each slice of sashimi in a dark sauce and swallows it down.",
  "drinks some refreshing water.",
  "has a glass of mint tea.",
  "shakes their head as if clearing a storm from inside their brain.",
  "drinks down a pink cocktail and smiles.",
   "licks their lips to get the last little bit of foam from a pale ale off.",
  }));
  set_menu_short(({
  "Salmon Filet",
  "Crab Bisque",
  "Watercress Salad",
  "Seafood Fettucini",
  "Sashimi",
  "Water",
  "Mint Tea",
  "Hurricane",
  "Seabreeze",
  "Pale Ale",
  }));
  set_menu_long(({
  "The salmon filet has been lightly grilled and is a light orange-pink"+
    " in color. It appears flaky and delicious, free of bones.",
  "A thick pale blue bowl decorated with seahorses holds the crab"+
    " bisque. It looks thick and creamy.",
  "This is an exotic salad filled with slightly wilted watercress"+
    " leaves. It is supposed to be a delicacy.",
  "A delicious looking plate of thin long noodles, smothered in a creamy"+
    " sauce with baby clam, bits of crab and shrimp in it.",
  "This is a plate of raw fish that has been sliced into slender pieces"+
    " and placed on a bed of shredded cabbage. There is a small dish of"+
    " dark sauce that you dip the fish in. It is a foreign dish that has"+
    " become quite popular with Torm's nobility.",
  "A glass of refreshing water with a twist of lemon.",
  "A glass of cool mint tea.",
   "This dark cocktail smells faintly of blackberries and navy rum.",
  "A tall glass, filled with a light red, almost pink drink that looks delicious.",
   "A short glass of pale ale, foaming just right.",
  }));
}


/*  Didn't work for some reason
void reset() {
   ::reset();
     if(random(2))  return;
     if(base_name(ETO) == "/d/dagger/Torm/city/c94") {
       force_me("east");
       return;
     }
     if(base_name(ETO) == "/d/dagger/Torm/city/c95") {
         force_me("west");
         return;
     }
}
*/
void move_around() {
   string *exits;
   string exitn;
   int j;

   if(!this_object()) return;
   if(!objectp(ETO)) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(environment(this_object()))
      exits = environment(TO)->query_exits();
   if(sizeof(exits)){
      j = random(sizeof(exits));
      exitn = (string)environment(TO)->query_exit(exits[j]);
      if(exitn != "/d/dagger/Torm/city/c93") {
         exitn->init();
         TO->force_me(exits[j]);
      }
   }
   moving=0;
}
