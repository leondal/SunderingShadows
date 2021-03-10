// Coral Sea Area - Created January 2009 by Ari

#include "/d/common/common.h"

// File Paths:
#define ROOMS "/d/islands/coralsea/rooms/"+
#define OBJ "/d/islands/coralsea/obj/"+
#define MON "/d/islands/coralsea/mon/"+
#define BASE "/d/islands/coralsea/base/"+

// For the Movie in coral_b1 
#define MASTERBEDROOM ({"%^BOLD%^%^WHITE%^You swim up close to the wall hanging and study it carefully.. %^RESET%^",\
"%^RESET%^%^CYAN%^A tall stone tower looms high upon a mountain top.  Ringing part of it is a hedge maze that follows the natural slope of the hill down toward where a small village stands.  %^RESET%^",\
"%^BOLD%^%^BLACK%^Beyond that, you can just make out a few farms that eventually give way to pristine forestland.  %^RESET%^",\
"%^RESET%^%^CYAN%^You notice that it is close to %^RED%^s%^YELLOW%^u%^RESET%^%^ORANGE%^n%^RED%^s%^YELLOW%^e%^RESET%^%^ORANGE%^t%^CYAN%^.  The tower's silhouette drapes most of the hedge in shadow. %^RESET%^",\
"%^BOLD%^%^BLACK%^As you watch, you see hunched creatures creeping outward from a hidden lair near the center of the maze. %^RESET%^",\
"%^RESET%^%^CYAN%^They stick to the shadows as they creep forward, inching their way toward a couple who stroll within the hedge.  The couple seems unaware of the looming danger",\
"%^BOLD%^%^BLACK%^A cloud passes before what's left of the sun, casting the whole hedge into darkness for a moment. %^RESET%^",\
"%^RESET%^%^CYAN%^The creatures don't wait.  They attack! %^RESET%^",\
"%^BOLD%^%^BLACK%^A blot of %^RED%^red %^BLACK%^stains the tapestry where the couple stood, slowly growing outward until the whole wall hanging seems completely covered in the %^RED%^blood red stain%^BLACK%^. %^RESET%^",\
})

// For the Movie in coral_b5
#define CHILDSROOM ({"%^BOLD%^%^WHITE%^You swim up close to the wall hanging and study it carefully.. %^RESET%^",\
"%^BOLD%^%^CYAN%^The scene is an open air market at the town square of a little village.  The occasion must be special, since ribbons festoon many of the booths and the people seem dressed in their finest clothing.%^RESET%^",\
"%^RESET%^%^CYAN%^Peasants with friendly faces pass each other, pausing now and again to stop and greet one another or shop. %^RESET%^",\
"%^BOLD%^%^CYAN%^In between the peasants you see the occasional colorful performer.  Each with painted faces and garish clothing.  They stroll through the market, entertaining the crowds.. %^RESET%^",\
"%^RESET%^%^CYAN%^One, a dog-faced man, pauses before a group of children and performs several sets of back flips and jumps. %^RESET%^",\
"%^BOLD%^%^CYAN%^A bit further off you see a juggler tossing fire brands into the air to the amazement of several young couples. %^RESET%^",\
"%^RESET%^%^CYAN%^A food hawker passes before you, pushing a cart filled with fresh meat pies.  You can almost smell the savory scent of the food as you continue to watch. %^RESET%^",\
"%^BOLD%^%^CYAN%^A young girl, no more then twelve summers of age and far better dressed then the surrounding peasants, stops the vendor and asks for a meat pie.  %^RESET%^",\
"%^RESET%^%^CYAN%^The vendor gives the girl a smile that doesn't reach his eyes.  He quickly looks over his goods, selecting out the best pie for the little girl who hands him a few silver coins in payment. %^RESET%^",\
"%^BOLD%^%^CYAN%^The girl then turns and makes her way down toward the dog-faced acrobat to watch his antics. %^RESET%^",\
"%^RESET%^%^CYAN%^As the other children spot her, they quickly disperse, leaving her as the only watcher. %^RESET%^",\
"%^BOLD%^%^CYAN%^With his audience all but gone, the dog-faced man performs a few more tricks then collects a silver from the girl and several coppers that the children threw his way earlier.  He then departs, you can almost see his relief. %^RESET%^",\
"%^RESET%^%^CYAN%^The girl remains where she is, the pie falling from her fingers and the small, tentative smile she had worn earlier falling from her lips.  She stands amongst the festivities, all alone.%^RESET%^",\
})

/* When part two is put into the game, the following should be 
added to the b5 movie.
"%^BOLD%^%^CYAN%^The girl frowns and her eyes glance upward.  She looks right at you.",\
"%^RESET%^%^CYAN%^You realize she's looking right at you even as a cold little smile lights her lips.  She suddenly looks very, very old. ",\
"%^BOLD%^%^CYAN%^Your eyes lock with hers.  %^RESET%^"Maybe you wont be so mean."%^CYAN%^ You see her say and then feel your body being pulled forward..."
"%^RESET%^%^CYAN%^You struggle, fighting against the pull, but its too late!  You're being drawn into the painting! ",\
"%^BOLD%^%^BLACK%^Nooooooooooooooooooooooooooooooooooooooooooooooo...... ",\

be sure to change the release message in the b5 room and to add commands to move the viewer to part two area. 

The whole world seems to tilt off center and you land with a heavy oof upon solid ground.  In the distance you can hear people talking and laughing.  Normal, every day sounds.  But sometime feels very, very wrong.
*/ 

/* Note stuff for future reference.

Things to consider, do we make it teleport proof?  How about a return portal?  Might be a good idea. 
To make that work, would need to have them pop into one room, and then walk into another room.  Could
have the dog-faced performer run up to them and tell them what's happening.  Give them their first part
of the quest.  Keep it simple so they have a fast way back.  What about the temple puzzle.  Could have 
the performer mention that its in the hedge maze's center but no one can get past the grimlins.
What are grimlins?  They could be what people who the little girl curses maybe?  Grimlins should 
probably cast darkness when they enter so that players don't use light to drive them off? Consider.
Eventually would like Kolsacara to have several quests to do. */
