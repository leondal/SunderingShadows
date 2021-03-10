#include <std.h>
#include "/d/islands/dinosaur/short.h"

#define GENSTONE OPATH "genstone.c"
#define COLORS ({"black", "red", "white", "yellow"})


object get_stone(string color);

object get_stone(string color){
    object ob;
    string file;

    if(color == "grey") return new(GENSTONE);
    if(!color || member_array(color, COLORS) == -1) color = COLORS[random(sizeof(COLORS))];

    if(random(5)){
      ob = new(GENSTONE);
      if(!random(4)) ob->set_color(color);
      return ob;
   } else {
      file = OPATH "stone_"+color;
      ob = new(file);
      return ob;
    }
    return 0;
}
