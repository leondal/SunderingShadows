//updated by Circe 6/7/04 with new lore from Shar
#include <std.h>

#define SHAPES ({\
"antelope","eagle","osprey","unicorn","owl","oriole","otter","owlbear",\
"frog","squirrel","dog","rabbit","cat","hawk","falcon","raven",\
"wolf","wolverine","lion","panther","puma","leopard","rose","cheetah",\
"horse","dragon","spider","fish","shark","turtle","snake","coyote",\
"doe","stag","dolphin","whale","sphinx","tiger","lizard","cougar",\
"bobcat","lynx","pegasus","manticore","hydra","griffon","pony","dragonfly",\
"bear","basilisk","cockatrice","robin","blue jay","sparrow","pheasant","fox",\
"thrush","badger","weasel","nightingale","ferret","skunk","raccoon","jaguar",\
"hyena","salamander","iguana","chameleon","gecko","scorpion","moose","swan",\
"vulture","condor","crow","smilodon","gopher","mole","centaur","chimera",\
"dragonne","gargoyle","mermaid","hippogriff","imp","kirre","lamia","beaver",\
"wemic","lammasu","jackal","boar","chipmunk","butterfly","mink","mouse",\
"muskrat","woodchuck","minotaur","peryton","phoenix","roc","satyr","selkie",\
"shedu","sprite","fairy","worg","dire wolf","winter wolf","wyvern","pelican",\
"duck","bat","gopher","hedgehog","sheep","goat","goose","donkey",\
"chicken","leprechaun","alligator","crocodile","bull",\
"peacock","finch","grass hopper","praying mantis","armadillo",\
"porcupine","tree","crescent moon"\
})

//STONES == wooden, soapstone, tigers eye, crystal, marble, ebony, ivory, jade

inherit DAEMON;

int j, val;
string str, STONE, VAR;

void create_statue(object obj)
{
   j = random(sizeof(SHAPES));
   str = SHAPES[j];
   VAR = "a";
   if(str == "antelope" || str == "eagle" || str == "osprey" || str == "owl" || str == "oriole" || str == "otter" || str == "owlbear") {
      VAR = "an";
   }
   val = random(350);
   switch(val) {
      case 0..20:
         STONE = "wooden";
         obj->set_long("%^ORANGE%^This is a beautifully carved wooden statue of "+VAR+""+
         " "+str+". The wood grain has been highly polished and treated to"+
         " bring out the grain of the wood, and the detail is superb.");
         break;
      case 21..40:
         STONE = "soapstone";
         obj->set_long("The soapstone has been carefully carved into the"+
         " image of "+VAR+" "+str+". Soapstone is a softer material and"+
         " sometimes hard to work with, but this "+str+" is perfect in detail.");
         break;
      case 41..60:
         STONE = "tigers eye";
         obj->set_long("%^ORANGE%^The statue was carved from a solid piece of tigers"+
         " eye into the shape of "+VAR+" "+str+". The tigers eye itself is"+
         " quite pretty and the crafter took full advantage of the natural"+
         " swirls and coloration of the stone to help enhance the details"+
         " of the "+str+".");
         break;
      case 61..100:
         STONE = "marble";
         obj->set_long("%^WHITE%^%^BOLD%^This white marble has been worked into the image of"+
         " "+VAR+" "+str+". The marble has been polished and the "+str+" is"+
         " depicted in perfect detail.");
         break;
      case 101..150:
         STONE = "crystal";
         obj->set_long("The statue has been carved from a piece of solid"+
         " quartz crystal into the image of "+VAR+" "+str+". There isn't one"+
         " chip or crack in the crystal, and the "+str+" is complete to the"+
         " smallest of details. Light refractures inside the crystal, giving"+
         " the "+str+" some semblance of life.");
         break;
      case 151..225:
         STONE = "ebony";
         obj->set_long("%^BOLD%^%^BLACK%^The ebony is dark and depthless and can normally"+
         " be a very hard wood to work with, but this statue has been"+
         " shaped into the shape of "+VAR+" "+str+" quite easily it seems."+
         " The craftsmanship is flawless and every detail has been captured.");
         break;
      case 226..275:
         STONE = "ivory";
         obj->set_long("%^BOLD%^%^WHITE%^This gorgeous statue is carved from a piece of ivory"+
         " into the image of "+VAR+" "+str+". It is excellent work and the"+
         " statue is truly life-like.");
         break;
      case 276..350:
         STONE = "jade";
         obj->set_long("%^BOLD%^%^GREEN%^The craftsmanship of this jade statue is simply"+
         " exquisite. The details of the "+str+" are flawless and ever so"+
         " precise. The "+str+" almost seems to glow from within, it's"+
         " breath taking.");
         break;
   }
   obj->set_name("statue");
   obj->set_weight(5);
   obj->set_value(val);
   if(val < 10) {
      obj->set_value(10);
   }
   obj->set_id(({"statue",""+str+" statue",""+str+" "+STONE+" statue",""+STONE+" statue",""+STONE+" "+str+" statue",""+str+"",""+STONE+" "+str+""}));
   obj->set_lore("Meriago is one of the most famous sculptures in "+
      "these lands.  His creations of wood or stone have come to be "+
      "highly praised by many noble folks and religious leaders "+
      "throughout the lands.  This little Halfling has found his "+
      "sudden fame a shock and slightly uncomfortable.  For all he "+
      "wanted to do, as hes been quoted, was just to listen to what "+
      "the material wanted to be.");
   obj->set_property("lore difficulty",6);
   obj->set_short("A "+STONE+" statue of "+VAR+" "+str+"");
   if(STONE == "ivory" || STONE == "ebony") {
     obj->set_short("An "+STONE+" statue of "+VAR+" "+str+"");
   }
}
