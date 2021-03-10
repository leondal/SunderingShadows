//mage_shrine.c - shrine to Mystra for new Seneca
//~Circe~ 1/4/08
//Updated by ~Circe~ to be a shrine to Kismet after the god changes

#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_indoors(1);
   set_name("Shrine of Mysteries, Esoteric Haven, Seneca");
   set_short("%^BOLD%^Shrine of %^CYAN%^M%^RESET%^%^CYAN%^y%^BOLD%^"+
      "s%^RESET%^%^CYAN%^t%^BOLD%^e%^RESET%^%^CYAN%^r%^BOLD%^i"+
      "%^RESET%^%^CYAN%^e%^BOLD%^s%^WHITE%^, %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^");
   set_long("%^BOLD%^Shrine of %^CYAN%^M%^RESET%^%^CYAN%^y%^BOLD%^"+
      "s%^RESET%^%^CYAN%^t%^BOLD%^e%^RESET%^%^CYAN%^r%^BOLD%^i"+
      "%^RESET%^%^CYAN%^e%^BOLD%^s%^WHITE%^, %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^\n"+
      "%^CYAN%^Nestled protectively at the apex of the tower, this "+
      "%^BOLD%^shrine%^RESET%^%^CYAN%^ praises the %^BOLD%^Mother of "+
      "Knowledge%^RESET%^%^CYAN%^ with a gorgeous %^BOLD%^statue "+
      "%^RESET%^%^CYAN%^in her honor.  The statue has been carved from "+
      "%^BOLD%^%^WHITE%^white marble%^RESET%^%^CYAN%^ that lends itself to the "+
      "coruscating colors of the %^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^a%^BOLD%^i"+
      "%^GREEN%^n%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w %^BOLD%^f"+
      "%^RED%^a%^YELLOW%^l%^GREEN%^l%^CYAN%^s %^RESET%^%^CYAN%^that "+
      "%^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r "+
      "%^CYAN%^above and behind the icon.  The Lady kneels atop a "+
      "raised %^BOLD%^%^BLACK%^stone dais%^RESET%^%^CYAN%^ carved with "+
      "seven %^BOLD%^mystical runes %^RESET%^%^CYAN%^encircling "+
      "it, each rune filled with %^BOLD%^%^WHITE%^molten mithril%^RESET%^%^CYAN%^.  "+
      "Her hair flows in waves down to her narrow waist, "+
      "which is belted with intricate %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v"+
      "%^RESET%^e%^BOLD%^r %^RESET%^b%^BOLD%^r%^RESET%^a%^BOLD%^i"+
      "%^RESET%^d%^CYAN%^, and her expression radiates wisdom with a hint "+
      "of all the knowledge she possesses.  An open book rests "+
      "in her left hand while her right is held loosely upright, "+
      "and the %^BOLD%^%^RED%^m%^YELLOW%^i%^GREEN%^s%^BLUE%^t"+
      "%^RESET%^%^MAGENTA%^s %^RESET%^%^CYAN%^seem to gather in her "+
      "open palm as if in response to her spell.  Crowding the "+
      "small space are bountiful %^BOLD%^%^BLUE%^v%^CYAN%^a%^RESET%^%^CYAN%^r"
      "%^ORANGE%^i%^YELLOW%^e%^RED%^g%^MAGENTA%^a%^RESET%^%^MAGENTA%^t%^GREEN%^e"
      "%^BOLD%^d %^RESET%^%^CYAN%^i%^BOLD%^r%^BLUE%^i%^RESET%^%^ORANGE%^s%^YELLOW%^e%^RED%^s "+
      "%^RESET%^%^CYAN%^with brilliant %^BOLD%^%^RED%^crimson "+
      "centers%^RESET%^%^CYAN%^ that rise on spiraling stands and "+
      "reach their crest just beneath the Lady's chin.  Placed "+
      "against the northern wall is a small %^BOLD%^%^BLUE%^"+
      "a%^CYAN%^l%^BLUE%^tar %^RESET%^%^CYAN%^fashioned from %^BOLD%^"+
      "%^BLUE%^bl%^CYAN%^u%^BLUE%^e m%^RESET%^%^BLUE%^a%^BOLD%^"+
      "rb%^CYAN%^l%^BLUE%^e %^RESET%^%^CYAN%^where Keepers of the Art "+
      "have piled their offerings of %^BOLD%^%^BLUE%^blue "+
      "%^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^white %^BLUE%^g%^WHITE%^e%^BLUE%^m"+
      "%^WHITE%^s %^RESET%^%^CYAN%^mixed with minor %^BOLD%^magical "+
      "trinkets%^RESET%^%^CYAN%^.  %^BOLD%^%^WHITE%^Globes %^RESET%^%^CYAN%^"+
      "fashioned from %^BOLD%^glassteel %^RESET%^%^CYAN%^and enchanted "+
      "to provide a faint %^BOLD%^%^WHITE%^white light %^RESET%^%^CYAN%^hover "+
      "within the area.%^RESET%^\n");
   set_smell("default","The crystal clean fragrance of water fills the air.");
   set_listen("default","The roar of the waterfall muffles all other sounds.");
   set_items(([
      ({"walls","wall","stone walls","gray stone walls"}) : "%^BOLD%^"+
         "%^BLACK%^The gray stone walls of the tower seem to blend "+
         "in to the background, difficult to see with the radiance "+
         "of the statue and the falls.%^RESET%^",
      ({"waterfall","water","falls","rainbow","rainbow falls"}) : (:TO,"rainbow_desc":),
      ({"mists","mist"}) : "%^BOLD%^Rising into the area is a billowing "+
         "mist that sparkles with the colors of the %^RED%^r"+
         "%^RESET%^%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^CYAN%^b"+
         "%^BLUE%^o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^ "+
         "and bathes the %^RESET%^statue%^RESET%^.  "+
         "Unlike natural mists, it is not cool to the touch - "+
         "indeed, it proves impossible to feel at all!%^RESET%^",
      ({"statue","icon"}) : "%^BOLD%^%^WHITE%^Fashioned from smooth white "+
         "marble, this artistic creation seeks to bring the "+
         "%^CYAN%^Mother of Knowledge %^WHITE%^to life.  Her "+
         "flowing robes have been so cleverly carved as if to "+
         "appear moving in the light of the %^BOLD%^%^RED%^r"+
         "%^RESET%^%^ORANGE%^a%^BOLD%^i%^GREEN%^n%^CYAN%^b"+
         "%^BLUE%^o%^RESET%^%^MAGENTA%^w %^BOLD%^f%^RED%^a"+
         "%^YELLOW%^l%^GREEN%^l%^CYAN%^s %^WHITE%^and mystical "+
         "globes.  Her attitude is one of supreme power and "+
         "understanding, and her face bears an expression of "+
         "other-worldliness that makes her seem unattainable.  "+
         "The tome in her left hand is massive but seems largely "+
         "forgotten, the cloth bookmark dangling carelessly as "+
         "she concentrates her energy upon the spell she generates, "+
         "calling the powers to her open right palm.  The "+
         "crowning piece of this exquisite statue is the lifelike "+
         "hair that billows around her face and dances in waves "+
         "down her back, where a belt of %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v"+
         "%^RESET%^e%^BOLD%^r %^RESET%^b%^BOLD%^r%^RESET%^a%^BOLD%^i"+
         "%^RESET%^d%^RESET%^ %^BOLD%^encircles her slender waist.%^RESET%^",
      ({"dais","stone dais","runes","mystical runes"}) : "%^BOLD%^"+
         "%^BLACK%^The dais is carved straight from the gray "+
         "stone of the tower.  It is about a foot high, and "+
         "the top surrounding the statue has been carved with "+
         "seven different runes, each of which may be examined "+
         "more closely.%^RESET%^",
      ({"rune 1","transformation rune"}) : (:TO,"look_runes":),
      ({"rune 2","insight rune"}) : (:TO,"look_runes":),
      ({"rune 3","diversity rune"}) : (:TO,"look_runes":),
      ({"rune 4","energy rune"}) : (:TO,"look_runes":),
      ({"rune 5","power rune"}) : (:TO,"look_runes":),
      ({"rune 6","resonance rune"}) : (:TO,"look_runes":),
      ({"rune 7","harmony rune"}) : (:TO,"look_runes":),
      ({"iris","irises","flowers","stands"}) : "%^BOLD%^Spiralling "+
         "stands made from burnished mithril rise near the statue, "+
         "covered entirely with waxy %^BOLD%^%^BLUE%^v%^CYAN%^a%^RESET%^"
         "%^CYAN%^r%^ORANGE%^i%^YELLOW%^e%^RED%^g%^MAGENTA%^a%^RESET%^"
         "%^MAGENTA%^t%^GREEN%^e%^BOLD%^d %^RESET%^%^CYAN%^i%^BOLD%^r%^BLUE%^i%^RESET%^%^ORANGE%^s%^YELLOW%^e%^RED%^s%^WHITE%^.  "+
         "These most unusual flowers are arranged in bountiful "+
         "designs that make the goddess appear to be in a fragrant "+
         "%^GREEN%^garden%^WHITE%^.%^RESET%^",
      ({"altar","marble altar","blue marble","blue marble altar"}) :
         "An elegant block carved from %^BOLD%^%^BLUE%^bl%^CYAN%^u"+
         "%^BLUE%^e m%^RESET%^%^BLUE%^a%^BOLD%^rb%^CYAN%^l%^BLUE%^e "+
         "%^RESET%^has been placed against the northern wall.  "+
         "The %^BOLD%^holy symbol %^RESET%^of the %^BOLD%^%^BLUE%^"+
         "Iridescent Inspiration %^RESET%^has been carved into "+
         "its smooth top, designating this as an altar.  Scattered "+
         "atop the altar are various offerings given to the Lady "+
         "by her faithful and practitioners of magic.",
      ({"offerings","gems","trinkets","magical trinkets"}) : "A "+
         "mound of %^BOLD%^%^BLUE%^blue %^RESET%^and %^BOLD%^"+
         "white %^BLUE%^g%^WHITE%^e%^BLUE%^m%^WHITE%^s%^RESET%^"+
         ", both cut and polished and left in the rough, have "+
         "been spread along the top of the altar.  Mingled among "+
         "the jewels are minor magical items such as rings, "+
         "clasps, and other trinkets, all left to honor the %^CYAN%^"+
         "Mother of Knowledge%^RESET%^.",
      ({"globes","globe","globes of light","glassteel globes"}) : 
         "The glassteel enchantment has been used to protect these "+
         "small globes.  Cunningly made, each globe was first "+
         "crafted from metal before having the magic worked upon "+
         "it.  Then, permanency made a soft %^BOLD%^white light "+
         "%^RESET%^continually work upon it to bring illumination "+
         "to this otherwise dark room.  Each globe hovers in the "+
         "area, suspended by magic."
   ]));
   set_exits(([
      "down" : ROOMS"mage_landing6"
   ]));
}

void rainbow_desc(){
string color, tmp;
   switch(random(10)){
      case 0: color = "%^BOLD%^%^RED%^red"; break;
      case 1: color = "%^RESET%^%^ORANGE%^orange";  break;
      case 2: color = "%^YELLOW%^yellow"; break;
      case 3: color = "%^BOLD%^%^GREEN%^green"; break;
      case 4: color = "%^BOLD%^%^CYAN%^blue"; break;
      case 5: color = "%^BOLD%^%^BLUE%^indigo"; break;
      case 6: color = "%^RESET%^%^MAGENTA%^violet"; break;
      case 7: color = "%^BOLD%^%^MAGENTA%^pink"; break;
      case 8: color = "%^BOLD%^%^WHITE%^silver"; break;
      default: color = "%^BOLD%^i%^RED%^r%^GREEN%^i%^CYAN%^d"+
         "%^YELLOW%^e%^MAGENTA%^s%^BLUE%^c%^WHITE%^e%^RESET%^"+
         "%^MAGENTA%^n%^YELLOW%^t"; break;
   }
   switch(random(4)){
      case 0: tmp = "Thick "+color+" vapor %^RESET%^suddenly "+
         "bathes the %^BOLD%^statue %^RESET%^in soft "+color+" "+
         "light%^RESET%^."; break;
      case 1: tmp = "The %^CYAN%^waterfall %^RESET%^pulses with "+
         ""+color+" light%^RESET%^ as you watch before fading "+
         "back to its transparent beauty."; break;
      case 2: tmp = "A %^BOLD%^g%^RESET%^l%^BOLD%^i%^RESET%^m"+
         "%^BOLD%^m%^RESET%^e%^BOLD%^r%^RESET%^i%^BOLD%^n%^RESET%^g "+
         ""+color+" mist %^RESET%^dances across the white form "+
         "of the %^BOLD%^statue%^RESET%^."; break;
      default: tmp = "The "+color+" mists %^RESET%^of the waterfall "+
         "part for a moment, and you glimpse its source - it seems "+
         "to pour forth from...nowhere!"; break;
   }
   return("The %^CYAN%^waterfall%^RESET%^ begins at a point above "+
      "the head of the statue and pours forth behind it.  "+tmp+"");
}

void look_runes(string str){
string tmp, name, lore;
int bonus;
   switch(str){
      case "rune 1": case "transformation rune":
         name = "transformation"; tmp = "This symbol looks almost "+
         "like a bird in flight made up of geometric shapes.  The "+
         "triangular beak points to the left while great arching "+
         "wings rise above and below.  The 'tail' is an extension "+
         "of the large triangle ends in a concave curve with two "+
         "points."; lore = "The rune of transformation is often "+
         "used to invoke the powers of transmutation and to "+
         "create stronger transmutation magic."; break;
      case "rune 2": case "insight rune":
         name = "insight"; tmp = "Carved cunningly to appear "+
         "almost three dimensional in shape, this rune features "+
         "an oval-shaped base.  Rising from it just right of "+
         "center is a sail-shaped triangle that seems almost to "+
         "be struggling to break the boundaries of the oval.";
         lore = "This rune is invoked by those who seek to gain "+
         "a deeper understanding.  Typically, this rune is "+
         "used by those masters of divination who seek answer to "+
         "some problem."; break;
      case "rune 3": case "diversity rune":
         name = "diversity"; tmp = "The back ground for this rune "+
         "is a triangle with the tip pointing toward the viewer.  "+
         "Inside the triangle are three interlocking circles of "+
         "different sizes."; lore = "The rune of diversity is "+
         "used most often in cooperative magic, when lore seekers "+
         "strive to bring together different aspects of magic to "+
         "reach a common goal."; break;
      case "rune 4": case "energy rune":
         name = "energy"; tmp = "This symbol has an angled streak "+
         "down the center that seems to contain the force of a "+
         "lightning bolt.  All around it, lines and curves dance, "+
         "their focus loosely turned to the bolt in the center.";
         lore = "This rune of energy calls forth the latent "+
         "powers of evocation, though it can also be used to "+
         "enhance any magical spell to be more intense."; break;
      case "rune 5": case "power rune":
         name = "power"; tmp = "This magic symbol is drawn to "+
         "look like a three-dimensional pyramid.  On the left "+
         "face is a circular outline that looks remarkably "+
         "reminiscent of the sun."; lore = "The rune of power "+
         "is called upon often in necromantic spells to "+
         "enhance the dark powers called forth.  Many other "+
         "mages find it useful, however, and it is also inscribed "+
         "upon many created magical items."; break;
      case "rune 6": case "resonance rune": 
         name = "resonance"; tmp = "This rune features great "+
         "arching curves joining together to form a triangle "+
         "that points to the right.  Superimposed on the base "+
         "of the curves is another triangle that mimics the "+
         "first."; lore = "This rune of resonance is often "+
         "inscribed to help extend the life of a spell.  "+
         "When used correctly, it has been known to even make "+
         "spells permanent.  When used incorrectly, it has been "+
         "known to drive the mage insane or to death."; break;
      case "rune 7": case "harmony rune": 
         name = "harmony"; tmp = "A small circle makes up the "+
         "center of this magical symbol.  Balancing it on "+
         "either side are two halves of what looks like a "+
         "larger circle.  They have been set apart but form a "+
         "protective shell around the central one."; lore = 
         "The rune of harmony is important to all magic.  "+
         "If the elements of a spell are not acting in concert "+
         "with each other, disaster may occur.  Magi have "+
         "learned to ignore this symbol at their own peril."; break;
      default: tell_object(TP,"Try looking at rune 1, rune 2, "+
         "and so on.");
         return;
         break;
   }
   if(TP->query_nwp("studying")) bonus = (int)TP->query_nwp("studying")-10;
   if(TP->is_class("bard")) bonus = (int)TP->query_guild_level("bard")-10;
   if(TP->is_class("mage")) bonus = TP->query_guild_level("mage");
   if(!TP->query_invis()){
      tell_room(TO,""+TPQCN+" looks over a rune.",TP);
   }
   if(bonus > 30){
      return("%^BOLD%^This is a rune of "+name+"."+
         "%^RESET%^\n"+tmp+"\n%^YELLOW%^"+lore+"%^RESET%^");
   }else{
      return(""+tmp+"");
   }
   return;
}