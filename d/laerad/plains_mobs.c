// Coded by Bane
// changed by *Styx* to use CROOM for mob control & mixing things up all across the wasteland and plains 12/14/03, last change 10/27/01 putting in terrain no doubt
// Adjusted by ~Circe~ 2/8/13 to increase the population

#include <std.h>

#define MOB "/d/laerad/mon/"
#define EXTRAS ({ MOB+"tlin1", MOB+"tlin2", MOB+"tlin3", MOB+"tlin4", MOB+"tlin5", MOB+"cildabrin", MOB+"tshala", MOB+"flailer", MOB+"gearth", MOB+"hordling", MOB+"hordling", MOB+"edrake" })

inherit CROOM;

// void more_mons();
void set_mobs();

void create() {
    if(!random(2)) {
	set_mobs();
    }
    ::create();
    set_repop(50);
    set_terrain(SCRUB_LANDS);
    set_travel(FOOT_PATH);
	set_climate("desert");
    set_name("Gods Plains");
    set_short("%^BOLD%^%^BLACK%^The Gods Plains%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand on a charred plain.  Blades of grass "
	"struggle to push their way up from the blackened earth.  Dark %^RESET%^clouds "
	"%^BOLD%^%^BLACK%^roil angrily in the sky above the impassable mountains that form the border of "
	"the plains to the north.  A fierce wind "
	"dances and cackles around you.  Desolation is all that is more abundant than the "
	"%^RED%^blood stains %^BLACK%^on the parched earth and the %^WHITE%^"
	"bones %^BLACK%^that have been picked clean by vultures.  Perhaps the "
	"rumors that the Gods themselves once waged a war here that caused the "
	"desolation and destruction are true.  Regardless of the cause, the "+
	"curse upon this land must truly be terrible.\n");
    set_property("light",2);
    if(random(4))
	set_property("no sticks", 1);
    set_smell("default","A bitter wind stings your face.");
    set_listen("default","You hear the screeching of %^BOLD%^%^BLACK%^vultures %^RESET%^%^GREEN%^circling above.");
}
/*
string ldesc(string str) {
   return("%^BOLD%^%^BLACK%^You stand on a charred plain.  Blades of grass "
	"struggle to push their way up from the blackened earth.  Dark %^RESET%^clouds "
	"%^BOLD%^%^BLACK%^roil angrily in the sky above the impassable mountains that form the border of "
	"the plains to the north.  A fierce wind "
	"dances and cackles around you.  Desolation is all that is more abundant than the "
	"%^RED%^blood stains %^BLACK%^on the parched earth and the %^WHITE%^"
	"bones %^BLACK%^that have been picked clean by vultures.  Perhaps the "
	"rumors that the Gods themselves once waged a war here that caused the "
	"desolation and destruction are true.  Regardless of the cause, the "+
	"curse upon this land must truly be terrible.\n"
   );


   return(
	"%^BOLD%^%^BLACK%^You stand on a charred plain.  Blades of grass struggle "
	"to push their way up from the blackened earth and only a few seem to "
	"survive for long.  Dark clouds roll "
	"through the sky up above.  A fierce wind dances and cackles "
	"its way past you, leaving you with an uneasy feeling even without the "
	"roars and rumbles from the vile creatures that roam here.  "
	"The curse upon this dreaded land must "
	"truly be terrible.  Perhaps the rumors are true that the Gods themselves "
	"once waged a war here.  Clearly only rubble and destruction "
	"were left in the wake of whatever befell this section of the island."
   );

}
*/

void set_mobs() {
  int num;
  num = sizeof(EXTRAS);

  switch(random(130)) {
    case 0:  	  set_monsters( ({MOB+"titan"}), ({1}) );
			break;
    case 1..2: 	  set_monsters( ({MOB+"titan", EXTRAS[random(num)] }), ({1, 1}) );
			break;
    case 3..4:	  set_monsters( ({MOB+"edrake"}), ({1}) );
			break;
    case 5..6:	  set_monsters( ({MOB+"edrake", EXTRAS[random(num)] }), ({1, 1}) );
			break;
    case 7..14:	  set_monsters( ({MOB+"gearth"}), ({1}) );
			break;
    case 15..18:  set_monsters( ({MOB+"gearth", EXTRAS[random(num)] }), ({1, 1}) );
			break;
    case 19..30:  set_monsters( ({MOB+"tlin1"}), ({1}) );
			break;
    case 31..32:  set_monsters( ({MOB+"tlin1", EXTRAS[random(num)] }), ({1, 1}) );
			break;
    case 33..40:  set_monsters( ({MOB+"tlin2"}), ({1}) );
			break;
    case 41..45:  set_monsters( ({MOB+"tlin2", EXTRAS[random(num)] }), ({1, 2}) );
			break;
    case 46..50:  set_monsters( ({MOB+"tlin3"}), ({1}) );
			break;
    case 51..58:  set_monsters( ({MOB+"tlin3", EXTRAS[random(num)], EXTRAS[random(num)] }),
				 ({1, 1, 1}) );
			break;
    case 59..62:  set_monsters( ({MOB+"tlin4"}), ({1}) );
			break;
    case 63..71:  set_monsters( ({MOB+"tlin4", EXTRAS[random(num)], EXTRAS[random(num)] }),
				 ({1, 1, 1}) );
			break;
    case 72..75:  set_monsters( ({MOB+"tlin5"}), ({1}) );
			break;
    case 76..85:  set_monsters( ({MOB+"tlin5", EXTRAS[random(num)], EXTRAS[random(num)] }),
				 ({1, 1, 1}) );
			break;
    case 86..89:  set_monsters( ({MOB+"cildabrin"}), ({random(2)+1}) );
			break;
    case 90..92:  set_monsters( ({MOB+"cildabrin", EXTRAS[random(num)] }), ({1, 2}) );
			break;
    case 93..95:  set_monsters( ({MOB+"tshala"}), ({random(2)+1}) );
			break;
    case 96..105:  set_monsters( ({MOB+"tshala", EXTRAS[random(num)]}), ({2, 1}) );
			break;
    case 106..108: set_monsters( ({MOB+"flailer"}), ({random(2)+1}) );
			break;
    case 109..112: set_monsters( ({MOB+"flailer", EXTRAS[random(num)]}), ({2, 1}) );
			break;
    case 113..129:  set_monsters( ({MOB+"hordling", EXTRAS[random(num)]}), ({2, 1}) );
			break;
    default:  break;
   }
   return;
}

void reset(){
   ::reset();
   if(!present("wild_gen") && base_name(TO) != "/d/laerad/plains_mobs.c"){
      new("/d/laerad/mon/wild_gen.c")->move(TO);
   }
}

/* preserving to study more for mix later
void reset() {
    ::reset();
    if(!random(10)){
  	switch(random(55)){
	    case 0..1:
		if(!present("titan"))
		new("/d/laerad/mon/titan")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 2..3:
		if(!present("drake"))
		new("/d/laerad/mon/edrake")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 4..8:
		if(!present("elemental"))
		new("/d/laerad/mon/gearth")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 9..15:
		if(!present("tlincalli"))
		new("/d/laerad/mon/tlin1")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 16..20:
		if(!present("tlincalli"))
		new("/d/laerad/mon/tlin2")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 21..25:
		if(!present("tlincalli"))
		new("/d/laerad/mon/tlin3")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 26..30:
		if(!present("tlincalli"))
		new("/d/laerad/mon/tlin4")->move(this_object());
		if(!random(5));
		more_mons();
		break;
	    case 31..35:
		if(!present("tlincalli"))
		new("/d/laerad/mon/tlin5")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 36..38:
		if(!present("cildabrin"))
		new("/d/laerad/mon/cildabrin")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 39..41:
		if(!present("runner"))
		new("/d/laerad/mon/runner2")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 42..46:
		if(!present("tshala"))
		new("/d/laerad/mon/tshala")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 47..50:
		if(!present("flailer"))
		new("/d/laerad/mon/flailer")->move(this_object());
		if(!random(5))
		more_mons();
		break;
	    case 51..54:
		more_mons();
		more_mons();
		break;
	}
    }
}

void more_mons(){
    switch(random(50)){
	case 0..4:
       new("/d/laerad/mon/tlin1")->move(this_object());
	    if(!random(10));
	    more_mons();
	    break;
	case 5..9:
	    new("/d/laerad/mon/tlin2")->move(this_object());
            if(!random(10))
            more_mons();
            break;
	case 10..14:
	    new("/d/laerad/mon/tlin3")->move(this_object());
            if(!random(10))
            more_mons();
            break;
	case 15..19:
	    new("/d/laerad/mon/tlin4")->move(this_object());
            if(!random(10))
            more_mons();
            break;
	case 20..24:
	    new("/d/laerad/mon/tlin5")->move(this_object());
            if(!random(10))
            more_mons();
            break;
	case 25..29:
	    new("/d/laerad/mon/cildabrin")->move(this_object());
            if(!random(10))
            more_mons();
            break;
	case 30..34:
	    new("/d/laerad/mon/runner2")->move(this_object());
            if(!random(10))
            more_mons();
            break;
	case 35..39:
	    new("/d/laerad/mon/tshala")->move(this_object());
            if(!random(10))
            more_mons();
            break;
	case 40..44:
	    new("/d/laerad/mon/flailer")->move(this_object());
            if(!random(10))
            more_mons();
            break;
	case 45..49:
	    new("/d/laerad/mon/gearth")->move(this_object());
	    break;
    }
}
*/
