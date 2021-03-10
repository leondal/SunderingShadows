#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init()
{
    ::init();
    add_action("read","read");
}
	
void create()
{
    ::create();
	
    set_name("profile");
    set_id(({"profile","area profile"}));
    set_short("%^BOLD%^%^MAGENTA%^Area profile");
    set_long("%^BOLD%^%^MAGENTA%^This is a general profile of this island. "+
    "It will tell you important information about it, if you read it.");
    set_weight(100000);
    set_value(10000);
}
	
int read(string str)
{
    if(!str || str != "profile") return  0;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!objectp(ETO)) return 0;
    tell_room(environment(TO),TPQCN+" reads the area profile!",TP);
    write("%^CYAN%^Area Name: %^RESET%^%^BOLD%^Eldebaro.\n");
    write("%^CYAN%^Area Type: %^RESET%^island.\n");
    write("%^CYAN%^Climate: %^RESET%^desert.\n");
    write("%^CYAN%^Location: %^RED%^<07'51>.\n");
    write("%^CYAN%^Difficulty Ranking: %^RESET%^high.\n");
    write("%^CYAN%^Monster Frequency: %^RESET%^random - can be high.\n");
    write("%^CYAN%^Suggested Level to Adventure Here: %^GREEN%^35+.\n");
    write("%^CYAN%^Sphere of Influence: %^BOLD%^%^BLUE%^Currently unknown.\n");
    write("%^B_CYAN%^%^YELLOW%^Please note: Eldebaro has been "+
    "completely revamped, as of December 2016. It is intended to "+
    "be a party adventuring area now. Use caution. You have been "+
    "warned.\n\nEnjoy,\nSaide.%^RESET%^");
    return 1;
}
	
