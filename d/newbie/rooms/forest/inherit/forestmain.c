//forestmain.c - main, center of forest
//took map out of switch now that newbies start with one.
//Circe 5/26/04
//fixed it so more bees or spiders won't come out if there are already some *Styx* 2/27/05
//added bard comps since it makes the most sense for them to be here ~Circe~ 5/9/11

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit ROOM;

int items;

void create() {
   items = 1;
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_short("%^GREEN%^Sparse forest%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(GAME_TRACK);
   set_long( (: TO,"ldesc" :) );
   set_smell("default","You smell pine needles and rotting leaves.");
   set_listen("default","You hear crickets and birds chirping.");
   set_items( ([ 
   	"pine trees":"The pine trees have a reddish brown flaky bark and tower over you.", 
    ({"undergrowth", "ivy"}):"%^GREEN%^A dark green ivy grows in patches and vines along dead limbs laying about.  Some patches are thick enough they might conceal small items lost by careless travellers.%^RESET%^", 
	({"trails", "trail"}):"%^ORANGE%^Trails meander around, probably made by animals but none seems more travelled than others.%^RESET%^",
	]) );
    set_search("default", "%^GREEN%^The ivy and undergrowth sure is thick isn't it?");
    set_search("ivy", (: TO, "search_pile" :) );
   set_search("undergrowth", (: TO, "search_pile" :) );
}

void search_pile() {
  object ob, mon;
  if(!items) {
     write("It looks like someone searched here recently.");
     return;
  }
//Summoned monsters were stopping searching, so added a check ~Circe~ 4/23/16
  if(present("bee", TO) && !present("bee",TO)->id("summoned monster")) {
     write("The bees are buzzing around too much to search.");
     return;
  }
  if(present("spider", TO)&& !present("spider",TO)->id("summoned monster")) {
     write("The spider is crawling all over the undergrowth.");
     return;
  }
//  if(random(5) < 3) {  making it all in the switch *Styx* 1/12/04, last change 11/29/02
  switch(random(18)) {
        case 0..1:
	  if(!present("bee", TO) && !present("spider", TO)) {
       	     write("On searching you find what looks like a trap door!\n"
		"%^YELLOW%^Suddenly, a giant spider jumps out from behind it at you!\n");
       	     tell_room(TO,"%^YELLOW%^"+TPQCN+" searches and finds what looks like "
		"a trap door, just as a giant spider jumps out from behind it!\n", TP);
 	     new(MONST"spidertd")->move(TO);
	  } else {
	    write("%^ORANGE%^You find an open hole like there had been a nest here.");
	    tell_room(TO,"%^ORANGE%^"+TPQCN+" finds a helmet-sized open hole that "
		"might have been a nest.", TP);
	  }
       	  break;
        case 2:
	  write("%^BOLD%^You find a dagger someone tossed aside or lost.\n");
	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a dagger someone tossed aside or lost.\n", TP);
	  new(WEAPONS"sdagger")->move(TO);
	  break;
        case 3:
	  ob = new("/std/obj/coins");
	  ob->set_money("gold", random(20)+2);
	  ob->set_money("silver", random(50)+10);
	  ob->set_money("copper", random(200)+50);
	  ob->move(TO);
	  write("%^BOLD%^You catch a glimpse of some coins but maybe your companions haven't noticed them yet.\n");
	  break;
	case 4:
	  new(MISC"gem")->move(TO);
	  write("%^BOLD%^You find a nice gem nearly buried under the leaves!  Maybe no one else noticed.");
	  break;
	case 5:
	  write("%^BOLD%^You find a scroll someone tossed aside or lost.\n");
	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a scroll someone tossed aside or lost.\n", TP);
  	  ob = new("/d/magic/scroll");
          ob->set_spell(2);
          ob->move(TO);
	  break;
	case 6:
      	  write("%^BOLD%^You've found a piece of paper.\n");
      	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a piece of paper.\n", TP);
      	  ob = new(STUFF"journal");
	  ob->move(TO);
       	  break;
        case 7..8:
	  if(!present("bee", TO) && !present("spider", TO)) {
	    tell_room(TO,"%^YELLOW%^A nest of angry bees swarms out of the ground!!");
	    call_out("bee_swarm", 1, TP);
	  } else {
	    write("%^ORANGE%^You find an open hole like there had been a nest here.");
	    tell_room(TO,"%^ORANGE%^"+TPQCN+" finds a helmet-sized open hole that "
		"might have been a nest.", TP);
	  }
	  break;
	case 9:
	  write("%^BOLD%^You find a scroll someone tossed aside or lost.\n");
	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a scroll someone tossed aside or lost.\n", TP);
  	  ob = new("/d/magic/safe_scroll");
          ob->set_spell(3);
          ob->move(TO);
	  break;
	case 10:
	  write("%^BOLD%^You find a few unbroken bottles filled with liquid.\n");
	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a few bottles.\n", TP);
  	  ob = new("/d/common/obj/potion/healing");
          ob->set_uses(random(3)+2);
          ob->move(TO);
	  break;
      case 11:
         write("%^BOLD%^You find a crumpled composition someone must've dropped.%^RESET%^\n");
         tell_room(TO,"%^BOLD%^"+TPQCN+" finds a crumpled piece of paper.%^RESET%^\n",TP);
         call_out("add_comp",0,TP);
         break;
      case 12..15:
      	  write("%^BOLD%^You've found a piece of paper.\n");
      	  tell_room(TO,"%^BOLD%^"+TPQCN+" finds a piece of paper.\n", TP);
      	  ob = new(STUFF"journal");
	  ob->move(TO);
       	  break;
      default: 
	  write("There's nothing much of interest in this particular patch of undergrowth.");
	  tell_room(TO, TPQCN+" doesn't seem to find anything in the undergrowth.", TP);
    }
    items = 0;
} 

void bee_swarm (){
   switch(random(4)){
 	case 0:
		new(MONST"beegk")->move(TO);
	case 1:
		new(MONST"beegk")->move(TO);
		new(MONST"beegk")->move(TO);
		break;
	case 2:
		new(MONST"beegk")->move(TO);
	  	new(MONST"beegk")->move(TO);
	case 3:
		new(MONST"beegk")->move(TO);
	  	new(MONST"beegk")->move(TO);
		new(MONST"beegk")->move(TO);
   }
}

void reset() {
   ::reset();
   if(random(8) < 3)
     items=1;
}

string ldesc(string str) {
   return("This area of the forest is somewhat sparse in vegetation.  "
     "%^CYAN%^Long-needled pine trees%^RESET%^ tower over scattered smaller "
     "evergreens and a few deciduous trees including oaks and sassafras.  Pine "
     "needles and fallen leaves cushion your steps but twigs interspersed with "
     "them frequently snap underfoot as you walk along.  The acidic soil from "
     "the decaying vegetable matter limits the %^GREEN%^undergrowth %^RESET%^to "
     "a few varieties of ivy and ferns.  Various trails cross here and there, "
     "although the area is clear enough you can travel nearly any direction.");
}

//Below added by ~Circe~ to allow bards to find comps
int add_comp(string str) {
   object obj;
   int num;
   switch(random(14)) {
      case 0..1:
         str = "trill";
         num = random(10)+5;
         break;
      case 2:
         str = "epithet";
         num = random(3)+1;
         break;
      case 3..4:
         str = "soliloquy";
         num = random(10)+6;
         break;
      case 5:
         str = "lullaby";
         num = random(7)+4;
         break;
      case 6..7:
         str = "limerick";
         num = random(10)+5;
         break;
      case 8:
         str = "dialogue";
         num = random(6)+2;
         break;
      case 9..10:
         str = "conceit";
         num = random(4)+3;
         break;
      case 11:
         str = "metaphor";
         num = random(2)+1;
         break;
      case 12:
         str = "elegy";
         num = random(10)+4;
         break;
      default:
         str = "whisper";
         num = random(10)+3;
         break;
    }
   obj = new("/d/magic/store_bard_comp.c");
   obj->set_name(str);
   obj->set_id(({""+str+"","component", "composition", "bard_component"}));
   obj->set_short(capitalize(str)+" (a bardic composition)");
   obj->set_long("     "+num+" "+str+""+ ""+obj->query_long());
   obj->set_comp_quantity(num);
   obj->move(ETP);
   return 1;
}
