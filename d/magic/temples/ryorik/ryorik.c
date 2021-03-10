//Temple of Ryorik - created by Kassius 10/18
//updated by ~Circe~ 10/5/19
#include <std.h>
inherit "/std/temple";

#define MYELEMENT ({"%^RESET%^%^RED%^f%^BOLD%^i%^YELLOW%^r%^RESET%^%^RED%^e","%^RESET%^%^CYAN%^w%^BOLD%^a%^BLUE%^t%^CYAN%^e%^RESET%^%^CYAN%^r","%^RESET%^%^CYAN%^wind","%^BOLD%^%^WHITE%^sn%^CYAN%^o%^WHITE%^w","%^RESET%^%^ORANGE%^ea%^YELLOW%^r%^RESET%^%^ORANGE%^th","%^BOLD%^%^WHITE%^s%^RESET%^a%^BOLD%^n%^RESET%^d","%^BOLD%^%^WHITE%^i%^CYAN%^c%^WHITE%^e","%^BOLD%^%^BLACK%^sm%^RESET%^o%^BOLD%^%^BLACK%^ke"})

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(4);
   set_indoors(0);
   set_temple("ryorik");
   set_name("Shrine of Ryorik");
   set_short("%^RESET%^%^CYAN%^Shrine of Ryorik%^RESET%^");
   set_long("%^RESET%^%^%^CYAN%^Shrine of Ryorik%^RESET%^\n%^BOLD%^%^WHITE%^This immense landscape seems an impossibility, given that it is contained within %^RESET%^pale stone walls %^BOLD%^barely visible in the distance. A vast swath of land opens here, a fr%^CYAN%^i%^WHITE%^g%^CYAN%^i%^WHITE%^d t%^CYAN%^u%^WHITE%^n%^CYAN%^d%^WHITE%^r%^CYAN%^a %^WHITE%^at the northernmost point is a %^RESET%^%^CYAN%^blur %^BOLD%^%^WHITE%^through the %^RESET%^%^CYAN%^e%^BOLD%^n%^RESET%^%^CYAN%^d%^BOLD%^l%^RESET%^%^CYAN%^e%^BOLD%^ss %^WHITE%^s%^CYAN%^n%^WHITE%^o%^CYAN%^w%^WHITE%^s%^CYAN%^t%^WHITE%^or%^CYAN%^m%^WHITE%^s. Directly to the south is the complete opposite, %^RESET%^%^BLUE%^mirages %^WHITE%^and %^RESET%^%^GREEN%^oasis %^BOLD%^%^WHITE%^blend together in the %^RESET%^%^RED%^grueling heat %^BOLD%^%^WHITE%^of a %^RESET%^%^ORANGE%^desert%^BOLD%^%^WHITE%^. A %^RESET%^rocky shoreline %^BOLD%^travels the eastern edge of the land, which seems to border a massive %^RESET%^%^CYAN%^o%^BOLD%^c%^BLUE%^e%^RESET%^%^BLUE%^a%^CYAN%^n%^BOLD%^%^WHITE%^, waves clashing against it as a constant %^RESET%^%^MAGENTA%^breeze %^BOLD%^%^WHITE%^flows from the east towards the %^BLACK%^mountainous %^WHITE%^west. A %^MAGENTA%^breathtaking %^WHITE%^mountain range stands on the western border with %^CYAN%^s%^WHITE%^no%^CYAN%^w%^WHITE%^-c%^CYAN%^o%^WHITE%^ve%^CYAN%^r%^WHITE%^e%^CYAN%^d %^WHITE%^p%^CYAN%^e%^WHITE%^a%^CYAN%^ks %^WHITE%^dipping into %^RESET%^%^GREEN%^rich valleys %^BOLD%^%^WHITE%^that fade quickly from view. The four unique areas being so close together causes many %^BLACK%^n%^GREEN%^a%^BLACK%^t%^GREEN%^u%^BLACK%^r%^GREEN%^a%^BLACK%^l p%^GREEN%^h%^BLACK%^e%^GREEN%^n%^BLACK%^o%^GREEN%^m%^BLACK%^e%^GREEN%^n%^BLACK%^a %^WHITE%^that %^RESET%^%^CYAN%^ebb %^BOLD%^%^WHITE%^and %^CYAN%^flow%^WHITE%^, dancing around each other, no element ever gaining the upper hand. In the direct center of the land sits an altar that shifts from a %^RESET%^mammoth granite rock %^BOLD%^hewn from the %^BLACK%^bones %^WHITE%^of the %^RESET%^%^ORANGE%^world %^BOLD%^%^WHITE%^to a %^RESET%^%^RED%^molten pillar %^BOLD%^%^WHITE%^of %^RED%^fire %^WHITE%^and %^RED%^m%^ORANGE%^a%^RED%^gm%^ORANGE%^a %^WHITE%^only to be sucked up into a vast %^BLACK%^m%^BLUE%^a%^BLACK%^e%^BLUE%^l%^BLACK%^s%^BLUE%^t%^BLACK%^r%^BLUE%^o%^BLACK%^m %^WHITE%^of %^RESET%^%^CYAN%^water %^BOLD%^%^WHITE%^and %^CYAN%^ice%^WHITE%^. The only constant is a glowing image of a %^CYAN%^scimitar %^WHITE%^suspended above the altar and the %^BLACK%^b%^GREEN%^re%^BLACK%^ath%^GREEN%^l%^BLACK%^e%^GREEN%^ss %^BLACK%^s%^GREEN%^i%^BLACK%^l%^GREEN%^e%^BLACK%^n%^GREEN%^ce %^WHITE%^that envelops the immediate area around it.%^RESET%^");
   set_items(([
      ({"tundra","frigid tundra","snowstorms"}) : "The northern portion of this temple is a %^BOLD%^%^WHITE%^fr%^CYAN%^i%^WHITE%^g%^CYAN%^i%^WHITE%^d t%^CYAN%^u%^WHITE%^n%^CYAN%^d%^WHITE%^r%^CYAN%^a %^RESET%^that stretches as far as the eye can see - which isn't very far, considering the %^BOLD%^%^WHITE%^s%^CYAN%^n%^WHITE%^o%^CYAN%^w%^WHITE%^s%^CYAN%^t%^WHITE%^or%^CYAN%^m%^WHITE%^s %^RESET%^that rage ceaselessly. %^BOLD%^%^BLACK%^Shadows %^RESET%^lurk within, though it is difficult to tell if they are trees, animals, or perhaps something more sinister.",
      ({"mirage","mirages","oasis","desert"}) : "%^RED%^Heat %^RESET%^rises in %^BOLD%^w%^RESET%^a%^BOLD%^v%^RESET%^e%^BOLD%^s%^RESET%^ in the %^ORANGE%^desert %^RESET%^to the south, creating treacherous, shimmering illusions that could lead the unwary to their deaths. With the way patches of green that could be either %^BLUE%^mirages %^RESET%^or %^GREEN%^oases%^RESET%^ rise in the distance, perhaps it is better to stay in the relative safety of the middle of the temple.",
      ({"shoreline","walls","temple"}) : "The massive stone blocks making up the walls of the temple give way to the sh%^BOLD%^o%^RESET%^rel%^YELLOW%^i%^RESET%^ne to the east. From the outside, the temple seemed to be perched atop a promontory, but here that illusion gives way to a stretch of beach inviting the %^RESET%^%^CYAN%^o%^BOLD%^c%^BLUE%^e%^RESET%^%^BLUE%^a%^CYAN%^n wa%^BOLD%^v%^RESET%^%^CYAN%^es%^RESET%^. A constant %^MAGENTA%^breeze %^RESET%^blows in off the sea, bringing with it the fragrance of the saltwater.",
      ({"ocean","sea","waves"}) : "The crystalline %^RESET%^%^CYAN%^o%^BOLD%^c%^BLUE%^e%^RESET%^%^BLUE%^a%^CYAN%^n %^RESET%^is breathtaking in its beauty. Sparkling %^CYAN%^b%^BOLD%^l%^BLUE%^u%^RESET%^%^CYAN%^e %^RESET%^and %^GREEN%^gr%^CYAN%^e%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^n%^RESET%^ beneath the brilliant %^YELLOW%^sun%^RESET%^, the %^BOLD%^white-capped waves%^RESET%^ lap onto the shore while %^BOLD%^%^BLACK%^dark shadows %^RESET%^swim in the depths.",
      ({"mountain","mountains","mountain range","peaks","valleys"}) : "To the west, a mountain range climbs toward the sky, its %^BOLD%^%^CYAN%^s%^WHITE%^no%^CYAN%^w%^WHITE%^-c%^CYAN%^o%^WHITE%^ve%^CYAN%^r%^WHITE%^e%^CYAN%^d %^WHITE%^p%^CYAN%^e%^WHITE%^a%^CYAN%^ks%^RESET%^ nearly brushing the %^CYAN%^cl%^BOLD%^o%^RESET%^%^CYAN%^uds%^RESET%^. The %^GREEN%^tree-lined slopes %^RESET%^are dotted here and there with %^GREEN%^lush valleys %^RESET%^that glint %^GREEN%^green %^RESET%^and rich %^ORANGE%^brown%^RESET%^ with hints of %^RED%^r%^BOLD%^i%^RESET%^%^ORANGE%^o%^YELLOW%^t%^GREEN%^o%^RESET%^%^GREEN%^u%^CYAN%^s %^BOLD%^c%^BLUE%^o%^WHITE%^l%^MAGENTA%^o%^RESET%^%^MAGENTA%^r%^RESET%^.",
      ({"altar","scimitar"}) : "The altar at the center of the temple is truly a wonder, a melding of elements from %^BOLD%^%^BLACK%^gr%^RESET%^a%^BOLD%^%^BLACK%^ni%^WHITE%^t%^BLACK%^e %^RESET%^and %^BOLD%^%^RED%^m%^YELLOW%^a%^RED%^gm%^YELLOW%^a %^RESET%^supporting a towering %^BOLD%^%^BLACK%^m%^BLUE%^a%^BLACK%^e%^BLUE%^l%^BLACK%^s%^BLUE%^t%^BLACK%^r%^BLUE%^o%^BLACK%^m %^RESET%^of %^RESET%^%^CYAN%^water %^RESET%^and %^BOLD%^%^CYAN%^ice%^RESET%^ that seems to defy the very laws of nature. Within the swirling %^BOLD%^%^BLACK%^m%^BLUE%^a%^BLACK%^e%^BLUE%^l%^BLACK%^s%^BLUE%^t%^BLACK%^r%^BLUE%^o%^BLACK%^m %^RESET%^ hovers a glowing %^BOLD%^%^CYAN%^scimitar %^RESET%^that draws the eye."
   ]));
   set_smell("default","The air is filled with natural scents that mingle with fresh water and a hint of the seas.");
   set_listen("default","The commotion and noise of the natural disasters fades as you approach the altar.");
   set_exits(([
      "out": "/d/dagger/Torm/road/path50"
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
   add_action("look","look");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Ryorik charges his followers with this message:%^RESET%^%^CYAN%^
Feel the freedom of the natural world. Run free like the wind, and obey your own moral code as devoutly as the stone. Care little for taming the elements, but revel in their power, respecting each force's natural dominion. Help others see that the storms are not to be bound and tamed, but to be unleashed, shared and respected. Let those who would manipulate and abuse them feel the unbridled touch of true elemental power. Fear not natural elemental destruction as it is the basis for growth and life.

%^RESET%^---

%^BOLD%^Ryorik has developed the following relationships:
%^RESET%^%^CYAN%^Allies: %^RESET%^Nim'navanon
%^CYAN%^Enemies: %^RESET%^None

%^CYAN%^*NOTE:%^WHITE%^ Being an ally or enemy does not necessarily mean you must aid or kill on sight. Determine the best course of action for your character based on your character's beliefs, the other individual(s) in question, and past actions/interactions with the individual(s) and/or their faith.
CHARGE
   );
   return 1;
}

int look(string str){
   string myelem;
   if(!str){
      return 0;
   }
   if(str == "phenomena" || str == "natural phenomena" || str == "phenomenon" || str == "elements"){
      myelem = MYELEMENT[random(sizeof(MYELEMENT))];
      switch(random(3)){
         case 0..1:  tell_object(TP,"As you watch, "+myelem+" %^RESET%^suddenly flares to life, rising over the %^BOLD%^%^BLACK%^c%^GREEN%^h%^BLACK%^a%^GREEN%^o%^BLACK%^t%^GREEN%^i%^BLACK%^c %^GREEN%^s%^BLACK%^w%^GREEN%^i%^BLACK%^r%^GREEN%^l %^RESET%^of elements before settling back into its relative harmony.");
                     break;
         default: tell_object(TP,"The %^RESET%^%^CYAN%^elements %^RESET%^dance in a %^BOLD%^%^BLACK%^c%^GREEN%^h%^BLACK%^a%^GREEN%^o%^BLACK%^t%^GREEN%^i%^BLACK%^c %^GREEN%^s%^BLACK%^w%^GREEN%^i%^BLACK%^r%^GREEN%^l %^RESET%^that makes it difficult to separate them.");
                     break;
      }
      if(!TP->query_invis()){
         tell_room(ETP,""+TPQCN+" peers curiously at the %^BOLD%^%^BLACK%^n%^GREEN%^a%^BLACK%^t%^GREEN%^u%^BLACK%^r%^GREEN%^a%^BLACK%^l p%^GREEN%^h%^BLACK%^e%^GREEN%^n%^BLACK%^o%^GREEN%^m%^BLACK%^e%^GREEN%^n%^BLACK%^a %^RESET%^created by the swirling elements.",TP);
         return 1;
      }
      return 1;
   }
   return 0;
}
