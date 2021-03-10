//Octothorpe (1/21/17)
//Shadow, Mage Tower Tea Mistress
//Designed by Ivyes
//Adapted from /d/shadow/mon/waitress.c

#include <std.h>
inherit "/std/barkeep";

void create()
{
   ::create();
   set_name("Shan Xiu");
   set_id(({
      "Shan Xiu","Shan","shan","shan xiu","mistress","mistress of the tea"
   }));
   set_short("%^MAGENTA%^Shan Xiu, Mistress of the Tea%^RESET%^");
   set_long("%^BOLD%^%^MAGENTA%^Shan Xiu is a young %^RESET%^Senzokuan "+
      "%^BOLD%^%^MAGENTA%^woman with %^BLACK%^short black hair "+
      "%^MAGENTA%^and slanted, almond-shaped %^BLACK%^eyes%^MAGENTA%^. "+
      "She is %^RESET%^pale %^BOLD%^%^MAGENTA%^and pretty, and "+
      "%^RESET%^%^MAGENTA%^reserved %^BOLD%^in her mannerisms. Her "+
      "%^BLACK%^dark eyes %^MAGENTA%^are wise and expressive, often "+
      "saying what her words do not. She is dressed in simple clothes, "+
      "a %^RESET%^white tunic %^BOLD%^%^MAGENTA%^with %^RESET%^"+
      "%^ORANGE%^tan pants%^BOLD%^%^MAGENTA%^, and she wears no shoes "+
      "as she shuffles silently around the tea shop. Despite her small "+
      "size, you get the impression she is not one to be trifled with, "+
      "like a cat ready to pounce.%^RESET%^");
   set_gender("female");
   set_exp(20);
   set_alignment(1);
   set_level(30);
   set_race("human");
   set_body_type("human");
   set_hd(30,4);
   set_max_hp(query_hp());
   add_money("copper",random(200));
   set_currency("silver");
   set_menu(
      ({"white cinnamon sage", "jasmine green","sweet orange spice","orchid vanilla","apple red","fresh vegetable salad","turkey wrap","tea cookies","apple strudel"}),
      ({"soft drink","soft drink","soft drink","soft drink","soft drink","food","food","food","food"}),
      ({12,12,12,12,12,20,25,15,20})
   );
   set_my_mess(({
      "%^ORANGE%^An undertone of %^BOLD%^honey %^RESET%^%^ORANGE%^"+
         "makes for an exceptionally crafted cup.%^RESET%^\n",
      "%^BOLD%^This is an exquisite cup of %^RESET%^%^CYAN%^sublime "+
         "%^BOLD%^%^WHITE%^sweetness.%^RESET%^\n",
      "%^BOLD%^You savor the richly %^RESET%^aromatic %^BOLD%^"+
         "tea.%^RESET%^\n",
      "%^BOLD%^Delicious and creamy, you savor the enchanting "+
         "%^GREEN%^t%^RESET%^%^GREEN%^r%^ORANGE%^o%^BOLD%^%^GREEN%^"+
         "pic%^RESET%^%^GREEN%^a%^BOLD%^l %^WHITE%^flavor.%^RESET%^\n",
      "%^BOLD%^You savor the %^RESET%^%^RED%^crisp %^BOLD%^apple "+
         "%^WHITE%^and %^RESET%^%^ORANGE%^rich %^BOLD%^%^BLACK%^"+
         "chocolate %^WHITE%^flavors.%^RESET%^\n",
      "%^BOLD%^%^GREEN%^You feel full of %^RESET%^%^GREEN%^healthy "+
         "%^BOLD%^stuff!%^RESET%^\n",
      "%^BOLD%^The combination of flavors is quite delectable.%^RESET%^\n",
      "%^BOLD%^You eat the last of the cookies, leaving not even a "+
         "crumb behind.%^RESET%^\n",
      "%^BOLD%^So much %^MAGENTA%^sweetness%^WHITE%^, as if you "+
         "weren't already sweet enough.%^RESET%^\n",
   }));
   set_your_mess(({
      "finishes the tea and looks invigorated!\n",
      "enjoys a cup of hot tea.\n",
      "finishes the tea, enjoying its rich flavor.\n",
      "enjoys a cup of tea.\n",
      "finishes off the last of the tea.\n",
      "enjoys a nice salad.\n",
      "devours the wrap and picks at the chips.\n",
      "eats the last of the cookies, leaving not even a crumb behind.\n",
      "devours a plate of strudel, savoring the sweetness.\n"
   }));
   set_menu_short(({
      "White Cinnamon Sage",
      "Jasmine Green",
      "Sweet Orange Spice",
      "Orchid Vanilla",
      "Apple Red",
      "Fresh Vegetable Salad",
      "Turkey Wrap",
      "Tea Cookies",
      "Appel Strudel"
   }));
   set_menu_long(({
      "%^BOLD%^This %^RESET%^white tea %^BOLD%^is heightened with the "+
         "zing of %^RED%^c%^RESET%^%^RED%^i%^ORANGE%^n%^BOLD%^%^RED%^na"+
         "%^RESET%^%^ORANGE%^m%^RED%^o%^BOLD%^n %^WHITE%^and an undertone "+
         "of %^RESET%^%^CYAN%^wis%^GREEN%^p%^CYAN%^y s%^GREEN%^a%^CYAN%^"+
         "ge%^BOLD%^%^WHITE%^.%^RESET%^\n",
      "%^BOLD%^%^GREEN%^This exceptional %^RESET%^%^GREEN%^green tea "+
         "%^BOLD%^is married with intoxicatingly fragrant %^WHITE%^"+
         "j%^RESET%^%^ORANGE%^a%^BOLD%^s%^WHITE%^mi%^RESET%^%^ORANGE%^"+
         "n%^BOLD%^%^WHITE%^e bl%^RESET%^%^ORANGE%^o%^BOLD%^%^WHITE%^"+
         "ss%^ORANGE%^o%^RESET%^%^ORANGE%^m%^BOLD%^%^WHITE%^s"+
         "%^GREEN%^.%^RESET%^\n",
      "%^BOLD%^%^BLACK%^This enticing rich %^RESET%^black tea "+
         "%^BOLD%^%^BLACK%^has the sweet, exotic taste of %^ORANGE%^"+
         "m%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^"+
         "a%^RESET%^%^ORANGE%^r%^BOLD%^i%^RESET%^%^ORANGE%^n %^BOLD%^"+
         "o%^RESET%^%^ORANGE%^r%^BOLD%^a%^RESET%^%^ORANGE%^n%^BOLD%^"+
         "g%^RESET%^%^ORANGE%^e%^BOLD%^s%^BLACK%^, accented with "+
         "zingy notes of %^RED%^c%^RESET%^%^RED%^i%^ORANGE%^n%^BOLD%^"+
         "%^RED%^na%^RESET%^%^ORANGE%^m%^RED%^o%^BOLD%^n%^BLACK%^.%^RESET%^\n",
      "%^BOLD%^%^BLACK%^Exceptional %^RESET%^black tea %^BOLD%^"+
         "%^BLACK%^leaves are blended with %^RESET%^vanilla %^BOLD%^"+
         "%^BLACK%^and delicate shavings of tropical %^RESET%^coconut"+
         "%^BOLD%^%^BLACK%^.%^RESET%^\n",
      "%^BOLD%^%^RED%^This %^RESET%^%^RED%^red tea %^BOLD%^has the "+
         "taste of fresh crisp %^RESET%^%^RED%^apples%^BOLD%^, the "+
         "euphoric flavor of delicious, deep %^BLACK%^d%^RESET%^%^ORANGE%^"+
         "a%^BOLD%^%^BLACK%^rk c%^RESET%^%^ORANGE%^ho%^BOLD%^%^BLACK%^"+
         "col%^RESET%^%^ORANGE%^at%^BOLD%^%^BLACK%^e%^RED%^, and a "+
         "tingle of c%^RESET%^%^RED%^i%^ORANGE%^n%^BOLD%^%^RED%^na"+
         "%^RESET%^%^ORANGE%^m%^RED%^o%^BOLD%^n.%^RESET%^\n",
      "%^BOLD%^%^GREEN%^Fresh green %^RESET%^%^GREEN%^leaf lettuce "+
         "%^BOLD%^tossed with %^RESET%^%^GREEN%^zucchini%^BOLD%^, "+
         "%^RESET%^%^GREEN%^cucumbers%^BOLD%^, %^RED%^tomatoes%^GREEN%^, "+
         "%^RESET%^%^ORANGE%^carrots%^BOLD%^%^GREEN%^, %^RESET%^%^MAGENTA%^"+
         "red cabbage%^BOLD%^%^GREEN%^, and homemade %^BLACK%^Honey Poppy "+
         "Seed %^GREEN%^dressing.%^RESET%^\n",
      "%^ORANGE%^Turkey %^CYAN%^and %^BOLD%^%^RED%^roasted %^RESET%^"+
         "%^RED%^red %^BOLD%^peppers %^RESET%^%^CYAN%^are wrapped in"+
         "%^WHITE%^flatbread %^CYAN%^with %^BOLD%^cheese%^RESET%^"+
         "%^CYAN%^, %^ORANGE%^watercress%^CYAN%^, %^BOLD%^%^GREEN%^"+
         "spinach leaves %^RESET%^%^CYAN%^and a touch of %^ORANGE%^"+
         "horseradish%^CYAN%^. Served with some %^ORANGE%^fried potato "+
         "chips%^CYAN%^.%^RESET%^\n",
      "%^BOLD%^A small plate of %^RESET%^c%^ORANGE%^o%^BOLD%^"+
         "%^BLACK%^o%^RESET%^k%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^e"+
         "%^BOLD%^%^BLACK%^s%^RESET%^\n",
      "%^BOLD%^%^GREEN%^Sweet %^RESET%^%^RED%^apples %^BOLD%^%^GREEN%^"+
         "are baked with %^BLACK%^raisins %^GREEN%^& %^RESET%^%^ORANGE%^"+
         "walnuts %^BOLD%^%^GREEN%^in a light, flakey %^RESET%^pastry"+
         "%^BOLD%^%^GREEN%^, finished with a dusting of %^RESET%^"+
         "powdered sugar%^BOLD%^%^GREEN%^.%^RESET%^\n"
   }));
}
