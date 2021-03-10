/* by Styx for Shadow jail 3/31/02, converted to /std/ inheritable 8/2005
* - food and water force-feeding based on Crystal's code in Alliance dungeon,
* - added real food & water slipped under the door for unbound people
* - jail_main sets property of player age when put in, release after MAXTIME
* - Figure out how to make the guard yell shut up in there if someone yells?
* - Tried using GoThroughDoor to handle the check_released but couldn't get it working if they were being drug.  So, the main jail code has on init to handle that.
** set max jail time in player age (online time) for auto-release
** is in seconds so 10800 = 3 hrs. (could easily take 6-10 if they mostly
** idle and their time isn't all counting)
** 12/20/02 - doubled it and also made it 24 hrs. for people on the wanted list
**   after someone got early release that shouldn't have - hopefully those won't
**   get out sooner than 3 RL days now, if then and those involved with the RP
**   will follow up and check on them regularly
** 2/12 - reduced playtime max to 1hr, and overall RL time to 2hrs; slim playerbase
** isn't giving much option for escape/rescue/etc. Not fun to sit around. N.
* Lowered jail and wanted times again - Octothorpe 6/6/16
*/
/* **********************************************************************
*  Notes regarding use:
*	can put extra messages in reset OR overload do_messages()
*     if banned list is to be captured rather than killed, need to use
*  set_release_to(filename) so they will be dumped outside the area with guards

************************************************************************* */

#define JAILFOOD "/d/common/obj/special/jail_food"
#define JAILDRINK "/d/common/obj/special/jail_drink"

#define MAXTIME 1200
#define MAXWANTED 3600

#include <std.h>
#include <daemons.h>

inherit VAULT;

void set_jail_location(string loc);	// must match the jail room's location
void set_jail(string filename);		// main jail filename for the area
void set_release_to(string filename);	// main jail or outside the city

void __Feed_em();
void __CheckRelease();
void do_messages();
void __ThrowOut();

int company;
string JailLoc, JailFile, ReleaseLoc;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("no phase",1);  // to keep the psion phase from letting them bypass the door
   set_property("no teleport",1);
   set_indoors(1);
   set_name("jail");
   set_short("A basic inheritable jail cell");
   set_long("A basic inheritable jail cell");
   set_listen("default","You can hear the rats scurrying around.");
   set_smell("default","A nauseating smell rises from the filthy, damp "
      "floor.");
}

void set_jail_location(string loc) {   JailLoc = loc;  }
void set_jail(string filename) { JailFile = filename; }
void set_release_to(string filename) { ReleaseLoc = filename; }

int query_jail_location() {  return JailLoc; }
int query_jail() {  return JailFile; }
int query_release_to() { return ReleaseLoc; }

void init() {
   ::init();
}

void reset() {
   ::reset();
   do_messages();
   __CheckRelease();
   if(random(2))
	__Feed_em();
}

void do_messages() {
   switch(random(24)) {
     case 1..3 : break;
     case 4 : tell_room(TO,"%^BOLD%^%^BLUE%^You swear you just heard voices "
	"coming from behind you!  When you look, nobody is there.  Maybe it "
	"was just %^RESET%^insanity%^BOLD%^%^BLUE%^ sinking in.");  break;
     case 5 : tell_room(TO,"%^YELLOW%^A very %^ORANGE%^LOUD THUD %^RESET%^"
		"%^YELLOW%^against the door startles you!\n\n%^CYAN%^"
		"After a few moments things seem quiet again.");     break;
     case 6 : tell_room(TO,"%^BOLD%^%^RED%^You hear blood curdling screams "
		"of agony from nearby.\n\n%^RESET%^They slowly weaken and "
		"subside into moans and, finally, eerie silence.");   break;
     case 7:  tell_room(TO,"%^BOLD%^%^CYAN%^The chill from the damp stone "
		"begins to drain your strength and will.");	     break;
     case 8 : tell_room(TO,"%^ORANGE%^A large rat scurries across the bed "
	"and disappears through a small crack in the wall.\n");      break;
     case 9 : tell_room(TO,"%^BOLD%^You hear footsteps outside but it's "
                "probably just the guard.\n");                       break;
     case 10: tell_room(TO,"%^MAGENTA%^You hear yelling somewhere outside."
                "  Might someone hear you if you yelled back?\n");   break;
     case 11: tell_room(TO,"%^YELLOW%^You hear the guard snoring loudly.  "
                 "Geez that is annoying!!\n");                       break;
     case 12: tell_room(TO,"%^GREEN%^That green slime on the walls draws "
                 "your attention.  Is it moving or are you beginning to "
                 "lose your sanity?\n");                             break;
     case 13: tell_room(TO,"%^BOLD%^%^CYAN%^A bit of a breeze blows in "
                 "somehow and relieves the stench a little.\n");
                                                                     break;
     case 14: tell_room(TO,"%^RED%^You notice some of the dark spots on "
                 "the walls look like blood.  Now you realize some people "
                 "have probably been beaten or even killed in here.\n");
                                                                     break;
     case 15: tell_room(TO,"%^CYAN%^A guard peers in through the window "
                 "grate and seems to be checking his list.\n");      break;
     case 16: tell_room(TO,"%^BOLD%^%^BLACK%^Droplets of a dirty liquid "
		"of some sort drip from the ceiling.\n");           break;
     case 17: tell_room(TO,"%^ORANGE%^You swear you just heard voices "
	"coming from behind you! When you look, nobody is there.\n"); break;
     case 18: tell_room(TO,"A %^BOLD%^feathery pillow%^RESET%^ and a nice "
		"%^BOLD%^soft blanket%^RESET%^ would be nice right about "
		"now, wouldn't they?\n");        		     break;
     case 19: tell_room(TO,"%^YELLOW%^The faint scent of warm, delicious-"
	"smelling food wafts through the air as the jailer sits down to "
	"enjoy a meal someone brought in.\n"); 		             break;
     case 20: tell_room(TO,"%^CYAN%^You hear the jailer arguing with "
	"someone outside, and then a door slams shut.\n");           break;
     case 21: tell_room(TO,"%^RED%^A %^RESET%^squealing%^RED%^ disturbance "
	"rises from the pit and a %^BOLD%^%^BLACK%^fu%^RESET%^%^ORANGE%^z"
	"%^BOLD%^%^BLACK%^zy %^ORANGE%^brown %^BOLD%^%^BLACK%^rode%^RESET%^"
	"%^ORANGE%^n%^BOLD%^%^BLACK%^t %^RESET%^%^RED%^scurries out, "
	"disappearing into a pile of %^RESET%^straw%^BOLD%^%^BLACK%^.\n");                 								     break;
     case 22: tell_room(TO,"You hear some shouts and drunken laughter "
	"from somewhere outside.  You can almost remember what it felt "
	"like to be... %^BOLD%^%^MAGENTA%^free%^RESET%^.\n");        break;
     default:  break;
   }
   return;
}

void __CheckRelease() {
   int i, j, jailed, jailtime, jailrealtime;
   string name, *wantedlist;
   object *inven;
   inven = all_living(TO);
   j = sizeof(inven);
   for(i=0;i<j;i++)
   {
      if(!userp(inven[i])) continue;
      if(!jailed = inven[i]->query("jailed_age")) continue;
      jailtime = (int)inven[i]->query_age() - jailed;
      name = inven[i]->query_name();
      //now, unless they are removed from the wanted list somehow
      //they would sit in jail until the play time they have since
      //getting jailed is greater than MAXWANTED - I am changing this - Saide
      //keep track of the time that they were jailed - in order to see if it has been longer
      //than that if so release them
      if(!intp(jailrealtime = (int)inven[i]->query("jailed_time")))
      {
        inven[i]->set("jailed_time", time());
        jailrealtime = (int)inven[i]->query("jailed_time");
      }
      if((AREALISTS_D->is_wanted(inven[i],JailLoc,TO) && (jailrealtime + MAXWANTED) < time()) && jailtime < MAXTIME) continue;
      //if(jailtime < MAXTIME)  	continue;
// if gets past all that, then release them
      "/cmds/avatar/_note.c"->cmd_note("ckpt "+inven[i]->query_name()+
	   " was %^RED%^TIME released from the "+JailLoc+" jail.%^RESET%^");
      AREALISTS_D->remove_prisoner(inven[i], JailLoc, TO);
      AREALISTS_D->remove_wanted(inven[i], JailLoc, TO);
      log_file("player/city_jails", "Prisoners - "+JailLoc+":  "+inven[i]->QCN+" was "
	   "out of the "+JailLoc+" jail on "+ctime(time())+".\n");
      tell_object(inven[i],"%^BOLD%^Some rough looking guards enter and "
         "drag you out of the cell to freedom.\n");
      tell_room(TO,"%^BOLD%^Some rough looking guards enter and drag "
          +inven[i]->query_cap_name()+" out of the cell.\n",inven[i]);
      if(query_release_to()) {
	inven[i]->move(ReleaseLoc);
      } else {
	inven[i]->move(JailLoc);
      }
      if(inven[i]->query_bound()) {
         inven[i]->set_bound(0);
         tell_object(inven[i],"%^BOLD%^The guard removes your bonds.");
      }
      inven[i]->force_me("look");
      continue;
   }
}

void __Feed_em() {
   int i, j, temp1, temp2, max;
   object *inven;
   inven = all_living(TO);
   j = sizeof(inven);
   for(i=0;i<j;i++) {
	if(!userp(inven[i])) 		continue;
	if(inven[i]->query_true_invis())  continue;
        max = inven[i]->query_formula();
        temp1 = inven[i]->query_stuffed();
        temp2 = max/6;
      if(!random(10)) {
         tell_room(TO, "%^GREEN%^You notice the green slime on the "
            "walls giving off a sickening smell.\n");
         tell_object(inven[i], "Suddenly you have sharp, stabbing pains "
	    "in your stomach and begin to %^BOLD%^%^MAGENTA%^vomit uncontrollably.");
         tell_room(TO, inven[i]->query_cap_name()+" doubles over in pain and "
            "begins to %^BOLD%^%^MAGENTA%^vomit %^RESET%^uncontrollably.  "
            "The sight and stench are sickening.",inven[i]);
         inven[i]->cause_typed_damage(inven[i], "torso", roll_dice(4, 4), "untyped");
         inven[i]->use_stamina(20);
      }
      if(!(temp1 < (temp2*3))) continue;
      if(!inven[i]->query_bound()) {
        if(!present("jail food")) {
          tell_room(TO,"A guard slides some food through a slot in the "
             "door.");
          new(JAILFOOD)->move(TO);
        }
        continue;
      }
      inven[i]->add_stuffed(500);
      tell_object(inven[i],"Some rough looking guards enter and feed you "
         "some %^ORANGE%^dark grainy substance %^RESET%^that might be old bread.");
      tell_room(TO,"Some rough looking guards enter and feed "+inven[i]->QCN+
	 " some %^ORANGE%^dark grainy substance %^RESET%^that resembles "
	 "old bread.",inven[i]);
      continue;
   }
   for(i=0;i<j;i++) {
      if(!userp(inven[i])) continue;
      if(inven[i]->query_true_invis())  continue;
      max = inven[i]->query_formula();
      temp1 = inven[i]->query_quenched();
      temp2 = max/6;
      if(!(temp1 < (temp2*3))) continue;
      if(!inven[i]->query_bound()) {
        if(!present("water")) {
          tell_room(TO,"A guard slides some water through a slot in the "
            "door.");
          new(JAILDRINK)->move(TO);
        }
        continue;
      }
      inven[i]->add_quenched(500);
      tell_object(inven[i],"Some rough looking guards enter and have "
        "you drink some stale water from a beat-up waterskin.");
      tell_room(TO,"Some rough looking guards enter and have "
        +inven[i]->QCN+" drink from a beat-up waterskin.",inven[i]);
      continue;
   }
}
