//jet_ring.c - A balance to the bone ring in Asgard sewers now that 
//nocturnal races have night blindness.  Circe 1/13/04
#include <std.h>
#include <daemons.h>
inherit ARMOUR;
#define MAXUSES 5
int uses, flag;
string place;
void create(){
    ::create();
    flag=1;
    set_short("%^BOLD%^%^BLACK%^a jet ring%^RESET%^");
    set_id(({"ring","jet ring"}));
    set_name("jet ring");
    set_long(
      "%^BOLD%^%^BLACK%^This ring is crafted out of a solid piece of jet.  "+
      "The jet has been cut with facets that cause the black stone to give "+
      "a slight sparkle, though only the top of the ring has been polished.  "+
      "Peering closely, you can see a message carved in tiny letters inside "+
      "the jet itself."
    );
    set_type("ring");
    set_ac(0);
    set_weight(1);
    set_value(150);
    set_limbs(({"right hand","left hand"}));
    set("read","Call the %^BOLD%^%^BLACK%^darkness %^RESET%^and it will answer.");
}
void init(){
    ::init();
    add_action("darkness","darkness");
    if(uses > 4){
    	set_value(0);
    }
}
int darkness(string str){
    if(str) return 0;
    place = environment(TP);
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
 
    if(query_worn()){
    if(uses < MAXUSES){
        if(flag != 0){
            tell_room(ETO,"%^BOLD%^%^BLACK%^A cloud of darkness spreads from the ring.%^RESET%^");
                    new("/cmds/spells/d/_darkness.c")->use_spell(TO,TP,1,100,"mage");
            flag=0;
            call_out("reset_flag",100,TO);
            uses += 1;
            return 1;
        }
        tell_object(ETO,"The ring fails to respond.");
        return 1;
 
    }
    tell_object(ETO,"The ring is out of charges.");
    return 1;
    }
    tell_object(ETO,"You must wear the ring first.");
    return 1;
}
void reset_flag(){flag=1;}
