//Many thanks to Shar for creating this item :)
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
#define MAXUSES 25
int uses;
string place;

void create(){
        ::create();
        set_name("necklace of insect bane");
        set_id(({ "necklace", "necklace of insect bane", "insect" }));
        set_short("%^BOLD%^%^BLACK%^Necklace of %^GREEN%^Insect Bane%^RESET%^");
        set_obvious_short("A jet and bloodstone necklace");
        set_long(
@AVATAR
%^BOLD%^%^BLACK%^Jet beads have been strung together to form the base of this necklace. The
image of a locust in flight hangs from the center of the necklace.  The
locust figurine is very detailed, the main body is crafted out of
%^GREEN%^bloodstone%^BOLD%^%^BLACK%^.  %^WHITE%^Mother of pearl %^BOLD%^%^BLACK%^has been inlaid to form the wings of the
locust, giving them an iridescent quality.  The way the inlays are shaped,
you almost think they spell out something.

AVATAR
        );
        set("read",
@AVATAR
%^BOLD%^%^GREEN%^With this charm, the bite and sting of nature's insects will never bother
you again.  With a simple %^BOLD%^%^BLACK%^begone%^GREEN%^, you shall be free of the
pesky creatures.

AVATAR
        );
     set("language","common");      set_weight(4);
        set_value(750);
        set_lore(
@AVATAR
The Necklace of Insect Bane was crafted by a necromancer, who often visited
swamps but hated that he had to deal with mosquitoes and flies.  With his
charm, he could safely travel about, without the pesky insects bothering
him.

AVATAR
        );
        set_property("lore difficulty",5);
        set_type("ring");
        set_limbs(({ "neck" }));
        set_size(2);
        set_property("enchantment",0);
}
void init(){
    ::init();
    add_action("pestbegone","begone");
    if(uses > 24){
        set_value(0);
    }
}
int pestbegone(string str){
        if(TP->query_bound() || TP->query_unconcious() ||
TP->query_paralyzed() ||
TP->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
    }
 
    if(query_worn()){
    if(uses < MAXUSES){
            tell_room(ETP,"%^BOLD%^%^GREEN%^The jet necklace worn by "+TPQCN+" glows "+
               "with an eerie light as several tiny insects buzz away from "+
               ""+TP->query_objective()+".",TP);
            tell_object(TP,"%^BOLD%^%^GREEN%^You speak the command words and your "+
               "necklace glows with an eerie light, sending several tiny insects "+
               "buzzing away from you.");
            uses += 1;
            return 1;
        }
    write("The magic of the necklace has been depleted!");
    return 1;
    }
    write("You must wear the necklace first.");
    return 1;
}
