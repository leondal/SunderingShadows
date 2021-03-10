#include "/d/dagger/tonovi/town/short.h";

object ob;

object get_room_monster(string type){
    seteuid(getuid(TO));

    ob = 0;

    switch(type){
      case "street":
      case "bazaar":
        if(!random(3)) ob = new(MPATH "guard1_city");
        else ob = new(MPATH "citizen");
      break;

      case "tbarracks":
//      case "jail":
	if(!random(4))  // changed to only randomly fill in *Styx* 10/9/05
           ob = new(MPATH "guard1_city");
      break;

      case "walls":     // and fixed this from "wall" since they are all set "walls"
	if(!random(4))  // changed to only randomly fill in *Styx* 10/9/05
          ob = new(MPATH "guard2_city");
      break;
    }
    return ob;
}
