//inn2.c - Restaurant area for Golden Perch Inn.  Circe 7/10/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Golden Perch Restaurant");
   set_short("Golden Perch Restaurant");
   set_long("%^ORANGE%^This large room is almost ornate in its "+
      "simplicity.  Unlike the common room, there is no central "+
      "fireplace here.  Instead, two large roaring %^RED%^fires "+
      "%^ORANGE%^are set within tall %^RESET%^stone arches %^ORANGE%^"+
      "in the northern wall on either side of the %^YELLOW%^doorway "+
      "%^RESET%^%^ORANGE%^that leads into the hall beyond.  Running "+
      "the length of the room is an enormous %^BOLD%^%^WHITE%^table "+
      "%^RESET%^%^ORANGE%^set low to the ground - well, for a firbolg, "+
      "at least.  There are no chairs or benches lined up next to "+
      "the table, and it seems most of the villagers simply sit upon "+
      "the %^GREEN%^rush-covered floor %^ORANGE%^with their legs "+
      "folded beneath the table.  However, some %^YELLOW%^benches "+
      "%^RESET%^%^ORANGE%^have been set along the southern wall "+
      "for those of smaller stature so they may eat comfortably.  "+
      "The eastern portion of the room is taken up by a long "+
      "wooden %^RED%^bar %^ORANGE%^covered with various soapstone and "+
      "wooden mugs, plates, bowls, and a few precious wooden spoons "+
      "and knives.  On the western wall is a large opening leading "+
      "back into the kitchen area, which consists of a large "+
      "%^RED%^hearth%^ORANGE%^, over which hang several %^BOLD%^"+
      "%^BLACK%^iron pots %^RESET%^%^ORANGE%^bubbling with stews, "+
      "along side roasting %^RESET%^fish %^ORANGE%^and other meats.  "+
      "It seems any food would be prepared there, then brought into "+
      "the center of the room for guests to enjoy.  A menu near "+
      "the kitchen tells you what dishes are served here.%^RESET%^\n");
   set_items(([
      ({"fires","arches","stone arches","northern wall"}) : "Precious "+
         "stone quarried from the mountainside has been used to "+
         "build two tall archways in the northern wall.  Each houses "+
         "a roaring fire to provide illumination and warmth at this "+
         "altitude.",
      ({"doorway","northern doorway"}) : "The doorway leading into "+
         "the hall is little more than a rectancular opening braced "+
         "by aged pine wood.  The hallway beyond looks quite wide "+
         "and has people coming and going over the rush-covered "+
         "floor almost constantly.",
      ({"table","center table","large table","enormous table"}) : "The "+
         "center of the floor is covered with a table rising about "+
         "six feet in the air, rather short for a firbolg.  It is "+
         "laden with baskets of bread, mugs, bowls, and spoons in "+
         "use, and a stunning display of fruit uncommon in these "+
         "higher reaches of the mountains.",
      ({"floor","rush-covered floor","rushes"}) : "%^GREEN%^The "+
         "rushes have been taken from the river and are swept up "+
         "each morning, with those who have outlived their purpose "+
         "being tossed out and the good ones returned.  The floor "+
         "here is made of stone, and the rushes help provide a "+
         "softer place for the firbolgs to sit while enjoying a "+
         "meal at the inn.",
      ({"benches","small benches"}) : "The benches along the wall "+
         "vary in height from three to four and a half feet and "+
         "may be pulled to the table so shorter folk may enjoy the "+
         "Lothwaite fare as well.",
      ({"bar","wooden bar"}) : "%^ORANGE%^The wooden bar at the eastern "+
         "end of the room is made of pine stained a deep chestnut shade.  "+
         "It has clearly seen much use but is kept well-maintained "+
         "and polished.  Behind the bar are many mugs, drinking "+
         "horns, and bottles of various liquids.",
      ({"mugs","plates","bowls","utensils","spoons","knives"}) : "On "+
         "every flat surface, there are small piles of bowls and plates "+
         "made from either wood or soapstone.  Matching mugs seem to "+
         "be a rarity but are found here as well.  Though utensils "+
         "seem to be scarce, there are a few wooden spoons to use "+
         "when enjoying a stew, and likewise a few knives when eating "+
         "meat.",
      ({"hearth","kitchen","kitchen area"}) : "The kitchen area to the "+
         "west has a stone floor much like this room, though it is "+
         "mostly taken up with a large hearth set into the floor.  Over "+
         "it hang various iron pots and spits roasting meat.  Several "+
         "firbolg women bustle about the kitchen, preparing and "+
         "delivering food to the hungry men of Lothwaite.",
      ({"pots","iron pots"}) : "%^BOLD%^%^BLACK%^A few iron pots "+
         "bubble with stew and a few unrecognizable concoctions on "+
         "the fire.  Most seem to be almost completely meat, though "+
         "a few beans and vegetables bubble up to the surface from "+
         "time to time.",
      ({"meats","spits"}) : " Balanced above the fire are a couple of "+
         "spits roasting what looks to be venison.  There is also "+
         "a large grate cooking salmon still in their skin with herbs "+
         "sprouting from their mouths and butter simmering on their "+
         "sides.",
      "menu" : "The menu is posted on a length of parchment near the "+
         "kitchen.  You could read it to see what's available."
   ]));
   set_smell("default","The smell of hearty foods lingers in the air.");
   set_listen("default","The deep, rumbling voices of the villagers fill the hall.");
   set_exits(([
      "south" : PATHEXIT"inn1",
      "north" : PATHEXIT"inn4"
   ]));
   set_door("pine door",PATHEXIT"inn1","south",0);
   set_door_description("pine door","This door is made from a large pine "+
      "plank sanded smooth.  In the center of the door is the carved "+
      "image of five %^YELLOW%^bees %^RESET%^flying in a diamond pattern.");
}

void init(){
   ::init();
   add_action("sit_em","sit");
   add_action("read", "read");
}

void reset() {
  ::reset();
    if(!present("bartender")){
      find_object_or_load(MON"madelyn")->move(TO);
    }
}


int sit_em(string str){
   if(!str){
      tell_object(TP,"Where would you like to sit?  You may try the "+
         "floor or a bench.");
      return 1;
   }
   if(str == "floor" || str == "on the floor" || str == "on floor"){
      if((int)TP->query_size() < 3){
         tell_object(TP,"You sit on the floor, and the table rises "+
            "several feet above your head.  Hmm...probably won't be "+
            "all that comfortable eating here.  You might want to try a "+
            "bench.  Ugh, firbolg feet.");
         tell_room(ETP,"Strangely, "+TPQCN+" sits underneath the table "+
            "among the firbolg feet.  The table is way over "+TP->QP+" "+
            "head!",TP);
         TP->force_me("pose sitting under the table among firbolg feet");
         return 1;
      }else{
         tell_object(TP,"You settle comfortably on the floor, crossing "+
            "your legs beneath the table as you prepare for a meal and "+
            "some good conversation.");
         tell_room(ETP,""+TPQCN+" settles onto the floor and takes "+
            ""+TP->QP+" place at the table.",TP);
         TP->force_me("pose sitting comfortably at the table");
         return 1;
      }
   }
   if(str == "bench" || str == "on bench" || str == "on a bench"){
      if((int)TP->query_size() < 2){
         tell_object(TP,"You drag one of the benches over to an "+
            "empty spot at the table before hopping up onto the "+
            "bench.");
         tell_room(ETP,""+TPQCN+" struggles a bit as "+TP->QS+" "+
            "pulls a bench over to the table, then hops up onto "+
            "the bench.",TP);
         TP->force_me("pose sitting atop a high bench");
         return 1;
      }
      if((int)TP->query_size() > 1 && (int)TP->query_size() < 3){
         tell_object(TP,"You move one of the tall benches over to "+
            "an empty place at the table and sit on it comfortably.");
         tell_room(ETP,""+TPQCN+" moves a bench to the table and "+
            "sits comfortably atop it.",TP);
         TP->force_me("pose sitting comfortably on a bench");
         return 1;
      }else{
         tell_object(TP,"That is much too small for you!  Try sitting "+
            "on the floor.");
         tell_room(ETP,""+TPQCN+" eyes one of the benches then seems "+
            "to think better of it.",TP);
         return 1;
      }
   }
   return 0;
}

int read(string str)
{
        object obj;
        if(!present("barkeep")) {
                write("The menu is smeared with the blood of the serving woman!");
                return 1;
        }
  	  obj = present("barkeep");
        if(str == "menu") {
                say(""+TPQCN+" reads over the menu.");
                message("Ninfo","The menu is on a length of parchment "+
                   "near the kitchen, and it lists these items:\n",TP);
                message("Ninfo","%^BOLD%^%^BLUE%^--------------------%^YELLOW%^{ %^WHITE%^Non-Alcoholic Drinks %^YELLOW%^}%^BLUE%^--------------------%^RESET%^\n",TP);
                message("Ninfo","\t%^CYAN%^Glass of Water%^RESET%^        \t\t"+
                " "+(int)obj->get_price("water")+" silver pieces\n",TP);
                message("Ninfo","\t%^%^BOLD%^%^MAGENTA%^Berry Breeze%^RESET%^        \t\t"+
                " "+(int)obj->get_price("berry breeze")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^BLACK%^Honey Chocolate%^RESET%^        \t\t"+
                " "+(int)obj->get_price("honey chocolate")+" silver pieces\n",TP);
                message("Ninfo","\t%^YELLOW%^Honey Lemonade%^RESET%^        \t\t"+
                " "+(int)obj->get_price("honey lemonade")+" silver pieces\n",TP);
                message("Ninfo","%^BOLD%^%^BLUE%^----------------------%^YELLOW%^{ %^WHITE%^Alcoholic Drinks %^YELLOW%^}%^BLUE%^----------------------%^RESET%^\n",TP);
                message("Ninfo","\t%^ORANGE%^Mead%^RESET%^        \t\t\t"+
                " "+(int)obj->get_price("mead")+" silver pieces\n",TP);
                message("Ninfo","\t%^YELLOW%^Honey Ale%^RESET%^        \t\t"+
                " "+(int)obj->get_price("honey ale")+" silver pieces\n",TP);
                message("Ninfo","\t%^ORANGE%^Lothwaite Lager%^RESET%^        \t\t"+
                " "+(int)obj->get_price("lothwaite lager")+" silver pieces\n",TP);
                message("Ninfo","\t%^RED%^Mulled Cider%^RESET%^        \t\t"+
                " "+(int)obj->get_price("mulled cider")+" silver pieces\n",TP);
                message("Ninfo","\t%^ORANGE%^Hot Toddy%^RESET%^        \t\t"+
                " "+(int)obj->get_price("hot toddy")+" silver pieces\n",TP);
                message("Ninfo","\t%^YELLOW%^Dandelion Wine%^RESET%^        \t\t"+
                " "+(int)obj->get_price("dandelion wine")+" silver pieces\n",TP);
                message("Ninfo","%^BOLD%^%^BLUE%^----------------------------%^YELLOW%^{ %^WHITE%^Shots %^YELLOW%^}%^BLUE%^---------------------------%^RESET%^\n",TP);
                message("Ninfo","\t%^BOLD%^Whiskey%^RESET%^        \t\t\t"+
                " "+(int)obj->get_price("whiskey")+" silver pieces\n",TP);
                message("Ninfo","\t%^ORANGE%^Brandy%^RESET%^        \t\t\t"+
                " "+(int)obj->get_price("brandy")+" silver pieces\n",TP);
                message("Ninfo","\t%^YELLOW%^Rum%^RESET%^        \t\t\t"+
                " "+(int)obj->get_price("rum")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^Gin%^RESET%^        \t\t\t"+
                " "+(int)obj->get_price("gin")+" silver pieces\n",TP);
                message("Ninfo","%^BOLD%^%^BLUE%^----------------------------%^YELLOW%^{ %^WHITE%^Food %^YELLOW%^}%^BLUE%^----------------------------%^RESET%^\n",TP);
                message("Ninfo","\t%^GREEN%^Cabbage Soup%^RESET%^        \t\t"+
                " "+(int)obj->get_price("cabbage soup")+" silver pieces\n",TP);
                message("Ninfo","\t%^ORANGE%^Deer Stew%^RESET%^        \t\t"+
                " "+(int)obj->get_price("deer stew")+" silver pieces\n",TP);
                message("Ninfo","\t%^RED%^Roasted Venison%^RESET%^        \t\t"+
                " "+(int)obj->get_price("roasted venison")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^Bread%^RESET%^        \t\t\t"+
                " "+(int)obj->get_price("bread")+" silver pieces\n",TP);
                message("Ninfo","\t%^MAGENTA%^Cottage Cheese and Fruit%^RESET%^        "+
                " "+(int)obj->get_price("cottage cheese and fruit")+" silver pieces\n",TP);
                message("Ninfo","\t%^RED%^Salted Bacon%^RESET%^        \t\t"+
                " "+(int)obj->get_price("salted bacon")+" silver pieces\n",TP);
                message("Ninfo","\t%^ORANGE%^Nuts and Berries%^RESET%^        \t"+
                " "+(int)obj->get_price("nuts and berries")+" silver pieces\n",TP);
                message("Ninfo","\t%^YELLOW%^Honeyed Fruit%^RESET%^        \t\t"+
                " "+(int)obj->get_price("honeyed fruit")+" silver pieces\n",TP);
                message("Ninfo","\t%^RED%^Lamb Kebabs%^RESET%^        \t\t"+
                " "+(int)obj->get_price("lamb kebabs")+" silver pieces\n",TP);
                message("Ninfo","\t%^BOLD%^%^MAGENTA%^Roasted Salmon%^RESET%^        \t\t"+
                " "+(int)obj->get_price("roasted salmon")+" silver pieces\n",TP);
                message("Ninfo","%^BOLD%^%^BLUE%^--------------------------%^YELLOW%^{ %^WHITE%^Desserts %^YELLOW%^}%^BLUE%^--------------------------%^RESET%^\n",TP);
                message("Ninfo","\t%^ORANGE%^Honeycake%^RESET%^        \t\t"+
                " "+(int)obj->get_price("honeycake")+" silver pieces\n",TP);
                message("Ninfo","\t%^MAGENTA%^Fruit Parfait%^RESET%^        \t\t"+
                " "+(int)obj->get_price("fruit parfait")+" silver pieces\n",TP);
                message("Ninfo","\t%^YELLOW%^Pear Delight%^RESET%^        \t\t"+
                " "+(int)obj->get_price("pear delight")+" silver pieces\n",TP);
                message("Ninfo","%^BOLD%^BLUE%^----------------------------------------------------------------\n",TP);
                message("Ninfo","<buy item_name> gets you the food or drink.\n",TP);
        return 1;
        }
}
