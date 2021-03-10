//Many thanks to Shar for creating this item :)
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
#define MAXUSES 25
int uses;
string place;

void create(){
        ::create();
        set_name("ring of purification");
        set_id(({ "ring", "ring of purification","band","platinum band" }));
        set_short("%^BOLD%^%^CYAN%^Ring of %^WHITE%^Purification%^RESET%^");
        set_obvious_short("A platium band inlaid with quartz");
        set_long(
           "%^BOLD%^%^WHITE%^A thin band of platinum forms the base of this "+
           "ring.  The band is perfectly round and has been polished smooth.  "+
           "Tiny crystal spikes of quartz have been set into the band, almost "+
           "looking as if they grow from the band itself.  Though the crystal "+
           "does rise up, it is not sharp enough to cut one's hand."
        );
        set("read",
@AVATAR
%^BOLD%^%^CYAN%^Looking into the crystals you see each one has a phrase floating
inside,%^WHITE%^"cleanse me"

AVATAR
        );
     set("langage","str");      set_weight(2);
        set_value(750);
        set_lore(
@AVATAR
The Ring of Purification was gifted to a bardess traveler by one of her
admirers.  The bardess enjoyed traveling with new people to record their
tales, but always hated the muck and mire the trips to sewers, graveyards
and caverns were filled with.  With this ring, she was able to cleanse her
clothing and person after her soiled adventures.

AVATAR
        );
        set_property("lore difficulty",7);
        set_type("ring");
        set_limbs(({ "right hand","left hand" }));
        set_size(2);
        set_property("enchantment",0);
}
void init(){
    ::init();
    add_action("cleanse","cleanse");
    if(uses > 24){
        set_value(0);
    }
}
int cleanse(string str){
   if ( !str || str !="me") {
      notify_fail ("Cleanse what?\n");
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
            tell_room(ETP,"%^BOLD%^%^CYAN%^A light mist begins to form at "+
               ""+TPQCN+"'s feet and grows thicker, rising and swirling around "+
               ""+TP->query_objective()+" and leaving "+TP->query_objective()+" "+
               "looking cleansed.",TP);
            tell_object(TP,"%^BOLD%^%^CYAN%^A fine mist swirls around your "+
               "body, lifting grime and leaving you purified.");
            uses += 1;
            return 1;
        }
 
    write("The magic of the ring has been depleted!");
    return 1;
    }
    write("You must wear the ring first.");
    return 1;
}
