#include <std.h>
#include "../theater.h"
#define TYPES ({"young fair complexioned woman","elderly noble male","middle aged female","young swarthy complexioned male","elderly noble female","middle aged male","swarthy complexioned female","fair complexioned male","young noble child","young half-elven male","young half-elven female","middle aged half-elf male","middle aged half-elf female","dwarven male","dwarven female","female gnome","male gnome","female halfling","male halfling"})
inherit OBJECT;

int j;
string str, TYPE;
void create(){
      object obj; 
	::create();
	j = random(sizeof(TYPES));
      TYPE = TYPES[j];
   	set_name("corpse");
      set_id(({"corpse","body","special_corpse"}));
      set_short("%^BOLD%^%^BLACK%^A corpse of a "+TYPE+"%^RESET%^");
      set_long("%^BOLD%^%^BLACK%^The withered husk of a "+TYPE+" is tied to"+
	" the rope.  Most of the flesh and tissue of the corpse has been striped"+
	" away, as if used for food.  What flesh remains now has become home to "+
	"the %^WHITE%^maggots%^BLACK%^ that crawl across and under the dried "+
	"flesh.  This corpse is still wearing the tattered rotting remains "+
	"of the clothing once worn.  Matted sections of hair cling to "+
	"the corpse's scalp, covered with dust and dried blood.  The corpse's"+
	" face is frozen with a look of horror and pain, its mouth hanging open"+
	" as if captured in the middle of a scream.  A %^GREEN%^sickening sweet"+
	" rotting %^BLACK%^aroma radiates off in waves from the corpse. \n");
      set_value(0);
      set_weight(150);
     }



