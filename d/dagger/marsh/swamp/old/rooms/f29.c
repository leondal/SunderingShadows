// putting in min. level per discussions with others *Styx*  11/9/03, last change 1998

#include <std.h>
#include <move.h>

inherit "/d/dagger/marsh/swamp/Mrooms.c";
#define MPATH "/d/dagger/marsh/swamp/mon/"+
#define RPATH "/d/dagger/marsh/swamp/rooms/"+
// int xy;  not used anywhere ?? *Styx*

// int CHECK1=1;  not used now *Styx*

void init() {
   ::init();
    // add_action("search_fun", "search");
}

// long desc

void create() {
    ::create();
   set_terrain(MARSH);
   set_travel(FRESH_BLAZE);
    set_property("light", -1);
    set_property("no teleport",1);
    set_short("%^BLUE%^Marsh of Fear%^RESET%^");
    set_long( "%^RESET%^%^BLUE%^"
      "The marsh now is very dark as the %^GREEN%^rotten vegetation%^BLUE%^ "
      "and %^ORANGE%^trees%^BLUE%^ grow up "
      "to form a canopy above you. Blackness fills the area making movement treacherous and slow. "
      "The %^MAGENTA%^bog%^BLUE%^ squishes below your feet and you "
      "are extremely careful not to fall prey to the patches of "
      "%^RED%^quicksand%^BLUE%^ that are surely to be found here. "
      "All around you %^YELLOW%^insects%^RESET%^%^BLUE%^ buzz madly. The vegetation seems "
      "to own this marsh, growing possessed and with an insane frenzy. It is "
      "almost as though the land here seeps evil and is sentient and aware of those "
      "which walk upon its surface.\n%^RED%^Before you lies a massive tower-shaped billowing black column "
      "of mist. There appears to be no way into the swirling mass other than "
      "to walk straight into the side of this mystical and evil place that must be the tower known only as Demongate."     
      "\n%^GREEN%^A large %^ORANGE%^oak tree%^GREEN%^ is here. From one of the branches a %^WHITE%^noose%^GREEN%^ has been "
      "slung, and from the %^WHITE%^noose%^GREEN%^ hangs a %^RED%^strangled man%^GREEN%^. The man has a bizarre %^RED%^twisted grin%^GREEN%^ "
      "upon his %^BLUE%^cold blue lips%^GREEN%^."
      "%^RESET%^"
    );
    set_listen("default",
      "Your mind screams in panic and you fight the urge to flee!"
    );
    set_smell("default",
      "Blood, evil, death, decay, insanity - it's all here and waits for you to join."
    );
    set_items(([
	"bog":"%^GREEN%^The bog is murky and disgusting%^RESET%^",
	"quicksand":"There is bound to be patches of its somewhere.%^RESET%^",
	"paths":"The paths are small and twist through the bog.",
	"insects":"Insects buzz around your head in a frenzy.",
	"trees":"The trees are all half-dead and rotten and provide many odd "
	"shaped shadows to add to the darkened mood.",
	"vegetation":"There is certainly an abundance of that here.",
	"moss":"The moss grows everywhere and on everything. It is as though "
	"vegetation is the master of this area.",
	"tower":"%^RED%^Ahead of you to the north lies a massive tower-shaped billowing black column "
	"of mist. There appears to be no way into the swirling mass, but perhaps closer up you may find entrance into "
	"this mystical and evil place that must be the tower known only as Demongate.%^RESET%^",
	"man":"The man is long dead, yet his face still bears a twisted grin.",
	"grin":"The man's lips are contorted into a cold blue toothy grin.",
	"lips":"The man's lips are twisted into a secretive knowing and evil grin.",
      ]));
    set_exits(([
	"west": RPATH "f28",
	"south": RPATH "f26",
	"tower": "/d/dagger/marsh/tower/rooms/a1",
      ]));
   set_pre_exit_functions(({"tower"}),({"exitsa_fun"}));
/* changing to use set_search while I'm fixing things *Styx*  11/9/03
   set_search("default", "Your attention is drawn to the man who was hung here.");
   set_search("man", "The man's lips are twisted in a rather unnatural way.");
   set_search("lips", (: TO, "search_fun" :) );
nevermind, the add_action had been commented out already so I guess it's not meant to be here
*/
}

/* not being used...
int search_fun(string str) {
    int xyz;
    if(!str) {
	notify_fail("Search what?\n");
	return 1;
    }
    if(str != "lips") {
	notify_fail("Search what?\n");
	return 1;
    }
    if(CHECK1 != 0) {
	notify_fail("You find nothing this time.\n");
	return 1;
    }
   write("%^CYAN%^You search the hanged man's lips and find a key!%^RESET%^");
   tell_room(TO,"%^CYAN%^"+TPQCN+" finds something within the hanged man's lips!%^RESET%^",TP);
    xyz = new("/d/dagger/marsh/tower/obj/mistkey.c")->move(TP);
    if( (xyz == MOVE_NO_ROOM) || (xyz == MOVE_NOT_ALLOWED) ){
	tell_room(ETP, "%^CYAN%^The key is too heavy, and falls to the ground!");
	new("/d/dagger/marsh/tower/obj/mistkey.c")->move(ETP);
    }
    CHECK1 = 1;
    return 1;
}
*/

int exitsa_fun() {
// adding check for min level per discussions with others *Styx*  11/9/03, last change 1998
   if(TP->query_level() < 20) {
	tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ steps toward the tower and immediately staggers back, looking faint and too terror stricken to proceed.", TP); 
	tell_object(TP, "%^BOLD%^%^RED%^As you step toward the tower, you immediately stagger back feeling faint and terror stricken, unable to continue forward.", TP);
	return 0;
   }
   write("%^BOLD%^%^BLUE%^"
      "A low, deep howl of pure agony echos all around you as you pass "
      "through the clouded mist which seems to be the side of Demongate "
      "tower.\nYou fear you may never see the light of day again.%^RESET%^"
    );
    tell_room(TO,"%^BOLD%^%^BLUE%^A low, deep howl fills the marsh!", TP);
    return 1;
}
