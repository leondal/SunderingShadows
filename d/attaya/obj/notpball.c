#include <std.h>
inherit OBJECT;

object room;
nosave int flag;

int charge;

void create(){
	::create();
	set_name("small clay sphere");
	set_id(({ "sphere", "ball", " no tp", " clay sphere" }));
	set_short("Sphere of protection");
	set_obvious_short("small clay sphere");
	set_long(
@AVATAR
This is a small clay sphere. It has only a single small divot scarring its surface. You notice it is very heavy for such a small item; its density must be very high.
The small divot is about the size of a small finger tip. It is as smooth on its inside as the sphere is on the outside.

AVATAR
	);
	//set_weight(25);
    set_weight(10); // changing weight to go along with other encumbrance changes -Ares
	set_value(55);
	set_lore(
@AVATAR
These ancient devices once protected war leaders in conference. They didn't trust their mages to hear their plans. They commanded that these devices were created to protect them from interuptions. They are short lived, but at one point could be recharged.

AVATAR
	);
    charge = 300 + random(300);
    set_heart_beat(10);
}

void heart_beat(){
    if (flag) {
        charge--;
    }
    if (flag && charge == 0) {
        flag =0;
        tell_room(ETO,"%^BOLD%^The whole sphere stops glowing.");
    }

}


void set_charge(int x){
    charge = x;

}

int query_charge(){
    return charge;
}




init(){
    ::init();

    if (ETO->is_room()) {
    if(objectp(room)) {
         room->set_property("teleport proof",-67);
     }
        room = ETO;
       room->set_property("teleport proof",67);
    }else{
    if(objectp(room)) {
        room->set_property("teleport proof",-67);//bumping this up to make a fail chance of escape
        room = 0;
    }
    }
    add_action("push","push");
}


int push(string str){
    if (!str || str != "divot") {
        return 0;
    }
    if (flag) {
        tell_object(TP,"%^BOLD%^You push the divot and the whole sphere stops glowing.");

        tell_room(ETP,"%^BOLD%^"+TPQCN+" pushes the divot and the whole sphere stops glowing.",TP);
        flag = 0;
        if (room) {
          room->set_property("teleport proof",-67);
        }
        return 1;
    } else if(charge) {
        tell_object(TP,"%^BOLD%^You push the divot and the whole sphere starts to glow.");
        tell_room(ETP,"%^BOLD%^"+TPQCN+" pushes the divot and the whole sphere starts glowing.",TP);
        flag = 1;
        return 1;

    }
}

string query_short(){
    string sh = ::query_short();
    if (flag && charge) {
        sh += " %^BOLD%^(glowing)%^RESET%^";
    }
    return sh;
}
