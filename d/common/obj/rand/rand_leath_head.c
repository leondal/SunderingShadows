#include <std.h>
inherit ARMOUR;
void make_me();

#define COLORS ({"%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y",\
"%^BOLD%^%^RED%^ruby red",\
"%^RED%^garnet red",\
"%^GREEN%^emerald green",\
"%^BOLD%^%^GREEN%^peridot green",\
"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^BLUE%^lapis blue",\
"%^BOLD%^%^WHITE%^brilliant white",\
"%^BOLD%^%^BLACK%^onyx black",\
"%^BLUE%^i%^MAGENTA%^n%^BLUE%^d%^MAGENTA%^i%^BLUE%^go",\
"%^YELLOW%^citrine yellow",\
"%^ORANGE%^tan",\
"%^BOLD%^%^CYAN%^turquoise",\
"%^BOLD%^%^CYAN%^aquamarine",\
"%^MAGENTA%^amethyst",\
"%^BOLD%^%^MAGENTA%^desert rose",\
"%^BOLD%^%^BLACK%^stone gray",\
"%^BOLD%^%^BLACK%^beryl gray",\
"%^MAGENTA%^plum",\
"%^BOLD%^%^MAGENTA%^fuchsia",\
"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^YELLOW%^n"})

#define types ({"coif","skullcap","hat","mask","bandanna","hood"})

void create(){
   	make_me();
   	set_lore("While on adventures, rogues, priests, and rangers "+
		"have always found a need to find some kind of protection"+
		" for their heads.  Some priests favor donning metal and "+
		"mail when they must battle, but others prefer leather.  "+
		"Rogues have always found a need to use lightweight headgear"+
		" to protect themselves, some even favoring form above function."+
		"  Hearing the complaints of a few of her friends, Desdemona the"+
		" Saffron, an enchantress, hired some of the best tailors, "+
		"seamstresses, and tanners across the lands to create for her"+
		" coifs, veils, hoods, skullcaps, hats and masks.  From her "+
		"workshop she then utilized her growing number of apprentices"+
		" to enchant these pieces of headgear to offer protection.  "+
		"Desdemona's side project soon became a very successful business"+
		" that kept her and her apprentices very rich and in demand.\n");
   	set_property("lore difficulty",7);
   	set_ac(0);
	set_weight(3);
   	set_value(75);
	set_property("enchantment",2);
      //set_type("leather"); changing this so that each type has its own type.  Cloth is cloth, leather is leather
   	set_limbs(({"head"}));
   	set_size(random(3)+1); 
}

void make_me(){
int i,x;
   string type, COLOR;
    i = random(sizeof(COLORS));
       COLOR = COLORS[i];
    x = random(sizeof(types));
       type = types[x];
   ::create();
   	switch(type){
case "coif":
	TO->set_long("%^CYAN%^Stitched from boiled leather, "+
		"this "+COLOR+" %^RESET%^%^CYAN%^coif has been "+
		"fashioned.  The boiled leather is tough and "+
		"unyielding.  The leather coif has a rounded dome"+
		" crown which is made to fit flush against the "+
		"wearer's head.  Leather flaps are stitched to the"+
		" sides of the coif, offering protection to the "+
		"ears.  Two twin cords of "+COLOR+" %^RESET%^%^CYAN%^"+
		"leather are attached to each flap, meant to be tied "+
		"under the wearer's chin.  These cords help secure "+
		"the coif in place, keeping the wearer safe from any"+
		" head blows.  The inside of the coif is lined with"+
		" quilted "+COLOR+" %^RESET%^%^CYAN%^cotton, giving"+
		" some cushion and comfort to the wearer.\n%^RESET%^");
   	TO->set_name("leather coif");
   	TO->set_short("%^RESET%^"+COLOR+" leather coif%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" leather coif%^RESET%^");
   	TO->set_id(({"coif","leather coif","helm"}));
      TO->set_type("leather");
      break;
case "skullcap":
      TO->set_long("%^CYAN%^Four triangular sections of soft "+COLOR+" "+
		"%^RESET%^%^CYAN%^suede are stitched together to "+
		"shape this skullcap.  The skullcap is made to only"+
		" cover the top of the wearer's head.  The skullcap "+
		"is prized and used by many scholars, sages, and "+
		"priests who do not wish to present an image of being"+
		" fully armored.  The "+COLOR+" %^RESET%^%^CYAN%^suede"+
		" exterior of the skullcap is stretched over a hardened"+
		" leather frame, giving shape to the cap.  The inside "+
		"of the cap is lined with suede, to help cushion any "+
		"blows and for comfort.\n%^RESET%^");  
   	TO->set_name("skullcap");
   	TO->set_short("%^RESET%^"+COLOR+" leather skullcap%^RESET%^");
      TO->set_id(({"cap","skullcap","leather cap","leather skullcap"}));   
      TO->set_type("leather");
      break;
case "hat":
      TO->set_long("%^CYAN%^This stylish hat is shaped from "+COLOR+" "+
		"%^RESET%^%^CYAN%^felt.  The wide brim of the hat is "+
		"softly formed and allowed to keep it's loose shape.  "+
		"This allows for the wear to decided how they will wear "+
		"their hat.  The crown of the hat is rounded to fit flush"+
		" with the wearer's head.  Inside the crown a boiled leather"+
		" plate has been sandwiched between two layers of felt, giving"+
		" additional protection to the stylish hat.  It is common for"+
		" people to personalize these hats with brooches, pins, or"+
		" plumes of feathers.\n%^RESET%^");
   	TO->set_name("hat");
   	TO->set_short("%^RESET%^"+COLOR+" felt hat%^RESET%^");
      TO->set_id(({"hat","felt hat","felt"}));
      TO->set_type("leather");
      break;
case "mask":
      TO->set_long("%^CYAN%^Fashioned from plush "+COLOR+" "+
		"%^RESET%^%^CYAN%^velvet, this "+
		"full mask covers the wearer's face.  Attached to"+
		" a twisted headband of "+COLOR+" %^RESET%^%^CYAN%^"+
		"velvet, the mask is allowed to drape freely.  A pair"+
		" of ties at the top of the mask allow for it to be "+
		"doubly secured behind the wearer's head.  Eye slits"+
		" are cut in the velvet and reinforced with "+
		"complimentary threads.  This extra stitching around"+
		" the eyes helps keep the plush velvet from unraveling."+
		"  Inside the hem of the mask a pair of small "+
		"%^BOLD%^%^BLACK%^iron weights%^RESET%^%^CYAN%^ have "+
		"been sewn into the cloth.  These weights help to keep"+
		" the mask from flying up and revealing the identity "+
		"of the wearer.\n%^RESET%^");
   	TO->set_name("velvet mask");
   	TO->set_short("%^RESET%^"+COLOR+" velvet mask%^RESET%^");
      TO->set_id(({"mask","velvet mask","velvet"}));
      TO->set_type("clothing");
      break;
case "bandanna":
      TO->set_long("%^CYAN%^Woven from a combination of metallic threads and"+
		" "+COLOR+" %^RESET%^%^CYAN%^silk, this brocade pattern"+
		" bandanna is meant "+
		"to be tied onto the wearer's head.  Some folks find they "+
		"prefer rolling the bandanna up and then tying it on.  "+
		"Others find they prefer covering the top of their head "+
		"with the cloth and then tucking in the rolled edge of the"+
		" bandanna.  The "+COLOR+" %^RESET%^%^CYAN%^silk "+
		"background of the bandanna features a geometrical brocade"+
		" pattern of squares, lines, circles and triangles.  The "+
		"metallic threads are actually thin strands of %^BOLD%^mithril"+
		"%^RESET%^%^CYAN%^ and %^BOLD%^%^WHITE%^titanium%^RESET%^%^CYAN%^"+
		" woven into the cloth to add some stability and protection to "+
		"the fragile looking silk.\n%^RESET%^");
   	TO->set_name("brocade bandanna");
   	TO->set_short("%^RESET%^"+COLOR+" brocade bandanna%^RESET%^");
      TO->set_id(({"bandanna","brocade bandanna","brocade"}));
      TO->set_type("leather");
      break;
case "hood":
      TO->set_long("%^CYAN%^Fashioned from soft "+COLOR+"%^RESET%^%^CYAN%^ cotton"+
		", this full hood looks comfortable.  The cotton hood has been attached"+
		" to a short mantel, to give it some added stability.  The mantle is "+
		"made to rest on the wearer's shoulders and across their chest and "+
		"back.  The voluminous hood has been cut with a generous amount of "+
		"cloth, allowing for it to fit nearly any size of head.  The inside "+
		"of the hood is lined with %^BOLD%^%^BLACK%^black cotton%^RESET%^"+
		"%^CYAN%^, helping to create shadows "+
		"should the wearer wish to conceal their face.  The rounded crown of "+
		"the hood is made to rest on the top of wearer's head and then drape "+
		"down to the mantle.%^RESET%^  \n");
   	TO->set_name("cotton hood");
   	TO->set_short("%^RESET%^"+COLOR+" cotton hood%^RESET%^");
      TO->set_id(({"hood","cotton hood","cotton"}));
      TO->set_type("clothing");
      break;
	}
}
