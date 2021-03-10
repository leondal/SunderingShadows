// removed the staff until it can be better adjusted to suit the 3e system. N, 9/13.
#include "lair.h"
inherit ROOM;

int clothes, weapons, armor, trinkets, coins, gems, active, trapped;

void create(){
   ::create();
   set_name("An immense cavern");
   set_property("light",1);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_short("%^BLUE%^A small side cavern%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_smell("default","%^ORANGE%^The bitter, acrid smell of %^GREEN%^a%^BOLD%^c%^RESET%^%^GREEN%^id %^ORANGE%^itches at your nose.%^RESET%^");
   set_listen("default","%^GREEN%^You can hear a low hiss, much like %^RESET%^steam%^GREEN%^.%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^A small side cavern%^RESET%^\n"
"%^BLUE%^This cavern is much smaller than the one you just stepped in from.  It seems to be naturally formed, with "
"%^ORANGE%^rug%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^ed%^BLUE%^ stone walls and a scattering of stalagmites around the "
"floor's edges.  The roof is visible only a short distance above, dotted with stalactites casting long %^BOLD%^%^BLACK%^"
"sh%^RESET%^ad%^BOLD%^%^BLACK%^ows %^RESET%^%^BLUE%^against the stone.  A few %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^"
"%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^are scattered across the floor, but other than that it is quite empty"
".\n%^RESET%^");
   set_items( ([ 
     ({"walls","cavern","floor","roof","stalagmites","stalactites"}):"%^BLUE%^This cavern is seemingly naturally-formed, "
"with %^ORANGE%^rough sto%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^walls and stalagmites that dot the perimiter of "
"the area.  The roof is visible a short distance above your head, dotted with stalactites that cast long %^BOLD%^%^BLACK%^"
"sh%^RESET%^ad%^BOLD%^%^BLACK%^ows %^RESET%^%^BLUE%^against the stone.%^RESET%^",
   ]) );
   set_exits(([
     "south":ROOMS"lair",
   ]));
   clothes = 0;
   weapons = 0;
   armor = 0;
   trinkets = 0;
   coins = 0;
   gems = 0;
   active = 0;
   trapped = 0;
}

void init() {
   ::init();
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   add_action("take_fun","take");
   add_action("quit_func","quit");
   if(active && !trapped && !TP->query_true_invis()) {
     trapped = 1;
     tell_room(TO,"%^GREEN%^As you step in, you hear a click and hiss.  A cloud of %^BOLD%^acr%^WHITE%^i%^GREEN%^d gas "
"%^RESET%^%^GREEN%^rises from the floor and settles over the treasure before you.%^RESET%^");
     if((TP->query_skill("dungeoneering")+roll_dice(1,20)) > 35)
       tell_object(TP,"%^BOLD%^%^GREEN%^Looks like something just activated a trap...%^RESET%^");
     set_long("%^BOLD%^%^BLACK%^A small side cavern%^RESET%^\n"
"%^BLUE%^This cavern is much smaller than the one you just stepped in from.  It seems to be naturally formed, with "
"%^ORANGE%^rug%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^ed%^BLUE%^ stone walls and a scattering of stalagmites around the "
"floor's edges.  The roof is visible only a short distance above, dotted with stalactites that cast long %^BOLD%^%^BLACK%^"
"sh%^RESET%^ad%^BOLD%^%^BLACK%^ows %^RESET%^%^BLUE%^against the stone.  All of these details are hardly noticed though, "
"for what the cavern holds within itself is quite %^BOLD%^%^CYAN%^breathtaking%^RESET%^%^BLUE%^ to behold.  The floor is "
"covered from one end to the other in %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^"
"and %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^, fine %^RESET%^a%^GREEN%^r%^RESET%^two%^ORANGE%^r"
"%^RESET%^k%^BLUE%^, %^GREEN%^cl%^CYAN%^ot%^GREEN%^hi%^BOLD%^n%^RESET%^%^GREEN%^g%^BLUE%^, %^WHITE%^ar%^ORANGE%^mo"
"%^RESET%^r %^BLUE%^and %^BOLD%^%^BLACK%^we%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^pons%^RESET%^%^BLUE%^, %^MAGENTA%^ar%^BOLD%^t"
"%^RESET%^%^MAGENTA%^if%^CYAN%^ac%^MAGENTA%^ts %^BLUE%^of all kinds and many other things besides; more treasure than you "
"could possibly imagine to be in one place at the same time.  A low %^BOLD%^%^GREEN%^hi%^WHITE%^s%^GREEN%^s %^RESET%^"
"%^BLUE%^emanates from the entire pile, and you realise whole items are being disintegrated by acid as you watch"
"!\n%^RESET%^");
   }
}

void reset() {
   ::reset();
   switch(random(9)){
     case 0..1: tell_room(TO,"%^ORANGE%^From somewhere nearby you hear the quiet drip, drip of %^CYAN%^water%^ORANGE%^.%^RESET%^"); break;
     case 2: tell_room(TO,"%^CYAN%^A coin %^YELLOW%^clinks %^RESET%^%^CYAN%^underfoot, startlingly loud in the silence of "
"the cavern.%^RESET%^"); break;
     case 3..4: tell_room(TO,"%^GREEN%^The musty air tickles at your nose."); break;
     case 5: tell_room(TO,"%^BOLD%^%^BLACK%^A tiny %^RESET%^%^RED%^spider %^BOLD%^%^BLACK%^crawls over your foot and "
"across the floor.%^RESET%^"); break;
     case 6: tell_room(TO,"%^BOLD%^%^CYAN%^A chilling breath of %^WHITE%^wind %^CYAN%^brushes past you, making you "
"shiver.%^RESET%^"); break;
     case 7: tell_room(TO,"%^MAGENTA%^An uneasy feeling causes the hairs on the back of your neck tingle, sending %^CYAN%^"
"chills %^MAGENTA%^down your spine.%^RESET%^"); break;
     case 8: tell_room(TO,"%^RED%^The air is heavy and still, so silent you can hear your own %^MAGENTA%^heartbeat%^RED%^"
".%^RESET%^"); break;
     default: break;
   }
}

int quit_func(string str) {
   TP->move(ROOMS"tunnel1");
   tell_object(TP,"%^BOLD%^%^BLUE%^You realise the lair of a dragon is not a wise place to remain for long.  You "
"carefully make your way back into the tunnel before taking a rest.%^RESET%^");
   TP->force_me("quit");
}

void activate_loot() {
   int i, j;
   active = 1;
   set_long("%^BOLD%^%^BLACK%^A small side cavern%^RESET%^\n"
"%^BLUE%^This cavern is much smaller than the one you just stepped in from.  It seems to be naturally formed, with "
"%^ORANGE%^rug%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^ed%^BLUE%^ stone walls and a scattering of stalagmites around the "
"floor's edges.  The roof is visible only a short distance above, dotted with stalactites that cast long %^BOLD%^%^BLACK%^"
"sh%^RESET%^ad%^BOLD%^%^BLACK%^ows %^RESET%^%^BLUE%^against the stone.  All of these details are hardly noticed though, "
"for what the cavern holds within itself is quite %^BOLD%^%^CYAN%^breathtaking%^RESET%^%^BLUE%^ to behold.  The floor is "
"covered from one end to the other in %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^"
"and %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^, fine %^RESET%^a%^GREEN%^r%^RESET%^two%^ORANGE%^r"
"%^RESET%^k%^BLUE%^, %^GREEN%^cl%^CYAN%^ot%^GREEN%^hi%^BOLD%^n%^RESET%^%^GREEN%^g%^BLUE%^, %^WHITE%^ar%^ORANGE%^mo"
"%^RESET%^r %^BLUE%^and %^BOLD%^%^BLACK%^we%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^pons%^RESET%^%^BLUE%^, %^MAGENTA%^ar%^BOLD%^t"
"%^RESET%^%^MAGENTA%^if%^CYAN%^ac%^MAGENTA%^ts %^BLUE%^of all kinds and many other things besides; more treasure than you "
"could possibly imagine to be in one place at the same time.\n%^RESET%^");
   set_items(([
     ({"walls","cavern","floor","roof","stalagmites","stalactites"}):"%^BLUE%^This cavern is seemingly naturally-formed, "
"with %^ORANGE%^rough sto%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^e %^BLUE%^walls and stalagmites that dot the perimiter of "
"the area.  The roof is visible a short distance above your head, dotted with stalactites that cast long %^BOLD%^%^BLACK%^"
"sh%^RESET%^ad%^BOLD%^%^BLACK%^ows %^RESET%^%^BLUE%^against the stone.%^RESET%^",
     "treasure":"%^BLUE%^This cavern is filled from one end to the other, with more treasure than you've ever "
"seen in a single place at the same time.  A sea of %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^%^ORANGE%^n%^YELLOW%^s "
"%^RESET%^%^BLUE%^coats the floor, speckled with precious %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^.  "
"All across this bed of sparkling metal lie pieces of %^GREEN%^cl%^CYAN%^ot%^GREEN%^hi%^BOLD%^n%^RESET%^%^GREEN%^g%^BLUE%^"
", %^WHITE%^ar%^ORANGE%^mo%^RESET%^r %^BLUE%^and %^BOLD%^%^BLACK%^we%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^pons%^RESET%^"
"%^BLUE%^, and rare %^MAGENTA%^ar%^BOLD%^t%^RESET%^%^MAGENTA%^if%^CYAN%^ac%^MAGENTA%^ts %^BLUE%^of all kinds.  A low "
"%^GREEN%^hi%^WHITE%^s%^GREEN%^s %^RESET%^%^BLUE%^is audible from the pile, as you realise droplets of acid are eating "
"through it!  You should %^YELLOW%^take %^RESET%^%^BLUE%^what you can before they are all lost!%^RESET%^%^RESET%^",
     "coins":"%^BLUE%^The entire cavern's floor is scattered with countless %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^"
"%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^of all kinds. Some are known to you, while others must be from foreign lands, "
"since you've never seen their like before.  A low %^GREEN%^hi%^WHITE%^s%^GREEN%^s %^RESET%^%^BLUE%^is audible from the "
"pile, as you realise droplets of acid are eating through it!  You should %^YELLOW%^take %^RESET%^%^BLUE%^what you can "
"before they are all lost!%^RESET%^",
     ({"gems","jewels","gemstones","artwork","art"}):"%^BLUE%^Sparkling %^YELLOW%^ge%^WHITE%^m%^YELLOW%^st%^RED%^o"
"%^MAGENTA%^n%^YELLOW%^es %^RESET%^%^BLUE%^and exquisite %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^ lie "
"scattered alongside precious works of %^RESET%^a%^GREEN%^r%^ORANGE%^t%^BLUE%^, all strewn amongst the %^YELLOW%^c"
"%^WHITE%^o%^YELLOW%^i%^RESET%^%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^on the floor.  A low %^GREEN%^hi%^WHITE%^s%^GREEN%^"
"s %^RESET%^%^BLUE%^is audible, as you realise droplets of acid are eating through them!  You should %^YELLOW%^take "
"%^RESET%^%^BLUE%^what you can before they are all lost!%^RESET%^",
     "armor":"%^BLUE%^Pieces of %^RESET%^ar%^ORANGE%^mo%^RESET%^r %^BLUE%^in all kinds of metals and leathers lay strewn "
"across the pile of treasure, from the mottled outline of a suit of %^YELLOW%^leather%^RESET%^%^BLUE%^, to the stark "
"granite surface of a suit of %^YELLOW%^plate%^RESET%^%^BLUE%^.  A jagged %^YELLOW%^shield%^RESET%^%^BLUE%^ lies off to "
"the side, and a pair of %^YELLOW%^gauntlets %^RESET%^%^BLUE%^have tumbled to the ground.  A low %^GREEN%^hi%^WHITE%^s"
"%^GREEN%^s %^RESET%^%^BLUE%^is audible, as you realise droplets of acid are eating through them!  You should %^YELLOW%^"
"take %^RESET%^%^BLUE%^what you can before they are all lost!%^RESET%^%^RESET%^",
     "weapons":"%^BLUE%^Nearly every kind of %^BOLD%^%^BLACK%^we%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^pon %^RESET%^%^BLUE%^"
"imaginable can be spied somewhere amongst the treasure before you.  Atop the pile you can see a %^YELLOW%^dagger%^RESET%^"
"%^BLUE%^ of obsidian and a golden %^YELLOW%^sword%^RESET%^%^BLUE%^, along with a %^YELLOW%^lance %^RESET%^%^BLUE%^made "
"of white-oak.  Further back, a %^YELLOW%^longbow %^RESET%^%^BLUE%^of pale weirwood lies unheeded amongst the hoard.  A "
"low %^GREEN%^hi%^WHITE%^s%^GREEN%^s %^RESET%^%^BLUE%^is audible, as you realise droplets of acid are eating through them"
"!  You should %^YELLOW%^take %^RESET%^%^BLUE%^what you can before they are all lost!%^RESET%^%^RESET%^",
     ({"clothes","clothing"}):"%^BLUE%^Garments of all kinds in a %^MAGENTA%^m%^RED%^y%^ORANGE%^r%^YELLOW%^i%^BOLD%^"
"%^GREEN%^a%^BLUE%^d %^RESET%^%^BLUE%^of hues lay strewn across the treasure before you, some recognizeable and others "
"less so.  Near your feet lies a set of delicate, silver-framed %^YELLOW%^lenses%^RESET%^%^BLUE%^.  Further up the pile "
"you can spot a %^YELLOW%^ring %^RESET%^%^BLUE%^of adamantite, a steel %^YELLOW%^hoop%^RESET%^%^BLUE%^, a pair of platinum "
"%^YELLOW%^bracelets%^RESET%^%^BLUE%^, and some mottled %^YELLOW%^boots%^RESET%^%^BLUE%^.  A low %^GREEN%^hi%^WHITE%^s"
"%^GREEN%^s %^RESET%^%^BLUE%^is audible, as you realise droplets of acid are eating through them!  You should %^YELLOW%^take "
"%^RESET%^%^BLUE%^what you can before they are all lost!%^RESET%^%^RESET%^",
     "artifacts":"%^BLUE%^All kinds of precious %^MAGENTA%^ar%^BOLD%^t%^RESET%^%^MAGENTA%^if%^CYAN%^ac%^MAGENTA%^ts "
"%^BLUE%^can be spotted amidst the glittering pile of treasure.  Near the top you can see a jasper %^YELLOW%^amulet"
"%^RESET%^%^BLUE%^ resting alongside a golden %^YELLOW%^cuff%^RESET%^%^BLUE%^ and a delicate %^YELLOW%^lattice %^RESET%^"
"%^BLUE%^of crystals.  Nearby lies a %^YELLOW%^box%^RESET%^%^BLUE%^, slightly ajar to reveal the shimmering dust within.  "
"Further down, a silver %^YELLOW%^circlet %^RESET%^%^BLUE%^has snagged upon a crystalline %^YELLOW%^decanter%^RESET%^"
"%^BLUE%^, while a %^YELLOW%^prism %^RESET%^%^BLUE%^of banded onyx sits alone off to the side.  A low %^GREEN%^hi"
"%^WHITE%^s%^GREEN%^s %^RESET%^%^BLUE%^is audible, as you realise droplets of acid are eating through them!  You should "
"%^YELLOW%^take %^RESET%^%^BLUE%^what you can before they are all lost!%^RESET%^%^RESET%^",
   ]));
   clothes = 1;
   weapons = 1;
   armor = 1;
   trinkets = 1;
   coins = 1;
   gems = 1;
}

int take_fun(string str) {
   object spawning;
   int i, j;
   if(!str) {
     tell_object(TP,"What do you want to take?");
     return 0;
   }
   if(!active) {
     tell_object(TP,"There is nothing here worth taking.");
     return 1;
   }
   if(!trapped) {
     tell_object(TP,"Something has gone wrong and the dragon has not activated the loot properly - please mail Nienne.");
     return 1;
   }
   switch(str) {
     case "lenses": case "bracelets": case "boots": case "ring": case "hoop":
       if(!clothes) {
         tell_object(TP,"%^ORANGE%^That's not here to take!%^RESET%^");
         return 1;
       }
       if(clothes == 2) {
         tell_object(TP,"%^GREEN%^The remaining clothes are too damaged to retrieve!%^RESET%^");
         return 1;
       }
       if(str == "lenses") spawning = new(OBJ"lenses");
       if(str == "bracelets") spawning = new(OBJ"spellbracelets");
       if(str == "boots") spawning = new(OBJ"tpboots");
       if(str == "ring") spawning = new(OBJ"greaterrop");
       if(str == "hoop") spawning = new(OBJ"weaponring");
       spawning->move(TO);
       tell_object(TP,"%^ORANGE%^You carefully reach in and retrieve the "+str+", before the rest of the clothing items "
"are too damaged to save from the acid.%^RESET%^");
       tell_room(TO,"%^ORANGE%^"+TP->QCN+" carefully reaches in and retrieves the "+str+", before the rest of the "
"clothing items are too damaged to save from the acid.%^RESET%^",TP);
       clothes = 2;
       remove_item("clothes");
       remove_item("clothing");
       add_item("clothes","%^BLUE%^Garments of all kinds in a %^MAGENTA%^m%^RED%^y%^ORANGE%^r%^YELLOW%^i%^BOLD%^"
"%^GREEN%^a%^BLUE%^d %^RESET%^%^BLUE%^of hues lay strewn across the treasure before you, some recognizeable and others "
"less so.  All are horribly %^RED%^damaged%^BLUE%^, however, as they have been eaten away by acid.  You doubt they would "
"be of use to anyone.%^RESET%^%^RESET%^");
       add_item("clothing","%^BLUE%^Garments of all kinds in a %^MAGENTA%^m%^RED%^y%^ORANGE%^r%^YELLOW%^i%^BOLD%^"
"%^GREEN%^a%^BLUE%^d %^RESET%^%^BLUE%^of hues lay strewn across the treasure before you, some recognizeable and others "
"less so.  All are horribly %^RED%^damaged%^BLUE%^, however, as they have been eaten away by acid.  You doubt they would "
"be of use to anyone.%^RESET%^%^RESET%^");
       break;
     case "leather": case "plate": case "shield": case "gauntlets":
       if(!armor) {
         tell_object(TP,"%^ORANGE%^That's not here to take!%^RESET%^");
         return 1;
       }
       if(armor == 2) {
         tell_object(TP,"%^GREEN%^The remaining armor is too damaged to retrieve!%^RESET%^");
         return 1;
       }
       if(str == "leather") spawning = new(OBJ"shadowdancer");
       if(str == "plate") spawning = new(OBJ"stoneplate");
       if(str == "shield") spawning = new(OBJ"barrier");
       if(str == "gauntlets") spawning = new(OBJ"gauntlets");
       spawning->move(TO);
       tell_object(TP,"%^ORANGE%^You carefully reach in and retrieve the "+str+", before the rest of the armor items "
"are too damaged to save from the acid.%^RESET%^");
       tell_room(TO,"%^ORANGE%^"+TP->QCN+" carefully reaches in and retrieves the "+str+", before the rest of the "
"armor items are too damaged to save from the acid.%^RESET%^",TP);
       armor = 2;
       remove_item("armor");
       add_item("armor","%^BLUE%^Pieces of %^RESET%^ar%^ORANGE%^mo%^RESET%^r %^BLUE%^in all kinds of metals and leathers "
"lay strewn across the pile of treasure.  All are horribly %^RED%^damaged%^BLUE%^, however, as they have been eaten away "
"by acid.  You doubt they would be of use to anyone.%^RESET%^%^RESET%^");
       break;
     case "dagger": case "longbow": case "lance": case "sword":
       if(!weapons) {
         tell_object(TP,"%^ORANGE%^That's not here to take!%^RESET%^");
         return 1;
       }
       if(weapons == 2) {
         tell_object(TP,"%^GREEN%^The remaining weapons are too damaged to retrieve!%^RESET%^");
         return 1;
       }
       if(str == "dagger") spawning = new(OBJ"sheoldagger");
       if(str == "longbow") spawning = new(OBJ"flamebow");
       if(str == "lance") spawning = new(OBJ"lance");
       if(str == "sword") spawning = new(OBJ"gsunblade");
       spawning->move(TO);
       tell_object(TP,"%^ORANGE%^You carefully reach in and retrieve the "+str+", before the rest of the weapons "
"are too damaged to save from the acid.%^RESET%^");
       tell_room(TO,"%^ORANGE%^"+TP->QCN+" carefully reaches in and retrieves the "+str+", before the rest of the "
"weapons are too damaged to save from the acid.%^RESET%^",TP);
       weapons = 2;
       remove_item("weapons");
       add_item("weapons","%^BLUE%^Nearly every kind of %^BOLD%^%^BLACK%^we%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^pon %^RESET%^"
"%^BLUE%^imaginable can be spied somewhere amongst the treasure before you.  All are horribly %^RED%^damaged%^BLUE%^, "
"however, as they have been eaten away by acid.  You doubt they would be of use to anyone.%^RESET%^%^RESET%^");
       break;
     case "amulet": case "decanter": case "cuff": case "prism": case "circlet": case "lattice": case "box":
       if(!trinkets) {
         tell_object(TP,"%^ORANGE%^That's not here to take!%^RESET%^");
         return 1;
       }
       if(trinkets == 2) {
         tell_object(TP,"%^GREEN%^The remaining artifacts are too damaged to retrieve!%^RESET%^");
         return 1;
       }
       if(str == "amulet") spawning = new(OBJ"alignamulet");
       if(str == "decanter") spawning = new(OBJ"decanter");
       if(str == "cuff") spawning = new(OBJ"geniescuff");
       if(str == "prism") spawning = new(OBJ"mendingprism");
       if(str == "circlet") spawning = new(OBJ"telepathycirclet");
       if(str == "lattice") spawning = new(OBJ"shimmaryn");
       if(str == "box") spawning = new(OBJ"dustbox");
       spawning->move(TO);
       tell_object(TP,"%^ORANGE%^You carefully reach in and retrieve the "+str+", before the rest of the artifacts "
"are too damaged to save from the acid.%^RESET%^");
       tell_room(TO,"%^ORANGE%^"+TP->QCN+" carefully reaches in and retrieves the "+str+", before the rest of the "
"artifacts are too damaged to save from the acid.%^RESET%^",TP);
       trinkets = 2;
       remove_item("artifacts");
       add_item("artifacts","%^BLUE%^All kinds of precious %^MAGENTA%^ar%^BOLD%^t%^RESET%^%^MAGENTA%^if%^CYAN%^ac"
"%^MAGENTA%^ts %^BLUE%^can be spotted amidst the glittering pile of treasure.  All are horribly %^RED%^damaged%^BLUE%^, "
"however, as they have been eaten away by acid.  You doubt they would be of use to anyone.%^RESET%^%^RESET%^");
       break;
     case "coins":
       if(!coins) {
         tell_object(TP,"%^ORANGE%^There's no coins of value here to take!%^RESET%^");
         return 1;
       }
       if(coins == 2) {
         tell_object(TP,"%^GREEN%^The remaining coins are too damaged to retrieve!%^RESET%^");
         return 1;
       }
       spawning = new("/std/obj/coins");
       spawning->set_money("platinum", random(5000)+2500);
       spawning->set_money("gold", random(10000)+10000);
       spawning->move(TO);
       tell_object(TP,"%^ORANGE%^You carefully scoop up as many undamaged coins as you can!%^RESET%^");
       tell_room(TO,"%^ORANGE%^"+TP->QCN+" carefully scoops up as many undamaged coins as possible!%^RESET%^",TP);
       coins = 2;
       remove_item("coins");
       add_item("coins","%^BLUE%^The entire cavern's floor is scattered with countless %^YELLOW%^c%^WHITE%^o%^YELLOW%^i"
"%^RESET%^%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^of all kinds. Some are known to you, while others must be from foreign "
"lands, since you've never seen their like before.  All are horribly %^RED%^damaged%^BLUE%^, however, as they have been "
"eaten away by acid.  You doubt they would be of use to anyone.%^RESET%^");
       break;
     case "gems": case "jewels": case "art": case "artwork":
       if(!gems) {
         tell_object(TP,"%^ORANGE%^There's no gems here to take!%^RESET%^");
         return 1;
       }
       if(gems == 2) {
         tell_object(TP,"%^GREEN%^The remaining gems are too damaged to retrieve!%^RESET%^");
         return 1;
       }
       new(OBJ"chargegem")->move(TO);
       new(OBJ"statue")->move(TO);
       new(OBJ"painting")->move(TO);
       j = roll_dice(1,4);
       for(i=0;i<j;i++) new(OBJ"gemstone")->move(TO);
       tell_object(TP,"%^ORANGE%^You carefully scoop up as many undamaged gemstones and art items as you can!%^RESET%^");
       tell_room(TO,"%^ORANGE%^"+TP->QCN+" carefully scoops up as many undamaged gemstones and art items as "
"possible!%^RESET%^",TP);
       gems = 2;
       remove_item("gems");
       remove_item("jewels");
       remove_item("gemstones");
       remove_item("artwork");
       remove_item("art");
       add_item("gems","%^BLUE%^Sparkling %^YELLOW%^ge%^WHITE%^m%^YELLOW%^st%^RED%^o%^MAGENTA%^n%^YELLOW%^es %^RESET%^"
"%^BLUE%^and exquisite %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^ lie scattered alongside precious "
"works of %^RESET%^a%^GREEN%^r%^ORANGE%^t%^BLUE%^, all strewn amongst the %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^"
"%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^on the floor.  All are horribly %^RED%^damaged%^BLUE%^, however, as they have "
"been eaten away by acid.  You doubt they would be of use to anyone.%^RESET%^%^RESET%^");
       add_item("jewels","%^BLUE%^Sparkling %^YELLOW%^ge%^WHITE%^m%^YELLOW%^st%^RED%^o%^MAGENTA%^n%^YELLOW%^es %^RESET%^"
"%^BLUE%^and exquisite %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^ lie scattered alongside precious "
"works of %^RESET%^a%^GREEN%^r%^ORANGE%^t%^BLUE%^, all strewn amongst the %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^"
"%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^on the floor.  All are horribly %^RED%^damaged%^BLUE%^, however, as they have "
"been eaten away by acid.  You doubt they would be of use to anyone.%^RESET%^%^RESET%^");
       add_item("gemstones","%^BLUE%^Sparkling %^YELLOW%^ge%^WHITE%^m%^YELLOW%^st%^RED%^o%^MAGENTA%^n%^YELLOW%^es "
"%^RESET%^%^BLUE%^and exquisite %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^ lie scattered alongside "
"precious works of %^RESET%^a%^GREEN%^r%^ORANGE%^t%^BLUE%^, all strewn amongst the %^YELLOW%^c%^WHITE%^o%^YELLOW%^i"
"%^RESET%^%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^on the floor.  All are horribly %^RED%^damaged%^BLUE%^, however, as "
"they have been eaten away by acid.  You doubt they would be of use to anyone.%^RESET%^%^RESET%^");
       add_item("artwork","%^BLUE%^Sparkling %^YELLOW%^ge%^WHITE%^m%^YELLOW%^st%^RED%^o%^MAGENTA%^n%^YELLOW%^es %^RESET%^"
"%^BLUE%^and exquisite %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^ lie scattered alongside precious "
"works of %^RESET%^a%^GREEN%^r%^ORANGE%^t%^BLUE%^, all strewn amongst the %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^"
"%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^on the floor.  All are horribly %^RED%^damaged%^BLUE%^, however, as they have "
"been eaten away by acid.  You doubt they would be of use to anyone.%^RESET%^%^RESET%^");
       add_item("art","%^BLUE%^Sparkling %^YELLOW%^ge%^WHITE%^m%^YELLOW%^st%^RED%^o%^MAGENTA%^n%^YELLOW%^es %^RESET%^"
"%^BLUE%^and exquisite %^RED%^j%^MAGENTA%^e%^GREEN%^we%^CYAN%^l%^MAGENTA%^s%^BLUE%^ lie scattered alongside precious "
"works of %^RESET%^a%^GREEN%^r%^ORANGE%^t%^BLUE%^, all strewn amongst the %^YELLOW%^c%^WHITE%^o%^YELLOW%^i%^RESET%^"
"%^ORANGE%^n%^YELLOW%^s %^RESET%^%^BLUE%^on the floor.  All are horribly %^RED%^damaged%^BLUE%^, however, as they have "
"been eaten away by acid.  You doubt they would be of use to anyone.%^RESET%^%^RESET%^");
       break;
     default:
       tell_object(TP,"%^ORANGE%^There's no "+str+" here to take!%^RESET%^");
       break;
   }
   return 1;
}
