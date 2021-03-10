#include <std.h>

string get_area_name(object ob){

  string name,stuff;
  string file = base_name(ob);

  if(strsrch(file,"/d/") == -1){
    return "not domain object";
  }
   if(sscanf(file,"/d/%s/%s",name, stuff) < 1){
    return "error in reading file name "+file;
}

return name;
}
