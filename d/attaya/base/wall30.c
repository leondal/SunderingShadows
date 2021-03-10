#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("Great orifice.");
    set_long(
      "You have arrived at the orifice to the Crystalline Tower.  A huge shaft of light lies just beyond the orifice.  Within the light, you can see millions of smaller lights speeding upwards in a stream.  You begin to wonder what will happen to you, should you enter the stream of light."+
      "On either side of the orifice is a statue of a golden warrior, hands outstretched to the heavens."+
      "%^BOLD%^%^CYAN%^A thick fog rolls in around you and you can only see the light behind the orifice."
    );

    set_smell("default", "%^BLUE%^The fog obstructs your view in all directions..");
    set_listen("default", "You hear the crackling of electricity about you.");

    set_items( ([
	"statues" : "The statues are made from pure gold and are much to heavy to lift.  They depict powerful warriors with their arms outstretched to the heavens",
	"orifice" : "The huge circular orifice has about 20 glass panels beveled at the ends that open and close every 20 seconds, but never wide enough to slip through.  A great column of light lies just beyond.",
	"light" : "It is comprised of hundreds of speeding particles speeding upwards.",
	"walls" : "The walls are made of granite and are quite solid.  You can see no seams or creases.",
      ]) );

    set_exits( ([
	"north" : "/d/attaya/base/wall29",
      ]) );

    set_invis_exits( ({"north"}) );
}

void init() {
    ::init();
    add_action("enter_orifice", "enter");
    add_action("open_orifice", "open");
}

int enter_orifice(string str) {
    if(str=="orifice") {
	if(present("knight")) {
	    write("The orifice is not opening wide enough to get through.");
	    say("You watch "+TPQCN+" attempt to climb through a hole far too small.");
	    return 1;
	}
	write("%^BOLD%^%^MAGENTA%^You feel your body disintigrate in the Shaft of Souls.");
	say(TPQCN+" enters the orifice and is torn apart in the Shaft of Souls.");
	set_items( ([
	    "orifice" : "It is now open."
	  ]) );
	TP->move_player("/d/attaya/base/base1");
	write("%^BOLD%^%^CYAN%^You feel your body begin to regain it's shape again.");
	return 1;
    }
    return 0;
}

int open_orifice(string str) {
    if(str=="orifice") {
	if(present("knight")) {
	    write("You are not able to budge it.  Something else must open it.");
	    say(TPQCN+" tries with all their might to open the orifice further.");
	    return 0;
	} else {
	    write("It is now open.");
	    set_items( ([
		"orifice" : "It is now open."
	      ]) );
	    return 1;
	}
    }
    return 0;
}

void reset()
{
    ::reset();
    if(!present("knight"))
    {
	new("/d/attaya/mon/knight")->move(TO);
	new("/d/attaya/mon/knight2")->move(TO);
    }
}
