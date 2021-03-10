#include <std.h>
inherit OBJECT;

void create()
{
::create();
set_name("plaque");
set_short ("A bronze plaque");
set_long("%^BOLD%^YELLOW%^This plaque is dedicated to the many beings whom have contributed to this city and my insanity, by thought, word and deed.  Perhaps, just out of curiosity, you could read the plaque.%^RESET%^");
set_weight (1000);
set_value (0);
}
void init ()
{
::init ();
add_action("read", "read");
}
int read(string str)
{
if(str!="plaque")
return 0;
write("%^BOLD%^YELLOW%^No words of thanks, gratitude, nor honours could begin to thank each and every one of you for the help, love and laughter you have given me over the past seven months.  So I have set your names in stone and in my memory, with warm thoughts.  I wish to thank the following in no particular order: Pator, Tristan, Thorn, Firedragon, Grayhawk, Bane, Pegasus, Grazzt, Gilgamesh, Catriana, Diana, Thundercracker, Abolition, Littler and Morgan.\n
Without your help, this city, would never have been.  I would also like to thank Anna, Dakkon, David, Captc, Aramina and Wolverine, for the laughter and the patience.  The last being on my list, gets special kudos, to Aidan, with my thanks, heartfelt gratitude and (aw shucks) love, for introducing me to a place where my dreams have no limit, where the additional gray hair I receive, matches the additional laughter lines.%^RESET%^", TP);
tell_room(environment(TP), TPQCN+ "reads the inscription upon the bronze plaque and smiles,", TP);
return 1;
}
