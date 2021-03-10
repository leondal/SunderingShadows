#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit OBJECT;

#define GOODGODS ({ "anhur", "helm", "lathander", "mielikki", "selune", "sune", "torm", "tymora", "tyr" })
#define HATERACES ({ "elf", "dwarf", "gnome", "halfling", "beastman", "firbolg", "voadkyn", "wemic" })

int started, guardscalled, lastattack, downtime, uptime;
void second_msg(string situation,object wasplace,object mytarget);

void create() {
   ::create();
   set_name("daroldralychaixxx");
   set("id", ({ "daroldralychaixxx"}) );
   set("short", "");
   set("long", "");
   set_weight(0);
   set_property("no animate",1);
   set_heart_beat(1);
   started = 0;
   downtime = 0;
   uptime = 0;
}

void remove_me() {
   if(objectp(ETO)) tell_object(ETO,"%^BOLD%^%^CYAN%^You finally relax upon departing the city.%^RESET%^\n");
   TO->remove();
}

void notify_me() {
   tell_object(ETO,"%^BOLD%^%^CYAN%^As you step into the city, your instincts kick in.  You can't help but feel a little wary in a place like this.%^RESET%^\n");
}

void init() {
   ::init();
   if(userp(ETO) && !started) { started = 1; call_out("notify_me",1); }
}

void heart_beat() { // reference: runs every 2sec by default.
   string myloc, mydeity, myrace;
   int myalign, usertally, i;
   object *presentusers;
   if(!objectp(ETO)) { remove_me(); return; }
   if(!userp(ETO)) { remove_me(); return; }
   if(!objectp(EETO)) { remove_me(); return; }
   if(!EETO->is_room()) { remove_me(); return; }
   if(ETO->query_true_invis()) { remove_me(); return; }

   usertally = 0;
   myloc = base_name(EETO);
   if(strsrch(myloc,"/d/underdark/daroldralych/rooms/") == -1) { remove_me(); return; }
   if(ETO->query_true_invis()) return; //skip the noisy for hidden imms plz.

// begin city interactions; based off race, deity and align to assume their reputation, until factions are done properly.
// this is not active yet; only ambience functionality is running. N, 8/12.
/*   myalign = ETO->query_true_align();
   mydeity = (string)ETO->query_diety();
   myrace = (string)ETO->query_race();

   if(myalign%3 == 1 || member_array(mydeity,GOODGODS) != -1 || member_array(myrace,HATERACES) != -1) {
   } */

// welcome to the city ambience section! Different echoes split by different areas. Easier to update as is not on NPCs/rooms.
   // fraction active chance: divide uptime tick speed by how many players here, eg 3 players, 1/3 frequency of uptick each = doesn't get too spammy.
   presentusers = all_living(EETO);
   for(i=0;i<sizeof(presentusers);i++) if(userp(presentusers[i])) usertally++;

   // 90 sec downtime, then another echo will go within 90 sec (one echo every 1.5-3min)
   if(downtime > 45) {
     if(!random(usertally)) uptime++;
   }
   else {
     if(!random(usertally)) downtime++;
   }
   if(roll_dice(1,45) > uptime) return; // chance to echo within 90sec max after the mandatory downtime is past.

   // if we get this far, it's echo time. Set both trackers back to zero and run an echo based on the area.
   uptime = 0;
   downtime = 0;

   if(strsrch(myloc,"temple") != -1) {
     switch(random(32)) {
       case 0..2:
         tell_object(ETO,"%^BLUE%^A rat-sized %^CYAN%^spider %^BLUE%^darts across your foot, its many legs moving furiously as it heads for the nearest wall.%^RESET%^");
         tell_room(EETO,"%^BLUE%^A rat-sized %^CYAN%^spider %^BLUE%^darts across "+ETO->QCN+"'s foot, its many legs moving furiously as it heads for the nearest wall.%^RESET%^",ETO);
       break;
       case 3..4:
         tell_room(EETO,"%^RED%^Those nearest to you bow their heads and murmur in hushed reverence, as from a darkened corner above emerges a massive hairy %^ORANGE%^spider%^RED%^.%^RESET%^");
         call_out("second_msg",1,"templespider",EETO,ETO);
       break;
       case 5..7:
         tell_object(ETO,"%^CYAN%^A priestess stalks imperiously past you, jostling you aside without even a backwards glance.%^RESET%^");
         tell_room(EETO,"%^CYAN%^A priestess stalks imperiously past "+ETO->QCN+", jostling "+ETO->QO+" aside without even a backwards glance.%^RESET%^",ETO);
       break;
       case 8..10:
         tell_room(EETO,"%^MAGENTA%^From a nearby chamber rises a chorus of voices, singing praises to the %^BLUE%^darkness%^MAGENTA%^.%^RESET%^");
       break;
       case 11..13:
         tell_room(EETO,"%^BOLD%^%^BLACK%^Nearby, someone or something screams in %^BOLD%^%^WHITE%^terror%^BOLD%^%^BLACK%^, before being abruptly silenced.%^RESET%^");
       break;
       case 14..16:
         tell_room(EETO,"%^GREEN%^Several black-clad %^MAGENTA%^priestesses %^GREEN%^walk past, muttering amongst themselves in low voices as their eyes dart about.%^RESET%^");
       break;
       case 17..18:
         tell_room(EETO,"%^MAGENTA%^One of the temple acolytes passes by, lighting incense in each alcove as she passes, and the coiling %^RESET%^smoke %^MAGENTA%^leaves you feeling momentarily "
"lightheaded.%^RESET%^");
       break;
       case 19..20:
         tell_room(EETO,"%^CYAN%^Floating on a drift-disc approaches the regally-clad matron of one of the city's houses, flanked on either side by her daughters.  They pay you not a moment's "
"heed in passing, eyes fixed forward as they depart.%^RESET%^");
       break;
       case 21..22:
         tell_room(EETO,"%^BLUE%^Towards you treads a heavily armored drow male, bearing a massive sword across his back.  His eyes remain directly ahead, never glancing to either side as he "
"strides past.%^RESET%^");
       break;
       case 23..24:
         tell_room(EETO,"%^ORANGE%^A gleeful priestess drags a whimpering %^GREEN%^goblin %^ORANGE%^in chains along behind her, the hapless creature no doubt destined for sacrifice somewhere in "
"the temple.%^RESET%^");
       break;
       case 25..26:
         tell_room(EETO,"%^GREEN%^You catch a %^BOLD%^%^GREEN%^hateful %^RESET%^%^GREEN%^glare from a priestess in passing, and the snake-headed whip at her belt snaps menancingly towards "
"you.%^RESET%^");
       break;
       case 27..29:
         tell_room(EETO,"%^ORANGE%^The %^BOLD%^%^BLACK%^cracked %^RESET%^%^ORANGE%^voice of an ancient priestess rises in cackling homage, her arms lifted toward the roof.%^RESET%^");
       break;
       case 30..31:
         tell_room(EETO,"%^MAGENTA%^A young priestess stumbles back into the room, pleading mercy from the circle of older priestesses that follow.  But none is to be had, as %^RED%^malice "
"%^MAGENTA%^fills their eyes and they lash out with their whips, striking at her prone form until she lies motionless.%^RESET%^");
         call_out("second_msg",2,"templedeath",EETO,ETO);
       break;
     }
     return;
   }
   if(strsrch(myloc,"square") != -1 || strsrch(myloc,"tower1") != -1 || strsrch(myloc,"east") != -1 || strsrch(myloc,"west") != -1 || strsrch(myloc,"north") != -1 || strsrch(myloc,"south") != -1 || strsrch(myloc,"outer") != -1) {
     switch(random(33)) {
       case 0..2:
         tell_room(EETO,"%^BLUE%^A beholder drifts slowly down the street, its massive central eye staring balefully forwards as crowds scatter to either side.%^RESET%^");
       break;
       case 3..5:
         tell_room(EETO,"%^RED%^A small group of duergar skulk down the street, muttering amongst themselves and eyeing others suspiciously as they pass.%^RESET%^");
       break;
       case 6..7:
         tell_object(ETO,"%^CYAN%^A young drow bumps into you in passing, and his eyes widen fearfully as if expecting punishment for the mis-step.  He skitters back and turns to flee up the "
"street.%^RESET%^");
         tell_room(EETO,"%^CYAN%^A young drow bumps into "+ETO->QCN+" in passing, and his eyes widen fearfully as if expecting punishment for the mis-step.  He skitters back and turns to flee "
"up the street.%^RESET%^",ETO);
         if(!random(5) && (((int)ETO->query_skill("perception")+roll_dice(1,20)) < 25)) call_out("second_msg",5,"theft",EETO,ETO);
       break;
       case 8..10:
         tell_room(EETO,"%^MAGENTA%^Darting through the crowds comes a tiny %^GREEN%^kobold%^MAGENTA%^, never remaining still quite long enough to be caught by the daggers and whips of scowling "
"drow as he dodges past and vanishes into the throng.%^RESET%^");
       break;
       case 11..13:
         tell_room(EETO,"%^BOLD%^%^BLACK%^The crowds part like water before the ranks of a noble house.  Grim-faced guards encircle a %^RESET%^%^MAGENTA%^glowing %^BOLD%^%^BLACK%^drift-disc, "
"carrying an ostentatiously dressed figure that could only be the matron of a ranked house.\n%^BOLD%^%^BLACK%^She floats slowly past, her imperious expression never faltering as the rest of her "
"entourage follow at a brisk pace.%^RESET%^");
       break;
       case 14..16:
         tell_room(EETO,"%^GREEN%^An %^RED%^agonised %^GREEN%^shriek rises from the depths of a nearby alleyway, quickly fading to a strangled gurgle that disappears beneath the bustling sounds "
"of the street.%^RESET%^");
       break;
       case 17..19:
         tell_room(EETO,"%^MAGENTA%^A pair of guards march by, glowering at the many 'lesser creatures' that give them a wide berth as they pass.  The storm-pikes gripped at their sides "
"%^BOLD%^%^WHITE%^s%^BOLD%^%^CYAN%^p%^BOLD%^%^WHITE%^a%^YELLOW%^r%^BOLD%^%^WHITE%^k %^RESET%^%^MAGENTA%^threateningly with static.%^RESET%^");
       break;
       case 20..21:
         tell_room(EETO,"%^CYAN%^The great bulk of an ogre hauls itself past, surrounded by such a miasma of stench that you can't help but feel a little %^GREEN%^nauseated%^CYAN%^.%^RESET%^");
       break;
       case 22..24:
         tell_room(EETO,"%^BLUE%^A group of drow priestesses stride confidently up the middle of the street, one of them lashing out with a snake-headed whip at an unfortunate goblin that "
"doesn't get out of her way fast enough.%^RESET%^");
         call_out("second_msg",2,"streetgoblin",EETO,ETO);
       break;
       case 25..26:
         tell_room(EETO,"%^ORANGE%^From somewhere above, a crossbow bolt streaks down to embed itself in the back of a passing drow.  She clutches feebly behind her in an attempt to dislodge it"
", a brief expression of %^MAGENTA%^agony %^ORANGE%^crossing her features as she stumbles and then falls to the ground, motionless.  A few wary glances dart her way, but noone dares stop to "
"check her.%^RESET%^");
       break;
       case 27..28:
         tell_room(EETO,"%^MAGENTA%^The vicious claws of a %^GREEN%^ravener %^MAGENTA%^click staccato on the stone ground as it stalks along the street, bearing an armored guard on patrol.  Its "
"sharp reptilian eyes regard the nearest creatures with a predatory hunger.%^RESET%^");
         if(random(2)) call_out("second_msg",2,"streetravener",EETO,ETO);
       break;
       case 29..31:
         tell_room(EETO,"%^GREEN%^An armored hobgoblin stomps past, half-leading and half-dragging a ragged human slave in chains behind him.%^RESET%^");
       break;
       case 32:
         if(!random(5)) {
           tell_room(EETO,"%^MAGENTA%^You turn your head to catch sudden sight of a breathtakingly beautiful male drow striding up the street, completely naked.  Nearly everyone on the street "
"seems to have likewise noticed him, and is standing and staring at him as he passes by.%^RESET%^");
           for(i=0;i<sizeof(presentusers);i++) {
             if(!SAVING_THROW_D->will_save(presentusers[i],-25)) { // I think the modifier is effectively the DC? On looking at the daemon? N, 8/12.
               tell_object(presentusers[i],"%^CYAN%^You are completely entranced by the gorgeous drow!%^RESET%^");
               presentusers[i]->set_paralyzed(roll_dice(3,4),"You are completely entranced by the gorgeous drow!");
             }
           }
         }
       break;
     }
     return;
   }
   if(strsrch(myloc,"alley") != -1) {
//distant screams, cowled stalkers, movement in the shadows, dying random, crossbow bolt overhead, goblin slinking past, someone brushing past at a run (theft), someone working over a body
//     switch
     return;
   }
   if(strsrch(myloc,"dock") != -1) {
     switch(random(33)) {
       case 0..2:
         tell_room(EETO,"%^BLUE%^The sounds of the bustling docks are underscored by the gentle lapping of water against the rocky shore.%^RESET%^");
       break;
       case 3..5:
         tell_room(EETO,"%^RED%^A small group of duergar skulk down the street, muttering amongst themselves and eyeing others suspiciously as they pass.%^RESET%^");
       break;
       case 6..7:
         tell_object(ETO,"%^CYAN%^A young drow bumps into you in passing, and his eyes widen fearfully as if expecting punishment for the mis-step.  He skitters back and turns to flee up the "
"street.%^RESET%^");
         tell_room(EETO,"%^CYAN%^A young drow bumps into "+ETO->QCN+" in passing, and his eyes widen fearfully as if expecting punishment for the mis-step.  He skitters back and turns to flee "
"up the street.%^RESET%^",ETO);
         if(!random(5) && (((int)ETO->query_skill("perception")+roll_dice(1,20)) < 25)) call_out("second_msg",5,"theft",EETO,ETO);
       break;
       case 8..10:
         tell_room(EETO,"%^MAGENTA%^Darting through the crowds comes a tiny %^GREEN%^kobold%^MAGENTA%^, never remaining still quite long enough to be caught by the daggers and whips of scowling "
"drow as he dodges past and vanishes into the throng.%^RESET%^");
       break;
       case 11..13:
         tell_room(EETO,"%^BOLD%^%^BLACK%^A hint of motion catches your eye as, further out across the lake's black surface, something large and heavy breaks the water only to resubmerge with "
"a %^RESET%^%^BLUE%^splash%^BOLD%^%^BLACK%^.%^RESET%^");
       break;
       case 14..16:
         tell_room(EETO,"%^GREEN%^An %^RED%^agonised %^GREEN%^shriek rises from the depths of a nearby alleyway, quickly fading to a strangled gurgle that disappears beneath the bustling sounds "
"of the street.%^RESET%^");
       break;
       case 17..19:
         tell_room(EETO,"%^MAGENTA%^A tall drow snarls curses at his team of slaves, as one drops something from the cart they're attempting to load.  The chained orc cowers back, but can't "
"avoid the %^RED%^cruel %^MAGENTA%^bite of the whip wielded with ruthless precision by the warehouse-keeper.%^RESET%^");
       break;
       case 20..21:
         tell_room(EETO,"%^CYAN%^The great bulk of an ogre hauls itself past, surrounded by such a miasma of stench that you can't help but feel a little %^GREEN%^nauseated%^CYAN%^.%^RESET%^");
       break;
       case 22..24:
         tell_room(EETO,"%^BLUE%^Down by the water's edge, a group of drow in common worker's garb go about hauling a fishing boat out onto the lake, ready for a day's labor.%^RESET%^");
       break;
       case 25..26:
         tell_room(EETO,"%^ORANGE%^From somewhere above, a crossbow bolt streaks down to embed itself in the back of a passing drow.  She clutches feebly behind her in an attempt to dislodge it"
", a brief expression of %^MAGENTA%^agony %^ORANGE%^crossing her features as she stumbles and then falls to the ground, motionless.  A few wary glances dart her way, but noone dares stop to "
"check her.%^RESET%^");
       break;
       case 27..28:
         tell_room(EETO,"%^MAGENTA%^The vicious claws of a %^GREEN%^ravener %^MAGENTA%^click staccato on the stone ground as it stalks along the street, bearing an armored guard on patrol.  Its "
"sharp reptilian eyes regard the nearest creatures with a predatory hunger.%^RESET%^");
         if(random(2)) call_out("second_msg",2,"streetravener",EETO,ETO);
       break;
       case 29..31:
         tell_room(EETO,"%^GREEN%^An armored hobgoblin stomps past, half-leading and half-dragging a ragged human slave in chains behind him.%^RESET%^");
       break;
       case 32:
         if(!random(5)) {
           tell_room(EETO,"%^MAGENTA%^You turn your head to catch sudden sight of a breathtakingly beautiful male drow striding up the street, completely naked.  Nearly everyone on the street "
"seems to have likewise noticed him, and is standing and staring at him as he passes by.%^RESET%^");
           for(i=0;i<sizeof(presentusers);i++) {
             if(!SAVING_THROW_D->will_save(presentusers[i],-25)) { // I think the modifier is effectively the DC? On looking at the daemon? N, 8/12.
               tell_object(presentusers[i],"%^CYAN%^You are completely entranced by the gorgeous drow!%^RESET%^");
               presentusers[i]->set_paralyzed(roll_dice(3,4),"You are completely entranced by the gorgeous drow!");
             }
           }
         }
       break;
     }
     return;
   }
   if(strsrch(myloc,"market") != -1) {
//nobility bartering, pickpocket (low), specific sale types?, someone bumped and executed, illithid trader, both guard echoes, crossbow echo, shouts of slave sales, someone hawking wares?
//     switch
     return;
   }
   if(strsrch(myloc,"tower") != -1 && strsrch(myloc,"tower1") == -1) {
//     switch
     return;
   }
   if(strsrch(myloc,"thief") != -1) {
//     switch
     return;
   }
   if(random(500) < 250) return; // halve the indoor echoes so people that are hanging around don't get spammed.
   if(strsrch(myloc,"library") != -1) {
     if(!present("zilvanna",EETO)) return;
     switch(random(3)) {
       case 0:
       tell_room(EETO,"%^CYAN%^A nearby goblin fumbles with a tome, nearly dropping it upon the stone floor.  Zilvanna raises her eyes, which narrow to %^RED%^crim%^BOLD%^s%^RESET%^%^RED%^on "
"slits %^CYAN%^as they settle upon the unfortunate slave, which suddenly utters a yelp of agony.  The creature's shaking fingers barely manage to keep hold of the tome, but apparent fear at the "
"consequences seem sufficient to keep from any further accidents, as it goes back to its tasks...");
       break;
       case 1:
       tell_room(EETO,"%^MAGENTA%^A tall, finely-garbed drow male strides in and approaches Zilvanna, who wordlessly hands across a curled %^RESET%^scro%^BOLD%^l%^RESET%^l %^MAGENTA%^into his "
"waiting hands, its surface marked by a single metallic %^ORANGE%^g%^YELLOW%^l%^WHITE%^yp%^RESET%^%^ORANGE%^h%^MAGENTA%^.  He turns on his heel and departs as abruptly as he came.%^RESET%^");
       break;
       case 2:
       tell_room(EETO,"%^ORANGE%^Zilvanna takes a moment to pass down one of the aisles formed by the shelves of books, checking each with painstaking care as she goes.%^RESET%^");
       break;
     }
   }
   if(strsrch(myloc,"inn1") != -1) {
     if(!present("bardess",EETO)) return;
     switch(random(5)) {
       case 0:
       tell_room(EETO,"%^CYAN%^The exotic performer takes up a graceful series of steps, changing direction without warning in a dance that is the more captivating for its unexpected twists "
"and turns.%^RESET%^");
       break;
       case 1:
       tell_room(EETO,"%^MAGENTA%^The dancer swishes her hips seductively in time to the music.%^RESET%^");
       break;
       case 2:
       tell_room(EETO,"%^ORANGE%^Picking up her pace, the dancer's performance moves through a complex series of dips and whirls.%^RESET%^");
       break;
       case 3:
       tell_room(EETO,"%^RED%^The dancer catches your eye as she sashays past, an alluring smile on her full lips.%^RESET%^");
       break;
       case 4:
       tell_room(EETO,"%^GREEN%^A brief quickening of the music and the performer moves likewise, her sinuous motions revealing curves of smooth flesh as the silks part her skin.%^RESET%^");
       break;
     }
   }
   if(strsrch(myloc,"arcanist") != -1) {
     if(!present("felyndra",EETO)) return;
     switch(random(5)) {
       case 0:
       tell_room(EETO,"%^CYAN%^The arcanist shifts lazily upon the cushions, not at all shy about the amount of skin she reveals in doing so.");
       break;
       case 1:
       tell_room(EETO,"%^MAGENTA%^Felyndra's %^RED%^v%^BOLD%^%^RED%^i%^RESET%^%^RED%^vid %^MAGENTA%^eyes fix onto you for a long moment, her intense gaze making you feel a little "
"uneasy.%^RESET%^");
       break;
       case 2:
       tell_room(EETO,"%^ORANGE%^With a motion of her fingers Felyndra beckons you forward, the %^BOLD%^%^WHITE%^je%^YELLOW%^w%^BOLD%^%^WHITE%^el%^BOLD%^%^MAGENTA%^r%^BOLD%^%^WHITE%^y "
"%^RESET%^%^ORANGE%^on her fingers sparkling with the motion.%^RESET%^");
       break;
       case 3:
       tell_room(EETO,"%^GREEN%^The seeress waves her fingers vaguely in the air before her, entertaining herself with sparkling %^CYAN%^m%^GREEN%^o%^CYAN%^t%^GREEN%^e%^CYAN%^s %^GREEN%^of "
"arcane light that dance back and forth before her.%^RESET%^");
       break;
       case 4:
       tell_room(EETO,"%^BLUE%^Felyndra yawns delicately, almost a picture of disinterest in her surrounds, save for the hawk-like sharpness of her gaze.%^RESET%^");
       break;
     }
   }

   if(strsrch(myloc,"bank") != -1) {
     if(!present("naddaer",EETO)) return;
     switch(random(2)) {
       case 0:
       tell_room(EETO,"%^CYAN%^Naddaer scrawls a series of figures upon a sheet of parchment, a look of intense concentration upon his face.");
       break;
       case 1:
       tell_room(EETO,"%^MAGENTA%^Coins clink together as Naddaer counts his way through another pouch.");
       break;
     }
   }
}

void second_msg(string situation,object wasplace,object mytarget) {
   int moneytake;
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(!userp(ETO)) return;
   if(!objectp(wasplace)) return;

   switch(situation) {
     case "templespider":
     tell_room(wasplace,"%^RED%^It blinks its many eyes at you, purposefully crawling across the roof until it slinks into another niche and becomes lost to view.%^RESET%^");
     break;
     case "templedeath":
     tell_room(wasplace,"%^MAGENTA%^Satisfied, they dissipate, the last of them giving the lifeless body a kick for good measure before she leaves.%^RESET%^");
     break;
     case "theft":
     moneytake = (int)ETO->query_money("gold");
     moneytake = moneytake/5; // 20% of their moneys will be lifted! This is pretty rare anyway.
     ETO->use_funds("gold",moneytake);
     moneytake = (int)ETO->query_money("platinum");
     moneytake = moneytake/5;
     ETO->use_funds("platinum",moneytake);
     tell_object(ETO,"%^CYAN%^It's only a moment later that you realise your purse has been considerably lightened.%^RESET%^");
     break;
     case "streetgoblin":
     tell_room(wasplace,"%^BLUE%^The creature falls to the ground and starts to choke and froth at the mouth, gasping its last breaths as not one of the priestesses spares it a backwards "
"glance.%^RESET%^");
     break;
     case "streetravener":
     tell_room(wasplace,"%^MAGENTA%^With lightning speed the ravener lunges, catching a nearby kobold slave in its razor-sharp teeth.  Its victim manages only a second's piercing squeal of pain "
"before it is abruptly silenced.  The ravener shakes its catch a few times, before growing bored of the lifeless body and dropping it unceremoniously to the ground, stalking onwards.%^RESET%^");
     break;
     default: break;
   }
}

int save_me(string file) { return 1; }