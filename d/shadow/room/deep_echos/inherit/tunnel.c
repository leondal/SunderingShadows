//tunnel.c inheritable first room in lower echo mnts
#include <std.h>
#include "../deep_echo.h"
inherit CVAULT;
int items = 1; //has items

void pick_critters();

void create(){
    pick_critters();
    set_repop(35);
    ::create();
    set_indoors(1);
	//set_property("no sticks",1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",-1);
    set_name("Deep Echoes Mountains");
    set_short("Deep Echoes Mountains");
    switch(random(3)){
	 case 0 : set_long("%^RED%^Below Echoes Mountains%^RESET%^\n"+
      "%^BOLD%^%^BLACK%^This dark and cool cave is deep in the earth.  "+
      "Nothing ever was built here unlike the echoes above.  "+
      "If any dwarves made it down here there is no trace left.  "+
      "The %^WHITE%^walls%^BLACK%^ are wet and"+
      " jagged, likely hollowed out by lava "+
      "ages ago and forming this cave. "+
      "Crumbled rocks from the %^WHITE%^ceiling%^BLACK%^"+
	  " form a uneven surface to walk on. "+
      "\n");
	   set_items(([
      (({"cavern","caverns","tunnel","cave"})) : "These tunnels "+
         "have either smooth or caved in %^BOLD%^ceilings%^RESET%^ "+
         "and %^BOLD%^walls%^RESET%^. "+
         " They were not created by anything but natural events "+
         "if this is home to anything, it is not civilized.  "+
         "The floors are full of jagged rocks.  "+
         "They are nothing like the dwarven work above. "+
         "\n",
 
      (({"wall","walls","ceiling"})) : "The walls are wet and "+
         "smooth from moisture "+
         "they are cold to the touch. "+
         "Although, several parts of the walls have been broken leaving "+
         "jagged outcropping.",]));
		 break;
     case 1 : 
	   set_long(
        "%^RED%^Below Echoes Mountains%^RESET%^\n"+
        "%^BOLD%^%^BLACK%^"+
		"This area is filled with %^CYAN%^cold water.%^BLACK%^  "+
        "One has to tred carefully to avoid getting their feet wet.  "+
        "If any dwarves made it down here there is no trace left.  "+
        "The %^WHITE%^walls%^BLACK%^ are wet and"+
        " jagged, likely hollowed out by lava "+
        "ages ago and forming this cave. "+
        "Crumbled rocks from the %^WHITE%^ceiling%^BLACK%^"+
		" form a uneven surface to walk "+
        "on. "+
        "\n");
	  set_items(([
	  (({"water","cold water",})) : "The water fills the "+
		 "uneven ground below",
      (({"cavern","caverns","tunnel","cave"})) : "These tunnels "+
         "have either smooth or caved in %^BOLD%^ceilings%^RESET%^ "+
         "and %^BOLD%^walls%^RESET%^.  "+
         "They were not created by anything but natural events.  "+
         "If this is home to anything, it is not civilized.  "+
         "The floors are full of jagged rocks.  "+
         "They are nothing like the dwarven work above. "+
         "\n",
	  (({"water","cold water"})) : "There is a puddle of water here.",
      (({"wall","walls","ceiling"})) : "The walls are wet and "+
         "smooth from moisture.  "+
         "They are cold to the touch.  "+
         "Several parts of the walls have been broken leaving "+
         "jagged outcropping.", ]));
		 set_search("default","Where do you want to search?");
         set_search("water",(:TO,"search_water":));   
      break;
	  case 2:
	    set_long("%^RED%^Below Echoes Mountains%^RESET%^\n"+
		 "%^BOLD%^%^BLACK%^This dark and cool cave is deep in the earth.  "+
         "Nothing ever was built here unlike the echoes above.  "+
         "If any dwarves made it down here there is no trace left. "+
         "The %^WHITE%^walls%^BLACK%^ are wet and"+
         " jagged, likely hollowed out by lava "+
         "ages ago and forming this cave.  "+
         "Crumbled rocks from the %^WHITE%^ceiling%^BLACK%^"+
	     " form a uneven surface to walk on. "+
		"%^RESET%^A pile of bones rests on the ground.");
	  set_items(([
	  (({"pile","bones",})) : "Someone met their end "+
		 "here.  The roaches have eaten down to the bone.",
      (({"cavern","caverns","tunnel","cave"})) : "These tunnels "+
         "have either smooth or caved in %^BOLD%^ceilings%^RESET%^ "+
         "and %^BOLD%^walls%^RESET%^.  "+
         "They were not created by anything but natural events.  "+
         "If this is home to anything, it is not civilized.  "+
         "The floors are full of jagged rocks, "+
         "nothing like the dwarven work above. "+
         "\n",
	  (({"water","cold water"})) : "There is a puddle of water here.",
      (({"wall","walls","ceiling"})) : "The walls are wet and "+
         "smooth from moisture.  "+
         "They are cold to the touch. "+
         "Several parts of the walls have been broken leaving "+
         "jagged outcropping.", ]));
		 set_search("default","Where do you want to search?");
         set_search("bones",(:TO,"search_bones":)); 
		
	  }
     set_listen("default","It is too quiet.");
     set_smell("default","The air here is stale.");
     

}

void reset(){
   ::reset();
   items = 1;
   switch(random(5)){
      case 0:  tell_room(TO,"%^CYAN%^A wisp of wind passes by.");
               break;
      case 1:  tell_room(TO,"%^GREEN%^You suddenly hear a clicking  "+
                  "noise nearby.");
               break;
      case 2:  tell_room(TO,"A loud %^RED%^--CLUNK--%^RESET%^"+
                  " sounds as "+
                  "another piece of stone falls to the ground.");
               break;
      case 3:  tell_room(TO,"%^BOLD%^%^BLACK%^The stale "+
                  "air makes your stomach "+
                  "turn.");
               break;
      case 4:  tell_room(TO,"Several %^RED%^bats%^RESET%^ fly "+
                  "through the cave past you, "+
                  "then out of sight.");
               break;
   }
}
int search_bones(string str){
     object ob;
     if (!items) {
     tell_object(TP,"It seems like someone has"+
      " searched around here already.");
      return 1;}
   switch(random(5)){
   case 0:
      ob = new("/d/common/obj/potion/extra_heal");
      ob->set_uses(random(5)+1);
      ob->move(ETP);
      tell_object(TP,"There are some vials burried in bones");
      tell_room(ETP,""+TP->QCN+" finds something in the bones.",TP);
      break;
   case 1:
      ob = new("/std/obj/coins");
      ob->set_money("platinum",random(12)*random(13));
      ob->set_money("electrum",random(12)*7);
      ob->move(ETP);
      tell_object(TP,"You find a few coins under the bones.");
      tell_room(ETP,""+TP->QCN+
	    " pulls out something from the bones.",TP);
      break;
  case 2:
     tell_object(TP,"Your hand comes back covered in insect excrement.");
     tell_room(ETP,""+TP->QCN+
	  " sticks a hand in the bones and looks grossed out.",TP);
	 break;
  case 3..4: 
      tell_object(TP,"You search through the bones and find something.");
      tell_room(ETP,""+TPQCN+" searches the bones and finds something!",TP);
      "/d/common/daemon/randtreasure_d"->find_stuff(TO,"magic");
      break;
  }	
   items=0;
   return 1;
}
int search_water(string str){
     object obj;
     if (!items) {
     tell_object(TP,"It seems like someone has"+
      " searched around here already.");
      return 1;}
     obj = new("/d/antioch/valley/obj/gem");
     obj->move(TO);
     tell_object(TP,"%^CYAN%^Fortune smiles upon you "+
      "and you find a gem.");
     items=0;
      return 1;
}
void pick_critters(){
      switch(random(11)) {     
        case 0:  break;
        case 1:  set_monsters( ({MOBS"blinkroach"}),({random(5)+1}));
				 break;
		case 2:  set_monsters( ({MOBS"deep_ogre"}),({random(5)+1}));
                 break;
        case 3:  set_monsters( ({MOBS"moldman", MOBS"blinkroach"}),({1,random(3)}));
                 break;
        case 4:  set_monsters( ({MOBS"displacer",MOBS"displacer"}),({1,random(2)}));
                 break;
        case 5:  set_monsters( ({MOBS"umberhulk",MOBS"umberhulk"}),({1,random(2)}));
                 break;
		case 6:  set_monsters( ({MOBS"deep_ogre",MOBS"ogre_mage"}),({random(4)+1,1}));
                 break;
		case 7..10: break;  //added to cut down on hack fest
      }
}
