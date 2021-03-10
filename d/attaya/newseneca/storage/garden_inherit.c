//inherit for the cathedral gardens in new Seneca
//~Circe~ 1/12/08
#include <std.h>
#include "../seneca.h"

inherit VAULT;
int count;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_climate("tropical");
   set_property("indoors",0);
   set_property("light",3);
   set_name("Cathedral Gardens, Seneca");
   set_short("Cathedral Gardens, Seneca");
   set_long("%^BOLD%^Cathedral Gardens, Seneca%^RESET%^\n"+
      "%^RESET%^%^GREEN%^This lush wonderland of beautiful %^BOLD%^"+
      "flowers %^RESET%^%^GREEN%^is a world apart from the city "+
      "of %^BOLD%^%^WHITE%^Seneca%^RESET%^%^GREEN%^ despite being "+
      "surrounded by it.  Banks of blossoming bougainvillea in "+
      "shades of brilliant %^BOLD%^%^MAGENTA%^pi%^WHITE%^n%^MAGENTA%^k"+
      "%^RESET%^%^GREEN%^, %^BOLD%^%^RED%^scarlet%^RESET%^"+
      "%^GREEN%^, and %^ORANGE%^ora%^YELLOW%^n%^RESET%^%^ORANGE%^ge"+
      "%^RESET%^%^GREEN%^ climb fences and fill "+
      "the air with their colorful petals.  Burgeoning %^BOLD%^"+
      "%^MAGENTA%^o%^YELLOW%^l%^WHITE%^e%^MAGENTA%^a%^YELLOW%^n"+
      "%^WHITE%^d%^MAGENTA%^e%^YELLOW%^r %^WHITE%^t%^MAGENTA%^r"+
      "%^YELLOW%^e%^WHITE%^e%^MAGENTA%^s %^RESET%^%^GREEN%^are spread throughout "+
      "the gardens, adding their sweet fragrance to the area.  "+
      "Much of the ground is left clear of flowers, giving plenty "+
      "of room for the soft %^BOLD%^grass %^RESET%^%^GREEN%^to "+
      "grow.  Sprinkled around the gardens are small "+
      "%^RESET%^stone statues %^GREEN%^and %^RESET%^bird baths "+
      "%^GREEN%^on narrow pedestals, encouraging %^CYAN%^c"+
      "%^BOLD%^%^RED%^o%^BLUE%^l%^YELLOW%^o%^GREEN%^r%^CYAN%^f"+
      "%^WHITE%^u%^RED%^l %^RESET%^%^GREEN%^birds to perch and "+
      "trill their playful songs.  Here and there a %^RESET%^"+
      "stone bench %^GREEN%^stands ready for visitors to "+
      "relax and enjoy the serene surroundings.  Visible just "+
      "through the foliage is the top of a %^ORANGE%^"+
      "gazebo%^RESET%^%^GREEN%^ centered in the northern part "+
      "of the gardens.%^RESET%^\n");
   set_smell("default","The bountiful aroma of flowers masks the "+
      "clean scent of the ocean.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"bougainvillea","pink bougainvillea","scarlet bougainvillea","orange bougainvillea"}) :
         "%^ORANGE%^These thorny, woody vines grow throughout the "+
         "%^GREEN%^gardens%^ORANGE%^, climbing up the bordering "+
         "%^BOLD%^%^BLACK%^fences %^RESET%^%^ORANGE%^and piling "+
         "into corners.  Sometimes called paper flowers, the "+
         "bracts are thin and brilliantly colored in shades "+
         "of %^BOLD%^%^MAGENTA%^pi%^WHITE%^n%^MAGENTA%^k"+
         "%^RESET%^%^ORANGE%^, %^BOLD%^%^RED%^scarlet%^RESET%^"+
         "%^ORANGE%^, and ora%^YELLOW%^n%^RESET%^%^ORANGE%^ge.%^RESET%^",
      ({"fence","fences"}) : "%^BOLD%^%^BLACK%^The gardens are "+
         "bounded around the outer edges by a picket fence.  "+
         "The iron picket fence has fleur-de-lis caps "+
         "and is set with %^RESET%^stone columns %^BOLD%^"+
         "%^BLACK%^at intervals, adding a decorative touch.%^RESET%^",
      ({"petal","petals"}) : "Dancing gracefully upon the wind "+
         "are countless petals from the %^ORANGE%^c%^BOLD%^o"+
         "%^RED%^l%^MAGENTA%^o%^YELLOW%^r%^RESET%^%^MAGENTA%^f"+
         "%^BOLD%^u%^RESET%^%^ORANGE%^l %^RESET%^bougainvillea "+
         "vines growing here.  You might be able to %^YELLOW%^"+
         "<%^WHITE%^collect%^YELLOW%^> %^RESET%^some of the "+
         "petals if you'd like.",
      ({"oleander","oleander trees","trees"}) : "%^GREEN%^Each "+
         "oleander tree has a slender trunk with widely spreading "+
         "branches bursting with clusters of flowers.  The "+
         "blossoms vary in hue from tree to tree - %^YELLOW%^"+
         "yellow %^RESET%^%^GREEN%^here, vibrant %^BOLD%^"+
         "%^MAGENTA%^fuscia %^RESET%^%^GREEN%^there, even "+
         "blinding %^BOLD%^%^WHITE%^white %^RESET%^%^GREEN%^in "+
         "places.  Each flower is beautiful - five petals arranged "+
         "around a fringed center that gives off a sweet "+
         "fragrance.%^RESET%^",
      ({"ground","grass","soft grass"}) : "%^BOLD%^%^GREEN%^"+
         "The grass here is soft and well-"+
         "groomed, quite unlike most of the beach grass growing "+
         "thoughout Seneca.  It is kept relatively short, and it "+
         "would likely be a great place for a picnic.%^RESET%^",
      ({"statue","statues","stone statues"}) : "Each of the "+
         "stone statues seems to be of an angel with wide-spread "+
         "wings or a young innocent with eyes cast to the sky.  "+
         "They are all small, around three feet tall, and they "+
         "provide a simple ornamentation to the beautiful gardens.",
      ({"bird bath","bird baths"}) : "The bird baths are round "+
         "dishes placed upon stone pedestals about four feet "+
         "in height.  Each is filled with water, and some have "+
         "developed a faintly green outline of algae.",
      ({"bird","birds","colorful birds"}) : "Birds of different "+
         "types visit the gardens, filling the air with their "+
         "soft trills and melodies.",
      "gazebo" : "%^ORANGE%^Peeking over the tops of the "+
         "oleander trees is the domed roof of a picturesque "+
         "gazebo.%^RESET%^"
   ]));
   if(random(4)) count = 1;
}

void reset(){
   ::reset();
   if(!random(3)) count = 1;
}

void init(){
   ::init();
   add_action("collect_em","collect");
}

int collect_em(string str){
   if(!str){
      tell_object(TP,"You might try to <collect petals>.");
      return 1;
   }
   if(str == "petals" || str == "bougainvillea petals" || str == "flower petals"){
      if(!count){
         tell_object(TP,"The flower petals here are too scattered "+
            "collect!");
         return 1;
      }
      tell_object(TP,"%^GREEN%^You carefully scoop together a handful "+
         "of the fallen petals.%^RESET%^");
      tell_room(TO,"%^GREEN%^"+TPQCN+" carefully scoops together a "+
         "handful of fallen bougainvillea petals.%^RESET%^",TP);
      new(OBJ"petals")->move(TO);
      count--;
      return 1;
   }
   return 0;
}
