#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_room_type("guild");
    set_short("Piano Platform");
    set_long(
      "Here on this platform sits a giant grand piano.  The great black piano rests here to entertain the people of the dining room, when someone is here to play it.  Unfortunately, there is currently nobody here playing it."
    );
    set_smell("default", "You can smell the great food from the dining room.");
    set_listen("default", "Beautiful music is coming from the grand piano.");
    set_listen("piano", "Hmm, strange.  Nobody is playing the piano, yet music is coming from it.");
    set_listen("music", "The music coming from the piano isn't just piano music, it sounds like a whole symphony!");

    set_items( ([
	"piano" : "The great grand piano sits without anyone to play it.",
      ]) );
    set_exits( ([
	"north" : RPATH "hotel2"
      ]) );
}

void init(){
    ::init();
    add_action("sit", "sit");
    add_action("play", "play");
    add_action("search_it", "search");
    add_action("move_piano", "move");
    add_action("set_fire", "burn");
    add_action("smash_it", "smash");
}

int sit(string str){
    if( (str != "at piano") && (str != "piano") && (str != "bench") && (str != "at bench") )
	return notify_fail("sit where?");

    if(query_property("smashed piano")) return notify_fail("The piano is smashed!!!\n");

    tell_object(TP, "You sit at the piano bench and run your fingers across the keys.");
    tell_room(ETP, TPQCN+" sits at the piano bench and runs "+TP->query_possessive()+" fingers across the keys.", TP);
    TP->set_property("pianositting", 1);
    return 1;
}

int play(string str){
    if(str != "piano") return notify_fail("Play what?");

    if(query_property("smashed piano")) return notify_fail("The piano is smashed!!!\n");

    if(!TP->is_class("bard")) {
	tell_object(TP, "You look at the piano keys, and remember you have no idea how to play the piano!");
	return 1;
    }

    if(!TP->query_property("pianositting")) {
	tell_object(TP, "You have to be sitting on the piano bench to play the piano!");
	return 1;
    }

    tell_object(TP, "You slide your fingers across the piano keys masterfully, playing an ancient song known only to the great bards.");
    tell_room(ETP, TPQCN+" runs "+TP->query_posessive()+" fingers across the piano keys, masterfully playing an ancient sounding tune that you know you've heard before, but can't place.", TP);
    tell_object(TP, "As you finish the song, the piano bench flashes suddenly, and you find yourself somplace else!");
    tell_room(ETP, TPQCN+" finishes the song, and suddenly vanishes in a flash!", TP);
    TP->remove_property("pianositting");
    TP->move_player(RPATH "cguilds/bard1");
    return 1;
}

int search_it(string str){
    if(!str || str != "piano") return notify_fail("Search what?\n");

    if(TP->is_class("bard")) {
      tell_object(TP, "The piano bench beckons to your musical spirit.  Perhaps you should sit and play a tune?");
      return 1;
    } else {
      tell_object(TP, "As you search the piano, you notice that its covering a strange trapdoor.  You can't see how to get the door open at all.  The damn piano is in the way.");
      return 1;
    }
}

int move_piano(string str){
    if(!str || str != "piano") return notify_fail("Move what?\n");
    tell_object(TP, "No matter how hard you try, you just can't move that piano!  There's gotta be another way to get rid of the stupid piece of firewood.");
    return 1;
}

int set_fire(string str){
    if(!str || str != "piano") return notify_fail("burn what?\n");
    tell_object(TP, "Now you're thinking, that'd get rid of the piano, but the hotel people would be here too quick...  there's gotta be another way to smash that damn thing.");
    return 1;
}

int smash_it(string str){
    if(!str || str != "piano") return notify_fail("Smash what?\n");
    if(TP->is_class("bard")) {
      tell_object(TP, "WHAT???  You'd smash that beautiful instrument?!?!  What kind of a bard are you???");
      return 1;
    } else {
      tell_object(TP, "You wind up, and KERPLOWIE!!!  Wow that was a nice hit.  The piano split in half!  You can now get at that door.");
      tell_room(TO, TPQCN+" raises "+TP->query_possessive()+" weapon, and with a battle cry smashes the piano!", TP);
      set_long(
        "Here on the platform sits the remains of what used to be a giant grand piano.  Someone decided they didn't like it and smashed it.  You should find them and kick their ass."
      );
      add_exit("/d/dagger/tonovi/town/cguilds/bardenter", "down");
      set_property("smashed piano", 1);
      return 1;
    }
}

void reset(){
    ::reset();
    remove_exit("down");
    set_long(
      "Here on this platform sits a giant grand piano.  The great black piano rests here to entertain the people of the dining room, when someone is here to play it.  Unfortunately, there is currently nobody here playing it."
    );
    remove_property("smashed piano");
}
