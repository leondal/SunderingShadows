//~Circe~ 5/30/07 - to give flavor to the yuan-ti without overpowering their items :)
#include <std.h>

#define TYPES ({"bracelet","amulet","ring","earrings","necklace","clasp"})

#define STONES ({"%^MAGENTA%^amethyst%^RESET%^",\
"%^BOLD%^%^WHITE%^ivory%^RESET%^",\
"%^BOLD%^%^BLACK%^ebony%^RESET%^",\
"%^GREEN%^agate%^RESET%^",\
"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx%^RESET%^",\
"%^ORANGE%^amber%^RESET%^",\
"%^BOLD%^%^GREEN%^jade%^RESET%^",\
"%^BOLD%^%^WHITE%^crystal quartz%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose quartz%^RESET%^",\
"%^BOLD%^%^BLACK%^smoky quartz%^RESET%^",\
"%^ORANGE%^tigers eye%^RESET%^",\
"%^RED%^fire agate%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^GREEN%^bloodstone%^RESET%^",\
"%^MAGENTA%^jasper%^RESET%^",\
"%^BOLD%^%^RED%^carnelian%^RESET%^",\
"%^YELLOW%^citrine%^RESET%^",\
"%^BLUE%^lapis lazuli%^RESET%^",\
"%^CYAN%^beryl%^RESET%^",\
"%^ORANGE%^topaz%^RESET%^",\
"%^CYAN%^malachite%^RESET%^",\
"%^BOLD%^%^BLUE%^blue spinel%^RESET%^",\
"%^RED%^red spinel%^RESET%^",\
"%^BOLD%^%^RED%^red jasper%^RESET%^",\
"%^GREEN%^moss agate%^RESET%^",\
"%^BOLD%^%^GREEN%^peridot%^RESET%^",\
"%^RED%^garnet%^RESET%^",\
"%^BOLD%^%^BLACK%^hematite%^RESET%^",\
"%^RESET%^%^CYAN%^turquoise%^RESET%^"})

#define WOODS ({ "%^RESET%^%^ORANGE%^copper%^RESET%^",\
"%^BOLD%^%^CYAN%^mithril%^RESET%^",\
"%^BOLD%^%^WHITE%^platinum%^RESET%^",\
"%^RESET%^%^GREEN%^aged copper%^RESET%^",\
"%^RESET%^%^ORANGE%^bronze%^RESET%^",\
"%^BOLD%^%^WHITE%^white gold%^RESET%^",\
"%^YELLOW%^yellow gold%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose gold%^RESET%^",\
"%^RESET%^%^BLUE%^electrum%^RESET%^",\
"%^BOLD%^%^WHITE%^silver%^RESET%^"})

#define DESIGNS ({"%^BOLD%^%^WHITE%^cumulus cloud%^RESET%^",\
"%^GREEN%^countless leaves%^RESET%^",\
"%^MAGENTA%^setting sun%^RESET%^",\
"%^BOLD%^%^CYAN%^ornate harp%^RESET%^",\
"%^CYAN%^twin crossed long swords%^RESET%^",\
"%^BOLD%^%^CYAN%^twin crossed short swords%^RESET%^",\
"%^BOLD%^%^CYAN%^starburst%^RESET%^",\
"%^YELLOW%^heart%^RESET%^",\
"%^BOLD%^%^BLUE%^majestic crescent moon%^RESET%^",\
"%^BOLD%^%^MAGENTA%^garland of flowers%^RESET%^",\
"%^GREEN%^leafy oak tree%^RESET%^",\
"%^BLUE%^slender wolf%^RESET%^",\
"%^BOLD%^%^BLACK%^stylized long bow%^RESET%^",\
"%^BOLD%^%^WHITE%^silver arrow%^RESET%^"})

#define TOTEMS ({"%^RESET%^%^GREEN%^cathsee%^RESET%^",\
"%^RESET%^%^GREEN%^cooshee%^RESET%^",\
"%^BOLD%^%^BLACK%^wolf%^RESET%^",\
"%^BOLD%^%^WHITE%^unicorn%^RESET%^",\
"%^BOLD%^%^CYAN%^pegasus%^RESET%^",\
"%^RESET%^%^ORANGE%^hawk%^RESET%^",\
"%^YELLOW%^phoenix%^RESET%^",\
"%^BOLD%^%^WHITE%^dragon%^RESET%^",\
"%^RESET%^%^RED%^fox%^RESET%^",\
"%^BOLD%^%^MAGENTA%^tressym%^RESET%^",\
"%^BOLD%^%^BLACK%^panther%^RESET%^",\
"%^RESET%^%^RED%^b%^BOLD%^u%^RESET%^%^ORANGE%^t%^YELLOW%^t%^GREEN%^e%^CYAN%^r%^BLUE%^f%^RESET%^%^BLUE%^l%^MAGENTA%^y%^RESET%^",\
"%^BOLD%^%^BLUE%^rabbit%^RESET%^"})

inherit DAEMON;

string TYPE,STONE,WOOD,DESIGN,TOTEM,brief,desc,mylimb,lore;
int i,j,k,l,m,val;

void create_jewelry(object obj){
   i = random(sizeof(TYPES));
   TYPE = TYPES[i];
   j = random(sizeof(STONES));
   STONE = STONES[j];
   k = random(sizeof(WOODS));
   WOOD = WOODS[k];
   l = random(sizeof(DESIGNS));
   DESIGN = DESIGNS[l];
   m = random(sizeof(TOTEMS));
   TOTEM = TOTEMS[m];
   val = (random(100)+random(100)+500);
   if(TYPE == "bracelet"){
      obj->set_id(({"jewelry","bracelet","bangle bracelet","bangle"}));
      if(!random(2)){
         mylimb = "left arm";
      }else{
         mylimb = "right arm";
      }
      switch(random(3)){
         case 0:  brief = "%^RESET%^%^a braided "+WOOD+" %^RESET%^bracelet%^RESET%^";
                  desc = "%^RESET%^This flat bracelet is made of many "+
                     "strands of "+WOOD+" set with tiny "+STONE+" beads.  "+
                     "The bracelet tapers at either end to a small "+
                     "braid, creating a cuff.";
                  break;
         case 1:  brief = "%^RESET%^a carved "+WOOD+" bangle%^RESET%^";
                  desc = "%^RESET%^This bangle is made of a flat "+
                     "piece of "+WOOD+" about an inch wide.  The surface "+
                     "has been carved with a "+DESIGN+" that add decoration "+
                     "to an otherwise elegant but simple piece of jewelry.";
                  break;
         default: brief = "%^RESET%^a carved "+WOOD+" %^RESET%^bracelet%^RESET%^";
                  desc = "%^RESET%^This "+WOOD+" bracelet has been carved "+
                     "with a "+TOTEM+" image.  Small "+STONE+" stones accentuate"+
			    " the carving, giving it a dazzling effect.";
                  break;
      }
   }
   if(TYPE == "amulet"){
      obj->set_id(({"jewelry","amulet","necklace"}));
      mylimb = "neck";
      brief = "%^RESET%^a carved "+WOOD+" %^RESET%^amulet%^RESET%^";
      desc = "Suspended on a thin "+WOOD+" chain, is a carved "+STONE+". "+
		" Taking the image of a "+DESIGN+", the amulet posses an elegant"+
		" intricate design.  Clearly, much time and craftsmanship went "+
         "into the creation of this piece of jewelry.";
   }
   if(TYPE == "ring"){
      obj->set_id(({"jewelry","ring","wooden ring"}));
      if(!random(2)){
         mylimb = "left hand";
      }else{
         mylimb = "right hand";
      }
      brief = "%^RESET%^a "+WOOD+" ring set with "+STONE+"";
      desc = "%^RESET%^This slender ring is made of a solid piece of "+WOOD+" "+
         "that has been carved in an lattice design.  The edges of the ring "+
         "taper, making it somewhat fragile in apperance.  A square cut "+STONE+" is "+
         "set into the top of the ring.";
   }
   if(TYPE == "earrings"){
      obj->set_id(({"jewelry","earrings","pair of earrings","earring"}));
      mylimb = "head";
      switch(random(2)){
         case 0:  brief = "%^RESET%^a "+WOOD+" earring%^RESET%^";
                  desc = "%^RESET%^This elegant earring is made "+
                     "of "+WOOD+".  Carved into the "+WOOD+" are images"+
			   " of "+DESIGN+", adding an artistic touch to this "+
			   "graceful earring.";
                  break;
         default: brief = ""+STONE+" %^RESET%^earrings%^RESET%^";
                  desc = "%^RESET%^The base for these earrings is carved "+
                     "from "+WOOD+".  The earrings dangle about three "+
                     "inches, with the lowest point encrusted with several "+
                     "small pieces of "+STONE+".";
                  break;
      }
   }
   if(TYPE == "necklace"){
      obj->set_id(({"jewelry","necklace","totem necklace"}));
      mylimb = "neck";
      brief = "%^RESET%^a "+WOOD+" necklace with a carved "+STONE+" "+TOTEM+"";
      desc = "%^RESET%^This necklace is made of a simple braided length of "+
         ""+WOOD+".  Hanging from a "+WOOD+" chain in the front is a stylized "+
         ""+TOTEM+" carved from "+STONE+".  Details of the "+TOTEM+" "+
         "have been carved and highlighted with fading paint, giving it a "+
	   "lifelike apperance.";
   }
	if(TYPE == "clasp"){
      obj->set_id(({"jewelry","clasp","cloak clasp"}));
      mylimb = "neck";
      switch(random(2)){
         case 0:  brief = "%^RESET%^a "+WOOD+" clasp%^RESET%^";
                  desc = "%^RESET%^Crafted from "+WOOD+", this round"+
				" cloak clasp has been polished to a high sheen."+
				"  The metal has been artfully carved into a "+DESIGN+","+
				" creating a highly detailed masterpiece.  Small "+STONE+" "+
				"chips accentuate the design, giving it more depth.  On "+
				"the backside of the clasp, a long slender pin has been "+
				"attached.  The pin looks strong enough to pierce even "+
				"the thickest fabrics, but gentle enough for more delicate"+
				" cloths.";
                  break;
         default: brief = ""+STONE+" %^RESET%^carved clasp%^RESET%^";
                  desc = "%^RESET%^Crafted from "+STONE+", this cloak clasp "+
				"has been polished to a high sheen.  Artfully carved "+
				"into the image of a "+TOTEM+", the cloak clasp is a "+
				"detailed masterpiece.  Light falls upon the facets of"+
				" the "+STONE+", giving added sparkle to the already "+
				"dazzling carving.  On the reverse side of the clasp a "+
				"slender narrow pin has been attached.  The pin looks "+
				"delicate enough for fragile fabrics, but strong enough "+
				"even to pierce the thickest leather.";
                  break;
      }
   }

   obj->set_value(val);
   obj->set_type("ring");
   obj->set_limbs(({""+mylimb+""}));
   obj->set_weight(1+random(2));
   obj->set_name("jewelry");
   obj->set_short(""+brief+"");
   obj->set_long(""+desc+"");
   obj->set_lore("Crafted by Elderthanal Silverspring, this piece of jewelry"+
		" displays the famous artistic beauty that is known to the elves. "+
		" Elderthanal spends years on each piece of jewelry, never satisfied"+
		" with average workmanship or styles.  This is one reason why his "+
		"jewelry is so expensive, for the time and care he puts into it.");
}
