// Coral Sea Area - Created January 2009 by Ari
// Cliff Notes & Walk Through for Imms 

/* First Things First:  Thanks!
This is my first project so I'm sure there will be a number 
of things that could be done better.  But hopefully it's at 
least reasonable.  I would like to thank the following 
wizards for their aid & patience along with their willingness 
to go over what I did and help me figure out where things 
went wrong: Ares, Circe, Dinji, Garrett, Loki, Lujke, 
Nienne, Octothorpe and Tsera.   Thanks guys! */

/* Second: Level Range
This area is designed for levels 20-23 with the expectation 
that some classes will be able to challenge it as early as 
18th level and that players may continue to explore it 
through 26th level or so.  A large mob (Aysu  created by 
Circe) will attack players when they attempt to enter the 
area if they are over 26th level.  Likewise, the dock will 
warn players under 18th from entering as well.  This is 
to try and ensure that the area doesn't become a gold or xp
cycle area, as well as to give it a set time frame during 
which leveled characters should explore.  A sign/warning is
on the dock telling players the suggested level range. 
Note that this area will likely be handled easiest by 
either a priest or a ranger and that the item rewards are 
somewhat geared toward those two classes, though other
classes can find gold and other goodies that may be of 
benefit. */

/* Third: What to Expect & Encounter
Players will encounter the following creatures within this
area: 
  * Undead Pirates: These are part of the crew from the ship 
wreck that is located at the bottom of the area. They are 
set to auto attack anyone that gets near them and are evil 
and aggressive. These guys have coralscape armor and each
of the three weapons available in the area.  They drop a
percentage of the time any of the above.
  * Undead Captain Zeralquin (Sub-Boss): Zeralquin has the 
compass that is needed in order to reach the golden 
chest and fight the main boss.  He has kelpwrap leather 
class armor, the only place that this can be obtained.
  * Coral_Fish: These are fish, there are 7 or 8 choices of
appearance, although they're all the same basic fish. 
They have a low grade poison bite (I researched fish that
could be found near a coral reef and have poison defenses
for authenticity.)  They are non aggressive but will swarm
if they are in the room with an attack.
  * Coral_Eel (Main Boss): The eel has electric shock and 
a fairly nasty bite.  She can stun and squeeze the life 
out of you. On death she shocks her attacker and stuns 
them for a few rounds.  She holds the golden chest in her
inventory and will drop it when she dies.  She also drops 
a earring that has a few charges of tongues upon it.
She cannot be stolen from.
  * Grizon the Privateer: This is the quest giver and he will 
be located at one of the local bars in Pirate Cove.  His job 
is to give out the quest and send players to fetch. He also 
reveals the main story line and rewards players for 
successfully returning the good chest, or may attack players 
who get greedy and return the broken chest.
 * Coral_Ayzu: Created by Circe who approved it having
 its home here, Ayzu is the 'forest ghost' of the area.
 Designed to attack level 30+ characters, she has a small
 chance of showing up on most exiting features and 
 dragging a highbie character off to her lair.  As it is
 a punishment, she doesn't have rewards, and she -only-
 takes the offending player off.  The rest of the party 
 can find the tunnel that takes them to Aysu's chamber.
 The good news is that there is an escape that sends you 
 to the surface in her room so you can escape.
  * Sharks: These guys only turn up like the fish and 
pirates.  They are aggressive and will try to eat players.  */

/* Fourth: Treasure, Prizes & Stuff!
The general theme of this area is to produce gear that
stuns, though said stuns are very short in duration:

Weapons:
* belaypin.c  This is by far the coolest of the weapon rewards 
and is carried by pirates and the captain.  There is a minor 
rate of drop so we shouldn't see a lot surfacing though if 
players want one they would just need to cycle a while.  A +2 
medium club with several nifty specials including a stunning and 
damage special. Also comes equipped with a lightning touch 2/day 
use command. 
* pikeofthedepths.c  A nice little polearm of +3 range to fill 
in a spot that was lacking, two specials that either do damage 
or stun. Dropped by Pirates.
* sharkskinwhip.c  A +3 whip that, like the polearm has a minor 
damage special or a stunning (choking) special. Dropped by 
Pirates or possibly Captain.
* coral_ale.c  This doesn't drop but is an impressive weapon 
for Grizon when/if attacked.  It is meant to make this otherwise 
less then productive member of society a bit fierce. 

Armor:
* coralscape.c  Banded mail +2 that has been covered in living 
coral.  Has a special on-hit that may stun the striker for a 
short period of time as coral dust flies into their eyes. 
Dropped by the priates on occasion. 
* kelpwrap.c  Only dropped by the captain.  +2 Leather armor 
that allows a player 2/day to cast either 'detect invisibility' 
or 'invisibility'. 

Objects:
* coral_goodchest.c  The chest that the eel drops. It can be 
broken into and if a player does so, then it will auto spawn a 
badchest. 
* coral_badchest.c  What is spawned if players get greedy and 
peeks inside the good chest.
* coral_compass.c  What is needed to put into the bulkhead's 
design to open the passage to the eel and golden chest.  The 
captain has this in his inventory and drops it when he is killed.
* coral_prize.c  A single file with multi-change-describe stuff 
that can be found by searching the kelp or ground of the sea.  
These are treasures of 300-400 gold value.  There is about a 
10% chance in around 30 rooms, so most players should find
four or five. 
* coral_earring.c  A prize from the Eel. Casts tongues 2d2 
uses. More of a utility/fun thing then anything else.
* coral_brasskey.c  Needed to reach the captain's cabin and 
'fresh air' while undersea.  Can be found on the masthead 
located in the tower's balcony by searching the clam shell.

*/

/* Fifth: The Area Layout & General To-Dos
This area is designed to be stand alone, however it references 
and will eventually lead to a higher level area.  The basic 
story is that a few years ago the Emerald Kipper, a two masted
schooner, was returning from a diplomatic mission to the south 
and got caught in a major storm just off the coast of Pirate 
Cove.  Amongst their cargo they were carrying a golden chest, a 
gift from the southern kingdom to the north with a group of 
official documents and titles and such.  All political garbage 
that will do the player no good but would, in the right hands, 
provide a certain Privateer with some rather nice resources. 

Enter Grizon.  Grizon is the Privateer and he hires a player to 
go fetch the golden chest.  He tells them to fetch it back 
without opening it and he'll pay them 25k gold as a reward (and 
100k xp).  He cautions them several times not to open it and 
then sends them on their way.

Players then have to locate the coral reef dock and go for a 
swim.  Below they will find the following areas:

* Dock (coraldock.c): This is the top of a large coral shelf. It 
is somewhat submerged so players are really standing in the 
water or, at least, treading water.  A large trough of flat 
space has been carved out of the top where the wrecked ship 
plowed into it.  The trough provide a calm area where one can 
tether a ship to a metal pole that was driven into the coral 
shelf some time ago.  RP wise, the pole also has the various 
warning signs and such.

* Open Sea (coralsea1.c): This is basically swimming on the 
surface.  No mobs spawn but there are ways to reach it from 
below and if mobs swim into the area they swim into the area. 
Players swim around this area until they figure out the 'dive' 
spots which are hidden.

* Under Water (coralsea2.c): This area is the first part that is 
encountered by the players.  Here, mobs begin to turn up.  
Either pirates or fish.  This is near the coral shelf Players 
can swim around this small area and either dive, or if they're 
clever find a spot they can knock a large chunk of coral free 
and swim into the tower.

* Deep Water (coralsea3.c): This is deep underwater, near the 
bottom of the sea. Here you can also find mobs and the first 
searchable-for-loot spots.  Digging around in the rubble at the 
bottom of the sea, which are describe as old sub-buildings that 
served the tower, you can find a bit of treasure in the form of 
either shipwreck cargo or ancient remains.  Also here you can 
break open the wooden side of the shipwreck to reach a air 
chamber, the captain's quarters. (No Teleport)

* Ancient Tower (coraltower.c): The tower is an ancient 
structure upon which a coral shelf has grown.  Within, you will 
find four rooms of major note.  The first is the daughter's 
bedroom.  Here you can find the "portal hanging" that will 
eventually take you to part two (the island's past).  For now, 
it simply has a movie that shows the "past" before the island 
sank into the sea.  The master bedroom is also located on the 
upper floor and has a second hanging which shows another part of 
the past, and hints that trouble is afoot.  It also shows the 
tower a bit more before it sank.  This also comes in the form of 
a movie.  The third interesting room is the master bedroom's 
balcony which is one of the locations you can use to reach the 
kelp bed.  You also find the key to the captain's quarter here 
by searching the masthead's clam shell.  The final room of 
interest is downstairs and this is the dining room which leads 
you out to the shipwreck. (No Teleport)

* Kelp Maze, Lower Bed (coralmaze2.c): Growing up from the 
remains of the tower's old hedge maze, the kelp bed can be 
reached by lifting the canvas of the ship or by lifting the 
netting on the tower's balcony.  This hides the front half of 
the ship and the Captain with the key to reach the Eel.  Mobs 
can be found here in the form of fish, pirates and the sharks 
that attack injured players. (No Teleport)

Kelp Maze (coralmaze1.c): This area is mostly designed for just 
swimming around in, it includes a single room that allows you to 
surface back toward the dock as well as allowing you to go back 
into the tower by lifting the net.  You cannot lift the canvas 
to get back into the ship. (No Teleport)

* Shipwreck Front Half (coralwreck.c): The ship is in two parts, 
the front half is lost in the kelp bed and players need to 
locate it in order to find the captain and get their compass 
which is the key to reaching the eel and golden chest.  The 
crowsnest is where the captain is hanging out and there is only 
one way to enter it, though several ways to exit.  (No Teleport)

* Shipwreck Rear Half (coralwreck.c): The rear half of the ship, 
this is where two major things are found.  First, the only location 
in the area besides the surface rooms where air can be found.  
This air pocket is located in the Captain's Quarters and is meant 
to provide players with a way to recover if their water breathing
goes out. Though considering they need a key or to break some wood, 
it wont be easy to reach.  The second interesting area requires the 
captain's compass in order to make a path through the bulkhead
and into the cargo hold.  Once players have defeated the captain 
and gotten the compass they insert the compass into the painting 
on the bulkhead and this opens a portal.  Going through the portal 
brings you to the cargo hold and searching the cargo hold allows 
you to find the eel who, upon death, coughs up the gold chest.  
(No Teleport)

* Gas Vent (coraltunnel.c): This natural vent in the earth issues
some harmless gas that creates lots of pretty bubbles to annoy
players with.  The end of this little tunnel is Aysu's lair, and 
the pathway down is only slightly hidden, so players can 
find it.  However, low level characters (25th and lower) will 
get warning messages that things might be a bit dangerous for 
them and maybe they should turn back.  The bubbles might 
even push them back!  If someone makes it to Aysu they'll be
auto attacked (including those shunted there for being too high
of level in the area.)  Aysu is mean, she's based off Genoslu and
can do nice little tricks like stun and heal-self.  So its not a fun
fight, though I imagine someone will challenge her intentionally.
Anyway, a vent if available to escape through so no one is 
trapped in the room.  Though there is a tiny delay on the vent
before you're allowed to exit.  Still, it should be enough to help
players survive if they're not ready to fight her.  (No Teleport)
*/

/* Sixth: Special Information
I've added several features and risks to this area to make the 
rewards that you can get (especially the 100k xp and 25k gp
quest reward) worth the effort.  Here's what they are:

Panic! Bad stuff happens. Your cleric dies, your magic runs out, 
whatever.  You're deep under water and the only way out is a long 
swim through kelp or rushing water.  You're almost out of air and
your lungs are burning.  That sucks.  You panic, and in a fit of 
urgency cast off your weighty treasure sacks and swim for the 
surface.  So you didn't get treasure this time, but oh the air 
tastes so sweet.  Players may type "surface" at any point in the 
coralsea2, coralsea3, coralmaze1 and coralmaze2 areas.  This 
causes them to drop all sacks and be instantly moved to one of
the surface locations with a mild stun for their troubles. The 
tower, wreck and surface areas do not have panic buttons.

Aysu, Terror of the Seas!  Written by Circe for a plot I ran 
as an Avatar, Aysu is the "forest ghost" or "Drizill" of this 
area.  Designed to keep highbies out and leave the area open 
for midrange players.  Anyone between level 26 and level 30 
will have a chance upon entering a room to have Aysu show 
up, grab them and drag them to a random surface room.  Her 
jaws do a little damage, but nothing major.  Players over 30th 
level who go swimming here will find the Aysu is hungry and 
she will take players to her lair where she'll fight them!  
Considering she has sharks for pets and she's as tough as 
Genoslu, this isnt a great place to be.  Thankfully, your 
friends can find you, if you can last that long.  Aysu attacks 
in any location that is underwater. 

Lowbies Not Wanted! The area's dock warns players who 
are of 18th level or lower that they should turn back as they
might get themselves killed if they continue.  As the area
has +2 and +3 gear, I don't want to encourage players to come 
here at 14-15th level but to keep the area designed for a 
specific range it is balanced for.

Silence! Yes, sound travels well under water, but you don't have 
any oxygen to cause sound now do you?  No.  If you have water 
breathing, then you can pull oxygen from your new gills into 
your blood stream directly.  If you don't have water breathing 
then you're not going to waste that precious air on speaking 
out loud.  So here, you cannot speak.  "say", "yell", "whisper" 
have all be discontinued in the underwater areas.  Use emote to
pantomime to your friends, find the one room that has air or 
surface if you want to talk.  

Pocket of Air!  Besides the surface, there is one room in the 
area (coral_w1) which has an air pocket.  This isn't easy to 
reach once you get to the maze, but for the first part of the
adventure and providing you have the key or search well, 
the air pocket gives you a chance to recover.

No Teleport!  Coralmaze1, Coralmaze2, Coraltower, Coraltunnel
Coralsea3 and Coralwreck, along with all their inherits, comes
with no-teleport feature.  Players can teleport into the surface 
rooms and into the first "area" under water, but beyond that 
they need to go through the area as normal.  I'm not thrilled 
with the all or nothing, but after discussions with testers it 
would seem a necessary evil. */