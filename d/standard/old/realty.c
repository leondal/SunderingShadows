//	/d/standard/realty.c
//	from the Nightmare mudlib
//	created by Descartes of Borg 01 february 1993

inherit "std/room";

void init() {
    ::init();
    add_action("purchase", "purchase");
    add_action("read", "read");
}

void create() {
  ::create();
    set_property("light", 2);
    set_property("indoors", 1);
   set("short", "Praxis Realty");
   set("long",
	"Welcome to Praxis Realty!\n"+
	"High mortals may purchase options for their homes here. "
	"A list on the wall details the options available from this "
	"realty shop, although it is by no means a list of all "
	"possibilities.");
    set_items(
	(["shop" : "High mortals may purchase building options here.",
	  "list" : "You can read the options available on it.",
	  "wall" : "It is plain."]) );
    set_exits( 
	      (["west" : "/d/standard/s_centre4"]) );
    set_property("no castle", 1);
}

void reset() {
  ::reset();
    if(present("atmos")) return;
    new("d/standard/obj/mon/atmos")->move(this_object());
}

int purchase(string str) {
    object ob;
    int cost;

    if(!present("atmos")) {
        notify_fail("Purchase from whom?\n");
	return 0;
    }
    if((string)this_player()->query_position() != "high mortal") {
	notify_fail("You do not have a home.\n");
	return 0;
    }
    if(!str) {
	notify_fail("Purchase what?\n");
	return 0;
    }
    str = lower_case(str);
    switch(str) {
	case "item":
	    ob = new("obj/itemer");
	    cost = 200;
	    break;
	case "description":
	    ob = new("obj/describer");
	    cost = 600;
	    break;
	case "room":
	    ob = new("obj/roomer");
	    cost = 10000;
	    break;
	default:
	    notify_fail("Atmos says: We do not have that.\n");
	    return 0;
    }
    if(cost > (int)this_player()->query_money("gold")) {
	notify_fail("You do not have that kind of money.\n");
	return 0;
    }
    this_player()->add_money("gold", -cost);
    ob->move(this_player());
    write("You purchase a "+str+" for your home.");
    say(this_player()->query_cap_name()+" purchases a "+str+" for "+
	(string)this_player()->query_possessive()+" home.");
    return 1;
}

int read(string str) {
    if(!str || str != "list") {
	notify_fail("Read what?\n");
	return 0;
    }
    say(this_player()->query_cap_name()+" takes a look at the list of home options.\n");
    write("Home options available from Praxis Realty:\n"+
	"--------------------------------------------------------------------\n"+
	"item: adds a new simple item into a room of yours          200 gold\n"+
	"\n"+
	"description: allows you to redescribe an old room          600 gold\n\n"+
	"room: adds a new room to a currently existing room       10000 gold\n"+
	"     <purchase option> gets you the option>\n"+
	"-------------------------------------------------------------------\n");
    return 1;
}

