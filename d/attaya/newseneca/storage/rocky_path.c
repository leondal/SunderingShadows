//rocky_path.c ~Circe~ 6/8/08
//Pathway from Seneca to the beach
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_climate("tropical");
   set_property("light", 2);
   set_name("A Rocky Pathway");
   set_short("A Rocky Pathway");
   set_long("%^RESET%^%^ORANGE%^A Rocky Pathway%^RESET%^\n"+
      "Carved from the %^ORANGE%^bedrock %^RESET%^that supports the "+
      "grand city of %^BOLD%^Seneca%^RESET%^, this footpath travels "+
      "from the city itself downward to the %^YELLOW%^g%^WHITE%^o"+
      "%^RESET%^l%^YELLOW%^d%^WHITE%^e%^RESET%^n %^YELLOW%^b%^WHITE%^"+
      "e%^RESET%^a%^YELLOW%^c%^WHITE%^h%^RESET%^ far below.  To "+
      "help with the slope, the path doubles upon itself, allowing "+
      "any who are upon it a great view of the rather ordinary "+
      "%^ORANGE%^brown bedrock %^RESET%^shot through with veins "+
      "of brilliant %^YELLOW%^golden rock%^RESET%^.  A slender, "+
      "yet sturdy %^ORANGE%^wooden handrail %^RESET%^lines the "+
      "path, providing added security.  Tall posts are set within "+
      "the handrail every few feet, each supporting an ornate "+
      "%^BOLD%^%^BLACK%^wrought iron lantern %^RESET%^with no "+
      "glass.  Dominating all other sights on the pathway is the "+
      "incredible view of the %^BOLD%^%^BLUE%^ocean %^RESET%^below, "+
      "the pounding waves creating %^BOLD%^white surf%^RESET%^ "+
      "as far as the eye can see.\n\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   set_listen("default","You can hear the crashing of "+
         "waves on the shore above the occasional cry of a seagull.");
   set_items(([
      ({"wall","walls"}) : "Just visible in different places from the "+
         "pathway, the %^BOLD%^co%^MAGENTA%^q%^WHITE%^ui"+
         "%^BLACK%^n%^WHITE%^a walls %^RESET%^of Seneca rise well over "+
         "twenty feet high and are eight feet wide.  Bastions are spread "+
         "along the wall at every one hundred or so feet.  These towers "+
         "are about ten feet taller than the rest of the wall and are "+
         "manned as look out points.  The top of the wall is crenellated, "+
         "allowing space for both archers to attack and defenders to deliver "+
         "nasty surprised to invaders.  The walls serve as a chilling reminder "+
         "that though the town of Seneca is prosperous, it is constantly "+
         "under threat from Intruder.",
      ({"lantern","lanterns","wrought iron lanterns","wrought iron lantern","iron lantern","iron lanterns"}) : 
         "Each lantern is tall and slender in design, tapering "+
         "from a wider, covered top to a more narrow base.  "+
         "The scrollwork sides help prevent the %^YELLOW%^flame "+
         "%^RESET%^within from being extinguished by the wind, while "+
         "the glassless design helps protect it from storms.",
      ({"beach","golden beach"}) : "The soft sand of the beach "+
         "below seems to glitter %^YELLOW%^golden %^RESET%^in any "+
         "light.  The beach itself is not very wide between the "+
         "crashing surf and the cliffs upon which this path is "+
         "carved, but there is definitely enough usable space "+
         "for people to enjoy.",
      ({"bedrock","brown bedrock"}) : "%^ORANGE%^The bedrock here "+
         "is dull brown in color, though upon closer inspection, "+
         "you can see various lighter and darker shades.  By far "+
         "the most eye-catching shade is the brilliant gold that "+
         "spiderwebs through the rock.%^RESET%^",
      ({"rock","golden rock","golden veins","veins"}) : "%^YELLOW%^"+
         "Slender veins of golden rock run through the rather "+
         "ordinary %^RESET%^%^ORANGE%^brown bedrock %^YELLOW%^that "+
         "supports the city of %^WHITE%^Seneca%^YELLOW%^.  The "+
         "rock appears to be golden quartz, which likely explains "+
         "its abundant presence on the beach and throughout the "+
         "city.%^RESET%^",
      ({"rail","handrail","wooden handrail","post","posts"}) : "%^ORANGE%^"+
         "The wooden handrail is weathered and well-used, but it "+
         "seems to stand up to the salt air rather well.  The "+
         "rail is simple in construction, made of two wooden "+
         "planks nailed to the taller vertical ones.  One plank "+
         "is set at about halfling height, while the other is "+
         "around five feet from the ground.  Tall posts are "+
         "placed every few feet, allowing a place for the "+
         "lanterns to hang.",
      ({"ocean","surf","white surf"}) : "The breathtaking ocean "+
         "%^BOLD%^%^BLUE%^s%^CYAN%^p%^BLUE%^a%^CYAN%^r%^BLUE%^k"+
         "%^CYAN%^l%^BLUE%^e%^CYAN%^s %^RESET%^%^CYAN%^green "+
         "%^RESET%^and %^BOLD%^%^BLUE%^blue %^RESET%^in the "+
         "light, while the crashing waves create %^BOLD%^white "+
         "surf %^RESET%^upon the shore."
   ]));
}

void reset(){
   ::reset();
   if(!present("beach lamp")) new(OBJ"beach_lamp")->move(TO);
}
