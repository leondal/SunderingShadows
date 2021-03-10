//converted from 2AC to +2, nienne 05/07
#include <std.h>
inherit "/d/common/obj/clothing/magerobe";
void make_me();


#define COLORS ({"%^BOLD%^%^BLACK%^jet black",\
"%^BOLD%^%^WHITE%^brilliant white",\
"%^BOLD%^%^RED%^crimson red",\
"%^RESET%^%^RED%^scarlet red",\
"%^RESET%^%^ORANGE%^bright orange",\
"%^RESET%^%^ORANGE%^walnut brown",\
"%^YELLOW%^goldenrod",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^RESET%^%^GREEN%^forest green",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^BOLD%^%^BLUE%^cerulean blue",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^RESET%^%^CYAN%^slate blue",\
"%^BOLD%^%^CYAN%^aquamarine blue",\
"%^RESET%^%^MAGENTA%^deep purple",\
"%^MAGENTA%^plum",\
"%^BOLD%^%^MAGENTA%^bright pink",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r",\
"%^ORANGE%^g%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d",\
"%^BOLD%^%^RED%^ruby red",\
"%^BOLD%^%^WHITE%^light cream",\
"%^BOLD%^%^BLACK%^raven black",\
"%^MAGENTA%^wine",\
"%^BOLD%^%^MAGENTA%^pale pink",\
"%^CYAN%^sea green"})


#define types ({"robe","jacket","toga","overcoat","tunic","vest"})

void create(){
   ::create();
   	make_me();
   	set_lore("Mage and Wizards have long needed a way to keep their"+
		" books and components close at hand.  While"
		" the typical mage care little for his sense"+
		" of style (thus how the robes became adopted) many"+
		" soon felt a need to create other garments that "+
		"offered similiar benifits as typical mage robes, but"+
		" were more fashionable"
		" and less fuddy duddy.  Thus the Arcane garments were "+
		"born. As long as there are mages, there will always be a"
		" demand for the Arcane clothing, much to the delight of"+
		" Pixenel Heffelhopps, the leading vendor and creator of"
		" the Arcane Clothing.");
	set_property("lore difficulty",10);
   set_property("enchantment",2);
//        set_ac(2);
   	set_weight(5);
   	set_value(1000);
   	set_type("clothing");
   	set_limbs(({"torso"}));
   	set_size(-1); 
   	set_max_internal_encumbrance(21);
   	set_wear((:TO,"wear_stuff":));
}

int wear_stuff(){
       if(!TP->is_class("bard") && !TP->is_class("psion") && !TP->is_class("mage") && !TP->is_class("sorcerer") && !TP->is_class("psywarrior")) {
		write("%^BOLD%^%^MAGENTA%^The magic within these robes prevents you from wearing them.");
		return 0;
	}
	return 1;
}
void make_me(){
int i,x;
   string type, COLOR;
    i = random(sizeof(COLORS));
       COLOR = COLORS[i];
    x = random(sizeof(types));
       type = types[x];
   switch(type){
   case "robe":
     TO->set_long("%^CYAN%^Shaped from cashmere wool, "+
		"this "+COLOR+" %^RESET%^%^CYAN%^robe"	
		" is full and voluminous.  With"
		" long sweeping sleeves and plenty of fabric for even"+
		" the largest of figures, it looks quite comfortable."
		"  Braided trim in precious metals such as "+
		"%^BOLD%^silver%^RESET%^%^CYAN%^, %^YELLOW%^gold"+
		"%^RESET%^%^CYAN%^, and %^BOLD%^%^CYAN%^platinum "+
		"%^RESET%^%^CYAN%^decorate the robe, giving it a "+
		"mystical feeling. The %^BOLD%^b%^WHITE%^r%^YELLOW%^"+
		"a%^CYAN%^i%^WHITE%^d%^YELLOW%^e%^CYAN%^d%^RESET%^%^CYAN%^"+
		" trim wraps around the cuffs of the robes, giving it a "+
		"stylish touch that any wizard would be proud of. There are a couple"
		" of pockets in the sides of the robes, perhaps to keep "+
		"some items safe and close at hand.\n%^RESET%^");
   TO->set_name("robe");
   TO->set_short("%^RESET%^"+COLOR+" arcane robe%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" cashmere robe%^RESET%^");
   TO->set_id(({"robe","arcane robe","robes","arcane robes", "mage robe","mage robes"}));
      break;
   case "jacket":
      TO->set_long("%^CYAN%^Made from heavy silk, this "+COLOR+" "+
		"%^RESET%^%^CYAN%^jacket has a lavish "
		"and elegant feel to it.  The silhouette is cut"
		" close to the body.  The upper parts of the sleeves "+
		"are slashed to reveal a striped %^BOLD%^%^BLACK%^"+
		"black%^RESET%^%^CYAN%^ and %^BOLD%^%^WHITE%^white"+
		"%^RESET%^%^CYAN%^ silk underneath, a style that is"+
		" typical among the nobles.  Lacing and eyelets run "+
		"up the forearm of each sleeve, allowing one to lace"+
		" them skintight.  The front of the jacket is lightly"+
		" padded, to give the appearance of"
		" a broader chest and a narrower waist.\n%^RESET%^");  
   TO->set_name("jacket");
   TO->set_short("%^RESET%^"+COLOR+" arcane jacket%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" silk jacket%^RESET%^");
   TO->set_id(({"jacket","arcane jacket","mage jacket","robes"}));   
      break;
   case "toga":
      TO->set_long("%^CYAN%^Finely spun wool has been woven in to this "+
		"length of "+COLOR+" %^RESET%^%^CYAN%^cloth.  The fabric "+
		"is folded and pleated about ones body to create this "+
		"garment.  Women typically use the cloth to first bind their"
		" breasts and then create the rest of the garment. While "+
		"the men prefer to leave their chest bare and exposed."
		"Typically togas are worn long, though it is not uncommon"+
		" to see them as short as knee length, or for the"
		" brazen young man or woman- higher than knee length! The"+
		" excess cloth is folded across the chest and usually"
		" held in place with brooches and pins. The edges of "+
		"the wool cloth feature a border of %^BOLD%^%^WHITE%^m"+
		"%^BLACK%^y%^BLUE%^t%^RED%^i%^WHITE%^c%^BLACK%^a%^BLUE%^"+
		"l%^RESET%^%^CYAN%^ looking runes. One could easily"+
		" hide a few items within the pockets the "+
		"pleating creates.\n%^RESET%^");
   TO->set_name("toga");
   TO->set_short("%^RESET%^"+COLOR+" arcane toga%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" wool toga%^RESET%^");
   TO->set_id(({"toga","arcane toga","mage toga","robes"}));
      break;
   case "overcoat":
      TO->set_long("%^CYAN%^Soft thin leather is used in the "+
		"creation of this loose fitting "+COLOR+" "+
		"%^RESET%^%^CYAN%^overcoat.  The coat comes"
		" to a stop at ones ankles, offering plenty of "+
		"protection from the elements.  The front of the"+
		" overcoat features an unbroken silhouette, "+
		"looking slightly stiff and rigid.  From the "+
		"waist down the excess fabric of the coat"
		" falls about in soft folds.  The long narrow "+
		"sleeves on the overcoat would keep anyone dry in the worst rains."
		"  Along each side are a row of hidden %^RESET%^silver%^CYAN%^"+
		" hooks, allowing one to close the coat without breaking the smooth"
		" lines of the front.  The coat has a monastic quality to it, "+
		"but the leather and small details help to shatter"
		" that image somewhat.  Two pockets are hidden in the seams of "+
		"the coat on either hip.\n%^RESET%^");
   TO->set_name("overcoat");
   TO->set_short("%^RESET%^"+COLOR+" arcane overcoat%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" thin leather overcoat%^RESET%^");
   TO->set_id(({"overcoat","arcane overcoat","coat","arcane coat", "mage coat","mage overcoat","robes"}));
      break;
   case "tunic":
      TO->set_long("%^CYAN%^Thick, though soft, silk is the "+
		"fabric of choice for this "+COLOR+" %^RESET%^%^CYAN%^"+
		"tunic. The full cut tunic features an open neckline "+
                "that is secured closed by %^RESET%^antique%^CYAN%^ "+
                "clasps in the shape of intertwined dragons.  The "+
                "long tunic flows past the knees, the excess fabric"+
                " typically gathered up with a belt or girdle.  A "+
                "slit up the front of the tunic adds for ease in walking."+
                "  Long full sleeves come down to the wrists, giving "+
                "plenty of coverage.  The tunic is trimmed with bands "+
                "of metallic threads in a series of %^BOLD%^%^CYAN%^a"+
                "r%^YELLOW%^c%^WHITE%^a%^CYAN%^n%^YELLOW%^e%^RESET%^%^CYAN%^"+
                " looking patterns. \n%^RESET%^");
   TO->set_name("tunic");
   TO->set_short("%^RESET%^"+COLOR+" arcane tunic%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" silk tunic%^RESET%^");
   TO->set_id(({"tunic","arcane tunic","tunic","mage tunic","robes"}));
      break;
   case "vest":
      TO->set_long("%^CYAN%^Elegant brocade in "+COLOR+" %^RESET%^%^CYAN%^is "+
		"used to create this lean vest.  The vest's shape fits close to the"
		" body in a smooth fit.  The sleeveless vest is lined with a "+
		"%^RESET%^neutral gray %^CYAN%^silk, as not to distract from the"
		" striking %^BOLD%^%^BLUE%^b%^YELLOW%^r%^WHITE%^o%^BLACK%^c"+
		"%^BLUE%^a%^YELLOW%^d%^WHITE%^e%^RESET%^%^CYAN%^ pattern.  "+
		"While most vests typically stop at the waist, this one drops"+
		" down futher, coming to below the hips.  Vests are commonly"+
		" worn by men with an undershirt, though some women in recent"+
		" years have come to wear them over their chemises.  An "+
		"ornate %^BOLD%^%^WHITE%^titantium%^RESET%^%^CYAN%^ buckle"+
		" set in the lower back of this vest allows"
		" for it to be adjusted to fit any size.  The buckle features"+
		" %^BOLD%^%^BLUE%^arcane runes%^RESET%^%^CYAN%^ carved into it"+
		" the white metal.  A couple of pockets are stitched into the "+
		"vest, allowing one to store a couple of items safely.\n%^RESET%^");
   TO->set_name("vest");
   TO->set_short("%^RESET%^"+COLOR+" arcane vest%^RESET%^");
   TO->set_obvious_short("%^RESET%^"+COLOR+" brocade vest%^RESET%^");
   TO->set_id(({"vest","arcane vest","mage vest","robes"}));
      break;
   }
}
