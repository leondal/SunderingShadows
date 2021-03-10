// Rosalyn, bartender for the Pig and Whistle in Tabor by Circe
#include <std.h>

inherit "/std/barkeep";

void create() {
  ::create();
  set_name("rosalyn");
  set_id( ({ "rosalyn", "bartender","barkeep","wench","beer wench","Rosalyn" }) );
  set_short("Rosalyn, beer wench of the Pig and Whistle");
  set_level(10);
  set_long(
     "Rosalyn is a robust young entrepreneur who runs the "+
     "Pig and Whistle with a determined air.  Despite the "+
     "fact that her customers are mostly soldiers who love "+
     "a pretty face, Rosalyn has decided to stay on at the "+
     "bar, realizing that her mere presence is enough to "+
     "bring the soldiers in at night.  She is a young woman "+
     "in her mid twenties, and she has long black hair pulled "+
     "back into a low ponytail of rolling waves that reach "+
     "her waist.  She has cool blue eyes filled with shrewdness, "+
     "and her creamy skin becomes flushed as she works hard at the "+
     "bar, giving her face a bit of color.  She is dressed in "+
     "a well-fitting white shirt above tight black breeches with "+
     "black leather boots reaching her knees.  It is no secret "+
     "that Rosalyn doesn't mind bringing in business with her "+
     "looks - but if anyone tries to push that relationship, "+
     "they may quickly find themselves out on the streets."
  );
  set_gender("female");
  set_exp(20);
  set_alignment(1);
  set_race("human");
  set_hd(10,0);
  set_hp(100);
  set_max_hp(query_hp());
  add_money("gold", random(10));
  set_body_type("human");
  set_currency("silver");
  set_menu(
       ({ "daydream","strawberry lemonade","squealing pansy","ginger peach cocktail",
          "stout ale","witch's brew","hairball","dirty dog","whiskey","tequila",
          "vodka","cognac","fish and chips","blood pudding","meat pie","roasted venison" }),
       ({ "soft drink","soft drink","water","soft drink","alcoholic",
          "alcoholic","alcoholic","alcoholic","alcoholic","alcoholic",
          "alcoholic","alcoholic","food","food","food","food"}),
       ({25,15,30,35,15,60,40,35,25,25,25,25,15,10,10,30})
   );
   set_my_mess(({
       "The sweet taste of passion fruit brings an innocent smile to your lips.\n",
       "The cool, refreshing glass of strawberry lemonade is wonderful.\n",
       "You squeal with delight and smile as you finish the water.\n",
       "The peach ginger cocktail is cool, smooth, and refreshing.\n",
       "You down the ale and slam the mug.  Damn, that's good.\n",
       "Smooth and tasty - the cranberry almost masks the vodka.\n",
       "You feel your throat burn from the whiskey through the sweetness of apple cider.\n",
       "The drink goes down smooth with the tang of cranberries.\n",
       "Your throat constricts as you slam down the whiskey.\n",
       "You down the tequila then suck on the lime.  Mmm...good.\n",
       "You throw back the vodka and feel your throat burn.\n",
       "The smooth, aged cognac packs quite a bite.\n",
       "The tangy taste of salt and vinegar enhances the flaky fish and chips.\n",
       "The blood pudding is gelatinous with a metallic tang.\n",
       "The flavorful meat mixes well with the buttery pastry.\n",
       "The fragrant aroma of cloves rises as you eat the venison.\n"
       }));
   set_your_mess(
       ({
       "drinks the daydream and smiles as sweetly as a young girl.\n",
       "drinks a glass of strawberry lemonade.\n",
       "drinks the water and squeals like a young girl.\n",
       "enjoys a cool ginger peach cocktail.\n",
       "throws back a mug of thick ale and slams the glass.\n",
       "drinks the witch's brew.\n",
       "drinks the hairball and coughs.\n",
       "enjoys a tall dirty dog.\n",
       "slams down a shot of whiskey.\n",
       "slams down a shot of tequila and sucks a lime.\n",
       "slams down a shot of vodka.\n",
       "slams down a shot of cognac.\n",
       "eats the salty fish and chips.\n",
       "eats a gelatinous mound of blood pudding.\n",
       "enjoys a large meat pie.\n",
       "eats the roasted venison as the scent of cloves rises in the air.\n"
        })
    );
    set_menu_short(
        ({
        "Daydream",
        "Strawberry Lemonade",
        "Squealing Pansy",
        "Ginger Peach Cocktail",
        "Stout Ale",
        "Witch's Brew",
        "Hairball",
        "Dirty Dog",
        "Shot of Whiskey",
        "Shot of Tequila",
        "Shot of Vodka",
        "Shot of Cognac",
        "Fish and Chips",
        "Blood Pudding",
        "Meat Pie",
        "Roasted Venison"
        })
    );
    set_menu_long(
        ({
        "%^BOLD%^%^MAGENTA%^This fruity drink is made up of "+
           "%^RESET%^%^ORANGE%^passion fruit juice %^BOLD%^"+
           "%^MAGENTA%^and %^RESET%^%^ORANGE%^orange juice"+
           "%^BOLD%^%^MAGENTA%^, and is colored a light pink.  "+
           "A thin ring of sugar lines the top of the glass, "+
           "giving the drink added sweetness, while a slice of "+
           "orange has been added for garnish.%^RESET%^\n",
        "%^YELLOW%^This tall glass of %^RED%^strawberry "+
           "%^YELLOW%^lemonade looks refreshing and inviting.  "+
           "Cool beads of condensation run down the outside of "+
           "the glass, and a thin sliver of lemon provides a "+
           "nice yellow contrast to the %^MAGENTA%^pink drink"+
           "%^YELLOW%^.%^RESET%^\n",
        "%^BOLD%^This tall glass of cold water has been "+
           "dyed a light %^MAGENTA%^pink shade %^WHITE%^from "+
           "the %^MAGENTA%^pansy %^WHITE%^stuck near the top.  "+
           "A light %^YELLOW%^lemon scent %^WHITE%^rises "+
           "from the glass.%^RESET%^\n",
        "%^RESET%^%^ORANGE%^This ginger peach cocktail is made "+
           "from sliced ginger and peach nectar.  It is served "+
           "in a round glass that has five thin peach slices "+
           "arranged in a star at the bottom.  It looks smooth "+
           "and sweet.%^RESET%^\n",
        "%^RESET%^%^ORANGE%^Served in a thick glass mug, this "+
           "frothy ale has a deep brown color and a foamy head.  "+
           "The strong flavor makes it a favorite of soldiers and "+
           "the like who enjoy nothing more than a good night of "+
           "ale and bad jokes.%^RESET%^\n",
        "%^MAGENTA%^Rosalyn's own creation, the Witch's Brew was "+
           "named by the patrons of the Pig and Whistle rather "+
           "than by Rosalyn herself.  A tall glass is filled halfway "+
           "with vodka, then mixed with ginger, cranberry juice, "+
           "and grape juice, giving it a fruity flavor.%^RESET%^\n",
        "%^RED%^A thick, warm apple cider is the basis for this "+
           "cinnamon-laced drink.  Mixed with ale and whiskey, the "+
           "already-fermented cider becomes quite potent.  A "+
           "wonderful scent of cinnamon and apples rises from the "+
           "frothy mug.%^RESET%^\n",
        "%^MAGENTA%^Crushed cranberries give this drink its "+
           "deep purple hue.  They have been mixed with cognac, "+
           "vodka, and orange juice to form this drink that is "+
           "a favorite among the citizens of Tabor.%^RESET%^\n",
        "%^BOLD%^This is a shot of whiskey, from which a strong "+
           "odor rises.  It is served in a short shot glass.%^RESET%^\n",
        "%^BOLD%^%^GREEN%^This shot of tequila is served in a "+
           "short shot glass with a small slice of salted lime.  "+
           "The thick liquid is amber and seems to swirl slowly "+
           "in the glass.%^RESET%^\n",
        "%^BOLD%^%^BLACK%^This shot of clear vodka is served "+
           "in a blackened shot glass, giving it the nickname "+
           "'Black Death' in Tabor.  The soldiers there use it "+
           "to test out a new recruit, having him drink until "+
           "he passes out.  The number of shots before he blacks "+
           "out becomes equal to his new rank in the social "+
           "structure of the militia.%^RESET%^\n",
        "%^YELLOW%^This shot of cognac is thick and served "+
           "in a short shot glass.  It is golden in the light, "+
           "and a pungent odor rises from it.%^RESET%^\n",
        "%^BOLD%^This is a large platter of lightly breaded "+
           "fish fried and placed alongside fried potatoes.  "+
           "It looks like a hearty meal, likely to be very "+
           "filling.  It has been sprinkled liberally with "+
           "salt and vinegar.%^RESET%^\n",
        "%^RED%^This small plate is piled high with a mound "+
           "of gelatinous blood pudding.  The pudding is the "+
           "ruddy hue of %^BOLD%^blood%^RESET%^%^RED%^, its "+
           "main ingredient.  Thin slices of hard bread are "+
           "placed around the platter.",
        "%^ORANGE%^This is a flaky square pastry filled with "+
           "delicious meat and a thick brown gravy.  It is "+
           "rather simple fare, but a favorite among all the "+
           "citizens of Tabor.  The fragrant scent of roasted "+
           "meat and spices rises from the still piping hot "+
           "pastry.%^RESET%^\n",
        "%^RED%^This is a large slice of roasted venison, "+
           "covered in thick gravy and garnished with cloves.  "+
           "The gravy seems to be made of cloves, cinnamon, and "+
           "other spices and is actually rather sweet, enhancing "+
           "the otherwise gamey taste of the venison.  Venison "+
           "such as this is caught in the forests around Tabor.%^RESET%^\n"
        })
    );
}

void init(){
   ::init();
   add_action("buy_em","buy");
}

void receive_given_item(object ob){
   if((string)ob->query_short() == "An empty bottle" ||
      (string)ob->query_name() == "bottle"){
      force_me("emote puts away the empty bottle.");
      ob->remove();
   }
}

int buy_em(string str){
   if(str == "squealing pansy" || str == "ginger peach cocktail" || str == "strawberry lemonade" || str == "daydream"){
         switch(random(4)){
            case 0:  tell_object(TP,"As you ask for a "+str+", "+
                        "a big man in the back yells, 'Are "+
                        "ya as sweet as ya look?'");
                     tell_room(ETO,"As "+TPQCN+" asks for a "+str+", "+
                        "a big man in the back yells, 'Are "+
                        "ya as sweet as ya look?'",TP);
                     break;
            case 1:  tell_object(TP,"A table in the corner gathers as one "+
                        "of the patrons whispers, then they all give "+
                        "hoots of laughter and cat calls as you "+
                        "order a "+str+".");
                     tell_room(ETO,"A table in the corner gathers as one "+
                        "of the patrons whispers, then they all give "+
                        "hoots of laughter and cat calls as "+TPQCN+" "+
                        "orders a "+str+".",TP);
                     break;
            case 2:  tell_object(TP,"One of the soldiers stands up and "+
                        "dances beside his table, prancing about after "+
                        "you order a "+str+".");
                     tell_room(ETO,"One of the soldiers stands up and "+
                        "dances beside his table, prancing about after "+
                        ""+TPQCN+" orders a "+str+".",TP);
                     break;
            case 3:  tell_object(TP,"Laughter resounds around the bar as "+
                        "you order a "+str+".");
                     tell_room(ETO,"The patrons of the bar burst into "+
                        "laughter as "+TPQCN+" orders a "+str+".",TP);
                     break;
         }
      return 0;
   }
   if(str == "stout ale"){
      if(!random(4)){
         tell_object(TP,"A chorus of 'Aye!' rises from one of the tables "+
            "as the soldiers raise their glasses to you.");
         tell_room(ETO,"A group of soldiers raise their glasses to "+
            ""+TPQCN+" as "+TP->QS+" orders a stout ale.",TP);
      }
      return 0;
   }
   return 0;
}