//~Circe~ 5/30/07 - to give flavor to the yuan-ti without overpowering their items :)
#include <std.h>

#define TYPES ({"bracelet","torque","ring","earrings","necklace","hair clip"})

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
"%^BOLD%^%^BLACK%^smokey quartz%^RESET%^",\
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

#define WOODS ({ "%^RESET%^%^ORANGE%^oak%^RESET%^",\
"%^RESET%^%^RED%^cedar%^RESET%^",\
"%^RESET%^%^RED%^red oak%^RESET%^",\
"%^RESET%^%^ORANGE%^ironwood%^RESET%^",\
"%^RESET%^%^ORANGE%^ash%^RESET%^",\
"%^RESET%^%^RED%^mahogany%^RESET%^",\
"%^YELLOW%^golden oak%^RESET%^",\
"%^BOLD%^%^BLACK%^chonta wood%^RESET%^",\
"%^RESET%^%^RED%^teak%^RESET%^",\
"%^BOLD%^%^WHITE%^balsa wood%^RESET%^"})

#define DESIGNS ({"%^ORANGE%^images of sparrows in flight%^RESET%^",\
"%^GREEN%^countless leaves%^RESET%^",\
"%^MAGENTA%^complex geometric patterns%^RESET%^",\
"%^GREEN%^images of knotted snakes%^RESET%^",\
"%^RED%^scenes of battles between human warriors and snake-men%^RESET%^",\
"%^YELLOW%^interlocking circles%^RESET%^",\
"%^BOLD%^the phases of the moon%^RESET%^",\
"%^BOLD%^%^MAGENTA%^images of the sunrise over mountains%^RESET%^",\
"%^GREEN%^many jungle trees%^RESET%^",\
"%^BOLD%^%^BLACK%^intricate maze patterns%^RESET%^",\
"%^YELLOW%^three overlapping pyramids%^RESET%^",\
"%^BOLD%^%^WHITE%^wolves baying at the moon%^RESET%^"})

#define TOTEMS ({"%^RESET%^%^GREEN%^frog%^RESET%^",\
"%^RESET%^%^GREEN%^snake%^RESET%^",\
"%^BOLD%^%^BLACK%^wolf%^RESET%^",\
"%^BOLD%^%^BLACK%^jaguar%^RESET%^",\
"%^BOLD%^%^GREEN%^macaw%^RESET%^",\
"%^RESET%^%^ORANGE%^monkey%^RESET%^",\
"%^RESET%^%^ORANGE%^wild boar%^RESET%^",\
"%^RESET%^%^GREEN%^iguana%^RESET%^",\
"%^RESET%^%^ORANGE%^porcupine%^RESET%^",\
"%^BOLD%^%^MAGENTA%^ibis%^RESET%^",\
"%^BOLD%^%^BLACK%^bat%^RESET%^",\
"%^BOLD%^%^BLUE%^parrot%^RESET%^"})

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
   val = (random(100)+random(100)+50);
   if(TYPE == "bracelet"){
      obj->set_id(({"jewelry","bracelet","bangle bracelet","wooden bracelet","bangle"}));
      if(!random(2)){
         mylimb = "left arm";
      }else{
         mylimb = "right arm";
      }
      switch(random(3)){
         case 0:  brief = "%^RESET%^%^ORANGE%^a braided "+STONE+" %^ORANGE%^bracelet%^RESET%^";
                  desc = "%^RESET%^This flat bracelet is made of many "+
                     "strands of %^GREEN%^d%^ORANGE%^y%^CYAN%^e%^GREEN%^d "+
                     "%^RESET%^hemp set with tiny "+STONE+" beads.  "+
                     "The bracelet tapers at either end to a small "+
                     "braid, and both ends are meant to be tied together "+
                     "to secure it.";
                  break;
         case 1:  brief = "%^RESET%^%^ORANGE%^a carved "+WOOD+" %^ORANGE%^bangle%^RESET%^";
                  desc = "%^RESET%^This wooden bangle is made of a flat "+
                     "piece of "+WOOD+" about an inch wide.  The surface "+
                     "has been carved with "+DESIGN+" that add decoration "+
                     "to an otherwise simple piece of jewelry.";
                  break;
         default: brief = "%^RESET%^%^ORANGE%^a carved "+WOOD+" %^ORANGE%^snake bracelet%^RESET%^";
                  desc = "%^RESET%^This "+WOOD+" bracelet has been carved "+
                     "to resemble a %^GREEN%^snake%^RESET%^ biting its own "+
                     "tail.  The %^GREEN%^snake %^RESET%^looks incredibly "+
                     "lifelike, and its eyes have been set with glittering "+
                     ""+STONE+" chips.";
                  break;
      }
   }
   if(TYPE == "torque"){
      obj->set_id(({"jewelry","torque","wooden necklace"}));
      mylimb = "neck";
      brief = "%^RESET%^%^ORANGE%^a carved "+WOOD+" %^ORANGE%^torque%^RESET%^";
      desc = "%^RESET%^About three inches wide, this "+WOOD+" torque "+
         "covers most of the neck when worn.  It has been carved with "+
         ""+DESIGN+" and carefully painted in faint colors to add "+
         "further detail.  Clearly, much time and craftsmanship went "+
         "into the creation of this piece of jewelry.";
   }
   if(TYPE == "ring"){
      obj->set_id(({"jewelry","ring","wooden ring"}));
      if(!random(2)){
         mylimb = "left hand";
      }else{
         mylimb = "right hand";
      }
      brief = "%^RESET%^%^ORANGE%^a "+WOOD+" %^ORANGE%^ring set with "+STONE+"";
      desc = "%^RESET%^This thick ring is made of a solid piece of "+WOOD+" "+
         "that has been carved until completely smooth.  The edges of the ring "+
         "do not taper, making it somewhat bulky.  A roughly cut "+STONE+" is "+
         "set into the top of the ring.";
   }
   if(TYPE == "earrings"){
      obj->set_id(({"jewelry","earrings","pair of earrings","earring"}));
      mylimb = "head";
      switch(random(2)){
         case 0:  brief = "%^RESET%^%^ORANGE%^a pair of "+WOOD+" %^ORANGE%^earrings%^RESET%^";
                  desc = "%^RESET%^This simple pair of earrings is made "+
                     "of "+WOOD+".  Each earring features three slender "+
                     ""+WOOD+" rods of increasing length.  The rods "+
                     "are carved in alternating bands, lending a "+
                     "geometric appearance to the earrings.";
                  break;
         default: brief = ""+STONE+" %^RESET%^%^ORANGE%^earrings%^RESET%^";
                  desc = "%^RESET%^The base for these earrings is carved "+
                     "from "+WOOD+".  The wooden earrings dangle about three "+
                     "inches, with the lowest point encrusted with several "+
                     "small pieces of "+STONE+".";
                  break;
      }
   }
   if(TYPE == "necklace"){
      obj->set_id(({"jewelry","necklace","hemp necklace","totem necklace"}));
      mylimb = "neck";
      brief = "%^RESET%^a hemp necklace with a carved "+WOOD+" "+TOTEM+"";
      desc = "%^RESET%^This necklace is made of a simple braided length of "+
         "hemp.  Hanging from a hemp thong in the front is a stylized "+
         ""+TOTEM+" carved from "+WOOD+".  Details of the "+TOTEM+" "+
         "have been carved and highlighted with fading paint.";
   }
   if(TYPE == "hair clip"){
      obj->set_id(({"jewelry","hairclip","clip","carved hair clip","hair clip"}));
      mylimb = "head";
      switch(random(2)){
         case 0:  brief = "a carved "+WOOD+" hair clip%^RESET%^";
                  desc = "This "+WOOD+" hair clip is made of a flat "+
                     "piece of wood carved with a single "+TOTEM+" "+
                     "in the center.  It is fitted with a long piece "+
                     "of hemp that is used to secure hair into the "+
                     "clip.";
                  break;
         default: brief = ""+STONE+"-beaded hair clip%^RESET%^";
                  desc = "Three thin disks of leather make up the base "+
                     "of this hair clip.  The surface of each has been "+
                     "decorated near the edge with a circle made of "+
                     "crushed "+STONE+".  A small hole on either end "+
                     "allows a thin stick of "+WOOD+" to be passed "+
                     "through, securing the hair.";
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
   obj->set_lore("Jewelry such as this is of uncertain origin.  Some claim it was "+
      "created by the ancient people known as the Tecqumin, a society which "+
      "has been obliterated.  Others say pieces like this one are created "+
      "by the yuan-ti who can now be found roaming through the jungles "+
      "once populated by the Tecqumin.  The truth is likely a mixture of "+
      "both, as the yuan-ti most likely continued the traditions of their "+
      "human ancestors.");
}
