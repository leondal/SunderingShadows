#include <std.h>
#include <daemons.h>
inherit ARMOUR;
#define MAXUSES 5
int uses, flag;
string place;
void create(){
    ::create();
    flag=1;
    set_obvious_short("%^BOLD%^%^BLACK%^a shi%^WHITE%^f%^BLACK%^t"+
       "ing bl%^WHITE%^a%^BLACK%^ck ring%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^Ring of Twilight%^RESET%^");
    set_id(({"ring","twilight ring","shadow ring","ring of twilight"}));
    set_name("twilight ring");
    set_long(
      "%^BOLD%^%^BLACK%^This ring is fashioned from a shifting, "+
      "flickering whisp of shadow itself!  It seems incapable of "+
      "keeping a constant form, swirling around the wearer's finger "+
      "incessantly.  The shadows seem to curl and shimmer, at "+
      "times revealing a message.%^RESET%^"
    );
   set_lore("This fantastic ring is said by some sages to "+
      "have simply appeared on this plane.  None can determine "+
      "a method for creating it here, and it seems that perhaps "+
      "they are made on the shadow plane and appear here through "+
      "some strange twist in a place that must be closely "+
      "connected to or cloaked in shadows.  Even more unusual is "+
      "the way the ring can produce shadows itself.");
   set_property("lore difficulty",13);
    set_type("ring");
    set_ac(0);
    set_weight(1);
    set_value(150);
    set_limbs(({"right hand","left hand"}));
    set("read","Call the %^BOLD%^%^BLACK%^twilight %^RESET%^and it will answer.");
}
void init(){
    ::init();
    add_action("darkness","twilight");
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
        tell_room(ETO,"%^BOLD%^%^BLACK%^A cloud of darkness spreads from the ring.%^RESET%^");
                    new("/cmds/spells/d/_darkness.c")->use_spell(TO,TP,1,100,"mage");
            flag=0;
            call_out("reset_flag",100,TO);
            uses += 1;
            return 1;
    }
    tell_object(ETO,"You must wear the ring first.");
    return 1;
}
void reset_flag(){flag=1;}
