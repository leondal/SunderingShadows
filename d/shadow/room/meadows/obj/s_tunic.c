#include <std.h>

#define COLORS ({"light brown","light gray","dark brown","dark gray","dark black","black","gray","brown"})

inherit DAEMON;

int j, val;
string str;

void create()
{
   ::create();
}

void create_tunic(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   obj->set_value(random(5)+5);
   obj->set_long("This is a tunic that has been made from soft sheepskin and"+
   " dyed a "+str+". The material is quite pliable and does a good job of"+
   " keeping the heat in and the wind out.");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(3);
   obj->set_name("sheepskin tunic");
   obj->set_short("A "+str+" sheepskin tunic");
   obj->set_id(({"tunic","sheepskin tunic","sheep skin tunic",""+str+" tunic",""+str+" sheepskin tunic"}));
}
