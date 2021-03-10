#include <std.h>
#include "/realms/grendel/grendel.h"

inherit OBJECT;
int uses;

void create(){
    ::create();
    set_name("black pearl");
    set_short("%^BLUE%^Black Pearl%^RESET%^");
    set_id( ({"perl", "pearl", "black pearl"}) );
    set_long(
      "This large black pearl, about a foot in diamaeter, is almost perfect.  The shape of the pearl is a perfect sphere with no cracks or other deformities, and the color is the black of the darkest night.  You can feel a dark power flowing from the pearl as you inspect it."
    );
    set_property("magic", 1);
    set_weight(10);
    set_value(8000);
    uses = 3+random(4);
}

void init(){
    ::init();
    add_action("scry_me", "scry");
}

int scry_me(string str){
    object target, place, *inv;
    int i;

    if(!str) return notify_fail("scry who?\n");
    if(!target = find_player(str)) return notify_fail("The pearl's surface remains black.\n");
    if(wizardp(target)) return notify_fail("The pearl's surface remains black.\n");
    if(target == TP) return notify_fail("You're right here silly.\n");
    if(target->query_property("no scry")) return notify_fail("The pearl shakes violently as its power wars with another, then quickly stops.\n");

    if(!is_evil(TP)){
      tell_object(TP, "The dark pearl crumbles to dust in your hands.");
      TO->remove();
      return 1;
    }
    
    place = environment(target);
    str = (string)place->query_long()+"\n";
    inv = all_inventory(place);
    for(i=0;i<sizeof(inv);i++){
      if(inv[i]->query_invis()) continue;
      str += (string)inv[i]->query_short()+"\n";
    }
    tell_object(TP, "%^BLUE%^You concentrate and peer into the depths of the pearl.%^RESET%^");
    tell_object(TP, "%^BLUE%^%^BOLD%^"+str);
    tell_room(ETP, TPQCN+" peers into the depths of the black pearl.", ({TP}) );
    uses--;
    if(uses <= 0){
      tell_object(TP, "As you watch the image, the pearl shakes then shatters in your hands!");
      tell_room(ETP, "The black pearl shatters in "+TPQCN+"'s hands!", ({TP}) );
      TO->remove();
      return 1;
    }
    return 1;
}
