#include <std.h>
#include "../tecqumin.h"


inherit OBJECT;
string text;

void set_text(string name){
  switch (random(7)){
  case 0:
    text = "On this " + name+", you can see a scene of agricultural life."
          +" Bare chested men and women, dressed in short woven kilts"
          +" toil in terraced fields to harves crops of millet, rice and"
          +" maize. A cattle herder can be seen warding off the attack of"
          +" a predatory wemic with his eyes on the Tecqumin herd.";
    break;
  case 1:
    text = "On this " + name+", a combination of %^BOLD%^%^GREEN%^gr"
          +"%^RESET%^%^GREEN%^ee%^BOLD%^%^GREEN%^n%^RESET%^, %^BOLD%^"
          +"%^BLUE%^bl%^CYAN%^u%^BLUE%^e%^RESET%^ and %^BOLD%^"
          +"%^WHITE%^white%^RESET%^ glazes has been used to depict a"
          +" great ziggurat rising from a jungle city, its zenith"
          +" stretching into an %^BOLD%^%^BLUE%^az%^CYAN%^u%^BLUE%^re"
          +" %^CYAN%^s%^WHITE%^k%^CYAN%^y%^RESET%^ dotted with softly"
          +" drifting %^BOLD%^%^WHITE%^white clouds%^RESET%^.";
    break;
  case 2:
    text = "This "+ name+ "bears a number of religious scenes, centred"
          +" around what looks lile a mass %^ORANGE%^human%^RESET%^"
          +" sacrifice. A crowd of Tecqumin stand before a massive"
          +" ziggurat, at the top of which a robed and masked figure cuts"
          +" the %^BOLD%^%^RED%^h%^RESET%^%^RED%^ea%^BOLD%^%^RED%^rt"
          +"%^RESET%^ from a helpless victim, holding it aloft before the"
          +" burning orb of the %^ORANGE%^s%^YELLOW%^u%^RESET%^"
          +"%^ORANGE%^n%^RESET%^ while gathered acolytes gather the"
          +" pouring %^RED%^blood%^RESET%^ in an earthenware bowl";
    break;
  case 3:
    text = "A rural scene is depicted here. In a small farmstead, a woman"
          +" gives birth while her husband and children look on. There"
          +" are a number of children already in the household and it is"
          +" clear that the stores of food are depleted. After the"
          +" child's birth, it is wrapped in swaddling and placed alone"
          +" on an exposed hillside. Much sadness is shown as the tamily"
          +" sheds tears, but the food stores last them through a period"
          +" of want.";
    break;
  case 4:
    text = "On this " + name + ", the Tecqumin people can be seen going"
          +" to %^RED%^war%^RESET%^. Arming themselves with knives, short"
          +" swords, adzes, sickles, clubs, spears and spear throwers,"
          +" they gather under the direction of some great religious or"
          +" political leader and march to wreak havoc in the lands of"
          +" their enemies. Prisoners are slain in their hundreds and"
          +" thousands, sacrificed before the image of the %^YELLOW%^sun"
          +"%^RESET%^, and their %^BOLD%^%^WHITE%^bl%^RESET%^ea%^BOLD%^"
          +"%^WHITE%^ched white sk%^RESET%^u%^BOLD%^%^WHITE%^lls^RESET%^"
          +" are piled in pyramids to rival the height of the Tecqumin's"
          +" mighty ziggurats.";
    break;
  case 5:
    text = "This " + name + " has a representation of a Tecqumin"
          +" festival. Great crowds gather around the temples and palaces"
          +" of the city and there are ritual dances, feasts and"
          +" celebrations. There also appears to be a strange game"
          +" represented, the aim of which appears to be to maneuver a"
          +" rubber ball through a vertical stone hoop placed ten feet up"
          +" in the wall of the playing area. The players seem to touch"
          +" the ball with every part of their bodies except their"
          +" hands.";
    break;
  case 6:
    text = "In amongst the decorations of this " + name + " is a vivid"
          +" depiction of a busy market in the centre of a thriving city."
          +" Right at the heart of the market, a slave block gathers the"
          +" biggest crowds as captured enemies and convicted criminals"
          +" are sold off to the highest bidder, some bound for household"
          +" or agricultural service, but many bound for the sacrificial"
          +" altar";
    break;
  }
}

string query_text(){
  return text;
}