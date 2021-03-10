#include <std.h>
#include <daemons.h>
inherit ARMOUR;
#define MAXUSES 5
int uses, flag;
string place;
void create(){
    ::create();
    flag=1;
    set_short("a bone ring");
    set_id(({"ring","bone ring"}));
    set_name("bone ring");
    set_long(
    "The ring is made of bone and looks quite ordinary, although "+
    "a faint glow can be seen when the ring passes through the "+
    "shadows. Crude writing can be seen inside the band."
    );
    set_type("ring");
    set_ac(0);
    set_weight(1);
    set_value(150);
    set_limbs( ({"right hand","left hand"}) );
    set("read","Say what right and you get me light.");
}
void init(){
    ::init();
    add_action("light","light");
    if(uses > 4){
    	set_value(0);
    }
}
int light(string str){
    if(str) return 0;
    place = environment(TP);
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
 
    if(query_worn()){
    if(uses < MAXUSES){
        if(flag != 0){
            tell_room(ETO,"%^BOLD%^YELLOW%^The bone ring lights up the room.");
                    new("/cmds/spells/l/_light.c")->use_spell(TO,TP,10,100,"mage");
            flag=0;
            call_out("reset_flag",100,TO);
            uses += 1;
            return 1;
        }
        write("The ring fails to respond.");
        return 1;
 
    }
    write("The ring is out of charges.");
    return 1;
    }
    write("You must wear the ring first.");
    return 1;
}
void reset_flag(){flag=1;}
