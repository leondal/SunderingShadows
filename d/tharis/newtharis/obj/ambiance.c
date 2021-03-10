#include <std.h>
#include <magic.h>
inherit OBJECT;

void notify_me();

void create() {
   ::create();
   set_name("tharisambiance");
   set_id(({"tharisambiancexxx"}));
   set_short("");
   set_long("");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(1);
}

void init() {
   ::init();
   if(userp(ETO)) call_out("notify_me",1);
}

void heart_beat() {
   string roomname;
   int i, playershere, chance;
   object *userobs;
   if(!objectp(ETO)) { TO->remove(); return; }
   if(!userp(ETO)) { TO->remove(); return; }
   if(!objectp(EETO)) { TO->remove(); return; }

   roomname = base_name(EETO);
   if(strsrch(roomname,"/d/tharis/newtharis/") == -1) {
     tell_object(ETO,"%^BLUE%^You can't help but relax just a little on leaving the confines of Tharis City.%^RESET%^");
     TO->remove();
     return;
   }

// here is the place to put eventual reactions to the area -> eg/ a fight may call guards
//   if(sizeof(ETO->query_attackers())) do_guard_stuff;

// now let's run ambiance! This is just to make the city feel lively.
   userobs = all_living(EETO);
   if(!sizeof(userobs)) return; // noone's here? This shouldn't trigger but just to be safe.
   playershere = 0;
   for(i=0;i<sizeof(userobs);i++) {
     if(userp(userobs[i])) playershere++; // playershere = makes it go off less often if there's more players potentially hitting emotes.
   }

   if(strsrch(roomname,"rooms/east") != -1) {
     chance = 240*playershere;
     if(random(chance)) return;
     switch(random(100)) {
       case 0..10:
       tell_room(EETO,"%^CYAN%^Grubby children go running past, shrieking and yelling as they chase one another.%^RESET%^");
       break;
       case 11..15:
       tell_room(EETO,"%^ORANGE%^A sharp shriek goes up from somewhere nearby, before the sound is abruptly strangled.%^RESET%^");
       break;
       case 16..20:
       tell_room(EETO,"%^YELLOW%^A brief ruckus comes from down a nearby alleyway, before going suddenly and unsettlingly silent.%^RESET%^");
       break;
       case 21..25:
       tell_room(EETO,"%^BOLD%^%^BLACK%^A shadowy figure slips between the buildings and vanishes from view, further down the road.%^RESET%^");
       break;
       case 26..30:
       tell_room(EETO,"%^BOLD%^%^BLACK%^A shadowy, cowled figure passes you, confident strides carrying him swiftly elsewhere.%^RESET%^");
       break;
       case 31..40:
       tell_room(EETO,"%^GREEN%^A soft breeze picks up, bringing with it the stench of the slums.%^RESET%^");
       break;
       case 41..50:
       tell_room(EETO,"%^BLUE%^You catch a glimpse of a rodent as it scampers along the ground beside a nearby building, and finds a place to hide.%^RESET%^");
       break;
       case 51..60:
       tell_room(EETO,"%^BOLD%^%^BLUE%^A gang of young, rough-looking youths strut along the street, peering about with hard expressions and arrogant sneers.%^RESET%^");
       break;
       case 61..70:
       tell_room(EETO,"%^CYAN%^An old, unsteady man wanders up the street, extending a hand to beg for alms as he goes.%^RESET%^");
       break;
       case 71..80:
       tell_room(EETO,"%^BLUE%^You hear them before you see them. A group of guards stomp past, keeping a vigilant watch on the area, their armor clacking in time with their footfalls.%^RESET%^");
       break;
       case 81..90:
       tell_room(EETO,"%^BOLD%^%^BLACK%^A small child jostles past you and goes running off into an alleyway. You quickly check that your coins are still in your pocket!%^RESET%^");
       break;
       default:
       tell_room(EETO,"%^MAGENTA%^A short, furtive figure concealed beneath hood and cloak slinks along the street, constantly looking to either side as if fearful. It turns a corner and vanishes from sight.%^RESET%^");
       break;
     }
     return;
   }
   if(strsrch(roomname,"rooms/elf") != -1) {
     chance = 240*playershere;
     if(random(chance)) return;
     switch(random(90)) {
       case 0..10:
       tell_room(EETO,"%^CYAN%^The torn remains of a poster rustle past, carried by a stray gust of wind.%^RESET%^");
       break;
       case 11..20:
       tell_room(EETO,"%^ORANGE%^A hollow crack echoes down the street, probably a piece of masonry coming loose.%^RESET%^");
       break;
       case 21..30:
       tell_room(EETO,"%^BOLD%^%^BLACK%^A shadowy figure slips between the buildings and disappears from view, further down the road.%^RESET%^");
       break;
       case 31..40:
       tell_room(EETO,"%^GREEN%^A soft breeze picks up, stirring the leaves of the small plants growing up through the walls and buildings.%^RESET%^");
       break;
       case 41..50:
       tell_room(EETO,"%^BLUE%^You catch a glimpse of a rodent as it scampers along the ground beside a nearby building, and finds a place to hide.%^RESET%^");
       break;
       case 51..60:
       tell_room(EETO,"%^YELLOW%^A brief ruckus comes from the west, further distant in the slums, before fading again to return the area to silence.%^RESET%^");
       break;
       case 61..70:
       tell_room(EETO,"%^CYAN%^The wind picks up briefly, causing the shutters on a nearby window to bang against the wall.%^RESET%^");
       break;
       case 71..80:
       tell_room(EETO,"%^BLUE%^You hear them before you see them. A group of guards stomp past, keeping a vigilant watch on the area, their armor clacking in time with their footfalls.%^RESET%^");
       break;
       default:
       tell_room(EETO,"%^MAGENTA%^A gentle trill of birdsong carries from somewhere above the nearby rooftops.%^RESET%^");
       break;
     }
     return;
   }
   if(strsrch(roomname,"rooms/square") != -1 || strsrch(roomname,"rooms/fountain") != -1) {
     chance = 90*playershere;
     if(random(chance)) return;
     switch(random(100)) {
       case 0..5:
       tell_room(EETO,"%^CYAN%^A well-dressed woman bustles past, multiple bags of shopping on each arm.%^RESET%^");
       break;
       case 6..10:
       tell_room(EETO,"%^BOLD%^%^BLACK%^A small child jostles past you and goes running off into the crowd. You quickly check that your coins are still in your pocket!%^RESET%^");
       break;
       case 11..15:
       tell_room(EETO,"%^YELLOW%^You can't help but jump as a stall-keeper at the stall beside you raises his voice to shout! Fine wares! Great bargains! Come see!%^RESET%^");
       break;
       case 16..20:
       tell_room(EETO,"%^BOLD%^%^GREEN%^A nearby stall-keeper gives you a greasy smile and motions to his wares.%^RESET%^");
       break;
       case 21..30:
       tell_room(EETO,"%^BLUE%^A squadron of guards stride past, and the citizens are quick to get out of their way. Unlike the rest of the people here, they seem to have no trouble clearing a path.%^RESET%^");
       break;
       case 31..35:
       tell_room(EETO,"%^BOLD%^%^MAGENTA%^A sharp wail goes up, a few stalls over, as a child starts throwing a great tantrum. His mother looks terribly embarassed as she hurries away, the youngster in tow.%^RESET%^");
       break;
       case 36..40:
       tell_room(EETO,"%^GREEN%^A young, scruffy woman glances warily side to side, slinking through the crowd and disappearing. You're sure you saw her filch something from that stall!%^RESET%^");
       break;
       case 41..45:
       tell_room(EETO,"%^BOLD%^%^BLUE%^A gang of young, rough-looking youths strut into the area and peer about with hard expressions and arrogant sneers. The rest of the citizenry give them a wary berth as they move on through the bazaar.%^RESET%^");
       break;
       case 46..50:
       tell_room(EETO,"%^MAGENTA%^A rowdy group of young men, probably nobles, laugh and banter as they push through the crowds.%^RESET%^");
       break;
       case 51..55:
       tell_room(EETO,"%^BOLD%^%^BLACK%^A shadowy, cowled figure passes you, confident strides carrying him swiftly elsewhere. All eyes seem to be on him as he passes, despite his unassuming appearance.%^RESET%^");
       break;
       case 56..60:
       tell_room(EETO,"%^MAGENTA%^A raven-haired woman passes, openly bearing the symbol of Lord Shadow upon a pendant at her throat. Several citizens murmur a few words and bow as she passes, making at least a show of respect.%^RESET%^");
       break;
       case 61..65:
       tell_room(EETO,"%^ORANGE%^A ragged youth is grabbed forcefully by one of several passing guards, and dragged unwillingly down the street, even as he loudly proclaims his innocence to anything and everything.%^RESET%^");
       break;
       case 66..70:
       tell_room(EETO,"%^BOLD%^%^CYAN%^Leaping and shouting like a thing possessed, a madman staggers down the road. Most ignore him, though some push him away forcefully until he moves on.%^RESET%^");
       break;
       case 71..75:
       tell_room(EETO,"%^ORANGE%^Just off to the side, a dirty street-child stands by a fruit cart, staring longingly at the produce being sold. The stern glare of the stall-keeper seems enough, however, to keep him at bay. Eventually he gives up and runs off.%^RESET%^");
       break;
       case 76..80:
       tell_room(EETO,"%^CYAN%^Well-dressed and impeccably groomed, you can't help but be surprised to see a young man a few feet away surrepticiously lift the purse of another citizen. He doesn't even break stride as he slips it into his pocket and vanishes into the crowds.%^RESET%^");
       break;
       case 81..85:
       tell_room(EETO,"%^GREEN%^A well-groomed merchant speaks in hushed tones with a nearby stall-keeper, attempting to haggle a price down to his likings.%^RESET%^");
       break;
       case 86..90:
       tell_room(EETO,"%^BLUE%^Voices are raised as haggling at a nearby stall becomes more of an argument. The irate customer comes storming past, muttering imprecations to the air.%^RESET%^");
       break;
       default:
       tell_room(EETO,"%^ORANGE%^The crowd thickens momentarily as several groups converge and attempt to pass all at once, jostling you about.%^RESET%^");
       break;
     }
     return;
   }
   if(strsrch(roomname,"rooms/tunnel") != -1) {
     chance = 360*playershere;
     if(random(chance)) return;
     switch(random(60)) {
       case 0..10:
       tell_room(EETO,"%^CYAN%^The silence here bears an almost tangible weight that makes you feel uncomfortable.%^RESET%^");
       break;
       case 11..20:
       tell_room(EETO,"%^ORANGE%^A shadowy form slinks along further up the winding tunnel and is lost to view.%^RESET%^");
       break;
       case 21..30:
       tell_room(EETO,"%^BOLD%^%^BLACK%^You hear a few muffled noises from the city far above.%^RESET%^");
       break;
       case 31..40:
       tell_room(EETO,"%^GREEN%^You only see the shadowy form at the very last moment, as it flits past you and vanishes again, almost one with the shadows.%^RESET%^");
       break;
       case 41..50:
       tell_room(EETO,"%^BLUE%^A furtive figure slinks closer, keeping well to the other side of the dimly lit tunnel as it passes you and quickly disappears into the darkness.%^RESET%^");
       break;
       default:
       tell_room(EETO,"%^YELLOW%^The echo of distant shouting sounds down the length of the winding tunnel.%^RESET%^");
       break;
     }
     return;
   }
   if(strsrch(roomname,"sewers") != -1) {
     chance = 360*playershere;
     if(random(chance)) return;
     switch(random(90)) {
       case 0..10:
       tell_room(EETO,"%^CYAN%^Liquid drips from somewhere in the darkness above.%^RESET%^");
       break;
       case 11..20:
       tell_room(EETO,"%^ORANGE%^A rodent (or something else?) screeches somewhere further along the sewers.%^RESET%^");
       break;
       case 21..30:
       tell_room(EETO,"%^BOLD%^%^BLACK%^You catch a glimpse of movement further up the sewer tunnel.%^RESET%^");
       break;
       case 31..40:
       tell_room(EETO,"%^GREEN%^A waft of choking stench filters past you, even worse than the usual smell of the filth here.%^RESET%^");
       break;
       case 41..50:
       tell_room(EETO,"%^BLUE%^A furtive figure slinks closer, keeping well to the other side of the sewer tunnel as it passes you and quickly disappears into the darkness.%^RESET%^");
       break;
       case 51..60:
       tell_room(EETO,"%^YELLOW%^The clang of a distant gate or sewer cover echoes along the tunnel.%^RESET%^");
       break;
       case 61..70:
       tell_room(EETO,"%^CYAN%^You hear a sudden surge and crash of water somewhere in the distance.%^RESET%^");
       break;
       case 71..80:
       tell_room(EETO,"%^BLUE%^A low hiss sounds off to the side, and gleaming eyes briefly peer back at you from the darkness.%^RESET%^");
       break;
       default:
       tell_room(EETO,"%^MAGENTA%^Scratching and scrabbling sounds from a small drainage grate nearby.%^RESET%^");
       break;
     }
     return;
   }
}

int save_me(string file) { return 1; }

void notify_me() {
   if(objectp(EETO)) {
     if(!EETO->query_property("indoors")) {
       tell_object(ETO,"%^BOLD%^%^BLACK%^As the looming shadow of the great sky fortress falls across you, you can't help but grow a little more cautious.%^RESET%^");
       return;
     }
   }
   tell_object(ETO,"%^CYAN%^As you set foot into the City of Shadows, you can't help but grow a little more cautious.%^RESET%^");
}