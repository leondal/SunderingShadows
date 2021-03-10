// by Styx based on Stefano's ideas 3/2003

/* Notes regarding problems encountered with the traps.... *mutter*
unlock lock on iron bound door with key
str is lock.
The guard catches you trying to get into the back room and attacks!
Shop guard positions himself to block the east exit
The glyph on the door suddenly glows brightly!
The air around you begins to shimmer.
Glyph takes in a deep breath and screams the words, 'HARRNES RUCKONUS!!!'
You reel backward, momentarily stunned by the power of Glyph's spell!

> > > > What traps are you attempting to remove
-------------------------
As you trace the runes around the glyph they glow, albeit briefly.
What traps are you attempting to remove
> > Is one of the toggle traps causing this?
--------------
// something is causing "unlock iron bound door with key" be ignored entirely
// required "unlock lock on iron bound door with key"
// pick lock on iron bound door was also ignored, but pick iron bound door said it was unlocked

need an error message for no tools on attempts to pick in the /std/Object code
with trap for pick set on iron bound door - no response to pick at all

test an elemental trying to open the door, etc.

I'm not positive the toggle traps is exactly right yet so don't use this as a fully tested and correct example.  However, I think it's close for trapping so many actions and lock as well as the door - *Styx*  4/6/03
*/

#include <std.h>

#define POFF "/d/player_stores/poffices/"
#define SCITY "/d/shadow/room/city/"

#define PSTORE "/std/pstore"
// #define PSTORE "/realms/styx/pstore"
#define GUARD_D "/d/shadow/mon/guards/guard_d"

inherit PSTORE;

#define MAX_ITEMS 20

int set;
void toggle_glyph(int on);

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
// *********
// Note:  Need to keep the settings in shadow_br (owners, etc.) in sync with these
  set_owners( ({"stefano", "styx" }));
  set_drop_storage(POFF+"shadowstorage");
  set_drop_deposit(100);   // owner can specify, but setting static here
  set_items_allowed( ({ "letters" }) );
// ********* see note above
  set_name("post office");
  set_short("%^BOLD%^%^YELLOW%^S%^CYAN%^hadow %^YELLOW%^M%^CYAN%^essage "
	"%^YELLOW%^S%^CYAN%^ervice");
  set_long("%^BOLD%^%^YELLOW%^S%^CYAN%^hadow %^YELLOW%^M%^CYAN%^essage "
	   "%^YELLOW%^S%^CYAN%^ervice\n"
"%^RESET%^%^WHITE%^The arched doorway leads into a small, plush room with white plaster walls and a blue %^BLUE%^car%^CYAN%^p%^BLUE%^et.%^WHITE%^ A clerk sits at a new-looking desk with a bold, brightly coloured %^WHITE%^%^BOLD%^sign%^RESET%^ on it. Black iron %^ORANGE%^la%^BLUE%^n%^BLUE%^t%^ORANGE%^erns%^WHITE%^ on the walls light the room brightly, and there is an additional tall white candle on the clerk's desk. Next to the candle is an odd-looking upturned brass hearing trumpet. A guard stands in the back corner of the room, beside a sturdy looking iron-bound oak door with a %^MAGENTA%^g%^BLUE%^l%^MAGENTA%^yp%^BLUE%^h%^WHITE%^ on it. Higher up, in the middle of the back wall is a small metal %^BOLD%^%^BLACK%^flap%^RESET%^%^BLUE%^.%^WHITE%^ Two comfortable %^BLUE%^chairs%^WHITE%^ are provided for customers. There is a small metal trash %^BLUE%^can%^WHITE%^ by the door.%^RESET%^

There is a %^BOLD%^sign%^RESET%^ here.
"
  );
  set_smell("default", "The room is clean and smells of paper, ink, and wood polish.");
  set_listen("default", "You can hear the sounds of the street outside.");
  set_exits(([
                 "east": "/d/shadow/city/room/melistel4",
	"west": POFF+"shadow_br",
  ]));
// removing outside door until can figure out why the trap goes off opening it 4/14/03
//  set_door("arched door",SCITY+"nroad","east");  //no key here so people don't get locked in
  set_door("iron bound door", POFF+"shadow_br", "west", "po_shadow_key");
  set_open("iron bound door", 0);  // will default to this actually
  set_locked("iron bound door", 1, "lock");
  set_door_description("iron bound door", "%^ORANGE%^This sturdy looking oak door is bound with %^BOLD%^%^BLACK%^iron%^RESET%^%^ORANGE%^ and bears an impressive looking %^RED%^glyph%^ORANGE%^ across it.  A sign above the doorway spells out in various languages: %^RED%^PRIVATE%^RESET%^");

  	lock_difficulty("iron bound door",-80, "lock");
	set_trapped(({"unlock iron bound door", "open iron bound door",
	"pick iron bound door"}), ({"special", "special", "special"}),
	({"zap_me", "zap_me", "zap_me"}));

  	set = 1;
  set_items( ([
        ({ "trashcan", "trash can", "can" }) :  "Another facility thoughtfully provided by the Shadow Message Service. Please <trash paper> to help Keep Shadow Tidy.  %^BOLD%^Paper only please%^RESET%^.",
	"sconces" : "Each of the decorative silver sconces holds %^BOLD%^three white candles%^RESET%^ which cast a pleasant %^YELLOW%^soft yellow light %^RESET%^into the room.",
	"desk": "A sturdy new pine desk with some drawers down one side and a little square door on the other. There is a %^BOLD%^%^WHITE%^slender white candle%^RESET%^ on the desk, and next to it a strange looking upturned %^RESET%^%^ORANGE%^brass hearing trumpet%^RESET%^.  There is also a sign with some instructions on the desk.",
	({ "square door", "desk door" }) : "The square door in the side of the desk is approximately one foot high.",
	"drawers" : "The drawers contain some odds and ends, including dust, furballs, and the like.  There are also some dead mice, neatly wrapped in packets of paper.",
	"chairs" : "%^GREEN%^Comfortable padded chairs that seem to invite you to sit and read your messages.",
	({"lanterns", "lantern"}) : "%^BOLD%^%^BLACK%^The black iron lanterns beam brightly, filling the room with %^YELLOW%^light%^RESET%^.",
	"glyph" : ( (: TO, "glyph_desc" :) ),
	"runes" : "You can't read them, although you do notice the door around them seems somewhat polished.",
	({ "trumpet", "hearing trumpet" }) : "This looks like a %^ORANGE%^brass hearing trumpet%^RESET%^, about four inches tall, with the thin end disappearing into the desktop, as though the desk was listening to something.",
	"carpet" : "%^BLUE%^The serviceable blue carpet is clean, and soft enough to make walking into the store seem inviting.",
	"flap": "A small metal flap, about eight inches across, high up in the back wall.  It is much too small to get through.",

	"sign": (: TO, "signdesc" :),
   ]) );

}

void signdesc() {
   write("%^BOLD%^%^CYAN%^Welcome to the %^BLUE%^Shadow Message Service%^CYAN%^, the %^YELLOW%^quickest%^CYAN%^ and most %^RED%^reliable%^CYAN%^ way to get a message to friends and foes alike, at those times you cannot seem to get hold of them yourself!
");
   write("%^BOLD%^%^BLUE%^You may leave a written document for any person you know, or check to see if anyone has left a message for you.
%^BOLD%^The current charge for leaving a letter is a mere %^YELLOW%^"+TO->query_deposit()+" gold.

Use <help shop> to know how to use the service.");
}

string glyph_desc() {
  if(set)  return("%^RED%^A curly scripted %^RESET%^G%^RED%^lyp%^RESET%^h%^RED%^ drawn in red and edged in %^RESET%^silver%^RED%^ with runes around it.  It covers most of the centre of the door and seems to %^BOLD%^glow slightly.");
  else return("%^RED%^A curly scripted %^RESET%^G%^RED%^lyp%^RESET%^h%^RED%^ drawn in red and edged in %^RESET%^silver%^RED%^ with runes around it.  It covers most of the centre of the door.");
}

void reset() {
//   string clerk, guard;  changing around from strings to objects to see if it helps zap the bugs *Styx* 1/4/04, last change 4/13/03
   object who;
   object clerk, guard;
   ::reset();
/*
   guard = "/d/player_stores/mons/poguard_shad";
   clerk = "/d/player_stores/clerks/po_shadow";
*/
//   guard = find_object_or_load("/d/player_stores/mons/poguard_shad");
//   clerk = find_object_or_load("/d/player_stores/clerks/po_shadow");
/*  taking the guard out for a while to see if we can figure out if he's the cause of the bugs from other guards entering here  *Styx* 7/18/05
   if(!present("shop guard"))
      if(!objectp(environment(guard)))
	 guard->move(TO);
*/

   if(!present("shop clerk"))
	new("/d/player_stores/clerks/po_shadow")->move(TO);
//      if(!objectp(environment(clerk)))
// 	 clerk->move(TO);
/*
   if(!present("shop clerk"))
      if(!objectp(environment(find_object_or_load(clerk))))
	find_object_or_load(clerk)->move(TO);
*/
   switch(random(7)) {
      case 0:  tell_room(TO, "%^BOLD%^%^BLUE%^A %^RED%^leathery imp %^BLUE%^appears and scuttles back behind the side door of the desk.");
 	 break;
      case 1:  tell_room(TO, "You hear some scuffling noises behind the back wall, then an imp peeks out through the flap in the upper part of the back wall.");
 	break;
      case 2:  tell_room(TO, "%^BOLD%^%^BLUE%^You hear a small scrabbling sound from the desk, then it goes quiet.");
	break;
      case 3:  tell_room(TO, "%^BOLD%^%^BLUE%^A strange, deep voice with high pitched overtones starts to sing.  It sounds like it's coming from the %^RESET%^%^ORANGE%^hearing trumpet %^BOLD%^%^BLUE%^on the desk.\nThe words are rather indistinct but the song ends with what sounds like a dirty chuckle.");
	break;
      case 4:  tell_room(TO, "%^BOLD%^%^BLUE%^The door at the side of the desk falls open and you catch a glimpse of %^BLACK%^leathery wings %^BLUE%^inside before it is pulled shut again.");
	break;
      case 5:
	if(present("winata"))
	   tell_room(TO, "%^GREEN%^Winata pulls a %^ORANGE%^yellowed, oft-folded piece of paper %^GREEN%^from her pocket.\nUnfolding it carefully, she reads it and a wistful light comes to her eyes before she folds it back up and tucks it away again.");
	break;
      case 6:
	if(present("mail clerk", TO)) {
	   who = present("mail clerk", TO);
	   tell_room(TO, "%^BOLD%^%^BLUE%^"+who->query_cap_name()+" gets "
	     "a small paper packet from one of the drawers and pulls something small "
	     "and furry from it. The contents of the parcel are slid down into the "
	     "%^RESET%^%^ORANGE%^hearing trumpet %^BOLD%^%^BLUE%^and disappear.  A "
	     "strange squeal of delight sounds from inside the desk, followed by the "
	     "uncouth munching sounds of someone or something with very poor table manners.");
	}
	break;
      default:  break;
   }
}

void init() {
   ::init();
   add_action("trash_paper", "trash");
   add_action("sit_chair", "sit");
   add_action("arm_trap", "trace");
   add_action("read_sign", "read");
}


int read_sign(string str)
{
    if (str == "sign") {
        signdesc();
        return 1;
    }
    return 0;
}

void get_help(object badguy) {
   object watch;
   watch = new("/d/shadow/mon/guardnew");
   watch->move("/d/shadow/room/city/nroad");
//   GUARD_D->blow_horn(TO);
//   GUARD_D->call_watch(TO, badguy);
   watch->force_me("open arched door");
   watch->force_me("yell It's the post office!");
   watch->force_me("west");
   watch->force_me("block east");
}

int trash_paper(string str) {
   object ob;
   if(!str)
	return notify_fail("Trash what?\n");
   if(strsrch(str, "paper") == -1)
	return notify_fail("You start to trash the "+str+" and then realize the trash can is clearly marked for paper only.\n");
   if(!ob = present(str, TP))
	return notify_fail("You don't seem to have a "+str+".\n");
   tell_room(ETP, TPQCN+" drops a piece of paper into the trash can.\nA gout of %^BOLD%^%^RED%^f%^RESET%^%^RED%^l%^BOLD%^%^RED%^ame roars up%^RESET%^, consuming it immediately.", TP);
   tell_object(TP, "A gout of %^BOLD%^%^RED%^f%^RESET%^%^RED%^l%^BOLD%^%^RED%^ame roars %^RESET%^from the trashcan, consuming the paper even as you drop it in.");
   ob->remove();
   return 1;
}

int sit_chair(string str) {
   if(!str) {
     tell_object(TP,"Did you mean to sit in a chair?");
     tell_room(ETP,TPQCN+" seems to be trying to decide where to sit.",TP);
     return 1;
   }
   if(str == "chair" || str == "in chair") {
      tell_object(TP,"You sink easily into the padded chair and relax.");
      tell_room(ETP,""+TPQCN+" sinks easily into one of the padded chairs and relaxes.",TP);
      TP->command("pose sitting in a comfortable looking chair");
      return 1;
   }
   return 0;
}

int zap_me(string str) {
  object guard, glyph, spell, spell2;
//  if(str == "arched door")  return 1;  this didn't work to avoid the trap
  if( interactive(TP)) {
     if(guard = present("shop guard", TO)) {
       	   tell_room(TO,"%^YELLOW%^The guard catches "+TPQCN+" trying to get into "
              	"the back room and attacks!", TP);
      	   tell_object(TP,"%^YELLOW%^The guard catches you trying to get into the "
        	"back room and attacks!");
           guard->force_me("kill "+TPQN);
	   guard->force_me("block east");
     }
     tell_room(TO,"%^BOLD%^%^CYAN%^The glyph on the door suddenly glows brightly!");
// bugs for most spells without moving it to an object and having the object cast the spell
// this makes it so there is an environment for the caster
     glyph = new("/std/Object");
         glyph->set_name("glyph");
         glyph->move(TO);
     spell = new("/cmds/spells/d/_dispel_magic");
         spell->move(glyph);
         spell->use_spell(glyph, TP, 40, 100, "mage");
     spell2 = new("/cmds/spells/w/_powerword_stun.c");
         spell2->move(glyph);
         spell2->use_spell(glyph, TP, 40, 100, "mage");
// to be safe and make sure the spell objects will get wiped
     glyph->move("/d/shadowgate/void");
     glyph->remove();
     get_help(TP);
     toggle_glyph(0);
     set = 0;
     return 1;
     }
  return 1;
}

int arm_trap(string str)
{
	if(!str) return 0;
	if(str != "runes")
	{
		write("Tracing the "+str+" doesn't seem to have any effect except "
	    	"perhaps to make you look silly.");
        	tell_room(ETP, TPQCN+" traces the "+str+" and looks a little silly don't "
	    	"you think?", TP);
		return 1;
   	}
   	if( (member_array((string)TPQN,TO->query_owners()) == -1) && !TP->query_true_invis())
	{
    		if(random(20))
		{
			tell_object(TP,"%^YELLOW%^As you attempt to trace the runes, "+
			"the glyph shoots a lightning bolt at you!");
			tell_room(ETP,"%^YELLOW%^A lightning bolt shoots from the glyph as "
	   		+TPQCN+" touches the runes around it.",TP);
			TP->cause_typed_damage(TP, "torso", roll_dice(5, 10), "electricity");
			TP->add_attacker(TO);
			TP->continue_attack();
  			TP->remove_attacker(TO);
			return 1;
     		}
   	}
   	if(!set)
	{
      	tell_object(TP,"As you trace the runes around the glyph they glow, albeit briefly.");
	      tell_room(ETP,TPQCN+" traces the runes around the glyph and they glow briefly.", TP);
      	toggle_glyph(1);
      	set = 1;
   	}
	else
	{
      	tell_object(TP,"The glow from the glyph fades as you trace the runes.");
      	tell_room(ETP,TPQCN+" traces the runes around the glyph and the "+
		"glow from it fades.",TP);
      	toggle_glyph(0);
      	set = 0;
   	}
   	return 1;
}

void toggle_glyph(int on)
{
   	if(on)
	{
   		if(TO->is_this_trapped("unlock iron bound door"))
		{
			TO->remove_trap("unlock iron bound door");
		}
		if(TO->is_this_trapped("open iron bound door"))
		{
			TO->remove_trap("open iron bound door");
		}
		if(TO->is_this_trapped("pick iron bound door"))
		{
			TO->remove_trap("pick iron bound door");
		}
		set_trapped(({"unlock iron bound door", "open iron bound door",
		"pick iron bound door"}), ({"special", "special", "special"}),
		({"zap_me", "zap_me", "zap_me"}));
		return;
   	}
	else
	{
    		if(TO->is_this_trapped("unlock iron bound door"))
		{
			TO->remove_trap("unlock iron bound door");
		}
		if(TO->is_this_trapped("open iron bound door"))
		{
			TO->remove_trap("open iron bound door");
		}
		if(TO->is_this_trapped("pick iron bound door"))
		{
			TO->remove_trap("pick iron bound door");
		}
	}
      return;
}
