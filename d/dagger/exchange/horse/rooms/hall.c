#include <std.h>
#include "../horse.h"

inherit ROOM;

object horse_master;
int open_race, current_race_id;

void init() {
    ::init();
    add_action("setup_race", "setup_as_immortal");
    add_action("run_race", "run_as_immortal");
    add_action("buy_horse", "buy");
    add_action("list_horse", "list");
    add_action("show_race", "view");
    add_action("list_horse2", "list2");
	add_action("buy", "bet");
	add_action("sell", "claim");
	add_action("research_horse", "research");
    horse_master =find_object_or_load(STORAGE"horse_master.c");
}

void reset(){
    ::reset();
    if(!present("sign")){
        new(OBJ"sign1.c")->move(TO);
    }
    if(!present("bunny girl")){
new(MOBS"bunny_girl.c")->move(TO);
    }
}

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
	set_property("light",2);
    set_name("horse betting parlor");
    set_short("%^RESET%^%^ORANGE%^horse betting parlor%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^this room is filled with "+
	"tables and chairs all arranged to face a small stage and a "+
	"series of %^BLACK%^%^BOLD%^boards%^RESET%^%^ORANGE%^ along the "+
	"north wall that show whatever race is about to happen next. "+
	"The west wall has a counter with %^CYAN%^piles "+
	"of books%^RESET%^%^ORANGE%^ that people mill around, "+
	"flipping through to look at the history of specific horses. on "+
	"them. The remaining wall space is dominated by %^BOLD%^paintings%^RESET%^%^ORANGE%^ of "+
	"different race tracks and advertisements for jockeys and "+
	"trainers. The hardwood floor is worn and beaten and "+
        "littered with paper. A %^RESET%^thick "+
        "haze of %^BOLD%^smoke%^RESET%^%^ORANGE%^ lays near the ceiling "+
        "and there is an atmopshere of excitement. A passageway extends "+
	"to the south and there are stairs headed back out.");
	open_race = 0;
	current_race_id = 0;
    set_exits(([
    "down" : "/d/dagger/exchange/rooms/hallway2",
    "south" : ROOMS"training",
    ]));
    set_items(([
        ({"boards"}) : "%^BLACK%^%^BOLD%^large blackboards on the "+
		"northern wall are filled with notes on the next "+
		"race to be run in the circuit. You can '%^CYAN%^view race%^BLACK%^%^BOLD%^ "+
		"to see if there is a race about to be run.\n%^RESET%^",
        ({"walls"}) : "%^ORANGE%^Every square inch of wall is covered in something, "+
		"you should look at it all.",
		({"books"}) : "%^RESET%^%^ORANGE%^The counter on the west wall is covered "+
		"in piles of well worn books. These contain specific information on horses. "+
		"Above the books is a list of all of the horses in the curcuit currently "+
		"along with what number they have in the registration. To look at all of "+
		"the horses ues %^RESET%^%^BOLD%^'list horses'%^RESET%^%^ORANGE%^ and to "+
		"find a specific horse in the books use %^RESET%^%^BOLD%^'research "+
		"<number>'%^RESET%^%^ORANGE%^.\n",
		({"paintings"}) : "%^RESET%^%^ORANGE%^There are four paintings, "+
		"you can look at them each 1 through 4.%^RESET%^",
		({"painting 1"}) : "%^RESET%^This painting is of a racetrack high in the "+
		"%^BLACK%^%^BOLD%^mountains%^RESET%^. You can see the beautiful spires of "+
		"the %^BOLD%^city of Antioch%^RESET%^ in the distance. The %^BLACK%^%^BOLD%^gray "+
		"snow capped mountains%^RESET%^ are a startling contrast to the perfectly %^BLUE%^clear "+
		"blue sky%^RESET%^. The track is a perfect oval laid with %^ORANGE%^fine dirt%^RESET%^ "+
		"and %^BLUE%^%^BOLD%^blue%^RESET%^ and %^BOLD%^white%^RESET%^ pendants flap in the "+
		"wind. Beneath the painting is a plaque '%^MAGENTA%^Northern Star Race Track%^RESET%^'\n",
		({"painting 2"}) : "%^RESET%^This painting is of a racetrack %^BLACK%^%^BOLD%^"+
		"underground%^RESET%^. It is in a %^BLACK%^%^BOLD%^giant cavern%^RESET%^ that is "+
		"large enough for the %^BLACK%^%^BOLD%^gravel oval%^RESET%^, and a small viewing "+
		"area. The cavern is lit with masses of %^YELLOW%^glowing lichen%^RESET%^ from the "+
		"ceiling and some sorcery has created %^ORANGE%^clouds%^RESET%^ that hang over the "+
		"course to drizzle on the soldiers guarding the entrances. Beneath the painting is "+
		"a plaque '%^MAGENTA%^Tharis Underground Race Track%^RESET%^'\n",
		({"painting 3"}) : "%^RESET%^This painting is of a racetrack deep in the %^ORANGE%^desert%^RESET%^. "+
		"It is hard from the painting to tell where the course is, but there are "+
		"several %^CYAN%^flapping pendants%^RESET%^ along the ground and %^BLUE%^%^BOLD%^"+
		"large expansive tents%^RESET%^ around it. The artist has captured the %^RED%^severe "+
		"heat%^RESET%^ of the course quite well in their brushstrokes. Beneath the painting "+
		"is a plaque '%^MAGENTA%^Al'tari kada Races%^RESET%^'\n",
		({"painting 4"}) : "%^RESET%^This painting is of a race track hidden deep in %^GREEN%^"+
		"tall trees%^RESET%^ in an %^GREEN%^%^BOLD%^ancient forest%^RESET%^. The track "+
		"itself is laid in %^ORANGE%^finely prepared dirt%^RESET%^ and you can see in the "+
		"painting several %^BOLD%^horses%^RESET%^ near the starting line. Near the course "+
		"is a %^BLACK%^%^BOLD%^squat stone fortress%^RESET%^. Beneath the painting is a "+
		"plaque '%^MAGENTA%^Royal Asgard Yards%^RESET%^'\n",
        ({"ceiling"}) : "T%^RESET%^%^ORANGE%^he ceiling rises high above you, the "+
        "rafters large enough to be keels of galleons.%^RESET%^",
        ({"floor"}) : "%^RESET%^%^ORANGE%^The hardwood floor here is littered with "+
        "torn racing stubs, obviously losing bets.%^RESET%^",
        ({"chandeliers"}) : "%^BLACK%^%^BOLD%^three chandeliers hang from the ceiling, "+
        "providing light through %^RESET%^%^ORANGE%^numerous candles%%^RESET%^",
    ]));

set_smell("default","%^BLACK%^%^BOLD%^The air is filled with acrid pipe smoke.%^RESET%^");
set_listen("default","The whole area is filled with the calls of those betting on horses.");

}

int run_race(string str){
    object horse_master;
    horse_master =find_object_or_load(STORAGE"horse_master.c");
    if(!str) {
        return 0;
    }

    if(str != "race"){
        tell_object(TP,"Run what?\n");
        return 1;
    }
            horse_master->run_race();
			open_race = 0;

            return 1;
        }

int list_horse(string str){
    horse_master =find_object_or_load(STORAGE"horse_master.c");

    if(!str) {
        return 0;
    }
    if(str != "horses"){
        tell_object(TP,"list what?\n");
        return 1;
    }
            //tell_room(ETP,""+TPQCN+" lists the horses...\n",TP);
            tell_object(TP,"You list the horses...\n");
            horse_master->show_all_horses();
            return 1;

}

int research_horse(string str){
	int x;

    horse_master =find_object_or_load(STORAGE"horse_master.c");
    if(!str){
	write("\n%^ORANGE%^To do research on a specific horse, you "+
	"need to '%^BOLD%^research <number>%^RESET%^%^ORANGE%^'. "+
    "Perhaps you should look at the list "+
	"of all the horses on file to see the numbers.\n");
	return 1;
	}
	    //tell_room(ETP,""+TPQCN+" researches a horse...\n",TP);
        tell_object(TP,"You research a horse...\n");
        x = str;
        horse_master->show_one_horse(x);
        return 1;

}

int show_race(string str){
    object horse_master;
    horse_master =find_object_or_load(STORAGE"horse_master.c");
    if(!str) {
        return 0;
    }
    if(str != "race"){
        tell_object(TP,"show what?\n");
        return 1;
    }
	    if(open_race == 0){
		    tell_object(TP,"%^BLACK%^%^BOLD%^You look over the race "+
			"board but its empty%^RESET%^");
			return 1;
		}
            horse_master->show_current_race();
            return 1;
}

int setup_race(string str){
    object horse_master;
    horse_master =find_object_or_load(STORAGE"horse_master.c");
    if(!str) {
        return 0;
    }

    if(str != "race"){
        tell_object(TP,"Setup what?\n");
        return 1;
    }
			open_race = 1;
			current_race_id = random(10000)+1;
            horse_master->create_race();
            return 1;
}

int buy(string str){
object ob;
int value_asked,uid_asked, total;

 if(!str) {
       tell_object(TP, "%^RESET%^%^ORANGE%^Try: 'bet <number> on <what>' (example %^YELLOW%^bet 10000 on 5%^RESET%^). ");
       return 1;
    }
    if(sscanf(str, "%d on %d", value_asked, uid_asked)<2){
       tell_object(TP, "%^RESET%^%^ORANGE%^Try: 'bet <number> on <what>' (example %^YELLOW%^bet 10000 on 5%^RESET%^). ");
       return 1;
    }
    sscanf(str, "%d on %d", value_asked, uid_asked);
    	    if(open_race == 0){
		    tell_object(TP,"%^BLACK%^%^BOLD%^The clerk applauds your enthusiasm, but there is "+
			"no race on the books so he doesn't know what you're betting on.\n%^RESET%^");
			return 1;
		}
    if (!TP->query_funds("gold",value_asked)){
        tell_object(TP, "%^BLACK%^%^BOLD%^You dig through your posessions and can't find enough to pay for that%^RESET%^");
        tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps up to buy, then looks embarassed.%^RESET%^",TP);
        return 1;
    }
    TP->use_funds("gold", value_asked);
    ob = new(OBJ"certificate.c");
    ob->set_value(value_asked);
    ob->set_uid(uid_asked);
	ob->set_race_id(current_race_id);
    ob->move(TP);
    tell_object(TP, "%^RESET%^%^ORANGE%^You look over the board and place a bet.%^RESET%^");
    tell_room(ETP, "%^BLACK%^%^BOLD%^"+TPQCN+"%^BLACK%^%^BOLD%^ steps up and places a bet.%^RESET%^",TP);
    return 1;
}

int sell(string str){
    object horse_master, ob;
    int uid, value, uid_bet, total, multi, total2, ticket, edge, winning, check;

    horse_master =find_object_or_load(STORAGE"horse_master.c");

    if(!str) return 0;
    ob = present(str, TP);
    if (!objectp(ob) || !ob->id("horse_ticket")){
        tell_object(TP, "%^RESET%^%^RED%^You can't sell that here%^RESET%^");
        return 1;
    }

    value = (int)ob->check_value();
    uid_bet = (int)ob->check_uid();
	edge = (int)horse_master->return_edge();
	uid = (int)horse_master->return_winner();
    check = (int)ob->check_race_id();

	if(check != current_race_id){
	        tell_object(TP, "%^RESET%^%^RED%^That is for an old race and is worthless now%^RESET%^");
        return 1;
	}

    if (edge < -50){multi = 101;}
	if ((edge >= -49) && (edge < -40)){multi = 110;}
	if ((edge >= -39) && (edge < -30)){multi = 120;}
	if ((edge >= -29) && (edge < -20)){multi = 130;}
	if ((edge >= -19) && (edge < -10)){multi = 140;}
	if ((edge >= -9) && (edge < -0)){multi = 150;}
    if (edge == 0){multi = 175;}
	if ((edge >= 0) && (edge < 5)){multi = 200;}
	if ((edge >= 4) && (edge < 10)){multi = 300;}
	if ((edge >= 9) && (edge < 15)){multi = 400;}
	if ((edge >= 14) && (edge < 20)){multi = 500;}
	if ((edge >= 19) && (edge < 30)){multi = 600;}
	if ((edge >= 29) && (edge < 40)){multi = 700;}
    if (edge >= 49){multi = 800;}

    tell_object(TP, "%^RESET%^%^RED%^Your ticket was worth "+value+" gold. %^RESET%^");
	//Ergo 2013-12-21
	//Eleazar suggested that this sounded wrong... I concur, therefore I fix.
    //tell_object(TP, "%^RESET%^%^RED%^Your ticket was bet on "+uid_bet+" horse. %^RESET%^");
    tell_object(TP, "%^RESET%^%^RED%^Your ticket was a bet on horse "+uid_bet+". %^RESET%^");
    tell_object(TP, "%^RESET%^%^RED%^Horse number "+uid+" won! %^RESET%^");
    tell_object(TP, "%^RESET%^%^RED%^Edge "+edge+" multi! "+multi+" %^RESET%^");

	winning = multi * value /100;

	if(uid != uid_bet){

	tell_object(TP, "%^YELLOW%^This ticket didn't win!");
    ob->remove();

	return 1;
	}

    tell_object(TP, "%^YELLOW%^You won! With your bet you get back "+winning+" gold!");
	TP->add_money("gold", winning);
    ob->remove();

    return 1;
}
