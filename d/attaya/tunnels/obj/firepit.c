//Coded by Lujke

// This fireplace is actually a secret quest timer that is used to make
// sure that the Treasury Quest cannot be completed more than once in a
// SG day. This should hopefully prevent players hearing someone else work 
// out the password then coming back after the room resets to claim the 
// quest themselves. Bah. I wish I didn't have to think like a Munchkin.


#include <std.h>
#define DAY 24000
inherit OBJECT;

int last_completion;
int query_last_completion();
void set_last_completion(int time);


void create() {
    ::create();
    set_name("firepit");
    set_id( ({"firepit","quest timer","timer","large firepit"}) );
    set_short("%^BOLD%^%^RED%^A l%^RESET%^%^RED%^a%^BOLD%^%^RED%^rge"
             +" f%^YELLOW%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^ep%^BOLD%^"
             +"%^BLACK%^i%^RED%^t%^MAGENTA%^");
    set_weight(2000000);
    set_long("%^RESET%^A %^BOLD%^%^RED%^l%^RESET%^%^RED%^a%^BOLD%^"
            +"%^RED%^rge f%^YELLOW%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^ep"
            +"%^BOLD%^%^BLACK%^i%^RED%^t%^RESET%^ in the centre of the"
            +" room. The %^BOLD%^%^RED%^f%^YELLOW%^i%^RESET%^%^RED%^r"
            +"%^BOLD%^%^RED%^e%^RESET%^ blazes and crackles away"
            +" constantly, filling the room with %^BOLD%^%^RED%^h"
            +"%^RESET%^RED%^ea%^BOLD%^%^RED%^t%^RESET%^.");
    if (last_completion>time()){last_completion = time()-DAY;}
}

int query_last_completion()
{
  return last_completion;
}

void set_last_completion(int time)
{
  last_completion = time;
}
