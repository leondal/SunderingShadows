
#include <std.h>
#include "../tunnel.h"

inherit BTUNNEL;
int devilkins;

void on_entry(object ob);
void on_entry2(object ob);

void create(){
    ::create();
    devilkins = 0;
    set_exits(([
                "south":TUNNELS + "tun07",
                "north":TUNNELS + "tun09",
      ]));
}

void on_entry(object ob)
{
  call_out("on_entry2", 1, ob);
}

void on_entry2(object ob)
{
  int i;
  object * devilkin;
  if (!objectp(ob)||devilkins){return;}
  if (ob->query_true_invis()||(string)ob->query_race()=="devil"
                    ||(string)ob->query_race()=="devilkin"){return;}
  tell_room(TO,"A gaggle of devilkin swoops down from the cracks and"
              +" fissures high in the walls and attacks!");
  for (i=0;i<4;i++)
  {
    devilkin = new(MOB+"devilkin");
    devilkin->move(TO);
    devilkin->attack(ob);
  }
  devilkins = 1;

}