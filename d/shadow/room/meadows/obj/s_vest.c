#include <std.h>

#define COLORS ({"light brown","light gray","dark brown","dark gray","dark black","black","gray","brown"})

inherit DAEMON;

int j, val;
string str;

void create()
{
   ::create();
}

void create_vest(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   obj->set_value(random(5)+10);
   obj->set_long("The vest is of very fine quality and has been made from"+
   " sheepskin. The outer part still has soft fur that has been dyed "+str+","+
   " while the inside is smoothed sheepskin. It is a warm and comfortable"+
   " vest, buttoning in the front.");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(2);
   obj->set_name("sheepskin vest");
   obj->set_short("A "+str+" sheepskin vest");
   obj->set_id(({"vest","sheepskin vest","sheep skin vest",""+str+" vest",""+str+" sheepskin vest"}));
}
