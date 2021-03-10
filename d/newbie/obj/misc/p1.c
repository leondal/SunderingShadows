#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("%^RESET%^%^ORANGE%^Beginners pamphlet%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is a small little pamphlet with all sorts of useful information written within that you may need to get started.  Simply <%^YELLOW%^read pamphlet%^RESET%^%^ORANGE%^> to get started.%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^A helpful pamphlet%^RESET%^");
   set_id(({"helpful pamphlet","pamphlet","paper"}));
   set_weight(0);
   set_read("Here is a list of basic commands that you will want to know to get started:\n\n%^YELLOW%^score"
"%^RESET%^\n-Score is probably one of your most valuable commands.  This will tell you what your characters status"
" is, including health, hunger, thirst, and condition.  Simply type <%^YELLOW%^score%^RESET%^> to try it."
"\n\n%^YELLOW%^i%^RESET%^\n-I is short for inventory.  This will list for you all of the things that your character"
" is carrying.  Typing <%^YELLOW%^i%^RESET%^> will do this for you.\n\n%^YELLOW%^look%^RESET%^\n-Look is another"
" great tool to use.  This will allow you to look around the room that you are in and will return the description,"
" exits as well as who and what else is in the room with you.  You can also use look to look at individual items"
" or people.  Just type <%^YELLOW%^look%^RESET%^> to see the room, or <%^YELLOW%^look sign%^RESET%^> to look at"
" a sign for example, or look person/race name to look at a person.. for example: <%^YELLOW%^look elf%^RESET%^>."
"\n\n%^YELLOW%^peer%^RESET%^\n-Peer is a great command to see what is ahead of you before you walk into a room."
"  You can simply <%^YELLOW%^peer west%^RESET%^> or actually specify a direction, for example <%^YELLOW%^peer east"
" 5%^RESET%^>\n\n%^YELLOW%^wear/wearall%^RESET%^\n-The wear and wearall commands will allow you to wear things such"
" as clothing, jewellery, shields, shoes, sheaths, ect.  By typing <%^YELLOW%^wearall%^RESET%^>, you will"
" automatically wear anything in your inventory that can be worn.  By typing a specific item, for example"
" <%^YELLOW%^wear shield%^RESET%^>, you will only wear the shield.\n\n%^YELLOW%^wield%^RESET%^\n-Wield is"
" another important one.  This will allow you to wield weapons primarily, but you can wield just about"
" anything you can carry.  As with most other commands, the syntax is simple, you type weild and then specify"
" what it is you wish to wield.  For example <%^YELLOW%^wield sword%^RESET%^> will make you wield your weapon."
"  You can specify the weapon number as well, so wield sword 1, or wield sword 2, ect.\n\n%^YELLOW%^Unwear/unwield"
"%^RESET%^\n-Unwear and unwield work just like wield and wear, but they allow you to remove an article of clothing"
" or unwield a weapon.\n\n%^YELLOW%^search%^RESET%^\n-Search allows you to search either an area or an individual"
" item or object in the room.  For example, if you do <%^YELLOW%^search%^RESET%^>, your character will do a"
" general search in the room.  However, if you type, for example <%^YELLOW%^search bushes%^RESET%^>, your"
" character will specifically search the bushes in the room.\n\n%^YELLOW%^get/get all%^RESET%^\n-Get is a great"
" command to know.  This allows your character to pick up things it sees laying around.  For instance, if you"
" see something like this:\n\n   The path here twists and turns along the mountainside.  A few bushes line the area"
" and the overhanging trees provide ample shade.\n%^ORANGE%^You smell the fresh scent of pine\n%^GREEN%^Sounds of"
" the forest echo around you\n%^BOLD%^%^MAGENTA%^a few pine cones is here\n\n%^RESET%^-You could pick up the pine"
" cones by simply typing <%^YELLOW%^get pinecones%^RESET%^>.  Get all works the same way, except your character"
" will pick everything in the room it sees.\n\n%^YELLOW%^offer/offerall%^RESET%^\n-Both of these commands come in"
" useful for getting rid of unwanted items.  For instance, if you type <%^YELLOW%^i%^RESET%^> and see that you have"
" an empty bottle you do not want, you can simply type <%^YELLOW%^offer bottle%^RESET%^> to get rid of it."
"  <%^YELLOW%^offerall%^RESET%^> does the same thing, but offers everything that is on the floor in the room"
" instead.\n\n%^YELLOW%^bury%^RESET%^\n-Bury is a useful tool to get rid of corpses after you are through with"
" a battle.  Simply type <%^YELLOW%^bury corpse%^RESET%^> to dispose of it and get a little bit of health back.");
}