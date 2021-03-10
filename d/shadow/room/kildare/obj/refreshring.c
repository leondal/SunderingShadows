//Many thanks to Shar for creating this item :)
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
#define MAXUSES 25
int uses;
string place;

void create(){
        ::create();
        set_name("ring of refresh");
        set_id(({ "ring", "ring of refresh","band","crystal band" }));
        set_short("%^BOLD%^%^CYAN%^Ring of Refresh%^RESET%^");
        set_obvious_short("A crystal band");
        set_long(
           "%^BOLD%^%^CYAN%^This band is fashioned out of a clear crystal.  "+
           "The ring has been unpolished to allow the valleys and peaks of "+
           "the crystal to remain, catching the light.  Only after you have "+
           "touched the ring do you realize that it is actually made out of ice!  "+
           "Some form of magic seems to keep it from melting."
        );
        set("read",
@AVATAR
%^BOLD%^%^CYAN%^Hidden below the surface of the ice is one word %^WHITE%^~%^CYAN%^*%^WHITE%^snowfall%^CYAN%^*%^WHITE%^~

AVATAR
        );
     set("langage","str");      set_weight(2);
        set_value(750);
        set_property("lore difficulty",5);
        set_type("ring");
        set_limbs(({ "left hand","right hand" }));
        set_size(2);
        set_property("enchantment",0);
}
void init(){
    ::init();
    add_action("snowfall","snowfall");
    if(uses > 24){
        set_value(0);
    }
}
int snowfall(string str){
   if (str) {
      notify_fail ("What?\n");
      return 0;
   }
        if(TP->query_bound() || TP->query_unconcious() ||
TP->query_paralyzed() ||
TP->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
    }

    if(query_worn()){
    if(uses < MAXUSES){
            tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+"'s skin forms a fine white "+
               "sheen that soon melts away, leaving "+TP->query_objective()+" "+
               "seeming refreshed and cool.",TP);
            tell_object(TP,"%^BOLD%^%^WHITE%^A fine layer of ice forms on your "+
               "skin briefly before melting away, leaving you feeling cool and refreshed.");
            uses += 1;
            return 1;
        }
    write("The magic of the ring has been depleted!");
    return 1;
    }
    write("You must wear the ring first.");
    return 1;
}
