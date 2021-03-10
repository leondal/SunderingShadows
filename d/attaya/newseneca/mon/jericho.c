// Adelina, barkeep for 
#include <std.h>

inherit BARKEEP;

void create() {
  ::create();
  set_name("jericho");
  set_id(({"jericho","Jericho","salt merchant","barkeep","bartender"}));
  set_short("Jericho, the old Salt Merchant");
  set_long("%^RESET%^%^CYAN%^Dressed in a %^BOLD%^%^WHITE%^white shirt "+
     "%^RESET%^%^CYAN%^with billowing sleeves beneath a %^BOLD%^%^BLUE%^"+
     "blue vest %^RESET%^%^CYAN%^with %^ORANGE%^brass buttons%^CYAN%^, "+
     "Jericho presents the very image of a %^BOLD%^sailor%^RESET%^%^CYAN%^"+
     ".  Puffy %^BOLD%^%^BLACK%^black pants %^RESET%^%^CYAN%^are tucked "+
     "into his %^BOLD%^%^BLACK%^boots%^RESET%^%^CYAN%^, which are laced "+
     "to the knee.  His aging face is grizzled from wind and sun, and he "+
     "has a perpetual %^ORANGE%^tan %^RESET%^%^CYAN%^that provides a sharp "+
     "contrast to his stark %^BOLD%^%^WHITE%^white beard%^RESET%^%^CYAN%^.  "+
     "He is rumored to be bald beneath the %^BOLD%^%^BLACK%^black hat "+
     "%^RESET%^%^CYAN%^he wears, but few are brave enough to try to find "+
     "out.  A long, fading %^BOLD%^%^WHITE%^scar %^RESET%^%^CYAN%^runs from "+
     "the corner of his merry %^BOLD%^%^GREEN%^green eyes %^RESET%^"+
     "%^CYAN%^to the left corner of his mouth, stretching to a thin line "+
     "with his customary smile.  Many odd %^BOLD%^tattoos %^RESET%^%^CYAN%^peek "+
     "from the edges of his clothing, though you cannot get a good view "+
     "of any of them.%^RESET%^");
  set_gender("male");
  set_level(20);
  set_exp(20);
  set_alignment(1);
  set_race("human");
  set_hd(20,20);
  set_hp(250);
  set_max_hp(query_hp());
  add_money("gold", random(10));
  set_body_type("human");
  set_currency("silver");
  set_menu(
       ({"salty dog","butterball","seneca dust","beshaba's kiss","prairie fire","three priests","oyster shooter","seneca sunrise","sea breeze","ambrosia","belladonna","bellini","tequila","rum","gin","brandy","vodka","attaya ale","bruiser","mercenary's milk","seafarer's slop","shrimp empanadas","fish cakes","rag pudding","fisherman's paella","briny deep","coconut milk","pomegranate juice"}),
      ({"alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic", "alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","alcoholic","food","food","food","food","water","soft drink","soft drink"}),
       ({35,30,40,90,25,50,80,35,35,75,80,70,60,25,25,25,25,25,15,25,30,60,35,45,50,60,15,25,25})
   );
   set_my_mess(({
       "The sting of grapefruit juice does nothing to sooth the burn of the vodka.  Lucky there was salt to...dull...it.\n",
       "You down the buttery concoction, marvelling at its creamy taste.\n",
       "You taste an astonishing blend of coffee and cinnamon mixed with tart pineapple.  Odd...\n",
       "You feel you've drawn the gaze of Beshaba for sure as you down the vile concoction.\n",
       "In one gulp, you slam the tequila, feeling the hot sauce burn.\n",
       "Three holy flavors of tequila, mint, and cinnamon blend as you take the shot.\n",
       "The slimy oyster wriggles down your through as you finish the shot, tasting horseradish and beer.\n",
       "You taste the pomegranate lightly mixed in over the orange juice and tequila.\n",
       "Drinking the Sea Breeze, you suck on the lime as the flavors of vodka, cranberry, and grapefruit mingle on your tongue.\n",
       "The bubbly champagne adds to the flavor of apple as you drink the ambrosia.\n",
       "The citrus flavors of pineapple and orange nearly mask the rum with just a hint of cranberry.\n",
       "You sip the frozen drink, enjoying the cool refreshment of champagne and peaches.\n",
       "Licking the salty rim, you slam back the tequila shot and suck on the lime.\n",
       "You notice a hint of coconut as the rum burns your throat.\n",
       "The gin makes your eyes water as you down it in one gulp.\n",
       "A hint of apricot reaches you as you take the brandy shot.\n",
       "You nearly choke as you down the vodka.\n",
       "Nothing quite like a good mug of ale.\n",
       "As you drink the ale, you taste the plums that give the bruiser its unique color.\n",
       "The light lager seems to lack flavor as you drink it.\n",
       "Belying its name, the Seafarer's Slop is smooth and robust.  Damn good!\n",
       "The empanadas are piping hot and filled with spiced shrimp.  Mmmm...\n",
       "The fish cake is a bit greasy, but tasty nonetheless.\n",
       "This rag pudding must be an acquired taste.  Still, the minced meat and onion is pretty good.\n",
       "You taste bits of fish, scallops, and calimari mixed among the saffron rice.\n",
       "Ugh...tastes as if it just came out of the sea.  It's water though.\n",
       "You drink the sweet milk of the coconut.\n",
       "The pomegranate juice has a pleasant mixture of sweet and tangy tastes.\n"
       }));
   set_your_mess(
       ({
       "drains a glass and blinks several times, wincing.\n",
       "drinks a glass of coffee-colored liquid and smiles.\n",
       "drinks the Seneca Dust and looks confused.\n",
       "drinks a gray drink, and you swear the room darkens.  Trick of the imagination, surely...\n",
       "slams back the tequila and pants.\n",
       "drinks the shot with wide eyes.\n",
       "sucks down the shot, swallowing the oyster.  Eww.\n",
       "enjoys a cool Seneca Sunrise.\n",
       "drains the tall glass and sucks on a slice of lime.\n",
       "enjoys a glass of ambrosia.\n",
       "drains a black highball glass with a secret smile.\n",
       "slowly drinks a frozen concoction.\n",
       "slams back the shot of tequila and sucks on a lime.\n",
       "downs the shot of rum and slams down the glass.\n",
       "downs the shot of gin and blinks with watery eyes.\n",
       "slams back the brandy and looks surprised.\n",
       "coughs and sputters drinking the vodka.\n",
       "drains a mug of ale.\n",
       "downs the purple ale.\n",
       "drinks the pale ale and looks vaguely disappointed.\n",
       "relishes a mug of dark ale.\n",
       "devours a couple of shrimp empanadas.\n",
       "eats a fish cake with greasy fingers.\n",
       "hesitantly eats the rag pudding.\n",
       "enjoys a large bowl of fisherman's paella.\n",
       "drinks the briny water and makes a face.\n",
       "drains the coconut milk from the shell.\n",
       "drinks the pomegranate juice with a quiet smile.\n"
        })
    );
    set_menu_short(
        ({"Salty Dog","Butterball","Seneca Dust","Beshaba's Kiss","Prairie Fire","Three Priests","Oyster Shooter","Seneca Sunrise","Sea Breeze","Ambrosia","Belladonna","Bellini","Shot of Tequila","Shot of Rum","Shot of Gin","Shot of Brandy","Shot of Vodka","Attaya Ale","Bruiser","Mercenary's Milk","Seafarer's Slop","Shrimp Empanadas","Fish Cakes","Rag Pudding","Fisherman's Paella","Briny Deep","Coconut Milk","Pomegranate Juice"})
    );
    set_menu_long(
        ({
        "Served in a highball tumbler, this drink is nearly clear "+
           "with a slightly %^YELLOW%^yellow %^RESET%^tint to it.  "+
           "It is concocted of %^BOLD%^vodka %^RESET%^and %^YELLOW%^"+
           "grapefruit juice%^RESET%^ and has a salted rim.\n",
        "%^ORANGE%^This yummy-looking drink is made from %^BOLD%^"+
           "%^BLACK%^coffee %^RESET%^%^ORANGE%^sweetened with a "+
           "special liquor called %^BOLD%^%^WHITE%^Kildare Cream "+
           "%^RESET%^%^ORANGE%^with just a hint of %^YELLOW%^"+
           "butterscotch%^RESET%^%^ORANGE%^.  Just looking at it "+
           "gives you the impression of being warm and cozy.%^RESET%^\n",
        "Seemingly an odd mix, this drink looks to have been made "+
           "with %^BOLD%^%^BLACK%^coffee-flavored liquor %^RESET%^"+
           "mixed with %^YELLOW%^pineapple juice%^RESET%^.  A "+
           "mixture of other %^MAGENTA%^fruit liquors %^RESET%^"+
           "heavy with %^ORANGE%^cinnamon %^RESET%^has been added, "+
           "creating a most unusual drink.\n",
        "%^BOLD%^%^BLACK%^The drink known as %^MAGENTA%^Beshaba's "+
           "Kiss %^BLACK%^comes in an innocuous-looking glass.  "+
           "It has become something of a legend among the people "+
           "of Seneca - sometimes used to protect one from Beshaba "+
           "by drinking it in her honor, and sometimes used as a "+
           "curse of sorts to bring down her %^RED%^ire %^BLACK%^"+
           "on an enemy.  The drink is made from the %^RESET%^"+
           "dregs %^BOLD%^%^BLACK%^left over from others' drinks.  "+
           "As such, it invariably has a %^RESET%^gray cast %^BOLD%^"+
           "%^BLACK%^and is none-too-safe.%^RESET%^\n",
        "The bottom of a shot glass has been filled with a layer of "+
           "%^BOLD%^%^RED%^hot sauce %^RESET%^made from the hottest "+
           "%^BOLD%^%^RED%^chili peppers %^RESET%^to be found.  "+
           "Topping it is a measure of %^ORANGE%^tequila%^RESET%^.  "+
           "This drink has become a favorite of the guardsmen of "+
           "Seneca, who use it as an initation rite for new "+
           "recruits.\n",
        "%^BOLD%^Known by many different names in different lands, "+
           "the recipe for this shot remains the same.  Equal "+
           "measures of %^RESET%^%^ORANGE%^tequila%^BOLD%^%^WHITE%^, "+
           "liquor flavored with %^GREEN%^mint%^WHITE%^, and that "+
           "of %^RESET%^%^ORANGE%^cinnamon%^BOLD%^%^WHITE%^ are "+
           "poured in the glass to make this unusual - and yet "+
           "somehow tasty - combination.%^RESET%^\n",
        "When he was a sailor, Jericho himself developed this "+
           "particular shot.  Viewed by many as a vile concoction "+
           "that must have come from one of the evil deities, "+
           "the shot includes a base of %^ORANGE%^beer %^RESET%^"+
           "mixed with %^BOLD%^%^RED%^cocktail sauce%^RESET%^, "+
           "%^BOLD%^horseradish%^RESET%^, and %^BOLD%^%^RED%^hot "+
           "pepper sauce%^RESET%^.  Topping it all is a %^BOLD%^"+
           "raw oyster%^RESET%^, meant to be swallowed along with "+
           "the drink.  Many find it a testament to their "+
           "courage if they can down this shot.\n",
        "%^YELLOW%^Formed primarily of %^RESET%^%^ORANGE%^orange "+
           "juice%^YELLOW%^, this cocktail also has a large shot "+
           "of %^WHITE%^tequila%^YELLOW%^.  It is sweetened with "+
           "a splash of %^MAGENTA%^pomegranate juice%^YELLOW%^, "+
           "which settles to help form the image of a "+
           "%^RESET%^%^MAGENTA%^su%^BOLD%^nr%^RED%^is%^YELLOW%^e, "+
           "for which it is named.%^RESET%^",
        "%^CYAN%^Refreshingly cool, just like its name, the %^BOLD%^"+
           "Sea Breeze %^RESET%^%^CYAN%^is made of %^RED%^cranberry "+
           "%^CYAN%^and %^YELLOW%^grapefruit %^RESET%^%^CYAN%^"+
           "juices mixed with %^BOLD%^%^WHITE%^vodka%^RESET%^"+
           "%^CYAN%^.  The rim of the tumbler has been edged with "+
           "%^BOLD%^%^WHITE%^sugar %^RESET%^%^CYAN%^and garnished "+
           "with a wedge of %^GREEN%^lime%^CYAN%^.%^RESET%^\n",
        "%^RED%^Apple brandy %^RESET%^adds the flavor to a sparkling "+
           "glass of %^BOLD%^%^CYAN%^champagne%^RESET%^.  The drink "+
           "is a light, refreshing choice for hot summer days, and "+
           "a sliver of %^YELLOW%^lemon %^RESET%^adds just a touch more.\n",
        "%^BOLD%^%^BLACK%^Served in an opaque black tumbler, the "+
           "%^GREEN%^Belladonna %^BLACK%^features light and dark "+
           "rum mixed with %^RED%^cranberry%^BLACK%^, %^YELLOW%^"+
           "pineapple%^BLACK%^, and %^RESET%^%^ORANGE%^orange "+
           "juices%^BOLD%^%^BLACK%^.  Named after deadly nightshade, "+
           "it is said that the enchanting flavor of this drink has "+
           "led more than one unsuspecting man to his death as he "+
           "doesn't know when to stop drinking.%^RESET%^\n",
        "%^BOLD%^Served in a fluted glass, this frozen drink seems "+
           "more of a dessert at times.  It is made from %^RESET%^"+
           "%^ORANGE%^pureed peaches %^BOLD%^%^WHITE%^mixed with "+
           "%^RESET%^champagne%^BOLD%^ and %^CYAN%^shaved ice%^WHITE%^.  "+
           "Just a hint of %^RED%^cherry %^WHITE%^adds the finishing "+
           "touch.%^RESET%^\n",
        "%^YELLOW%^This shot of tequila is served in a short shot glass rimmed "+
           "with %^WHITE%^salt %^YELLOW%^and garnished with a small "+
           "slice of %^GREEN%^lime%^YELLOW%^.  The thick liquid is "+
           "amber and seems to swirl slowly in the glass.%^RESET%^\n",
        "%^BOLD%^%^WHITE%^Served in a short shot glass, this rum is "+
           "completely transparent.  It gives off the faint odor of "+
           "coconut and is served with no garnish.%^RESET%^\n",
        "Utterly colorless, this shot is made up of %^BOLD%^gin "+
           "%^RESET%^lightly flavored with %^MAGENTA%^juniper "+
           "berries %^RESET%^and %^ORANGE%^orange peel%^RESET%^.  "+
           "Altogether, this would likely be a drink that burns.\n",
        "%^BOLD%^%^MAGENTA%^Light peach in color, the liquid in "+
           "this shot glass gives off a powerful aroma.  Blending "+
           "with the fragrance of pure alcohol is that of sweet "+
           "apricots.%^RESET%^\n",
        "As you stare at the shot of vodka, you cannot find much "+
           "to like about it.  From what you can tell, it is "+
           "pure alcohol - and damn likely to burn.\n",
        "%^ORANGE%^The standard brew of Attaya, this ale is "+
           "not too strong and not too weak.  It has a brown "+
           "tint with a bitter smell, and it is enjoyed "+
           "by many of the citizens of Seneca.%^RESET%^\n",
        "%^MAGENTA%^Fermented from plums, this ale retains a "+
           "purple hue that looks rather like a fresh bruise.  "+
           "It has a sweet flavor that many beer-drinkers cannot "+
           "adjust to.%^RESET%^\n",
        "%^ORANGE%^Named for an inept mercenary that often drank "+
           "this weak brew, Mercenary's Milk is a pale %^YELLOW%^"+
           "yellow %^RESET%^%^ORANGE%^in color.  It does not seem "+
           "to be ordered often by the locals, thought many tourists "+
           "order it.%^RESET%^\n",
        "%^ORANGE%^Ironically named, %^YELLOW%^Seafarer's Slop "+
           "%^RESET%^%^ORANGE%^is purportedly the best ale to "+
           "be found in Seneca.  It is deep brown, almost %^BOLD%^"+
           "%^BLACK%^black%^RESET%^%^ORANGE%^, with a thick "+
           "%^BOLD%^%^WHITE%^head%^RESET%^%^ORANGE%^.  A deep, "+
           "robust aroma rises from the mug, encouraging you to "+
           "drink.%^RESET%^\n",
        "%^ORANGE%^Fried to a golden brown, two %^YELLOW%^empanadas "+
           "%^RESET%^%^ORANGE%^lie on a simple wooden plate.  "+
           "Each has been stuffed with %^BOLD%^%^MAGENTA%^shrimp "+
           "%^RESET%^%^ORANGE%^and served piping hot.%^RESET%^\n",
        "A favorite creation for the soldiers of Seneca, this "+
           "unusual dish is made from two thin slices of %^BOLD%^"+
           "potato %^RESET%^with a %^ORANGE%^fish cake %^RESET%^"+
           "layered between them.  The whole dish is deep-fried "+
           "until its edges are %^ORANGE%^golden%^RESET%^ and "+
           "then eaten almost like a sandwich.\n",
        "The plate is covered with a rectangular %^BOLD%^pastry "+
           "%^RESET%^that has become lighter since being boiled.  "+
           "It is stuffed nearly to bursting with %^ORANGE%^"+
           "minced meat %^RESET%^and %^BOLD%^onions%^RESET%^ to "+
           "provide a soft, easy-to-eat meal.\n",
        "Considered by many to be the best dish Seneca has to "+
           "offer, the paella has %^YELLOW%^saffron rice %^RESET%^"+
           "as its base.  Mixed within are pieces of flaky "+
           "%^BOLD%^fish%^RESET%^, juicy %^BOLD%^%^MAGENTA%^"+
           "shrimp%^RESET%^, and tender %^BOLD%^calimari%^RESET%^.  "+
           "Special %^RED%^seasoning %^RESET%^has been added "+
           "to give this dish an extra kick.\n",
        "%^CYAN%^A glass tumbler has been filled with somewhat "+
           "cloudy %^RESET%^water%^CYAN%^.  Still, it seems your "+
           "best bet if you want something thirst-quenching here.%^RESET%^\n",
        "Technically %^BOLD%^coconut water%^RESET%^, this drink is "+
           "served in a %^ORANGE%^coconut shell %^RESET%^with the top "+
           "cut off to reveal the pulpy %^BOLD%^white %^RESET%^"+
           "interior.  The thin, milky liquid inside is "+
           "quite sweet with - naturally - a taste of %^BOLD%^"+
           "coconut%^RESET%^.\n",
        "Served in a %^BOLD%^%^CYAN%^wine glass%^RESET%^, this "+
           "%^BOLD%^%^MAGENTA%^pomegranate juice %^RESET%^is "+
           "far from alcoholic.  It is a sweet, tangy choice "+
           "for those who prefer not to drink.\n"
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
   if(str == "briny deep" && !random(2)){
      tell_object(TP,""+TOQCN+" fills a tumbler with gray-looking water "+
         "and hands it to you with a grin.  Snickering breaks out from the "+
         "patrons around you.");
      tell_room(ETO,""+TOQCN+" fills a tumbler with grayish water and "+
         "hands it to "+TPQCN+" accompanied by snickering from some of "+
         "the patrons.",TP);
      return 0;
   }
   if(str == "coconut milk" || str == "pomegranate juice" || str == "mercenary's milk" && !random(3)){
         switch(random(4)){
            case 0:  tell_object(TP,"As you turn from ordering your "+
                        ""+str+", one of the sailors bats his "+
                        "eyes at you with a grin.");
                     tell_room(ETO,"As "+TPQCN+" goes to order a "+
                        ""+str+", one of the sailors moves up behind "+
                        ""+TP->QO+".  When "+TPQCN+" turns around, "+
                        "the sailor bats his eyes and puckers up with "+
                        "a grin.",TP);
                     break;
            case 1:  tell_object(TP,"With mock solemnity, one of the "+
                        "guardsmen raises a glass and toasts you when "+
                        "you order a "+str+", much to the delight of "+
                        "his companions.");
                     tell_room(ETO,"A guardsmen raises his glass with "+
                        "mock solemnity and toasts "+TPQCN+" when "+
                        ""+TP->QS+" orders a "+str+", much to the "+
                        "delight of the guardsman's companions.",TP);
                     break;
            case 2:  tell_object(TP,"One of the sailors stands up and "+
                        "dances beside his table, prancing about after "+
                        "you order a "+str+".");
                     tell_room(ETO,"One of the sailors stands up and "+
                        "dances beside his table, prancing about after "+
                        ""+TPQCN+" orders a "+str+".",TP);
                     break;
            case 3:  tell_object(TP,"Laughter resounds around the bar as "+
                        "you order a "+str+".  Surely that wasn't meant for "+
                        "you...right?");
                     tell_room(ETO,"The patrons of the bar burst into "+
                        "laughter as "+TPQCN+" orders a "+str+".",TP);
                     break;
         }
      return 0;
   }
   if(str == "beshaba's kiss"){
      if(!random(3)){
         tell_object(TP,"A few patrons make signs to ward off evil as "+
            "you order the "+str+".");
         tell_room(ETO,"A few patrons make signs to ward off evil as "+
            ""+TPQCN+" orders a "+str+".  Not a superstitious lot at all.",TP);
      }
      return 0;
   }
   if(str == "prairie fire"){
      if(!random(3)){
         tell_object(TP,"Some of the guardsmen cheer and turn to watch as "+
            "you order the "+str+".");
         tell_room(ETO,"As "+TPQCN+" orders a "+str+", several of the "+
            "guardsmen cheer and turn to watch.",TP);
      }
      return 0;
   }
   if(str == "oyster shooter" && (string)TO->query_name() == "jericho"){
      if(!random(3)){
         tell_object(TP,"Jericho grins and pats you on the back as he "+
            "hands you the "+str+".");
         tell_room(ETO,"Jericho pats "+TPQCN+" on the back with a "+
            "grin.",TP);
         tell_room(ETO,"%^MAGENTA%^Jericho rumbles%^RESET%^: That'll "+
            "put hair on yer chest, that will.");
      }
      return 0;
   }
   if(str == "seafarer's slop"){
      if(!random(3)){
         tell_object(TP,"A group of sailors raises the chant, 'Drink! "+
            "Drink! Drink!' as you order the "+str+".");
         tell_room(ETO,"As "+TPQCN+" orders a "+str+", a group of "+
            "sailors raises the chant, 'Drink! Drink! Drink!'",TP);
      }
      return 0;
   }
   return 0;
}