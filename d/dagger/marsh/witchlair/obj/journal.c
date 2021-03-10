#include <std.h>
#include "../witchlair.h"
inherit OBJECT;

void create(){
   ::create();
   set_name("journal");
   set_id(({"book","old book","journal","diary"}));
   set_short("%^RESET%^%^ORANGE%^a small le"
"%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^her"
"%^BOLD%^%^BLACK%^bo%^RESET%^%^ORANGE%^und book");
   set_long("%^RESET%^%^ORANGE%^Rather nondescript,"
"the small tome bears a cover of aged, blackened "
"leather and has little marking beyond a trio "
"of small runes on the spine, quite primitive "
"in nature. The pages are strangely "
"%^BOLD%^%^WHITE%^crisp %^RESET%^%^ORANGE%^and near"
" newly-made condition. Only the first several "
"pages bear writing, and the rest has been left "
"blank. You could probably read it if you so wished.");
   set_value(200);
   set("language","common");
   set("read","%^BOLD%^%^GREEN%^Page I\n"
     "%^RESET%^%^CYAN%^After decades of research, I've "
"finally come across something of note. There is a tower,"
" deep within Dagger's infamous marshes, that rumor claims"
" is the home of an ancient lich and his servants...among"
" whom is said to be one of the beings I seek. I shall "
"investigate these rumors further, possibly after "
"enlisting the aid of a mercenary or some fool adventurer"
". One can never be too cautious.\n\n"
"%^BOLD%^%^GREEN%^Page II\n"
"%^RESET%^%^CYAN%^The legend is true! There is indeed one"
" of the creatures, those who lie beyond death's hand, "
"residing in the marsh. Unfortunately, he wasn't "
"particularly taken to peaceful conversation. I was forced"
" to destroy what I believed was my only hope of attaining"
" the state of vampirism - until the lich. I cannot "
"possibly state accurately enough how foolish I was to "
"steal his secrets, to take the knowledge I needed by "
"force - but it will pay off. There must be something "
"hidden within these old tomes. For the time being, however,"
"I've the matter of avoiding the lich's retribution to "
"deal with.\n\n"
"%^RESET%^%^CYAN%^I have come across quite the stroke of "
"luck; the lady of misfortune seems not to despise my existence. "
"I've discovered a clearing deep within the marshes, "
"evidently touched both by those who represent Sun and "
"Moon. The combination of their vile, holy influence seems"
" enough to stave off this accursed fog, which is in "
"fact the presence of the lich himself. The energy here"
" is sickeningly peaceful, but I will withstand it if it"
" means avoiding him long enough to find what I need "
"within this text.\n\n"
"%^BOLD%^%^GREEN%^Page III\n"
"%^RESET%^%^CYAN%^Decades further, and little progress."
" The goblins are capable thralls, true, but the methods"
" spoken of in these books have such ridiculous "
"requirements - how in the Abyss am I to acquire the heart "
"of a high priest of Hanali? Gathering the lifeblood of "
"a thousand souls may be the simplest course of action,"
" time-consuming as it may be, but I'm uncertain if asking"
" a boon of Grazzt (should the summoning actually work) "
"would truly be without reparation, as the ritual supposedly"
" promises.");
}
