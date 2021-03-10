//chapel4.c - Chapel for Lothwaite.  Circe 9/19/04
#include <std.h>
#include "../lothwaite.h"

inherit VAULT;

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
      "altar %^RESET%^%^ORANGE%^further to the west.%^RESET%^\n");
   set_items(([
      ({"wall","walls","ceiling"}) : "%^ORANGE%^The whole building seems to be "+
         "made of thick polished wood.  Decorative carving is made in "+
         "the most unlikely places - whole borders of carved vines "+
         "climb in small bands up the walls and seem to reach all the "+
         "way to the very point of the ceiling!  Clearly, the firbolg "+
         "passion for woodcarving spills over into their faith.",
      ({"rug","blue rug","runner","carpet"}) : "%^BOLD%^%^BLUE%^A blue rug "+
         "edged in %^YELLOW%^gold %^BLUE%^runs between the "+
         "two sections of pews, forming an aisle leading from the "+
         "chapel door to the altar to the west.",
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
      ({"altar","marble altar","blue altar"}) : "The blue marble "+
         "altar is in the western part of the chapel, at the end "+
         "of the aisle.  You can see little detail from here, but you "+
         "can tell it is on a raised dais there.",
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
         "here, you can see alcoves dedicated to %^BOLD%^Tyr%^RESET%^, "+
         "%^BOLD%^%^MAGENTA%^Tymora%^RESET%^, %^YELLOW%^Torm%^RESET%^, "+
         "%^BOLD%^%^RED%^Tempus%^RESET%^, %^BOLD%^%^BLUE%^Talos%^RESET%^, "+
	   "%^RED%^Sune%^RESET%^, %^CYAN%^Shaundakul%^RESET%^, "+
         "%^BOLD%^%^BLACK%^Shar%^RESET%^, %^BOLD%^Selune%^RESET%^, "+
         "%^MAGENTA%^Oghma%^RESET%^, %^BOLD%^%^CYAN%^Mystra%^RESET%^, "+
         "%^GREEN%^Mielikki%^RESET%^, %^BOLD%^%^BLACK%^Mask%^RESET%^, "+
         "and %^BOLD%^%^RED%^Malar%^RESET%^.  You may look at the "+
         "individual alcoves by <look -deity- alcove>",
      ({"tyr","tyr alcove"}) : "%^BOLD%^The alcove dedicated to Tyr "+
         "is austere and sparsely decorated.  The top %^RESET%^"+
         "%^ORANGE%^shelf %^BOLD%^%^WHITE%^supports a beautiful "+
         "%^YELLOW%^golden scale %^WHITE%^atop a small altar cloth.  "+
         "The altar cloth has been positioned to hang off the shelf, "+
         "and it curves to a point.  The cloth has been embroidered "+
         "with a %^BLUE%^blue shield %^WHITE%^emblazoned with the "+
         "symbol of Tyr - balanced %^YELLOW%^scales %^WHITE%^resting "+
         "atop an aged %^RESET%^%^RED%^warhammer%^BOLD%^%^WHITE%^.",
      ({"tymora","tymora alcove"}) : "%^BOLD%^%^MAGENTA%^The alcove "+
         "dedicated to Tymora is cheerful and fitting for Lady Luck.  "+
         "The %^RESET%^%^ORANGE%^shelf %^BOLD%^%^MAGENTA%^is a jumble "+
         "of tokens of luck - %^WHITE%^fluffy rabbits' feet%^MAGENTA%^, "+
         "%^CYAN%^pairs of dice%^MAGENTA%^, and %^RESET%^silver coins%^BOLD%^"+
         "%^MAGENTA%^, all of which are scattered atop an altar cloth "+
         "that has been left to hang over the edge of the %^RESET%^"+
         "%^ORANGE%^shelf%^BOLD%^%^MAGENTA%^.  The cloth has a scalloped "+
         "border that resembles a shamrock, and it has been lovingly "+
         "embroidered with the symbol of Tymora - a %^WHITE%^silver "+
         "coin %^MAGENTA%^decorated with Tymora's smiling face.",
      ({"torm","torm alcove"}) : "%^YELLOW%^The alcove dedicated to "+
         "Torm reflects the god's dedication to duty and loyalty "+
         "above all else.  Foregoing the embellishments of other "+
         "alcoves, this one has been set with a simple %^RESET%^"+
         "steel gauntlet %^YELLOW%^held upright with the palm "+
         "forward.  The altar cloth which hangs off the %^RESET%^"+
         "%^ORANGE%^wooden shelf %^YELLOW%^has been embroidered "+
         "with a simple version of Torm's symbol - the selfsame "+
         "gauntlet which graces the %^RESET%^%^ORANGE%^shelf%^YELLOW%^.",
      ({"tempus","tempus alcove"}) : "%^RED%^The alcove dedicated to "+
         "Tempus has been decorated with a life-like %^RESET%^"+
         "statue %^RED%^of the %^BOLD%^Lord of Battles%^RESET%^%^RED%^.  "+
         "The statue shows %^BOLD%^Tempus %^RESET%^%^RED%^wearing "+
         "beaten and bloody platemail with a massive war helm and standing "+
         "atop %^BOLD%^%^BLACK%^Deiros, a black stallion, %^RESET%^"+
         "%^RED%^and %^BOLD%^%^WHITE%^Veiros, a white mare%^RESET%^"+
         "%^RED%^.  An altar cloth spread below the statue hangs "+
         "over the edge of the %^ORANGE%^shelf %^RED%^and bears "+
         "an embroidered image of Tempus' holy symbol - a %^YELLOW%^"+
         "bl%^RED%^a%^YELLOW%^zing %^WHITE%^silver sword %^RESET%^"+
         "%^RED%^on a %^BOLD%^blood red shield%^RESET%^%^RED%^.",
      ({"talos","talos alcove"}) : "%^BOLD%^%^BLUE%^The alcove "+
         "dedicated to Talos features remnants of %^BLACK%^storms "+
         "%^BLUE%^from all over the realms.  A twisted %^CYAN%^"+
         "spiral of glass %^BLUE%^formed from %^YELLOW%^lightning "+
         "%^BLUE%^striking sand draws the eye, but it is surrounded "+
         "by all manner of objects, including a piece of a %^RESET%^%^ORANGE%^"+
         "ship's mast %^BOLD%^%^BLUE%^broken by a storm at sea and "+
         "a single %^RESET%^tile %^BOLD%^%^BLUE%^from the roof "+
         "of a destroyed inn.  The altar cloth has a jagged, chaotic "+
         "border, and it bears an embroidered image of Talos' "+
         "holy symbol - three %^YELLOW%^jagged lightning bolts "+
         "%^BLUE%^striking together.",
      ({"shar","shar alcove"}) : "%^BOLD%^%^BLACK%^The alcove "+
         "reserved for Shar is shrouded in thick black velvet.  "+
         "The shelf is ominously devoid of anything at all, letting "+
         "the inky darkness of the fabric make a statement all its "+
         "own.  The altar cloth hanging over the edge of the shelf "+
         "bears a stylized version of Shar's holy symbol - an "+
         "obsidian disk with a deep %^RESET%^%^MAGENTA%^purple "+
         "border%^BOLD%^%^BLACK%^.",
      ({"selune","selune alcove"}) : "%^BOLD%^The alcove dedicated "+
         "to the Goddess of the Moon is decorated with %^RESET%^"+
         "silver silks %^BOLD%^draped around the edges.  The "+
         "%^RESET%^%^ORANGE%^wooden shelf %^BOLD%^%^WHITE%^supports "+
         "a beautiful tri-faced statue carved of pure %^RESET%^"+
         "moonstone%^BOLD%^.  Each side of the statue represents a "+
         "version of Selune as she has been known to appear - from "+
         "the matronly, aging woman all the way to a young girl with "+
         "a lithe build.  An altar cloth with a scalloped border "+
         "depicting phases of the moon also reveals the holy symbol "+
         "of Selune - a pair of %^BLACK%^dark, feminine eyes "+
         "%^WHITE%^peering out through a circle of %^CYAN%^seven "+
         "stars%^WHITE%^.",
      ({"oghma","oghma alcove"}) : "%^MAGENTA%^Decorated in "+
         "relics connected with his brief "+
         "history in the northern regions of the Realms, the alcove "+
         "dedicated to Oghma reveals his devotion to both music "+
         "and knowledge.  As patron of the bards, his %^ORANGE%^"+
         "shelf %^MAGENTA%^supports an %^ORANGE%^ancient wooden "+
         "lute %^MAGENTA%^said to have been played by the first "+
         "bard to visit Lothwaite centuries ago.  Beside the "+
         "%^ORANGE%^lute %^MAGENTA%^is a coiled, aged %^RESET%^"+
         "scroll%^MAGENTA%^.  The altar cloth has been embroidered "+
         "with the simple symbol of the Binder - a single %^RESET%^"+
         "blank scroll%^MAGENTA%^.",
      ({"mystra","mystra alcove"}) : "%^BLUE%^The alcove "+
         "given to the Mother of All Magic features a mystical "+
         "creation all its own.  A large %^BOLD%^%^WHITE%^crystal "+
         "%^RESET%^%^BLUE%^"+
         "hangs suspended in mid-air in the center of the alcove.  "+
         "Inside it, one can view constantly shifting images of "+
         "%^BOLD%^magi %^RESET%^%^BLUE%^through the ages casting various "+
         "spells and researching incantations.  Even those who "+
         "have watched as long as their eyes could bear swear they "+
         "have never seen the same image twice.  The altar cloth "+
         "upon the %^RESET%^%^ORANGE%^shelf %^BLUE%^bears "+
         "an exquisite representation of Mystra's holy symbol - a "+
         "circle of seven %^BOLD%^blue%^CYAN%^-%^WHITE%^"+
         "white %^CYAN%^stars %^RESET%^%^BLUE%^with %^BOLD%^%^RED%^"+
         "red mist %^RESET%^%^BLUE%^flowing "+
         "from the center.",
      ({"mielikki","mielikki alcove"}) : "%^GREEN%^The alcove "+
         "dedicated to Mielikki brings a touch of the outdoors "+
         "inside.  A small potted %^BOLD%^tree %^RESET%^%^GREEN%^"+
         "flourishes upon the %^ORANGE%^shelf%^GREEN%^, and %^WHITE%^"+
         "tokens%^GREEN%^ of faith have been left all around its "+
         "%^ORANGE%^trunk%^GREEN%^.  The firbolg affinity for "+
         "%^ORANGE%^wood-carving %^GREEN%^is evident, as many "+
         "of the %^WHITE%^tokens %^GREEN%^are wooden representations "+
         "of %^BOLD%^%^WHITE%^unicorns%^RESET%^%^GREEN%^, "+
         "%^ORANGE%^deer%^GREEN%^, and various other woodland "+
         "creatures.  The altar cloth gracing the %^ORANGE%^"+
         "shelf%^GREEN%^ is rather rough and rustic, bearing "+
         "the image of Mielikki's holy symbol - a %^BOLD%^"+
         "%^WHITE%^white unicorn's head %^RESET%^%^GREEN%^upon a "+
         "%^BOLD%^field of green%^RESET%^%^GREEN%^.",
      ({"mask","mask alcove"}) : "%^BOLD%^%^BLACK%^The alcove "+
         "dedicated to Mask is shrouded in shadow created by "+
         "the layers of silk ranging in color from %^RESET%^"+
         "deep gray %^BOLD%^%^BLACK%^to inky black that "+
         "hang within the recess.  An aged black leather "+
         "coin purse with drawstrings rests upon the %^RESET%^"+
         "%^ORANGE%^shelf%^BOLD%^%^BLACK%^, and it is said "+
         "that this purse once belonged to a legendary thief "+
         "whose name is never said aloud but rather whispered "+
         "into the shadows.  The altar cloth upon the %^RESET%^"+
         "%^ORANGE%^shelf %^BOLD%^%^BLACK%^bears the image of "+
         "a flowing black mask edged in %^RESET%^%^RED%^red"+
         "%^BOLD%^%^BLACK%^.",
	({"shaundakul","shaundakul alcove"}) : "This simple alcove "+
	  "dedicated to %^CYAN%^Shaundakul%^RESET%^, has lined with"+
	  " birch planks.  A miniature weathered %^BOLD%^%^BLACK%^s"+
	  "%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^e"+
	  "%^RESET%^ throne dominates the space of the alcove, serving"+
	  " as the symbolic %^MAGENTA%^Seat of Shaundakul%^RESET%^.  "+
	  "Painted onto the throne is an image of a %^BOLD%^%^WHITE%^"+
	  "silver%^RESET%^ left hand held upright with %^CYAN%^ripples"+
	  "%^RESET%^ of wind surrounding it.  Carvings of %^BOLD%^rabbits"+
	  "%^RESET%^, %^ORANGE%^squirrels%^RESET%^, %^BOLD%^%^BLACK%^wolves"+
	  "%^RESET%^, and %^MAGENTA%^hawks%^RESET%^ have been left at the "+
	  "foot of the throne before travellers begin a new journey.",
	({"sune","sune alcove"}) : "%^BOLD%^%^WHITE%^The alcove dedicated to Sune"+
	  " is draped with thick plush %^RESET%^%^RED%^deep crimson%^BOLD%^"+
	  "%^WHITE%^ velvet.  Resting in the middle of the pools of velvet"+
	  " is an ivory statue.  The stark white of the statue stands out"+
	  " like a beacon against the %^RESET%^%^RED%^crimson%^BOLD%^%^WHITE%^"+
	  " velvet.  Carved to in likeness of an indescribably beautiful woman"+
	  " with long flowing %^RESET%^%^RED%^tresses%^BOLD%^%^WHITE%^, the "+
	  "statue's %^BOLD%^%^GREEN%^emerald%^BOLD%^%^WHITE%^ eyes "+
	  "sparkle in the light of the church.  At the feet of the statue "+
	  "fresh %^BOLD%^%^RED%^r%^WHITE%^o%^YELLOW%^s%^MAGENTA%^e%^RESET%^"+
	  "%^RED%^s%^BOLD%^%^WHITE%^ have been laid.",
      ({"malar","malar alcove"}) : "%^BOLD%^%^RED%^Roughly "+
         "fashioned %^RESET%^%^RED%^skins %^BOLD%^decorate "+
         "the alcove dedicated to Malar.  A %^RESET%^%^ORANGE%^"+
         "wooden claw %^BOLD%^%^RED%^supports an %^WHITE%^"+
         "ivory horn%^RED%^, the base of which is still tinged "+
         "in %^RESET%^%^RED%^dried blood%^BOLD%^.  Beneath it, "+
         "the altar cloth bears the image of the holy symbol "+
         "of Malar, a %^RESET%^%^ORANGE%^furred, beastial claw "+
         "%^BOLD%^%^RED%^with long, curving %^WHITE%^talons "+
         "%^RED%^dripping with %^RESET%^%^RED%^blood%^BOLD%^."
   ]));
   set_smell("default","A light, spicy fragrance of incense is in the air.");
   set_listen("default","Quiet prayers are whispered from the alcoves.");
   set_exits(([
      "east" : PATHEXIT"chapel3",
      "west" : PATHEXIT"chapel5"
   ]));
   set_door("chapel door",PATHEXIT"chapel3","east",0);
   set_door_description("chapel door","The ornate chapel door has been "+
      "carved from imported oak wood that bears intricate scrollwork "+
      "along the edges.  The door rises to a point that seems to emphasize "+
      "the %^YELLOW%^s%^GREEN%^t%^CYAN%^a%^BLUE%^i%^RESET%^%^MAGENTA%^n"+
      "%^YELLOW%^e%^GREEN%^d %^CYAN%^g%^BLUE%^l%^RESET%^%^MAGENTA%^a"+
      "%^YELLOW%^s%^GREEN%^s %^RESET%^panel just above it.");
}