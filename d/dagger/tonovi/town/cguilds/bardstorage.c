#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
    set_short("storage room");
    set_property("indoors", 1);
    set_property("light", 1);
    set_property("no teleport", 1);
    set_long(
      "You shouldn't be in here, so leave."
    );
    set_exits( ([
	"out" : "/d/darkwood/tabor/room/cnc_backstage.c",
      ]) );
}

void reset(){
    ::reset();
    if(!present("drum"))
	new("/d/dagger/tonovi/obj/drum.c")->move(TO);
    if(!present("fife"))
	new("/d/dagger/tonovi/obj/fife.c")->move(TO);
    if(!present("lute"))
	new("/d/dagger/tonovi/obj/lute.c")->move(TO);
    if(!present("instrument case"))
      new("/d/common/obj/instruments/instrument_case.c")->move(TO);
    if(!present("instrument case") && !random(3))
      new("/d/common/obj/instruments/instrument_case.c")->move(TO);
	if(!present("instrument 4"))
		switch(random(18)){
		default:
			new("/d/common/obj/instruments/lyre.c")->move(TO);
		break;
		case 1:
			new("/d/common/obj/instruments/bagpipes.c")->move(TO);
		break;
		case 2:
			new("/d/common/obj/instruments/bones.c")->move(TO);
		break;
		case 3:
			new("/d/common/obj/instruments/banjolele.c")->move(TO);
		break;
		case 4:
			new("/d/common/obj/instruments/bongodrums.c")->move(TO);
		break;
		case 5:
			new("/d/common/obj/instruments/clavichord.c")->move(TO);
		break;
		case 6:
			new("/d/common/obj/instruments/drum.c")->move(TO);
		break;
		case 7:
			new("/d/common/obj/instruments/fiddle.c")->move(TO);
		break;
		case 8:
			new("/d/common/obj/instruments/flute.c")->move(TO);
		break;
		case 9:
			new("/d/common/obj/instruments/handbell.c")->move(TO);
		break;
		case 10:
			new("/d/common/obj/instruments/harmonica.c")->move(TO);
		break;
		case 11:
			new("/d/common/obj/instruments/hautbois.c")->move(TO);
		break;
		case 12:
			new("/d/common/obj/instruments/lap-harp.c")->move(TO);
		break;
		case 13:
			new("/d/common/obj/instruments/lute.c")->move(TO);
		break;
		case 14:
			new("/d/common/obj/instruments/mandolin.c")->move(TO);
		break;
		case 15:
			new("/d/common/obj/instruments/panpipes.c")->move(TO);
		break;
		case 16:
			new("/d/common/obj/instruments/shawm.c")->move(TO);
		break;
		case 17:
			new("/d/common/obj/instruments/tabor.c")->move(TO);
		break;
		}
	if(!present("instrument 5"))
		switch(random(18)){
		default:
			new("/d/common/obj/instruments/lyre.c")->move(TO);
		break;
		case 1:
			new("/d/common/obj/instruments/bagpipes.c")->move(TO);
		break;
		case 2:
			new("/d/common/obj/instruments/bones.c")->move(TO);
		break;
		case 3:
			new("/d/common/obj/instruments/banjolele.c")->move(TO);
		break;
		case 4:
			new("/d/common/obj/instruments/bongodrums.c")->move(TO);
		break;
		case 5:
			new("/d/common/obj/instruments/clavichord.c")->move(TO);
		break;
		case 6:
			new("/d/common/obj/instruments/drum.c")->move(TO);
		break;
		case 7:
			new("/d/common/obj/instruments/fiddle.c")->move(TO);
		break;
		case 8:
			new("/d/common/obj/instruments/flute.c")->move(TO);
		break;
		case 9:
			new("/d/common/obj/instruments/handbell.c")->move(TO);
		break;
		case 10:
			new("/d/common/obj/instruments/harmonica.c")->move(TO);
		break;
		case 11:
			new("/d/common/obj/instruments/hautbois.c")->move(TO);
		break;
		case 12:
			new("/d/common/obj/instruments/lap-harp.c")->move(TO);
		break;
		case 13:
			new("/d/common/obj/instruments/lute.c")->move(TO);
		break;
		case 14:
			new("/d/common/obj/instruments/mandolin.c")->move(TO);
		break;
		case 15:
			new("/d/common/obj/instruments/panpipes.c")->move(TO);
		break;
		case 16:
			new("/d/common/obj/instruments/shawm.c")->move(TO);
		break;
		case 17:
			new("/d/common/obj/instruments/tabor.c")->move(TO);
		break;
		}











}
