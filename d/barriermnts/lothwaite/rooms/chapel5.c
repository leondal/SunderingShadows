//chapel5.c - Chapel for Lothwaite.  Circe 9/27/04
//Added Sune and Shaundakul Cythera 8/05
//Replaced Loviatar with Anhur, Nienne 09/08.
#include <std.h>
#include "../lothwaite.h"

//inherit ROOM;
inherit "/std/church";

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("A Magnificent Wooden Chapel");
   set_short("%^RESET%^%^ORANGE%^A Magnificent Wooden Chapel%^RESET%^");
   set_long("%^ORANGE%^This awe-inspiring chapel is made of rich "+
      "wood polished to a %^RESET%^glossy shine%^ORANGE%^.  The "+
      "vaulted ceiling rises high overhead, coming to a graceful "+
      "point many feet over the tallest firbolg's head.  A single, central "+
      "aisle carpeted with a thick %^BOLD%^%^BLUE%^blue rug %^RESET%^%^ORANGE%^"+
      "edged in %^YELLOW%^gold %^RESET%^%^ORANGE%^runs from the "+
      "chapel door between two sections of %^YELLOW%^pews %^RESET%^"+
      "%^ORANGE%^polished to be a slightly lighter shade than the "+
      "walls.  The end of each pew is decorated with a hanging "+
      "%^WHITE%^willow basket%^ORANGE%^ filled with magnificent "+
      "%^MAGENTA%^w%^BOLD%^i%^RED%^l%^YELLOW%^d%^RED%^f%^MAGENTA%^l"+
      "%^RESET%^%^MAGENTA%^o%^BOLD%^w%^RED%^e%^YELLOW%^r%^RED%^s"+
      "%^RESET%^%^ORANGE%^.  The wooden pews are softened with "+
      "thin %^BOLD%^%^BLUE%^blue cushions %^RESET%^%^ORANGE%^matching the rug, "+
      "while a contrasting %^MAGENTA%^padded kneeler %^ORANGE%^"+
      "runs just in front of each pew.  All along the walls "+
      "are %^YELLOW%^recessed alcoves%^RESET%^%^ORANGE%^, "+
      "each of which seems to be dedicated to a different deity.  "+
      "Above each alcove is set a %^YELLOW%^s%^GREEN%^t%^CYAN%^a"+
      "%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
      "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
      "%^YELLOW%^s%^GREEN%^s %^RESET%^%^ORANGE%^window depicting "+
      "a scene of that particular deity's mythology.  The tall "+
      "chapel door to the east stands just under a massive "+
      "triangular %^YELLOW%^s%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
      "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
      "%^YELLOW%^s%^GREEN%^s %^RESET%^%^ORANGE%^panel, though it is "+
      "difficult to see more than colored light from the inside.  "+
      "The central aisle leads all the way from the doorway to a "+
      "large %^BOLD%^%^BLUE%^bl%^CYAN%^u%^BLUE%^e mar%^CYAN%^bl%^BLUE%^e "+
      "altar %^RESET%^%^ORANGE%^on a raised dais here at the "+
      "western end of the chapel.  The %^BOLD%^%^BLUE%^altar %^RESET%^"+
      "%^ORANGE%^supports various %^RESET%^offerings %^ORANGE%^"+
      "and tokens given to the Lady of the Winds, whose breath "+
      "is often felt here in the valley of Lothwaite.%^RESET%^\n");
   set_items(([
      ({"door","chapel door"}) : "The chapel door is far to the "+
         "east, at the end of the long aisle between the pews.",
      ({"wall","walls","ceiling"}) : "%^ORANGE%^The whole building seems to be "+
         "made of thick polished wood.  Decorative carving is made in "+
         "the most unlikely places - whole borders of carved vines "+
         "climb in small bands up the walls and seem to reach all the "+
         "way to the very point of the ceiling!  Clearly, the firbolg "+
         "passion for woodcarving spills over into their faith.",
      ({"rug","blue rug","runner","carpet"}) : "%^BOLD%^%^BLUE%^A blue rug "+
         "edged in %^YELLOW%^gold %^BLUE%^runs between the "+
         "two sections of pews, forming an aisle leading from the "+
         "chapel door to the altar.  The rug ends just at the edge "+
         "of the front row of pews, leaving a wide stone floor "+
         "before the raised dais.",
      ({"pew","pews","cushions"}) : "Each wooden pew is polished "+
         "to a high shine that is somewhat lighter than the walls.  "+
         "Blue cushions matching the rug line each pew, making them "+
         "slightly more comfortable during the long ceremonies held "+
         "here on feast days.",
      ({"kneeler","padded kneeler","kneelers","padded kneelers"}) : 
         "%^MAGENTA%^Running in front of each pew is a low padded "+
         "kneeler.  Smaller matching kneelers are placed within each "+
         "alcove as well, all of them allowing for the firbolg custom "+
         "of kneeling while in prayer.",
      ({"basket","willow basket","flowers","wildflowers"}) : "The end "+
         "of each pew is decorated with a simple willow basket filled "+
         "each day with %^MAGENTA%^w%^BOLD%^i%^RED%^l%^YELLOW%^d%^RED%^f%^MAGENTA%^l"+
         "%^RESET%^%^MAGENTA%^o%^BOLD%^w%^RED%^e%^YELLOW%^r%^RED%^s"+
         "%^RESET%^ picked by the firbolg children of "+
         "Lothwaite.",
      ({"panel","stained glass panel"}) : "You can see little detail "+
         "in the stained glass panel above the chapel door.  Clearly, "+
         "though, the panel must be breathtaking from outside.",
      ({"altar","marble altar","blue altar","offerings"}) : "%^BOLD%^%^BLUE%^"+
         "The blue marble altar is formed in what looks to be a "+
         "free-form oval shape, allowing for minor curves and dips "+
         "that add to its chaotic charm.  Atop the altar are various "+
         "tokens and offerings to Akadi, a goddess revered above all "+
         "others in Lothwaite.  %^CYAN%^Sticks of incense%^BLUE%^, "+
         "%^WHITE%^small feathers%^BLUE%^, "+
         "blue glass beads, and various other tokens have been left "+
         "here for the Lady of the Winds.  The altar itself stands "+
         "atop a raised stone dais.",
      ({"dais","stone dais","raised dais"}) : "The raised dais "+
         "is made of the same smooth stone as the rest of the "+
         "floor.  Three curving steps rise up to the base of the "+
         "altar.  Most firbolgs make their vows of marriage either "+
         "here or on the village green, and many festivals and prayers "+
         "are held here throughout the year.",
      ({"alcoves","alcove","window","windows","stained glass"}) : 
         "There are twenty two alcoves set within "+
         "the walls of this chapel.  Each has a beautiful arched "+
         "%^YELLOW%^s%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
         "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
         "%^YELLOW%^s%^GREEN%^s %^RESET%^window set above it and "+
         "features a finely carved %^ORANGE%^wooden shelf%^RESET%^ "+
         "that supports an %^BOLD%^icon %^RESET%^dedicated to a particular "+
         "deity.  A small %^MAGENTA%^padded kneeler %^RESET%^is at the "+
         "base of each alcove, and another %^ORANGE%^wooden shelf "+
         "%^RESET%^stands ready to collect offerings in each.  From "+
         "here, you can see alcoves dedicated to %^BOLD%^"+
         "%^BLUE%^Anhur%^RESET%^, %^YELLOW%^Lathander%^RESET%^, %^BOLD%^"+
         "%^RED%^Kossuth%^RESET%^, %^BOLD%^%^BLACK%^Kelemvor%^RESET%^, "+
         "%^CYAN%^Istishia%^RESET%^, %^BOLD%^Helm%^RESET%^, %^ORANGE%^"+
         "Grumbar%^RESET%^, %^BOLD%^%^BLACK%^Cyric%^RESET%^, "+
	   "%^BOLD%^%^MAGENTA%^Beshaba%^RESET%^, %^BOLD%^"+
         "%^GREEN%^Bane%^RESET%^, %^BOLD%^%^CYAN%^Auppenser%^RESET%^,"+
	   "and %^BOLD%^Auril%^RESET%^.  You "+
         "may look at the "+
         "individual alcoves by <look -deity- alcove>",
      ({"anhur","anhur alcove"}) : "%^YELLOW%^The alcove dedicated "+
         "to Anhur features a lining of %^BLUE%^vibrant cobalt silk"+
         "%^YELLOW%^.  Upon the shelf lies a %^RESET%^steel falchion "+
         "%^YELLOW%^of fine crafting, its thick blade polished to a "+
         "bright sheen.  The weapon's swept hilt and pommel are "+
         "engraved with the image of a %^RESET%^%^ORANGE%^fierce hawk "+
         "%^YELLOW%^in flight, its wings spread and its beak opened "+
         "in a scream.  The altar cloth upon the %^RESET%^%^ORANGE%^"+
         "shelf %^YELLOW%^bears an image of the holy symbol of Anhur "+
         "embroidered in golden thread - a %^RED%^hawk's head"+
         "%^YELLOW%^, much resembling that upon the falchion's "+
         "hilt.%^RESET%^",
/*      ({"loviatar","loviatar alcove"}) : "%^BOLD%^%^RED%^The alcove "+
         "dedicated to Loviatar features a deep red silk lining "+
         "studded with small pyramids of %^BLACK%^obsi%^WHITE%^d"+
         "%^BLACK%^ian%^RED%^.  Contrasting sharply with the "+
         "sinister background is the %^WHITE%^alabastar statue "+
         "%^RED%^prominently displayed upon the %^RESET%^%^ORANGE%^"+
         "shelf%^BOLD%^%^RED%^.  The %^WHITE%^statue %^RED%^is "+
         "of a striking woman with long %^WHITE%^platinum hair "+
         "%^RED%^dressed in a thin %^WHITE%^shift of white%^RED%^.  "+
         "Her eyes reveal a smoldering malicious intent, and her "+
         "lips are parted, slightly baring her %^WHITE%^teeth%^RED%^"+
         ".  The altar cloth upon the %^RESET%^%^ORANGE%^shelf "+
         "%^BOLD%^%^RED%^bears an embroidered image of the holy "+
         "symbol of Loviatar - a %^BLACK%^nine-stranded whip "+
         "%^RED%^ending in %^RESET%^%^RED%^bloody barbs%^BOLD%^.", */
      ({"lathander","lathander alcove"}) : "%^YELLOW%^The alcove "+
         "dedicated to Lathander is decorated in all the hues of "+
         "a beautiful %^RESET%^%^MAGENTA%^s%^RED%^u%^BOLD%^"+
         "n%^MAGENTA%^r%^RESET%^%^ORANGE%^i%^YELLOW%^s%^WHITE%^e"+
         "%^YELLOW%^.  Thin, wispy fabrics "+
         "dyed in bleeding bands of color hang in the background, "+
         "while a flawless %^MAGENTA%^rose quartz crystal %^YELLOW%^"+
         "stands on display.  Inside the %^MAGENTA%^crystal%^YELLOW%^, "+
         "you can see the carved image of a well-toned athlete "+
         "in mid-race before the gates of a towering %^WHITE%^city"+
         "%^YELLOW%^.  The altar cloth upon the %^RESET%^%^ORANGE%^"+
         "shelf %^YELLOW%^carries a depiction of Lathander's holy "+
         "symbol - a %^MAGENTA%^quartz disk of rosey pink hue "+
         "%^YELLOW%^dangling from a ribbon dyed the shades of "+
         "the %^RESET%^%^MAGENTA%^s%^RED%^u%^BOLD%^"+
         "n%^MAGENTA%^r%^RESET%^%^ORANGE%^i%^YELLOW%^s%^WHITE%^e"+
         "%^YELLOW%^.",
      ({"kossuth","kossuth alcove"}) : "%^BOLD%^%^RED%^The alcove "+
         "given to the glory of the Fl%^YELLOW%^a%^RED%^me Lord "+
         "is adorned in bold, fi%^RESET%^%^ORANGE%^e%^YELLOW%^r"+
         "%^RED%^y silks.  Centered upon the %^RESET%^%^ORANGE%^"+
         "shelf %^BOLD%^%^RED%^is a %^YELLOW%^brass brazier %^RED%^"+
         "in which an %^YELLOW%^etern%^RED%^a%^YELLOW%^l %^RED%^"+
         "fl%^YELLOW%^a%^RED%^me burns.  The legs of the brazier "+
         "hold it carefully above the embroidered altar cloth, "+
         "which bears a stylized version of Kossuth's holy "+
         "symbol - a springing f%^RESET%^%^ORANGE%^l%^YELLOW%^"+
         "a%^RESET%^%^ORANGE%^m%^BOLD%^%^RED%^e.",
      ({"kelemvor","kelemvor alcove"}) : "%^BOLD%^%^BLACK%^The "+
         "alcove dedicated to the Lord of the Dead is understandably "+
         "somber and austere.  Thin layers of %^RESET%^gray muslin "+
         "%^BOLD%^%^BLACK%^waft softly on the breeze blowing "+
         "through the chapel, providing a backdrop for the holy "+
         "relics gracing the alcove.  A battered %^RESET%^gray "+
         "leather prayer book %^BOLD%^%^BLACK%^stands beside "+
         "a beautiful %^RESET%^aspergillum%^BOLD%^%^BLACK%^, "+
         "both used by priests as they guide people into the "+
         "afterlife.  The altar cloth beneath them bears the "+
         "holy symbol of Kelemvor - an upright %^WHITE%^skeletal "+
         "arm %^BLACK%^holding the balanced %^YELLOW%^scales "+
         "of justice%^BLACK%^.",
      ({"istishia","istishia alcove"}) : "%^CYAN%^The alcove "+
         "dedicated to Istishia is dominated by a beautiful "+
         "%^RESET%^gray stone fountain%^CYAN%^.  A stream of "+
         "lightly %^CYAN%^babbling water %^RESET%^%^CYAN%^"+
         "flows over the rocks, smoothing them eternally and "+
         "expressing the might of the Water Lord over all "+
         "other elements.  The altar cloth at the base of the "+
         "fountain features a simple version of Istishia's "+
         "holy symbol - a single %^BOLD%^cresting wave%^RESET%^"+
         "%^CYAN%^.",
      ({"helm","helm alcove"}) : "%^BOLD%^The alcove reserved "+
         "for the watchful deity Helm is rather stark in "+
         "appearance, leaving all avenues of sight open.  In "+
         "the center of the alcove is a standing %^RESET%^"+
         "mithril gauntlet%^BOLD%^, emblazoned on the back "+
         "with an open %^BLUE%^eye %^WHITE%^crafted of beautiful "+
         "%^BLUE%^sapphires%^WHITE%^.  The altar cloth upon "+
         "the %^RESET%^%^ORANGE%^wooden shelf %^BOLD%^%^WHITE%^"+
         "bears an embroidered version of Helm's holy symbol - "+
         "a %^RESET%^gauntlet %^BOLD%^closely matching the "+
         "one upon the %^RESET%^%^ORANGE%^shelf%^BOLD%^%^WHITE%^.",
      ({"grumbar","grumbar alcove"}) : "%^ORANGE%^Devoid of "+
         "any fabric, the alcove dedicated to Grumbar is "+
         "instead decorated solely with a replica of a mountain "+
         "made of pure materials from the earth.  The "+
         "mountain seems almost to be a true version rather than "+
         "a replica - ancient seeming %^GREEN%^trees %^ORANGE%^"+
         "dot its top beneath a dusting of what seems to be "+
         "%^BOLD%^%^WHITE%^snow%^RESET%^%^ORANGE%^!  The "+
         "mountain rests upon the altar cloth, which bears "+
         "an embroidered image of Grumbar's holy symbol - a "+
         "series of three mountains upon a field of %^MAGENTA%^"+
         "purple%^ORANGE%^.",
      ({"cyric","cyric alcove"}) : "%^BOLD%^%^BLACK%^The alcove "+
         "dedicated to the Prince of Lies has been lined with "+
         "%^RESET%^dark-v%^BOLD%^%^BLACK%^ei%^RESET%^ned slabs of "+
         "%^BOLD%^%^BLACK%^mi%^RESET%^c%^BOLD%^%^BLACK%^a, "+
         "creating a glittering backdrop that continually shifts.  "+
         "Suspended in mid-air within the alcove are a pair of "+
         "%^RESET%^silver bracelets %^BOLD%^%^BLACK%^that turn "+
         "slowly and seem to occasionally morph into different "+
         "images and shapes.  Beneath the bracelets upon the "+
         "%^RESET%^%^ORANGE%^shelf %^BOLD%^%^BLACK%^is an altar "+
         "cloth bearing the holy symbol of Cyric - a %^WHITE%^"+
         "white skull %^BLACK%^without a jawbone upon a black "+
         "sunburst.",
      ({"bane","bane alcove"}) : "%^BOLD%^%^GREEN%^The orderly "+
         "alcove dedicated to Bane is lined with plates of%^BLACK%^ "+
         "black iron%^GREEN%^.  Sitting upon the %^RESET%^"+
         "%^ORANGE%^shelf %^BOLD%^%^GREEN%^is an eerie %^BLACK%^"+
         "horned helm %^GREEN%^with the visor down, creating the "+
         "unnerving feeling of unseen eyes bearing down upon "+
         "anyone who gazes upon it.  The altar cloth upon the "+
         "%^RESET%^%^ORANGE%^shelf %^BOLD%^%^GREEN%^bears the "+
         "embroidered image of the holy symbol of Bane - an "+
         "upright %^BLACK%^black hand %^GREEN%^tinged with "+
         "%^RESET%^%^RED%^red %^BOLD%^%^GREEN%^upon a field of "+
         "%^RESET%^%^GREEN%^green%^BOLD%^.",
	({"beshaba","beshaba alcove"}) : "%^BOLD%^%^MAGENTA%^The alcove "+
         "dedicated to Beshaba is covered with %^BOLD%^%^RED%^red%^MAGENTA%^"+
	   " linen with crackling lines of %^BOLD%^%^BLACK%^black%^MAGENTA%^."+
	   "  The chaotic and wild apperance of the alcove often leaves one "+
	   "feeling ill at ease.  A laqured shelf supports a pair of "+
	   "%^BOLD%^%^BLACK%^black antlers%^MAGENTA%^ against the %^RED%^red"+
	   "%^MAGENTA%^ field of the alcove. A shattered and broken ornate "+
	   "%^BOLD%^%^WHITE%^mirror%^MAGENTA%^ rests behind the antlers, "+
	   "reflecting the distorted images back.  The mirror is placed "+
	   "within the alcove to remind all that the misfortunes of Beshaba "+
	   "can happen to anyone.  Lining the shelf is an altar cloth that "+
	   "features a %^RED%^red%^MAGENTA%^ triangle with a rack of %^BOLD%^"+
	   "%^BLACK%^black antlers%^MAGENTA%^ sewn into the silk.",
	({"auppenser","auppenser alcove"}) : "%^CYAN%^Lined with shades of "+
	  "%^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^l%^BOLD%^%^BLUE%^u%^RESET%^%^BLUE%^e"+
	  "%^CYAN%^ and %^BOLD%^c%^RESET%^%^CYAN%^y%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^"+
	  "n cotton, this alcove dedicated to Auppenser radiates a feeling of "+
	  "serenity. A variety of %^BOLD%^%^WHITE%^c%^RED%^r%^RESET%^%^ORANGE%^"+
	  "y%^YELLOW%^s%^GREEN%^t%^CYAN%^a%^BLUE%^l%^MAGENTA%^s%^RESET%^%^CYAN%^"+
	  " have been fused together to create the large shelf that rests on the"+
	  " wall.  On the shelf a %^BOLD%^%^WHITE%^crystal%^RESET%^%^CYAN%^ statue"+
	  " of a couatl rests.  The %^RESET%^%^RED%^p%^BOLD%^r%^RESET%^%^ORANGE%^i"+
	  "%^YELLOW%^s%^GREEN%^m%^RESET%^%^CYAN%^a%^BLUE%^t%^BOLD%^%^MAGENTA%^i"+
	  "%^RESET%^%^MAGENTA%^c%^CYAN%^ scales of the coutal shines in the light"+
	  " as its feathered wings are outstretched.  The body of the couatl wraps"+
	  " protectively around a plate of %^ORANGE%^bronze %^CYAN%^that features a"+
	  " stylized %^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^ eye on it. ",
      ({"auril","auril alcove"}) : "%^BOLD%^The alcove dedicated "+
         "to Auril is draped in delicate lace made with a %^CYAN%^"+
         "snowflake %^WHITE%^pattern.  The lace is layered and "+
         "actually falls in front of the statue %^BOLD%^%^WHITE%^"+
         "of a %^RESET%^winter wolf%^BOLD%^ upon the %^RESET%^"+
         "%^ORANGE%^shelf%^BOLD%^%^WHITE%^, creating the illusion "+
         "of a snowstorm "+
         "upon a mountainside.  The altar cloth bears the image "+
         "of Auril's holy symbol - an intricate %^CYAN%^snowflake "+
         "%^WHITE%^on a %^RESET%^gray diamond %^BOLD%^with a "+
         "white border."
   ]));
   set_smell("default","A light, spicy fragrance of incense is in the air.");
   set_listen("default","Quiet prayers are whispered from the alcoves.");
   set_exits(([
      "east" : PATHEXIT"chapel4"
   ]));
}

void reset(){
   ::reset();
   if(!query_night()){
      if(!present("murchadh")){
         new(MON"shaman")->move(TO);
      }
   }
}
