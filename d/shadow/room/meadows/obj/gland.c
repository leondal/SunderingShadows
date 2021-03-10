//updated by Circe 6/7/04 with new desc, lore, etc, by Shar
#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("gland");
   set_short("%^BOLD%^%^RED%^A glowing red object%^RESET%^");
   set_id(({"gland","fire beetle gland","object","red object","glowing red object"}));
   set_long("%^BOLD%^%^RED%^Upon close inspection of the object it appears"+
   " to be the gland from a fire beetle. It is constantly glowing with a"+
   " dull red glow.");
   set_lore(
@CIRCE
Its very rare to find a gland from a fire beetle that has not been ruptured.  Wizards and alchemists pay dearly for such a gland, it is said.  The glands seem to be used in the creation of spells and objects that rely on fire.  Its speculated that these glands also are used in the summoning of a fire elemental.  Followers of Kossuth are known to string the glands onto golden chain and wear them as a badge of courage.
CIRCE
   );
   set_property("lore difficulty",10);
   set_weight(1);
   set_value(200);
}

int move(mixed dest)
{
   int x;

   if(objectp(ETO))
      ETO->set_property("light",-1);
      x = ::move(dest);
   if(objectp(ETO))
      ETO->set_property("light",1);
   return x;
}

int save_me(string file) { return 1; }
