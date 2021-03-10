//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;
void searching(object tp);

void create(){
	::create();
	set_name("library");
   set_short("library");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"Little light filters into this musty room in the recesses "+
   	"of the temple.  The tall wooden bookshelves that stretch "+
   	"from floor to ceiling are shrouded in shadow.  The books "+
   	"themselves seem well looked after, although it is clear that "+
   	"some sections are in more frequent use than others"+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","%^BOLD%^%^CYAN%^The air smells faintly "+
   	"of %^WHITE%^candles%^CYAN%^, %^RESET%^%^RED%^blood "+
   	"%^BOLD%^%^CYAN%^and %^MAGENTA%^incense%^CYAN%^.%^RESET%^");
   set_listen("default","%^YELLOW%^You hear tortured screams "+
   	"from deep within the temple.%^RESET%^\n");
   set_items(([
   	({"bookshelf","bookshelves"}) : "The wooden bookshelves are "+
   		"stacked with books.  There are sections on theology, the "+
   		"beliefs and practices of a number of religions, a great many "+
   		"biographies, as well as a large number of treatises on the "+
   		"practice and theory of torture.\n",
   	"theology" : "The books in this section tend to be dry and learned, "+
   		"dealing in quite technical terms with the problems of the "+
   		"relationships between the gods and mortals.  There is a "+
   		"tendancy towards the ponderous turn of a phrase and the "+
   		"tortured twists of logic and you wonder whether the lovites "+
   		"read these books for knowledge or just the pain of wading "+
   		"through turgid test.\n",
   	"biographies" : "At first glance it is something of a surprise "+
   		"to see so many tales of individual lives within this collection "+
   		"of books.  However, leafing through just a few texts brings to "+
   		"mind just how much pain and misery afflicts life.  Presumably "+
   		"the Loviatans like to use these texts to remind themselves, "+
   		"and others, of that simple truth.  Doubtless too, through "+
   		"reading they can better understand the suffering of others "+
   		"and thereby be more efficient in multiplying it.\n",
   	"torture" : "Well here's a little treasure trove of books devoted "+
   		"to all manner of torture, from simple twists of mind games and "+
   		"emotional blackmail, through to pincer, tongs and red hot coals "+
   		"of basic physical abuse of a captive./n"
  	]));
   set_exits(([
		"north" : GAB+"hall0"
	]));

  	set_door("wooden door",GAB+"hall0","north","loviatar_holy_symbol");
   set_door_description("walnut door","The door is made of stout oak "+
   	"and is banded in iron.\n");
   set_string("wooden door","open","The door opens into a hall.\n");

}
void init(){
   ::init();
   add_action("search_em","search");
}
int search_em(string str) {
        if(!str) return 0;
        if(str != "books") return 0;
   if (str == "books"){
   	tell_object(TP,"%^BOLD%^You search the books and read a random passage.\n");
   	tell_room(TO,"%^BOLD%^"+TPQCN+" searches through the books and pulls down "+
                "one and begins to read.\n",TP);
      searching(TP);
      return 1;
   }
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
				"damage and will not fit in a plastic baggie if someone "+
				"can find a squeegie.\n%^YELLOW%^PSYKE!!! %^RED%^Either that or something "+
				"bugged and you need to ask a wiz.");
			break;
	}
}
void searching(object tp){
	string str;

	switch(random(11)){
   	case(0):
   		str = "...the premise, then, that the matters concerning a "+
   			"deity's sphere of influence can be taken to be their "+
   			"concern alone among the grater and lesser powers is shown "+
   			"to be false by the application of Darmissius's theory of "+
   			"conjoined influences.  Thus, the controlling power of Tempus "+
   			"in the fields of battle does not exclude the interest and "+
   			"influence of Loviatar on the pain and suffering entailed "+
   			"therein.  Cantillus further asserts that by no means all "+
   			"matters relating to the deities' sphere of influence can be "+
   			"actually shown to be of interest to, or the province of, the "+
   			"deity involved...";
			break;
		case(1):
			str = "...and so Lovites argue that the Maiden, born of searing "+
				"agony of the first tearing of creation, is truly the first "+
				"among gods.  There is some merit to this argument, although, "+
				"it can clearly be shown that other deities at this time wield "+
				"more power (at this point the text has been rather unpleasantly "+
				"defaced and is quite unreadable)...";
			break;
    	case(2):
    		str = "...taking the assumption of a hierarchical structure as "+
    			"implicit in the descriptive terms of greater and lesser powers "+
    			"is, in itself, flawed and misleading and can tend one towards "+
    			"the fundamental error of assuming some static and unchanging "+
    			"relationship between those powers, where in fact the very annals "+
    			"of cannoical research attest to unending vageries, uncertainties, "+
    			"and constant realignments in said relationships.  It is, therefore, "+
    			"better in some ways, although entirely wrong in others of course, "+
    			"to think of the gods in much the same manner as mortals, with their "+
    			"own constant struggles and contests for power, forming and "+
    			"reforming of alliances, and emnities.  One difference, of course, "+
    			"is the time structure which such...";
			break;
		case(3):
			str = "...to which Thakkarus responded that Deavine's "+
				"theorum 'were't based upon such solid grounds that if "+
				"t'were a fortification  it should surely sink in't mire "+
				"and be lost fore're'.  All assembled were in agreement that "+
				"this would be no bad thing in the curcumstances and so Deavine "+
				"was unanimously voted down from the chair and Thakkarus was "+
				"voted up, at which point his own essaying on the nature of the "+
				"Avatar came under much closer scrutiny than before, leading to "+
				"the discovery by Allinus of Seneca of the one fatal flaw which "+
				"exposed the soft underbelly of all Thakkarus's musings and so...";
			break;
   	case(4):
   		str = "...that learning faith is the single most important "+
   			"journey that any mortal can undertake and yet, paradoxically, "+
   			"faith itself is the one thing which may not be learned.  "+
   			"Theory yes, history yes, dogma and scripture certainly, "+
   			"obediance without a doubt, but faith. elusive to the end, "+
   			"stays beyond those who would grasp at it or seek after it.  "+
   			"Faith, in the final analysis, is only there not when you choose "+
   			"a god, but when a god chooses you.  Thus, the decision to "+
   			"follow is not one to be taken lightly, or at a whim, but only "+
   			"when the hearts purpose is fully revealed.  It should be a "+
   			"matter of imperative, not of choice.  If a mortal is able to "+
   			"make a choice about which god to follow, argues Leddan, then "+
   			"he should follow none.  Dedication, and true worship, is only "+
   			"there for those for whom there is no choice...";
			break;
		case(5):
			str = "******************************\n3 Autumnstime\n\nTormini "+
				"came home today and I was so excited to see him again.  He "+
				"had been gone so long and I missed him so much.  When he "+
				"walked through the gate I could see those sparkling blue "+
				"eyes I always loved so much, that crooked smile, and the "+
				"way he always stooped slightly, being so tall and all.  "+
				"I ran to him, throwing my arms around his neack and he "+
				"lifted me up and we kissed, my heart sang.  I could feel "+
				"myself blushing and laughing all at once. not knowing "+
				"whether to kiss him or hug him or put him over my knee "+
				"and spank him for being away so long.  But when he looked "+
				"up at me again, there was something in his eyes and I knew "+
				"something was wrong.  'Nessis' he said, 'there's someone I "+
				"want you to meet - '  And the I saw her, fussing round the "+
				"back of his wagon so prissily, a dumb looking blonde half-elf "+
				"wench no more than half his age.  Pretty enough I suppose if "+
				"you like that sort of thing, but certainly not good enough for "+
				"my Tormini.  Yes!  MY Tormini.  He was supposed to be mine, "+
				"wasn't he?  He promised and I waited, all those years, and all "+
				"those offers I could have taken...";
			break;
   	case(6):
   		str = "...the fever.  The healer said it would be alright if she "+
   			"drank a little of the swamp water every day, so I went down "+
   			"and fetched it for her, regular as you like, but she just "+
   			"seemed to get worse and worse until one day she upped and "+
   			"died.  I never felt worse than that, least until I heard one "+
   			"of the children start coughing in that same wheezy cough that "+
   			"Labann started with and I felt me own throat start with a raw "+
   			"tickle.  I suppose this is going to mean yet more trips to "+
   			"the swamp for me...";
			break;
		case(7):
			str = "...In the springtime, not long after little Kalani was "+
				"born, Martja and Elsinor moved to the peaceful town of "+
				"Sanctuary. Elsinor found work helping the rangers patrol "+
				"the nearby forest and Marja soon found herself with child "+
				"again. In the fourth month of her pregnancy, little Kalani "+
				"died. It was nothing spectacular or dramatic, he just caught "+
				"a bug and... died.  Martja was devastated, of course, but "+
				"with her new baby to thinkof she did all that she could to "+
				"find a way to cope. It was Elsinor who was hit the hardest.  "+
				"Suddenly coming home seemed to do nothing but remind him of "+
				"the little boy he loved but hadn't done enough for in his "+
				"mind.  So, instead he stayed away, throwing himself into his "+
				"work at just the moment Martje needed him most and slowly "+
				"they drifted apart, became distant, more spiteful towards each other...";
			break;
   	case(8):
   		str = "...use of the rack for more pragmatic purposes.  As with "+
   			"all torture, however, the information given cannot be "+
   			"accepted as fact, as the recipient is speaking from a "+
   			"desire to end the pain rather than to make clear the "+
   			"truth. The teachings of the Maiden, however, show us "+
   			"that any information gained or concession granted is "+
   			"of secondary to concern when compared to the simple "+
   			"sanctity of the pain created. It should also be noted "+
   			"that the mental duress is infinitely increased by the "+
   			"judicious creation and then destruction of hope. Do not "+
   			"be too swift, then, to get to the bone-cracking, joint "+
   			"popping denouement of the racks employ, but rather let "+
   			"the chains slacken from time to time, to let hope grow in "+
   			"the heart of your victim before crushing it utterly.  "+
   			"Remember also to give some small thanks to the divine "+
   			"Shar for the use of Her knowledge about hope and its "+
   			"destruction...";
         break;
     	case(9):
     		str = "...the metal boots. Once strapped in, the victim "+
     			"is quite unable to move and it is at this point that "+
     			"the boiling oil may be poured into the boots via the "+
     			"special inlets mounted on the boots' sides. Care should "+
     			"be taken about the security of the area used for this "+
     			"process as the victim's screams as the flesh and sinew "+
     			"is scalded away from their feet and ankles are likely "+
     			"to cause great alarm if overheard. An added bonus of the "+
     			"solid construction of the boots is that should the victim "+
     			"be unable to withstand the pain and faint or fall they are "+
     			"most likely to snap their own shinbones in the process. It "+
     			"is generally advised to pour the oil in for a brief period, "+
     			"then drain it and start over again, both to maintain the "+
     			"necessary temperature and to prolong and repeat the agony.  "+
     			"It is also advised to halt the procedure before all remnants "+
     			"of flesh have been stripped away from the victim's lower legs, "+
     			"as it is generally acknowledged that the real pain begins as "+
     			"the body's natural healing processes get underway. It is "+
     			"better to leave a little raw and bleeding flesh alive than "+
     			"simply to boil it all away, and careful judgement, the "+
     			"result of many hours of experimentation, will be needed "+
     			"to achieve this...";
     		break;
     	case(10):
     		str = "...given to the longer term and psychological pain which "+
     			"may be caused through torture, as well as just its immediate "+
     			"physical impact. Careful study shows that victims often suffer "+
     			"from recurring nightmares and flashbacks to their torment, and "+
     			"in their ongoing distress can cause great suffering and anguish "+
     			"to all those who care about them. It seems to be the case that "+
     			"the more helpless and vulnerable the victim can be made to feel "+
     			"at the time, the more pronounced and prolonged these effects are "+
     			"likely to be. Causing some form of permanent disfigurement, "+
     			"especially if it is in some way physically handicapping, such "+
     			"as the loss of an eye or the fingers of a hand, can serve as "+
     			"a constant reminder to the victim, and...";
     		break;
 	}
	tell_object(tp,"%^BOLD%^You read:\n"+str+"%^RESET%^\n");
  	return;
}
