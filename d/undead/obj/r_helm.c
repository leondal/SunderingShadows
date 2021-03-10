#include <std.h>
//Adding 1 to ac of helm to be in line with the progression of all the other helms in easier to get places.
//Dinji

inherit "/d/common/obj/armour/helm.c";

void make_me();


#define COLORS ({"%^CYAN%^steel",\
"%^BOLD%^%^BLACK%^iron",\
"%^BOLD%^%^WHITE%^platinum",\
"%^YELLOW%^yellow gold", \
"%^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l",\
"%^BOLD%^%^RED%^fever iron",\
"%^ORANGE%^copper",\
"%^BOLD%^%^BLUE%^electrum",\
"%^YELLOW%^bronze",\
"%^BOLD%^%^CYAN%^adamantium",\
"%^BOLD%^silver",\
"%^BOLD%^%^WHITE%^white gold",\
"%^BOLD%^%^RED%^rose gold",\
"%^BOLD%^%^WHITE%^titanium",\
"%^BLUE%^cold iron",\
"%^MAGENTA%^darksteel",\
"%^BOLD%^%^WHITE%^a%^GREEN%^r%^WHITE%^and%^BLUE%^u%^WHITE%^r",\
"%^BOLD%^%^WHITE%^dl%^GREEN%^a%^WHITE%^r%^GREEN%^a%^WHITE%^n"})

#define types ({"barbute","morion","spangenhelm","sentinel","maximilian","sugarloaf"})

void create(){
   	make_me();
   	set_lore("Warriors, priests, and knights across the lands search"+
		" for an adequate means to protect their head when in battle."+
		"  Hearing the call of these armored folk, the twin brothers "+
		"Palium and Palius created a successful business in manufacturing"+
		" enchanted helms.  Palium, being a warrior himself, became a "+
		"skilled blacksmith along his adventures.  His workshop, The "+
		"Blazing Anvil, in Asgard was one of the most famous of his time."+
		" Working with his wizardly brother, Palius, Palium was able to "+
		"craft suits of armor and helmets for the adventures or clergy "+
		"folk in need of protection.  His helms have graced the heads of"+
		" many legendary figures during his time.  \n");
   	set_property("lore difficulty",7);
        set_ac(1);
    set_weight(4);
   	set_value(75);
	set_property("enchantment",3);
   	set_type("armour");
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
    case "barbute":
	TO->set_long("Crafted from "+COLOR+"%^RESET%^"+
		", this open face barbute helm"+
		" offers protection to ones head.  The dome shape of"+
		" the helmet helps to reflect blows given to the top "+
		"of the helm.  The helmet is made to fit low on the "+
		"wearer's head.  A T like shape has been cut into the"+
		" front of the helm, leaving the wearer's eyes, nose "+
		"and mouth exposed.  The insides of the helm is lined "+
		"with quilted leather, helping to bring some comfort "+
		"to the wearer.\n");
   	TO->set_name("barbute helm");
   	TO->set_short("%^RESET%^"+COLOR+" barbute helmet%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" open face helmet%^RESET%^");
   	TO->set_id(({"helm","helmet","barbute"}));
	break;
    case "morion":
      TO->set_long("Crafted from "+COLOR+"%^RESET%^, this open face "+
		"morion helm offers protection to ones head.  The dome shape of"+
		" the helmet helps to reflect blows given to the top of "+
		"the helm.  The helmet is crafted with a metal brim that"+
		" dips low in the back and rises up in the front.  The "+
		"front and back of the helmet taper to a sharp point.  "+
		"An inverted crescent shape is attached to the top of the"+
		" helm, further helping to reflect blows to the head.  "+
		"The inside of the helm is lined with quilted leather, "+
		"granting the wearer some comfort.\n");  
   	TO->set_name("morion helm");
   	TO->set_short("%^RESET%^"+COLOR+" morion helmet%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" open face helmet%^RESET%^");
   	TO->set_id(({"helmet","helm","morion"}));   
      break;
    case "spangenhelm":
      TO->set_long("Crafted from "+COLOR+"%^RESET%^, this closed face"+
		" spangenhelm "+
		"offers protection to ones head.  The dome shape of the"+
		" helmet helps to reflect blows given to the top of the "+
		"helm.  A face plate is attached to the helmet, adding an"+
		" additional feeling of protection.  The convex face plate"+
		" has been attached to the helm.  The face plate features"+
		" curved oval eye slits.  A repeating pattern of small "+
		"diamonds is cut into the metal, allowing from maximum "+
		"airflow through the face plate.  The inside of the helm "+
		"is lined with quilted leather, granting the wearer some "+
		"comfort.\n");
   	TO->set_name("spangenhelm");
   	TO->set_short("%^RESET%^"+COLOR+" spangenhelm helmet%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" close faced helmet%^RESET%^");
   	TO->set_id(({"spangenhelm","helm","helmet"}));
      break;
    case "sentinel":
      TO->set_long("Crafted from "+COLOR+"%^RESET%^, this open face"+
		" sentinel helm offers"+
		" protection to ones head.  The dome shape of the helmet "+
		"helps to reflect blows given to the top of the helm.  A "+
		"metal plate has been attached over the brow of the helm, "+
		"adding further protection to the front of the helm.  A "+
		"metal brim is set into the place above the eyes, shading"+
		" the wearer's face.  This brim helps to keep rain and "+
		"other liquids from dripping down onto the wearer.  The "+
		"inside of the helm is lined with quilted leather, "+
		"granting the wearer some comfort.\n");
   	TO->set_name("sentinel helm");
   	TO->set_short("%^RESET%^"+COLOR+" sentinel helm%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" open face helm%^RESET%^");
   	TO->set_id(({"sentinel","helm","helmet","sentinel helm"}));
      break;
    case "maximilian":
      TO->set_long("Crafted from "+COLOR+"%^RESET%^, this closed face"+
		" maximilian helm offers"+
		" protection to ones head.  The dome shape of the helmet helps"+
		" to deflect blows given to the top of the helm.  A rippling "+
		"strip of metal is attached to the top of the helm.  The peaks"+
		" and valleys of the ripping metal help further deflect blows.  "+
		"A convex hinged face plate is attached to the front of the helmet."+
		"  The face plate ripples in a similar fashion as the top of the "+
		"helm, offering similar benefits.  A thin metal horizontal stripe "+
		"is cut into the face plate, for sake of vision.  Small circular "+
		"holes perforate the visor, allowing for plenty of air to flow "+
		"inside.  The inside of the helm is lined with quilted leather, "+
		"granting the wearer some comfort.\n");
   	TO->set_name("maximilian helm");
   	TO->set_short("%^RESET%^"+COLOR+" maximilian helm%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" closed face helm%^RESET%^");
   	TO->set_id(({"maximilian helm","helmet","helm"}));
      break;
    case "sugarloaf":
      TO->set_long("Crafted from "+COLOR+"%^RESET%^, this closed face"+
		" sugarloaf helm "+
		"offers protection to ones head.  The tall cone shape of the "+
		"helmet helps to deflect blows given to the top of the helm. "+
		"This seamless helm is crafted without a face plate, in hopes "+
		"of further protection the wearer.  Contrasting metal strips "+
		"are overlain onto the front of the helm.  These metal strips, "+
		"in a cross like shape, add an additional sense of protection.  "+
		"A rectangular slit is cut into the front of the helm, for sake "+
		"of vision.  Small round holes perforate the helm underneath the "+
		"eye slit, allowing for plenty of air to flow to the wearer.  The "+
		"inside of the helm is lined with quilted leather, granting the "+
		"wearer some comfort.\n");
   	TO->set_name("sugarloaf helm");
   	TO->set_short("%^RESET%^"+COLOR+" sugarloaf helm%^RESET%^");
   	TO->set_obvious_short("%^RESET%^"+COLOR+" closed face helm%^RESET%^");
   	TO->set_id(({"sugarloaf helm","helm","helmet"}));
      break;
	}
}
