//Server of ice cream for the beach in new Seneca
//By ~Circe~ 6/18/08 - she is technically behind a 
//window, so when she is attacked, she slams the 
//shutter down and vapes
#include <std.h>
#include <move.h>
#include "../seneca.h"

inherit BARKEEP;

void create() {
   ::create();
   set_name("minniwyn");
   set_id(({"minniwyn","Minniwyn","beach merchant","barkeep","bartender"}));
   set_short("Minniwyn, purveyor of frosty treats");
   set_long("%^RESET%^%^CYAN%^A thick line of %^BOLD%^%^WHITE%^"+
      "white paint %^RESET%^%^CYAN%^of some kind has been slathered "+
      "upon this gnome's nose, apparently for protection from the "+
      "sun, judging from her deep %^ORANGE%^brown complexion%^CYAN%^.  "+
      "Only the upper portion of her body is visible through the "+
      "short window through which she serves her customers.  She "+
      "wears a sleeveless %^BOLD%^%^MAGENTA%^pink top%^RESET%^ "+
      "%^CYAN%^and a wide-brimmed %^ORANGE%^straw hat%^CYAN%^, "+
      "and she seems quite happy to spend her days here on the "+
      "beach, waiting on those who would like some frosty treats.");
   set_gender("female");
   set_level(20);
   set_exp(20);
   set_alignment(1);
   set_race("gnome");
   set_hd(20,20);
   set_hp(10000);
   set_max_hp(query_hp());
   set_currency("silver");
   set_menu(
      ({"vanilla ice cream","chocolate ice cream","strawberry ice cream","peach ice cream","red snowcone","pink snowcone","blue snowcone","yellow snowcone","green snowcone","orange snowcone","purple snowcone","rainbow snowcone","frozen lemonade","ice water"}),
      ({"food","food","food","food","food","food","food","food","food","food","food","food","soft drink","water"}),
      ({15,15,15,15,10,10,10,10,10,10,10,15,25,10})
   );
   set_my_mess(({
      "The cold vanilla ice cream has a soft, creamy taste.\n",
      "The cold chocolate ice cream has a soft, creamy taste.\n",
      "The cold strawberry ice cream has a sweet, creamy taste.\n",
      "The cold peach ice cream has a sweet, creamy taste.\n",
      "The frozen ice has a slight taste of cherries.\n",
      "The frozen ice has a slight taste of strawberries.\n",
      "The frozen ice has a slight taste of raspberries.\n",
      "The frozen ice has a slight taste of lemon...whew!\n",
      "The frozen ice has a slight taste of lime.\n",
      "The frozen ice has a slight taste of orange.\n",
      "The frozen ice has a slight taste of grape.\n",
      "The frozen ice has a slight taste of mixed fruit.\n",
      "The icy lemonade has a cool, refreshing flavor.\n",
      "The deliciously cold ice water hits the spot.\n"
   }));
   set_your_mess(({
      "eats a vanilla ice cream cone.\n",
      "eats a chocolate ice cream cone.\n",
      "eats a strawberry ice cream cone.\n",
      "eats a peach ice cream cone.\n",
      "eats a red snowcone.\n",
      "eats a pink snowcone.\n",
      "eats a blue snowcone.\n",
      "eats a yellow snowcone.\n",
      "eats a green snowcone.\n",
      "eats a orange snowcone.\n",
      "eats a purple snowcone.\n",
      "eats a rainbow snowcone.\n",
      "drinks a frozen lemonade.\n",
      "enjoys a glass of ice water.\n"
   }));
   set_menu_short(({
      "Vanilla Ice Cream",
      "Chocolate Ice Cream",
      "Strawberry Ice Cream",
      "Peach Ice Cream",
      "Red Snowcone",
      "Pink Snowcone",
      "Blue Snowcone",
      "Yellow Snowcone",
      "Green Snowcone",
      "Orange Snowcone",
      "Purple Snowcone",
      "Rainbow Snowcone",
      "Frozen Lemonade",
      "Ice Water"
   }));
   set_menu_long(({
      "Two scoops of %^BOLD%^vanilla ice cream %^RESET%^are pressed into a fresh %^ORANGE%^waffle cone%^RESET%^.  The ice cream seems to melt around the edges, sending tiny rivulets dribbling down onto your hand.",
      "Two scoops of %^BOLD%^%^BLACK%^chocolate ice cream %^RESET%^are pressed into a fresh %^ORANGE%^waffle cone%^RESET%^.  The ice cream seems to melt around the edges, sending tiny rivulets dribbling down onto your hand.",
      "Two scoops of %^BOLD%^%^RED%^strawberry ice cream %^RESET%^are pressed into a fresh %^ORANGE%^waffle cone%^RESET%^.  The ice cream seems to melt around the edges, sending tiny rivulets dribbling down onto your hand.  Small pieces of freshly cut %^BOLD%^%^RED%^strawberry%^RESET%^ have been worked into the ice cream, adding additional flavor.",
      "Two scoops of %^RESET%^%^ORANGE%^peach ice cream %^RESET%^are pressed into a fresh %^ORANGE%^waffle cone%^RESET%^.  The ice cream seems to melt around the edges, sending tiny rivulets dribbling down onto your hand.  Small pieces of freshly cut %^RESET%^%^ORANGE%^peach%^RESET%^ have been worked into the ice cream, adding additional flavor.",
      "A simple %^BOLD%^white paper cone%^RESET%^ has been filled with a mound of %^BOLD%^%^CYAN%^shaved ice %^RESET%^colored %^BOLD%^%^RED%^bright red%^RESET%^.  A light fragrance of %^BOLD%^%^RED%^cherries %^RESET%^rises from the ice, which seems to be melting pretty quickly.  This would be a fantastic treat on a hot summer day.",
      "A simple %^BOLD%^white paper cone%^RESET%^ has been filled with a mound of %^BOLD%^%^CYAN%^shaved ice %^RESET%^colored %^BOLD%^%^MAGENTA%^bright pink%^RESET%^.  A light fragrance of %^BOLD%^%^MAGENTA%^strawberries %^RESET%^rises from the ice, which seems to be melting pretty quickly.  This would be a fantastic treat on a hot summer day.",
      "A simple %^BOLD%^white paper cone%^RESET%^ has been filled with a mound of %^BOLD%^%^CYAN%^shaved ice %^RESET%^colored %^BOLD%^%^BLUE%^bright blue%^RESET%^.  A light fragrance of %^BOLD%^%^BLUE%^raspberries %^RESET%^rises from the ice, which seems to be melting pretty quickly.  This would be a fantastic treat on a hot summer day.",
      "A simple %^BOLD%^white paper cone%^RESET%^ has been filled with a mound of %^BOLD%^%^CYAN%^shaved ice %^RESET%^colored %^YELLOW%^bright yellow%^RESET%^.  A light fragrance of %^YELLOW%^lemon %^RESET%^rises from the ice, which seems to be melting pretty quickly.  This would be a fantastic treat on a hot summer day.",
      "A simple %^BOLD%^white paper cone%^RESET%^ has been filled with a mound of %^BOLD%^%^CYAN%^shaved ice %^RESET%^colored %^BOLD%^%^GREEN%^bright green%^RESET%^.  A light fragrance of %^BOLD%^%^GREEN%^lime %^RESET%^rises from the ice, which seems to be melting pretty quickly.  This would be a fantastic treat on a hot summer day.",
      "A simple %^BOLD%^white paper cone%^RESET%^ has been filled with a mound of %^BOLD%^%^CYAN%^shaved ice %^RESET%^colored %^ORANGE%^bright orange%^RESET%^.  A light fragrance of %^ORANGE%^oranges %^RESET%^rises from the ice, which seems to be melting pretty quickly.  This would be a fantastic treat on a hot summer day.",
      "A simple %^BOLD%^white paper cone%^RESET%^ has been filled with a mound of %^BOLD%^%^CYAN%^shaved ice %^RESET%^colored %^MAGENTA%^deep purple%^RESET%^.  A light fragrance of %^MAGENTA%^grapes %^RESET%^rises from the ice, which seems to be melting pretty quickly.  This would be a fantastic treat on a hot summer day.",
      "A simple %^BOLD%^white paper cone%^RESET%^ has been filled with a mound of %^BOLD%^%^CYAN%^shaved ice %^RESET%^colored with all the hues of the %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w%^RESET%^.  A light, sweet fragrance of %^BOLD%^%^RED%^f%^YELLOW%^r%^BLUE%^u%^GREEN%^i%^MAGENTA%^t %^RESET%^rises from the ice, which seems to be melting pretty quickly.  This would be a fantastic treat on a hot summer day.",
      "This slender container is made from waxed paper shaped into a tumbler, and it holds a serving of frosty, nearly frozen %^YELLOW%^lemonade%^RESET%^.  Made from freshly squeezed %^YELLOW%^lemons%^RESET%^, this drink is a favorite among beachgoers in Seneca.",
      "A slender container made from waxed paper shaped into a tumbler holds a serving of clear %^CYAN%^water%^RESET%^.  Several irregularly shaped %^BOLD%^%^CYAN%^ice cubes%^RESET%^ float in the glass as well, helping to ensure that this drink will bring relief from the heat."
   }));
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(sizeof(TO->query_attackers()) > 0){
      TO->force_me("emote screams and quickly knocks out the "+
         "prop, shutting the window against such attacks!");
      TO->move("/d/shadowgate/void"); 
      TO->remove();
   }
}

void init(){
   ::init();
   add_action("buy_em","buy");
}

int buy_em(string str){
   object obj;
   if(str == "mystery ice cream"){
      if(!TP->query_funds("silver",25)){
         force_me("say I'm sorry, you don't have enough money for "+
            "a mystery cone.");
         return 1;
      }
      tell_room(ETO,""+TOQCN+" grins mischievously and claps her "+
         "hands.  She ducks below the window, and you hear a random "+
         "bang before she returns with the ice cream.");
      TP->use_funds("silver",25);
      tell_object(TP,""+TOQCN+" gives you a mystery cone.");
      tell_room(ETO,""+TOQCN+" collects some silver from "+TPQCN,TP);
      obj = new(OBJ"mystery_cone.c");
      if(obj->move(TP)){
         tell_object(TP,"You cannot carry it!");
         force_me("say Hmm...looks like you can't carry this.  "+
            "I'll just put it on the counter for you.");
         obj->move(ETP);
      }
      return 1;
   }
   return 0;
}