#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("%^RESET%^%^ORANGE%^An old leatherbound book%^RESET%^");
   set_id(({"book","leather book","old book"}));
   set_short("%^RESET%^%^ORANGE%^An old leatherbound book%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a very old leatherbound book.  Gracefully written in calligraphy across the front is simply the word %^RESET%^Journal.");
   set_weight(0);
   set_read("%^BOLD%^BLUE%^%^Page 1\n%^RESET%^Building the pyramid has been the best thing we have done thus far."
"  It has given us a base to study our magics from and the pointed tip seems indeed pull the power of the weave into"
" it.  You cannot enter magically nor leave with the magic.  The weave is strong here and protects us from the"
" surprise visits the white mages use to like to give us.  With this new knowledge and the power of the"
" building, we will soon start our summoning experimentations."
"  Our earlier experimentations on the forest animals have gone well.  They have grown big and strong and I doubt"
" many will enter this forest to see exactly what it is we do here now.\n\n%^BOLD%^%^BLUE%^Page 2\n%^RESET%^That"
" damnable ranger of Mielikki has caught wind of our experiments and is trying to rally people to help him stop us."
"  I doubt many will be willing to come to his aid, this forest has been all but forgotten.\nOur first experiments"
" on portals have gone well however.  In the southern summoning room we have managed to open a portal to the land of"
" the leprechauns.  It didn't seem to have gone quite right however, as you can only enter the portal from this side."
"  We have lost two good magi of our twelve this way, Clarion and Sindar.  No matter, our experiments with the other"
" portal will start tommorow morning in the deepest summoning room we have.%^RESET%^");
   set_language("common"); 
}
