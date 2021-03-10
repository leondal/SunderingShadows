//drinking_horn.c - by Circe for Lothwaite 6/21/04
//adapted from waterskin.c in Antioch
#include <std.h>
inherit ARMOUR;

#define DESIGNS ({"%^RED%^dragons","%^BOLD%^%^MAGENTA%^flowers","%^YELLOW%^bees","%^ORANGE%^stags","%^RED%^bulls","%^BOLD%^%^BLUE%^swirling ribbons","%^ORANGE%^dogs","%^BOLD%^%^RED%^a pho%^YELLOW%^e%^RED%^nix","%^BOLD%^%^BLACK%^repeating daggers","%^YELLOW%^crowns %^RESET%^and %^CYAN%^jewels","%^BOLD%^%^RED%^hearts"})

int drinks,i;
int alcohol;
string DESIGN;

void create()
{
	::create();
	i = random(sizeof(DESIGNS));
	DESIGN = DESIGNS[i];
	set_name("drinking horn");
	set_short("%^YELLOW%^drinking horn%^RESET%^");
	set_id(({"horn","drinking horn","firbolg horn","firbolg drinking horn"}));
	set_long("This drinking horn is made from the %^BOLD%^antler "+
         "%^RESET%^of a large bull.  The horn curves near the end to a "+
         "point, which is capped in %^YELLOW%^gold%^RESET%^.  The "+
         "open end of the horn is rimmed in a two-inch %^YELLOW%^"+
         "golden band %^RESET%^beaten with the image of "+DESIGN+""+
         "%^RESET%^.  A well-fitting %^ORANGE%^leather cap %^RESET%^"+
         "is attached to the horn with a %^ORANGE%^leather thong"+
         "%^RESET%^, and it looks as though it would provide a good "+
         "seal.  A leather thong attached to a wooden toggle allows "+
         "the horn to hang from a belt.  It looks like you could "+
         "probably drink quite "+
         "a bit from the horn before you refill it.  You may also "+
         "empty it, though...why would you want to?");
set_weight(3);
	set_value(500);
      set_type("ring");
      set_limbs(({"waist"}));
      set_ac(0);
	drinks = 5;
      alcohol = 1;
      set_wear("You slip the wooden toggle through a belt loop, "+
         "letting the horn dangle at your side.");
}

void init()
{
	::init();
	add_action("drink","drink");
	add_action("refill_skin","refill");
	add_action("check_skin","check");
      add_action("empty_horn","empty");
}

void drink(string str)
{
	if(!living(ETO)) {
		notify_fail("You must be holding the drinking horn to be able to drink from it.\n");
		return 0;
	}
	if(!interactive(ETO)) {
		notify_fail("You must be holding the drinking horn to be able to drink from it.\n");
		return 0;
	}
	if(str == "from horn" || str == "from drinking horn") {
         if(alcohol == 1){
		if(drinks < 1) {
			tell_object(ETO,"The drinking horn is empty.");
			return 1;
		}
		if(!ETO->add_intox(50)) {
			notify_fail("Your stomach quails at the thought of another drink!\n");
			return 0;
		}
		if(drinks == 1) {
			tell_object(ETO,"You drink the last of the wonderful "+
                     "mead from the drinking horn.");
			tell_room(EETO,""+ETOQCN+" takes a drink from"
			" "+ETO->QP+" drinking horn.",ETO);
			ETO->add_intox(50);
			drinks -= 1;
                  alcohol = 0;
			return 1;
		}
		else {
			tell_object(ETO,"You take a long drink from the "+
                     "drinking horn, savoring the sweet honey mead.");
			tell_room(EETO,""+ETOQCN+" takes a long drink from"+
			" "+ETO->QP+" drinking horn.",ETO);
			ETO->add_intox(50);
                  alcohol = 1;
			drinks -= 1;
			return 1;
		}
         }else{
		if(drinks < 1) {
			tell_object(ETO,"The drinking horn is empty.");
			return 1;
		}
		if(!ETO->add_quenched(20)) {
			notify_fail("Your stomach is sloshing already!\n");
			return 0;
		}
		if(drinks == 1) {
			tell_object(ETO,"You drink the last of the cool water "+
                     "from the drinking horn.");
			tell_room(EETO,""+ETOQCN+" takes a drink from"
			" "+ETO->QP+" drinking horn.",ETO);
			ETO->add_quenched(20);
                  alcohol = 0;
			drinks -= 1;
			return 1;
		}
		else {
			tell_object(ETO,"You take a long drink from the "+
                     "drinking horn, enjoying the cool water.");
			tell_room(EETO,""+ETOQCN+" takes a long drink from"+
			" "+ETO->QP+" drinking horn.",ETO);
			ETO->add_quenched(20);
                  alcohol = 0;
			drinks -= 1;
			return 1;
            }
         }
	}
}

void refill_skin(string str)
{
string liquid;
	if(!living(ETO)) {
		notify_fail("You must be holding the drinking horn to be able to refill it.\n");
                return 1;
	}
	if(!interactive(ETO)) {
		notify_fail("You must be holding the drinking horn to be able to refill it.\n");
		return 0;
	}
      if(sscanf(str,"horn with %s",liquid) != 1){
		tell_object(ETO,"Try refill horn with water or refill "+
               "horn with mead.\n");
		return 1;
	}
	if(drinks > 0) {
		tell_object(ETO,"The drinking horn already has something "+
               "in it!  You may empty it if you want.");
		return 1;
	}
      if(liquid == "mead"){
	   if(present("barkeep",EETO) || present("bartender",EETO)) {
	   	if(!ETO->query_funds("gold",75)) {
			tell_object(ETO,"The price is 75 gold.  You do not "+
                     "have enough money.");
			return 1;
		}
		else {
			tell_object(ETO,"You hand your drinking horn to "+
                     "the bartender to be refilled for a nominal fee.");
			tell_room(EETO,""+ETOQCN+" hands "+ETO->QP+""+
			" drinking horn over to the bartender who refills "+
                  "it and hands it back",ETO);
			ETO->use_funds("gold",75);
			drinks = 5;
                  alcohol = 1;
			return 1;
          }
       }
          tell_object(ETO,"Now where do you think you're going to get "+
             "mead here?  Try a bar.");
          return 1;
    }
    if(liquid == "water"){
	if(environment(ETO)->query_property("fill waterskin")) {
		tell_object(ETO,"You bend down and refill the drinking horn.");
		tell_room(EETO,""+ETOQCN+" bends down and"+
		" refills "+ETO->QP+" drinking horn.",ETO);
		drinks = 5;
            alcohol = 0;
		return 1;
	}
	else {
		tell_object(ETO,"You must be at a pond or like place to refill"+
		" this drinking horn. If you believe you are at one and it is not working,"+
		" use the bug command and report it.\n");
                return 1;
	}
    }
    tell_object(ETO,"You may refill the drinking horn with mead or water.");
    return 1;
}

void check_skin(string str)
{
	if(!living(ETO)) {
		notify_fail("You must be holding the drinking horn to be able to check it.\n");
		return 0;
	}
	if(!interactive(ETO)) {
		notify_fail("You must be holding the drinking horn to be able to check it.\n");
		return 0;
	}
	if(str != "drinking horn" && str != "horn") {
		notify_fail("Check what?\n");
		return 0;
	}
      if(alcohol == 1){
   	   switch(drinks) {
		case 5:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is full of mead.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 4:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is almost full of mead.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 3:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is about half full of mead.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 2:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is still has mead, though it is getting close "+
                     "to empty.  Pity.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 1:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is has very little mead left in the bottom.  You "+
                     "should visit a bartender soon.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 0:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is completely empty.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside, then sighs.",ETO);
			break;
		default:
			notify_fail("Something seems to be wrong here.  "+
                     "Bug report it or contact a wiz.");
			return 0;
	   }
         return 1;
	}else{
   	   switch(drinks) {
		case 5:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is full of water.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 4:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is almost full of water.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 3:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is about half full of water.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 2:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is still has water, though it is getting close "+
                     "to empty.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 1:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is has very little water left in the bottom.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside.",ETO);
			break;
		case 0:
			tell_object(ETO,"You flip the top off and see the horn "+
                     "is completely empty.");
                  tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" "+
                     "drinking horn and peers inside, then sighs.",ETO);
			break;
		default:
			notify_fail("Something seems to be wrong here.  "+
                     "Bug report it or contact a wiz.");
			return 0;
	   }
         return 1;
      }
	return 1;
}

void empty_horn(string str){
   if(!str){
      tell_object(TP,"Try empty horn.");
      return 1;
   }
   if(str != "horn" && str != "drinking horn"){
      tell_object(TP,"Try empty horn.");
      return 1;
   }
   if(drinks == 0){
      tell_object(ETO,"You flip the top off the horn and turn it over, "+
         "but nothing comes out.");
      tell_room(EETO,""+ETOQCN+" flips the top off "+ETO->QP+" horn "+
         "and turns it over, but nothing comes out.",ETO);
      return 1;
   }
   if(alcohol == 1){
      tell_object(ETO,"You flip the top off the horn and pour the "+
         "precious %^YELLOW%^honey mead %^RESET%^onto the ground.  "+
         "Why, oh why?!");
      tell_room(EETO,""+ETOQCN+" flips the top off the horn and "+
         "pours an %^YELLOW%^amber liquid %^RESET%^onto the ground.",ETO);
      alcohol = 0;
      drinks = 0;
      return 1;
   }
   tell_object(ETO,"You flip the top off the horn and pour the "+
      "water onto the ground.");
   tell_room(EETO,""+ETOQCN+" flips the top off "+ETOQCN+" horn and "+
      "pours water onto the ground.",ETO);
   drinks = 0;
   return 1;
}
