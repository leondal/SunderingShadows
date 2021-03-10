//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

int DRAWER;

void create(){
	::create();
	set_name("high priest's room");
   set_short("high priest's room");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"The %^YELLOW%^low glimmer %^BOLD%^%^BLACK%^of a few "+
   	"discretely placed candles is all the illumination "+
   	"available in this spacious and elegantly appointed room.  "+
   	"The %^RESET%^%^RED%^thick carpet %^BOLD%^%^BLACK%^is "+
            "patterned in hues of %^RESET%^%^RED%^deep burgundy "+
   	"%^BOLD%^%^BLACK%^and the walls are dark.  In one corner "+
   	"there is a writing desk, in another a couple of comfortable "+
   	"looking armchairs.  A four-poster bed sits off to one side "+
   	"with a dresser and wardrobe beside it.  In the center of "+
   	"the room there is a plinth bearing an "+
   	"%^RESET%^%^WHITE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^WHITE%^y%^BOLD%^%^BLACK%^x "+
   	"statue of %^RED%^Loviatar%^BOLD%^%^BLACK%^."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","%^RED%^There is a hint of incense in the "+
   	"air, sweet, but not cloying.%^RESET%^");
   set_listen("default","%^RED%^You can clearly hear sounds of "+
   	"activity from below.%^RESET%^");
   set_items(([
   	({"armchairs","armchair","chairs","chair"}) : "The chairs look "+
   		"comfortable and well padded.\n",
   	"bed" : "The bed is large and looks luxurious.  The gleaming "+
   		"brass posts support elegant muslin drapes, hung in sweeping "+
   		"curves.  The coverlet is black and the pillows bone white.\n",
   	({"posts","post","bed posts","bed post"}) : "The brass posts, "+
   		"and the frame they support, are all polished to a high "+
   		"shine, but you notice a few areas where the shine is not "+
   		"so great.  Looking more closely you can see there are "+
   		"scratch marks on the frame at each of the four corners "+
   		"of the bed as if, perhaps, chains had been attached at "+
   		"one time or another.\n",
   	"desk" : "The desk is clean and starkly uncluttered.  The "+
   		"few papers, neatly arranged, seem to deal, mainly, "+
   		"with administrative correspondence.  You, also, notice "+
   		"a few scraps of unfinished sermons.\n",
   	"dresser" : "This is a plain, four-drawer, dressing table "+
   		"with a silver framed mirror.\n",
   	({"drawer","drawers"}) : "Most of the drawers are filled with "+
   		"the general clutter of combs, hair-pins, and dozens of "+
   		"other things a high priest might use to keep up her "+
   		"appearance.  You do notice that some of the hair-pins "+
   		"are somewhat sharper than you would normally expect.  "+
   		"The fourth drawer is stuck shut.\n",
   	"fourth drawer" : "The drawer is closed.\n",
   	"carpet" : "The luxuriantly thick carpet bears a complex "+
   		"pattern of subtly varying shades of deep red and burgundy.  "+
   		"This color would seem to be well suited for not showing "+
   		"stains, especially red ones.\n",
   	"wardrobe" : "This is a plain mahogany wardrobe.\n",
   	({"statue","onyx statue","statue of loviatar"}) : "Standing about "+
   		"eighteen inches high on the plinth, the statue has been "+
   		"finely sculpted in the highest quality marble.  Loviatar "+
   		"is portrayed as a truly beautiful woman.  Her revealing "+
   		"garb clings to a figure seemingly designed with sexual "+
   		"allure in mind.  Her face is finely cast, but her "+
   		"expression is one of awful, eternal cruelty and pain.  "+
   		"Her eyes are marked out in glittering black onyx and in "+
   		"her hand she carries a nine tailed whip.  The whip hangs "+
   		"loosely by her side, but the tails seem to twine around "+
   		"her thigh and calf, embracing her like a serpent and "+
   		"bringing to mind the same combination of sensuality and threat.\n"
  	]));
   set_exits(([
		"south" : GAB+"hall1"
	]));
	set_search("fourth drawer","This drawer is stuck, but you cannot "+
		"discern the reason why.  Perhaps the only way to open it would seem "+
		"to be to force the drawer and hope your strong enough to open it.\n");

  	set_door("walnut door",GAB+"hall1","south","loviatar_holy_symbol");
   set_door_description("walnut door","The door is made of stout black walnut "+
   	"and is banded in iron.\n");
   set_string("walnut door","open","The door opens into a hall.\n");

   DRAWER = 0;

	set_trap_functions(({"fourth drawer"}),({"prick_em"}),({"force"}));
}
void init() {
  	::init();
  	add_action("sit_em","sit");
  	add_action("push_em","push");
}
int sit_em(string str) {
  	if(!str) {
   	tell_object(TP,"Sit where?");
      return 1;
   }
  	if(str == "chair" || str == "armchair" || str == "on chair" || str == "on armchair"){
   	tell_object(TP,"%^BOLD%^You recline easily into the comfortable chair.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" reclines with ease in an armchair.\n%^RESET%^",TP);
		return 1;
	}
}
int push_em(string str) {
  	if(!str) {
        	tell_object(TP,"Push what?");
        	return 1;
    	}

  	if(str == "fourth drawer"){
   	if(DRAWER == 1){
       	DRAWER = 0;
  			tell_object(TP,"%^BOLD%^You push the fourth drawer "+
   			"closed till it clicks.%^RESET%^\n");
   		tell_room(TO,"%^BOLD%^"+TPQCN+" pushes the fourth "+
   			"drawer closed.%^RESET%^\n");
   		add_item("fourth drawer","The drawer is closed.");
      	return 1;
   	}
		DRAWER = 1;
		tell_room(TO,""+TPQCN+" opens the fourth drawer.\n",TP);
		tell_object(TP,"You push the fourth drawer inward and it pops open for you.\n");
		add_item("fourth drawer","All that work and the dang thing is empty.\n");
    	return 1;
	}
	tell_object(TP,"%^BOLD%^You pushed the "+str+".  Feel "+
		"better pushing around the poor "+str+"?%^RESET%^\n");
	return 1;
}
int prick_em(string str){
	int poison;
   if(!interactive(TP)) return 1;
	if(str == "fourth drawer"){
		toggle_trap("fourth drawer");
		tell_object(TP,"%^BOLD%^%^GREEN%^As you pull hard to force the fourth drawer "+
			"open a pair of small needles shoot out from the desk and sink "+
			"into your forearm.  You feel the fire of an unknown poison "+
			"racing through your veins!%^RESET%^\n");
		tell_object(TP,"%^BOLD%^You notice that the drawer gave a little "+
			"inward when you started to force it...maybe you should have "+
			"pushed instead?%^RESET%^\n");
		tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" pulls on the drawer and then "+
			"clutches "+TP->query_possessive()+" forearm in obvious pain!%^RESET%^",TP);
		TP->do_damage("torso",roll_dice(1,4));
  		if((int)TP->query_stats("constitution")>random(25)){
			tell_object(TP,"%^BOLD%^%^GREEN%^The buring in your arm "+
				"quickly fades and except for the red marks of the needles "+
				"you feel no worse for the wear.");
			tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" rubs "+
				""+TP->query_possessive()+" arm a bit and smiles "+
				"with relief!%^RESET%^",TP);
			return 1;
		}
		tell_object(TP,"%^BOLD%^%^RED%^The fire in your arm builds and "+
			"courses through your body!%^RESET%^");
  		poison = roll_dice(10,10);
		TP->add_poisoning(poison);
		TP->setPoisoner(TO);
		TP->add_attacker(TO);
		TP->continue_attack();
		return 1;
	}
	tell_object(TP,"Force what?");
	return 1;
}
void reset(){
	::reset();
	switch(random(10)){
		case 0..4 :
			break;
		case 5 :
			tell_room(TO,"%^BOLD%^%^RED%^Horrific screams can "+
				"be heard clearly nearby.");
			break;
		case 6 :
			tell_room(TO,"%^BOLD%^%^BLACK%^A feeling of fear "+
				"and panic fills you and then departs as suddenly as it started.");
			break;
		case 7 :
			tell_room(TO,"%^RED%^You hear the crack of a whip "+
				"followed closely by a scream and then a whimper.");
			break;
		case 8 :
			tell_room(TO,"%^CYAN%^The candles flicker and sputter as "+
				"if from an unseen wind.");
			break;
		case 9 :
			tell_room(TO,"%^BOLD%^%^RED%^Wailing and weeping can be "+
				"heard in the distance.");
			break;
		default :
			tell_room(TO,"%^BOLD%^%^RED%^There is a terrible shaking as the walls "+
				"crumble and fall in on your head!!\nYou take horrific "+
				"damage and wwould not fit in a plastic baggie even if someone "+
				"could find a squeegie.\n%^YELLOW%^PSYKE!!! %^RED%^Either that or something "+
				"bugged and you need to ask a wiz.");
			break;
	}
}
